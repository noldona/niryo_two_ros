/*
    niryo_one_driver_node.cpp
    Copyright (C) 2017 Niryo
    All rights reserved.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "controller_manager/controller_manager.hpp"
#include "hardware_interface/resource_manager.hpp"
#include "hardware_interface/system_interface.hpp"
#include "rclcpp/rclcpp.hpp"
#include <memory>
#include <sensor_msgs/msg/joint_state.hpp>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "niryo_one_driver/communication_base.hpp"
#include "niryo_one_driver/fake_communication.hpp"
#include "niryo_one_driver/niryo_one_communication.hpp"
#include "niryo_one_driver/niryo_one_hardware_interface.hpp"
#include "niryo_one_driver/ros_interface.hpp"
#include "niryo_one_driver/rpi_diagnostics.hpp"

#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "std_msgs/msg/empty.hpp"

class NiryoOneDriver: public rclcpp::Node {
	private:
	int hardware_version;

	std::shared_ptr<CommunicationBase> comm;

	std::unique_ptr<NiryoOneHardwareInterface> robot;
	std::shared_ptr<controller_manager::ControllerManager> cm;

	std::shared_ptr<RosInterface> ros_interface;

	std::shared_ptr<RpiDiagnostics> rpi_diagnostics;

	std::shared_ptr<rclcpp::Rate> ros_control_loop_rate;

	std::shared_ptr<std::thread> ros_control_thread;

	bool flag_reset_controllers;

	rclcpp::Subscription<std_msgs::msg::MultiArrayDimension>::SharedPtr
			reset_controller_subscriber;  // workaround to compensate missed steps
	rclcpp::Subscription<control_msgs::action::FollowJointTrajectory_Result>::
			SharedPtr trajectory_result_subscriber;
	rclcpp::Clock clock = rclcpp::Clock();

	public:
	void rosControlLoop() {
		rclcpp::Time last_time = clock.now();
		rclcpp::Time current_time = clock.now();
		rclcpp::Duration elapsed_time =
				rclcpp::Duration(current_time - last_time);

		while (rclcpp::ok()) {
			current_time = clock.now();
			elapsed_time = rclcpp::Duration(current_time - last_time);
			last_time = current_time;
			robot->read(current_time, elapsed_time);

			if (flag_reset_controllers) {
				robot->setCommandToCurrentPosition();
				cm->update(clock.now(), elapsed_time);
				flag_reset_controllers = false;
			} else {
				cm->update(clock.now(), elapsed_time);
			}
			robot->write(current_time, elapsed_time);

			ros_control_loop_rate->sleep();
		}
	}

	NiryoOneDriver(): Node("niryo_one_driver") {
		reset_controller_subscriber =
				this->create_subscription<std_msgs::msg::MultiArrayDimension>(
						"/niryo_one/reset_controllers", 10,
						std::bind(&NiryoOneDriver::callbackTrajectoryGoal, this,
								std::placeholders::_1));

		trajectory_result_subscriber = this->create_subscription<
				control_msgs::action::FollowJointTrajectory_Result>(
				"/niryo_one_follow_joint_trajectory_controller/"
				"follow_joint_trajectory/result",
				10,
				std::bind(&NiryoOneDriver::callbackTrajectoryResult, this,
						std::placeholders::_1));

		this->declare_parameter(
				"/niryo_one/hardware_version", rclcpp::PARAMETER_INTEGER);
		this->hardware_version =
				this->get_parameter("/niryo_one/hardware_version").as_int();

		if (hardware_version != 1 && hardware_version != 2) {
			RCLCPP_ERROR(this->get_logger(),
					"Incorrect hardware version, should be 1 or 2");
			return;
		}

		this->declare_parameter(
				"~ros_control_loop_frequency", rclcpp::PARAMETER_DOUBLE);
		double ros_control_frequency =
				this->get_parameter("~ros_control_loop_frequency").as_double();

		this->declare_parameter("~fake_communication", rclcpp::PARAMETER_BOOL);
		bool fake_communication =
				this->get_parameter("~fake_communication").as_bool();

		RCLCPP_INFO(this->get_logger(),
				"Starting niryo_one driver thread (frequency : %lf)",
				ros_control_frequency);

		if (fake_communication) {
			comm.reset(new FakeCommunication(hardware_version));
		} else {
			comm.reset(new NiryoOneCommunication(hardware_version));
		}

		int init_result = comm->init();
		if (init_result != 0) {
			return;  // need to check last ROS_ERROR to get more info
		}

		RCLCPP_INFO(this->get_logger(),
				"NiryoOne communication has been successfully started");

		rclcpp::sleep_for(std::chrono::milliseconds(100));
		flag_reset_controllers = true;

		RCLCPP_INFO(this->get_logger(), "Start hardware control loop");
		comm->manageHardwareConnection();
		rclcpp::sleep_for(std::chrono::milliseconds(500));

		RCLCPP_INFO(this->get_logger(), "Start hardware interface");
		robot.reset(new NiryoOneHardwareInterface(comm.get()));

		RCLCPP_INFO(this->get_logger(), "Create controller manager");
		std::unique_ptr<NiryoOneHardwareResourceManager> rm =
				std::make_unique<NiryoOneHardwareResourceManager>(
						this->get_node_clock_interface(),
						this->get_node_logging_interface());
		// rm->add_system_interface(robot.get());
		std::shared_ptr<rclcpp::Executor> executor =
				std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
		cm = std::make_shared<controller_manager::ControllerManager>(
				std::move(rm), executor, "control_manager", "",
				rclcpp::NodeOptions());
		rclcpp::sleep_for(std::chrono::milliseconds(100));

		RCLCPP_INFO(this->get_logger(), "Starting ROS control thread...");
		ros_control_loop_rate.reset(new rclcpp::Rate(ros_control_frequency));
		ros_control_thread.reset(new std::thread(
				std::bind(&NiryoOneDriver::rosControlLoop, this)));

		RCLCPP_INFO(this->get_logger(), "Start Rpi Diagnostics...");
		rpi_diagnostics.reset(new RpiDiagnostics());

		RCLCPP_INFO(this->get_logger(), "Starting ROS interface...");
		bool learning_mode_activated_on_startup = true;
		ros_interface.reset(new RosInterface());
		ros_interface->init(comm.get(), rpi_diagnostics.get(),
				&flag_reset_controllers, learning_mode_activated_on_startup,
				hardware_version);

		// activate learning mode
		comm->activateLearningMode(learning_mode_activated_on_startup);
	}

	/*
     * Problem : for joint_trajectory_controller, position command has no discontinuity
     * --> If the stepper motor missed some steps, we need to start at current position (given by the encoder)
     *  So current real position != current trajectory command, we need a discontinuity in controller command.
     *  We have to reset controllers to start from sensor position.
     *  If we subscribe to trajectory /goal topic and reset when we receive a goal, it is often
     *  too late and trajectory will just be preempted.
     *
     *  So, in order to start from encoder position, we need to reset controller before we send the goal. If you
     *  send a new goal, be sure to send a message on /niryo_one_steppers_reset_controller BEFORE sending the goal.
     *
     *  This behavior is used in robot_commander node.
     *
     */
	void callbackTrajectoryGoal(const std_msgs::msg::MultiArrayDimension &msg) {
		RCLCPP_INFO(this->get_logger(), "Received trajectory GOAL");
		robot->setCommandToCurrentPosition();  // set current command to encoder position
		cm->update(clock.now(),
				rclcpp::Duration(std::chrono::seconds(
						0)));  // reset controllers to allow a discontinuity in position command
		comm->synchronizeMotors(true);
	}

	void callbackTrajectoryResult(
			const control_msgs::action::FollowJointTrajectory_Result &msg) {
		RCLCPP_INFO(this->get_logger(), "Received trajectory RESULT");
		comm->synchronizeMotors(false);
	}
};

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<NiryoOneDriver>());
	rclcpp::shutdown();
	RCLCPP_INFO(rclcpp::get_logger("NiryoOneDriverNode"), "shutdown node");
}
