#include "niryo_one_driver/niryo_one_communication.hpp"

NiryoOneCommunication::NiryoOneCommunication(int hardware_version) {
	this->hardware_version = hardware_version;

	this->declare_parameter("~can_enabled", rclcpp::PARAMETER_BOOL);
	this->declare_parameter("~dxl_enabled", rclcpp::PARAMETER_BOOL);
	this->declare_parameter("~niryo_one_hw_check_connection_frequency",
			rclcpp::PARAMETER_DOUBLE);
	this->can_enabled = this->get_parameter("~can_enabled").as_bool();
	this->dxl_enabled = this->get_parameter("~dxl_enabled").as_bool();
	this->niryo_one_hw_check_connection_frequency =
			this->get_parameter("~niryo_one_hw_check_connection_frequency")
					.as_double();

	if (!this->can_enabled) {
		RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
				"CAN communication is disabled for debug purposes");
	}
	if (!this->dxl_enabled) {
		RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
				"DXL communication is disabled for debug purposes");
	}

	if (this->can_enabled) {
		this->canComm.reset(new CanCommunication());
	}

	if (this->dxl_enabled) {
		this->dxlComm.reset(new DxlCommunication());
	}

	this->new_calibration_requested = false;
	this->niryo_one_comm_ok = false;
	this->can_comm_ok = false;
	this->dxl_comm_ok = false;
}

int NiryoOneCommunication::init() {
	int result = 0;
	if (this->can_enabled) {
		result = this->canComm->init(hardware_version);
		if (result != 0) {
			return result;
		}
	}
	if (this->dxl_enabled) {
		result = this->dxlComm->init(hardware_version);
		if (result != 0) {
			return result;
		}
	}
	return result;
}

bool NiryoOneCommunication::scanAndCheckMotors() {
	bool result = true;
	if (this->can_enabled) {
		result = ((this->canComm->scanAndCheck() == CAN_SCAN_OK) && result);
	}
	if (this->dxl_enabled) {
		result = ((this->dxlComm->scanAndCheck() == DXL_SCAN_OK) && result);
	}
	this->niryo_one_comm_ok = result;
	return result;
}

bool NiryoOneCommunication::isConnectionOk() {
	bool result = true;
	if (this->can_enabled) {
		result = ((this->canComm->isConnectionOk()) && result);
	}
	if (this->dxl_enabled) {
		result = ((this->dxlComm->isConnectionOk()) && result);
	}
	this->niryo_one_comm_ok = result;
	return result;
}

