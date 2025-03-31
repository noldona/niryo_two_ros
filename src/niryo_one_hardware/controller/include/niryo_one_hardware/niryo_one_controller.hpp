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
		std::vector<std::string> gpio_names_;
		std::vector<std::string> gpio_interface_types_;

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
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				gpio_command_interface_;

		// Additional Commands
		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				calibrate_motors_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>>
				calibrate_motors_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>
				calibrate_motors_msg_;

		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				request_new_calibration_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>>
				request_new_calibration_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>
				request_new_calibration_msg_;

		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				test_motors_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>>
				test_motors_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> test_motors_msg_;

		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				activate_learning_mode_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>>
				activate_learning_mode_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>
				activate_learning_mode_msg_;

		rclcpp::Service<niryo_one_msgs::srv::SetLeds>::SharedPtr
				activate_leds_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::SetLeds::Request>>
				activate_leds_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SetLeds::Request>
				activate_leds_msg_;

		rclcpp::Service<niryo_one_msgs::srv::PingDxlTool>::SharedPtr
				ping_and_set_dxl_tool_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::PingDxlTool::Request>>
				ping_and_set_dxl_tool_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::PingDxlTool::Request>
				ping_and_set_dxl_tool_msg_;

		rclcpp::Service<niryo_one_msgs::srv::OpenGripper>::SharedPtr
				open_gripper_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::OpenGripper::Request>>
				open_gripper_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::OpenGripper::Request>
				open_gripper_msg_;

		rclcpp::Service<niryo_one_msgs::srv::CloseGripper>::SharedPtr
				close_gripper_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::CloseGripper::Request>>
				close_gripper_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::CloseGripper::Request>
				close_gripper_msg_;

		rclcpp::Service<niryo_one_msgs::srv::PullAirVacuumPump>::SharedPtr
				pull_air_vacuum_pump_server;
		realtime_tools::RealtimeBuffer<std::shared_ptr<
				niryo_one_msgs::srv::PullAirVacuumPump::Request>>
				pull_air_vacuum_pump_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump::Request>
				pull_air_vacuum_pump_msg_;

		rclcpp::Service<niryo_one_msgs::srv::PushAirVacuumPump>::SharedPtr
				push_air_vacuum_pump_server;
		realtime_tools::RealtimeBuffer<std::shared_ptr<
				niryo_one_msgs::srv::PushAirVacuumPump::Request>>
				push_air_vacuum_pump_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::PushAirVacuumPump::Request>
				push_air_vacuum_pump_msg_;

		rclcpp::Service<niryo_one_msgs::srv::ChangeHardwareVersion>::SharedPtr
				change_hardware_version_server;
		realtime_tools::RealtimeBuffer<std::shared_ptr<
				niryo_one_msgs::srv::ChangeHardwareVersion::Request>>
				change_hardware_version_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::ChangeHardwareVersion::Request>
				change_hardware_version_msg_;

		rclcpp::Service<niryo_one_msgs::srv::SendCustomDxlValue>::SharedPtr
				send_custom_dxl_value_server;
		realtime_tools::RealtimeBuffer<std::shared_ptr<
				niryo_one_msgs::srv::SendCustomDxlValue::Request>>
				send_custom_dxl_value_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue::Request>
				send_custom_dxl_value_msg_;

		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				reboot_motors_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>>
				reboot_motors_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Request>
				reboot_motors_msg_;

		// Conveyor services
		rclcpp::Service<niryo_one_msgs::srv::SetConveyor>::SharedPtr
				ping_and_set_stepper_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::SetConveyor::Request>>
				ping_and_set_stepper_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::SetConveyor::Request>
				ping_and_set_stepper_msg_;

		rclcpp::Service<niryo_one_msgs::srv::ControlConveyor>::SharedPtr
				control_conveyor_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::ControlConveyor::Request>>
				control_conveyor_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::ControlConveyor::Request>
				control_conveyor_msg_;

		rclcpp::Service<niryo_one_msgs::srv::UpdateConveyorId>::SharedPtr
				update_conveyor_id_server;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<niryo_one_msgs::srv::UpdateConveyorId::Request>>
				update_conveyor_id_external_ptr_;
		std::shared_ptr<niryo_one_msgs::srv::UpdateConveyorId::Request>
				update_conveyor_id_msg_;

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
