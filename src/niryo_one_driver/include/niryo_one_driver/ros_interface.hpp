#ifndef ROS_INTERFACE_H
#define ROS_INTERFACE_H

#include <memory>
#include <thread>
#include <vector>

#include "rclcpp/rclcpp.hpp"

#include "niryo_one_driver/change_hardware_version.hpp"
#include "niryo_one_driver/communication_base.hpp"
#include "niryo_one_driver/rpi_diagnostics.hpp"
// #include "niryo_one_driver/test_motors.hpp"

#include "niryo_one_msgs/srv/set_int.hpp"
#include "niryo_one_msgs/srv/set_leds.hpp"

#include "niryo_one_msgs/srv/close_gripper.hpp"
#include "niryo_one_msgs/srv/open_gripper.hpp"
#include "niryo_one_msgs/srv/ping_dxl_tool.hpp"
#include "niryo_one_msgs/srv/pull_air_vacuum_pump.hpp"
#include "niryo_one_msgs/srv/push_air_vacuum_pump.hpp"

#include "niryo_one_msgs/srv/change_hardware_version.hpp"
#include "niryo_one_msgs/srv/control_conveyor.hpp"
#include "niryo_one_msgs/srv/send_custom_dxl_value.hpp"
#include "niryo_one_msgs/srv/set_conveyor.hpp"
#include "niryo_one_msgs/srv/update_conveyor_id.hpp"

#include "niryo_one_msgs/msg/conveyor_feedback.hpp"
#include "niryo_one_msgs/msg/hardware_status.hpp"
#include "niryo_one_msgs/msg/software_version.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/int8_multi_array.hpp"

class RosInterface: public rclcpp::Node {
	public:
	RosInterface(): rclcpp::Node("interface") {}
	void init(CommunicationBase *niryo_one_comm,
			RpiDiagnostics *rpi_diagnostics, bool *flag_reset_controllers,
			bool learning_mode_on, int hardware_version);

	void startServiceServers();
	void startPublishers();
	void startSubscribers();

	private:
	CommunicationBase *comm;
	RpiDiagnostics *rpi_diagnostics;

	// NiryoOneTestMotor test_motor;

	bool *flag_reset_controllers;
	int hardware_version;
	bool learning_mode_on;
	int calibration_needed;
	bool calibration_in_progress;
	bool last_connection_up_flag;
	int motor_test_status;

	std::string rpi_image_version;
	std::string ros_niryo_one_version;

	// Publishers
	rclcpp::Publisher<niryo_one_msgs::msg::HardwareStatus>::SharedPtr
			hardware_status_publisher;
	std::shared_ptr<std::thread> publish_hardware_status_thread;

	rclcpp::Publisher<niryo_one_msgs::msg::SoftwareVersion>::SharedPtr
			software_version_publisher;
	std::shared_ptr<std::thread> publish_software_version_thread;

	rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr learning_mode_publisher;
	std::shared_ptr<std::thread> publish_learning_mode_thread;

	rclcpp::Publisher<niryo_one_msgs::msg::ConveyorFeedback>::SharedPtr
			conveyor_1_feedback_publisher;
	std::shared_ptr<std::thread> publish_conveyor_1_feedback_thread;

	rclcpp::Publisher<niryo_one_msgs::msg::ConveyorFeedback>::SharedPtr
			conveyor_2_feedback_publisher;
	std::shared_ptr<std::thread> publish_conveyor_2_feedback_thread;

	// Publish methods
	void publishHardwareStatus();
	void publishSoftwareVersion();
	void publishLearningMode();
	void publishConveyor1Feedback();
	void publishConveyor2Feedback();

	// Services
	rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
			calibrate_motors_server;
	rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
			request_new_calibration_server;

	// rclcpp::Service<niryo_one::srv::SetInt>::SharedPtr test_motors_server;

	rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
			activate_learning_mode_server;
	rclcpp::Service<niryo_one_msgs::srv::SetLeds>::SharedPtr
			activate_leds_server;

