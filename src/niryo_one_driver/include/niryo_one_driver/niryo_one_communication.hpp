#ifndef NIRYO_COMMUNICATION_H
#define NIRYO_COMMUNICATION_H

#include "rclcpp/rclcpp.hpp"
#include <memory>
#include <string>
#include <thread>

#include "niryo_one_driver/can_communication.hpp"
#include "niryo_one_driver/dxl_communication.hpp"

#include "niryo_one_driver/communication_base.hpp"

#include "niryo_one_driver/change_hardware_version.hpp"

class NiryoOneCommunication: public CommunicationBase {
	public:
	NiryoOneCommunication(int hardware_version);
	int init();

	void manageHardwareConnection();
	bool isConnectionOk();

	void startHardwareControlLoop();
	void stopHardwareControlLoop();
	void resumeHardwareControlLoop();

	void getCurrentPosition(double pos[6]);

	void getHardwareStatus(bool *is_connection_ok, std::string &error_message,
			int *calibration_needed, bool *calibration_in_progress,
			std::vector<std::string> &motor_names,
			std::vector<std::string> &motor_types,
			std::vector<int32_t> &temperatures, std::vector<double> &voltages,
			std::vector<int32_t> &hw_errors);

	void getFirmwareVersions(std::vector<std::string> &motor_names,
			std::vector<std::string> &firmware_versions);

	void sendPositionToRobot(const double cmd[6]);
	void activateLearningMode(bool activate);
	bool setLeds(std::vector<int> &leds, std::string &message);

	int allowMotorsCalibrationToStart(int mode, std::string &result_message);
	void requestNewCalibration();
	bool isCalibrationInProgress();

	// conveyor belt
	int pingAndSetConveyor(uint8_t id, bool activate, std::string &message);
	int moveConveyor(uint8_t id, bool activate, int16_t speed, int8_t direction,
			std::string &message);
	int updateIdConveyor(uint8_t old_id, uint8_t new_id, std::string &message);
	void geCurrentConveyorStatus(
			int *status_conveyor_1, int *status_conveyor_2);
	void getConveyorFeedBack(uint8_t conveyor_id, bool *connection_state,
			bool *running, int16_t *speed, int8_t *direction);

	// Tools
	int pingAndSetDxlTool(uint8_t id, std::string name);

	int openGripper(uint8_t id, uint16_t open_position, uint16_t open_speed,
			uint16_t open_hold_torque);
	int closeGripper(uint8_t id, uint16_t close_position, uint16_t close_speed,
			uint16_t close_hold_torque, uint16_t close_max_torque);

	int pullAirVacuumPump(uint8_t id, uint16_t pull_air_position,
			uint16_t pull_air_hold_torque);
	int pushAirVacuumPump(uint8_t id, uint16_t push_air_position);

	// Steppers
	void synchronizeMotors(bool begin_traj);

	// Check hardware version (V1/V2)
	void checkHardwareVersionFromDxlMotors();

	void addCustomDxlCommand(int motor_type, uint8_t id, uint32_t value,
			uint32_t reg_address, uint32_t byte_number);

	void rebootMotors();

	private:
	int hardware_version;

	std::shared_ptr<DxlCommunication> dxlComm;
	std::shared_ptr<CanCommunication> canComm;

	bool can_enabled;
	bool dxl_enabled;

	double niryo_one_hw_check_connection_frequency;

	std::shared_ptr<std::thread> hardware_connection_loop_thread;
	std::shared_ptr<std::thread> can_connection_loop_thread;
	std::shared_ptr<std::thread> dxl_connection_loop_thread;

	void manageHardwareConnectionLoop();
	void manageCanConnectionLoop();
	void manageDxlConnectionLoop();

	bool scanAndCheckMotors();

	// Used when can or dxl is disabled
	double pos_can_disabled_v1[4] = {0.0, 0.628, -1.4, 0.0};
	double pos_dxl_disabled_v1[2] = {0.0, 0.0};

	double pos_can_disabled_v2[3] = {0.0, 0.628, -1.4};
	double pos_dxl_disabled_v2[3] = {0.0, 0.0, 0.0};

	// For new calibration request
	bool new_calibration_requested;

	bool niryo_one_comm_ok;
	bool can_comm_ok;
	bool dxl_comm_ok;
};

#endif
