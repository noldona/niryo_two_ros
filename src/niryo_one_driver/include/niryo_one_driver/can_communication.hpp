#ifndef NIRYO_CAN_COMMUNICATION_H
#define NIRYO_CAN_COMMUNICATION_H

#include "rclcpp/rclcpp.hpp"
#include <cmath>
#include <memory>
#include <string>
#include <thread>
#include <time.h>

#include "niryo_one_driver/motor_offset_file_handler.hpp"
#include "niryo_one_driver/niryo_one_can_driver.hpp"
#include "niryo_one_driver/stepper_motor_state.hpp"

#define TIME_TO_WAIT_IF_BUSY 500  // microseconds

// Those ids need to be used in niryo_one_motors.yaml to enable/disable some stepper motors
#define CAN_MOTOR_1_ID 1
#define CAN_MOTOR_2_ID 2
#define CAN_MOTOR_3_ID 3
#define CAN_MOTOR_4_ID 4

// All motors have positive filter for their own id + this one
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

class CanCommunication: public rclcpp::Node {
	public:
	CanCommunication(): Node("can_communication") {}
	int init(int hardware_version);
	int setupCommunication();

	void startHardwareControlLoop(bool limited_mode);
	void stopHardwareControlLoop();

	void setGoalPositionV1(double axis_1_pos_goal, double axis_2_pos_goal,
			double axis_3_pos_goal, double axis_4_pos_goal);
	void setGoalPositionV2(double axis_1_pos_goal, double axis_2_pos_goal,
			double axis_3_pos_goal);
	void getCurrentPositionV1(double *axis_1_pos, double *axis_2_pos,
			double *axis_3_pos, double *axis_4_pos);
	void getCurrentPositionV2(
			double *axis_1_pos, double *axis_2_pos, double *axis_3_pos);

	void getHardwareStatus(bool *is_connection_ok, std::string &error_message,
			int *calibration_needed, bool *calibration_in_progress,
			std::vector<std::string> &motor_names,
			std::vector<std::string> &motor_types,
			std::vector<int32_t> &temperatures, std::vector<double> &voltages,
			std::vector<int32_t> &hw_errors);
	void getFirmwareVersions(std::vector<std::string> &motor_names,
			std::vector<std::string> &firmware_versions);
	bool isConnectionOk();
	bool isOnLimitedMode();

	void setTorqueOn(bool on);

	void setMicroSteps(std::vector<uint8_t> micro_steps_list);
	void setMaxEffort(std::vector<uint8_t> max_effort_list);

	int getCalibrationMode();
	bool isCalibrationInProgress();
	int calibrateMotors(int calibration_step);
	int manualCalibration();
	int autoCalibrationStep1();
	int autoCalibrationStep2();
	int sendCalibrationCommandForOneMotor(StepperMotorState *motor,
			int delay_between_steps, int calibration_direction,
			int calibration_timeout);
	int getCalibrationResults(std::vector<StepperMotorState *> steppers,
			int calibration_timeout, std::vector<int> &sensor_offset_ids,
			std::vector<int> &sensor_offset_steps);

	int scanAndCheck();

	bool canProcessManualCalibration(std::string &result_message);
	void validateMotorsCalibrationFromUserInput(int mode);
	void setCalibrationFlag(bool flag);

	void synchronizeSteppers(bool begin_traj);
	int setConveyor(uint8_t id, bool activate);
	int conveyorOn(uint8_t id, bool activate, int16_t speed, int8_t direction);
	int updateConveyorId(uint8_t id, uint8_t new_id_up);

	void getConveyorFeedBack(uint8_t conveyor_id, bool *connection_state,
			bool *running, int16_t *speed, int8_t *direction);
	// Conveyor reset flags
	void resetConveyor(uint8_t conveyor_id);

	private:
	// Niryo One hardware version
	int hardware_version;
	int64_t spi_channel;
	int64_t spi_baudrate;
	int64_t gpio_can_interrupt;

	std::shared_ptr<NiryoCanDriver> can;

	std::vector<int64_t> required_steppers_ids;
	std::vector<int64_t> allowed_steppers_ids;

	// For hardware control
	bool is_can_connection_ok;
	std::string debug_error_message;

	uint8_t torque_on;  // Torque is ON/OFF for all motors at the same time

	double time_hw_last_write;  // 100 Hz
	double time_hw_last_check_connection;  // 2 Hz
	double hw_write_frequency;  // 200 Hz
	double hw_check_connection_frequency;

	double hw_control_loop_frequency;
	bool hw_control_loop_keep_alive;
	bool hw_is_busy;
	bool hw_limited_mode;

	// Check if a stepper is connected (external stepper)
	bool is_conveyor_id_1_connected;
	bool is_conveyor_id_2_connected;
	bool conveyor_id_1_state;
	bool conveyor_id_2_state;

	bool is_conveyor_id_1_on;
	bool is_conveyor_id_2_on;
	int conveyor_id_1_speed;
	int conveyor_id_2_speed;
	int8_t conveyor_id_1_direction;
	int8_t conveyor_id_2_direction;

	bool update_id;
	uint8_t new_id;
	uint8_t old_id;

	void hardwareControlLoop();
	void hardwareControlRead();
	void hardwareControlWrite();
	void hardwareControlCheckConnection();
	void resetHardwareControlLoopRates();

	std::shared_ptr<std::thread> hardware_control_loop_thread;

	StepperMotorState m1;
	StepperMotorState m2;
	StepperMotorState m3;
	StepperMotorState m4;  // NOT used for Niryo One V2
	StepperMotorState m6;  // Conveyor belt 1
	StepperMotorState m7;  // Conveyor belt 2

	std::vector<StepperMotorState *> motors;
	std::vector<StepperMotorState *> allowed_motors;

	// Enable flags (no read flag)
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
	int64_t calibration_timeout;

	int relativeMoveMotor(
			StepperMotorState *motor, int steps, int delay, bool wait);

	// Conversions steps <-> rad angle
	int32_t rad_pos_to_steps(
			double position_rad, double gear_ratio, double direction);
	double steps_to_rad_pos(int32_t steps, double gear_ratio, double direction);

	rclcpp::Clock clock = rclcpp::Clock();
};

#endif