	rclcpp::Service<niryo_one_msgs::srv::PingDxlTool>::SharedPtr
			ping_and_set_dxl_tool_server;

	rclcpp::Service<niryo_one_msgs::srv::OpenGripper>::SharedPtr
			open_gripper_server;
	rclcpp::Service<niryo_one_msgs::srv::CloseGripper>::SharedPtr
			close_gripper_server;
	rclcpp::Service<niryo_one_msgs::srv::PullAirVacuumPump>::SharedPtr
			pull_air_vacuum_pump_server;
	rclcpp::Service<niryo_one_msgs::srv::PushAirVacuumPump>::SharedPtr
			push_air_vacuum_pump_server;

	rclcpp::Service<niryo_one_msgs::srv::ChangeHardwareVersion>::SharedPtr
			change_hardware_version_server;
	rclcpp::Service<niryo_one_msgs::srv::SendCustomDxlValue>::SharedPtr
			send_custom_dxl_value_server;
	rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
			reboot_motors_server;

	// Conveyor services
	rclcpp::Service<niryo_one_msgs::srv::SetConveyor>::SharedPtr
			ping_and_set_stepper_server;
	rclcpp::Service<niryo_one_msgs::srv::ControlConveyor>::SharedPtr
			control_conveyor_server;
	rclcpp::Service<niryo_one_msgs::srv::UpdateConveyorId>::SharedPtr
			update_conveyor_id_server;

	// Callbacks
	// void callbackTestMotors(niryo_one_msgs::srv::SetInt::Request &req,
	// 		niryo_one_msgs::srv::SetInt::Response &res);

	void callbackCalibrateMotors(
			const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
			std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res);
	void callbackRequestNewCalibration(
			const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
			std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res);

	void callbackActivateLearningMode(
			const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
			std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res);
	void callbackActivateLeds(
			const std::shared_ptr<niryo_one_msgs::srv::SetLeds::Request> req,
			std::shared_ptr<niryo_one_msgs::srv::SetLeds::Response> res);

	void callbackPingAndSetDxlTool(
			const std::shared_ptr<niryo_one_msgs::srv::PingDxlTool::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::PingDxlTool::Response> res);

	void callbackPingAndSetConveyor(
			const std::shared_ptr<niryo_one_msgs::srv::SetConveyor::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::SetConveyor::Response> res);
	void callbackControlConveyor(
			const std::shared_ptr<niryo_one_msgs::srv::ControlConveyor::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::ControlConveyor::Response>
					res);
	void callbackUpdateIdConveyor(
			const std::shared_ptr<
					niryo_one_msgs::srv::UpdateConveyorId::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::UpdateConveyorId::Response>
					res);

	void callbackOpenGripper(
			const std::shared_ptr<niryo_one_msgs::srv::OpenGripper::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::OpenGripper::Response> res);
	void callbackCloseGripper(
			const std::shared_ptr<niryo_one_msgs::srv::CloseGripper::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::CloseGripper::Response> res);

	void callbackPullAirVacuumPump(
			const std::shared_ptr<
					niryo_one_msgs::srv::PullAirVacuumPump::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump::Response>
					res);
	void callbackPushAirVacuumPump(
			const std::shared_ptr<
					niryo_one_msgs::srv::PushAirVacuumPump::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::PushAirVacuumPump::Response>
					res);

	void callbackChangeHardwareVersion(
			const std::shared_ptr<
					niryo_one_msgs::srv::ChangeHardwareVersion::Request>
					req,
			std::shared_ptr<
					niryo_one_msgs::srv::ChangeHardwareVersion::Response>
					res);

	void callbackSendCustomDxlValue(
			const std::shared_ptr<
					niryo_one_msgs::srv::SendCustomDxlValue::Request>
					req,
			std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue::Response>
					res);

	void callbackRebootMotors(
			const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
			std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res);
};

#endif
