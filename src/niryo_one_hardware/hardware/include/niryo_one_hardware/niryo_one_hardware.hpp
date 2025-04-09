#ifndef NIRYO_ONE_HARDWARE_H
#define NIRYO_ONE_HARDWARE_H

#include <string>
#include <unordered_map>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"

#include "niryo_one_hardware/communication_base.hpp"
#include "niryo_one_hardware/fake_communication.hpp"
#include "niryo_one_hardware/niryo_one_communication.hpp"

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

using hardware_interface::return_type;

namespace niryo_one_hardware {
#define TIME_TO_WAIT_IF_BUSY 500  // microseconds

// These IDs need to be used in niryo_one_motors.yaml to enable/disable some stepper motors
#define CAN_MOTOR_1_ID 1
#define CAN_MOTOR_2_ID 2
#define CAN_MOTOR_3_ID 3
#define CAN_MOTOR_4_ID 4

// All motors have positive filter for their own ID + this one
#define CAN_BROADCAST_ID 5

#define CAN_MOTOR_CONVEYOR_1_ID 6
#define CAN_MOTOR_CONVEYOR_2_ID 7

#define CAN_SCAN_OK 0
#define CAN_SCAN_BUSY -10001
#define CAN_SCAN_NOW_ALLOWED -10002
#define CAN_SCAN_TIMEOUT -10003

#define RADIAN_TO_DEGREE 57.295779513082320876798154814105

#define CAN_STEPPERS_CALIBRATION_OK 1
#define CAN_STEPPERS_CALIBRATION_TIMEOUT 2
#define CAN_STEPPERS_CALIBRATION_BAD_PARAM 3
#define CAN_STEPPERS_CALIBRATION_FAIL 4
#define CAN_STEPPERS_CALIBRATION_WAITING_USER_INPUT 5

#define CAN_STEPPERS_CALIBRATION_MODE_AUTO 1
#define CAN_STEPPERS_CALIBRATION_MODE_MANUAL 2

#define CAN_STEPPERS_WRITE_OFFSET_FAIL -3

	using CallbackReturn = rclcpp_lifecycle::node_interfaces::
			LifecycleNodeInterface::CallbackReturn;

	struct Config {
		int hardware_version;
		bool use_sim;

		std::string rpi_image_version;
		std::string ros_niryo_one_version;
		FakeCommunicationConfig fc_cfg;
		NiryoOneCommunicationConfig noc_cfg;
	};

	class NiryoOneHardware: public hardware_interface::SystemInterface {
		public:
		CallbackReturn on_init(
				const hardware_interface::HardwareInfo &info) override;

		CallbackReturn on_configure(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_cleanup(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_activate(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_deactivate(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_shutdown(
				const rclcpp_lifecycle::State &previous_state) override;

		CallbackReturn on_error(
				const rclcpp_lifecycle::State &previous_state) override;

		return_type read(const rclcpp::Time &time,
				const rclcpp::Duration &period) override;

		return_type write(const rclcpp::Time &time,
				const rclcpp::Duration &period) override;

		protected:
		Config cfg_;
		bool startup;

		private:
		std::shared_ptr<NiryoCanDriver> can;
	};
}

#endif
