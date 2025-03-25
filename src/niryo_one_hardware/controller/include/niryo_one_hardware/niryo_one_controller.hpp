#ifndef NIRYO_ONE_CONTROLLER_H
#define NIRYO_ONE_CONTROLLER_H

#include <chrono>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "control_msgs/msg/joint_trajectory_controller_state.hpp"
#include "controller_interface/controller_interface.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "rclcpp/duration.hpp"
#include "rclcpp/subscription.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp/timer.hpp"
#include "rclcpp_lifecycle/lifecycle_publisher.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "realtime_tools/realtime_buffer.hpp"
#include "trajectory_msgs/msg/joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"

namespace niryo_one_hardware {
	class NiryoOneController: public controller_interface::ControllerInterface {
		public:
		NiryoOneController();

		controller_interface::InterfaceConfiguration
				command_interface_configuration() const override;

		controller_interface::InterfaceConfiguration
				state_interface_configuration() const override;

		controller_interface::return_type update(const rclcpp::Time &time,
				const rclcpp::Duration &period) override;

		controller_interface::CallbackReturn on_init() override;

		controller_interface::CallbackReturn on_configure(
				const rclcpp_lifecycle::State &previous_state) override;

		controller_interface::CallbackReturn on_activate(
				const rclcpp_lifecycle::State &previous_state) override;

		controller_interface::CallbackReturn on_deactivate(
				const rclcpp_lifecycle::State &previous_state) override;

		protected:
		std::vector<std::string> joint_names_;
		std::vector<std::string> command_interface_types_;
		std::vector<std::string> state_interface_types_;

		rclcpp::Subscription<trajectory_msgs::msg::JointTrajectory>::SharedPtr
				joint_command_subscriber_;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<trajectory_msgs::msg::JointTrajectory>>
				traj_msg_external_point_ptr_;
		bool new_msg_ = false;
		rclcpp::Time start_time_;
		std::shared_ptr<trajectory_msgs::msg::JointTrajectory> trajectory_msg_;
		trajectory_msgs::msg::JointTrajectoryPoint point_interp_;

		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_position_command_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_velocity_command_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_position_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_velocity_state_interface_;

		std::unordered_map<std::string,
				std::vector<std::reference_wrapper<
						hardware_interface::LoanedCommandInterface>> *>
				command_interface_map_ = {
						{"position", &joint_position_command_interface_},
						{"velocity", &joint_velocity_command_interface_}};

		std::unordered_map<std::string,
				std::vector<std::reference_wrapper<
						hardware_interface::LoanedStateInterface>> *>
				state_interface_map_ = {
						{"position", &joint_position_state_interface_},
						{"velocity", &joint_velocity_state_interface_}};
	};
}  // namespace niryo_one_hardware

#endif