void NiryoOneCommunication::manageCanConnectionLoop() {
	if (!this->can_enabled) {
		return;
	}

	rclcpp::Rate check_connection_rate =
			rclcpp::Rate(this->niryo_one_hw_check_connection_frequency);
	bool motors_ok = false;

	while (rclcpp::ok()) {
		if (!this->canComm->isConnectionOk() ||
				this->new_calibration_requested) {
			this->new_calibration_requested = false;
			RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
					"Stop Can hw control");
			this->canComm->stopHardwareControlLoop();
			rclcpp::sleep_for(std::chrono::milliseconds(100));

			while (this->canComm->scanAndCheck() !=
					CAN_SCAN_OK) {  // Wait for connection to be up
				RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
						"Scan to find stepper motors...");
				rclcpp::sleep_for(std::chrono::milliseconds(250));
			}

			// Once connected, set calibration flag
			RCLCPP_INFO(rclcpp::get_logger("NiryoOneCommunication"),
					"Set calibration flag");
			this->canComm->setCalibrationFlag(true);

			// Deactivate motors (?)
			this->canComm->setTorqueOn(false);

			this->canComm->startHardwareControlLoop(true);  // Limited mode
			motors_ok = false;

			while (!motors_ok) {
				int calibration_step1_result = CAN_STEPPERS_CALIBRATION_FAIL;
				int calibration_step2_result = CAN_STEPPERS_CALIBRATION_FAIL;

				calibration_step1_result = this->canComm->calibrateMotors(1);
				if (calibration_step1_result == CAN_STEPPERS_CALIBRATION_OK) {
					if (this->dxl_enabled) {
						if (this->canComm->getCalibrationMode() ==
								CAN_STEPPERS_CALIBRATION_MODE_AUTO) {
							RCLCPP_INFO(
									rclcpp::get_logger("NiryoOneCommunication"),
									"Asking Dynamixel motors to go to home "
									"position");
							this->dxlComm->moveAllMotorsToHomePosition();
						}
					}
					calibration_step2_result =
							this->canComm->calibrateMotors(2);
				}

				if ((calibration_step1_result == CAN_STEPPERS_CALIBRATION_OK) &&
						(calibration_step2_result ==
								CAN_STEPPERS_CALIBRATION_OK)) {
					motors_ok = true;
					this->new_calibration_requested = false;
					activateLearningMode(true);
				} else {  // if calibration is not ok, wait and retry
					// check if connection is still ok
					if (!this->canComm->isConnectionOk()) {
						while (this->canComm->scanAndCheck() !=
								CAN_SCAN_OK) {  // wait for connection to be up
							RCLCPP_WARN(
									rclcpp::get_logger("NiryoOneCommunication"),
									"Scan to find stepper motors...");
							rclcpp::sleep_for(std::chrono::milliseconds(250));
						}
					}

					// last calibration has failed, reset flag
					if (calibration_step1_result !=
							CAN_STEPPERS_CALIBRATION_WAITING_USER_INPUT) {
						this->canComm->setCalibrationFlag(true);
						// go back to limited mode (during calibration, hw control loop is stopped)
						this->canComm->startHardwareControlLoop(true);
					}

					rclcpp::sleep_for(std::chrono::milliseconds(250));
				}
			}

			RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
					"Resume can hw control");
			this->activateLearningMode(true);
			if (this->dxl_enabled) {
				this->canComm->startHardwareControlLoop(
						!this->dxlComm->isConnectionOk());
			} else {
				this->canComm->startHardwareControlLoop(false);
			}
		} else {  // can connection ok + calibrated
			if (this->dxl_enabled && !this->dxlComm->isConnectionOk()) {
				if (!this->canComm->isOnLimitedMode()) {
					this->canComm->startHardwareControlLoop(true);
				}
			} else {
				if (this->canComm->isOnLimitedMode()) {
					this->canComm->setTorqueOn(false);
					this->canComm->startHardwareControlLoop(false);
				}
			}
		}
		check_connection_rate.sleep();
	}
}

// stepper niryo one conveyor belt test is here
int NiryoOneCommunication::pingAndSetConveyor(
		uint8_t id, bool activate, std::string &message) {
	if (this->can_enabled) {
		int res = this->canComm->setConveyor(id, activate);
		if (res == CONVEYOR_STATE_SET_OK)
			message = " Set conveyor OK ";
		else
			message = "Set conveyor ERROR";
		return res;
	}
	message = " Set conveyor ERROR ";
	return CONVEYOR_STATE_SET_ERROR;
}

// stepper niryo one conveyor belt test is here
int NiryoOneCommunication::moveConveyor(uint8_t id, bool activate,
		int16_t speed, int8_t direction, std::string &message) {
	if (this->can_enabled) {
		int res = this->canComm->conveyorOn(id, activate, speed, direction);
		if (res == CONVEYOR_CONTROL_OK) {
			message = "Command conveyor OK";
		} else
			message = "Command conveyor ERROR";

		return res;
	}
	message = "Can problem";
	return CONVEYOR_CONTROL_ERROR;
}
int NiryoOneCommunication::updateIdConveyor(
		uint8_t old_id, uint8_t new_id, std::string &message) {
	if (this->can_enabled) {
		int res = this->canComm->updateConveyorId(old_id, new_id);
		if (res == CONVEYOR_UPDATE_ID_OK) {
			message = " Update conveyor  OK ";
			return res;
		} else {
			message = " Update conveyor  ERROR ";
			return res;
		}
	}
	message = "Can problem";
	return CONVEYOR_UPDATE_ID_ERROR;
}

