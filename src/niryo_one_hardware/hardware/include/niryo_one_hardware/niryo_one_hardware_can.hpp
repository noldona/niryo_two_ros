#ifndef NIRYO_ONE_HARDWARE_CAN_H
#define NIRYO_ONE_HARDWARE_CAN_H

#include <string>
#include <unordered_map>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"

#include "niryo_one_hardware/motor_offset_file_handler.hpp"
#include "niryo_one_hardware/niryo_one_can_driver.hpp"

#include "niryo_one_hardware/interface_constants.hpp"
// #include "niryo_one_hardware/test_motors.hpp"

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
#define CAN_SCAN_NOT_ALLOWED -10002
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

using hardware_interface::return_type;

namespace niryo_one_hardware {

	using CallbackReturn = rclcpp_lifecycle::node_interfaces::
			LifecycleNodeInterface::CallbackReturn;

	class NiryoOneHardwareCan: public hardware_interface::SystemInterface {
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
		int spi_channel;
		int spi_baudrate;
		int gpio_can_interrupt;

		std::shared_ptr<NiryoCanDriver> can;

		bool can_enabled;
		double niryo_one_hw_check_connection_frequency;

		// For hardware control
		bool is_can_connection_ok;

		uint8_t torque_on;  // torque is ON/OFF for all motors at the same time

		double time_hw_last_write;  // 100 Hz
		double time_hw_last_check_connection;  // 2 Hz
		double hw_write_frequency;  // 200 Hz
		double hw_check_connection_frequency;

		double hw_control_loop_frequency;
		bool hw_control_loop_keep_alive;
		bool hw_is_busy;
		bool hw_limited_mode;

		// Enable flags
		bool write_position_enable;
		bool write_torque_enable;
		bool write_torque_on_enable;

		bool write_synchronize_enable;
		bool write_micro_steps_enable;
		bool write_max_effort_enable;

		// Calibration
		bool waiting_for_user_trigger_calibration;
		int steppers_calibration_mode;
		bool write_synchronize_begin_traj;
		bool calibration_in_progress;
		int calibration_timeout;

		bool new_calibration_requested;

		std::shared_ptr<std::thread> async_thread_;
		std::atomic_bool async_thread_shutdown_;
		bool initialized_;

		std::shared_ptr<std::thread> can_connection_loop_thread;

		void manageCanConnection();
		int scanAndCheck();
		void setTorqueOn(bool on);
		void stopHardwareControlLoop();
		void startHardwareControlLoop(bool limited_mode);
		void activateLearningMode(bool activate);
		int calibrateMotors(int calibration_step);
		int manualCalibration();
		int autoCalibrationStep1();
		int autoCalibrationStep2();
		int relativeMoveMotor(hardware_interface::ComponentInfo joint,
				int steps, int delay, bool wait);
		int32_t rad_pos_to_steps(
				double position_rad, double gear_ratio, double direction);
		double steps_to_rad_pos(
				int32_t steps, double gear_ratio, double direction);
		int sendCalibrationCommandForOneMotor(
				hardware_interface::ComponentInfo joint,
				int delay_between_steps, int calibration_direction,
				int calibr_timeout);
		int getCalibrationResults(
				std::vector<hardware_interface::ComponentInfo> joints,
				int calibr_timeout, std::vector<int> &sensor_offset_ids,
				std::vector<int> &sensor_offset_steps);

		void calibrateMotors();
		void requestNewCalibration();
		void testMotors();
		void activateLearningMode();
		void activateLeds();
		void pingAndSetDxlTool();
		void openGripper();
		void closeGripper();
		void pullAirVacuumPump();
		void pushAirVacuumPump();
		void changeHardwareVersion();
		void rebootMotors();

		int allowMotorsCalibrationToStart(
				int mode, std::string &result_message);
		bool canProcessManualCalibration();
		void validateMotorsCalibrationFromUserInput(int mode);
		void hardwareControlRead();
		void hardwareControlWrite();
		void hardwareControlCheckConnection();
	};
}

#endif
