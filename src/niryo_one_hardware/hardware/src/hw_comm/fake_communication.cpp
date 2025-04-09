#include "niryo_one_hardware/fake_communication.hpp"

FakeCommunication::FakeCommunication(
		int hardware_version, FakeCommunicationConfig cfg) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Starting Fake Communication... It will just echo cmd into "
			"current position");

	this->hardware_version = hardware_version;

	if (hardware_version == 1) {
		echo_pos[0] = cfg.pos_0;
		echo_pos[1] = cfg.pos_1;
		echo_pos[2] = cfg.pos_2;
		echo_pos[3] = cfg.pos_3;
		echo_pos[4] = 0.0;
		echo_pos[5] = 0.0;
	} else if (hardware_version == 2) {
		echo_pos[0] = cfg.pos_0;
		echo_pos[1] = cfg.pos_1;
		echo_pos[2] = cfg.pos_2;
		echo_pos[3] = 0.0;
		echo_pos[4] = 0.0;
		echo_pos[5] = 0.0;
	}
}

int FakeCommunication::init() {
	return 0;  // Success
}

void FakeCommunication::manageHardwareConnection() {
	// No hardware, nothing to manage
}

void FakeCommunication::startHardwareControlLoop() {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Start hardware control loop : nothing to do in fake mode.");
}

void FakeCommunication::stopHardwareControlLoop() {
	// Nothing
}

void FakeCommunication::resumeHardwareControlLoop() {
	// Nothing
}

void FakeCommunication::synchronizeMotors(bool begin_traj) {
	// Nothing
}

bool FakeCommunication::isConnectionOk() {
	return true;
}

int FakeCommunication::allowMotorsCalibrationToStart(
		int mode, std::string & /*result_message*/) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Motor calibration with mode : %d", mode);
	return 200;
}

void FakeCommunication::requestNewCalibration() {
	// Nothing
}

bool FakeCommunication::isCalibrationInProgress() {
	return false;
}

void FakeCommunication::sendPositionToRobot(const double cmd[6]) {
	for (int i = 0; i < 6; i++) {
		echo_pos[i] = cmd[i];
	}
}

void FakeCommunication::getCurrentPosition(double pos[6]) {
	for (int i = 0; i < 6; i++) {
		pos[i] = echo_pos[i];
	}
}

void FakeCommunication::addCustomDxlCommand(int motor_type, uint8_t id,
		uint32_t value, uint32_t reg_address, uint32_t byte_number) {
	RCLCPP_INFO(
			rclcpp::get_logger("Fake Communication"), "Add custom Dxl command");
}

void FakeCommunication::rebootMotors() {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"), "Reboot Motors");
}

void FakeCommunication::getHardwareStatus(bool *is_connection_ok,
		std::string & /*error_message*/, int *calibration_needed,
		bool *calibration_in_progress, std::vector<std::string> &motor_names,
		std::vector<std::string> &motor_types,
		std::vector<int32_t> &temperatures, std::vector<double> &voltages,
		std::vector<int32_t> &hw_errors) {
	//RCLCPP_INFO(rclcpp::get_logger("Fake Communication"), "Get Hardware Status");
	*(is_connection_ok) = true;
	*(calibration_needed) = false;
	*(calibration_in_progress) = false;
}

void FakeCommunication::getFirmwareVersions(
		std::vector<std::string> &motor_names,
		std::vector<std::string> &firmware_versions) {
	// RCLCPP_INFO(rclcpp::get_logger("Fake Communication"), "Get firmware versions")
}

void FakeCommunication::activateLearningMode(bool activate) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Activate learning mode : %d", activate);
}

bool FakeCommunication::setLeds(std::vector<int> &leds, std::string &message) {
	//    RCLCPP_INFO(rclcpp::get_logger("Fake Communication"), "Set leds");
	return true;
}

int FakeCommunication::pullAirVacuumPump(
		uint8_t id, uint16_t pull_air_position, uint16_t pull_air_hold_torque) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Pull air on vacuum pump with id : %03d", id);
	return VACUUM_PUMP_STATE_PULLED;
}
int FakeCommunication::pushAirVacuumPump(
		uint8_t id, uint16_t push_air_position) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Push air on vacuum pump with id : %03d", id);
	return VACUUM_PUMP_STATE_PUSHED;
}

int FakeCommunication::pingAndSetDxlTool(uint8_t id, std::string name) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Ping gripper with id : %03d", id);
	return TOOL_STATE_PING_OK;
}
int FakeCommunication::pingAndSetConveyor(
		uint8_t id, bool activate, std::string &message) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"activate stepper with id : %03d", id);
	return TOOL_STATE_PING_OK;
}
int FakeCommunication::moveConveyor(uint8_t id, bool activate, int16_t speed,
		int8_t direction, std::string &message) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"move stepper with id : %03d", id);
	return TOOL_STATE_PING_OK;
}
int FakeCommunication::updateIdConveyor(
		uint8_t old_id, uint8_t new_id, std::string &message) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"update  conveyor id  with id : %03d", new_id);
	return TOOL_STATE_PING_OK;
}

void FakeCommunication::getConveyorFeedBack(uint8_t conveyor_id,
		bool *connection_state, bool *running, int16_t *speed,
		int8_t *direction) {
	//nothing
}

int FakeCommunication::openGripper(uint8_t id, uint16_t open_position,
		uint16_t open_speed, uint16_t open_hold_torque) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Open gripper with id : %03d", id);
	return GRIPPER_STATE_OPEN;
}

int FakeCommunication::closeGripper(uint8_t id, uint16_t close_position,
		uint16_t close_speed, uint16_t close_hold_torque,
		uint16_t close_max_torque) {
	RCLCPP_INFO(rclcpp::get_logger("Fake Communication"),
			"Close gripper with id : %03d", id);
	return GRIPPER_STATE_CLOSE;
}