void NiryoOneCommunication::getConveyorFeedBack(uint8_t conveyor_id,
		bool *connection_state, bool *running, int16_t *speed,
		int8_t *direction) {
	if (this->can_enabled) {
		this->canComm->getConveyorFeedBack(
				conveyor_id, connection_state, running, speed, direction);
	}
}
void NiryoOneCommunication::checkHardwareVersionFromDxlMotors() {
	// Check if hardware_version is compatible
	// The purpose here is retro-compatibility with version 1.
	// Version 2 is the default
	// If the robot is still V1 (old version) we can detect it from
	// Dynamixel motors setup, and automatically change the version
	// used, without any user input
	int detected_version = -1;
	detected_version = this->dxlComm->detectVersion();
	while (detected_version < 0) {
		RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
				"Scan to find Dxl motors + Check hardware version");
		detected_version = this->dxlComm->detectVersion();
		rclcpp::sleep_for(std::chrono::milliseconds(250));
	}

	RCLCPP_INFO(rclcpp::get_logger("NiryoOneCommunication"),
			"Detected version from hardware : %d", detected_version);

	if (detected_version == 0) {
		// version could not be detected from current hardware setup
		// it seems that some motors have been disabled for debug purposes
		// --> continue like nothing happened
	} else if ((detected_version == 1 && this->hardware_version == 2) ||
			(detected_version == 2 && this->hardware_version == 1)) {
		// change version (V1->V2 or V2->V1) and reboot
		change_hardware_version_and_reboot(
				this->hardware_version, detected_version);
	}
}

void NiryoOneCommunication::manageDxlConnectionLoop() {
	if (!this->dxl_enabled) {
		return;
	}

	checkHardwareVersionFromDxlMotors();

	rclcpp::Rate check_connection_rate =
			rclcpp::Rate(niryo_one_hw_check_connection_frequency);

	while (rclcpp::ok()) {
		if (!this->dxlComm->isConnectionOk()) {
			RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
					"Stop Dxl hw control");
			this->dxlComm->stopHardwareControlLoop();
			rclcpp::sleep_for(std::chrono::milliseconds(100));

			while (dxlComm->scanAndCheck() !=
					DXL_SCAN_OK) {  // wait for connection to be up
				RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
						"Scan to find Dxl motors");
				rclcpp::sleep_for(std::chrono::milliseconds(250));
			}

			RCLCPP_WARN(rclcpp::get_logger("NiryoOneCommunication"),
					"Resume Dxl hw control");
			this->dxlComm->setTorqueOn(false);
			activateLearningMode(true);
			if (this->can_enabled) {
				this->dxlComm->startHardwareControlLoop(
						!this->canComm->isConnectionOk());
			} else {
				this->dxlComm->startHardwareControlLoop(false);
			}
		} else {  // dxl connection ok
			if (this->can_enabled && !this->canComm->isConnectionOk()) {
				if (!this->dxlComm->isOnLimitedMode()) {
					this->dxlComm->startHardwareControlLoop(true);
				}
			} else {
				if (this->dxlComm->isOnLimitedMode()) {
					this->dxlComm->setTorqueOn(false);
					this->dxlComm->startHardwareControlLoop(false);
				}
			}
		}
		check_connection_rate.sleep();
	}
}

void NiryoOneCommunication::manageHardwareConnection() {
	this->can_connection_loop_thread.reset(new std::thread(
			std::bind(&NiryoOneCommunication::manageCanConnectionLoop, this)));
	this->dxl_connection_loop_thread.reset(new std::thread(
			std::bind(&NiryoOneCommunication::manageDxlConnectionLoop, this)));
}

void NiryoOneCommunication::startHardwareControlLoop() {
	if (this->can_enabled) {
		this->canComm->startHardwareControlLoop(false);
	}
	if (this->dxl_enabled) {
		this->dxlComm->startHardwareControlLoop(false);
	}
}

void NiryoOneCommunication::stopHardwareControlLoop() {
	if (this->can_enabled) {
		this->canComm->stopHardwareControlLoop();
	}
	if (this->dxl_enabled) {
		this->dxlComm->stopHardwareControlLoop();
	}
}

