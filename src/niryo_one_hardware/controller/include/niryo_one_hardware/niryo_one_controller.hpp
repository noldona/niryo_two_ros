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
#include "sensor_msgs/msg/joint_state.hpp"
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

#include "niryo_one_hardware/interface_constants.hpp"

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
		std::vector<std::string> can_joint_names_;
		std::vector<std::string> can_command_interface_types_;
		std::vector<std::string> can_state_interface_types_;
		std::vector<std::string> dxl_joint_names_;
		std::vector<std::string> dxl_command_interface_types_;
		std::vector<std::string> dxl_state_interface_types_;

		rclcpp::Subscription<trajectory_msgs::msg::JointTrajectory>::SharedPtr
				joint_command_subscriber_;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<trajectory_msgs::msg::JointTrajectory>>
				traj_msg_external_point_ptr_;
		rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr
				joint_state_subscriber_;
		realtime_tools::RealtimeBuffer<
				std::shared_ptr<sensor_msgs::msg::JointState>>
				joint_msg_external_ptr_;
		bool new_msg_ = false;
		rclcpp::Time start_time_;
		std::shared_ptr<trajectory_msgs::msg::JointTrajectory> trajectory_msg_;
		std::shared_ptr<sensor_msgs::msg::JointState> joint_state_msg_;
		trajectory_msgs::msg::JointTrajectoryPoint point_interp_;

		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_position_command_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_velocity_command_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_torque_command_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_micro_steps_command_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_max_effort_command_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				joint_led_command_interface_;

		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_position_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_velocity_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_torque_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_temperature_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_hardware_error_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_enabled_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_hw_fail_counter_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_last_time_read_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_firmware_version_major_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_firmware_version_minor_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_firmware_version_patch_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_voltage_state_interface_;
		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				joint_hw_error_state_interface_;

		std::vector<std::reference_wrapper<
				hardware_interface::LoanedCommandInterface>>
				niryo_one_command_interface_;
		int niryo_one_can_command_interface_count = 0;

		std::vector<std::reference_wrapper<
				hardware_interface::LoanedStateInterface>>
				niryo_one_state_interface_;
		int niryo_one_can_state_interface_count = 0;

		std::unordered_map<std::string,
				std::vector<std::reference_wrapper<
						hardware_interface::LoanedCommandInterface>> *>
				command_interface_map_ = {
						{"position", &joint_position_command_interface_},
						{"velocity", &joint_velocity_command_interface_},
						{"torque", &joint_torque_command_interface_},
						{"mirco_steps", &joint_micro_steps_command_interface_},
						{"max_effort", &joint_max_effort_command_interface_},
						{"led", &joint_led_command_interface_},
						{"niryo_one", &niryo_one_command_interface_}};

		std::unordered_map<std::string,
				std::vector<std::reference_wrapper<
						hardware_interface::LoanedStateInterface>> *>
				state_interface_map_ = {
						{"position", &joint_position_state_interface_},
						{"velocity", &joint_velocity_state_interface_},
						{"torque", &joint_torque_state_interface_},
						{"temperature", &joint_temperature_state_interface_},
						{"hardware_error",
								&joint_hardware_error_state_interface_},
						{"enabled", &joint_enabled_state_interface_},
						{"hw_fail_counter",
								&joint_hw_fail_counter_state_interface_},
						{"last_time_read",
								&joint_last_time_read_state_interface_},
						{"firmware_version_major",
								&joint_firmware_version_major_state_interface_},
						{"firmware_version_minor",
								&joint_firmware_version_minor_state_interface_},
						{"firmware_version_patch",
								&joint_firmware_version_patch_state_interface_},
						{"voltage", &joint_voltage_state_interface_},
						{"hw_error", &joint_hw_error_state_interface_}};

		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				calibrate_motors_srv_;
		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				request_new_calibration_srv_;

		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				test_motors_srv_;

		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				activate_learning_mode_srv_;
		rclcpp::Service<niryo_one_msgs::srv::SetLeds>::SharedPtr
				activate_leds_srv_;

		rclcpp::Service<niryo_one_msgs::srv::PingDxlTool>::SharedPtr
				ping_and_set_dxl_tool_srv_;

		rclcpp::Service<niryo_one_msgs::srv::OpenGripper>::SharedPtr
				open_gripper_srv_;
		rclcpp::Service<niryo_one_msgs::srv::CloseGripper>::SharedPtr
				close_gripper_srv_;
		rclcpp::Service<niryo_one_msgs::srv::PullAirVacuumPump>::SharedPtr
				pull_air_vacuum_pump_srv_;
		rclcpp::Service<niryo_one_msgs::srv::PushAirVacuumPump>::SharedPtr
				push_air_vacuum_pump_srv_;

		rclcpp::Service<niryo_one_msgs::srv::ChangeHardwareVersion>::SharedPtr
				change_hardware_version_srv_;
		rclcpp::Service<niryo_one_msgs::srv::SendCustomDxlValue>::SharedPtr
				send_custom_dxl_value_srv_;
		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				reboot_motors_srv_;
		rclcpp::Service<niryo_one_msgs::srv::SetInt>::SharedPtr
				factory_reset_motor_srv;

		template<typename T>
		bool waitForAsyncCommand(std::function<T(void)> get_value);

		void createSubscribers();
		void createPublishers();
		void createServices();

		private:
		void callbackCalibrateMotors(
				const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
				niryo_one_msgs::srv::SetInt::Response::SharedPtr res);
		void callbackRequestNewCalibration(
				const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
				niryo_one_msgs::srv::SetInt::Response::SharedPtr res);

		void callbackTestMotors(
				const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
				niryo_one_msgs::srv::SetInt::Response::SharedPtr res);

		void callbackActivateLearningMode(
				const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
				niryo_one_msgs::srv::SetInt::Response::SharedPtr res);
		void callbackActivateLeds(
				const niryo_one_msgs::srv::SetLeds::Request::SharedPtr req,
				niryo_one_msgs::srv::SetLeds::Response::SharedPtr res);

		void callbackPingAndSetDxlTool(
				const niryo_one_msgs::srv::PingDxlTool::Request::SharedPtr req,
				niryo_one_msgs::srv::PingDxlTool::Response::SharedPtr res);

		void callbackOpenGripper(
				const niryo_one_msgs::srv::OpenGripper::Request::SharedPtr req,
				niryo_one_msgs::srv::OpenGripper::Response::SharedPtr res);
		void callbackCloseGripper(
				const niryo_one_msgs::srv::CloseGripper::Request::SharedPtr req,
				niryo_one_msgs::srv::CloseGripper::Response::SharedPtr res);
		void callbackPullAirVacuumPump(
				const niryo_one_msgs::srv::PullAirVacuumPump::Request::SharedPtr
						req,
				niryo_one_msgs::srv::PullAirVacuumPump::Response::SharedPtr
						res);
		void callbackPushAirVacuumPump(
				const niryo_one_msgs::srv::PushAirVacuumPump::Request::SharedPtr
						req,
				niryo_one_msgs::srv::PushAirVacuumPump::Response::SharedPtr
						res);

		void callbackChangeHardwareVersion(
				const niryo_one_msgs::srv::ChangeHardwareVersion::Request::
						SharedPtr req,
				niryo_one_msgs::srv::ChangeHardwareVersion::Response::SharedPtr
						res);
		void callbackSendCustomDxlValue(
				const niryo_one_msgs::srv::SendCustomDxlValue::Request::
						SharedPtr req,
				niryo_one_msgs::srv::SendCustomDxlValue::Response::SharedPtr
						res);
		void callbackRebootMotors(
				const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
				niryo_one_msgs::srv::SetInt::Response::SharedPtr res);
		void callbackFactoryResetMotor(
				const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
				niryo_one_msgs::srv::SetInt::Response::SharedPtr res);
	};
}  // namespace niryo_one_hardware

#endif
