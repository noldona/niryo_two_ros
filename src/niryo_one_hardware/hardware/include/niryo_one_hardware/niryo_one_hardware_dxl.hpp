#ifndef NIRYO_ONE_HARDWARE_DXL_H
#define NIRYO_ONE_HARDWARE_DXL_H

#include <string>
#include <unordered_map>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"

#include "dynamixel_sdk/dynamixel_sdk.hpp"
#include "niryo_one_hardware/dxl_motor_state.hpp"
#include "niryo_one_hardware/xl320_driver.hpp"
#include "niryo_one_hardware/xl430_driver.hpp"

#include "niryo_one_hardware/interface_constants.hpp"

#define DXL_MOTOR_4_ID 2  // V2 - axis 4
#define DXL_MOTOR_5_ID 3  // V2 - axis 5
#define DXL_MOTOR_5_1_ID 4  // V1 - axis 5 (1)
#define DXL_MOTOR_5_2_ID 5  // V1 - axis 5 (2)
#define DXL_MOTOR_6_ID 6

#define DXL_BUS_PROTOCOL_VERSION 2.0

#define DXL_FAIL_OPEN_PORT -4500
#define DXL_FAIL_PORT_SET_BAUDRATE -4501
#define DXL_FAIL_SETUP_GPIO -4502

// we stop at 1022 instead of 1023, to get an odd number of positions (1023)
// --> so we can get a middle point (511)
#define XL320_TOTAL_ANGLE 296.67
#define XL320_MAX_POSITION 1022
#define XL320_MIN_POSITION 0
#define XL320_MIDDLE_POSITION 511
#define XL320_TOTAL_RANGE_POSITION 1023

// we stop at 4094 instead of 4095, to get an odd number of positions (4095)
// --> so we can get a middle point (2047)
#define XL430_TOTAL_ANGLE 360.36
#define XL430_MAX_POSITION 4094
#define XL430_MIN_POSITION 0
#define XL430_MIDDLE_POSITION 2047
#define XL430_TOTAL_RANGE_POSITION 4095

#define RADIAN_TO_DEGREE 57.295779513082320876798154814105

#define TIME_TO_WAIT_IF_BUSY 500  // microseconds

#define DXL_SCAN_OK 0
#define DXL_SCAN_MISSING_MOTOR -50
#define DXL_SCAN_UNALLOWED_MOTOR -51

#define DXL_GRIPPER_ACTION_TIMEOUT 5

#define DXL_CONTROL_MODE_POSITION 1
#define DXL_CONTROL_MODE_VELOCITY 2
#define DXL_CONTROL_MODE_TORQUE 3

// according to xl-320 datasheet : 1 speed ~ 0.111 rpm ~ 1.8944 dxl position per second
#define XL320_STEPS_FOR_1_SPEED 1.8944  // 0.111 * 1024 / 60

using hardware_interface::return_type;

namespace niryo_one_hardware {

	using CallbackReturn = rclcpp_lifecycle::node_interfaces::
			LifecycleNodeInterface::CallbackReturn;

	class NiryoOneHardwareDxl: public hardware_interface::SystemInterface {
		public:
		CallbackReturn on_init(
				const hardware_interface::HardwareInfo &info) override;

		std::vector<hardware_interface::InterfaceDescription>
				export_unlisted_command_interface_descriptions() override;

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

		void asyncThread();

		private:
		int hardware_version;
		bool use_sim;

		std::string device_name;
		int uart_baudrate;

		bool dxl_enabled;
		double niryo_one_hw_check_connection_frequency;

		dynamixel::PortHandler *dxlPortHandler;
		dynamixel::PacketHandler *dxlPacketHandler;

		std::shared_ptr<XL320Driver> xl320;
		std::shared_ptr<XL430Driver> xl430;

		// For hardware control
		bool is_dxl_connection_ok;

		uint8_t torque_on;  // Torque is ON/OFF for all motors at the same time

		bool is_tool_connected;

		bool hw_control_loop_keep_alive;
		bool hw_is_busy;
		bool hw_limited_mode;

		double hw_control_loop_frequency;

		int xl320_hw_fail_counter_read;
		int xl430_hw_fail_counter_read;

		double time_hw_data_last_write;
		double time_hw_data_last_read;
		double time_hw_status_last_read;
		double hw_data_write_frequency;
		double hw_data_read_frequency;
		double hw_status_read_frequency;

		std::queue<DxlCustomCommand> custom_command_queue;
		bool should_reboot_motors;

		// Enable flags
		bool read_position_enable;
		bool read_velocity_enable;
		bool read_torque_enable;
		bool read_hw_status_enable;  // For temperature + voltage + hw_error

		bool write_position_enable;
		bool write_velocity_enable;
		bool write_torque_enable;
		bool write_led_enable;
		bool write_torque_on_enable;
		bool write_tool_enable;

		std::shared_ptr<std::thread> async_thread_;
		std::atomic_bool async_thread_shutdown_;
		bool initialized_;

		std::shared_ptr<std::thread> dxl_connection_loop_thread;

		void manageDxlConnection();
		void checkHardwareVersionFromDxlMotors();
		int detectVersion();

		uint32_t rad_pos_to_xl320_pos(double position_rad);
		double xl320_pos_to_rad_pos(uint32_t position_dxl);

		uint32_t rad_pos_to_xl430_pos(double position_rad);
		double xl430_pos_to_rad_pos(uint32_t position_dxl);
	};
}

#endif