void NiryoOneCommunication::resumeHardwareControlLoop() {
	if (this->can_enabled) {
		this->canComm->startHardwareControlLoop(false);
	}
	if (this->dxl_enabled) {
		this->dxlComm->startHardwareControlLoop(false);
	}
}

void NiryoOneCommunication::synchronizeMotors(bool begin_traj) {
	if (this->can_enabled) {
		this->canComm->synchronizeSteppers(begin_traj);
	}
}

int NiryoOneCommunication::allowMotorsCalibrationToStart(
		int mode, std::string &result_message) {
	if (this->can_enabled) {
		if (mode == CAN_STEPPERS_CALIBRATION_MODE_MANUAL) {
			if (!this->canComm->canProcessManualCalibration(result_message)) {
				return 400;
			}
		}
		this->canComm->validateMotorsCalibrationFromUserInput(mode);
	}
	if (this->dxl_enabled) {
		// TODO: check dxl in bounds
	}

	result_message = "Calibration is starting";
	return 200;
}

void NiryoOneCommunication::requestNewCalibration() {
	this->new_calibration_requested = true;
}

bool NiryoOneCommunication::isCalibrationInProgress() {
	if (this->can_enabled) {
		return this->canComm->isCalibrationInProgress();
	}
	return false;
}

void NiryoOneCommunication::getHardwareStatus(bool *is_connection_ok,
		std::string &error_message, int *calibration_needed,
		bool *calibration_in_progress, std::vector<std::string> &motor_names,
		std::vector<std::string> &motor_types,
		std::vector<int32_t> &temperatures, std::vector<double> &voltages,
		std::vector<int32_t> &hw_errors) {
	bool can_connection_ok =
			!can_enabled;  // if CAN disabled, declare connection ok
	int can_calibration_needed = 0;
	bool can_calibration_in_progress = false;
	std::string can_error_message = "";
	std::vector<std::string> can_motor_names;
	std::vector<std::string> can_motor_types;
	std::vector<int32_t> can_temperatures;
	std::vector<double> can_voltages;
	std::vector<int32_t> can_hw_errors;

	bool dxl_connection_ok =
			!dxl_enabled;  // if Dxl disabled, declare connection ok
	int dxl_calibration_needed = 0;
	bool dxl_calibration_in_progress = false;
	std::string dxl_error_message = "";
	std::vector<std::string> dxl_motor_names;
	std::vector<std::string> dxl_motor_types;
	std::vector<int32_t> dxl_temperatures;
	std::vector<double> dxl_voltages;
	std::vector<int32_t> dxl_hw_errors;

	if (this->can_enabled) {
		this->canComm->getHardwareStatus(&can_connection_ok, can_error_message,
				&can_calibration_needed, &can_calibration_in_progress,
				can_motor_names, can_motor_types, can_temperatures,
				can_voltages, can_hw_errors);
	}
	if (this->dxl_enabled) {
		this->dxlComm->getHardwareStatus(&dxl_connection_ok, dxl_error_message,
				&dxl_calibration_needed, &dxl_calibration_in_progress,
				dxl_motor_names, dxl_motor_types, dxl_temperatures,
				dxl_voltages, dxl_hw_errors);
	}

	motor_names.clear();
	motor_types.clear();
	temperatures.clear();
	voltages.clear();
	hw_errors.clear();

	motor_names.insert(
			motor_names.end(), can_motor_names.begin(), can_motor_names.end());
	motor_names.insert(
			motor_names.end(), dxl_motor_names.begin(), dxl_motor_names.end());
	motor_types.insert(
			motor_types.end(), can_motor_types.begin(), can_motor_types.end());
	motor_types.insert(
			motor_types.end(), dxl_motor_types.begin(), dxl_motor_types.end());
	temperatures.insert(temperatures.end(), can_temperatures.begin(),
			can_temperatures.end());
	temperatures.insert(temperatures.end(), dxl_temperatures.begin(),
			dxl_temperatures.end());
	voltages.insert(voltages.end(), can_voltages.begin(), can_voltages.end());
	voltages.insert(voltages.end(), dxl_voltages.begin(), dxl_voltages.end());
	hw_errors.insert(
			hw_errors.end(), can_hw_errors.begin(), can_hw_errors.end());
	hw_errors.insert(
			hw_errors.end(), dxl_hw_errors.begin(), dxl_hw_errors.end());

	*(is_connection_ok) = (can_connection_ok && dxl_connection_ok);
	*(calibration_needed) = (can_calibration_needed || dxl_calibration_needed);
	*(calibration_in_progress) =
			(can_calibration_in_progress || dxl_calibration_in_progress);
	error_message = "";
	error_message += can_error_message;
	if (dxl_error_message != "") {
		error_message += "\n";
	}
	error_message += dxl_error_message;
}

void NiryoOneCommunication::getFirmwareVersions(
		std::vector<std::string> &motor_names,
		std::vector<std::string> &firmware_versions) {
	std::vector<std::string> can_firmware_versions;
	std::vector<std::string> can_motor_names;

	if (this->can_enabled) {
		this->canComm->getFirmwareVersions(
				can_motor_names, can_firmware_versions);
	}

	motor_names.clear();
	firmware_versions.clear();

	firmware_versions.insert(firmware_versions.end(),
			can_firmware_versions.begin(), can_firmware_versions.end());
	motor_names.insert(
			motor_names.end(), can_motor_names.begin(), can_motor_names.end());
}

void NiryoOneCommunication::getCurrentPosition(double pos[6]) {
	if (this->hardware_version == 1) {
		if (this->can_enabled) {
			this->canComm->getCurrentPositionV1(
					&pos[0], &pos[1], &pos[2], &pos[3]);
		}
		if (this->dxl_enabled) {
			this->dxlComm->getCurrentPositionV1(&pos[4], &pos[5]);
		}

		// if disabled (debug purposes)
		if (!this->can_enabled) {
			pos[0] = this->pos_can_disabled_v1[0];
			pos[1] = this->pos_can_disabled_v1[1];
			pos[2] = this->pos_can_disabled_v1[2];
			pos[3] = this->pos_can_disabled_v1[3];
		}

		if (!this->dxl_enabled) {
			pos[4] = this->pos_dxl_disabled_v1[0];
			pos[5] = this->pos_dxl_disabled_v1[1];
		}
	} else if (this->hardware_version == 2) {
		if (this->can_enabled) {
			this->canComm->getCurrentPositionV2(&pos[0], &pos[1], &pos[2]);
		}
		if (this->dxl_enabled) {
			this->dxlComm->getCurrentPositionV2(&pos[3], &pos[4], &pos[5]);
		}

		// if disabled (debug purposes)
		if (!this->can_enabled) {
			pos[0] = this->pos_can_disabled_v2[0];
			pos[1] = this->pos_can_disabled_v2[1];
			pos[2] = this->pos_can_disabled_v2[2];
		}

		if (!this->dxl_enabled) {
			pos[3] = this->pos_dxl_disabled_v2[0];
			pos[4] = this->pos_dxl_disabled_v2[1];
			pos[5] = this->pos_dxl_disabled_v2[2];
		}
	}
}

void NiryoOneCommunication::sendPositionToRobot(const double cmd[6]) {
	bool is_calibration_in_progress = false;
	if (this->can_enabled) {
		is_calibration_in_progress = this->canComm->isCalibrationInProgress();
	}

	// don't send position command when calibrating motors
	if (!is_calibration_in_progress) {
		if (this->hardware_version == 1) {
			if (this->can_enabled) {
				this->canComm->setGoalPositionV1(
						cmd[0], cmd[1], cmd[2], cmd[3]);
			}
			if (this->dxl_enabled) {
				this->dxlComm->setGoalPositionV1(cmd[4], cmd[5]);
			}

			// if disabled (debug purposes)
			if (!this->can_enabled) {
				this->pos_can_disabled_v1[0] = cmd[0];
				this->pos_can_disabled_v1[1] = cmd[1];
				this->pos_can_disabled_v1[2] = cmd[2];
				this->pos_can_disabled_v1[3] = cmd[3];
			}

			if (!this->dxl_enabled) {
				this->pos_dxl_disabled_v1[0] = cmd[4];
				this->pos_dxl_disabled_v1[1] = cmd[5];
			}
		} else if (this->hardware_version == 2) {
			if (this->can_enabled) {
				this->canComm->setGoalPositionV2(cmd[0], cmd[1], cmd[2]);
			}
			if (this->dxl_enabled) {
				this->dxlComm->setGoalPositionV2(cmd[3], cmd[4], cmd[5]);
			}

			// if disabled (debug purposes)
			if (!this->can_enabled) {
				this->pos_can_disabled_v2[0] = cmd[0];
				this->pos_can_disabled_v2[1] = cmd[1];
				this->pos_can_disabled_v2[2] = cmd[2];
			}

			if (!this->dxl_enabled) {
				this->pos_dxl_disabled_v2[0] = cmd[3];
				this->pos_dxl_disabled_v2[1] = cmd[4];
				this->pos_dxl_disabled_v2[2] = cmd[5];
			}
		}
	}
}

void NiryoOneCommunication::addCustomDxlCommand(int motor_type, uint8_t id,
		uint32_t value, uint32_t reg_address, uint32_t byte_number) {
	if (this->dxl_enabled) {
		this->dxlComm->addCustomDxlCommand(
				motor_type, id, value, reg_address, byte_number);
	}
}

void NiryoOneCommunication::rebootMotors() {
	// Only useful for Dynamixel motors
	if (this->dxl_enabled) {
		this->dxlComm->rebootMotors();
	}
}

void NiryoOneCommunication::activateLearningMode(bool activate) {
	if (this->can_enabled) {
		this->canComm->setTorqueOn(!activate);
	}
	if (this->dxl_enabled) {
		this->dxlComm->setTorqueOn(!activate);
	}
}

bool NiryoOneCommunication::setLeds(
		std::vector<int> &leds, std::string &message) {
	if (leds.size() != 4) {
		message = "Led array must have 4 values";
		return false;
	}

	if (this->dxl_enabled) {
		this->dxlComm->setLeds(leds);
	}

	message = "Set LED ok";
	return true;
}

int NiryoOneCommunication::pullAirVacuumPump(
		uint8_t id, uint16_t pull_air_position, uint16_t pull_air_hold_torque) {
	if (this->dxl_enabled) {
		return this->dxlComm->pullAirVacuumPump(
				id, pull_air_position, pull_air_hold_torque);
	}
	return VACUUM_PUMP_STATE_PULLED;
}

int NiryoOneCommunication::pushAirVacuumPump(
		uint8_t id, uint16_t push_air_position) {
	if (this->dxl_enabled) {
		return this->dxlComm->pushAirVacuumPump(id, push_air_position);
	}
	return VACUUM_PUMP_STATE_PUSHED;
}

int NiryoOneCommunication::pingAndSetDxlTool(uint8_t id, std::string name) {
	if (this->dxl_enabled) {
		return this->dxlComm->pingAndSetTool(id, name);
	}
	return TOOL_STATE_PING_OK;
}

int NiryoOneCommunication::openGripper(uint8_t id, uint16_t open_position,
		uint16_t open_speed, uint16_t open_hold_torque) {
	if (this->dxl_enabled) {
		return this->dxlComm->openGripper(
				id, open_position, open_speed, open_hold_torque);
	}
	return GRIPPER_STATE_OPEN;
}

int NiryoOneCommunication::closeGripper(uint8_t id, uint16_t close_position,
		uint16_t close_speed, uint16_t close_hold_torque,
		uint16_t close_max_torque) {
	if (this->dxl_enabled) {
		return this->dxlComm->closeGripper(id, close_position, close_speed,
				close_hold_torque, close_max_torque);
	}
	return GRIPPER_STATE_CLOSE;
}
