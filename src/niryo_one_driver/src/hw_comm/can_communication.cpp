#include "niryo_one_driver/can_communication.hpp"

int32_t CanCommunication::rad_pos_to_steps(
		double position_rad, double gear_ratio, double direction) {
	return (int32_t) ((200.0 * 8.0 * gear_ratio * position_rad *
							  RADIAN_TO_DEGREE / 360) *
			direction);
}

double CanCommunication::steps_to_rad_pos(
		int32_t steps, double gear_ratio, double direction) {
	return (double) (((double) steps * 360.0 /
							 (200.0 * 8.0 * gear_ratio * RADIAN_TO_DEGREE)) *
			direction);
}

int CanCommunication::init(int hardware_version) {
	this->hardware_version = hardware_version;

	if (hardware_version != 1 && hardware_version != 2) {
		debug_error_message = "Incorrect hardware version, should be 1 or 2";
		RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
				debug_error_message.c_str());
		return -1;
	}

	// Conveyors Init
	this->is_conveyor_id_1_connected = false;
	this->is_conveyor_id_2_connected = false;
	this->conveyor_id_1_state = false;
	this->conveyor_id_2_state = false;
	this->is_conveyor_id_1_on = false;
	this->is_conveyor_id_2_on = false;
	this->conveyor_id_1_speed = 0;
	this->conveyor_id_2_speed = 0;
	this->conveyor_id_1_direction = 1;
	this->conveyor_id_2_direction = 1;
	this->update_id = false;

	this->declare_parameter("spi_channel", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter("spi_baudrate", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter("gpio_can_interrupt", rclcpp::PARAMETER_INTEGER);
	this->spi_channel = this->get_parameter("spi_channel").as_int();
	this->spi_baudrate = this->get_parameter("spi_baudrate").as_int();
	this->gpio_can_interrupt =
			this->get_parameter("gpio_can_interrupt").as_int();

	// Set frequencies for hw control loop
	this->declare_parameter(
			"can_hardware_control_loop_frequency", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("can_hw_write_frequency", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"can_hw_check_connection_frequency", rclcpp::PARAMETER_DOUBLE);
	this->hw_control_loop_frequency =
			this->get_parameter("can_hardware_control_loop_frequency")
					.as_double();
	this->hw_write_frequency =
			this->get_parameter("can_hw_write_frequency").as_double();
	this->hw_check_connection_frequency =
			this->get_parameter("can_hw_check_connection_frequency")
					.as_double();

	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"Start CAN communication (%1f Hz)",
			this->hw_control_loop_frequency);
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"Writing data on CAN at %1f Hz", this->hw_write_frequency);
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"Checking CAN connection at %1f Hz",
			this->hw_check_connection_frequency);

	resetHardwareControlLoopRates();

	// Set calibration timeouut
	this->declare_parameter("calibration_timeout", rclcpp::PARAMETER_INTEGER);
	this->calibration_timeout =
			this->get_parameter("calibration_timeout").as_int();
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"NiryoStepper calibration timeout: %d seconds",
			this->calibration_timeout);

	// Start CAN driver
	can.reset(new NiryoCanDriver(
			this->spi_channel, this->spi_baudrate, this->gpio_can_interrupt));

	this->is_can_connection_ok = false;
	debug_error_message = "No connection with CAN motors has been made yet";

	// Get connected motors from parameters
	this->declare_parameter(
			"can_required_motors", rclcpp::PARAMETER_INTEGER_ARRAY);
	this->declare_parameter(
			"can_authorized_motors", rclcpp::PARAMETER_INTEGER_ARRAY);
	this->required_steppers_ids =
			this->get_parameter("can_required_motors").as_integer_array();
	this->allowed_steppers_ids =
			this->get_parameter("can_authorized_motors").as_integer_array();
	this->required_steppers_ids.insert(this->required_steppers_ids.end(),
			this->required_steppers_ids.begin(),
			this->required_steppers_ids.end());
	this->allowed_steppers_ids.insert(this->allowed_steppers_ids.end(),
			this->required_steppers_ids.begin(),
			this->required_steppers_ids.end());
	this->allowed_steppers_ids.insert(this->allowed_steppers_ids.end(),
			this->allowed_steppers_ids.begin(),
			this->allowed_steppers_ids.end());

	// Get gear ratios from parameters
	double gear_ratio_1, gear_ratio_2, gear_ratio_3, gear_ratio_4, gear_ratio_6,
			gear_ratio_7;
	this->declare_parameter("stepper_1_gear_ratio", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_2_gear_ratio", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_3_gear_ratio", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_4_gear_ratio", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_6_gear_ratio", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_7_gear_ratio", rclcpp::PARAMETER_DOUBLE);
	gear_ratio_1 = this->get_parameter("stepper_1_gear_ratio").as_double();
	gear_ratio_2 = this->get_parameter("stepper_2_gear_ratio").as_double();
	gear_ratio_3 = this->get_parameter("stepper_3_gear_ratio").as_double();
	gear_ratio_4 = this->get_parameter("stepper_4_gear_ratio").as_double();
	gear_ratio_6 = this->get_parameter("stepper_6_gear_ratio").as_double();
	gear_ratio_7 = this->get_parameter("stepper_7_gear_ratio").as_double();
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"Gear ratios: (1: %1f, 2: %1f, 3: %1f, 4: %1f, 6: %1f, 7: "
			"%1f",
			gear_ratio_1, gear_ratio_2, gear_ratio_3, gear_ratio_4,
			gear_ratio_6, gear_ratio_7);

	// Get home position from parameters
	double home_position_1, home_position_2, home_position_3, home_position_4;
	this->declare_parameter(
			"stepper_1_home_position", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"stepper_2_home_position", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"stepper_3_home_position", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"stepper_4_home_position", rclcpp::PARAMETER_DOUBLE);
	home_position_1 =
			this->get_parameter("stepper_1_home_position").as_double();
	home_position_2 =
			this->get_parameter("stepper_2_home_position").as_double();
	home_position_3 =
			this->get_parameter("stepper_3_home_position").as_double();
	home_position_4 =
			this->get_parameter("stepper_4_home_position").as_double();
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"Home positions: (1: %1f, 2: %1f, 3: %1f, 4: %1f)", home_position_1,
			home_position_2, home_position_3, home_position_4);

	double offset_position_1, offset_position_2, offset_position_3,
			offset_position_4;
	this->declare_parameter(
			"stepper_1_offset_position", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"stepper_2_offset_position", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"stepper_3_offset_position", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"stepper_4_offset_position", rclcpp::PARAMETER_DOUBLE);
	offset_position_1 =
			this->get_parameter("stepper_1_offset_position").as_double();
	offset_position_2 =
			this->get_parameter("stepper_2_offset_position").as_double();
	offset_position_3 =
			this->get_parameter("stepper_3_offset_position").as_double();
	offset_position_4 =
			this->get_parameter("stepper_4_offset_position").as_double();
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"Angle offsets: (1: %1f, 2: %1f, 3: %1f, 4: %1f)",
			offset_position_1, offset_position_2, offset_position_3,
			offset_position_4);

	double direction_1, direction_2, direction_3, direction_4;
	this->declare_parameter("stepper_1_direction", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_2_direction", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_3_direction", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("stepper_4_direction", rclcpp::PARAMETER_DOUBLE);
	direction_1 = this->get_parameter("stepper_1_direction").as_double();
	direction_2 = this->get_parameter("stepper_2_direction").as_double();
	direction_3 = this->get_parameter("stepper_3_direction").as_double();
	direction_4 = this->get_parameter("stepper_4_direction").as_double();

	int64_t max_effort_1, max_effort_2, max_effort_3, max_effort_4,
			max_effort_6, max_effort_7;
	this->declare_parameter("stepper_1_max_effort", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter("stepper_2_max_effort", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter("stepper_3_max_effort", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter("stepper_4_max_effort", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter("stepper_6_max_effort", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter("stepper_7_max_effort", rclcpp::PARAMETER_INTEGER);
	max_effort_1 = this->get_parameter("stepper_1_max_effort").as_int();
	max_effort_2 = this->get_parameter("stepper_2_max_effort").as_int();
	max_effort_3 = this->get_parameter("stepper_3_max_effort").as_int();
	max_effort_4 = this->get_parameter("stepper_4_max_effort").as_int();
	max_effort_6 = this->get_parameter("stepper_6_max_effort").as_int();
	max_effort_7 = this->get_parameter("stepper_7_max_effort").as_int();

	// Create motors with previous params
	this->m1 = StepperMotorState("Stepper Axis 1", CAN_MOTOR_1_ID, gear_ratio_1,
			direction_1,
			rad_pos_to_steps(home_position_1, gear_ratio_1,
					direction_1),  // Home position
			rad_pos_to_steps(offset_position_1, gear_ratio_1,
					direction_1),  // Offset position
			8, max_effort_1);
	this->m2 = StepperMotorState("Stepper Axis 2", CAN_MOTOR_2_ID, gear_ratio_2,
			direction_2,
			rad_pos_to_steps(home_position_2, gear_ratio_2,
					direction_2),  // Home position
			rad_pos_to_steps(offset_position_2, gear_ratio_2,
					direction_2),  // Offset position
			8, max_effort_2);
	this->m3 = StepperMotorState("Stepper Axis 3", CAN_MOTOR_3_ID, gear_ratio_3,
			direction_3,
			rad_pos_to_steps(home_position_3, gear_ratio_3,
					direction_3),  // Home position
			rad_pos_to_steps(offset_position_3, gear_ratio_3,
					direction_3),  // Offset position
			8, max_effort_3);

	// This motor is declared for hardware_version 1 & 2,
	// but will be disabled for hardware_version 2 (replaced by a XL430-W250 Dynamixel motor)
	this->m4 = StepperMotorState("Stepper Axis 4", CAN_MOTOR_4_ID, gear_ratio_4,
			direction_4,
			rad_pos_to_steps(home_position_4, gear_ratio_4,
					direction_4),  // Home position
			rad_pos_to_steps(offset_position_4, gear_ratio_4,
					direction_4),  // Offset position
			8, max_effort_4);

	// Conveyor belt steppers
	this->m6 = StepperMotorState("Stepper Conveyor Belt 1",
			CAN_MOTOR_CONVEYOR_1_ID, gear_ratio_6, 1, 0, 0, 8, max_effort_6);
	this->m7 = StepperMotorState("Stepper Conveyor Belt 2",
			CAN_MOTOR_CONVEYOR_2_ID, gear_ratio_7, 1, 0, 0, 8, max_effort_7);

	for (uint8_t i = 0; i < this->required_steppers_ids.size(); i++) {
		if (this->required_steppers_ids.at(i) == this->m1.getId()) {
			this->m1.enable();
		} else if (this->required_steppers_ids.at(i) == this->m2.getId()) {
			this->m2.enable();
		} else if (this->required_steppers_ids.at(i) == this->m3.getId()) {
			this->m3.enable();
		} else if (hardware_version == 1 &&
				this->required_steppers_ids.at(i) == this->m4.getId()) {
			this->m4.enable();
		} else {
			this->debug_error_message =
					"Incorrect configuration: Wrong ID (%s) given in ROS Param "
					"/niryo_one_motors/can_required_motors.";
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					this->debug_error_message.c_str(),
					std::to_string(this->required_steppers_ids.at(i)));
			return -1;
		}
	}

	if (this->required_steppers_ids.size() == 0) {
		this->debug_error_message =
				"Incorrect configuration: No motor ID given in ROS Param "
				"/niryo_one_motors/can_required_motors.";
		RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
				this->debug_error_message.c_str());
		return -1;
	}

	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"%d motors should be connected to CAN bus",
			(int) this->required_steppers_ids.size());

	// Enable conveyor belt motors
	if (this->is_conveyor_id_1_connected) {
		this->m6.enable();
	}
	if (this->is_conveyor_id_2_connected) {
		this->m7.enable();
	}

	// Fill motor array (to avoid redudant code later)
	this->motors.push_back(&m1);
	this->motors.push_back(&m2);
	this->motors.push_back(&m3);
	if (hardware_version == 1) {
		motors.push_back(&m4);
	}

	this->allowed_motors.push_back(&m1);
	this->allowed_motors.push_back(&m2);
	this->allowed_motors.push_back(&m3);
	if (hardware_version == 1) {
		this->allowed_motors.push_back(&m4);
	}
	this->allowed_motors.push_back(&m6);
	this->allowed_motors.push_back(&m7);

	// Set HW Control init state
	this->torque_on = 0;

	this->hw_is_busy = false;
	this->hw_limited_mode = true;

	this->write_position_enable = true;
	this->write_torque_enable = false;
	this->write_torque_on_enable = true;

	this->write_synchronize_enable = false;
	this->write_micro_steps_enable = true;
	this->write_max_effort_enable = true;

	this->waiting_for_user_trigger_calibration = false;
	this->steppers_calibration_mode =
			CAN_STEPPERS_CALIBRATION_MODE_AUTO;  // default
	this->write_synchronize_begin_traj = true;
	this->calibration_in_progress = false;

	return setupCommunication();
}

int CanCommunication::setupCommunication() {
	int gpio_result = this->can->setupInterruptGpio();
	if (gpio_result != CAN_OK) {
		RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
				"Failed to start GPIO for CAN bus");
		return gpio_result;
	}

	int spi_result = this->can->setupSpi();
	if (spi_result != CAN_OK) {
		RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
				"Failed to start SPI for CAN bus");
		return spi_result;
	}

	// Will return 0 on success
	return this->can->init();
}

bool CanCommunication::isOnLimitedMode() {
	return this->hw_limited_mode;
}

void CanCommunication::resetHardwareControlLoopRates() {
	double now = rclcpp::Clock().now().seconds();
	this->time_hw_last_write = now;
	this->time_hw_last_check_connection = now;
}

void CanCommunication::startHardwareControlLoop(bool limited_mode) {
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"CAN: Start hardware control loop");
	this->write_torque_on_enable = true;
	this->write_micro_steps_enable = true;
	this->write_max_effort_enable = true;
	this->resetHardwareControlLoopRates();

	// Depends on limited_mode flag
	this->write_position_enable = !limited_mode;
	this->write_synchronize_enable = !limited_mode;
	this->write_torque_on_enable = true;

	this->hw_limited_mode = limited_mode;
	this->hw_control_loop_keep_alive = true;

	if (!this->hardware_control_loop_thread) {
		RCLCPP_WARN(rclcpp::get_logger("CanCommunication"),
				"CAN: Start control loop thread CAN");
		this->hardware_control_loop_thread.reset(new std::thread(
				std::bind(&CanCommunication::hardwareControlLoop, this)));
	}
}

void CanCommunication::stopHardwareControlLoop() {
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"CAN: Stop hardware control loop");
	for (int i = 0; i < this->motors.size(); i++) {
		this->motors.at(i)->resetState();
	}
	this->m6.resetState();
	this->m7.resetState();
	this->hw_control_loop_keep_alive = false;
}

void CanCommunication::hardwareControlRead() {
	if (this->can->canReadData()) {
		long unsigned int rxId;
		unsigned char len;
		unsigned char rxBuf[8];

		this->can->readMsgBuf(&rxId, &len, rxBuf);

		/*
		 * 0. This functionality will come later, to allow user to plug other CAN devices into RPI
		 * Development to do here: Check if ID >= 0x20
		 * Ids between 0x00 and 0x1F are reserved for Niryo One core communication
		 * Those are lower IDs with higher priority, to ensure connection
		 * with motors ia always up.
		 */
		if (rxId >= 0x20) {
			// Send frame to another place and return
			// RCLCPP_INFO(rclcpp::get_logger("CanCommunication"), "Frame will be sent somewhere else");
			// return;
		}

		// 1. Validate motor ID
		int motor_id = rxId & 0x0F;  // 0x11 for ID 1, 0x02 for ID, ...

		// Conveyor belt detected
		if (motor_id == CAN_MOTOR_CONVEYOR_1_ID &&
				this->is_conveyor_id_1_connected) {
			if (this->update_id && this->old_id == motor_id) {
				if (this->can->sendUpdateConveyorId(
							CAN_MOTOR_CONVEYOR_1_ID, this->new_id) != CAN_OK) {
					RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
							"CAN: Failed to send update conveyor with ID: %d",
							motor_id);
				}
				this->update_id = false;
				this->is_conveyor_id_1_connected = false;
				this->conveyor_id_1_state = false;
				this->resetConveyor(CAN_MOTOR_CONVEYOR_1_ID);
				this->is_conveyor_id_2_connected = true;
				this->conveyor_id_2_state = true;
				return;
			}

			if (!this->conveyor_id_1_state) {
				this->resetConveyor(CAN_MOTOR_CONVEYOR_1_ID);
				is_conveyor_id_1_connected = false;
			}

			if (this->can->sendConveyoOnCommand(CAN_MOTOR_CONVEYOR_1_ID,
						this->is_conveyor_id_1_on, this->conveyor_id_1_speed,
						this->conveyor_id_1_direction) != CAN_OK) {
				RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
						"CAN: Failed to send command to the conveyor with ID: "
						"%d",
						motor_id);
			}

			int control_byte = rxBuf[0];

			if (control_byte == CAN_DATA_CONVEYOR_STATE) {
				this->m6.setConveyorFeedback(rxBuf[1], rxBuf[2], rxBuf[3]);
				return;
			}

			return;
		}

		if (motor_id == CAN_MOTOR_CONVEYOR_2_ID &&
				this->is_conveyor_id_2_connected) {
			if (this->update_id && this->old_id == motor_id) {
				if (this->can->sendUpdateConveyorId(
							CAN_MOTOR_CONVEYOR_2_ID, this->new_id) != CAN_OK) {
					RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
							"CAN: Failed to send update conveyor with ID: %d",
							motor_id);
				}
				this->update_id = false;
				this->is_conveyor_id_2_connected = false;
				this->conveyor_id_2_state = false;
				this->resetConveyor(CAN_MOTOR_CONVEYOR_2_ID);
				this->is_conveyor_id_1_connected = true;
				this->conveyor_id_1_state = true;
				return;
			}

			if (!this->conveyor_id_2_state) {
				this->resetConveyor(CAN_MOTOR_CONVEYOR_2_ID);
				is_conveyor_id_2_connected = false;
			}

			if (this->can->sendConveyoOnCommand(CAN_MOTOR_CONVEYOR_2_ID,
						this->is_conveyor_id_2_on, this->conveyor_id_2_speed,
						this->conveyor_id_2_direction) != CAN_OK) {
				RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
						"CAN: Failed to send command to the conveyor with ID: "
						"%d",
						motor_id);
			}

			int control_byte = rxBuf[0];

			if (control_byte == CAN_DATA_CONVEYOR_STATE) {
				this->m7.setConveyorFeedback(rxBuf[1], rxBuf[2], rxBuf[3]);
				return;
			}

			return;
		}

		// Niryo One Steppers
		bool motor_found = false;
		for (int i = 0; i < this->allowed_motors.size(); i++) {
			if (motor_id == this->allowed_motors.at(i)->getId()) {
				this->allowed_motors.at(i)->setLastTimeRead(
						rclcpp::Clock().now().seconds());
				motor_found = true;
				break;
			}
		}

		if (!motor_found) {
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					"CAN: Recieved frame with wrong ID: %d", motor_id);
			this->debug_error_message = "Unallowed connected motor: ";
			this->debug_error_message += std::to_string(motor_id);
			this->is_can_connection_ok = false;
			return;
		}

		// 1.1 Check buffer is not empty
		if (len < 1) {
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					"CAN: Recieved empty frame");
			return;
		}

		// 2. If ID OK, check control byte and fill data
		int control_byte = rxBuf[0];

		switch (control_byte) {
			case CAN_DATA_POSITION: {
				// Check data length
				if (len != 4) {
					RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
							"CAN: Position CAN frame should contain 4 data "
							"bytes");
					return;
				}

				int32_t pos = (rxBuf[1] << 16) + (rxBuf[2] << 8) + rxBuf[3];
				if (pos & (1 << 15)) {
					pos = -1 * ((~pos + 1) & 0xFFFF);
				}

				// Fill Data
				for (int i = 0; i < this->motors.size(); i++) {
					if (motor_id == this->motors.at(i)->getId() &&
							this->motors.at(i)->isEnabled()) {
						this->motors.at(i)->setPositionState(pos);
						break;
					}
				}
				break;
			}
			case CAN_DATA_DIAGNOSTICS: {
				// Check data length
				if (len != 4) {
					RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
							"CAN: Diagnostics CAN frame should contain 4 data "
							"bytes");
					return;
				}

				int mode = rxBuf[1];
				int driver_temp_raw = (rxBuf[2] << 8) + rxBuf[3];
				double a = -0.00316;
				double b = -12.924;
				double c = 2367.7;
				double v_temp = driver_temp_raw * 3.3 / 1024.0 * 1000.0;
				int driver_temp =
						int((-b - std::sqrt(b * b - 4 * a * (c - v_temp))) /
										(2 * a) +
								30);

				// Fill Data
				for (int i = 0; i < this->motors.size(); i++) {
					if (motor_id == this->motors.at(i)->getId() &&
							this->motors.at(i)->isEnabled()) {
						this->motors.at(i)->setTemperatureState(driver_temp);
						break;
					}
				}
				break;
			}
			case CAN_DATA_FIRMWARE_VERSION: {
				// Check data length
				if (len != 4) {
					RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
							"CAN: Firmware CAN frame should contain 4 data "
							"bytes");
					return;
				}

				int v_major = rxBuf[1];
				int v_minor = rxBuf[2];
				int v_patch = rxBuf[3];
				std::string version = "";
				version += std::to_string(v_major);
				version += ".";
				version += std::to_string(v_minor);
				version += ".";
				version += std::to_string(v_patch);

				// Fill Data
				for (int i = 0; i < this->motors.size(); i++) {
					if (motor_id == this->motors.at(i)->getId() &&
							this->motors.at(i)->isEnabled()) {
						this->motors.at(i)->setFirmwareVersion(version);
						break;
					}
				}
				break;
			}
			case CAN_DATA_CONVEYOR_STATE: {
				// Conveyor not enabled: Do nothing
				this->is_conveyor_id_1_connected = this->conveyor_id_1_state;
				this->is_conveyor_id_2_connected = this->conveyor_id_2_state;
				break;
			}
			default: {
				RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
						"CAN: Receieved CAN frame with unknown control byte");
				break;
			}
		}
		return;
	}
}

/*
 * Send a CAN frame per motor (ID + control byte + data)
 */
void CanCommunication::hardwareControlWrite() {
	if (rclcpp::Clock().now().seconds() - this->time_hw_last_write >
			1.0 / this->hw_write_frequency) {
		this->time_hw_last_write += 1.0 / this->hw_write_frequency;

		// Write torque ON/OFF
		if (this->write_torque_on_enable) {
			if (this->can->sendTorqueOnCommand(
						CAN_BROADCAST_ID, this->torque_on) != CAN_OK) {
				RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
						"CAN: Failed to send torque ON command");
			} else {
				this->write_torque_on_enable =
						false;  // Disable writing on success
			}
		}
	}

	// Write synchronize position
	if (this->write_synchronize_enable) {
		bool synchronize_write_success = true;

		for (int i = 0; i < this->motors.size(); i++) {
			if (this->motors.at(i)->isEnabled()) {
				if (this->can->sendSynchronizePositionCommand(
							this->motors.at(i)->getId(),
							this->write_synchronize_begin_traj) != CAN_OK) {
					synchronize_write_success = false;
				}
			}
		}

		if (synchronize_write_success) {
			this->write_synchronize_enable =
					false;  // Disable writing on success
		} else {
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					"CAN: Failed to send synchronize position command");
		}
	}

	// Write position
	if (this->write_position_enable) {
		for (int i = 0; i < this->motors.size(); i++) {
			if (this->motors.at(i)->isEnabled()) {
				if (this->can->sendPositionCommand(this->motors.at(i)->getId(),
							this->motors.at(i)->getPositionCommand()) !=
						CAN_OK) {
					// RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					// 		"CAN: Failed to send position command");
				}
			}
		}
	}

	// Write micro steps
	if (this->write_micro_steps_enable) {
		bool micro_steps_write_success = true;

		for (int i = 0; i < this->motors.size(); i++) {
			if (this->motors.at(i)->isEnabled()) {
				if (this->can->sendMicroStepsCommand(
							this->motors.at(i)->getId(),
							this->motors.at(i)->getMicroStepsCommand()) !=
						CAN_OK) {
					micro_steps_write_success = false;
				}
			}
		}

		if (micro_steps_write_success) {
			this->write_micro_steps_enable =
					false;  // Disable writing on success
		} else {
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					"CAN: Failed to send micro steps command");
		}
	}

	// Write max effort
	if (this->write_max_effort_enable) {
		bool max_effort_write_success = true;

		for (int i = 0; i < this->motors.size(); i++) {
			if (this->motors.at(i)->isEnabled()) {
				if (this->can->sendMaxEffortCommand(this->motors.at(i)->getId(),
							this->motors.at(i)->getMaxEffortCommand()) !=
						CAN_OK) {
					max_effort_write_success = false;
				}
			}
		}

		if (max_effort_write_success) {
			this->write_max_effort_enable =
					false;  // Disable writing on success
		} else {
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					"CAN: Failed to send max effort command");
		}
	}
}

void CanCommunication::hardwareControlCheckConnection() {
	if (rclcpp::Clock().now().seconds() - this->time_hw_last_check_connection >
			1.0 / this->hw_check_connection_frequency) {
		this->time_hw_last_check_connection +=
				1.0 / this->hw_check_connection_frequency;

		if (!this->is_can_connection_ok) {
			return;
		}

		double time_now = rclcpp::Clock().now().seconds();
		if (this->hw_check_connection_frequency > 5.0) {
			// If we check MCP_2515 too fast it will not work
			this->hw_check_connection_frequency = 5.0;
		}

		double timeout_read = 1.0 / this->hw_check_connection_frequency;
		int max_fail_counter = (int) (this->hw_check_connection_frequency +
				0.5);  // Connection erro will be detected after 1 second

		for (int i = 0; i < this->motors.size(); i++) {
			if (this->motors.at(i)->isEnabled()) {
				if (time_now - this->motors.at(i)->getLastTimeRead() >
						timeout_read *
								(this->motors.at(i)->getHwFailCounter() + 1)) {
					RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
							"CAN: Connection problem with motor %d, HW fail "
							"counter: %d",
							this->motors.at(i)->getId(),
							this->motors.at(i)->getHwFailCounter());
					if (this->motors.at(i)->getHwFailCounter() >=
							max_fail_counter) {
						this->is_can_connection_ok = false;
						this->debug_error_message =
								"CAN: Connection problem with bus. Motor ";
						this->debug_error_message +=
								this->motors.at(i)->getName();
						this->debug_error_message += " is not connected";
						return;
					}

					// Reset MCP_2515
					// int result = this->can->init();
					// RCLCPP_INFO(rclcpp::get_logger("CanCommunication"), "CAN: Init: %d", result);
					this->motors.at(i)->setHwFailCounter(
							this->motors.at(i)->getHwFailCounter() + 1);
				} else {
					this->motors.at(i)->setHwFailCounter(0);
				}
			}
		}
	}
}

void CanCommunication::hardwareControlLoop() {
	rclcpp::Rate hw_control_loop_rate = rclcpp::Rate(this->hw_write_frequency);

	while (rclcpp::ok()) {
		if (!this->hw_is_busy && this->hw_control_loop_keep_alive) {
			this->hw_is_busy = true;

			this->hardwareControlRead();
			this->hardwareControlWrite();
			this->hardwareControlCheckConnection();

			this->hw_is_busy = false;
			hw_control_loop_rate.sleep();
		} else {
			rclcpp::sleep_for(std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
			this->resetHardwareControlLoopRates();
		}
	}
}

void CanCommunication::synchronizeSteppers(bool begin_traj) {
	this->write_synchronize_enable = true;
	this->write_synchronize_begin_traj = begin_traj;
}

void CanCommunication::setTorqueOn(bool on) {
	if (!on && this->is_can_connection_ok &&
			this->waiting_for_user_trigger_calibration &&
			!this->calibration_in_progress) {
		this->can->sendTorqueOnCommand(CAN_BROADCAST_ID,
				false);  // Only to deactivate motors when waiting for calibration
	} else if (this->hw_limited_mode) {
		this->torque_on = false;
		this->write_torque_on_enable = true;
	} else {
		this->torque_on = on;
		this->write_torque_on_enable = true;
	}
}

bool CanCommunication::canProcessManualCalibration(
		std::string &result_message) {
	// 1. Check if motors firmware version is OK
	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			std::string firmware_version =
					this->motors.at(i)->getFirmwareVersion();
			if (firmware_version.length() == 0) {
				result_message = "No firmware version available for motor " +
						std::to_string(this->motors.at(i)->getId()) +
						". Make sure all motors are connected";
				RCLCPP_WARN(rclcpp::get_logger("CanCommunication"),
						"Can't process manual calibration: %s",
						result_message.c_str());
				return false;
			}
		}
	}

	// 2. Check if motor offset values have been previously saved (with auto calibration)
	std::vector<int> motor_id_list;
	std::vector<int> steps_list;
	if (!get_motors_calibration_offsets(motor_id_list, steps_list)) {
		result_message = "You need to make one auto calibration before using "
						 "the manual calibration";
		RCLCPP_WARN(rclcpp::get_logger("CanCommunication"),
				"Can't process manual calibration: %s", result_message.c_str());
		return false;
	}

	// 3. Check if all connected motors have a motor offset value
	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			for (int j = 0; j < motor_id_list.size(); j++) {
				if (motor_id_list.at(j) == this->motors.at(i)->getId()) {
					break;
				}
				if (j == motor_id_list.size() - 1) {
					result_message = "Motor " +
							std::to_string(this->motors.at(i)->getId()) +
							" does not have a saved offset value, you need to "
							"do one auto calibration";
					RCLCPP_WARN(rclcpp::get_logger("CanCommunication"),
							"Can't process manual calibration: %s",
							result_message.c_str());
					return false;
				}
			}
		}
	}

	return true;
}

/*
 * User input to clear the calibration flag
 * - also choose a calibration mode (manual|auto)
 */
void CanCommunication::validateMotorsCalibrationFromUserInput(int mode) {
	this->waiting_for_user_trigger_calibration = false;
	if (mode == CAN_STEPPERS_CALIBRATION_MODE_MANUAL ||
			mode == CAN_STEPPERS_CALIBRATION_MODE_AUTO) {
		this->steppers_calibration_mode = mode;
	}
}

/*
 * This flag should be cleared by calling the service /niryo_one_control/calibrate_motors
 */
void CanCommunication::setCalibrationFlag(bool flag) {
	this->waiting_for_user_trigger_calibration = flag;
}

/*
 * 1. If mode is manual, it will just send an offset to all the motors,
 * it means the user has to place the robot to home position before using
 * this mode
 * 2. If mode is automatic, it will send a calibration command to all
 * motors, and wait until it receives a confirmation from all motors
 * (success, timeout, bad params)
 * Also, the auto calibration is done with multiple steps.
 */
int CanCommunication::calibrateMotors(int calibration_step) {
	if (!this->is_can_connection_ok) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	// This flag should be cleared by a user action to continue
	if (this->waiting_for_user_trigger_calibration) {
		return CAN_STEPPERS_CALIBRATION_WAITING_USER_INPUT;
	}

	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"START Calibrating stepper motors, step number %d",
			calibration_step);
	this->stopHardwareControlLoop();
	rclcpp::sleep_for(std::chrono::milliseconds(100));

	// If user wants to do a manual calibration, just send offset to current position
	if (this->steppers_calibration_mode ==
			CAN_STEPPERS_CALIBRATION_MODE_MANUAL) {
		if (calibration_step > 1) {
			return CAN_STEPPERS_CALIBRATION_OK;  // Do manual calibration only once
		}
		this->calibration_in_progress = true;
		int result = this->manualCalibration();
		this->calibration_in_progress = false;
		return result;
	} else if (this->steppers_calibration_mode ==
			CAN_STEPPERS_CALIBRATION_MODE_AUTO) {
		if (calibration_step == 1) {
			this->calibration_in_progress = true;
			int result = this->autoCalibrationStep1();
			return result;
		} else if (calibration_step == 2) {
			int result = this->autoCalibrationStep2();
			this->calibration_in_progress = false;
			return result;
		}
	} else {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	return CAN_STEPPERS_CALIBRATION_FAIL;
}

int CanCommunication::getCalibrationMode() {
	return this->steppers_calibration_mode;
}

bool CanCommunication::isCalibrationInProgress() {
	return this->calibration_in_progress;
}

int CanCommunication::manualCalibration() {
	std::vector<int> motor_id_list;
	std::vector<int> steps_list;

	if (!get_motors_calibration_offsets(motor_id_list, steps_list)) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			// Compute step offset to send
			int offset_to_send = 0;
			int sensor_offset_steps = 0;
			int absolute_steps_at_offset_position = 0;
			int offset_steps = this->motors.at(i)->getOffsetPosition();
			for (int j = 0; j < motor_id_list.size(); j++) {
				if (motor_id_list.at(j) == this->motors.at(i)->getId()) {
					sensor_offset_steps = steps_list.at(j);
					break;
				}
			}

			if (this->motors.at(i)->getId() == 1 ||
					this->motors.at(i)->getId() == 2 ||
					this->motors.at(i)->getId() == 4) {  // Position 0.0
				offset_to_send = (sensor_offset_steps - offset_steps) % 1600;
				if (offset_to_send < 0) {
					offset_to_send += 1600;
				}
				absolute_steps_at_offset_position = offset_to_send;
			} else if (this->motors.at(i)->getId() == 3) {  // Max position
				offset_to_send = sensor_offset_steps - offset_steps;
				absolute_steps_at_offset_position = sensor_offset_steps;
			}

			RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
					"Motor %d - sending offset: %d",
					this->motors.at(i)->getId(), offset_to_send);
			if (this->can->sendPositionOffsetCommand(
						this->motors.at(i)->getId(), offset_to_send,
						absolute_steps_at_offset_position) != CAN_OK) {
				return CAN_STEPPERS_CALIBRATION_FAIL;
			}
		}
	}

	return CAN_STEPPERS_CALIBRATION_OK;
}

int CanCommunication::sendCalibrationCommandForOneMotor(
		StepperMotorState *motor, int delay_between_steps,
		int calibration_direction, int calibr_timeout) {
	if (!motor->isEnabled()) {
		return CAN_OK;
	}

	if (this->can->sendCalibrationCommand(motor->getId(),
				motor->getOffsetPosition(), delay_between_steps,
				(int) motor->getDirection() * calibration_direction,
				calibr_timeout) != CAN_OK) {
		RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
				"CAN: Failed to send calibration command for motor %d",
				motor->getId());
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	return CAN_OK;
}

int CanCommunication::getCalibrationResults(
		std::vector<StepperMotorState *> steppers, int calibration_timeout,
		std::vector<int> &sensor_offset_ids,
		std::vector<int> &sensor_offset_steps) {
	std::vector<int> motor_ids;
	std::vector<bool> calibration_results;

	for (int i = 0; i < motors.size(); i++) {
		if (steppers.at(i)->isEnabled()) {
			motor_ids.push_back(steppers.at(i)->getId());
			calibration_results.push_back(false);
		}
	}

	double time_begin_calibration = rclcpp::Clock().now().seconds();
	double timeout = time_begin_calibration + (double) calibration_timeout;
	RCLCPP_INFO(rclcpp::get_logger("CanCommunication"),
			"Waiting for motor calibration");

	while (rclcpp::Clock().now().seconds() < timeout) {
		rclcpp::sleep_for(std::chrono::milliseconds(5));  // Check at 2000 Hz

		// Check if success
		bool success = true;
		for (int i = 0; i < calibration_results.size(); i++) {
			if (!calibration_results.at(i)) {
				success = false;
				break;
			}
		}

		if (success) {
			return CAN_STEPPERS_CALIBRATION_OK;
		}

		if (this->can->canReadData()) {
			long unsigned int rxId;
			unsigned char len;
			unsigned char rxBuf[8];

			this->can->readMsgBuf(&rxId, &len, rxBuf);

			// 1. Get motor ID
			int motor_id = rxId & 0x00F;  // 0x101 for ID 1, 0x102 for ID 2, ...

			// 2. Check if motor ID is in array
			for (int i = 0; i < motor_ids.size(); i++) {
				if (motor_id == motor_ids.at(i)) {
					if (len == 2) {
						// 3. Check control byte
						int control_byte = rxBuf[0];

						// Only check this frame
						if (control_byte == CAN_DATA_CALIBRATION_RESULT) {
							int result = rxBuf[1];

							if (result == CAN_STEPPERS_CALIBRATION_TIMEOUT) {
								RCLCPP_ERROR(
										rclcpp::get_logger("CanCommunication"),
										"Motor %d calibration timeout",
										motor_id);
								return result;
							} else if (result ==
									CAN_STEPPERS_CALIBRATION_BAD_PARAM) {
								RCLCPP_ERROR(
										rclcpp::get_logger("CanCommunication"),
										"Motor %d calibration bad param",
										motor_id);
								return result;
							} else if (result == CAN_STEPPERS_CALIBRATION_OK) {
								RCLCPP_INFO(
										rclcpp::get_logger("CanCommunication"),
										"Motor %d calibration OK", motor_id);
								calibration_results.at(i) = true;
							}
						}
						// New firmware version -> get result + absolute sensor steps at offset position
					} else if (len == 4) {
						// 3. Check control byte
						int control_byte = rxBuf[0];

						// Only check this frame
						if (control_byte == CAN_DATA_CALIBRATION_RESULT) {
							int result = rxBuf[1];

							if (result == CAN_STEPPERS_CALIBRATION_TIMEOUT) {
								RCLCPP_ERROR(
										rclcpp::get_logger("CanCommunication"),
										"Motor %d calibration timeout",
										motor_id);
								return result;
							} else if (result ==
									CAN_STEPPERS_CALIBRATION_BAD_PARAM) {
								RCLCPP_ERROR(
										rclcpp::get_logger("CanCommunication"),
										"Motor %d calibration bad param",
										motor_id);
								return result;
							} else if (result == CAN_STEPPERS_CALIBRATION_OK) {
								RCLCPP_INFO(
										rclcpp::get_logger("CanCommunication"),
										"Motor %d calibration OK", motor_id);
								int steps_at_offset_pos =
										(rxBuf[2] << 8) + rxBuf[3];
								RCLCPP_INFO(
										rclcpp::get_logger("CanCommunication"),
										"Motor %d absolute steps at offset "
										"position: %d",
										motor_id, steps_at_offset_pos);
								sensor_offset_ids.push_back(motor_id);
								sensor_offset_steps.push_back(
										steps_at_offset_pos);
								calibration_results.at(i) = true;

								// Key torque ON for axis 2
								// If torsion spring is too string, the axis might
								// move too much for the following calibration steps
								if (motor_id == this->m2.getId()) {
									this->can->sendTorqueOnCommand(
											this->m2.getId(), true);
								}

								// Keep torque ON for axis 2
								if (motor_id == m1.getId()) {
									this->can->sendTorqueOnCommand(
											m1.getId(), true);
								}
							}
						}
					}
				}
			}
		}
	}

	return CAN_STEPPERS_CALIBRATION_TIMEOUT;
}

/*
 * To use only during calibration phase, or for debug purposes
 * - Move motor from whatever current position to current_steps + steps
 */
int CanCommunication::relativeMoveMotor(
		StepperMotorState *motor, int step, int delay, bool wait) {
	if (!motor->isEnabled()) {
		return CAN_OK;
	}

	if (this->can->sendTorqueOnCommand(motor->getId(), true) != CAN_OK) {
		RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
				"CAN: Failed to send torque ON command for motor %d",
				motor->getId());
		return CAN_FAIL;
	}

	if (this->can->sendRelativeMoveCommand(motor->getId(), step, delay) !=
			CAN_OK) {
		RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
				"CAN: Failed to send relative move command for motor %d",
				motor->getId());
		return CAN_FAIL;
	}

	if (wait) {
		rclcpp::sleep_for(std::chrono::microseconds(step * delay + 500000));
	}

	return CAN_OK;
}

int CanCommunication::autoCalibrationStep1() {
	int results;

	// 0. Torque ON for motor 2
	if (this->can->sendTorqueOnCommand(this->m2.getId(), true) != CAN_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	// 1. Move axis 3 up
	if (this->relativeMoveMotor(&this->m3,
				rad_pos_to_steps(
						0.5, this->m3.getGearRatio(), this->m3.getDirection()),
				1500, true) != CAN_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	return CAN_STEPPERS_CALIBRATION_OK;
}

int CanCommunication::autoCalibrationStep2() {
	int result;
	std::vector<int> sensor_offset_ids;
	std::vector<int> sensor_offset_steps;  // Absolute steps at offset position

	// 2. Send calibration command 1 + 2 _ 4 (+ 3 if hw version == 2)
	if (this->sendCalibrationCommandForOneMotor(
				&this->m1, 800, 1, this->calibration_timeout) != CAN_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	if (this->sendCalibrationCommandForOneMotor(
				&this->m2, 1100, 1, this->calibration_timeout) != CAN_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	if (this->sendCalibrationCommandForOneMotor(
				&this->m4, 800, 1, this->calibration_timeout) != CAN_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	if (this->hardware_version == 2) {
		if (this->sendCalibrationCommandForOneMotor(
					&this->m3, 1100, 1, this->calibration_timeout) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}
	}

	// 2.1 Wait for calibration result
	std::vector<StepperMotorState *> steppers = {
			&this->m1, &this->m2, &this->m4};
	if (this->hardware_version == 2) {
		steppers.push_back(&this->m3);
	}

	if (this->getCalibrationResults(steppers, this->calibration_timeout,
				sensor_offset_ids,
				sensor_offset_steps) != CAN_STEPPERS_CALIBRATION_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	// 3. Move motors 1, 2, 4, to 0.0
	int delay_mircros = 2000;
	if (this->relativeMoveMotor(&this->m1, -this->m1.getOffsetPosition(), 1300,
				false) != CAN_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}
	if (this->hardware_version == 1) {
		if (this->relativeMoveMotor(&this->m2, -this->m2.getOffsetPosition(),
					3000, false) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}
	}
	if (this->relativeMoveMotor(&this->m4, -this->m4.getOffsetPosition(), 3000,
				false) != CAN_OK) {
		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	// 3.1 Wait for motors to finish moving (at least m4, so we can start m3 calibration)
	// For hw version 2, just wait for m1 to be at home position
	if (this->hardware_version == 1) {
		rclcpp::sleep_for(std::chrono::seconds(
				abs(this->m4.getOffsetPosition()) * 1500 / 1000000));
	} else if (this->hardware_version == 2) {
		rclcpp::sleep_for(std::chrono::seconds(
				abs(this->m1.getOffsetPosition()) * 1300 / 1000000));
	}

	// 3.2 Move axis 2 to home position after axis 1
	// --> in case a gripper is attached, so it won't collide with the base while moving
	if (this->hardware_version == 2) {
		if (relativeMoveMotor(&this->m2, -this->m2.getOffsetPosition(), 3000,
					false) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}
		rclcpp::sleep_for(std::chrono::microseconds(
				abs(this->m2.getOffsetPosition()) * 3000 + 500000));
	}

	// 5. Send calibration command m3 (only for hw version 1)
	if (this->hardware_version == 1) {
		if (this->sendCalibrationCommandForOneMotor(
					&this->m3, 1100, -1, this->calibration_timeout) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		// 5.1 Wait for calibration result
		std::vector<StepperMotorState *> steppers = {&this->m3};
		if (this->getCalibrationResults(steppers, this->calibration_timeout,
					sensor_offset_ids,
					sensor_offset_steps) != CAN_STEPPERS_CALIBRATION_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}
	}

	// 6. Write sensor_offset_steps to file
	set_motors_calibration_offsets(sensor_offset_ids, sensor_offset_steps);

	return CAN_STEPPERS_CALIBRATION_OK;
}

void CanCommunication::setGoalPositionV1(double axis_1_pos_goal,
		double axis_2_pos_goal, double axis_3_pos_goal,
		double axis_4_pos_goal) {
	if (this->hardware_version == 1) {
		this->m1.setPositionCommand(rad_pos_to_steps(axis_1_pos_goal,
				this->m1.getGearRatio(), this->m1.getDirection()));
		this->m2.setPositionCommand(rad_pos_to_steps(axis_2_pos_goal,
				this->m2.getGearRatio(), this->m2.getDirection()));
		this->m3.setPositionCommand(rad_pos_to_steps(axis_3_pos_goal,
				this->m3.getGearRatio(), this->m3.getDirection()));
		this->m4.setPositionCommand(rad_pos_to_steps(axis_4_pos_goal,
				this->m4.getGearRatio(), this->m4.getDirection()));

		// If motor disaled, pos_state = pos_cmd (echo position)
		for (int i = 0; i < this->motors.size(); i++) {
			if (!this->motors.at(i)->isEnabled()) {
				this->motors.at(i)->setPositionState(
						this->motors.at(i)->getPositionCommand());
			}
		}
	}
}

void CanCommunication::setGoalPositionV2(double axis_1_pos_goal,
		double axis_2_pos_goal, double axis_3_pos_goal) {
	if (this->hardware_version == 2) {
		this->m1.setPositionCommand(rad_pos_to_steps(axis_1_pos_goal,
				this->m1.getGearRatio(), this->m1.getDirection()));
		this->m2.setPositionCommand(rad_pos_to_steps(axis_2_pos_goal,
				this->m2.getGearRatio(), this->m2.getDirection()));
		this->m3.setPositionCommand(rad_pos_to_steps(axis_3_pos_goal,
				this->m3.getGearRatio(), this->m3.getDirection()));

		// If motor disaled, pos_state = pos_cmd (echo position)
		for (int i = 0; i < this->motors.size(); i++) {
			if (!this->motors.at(i)->isEnabled()) {
				this->motors.at(i)->setPositionState(
						this->motors.at(i)->getPositionCommand());
			}
		}
	}
}

void CanCommunication::getCurrentPositionV1(double *axis_1_pos,
		double *axis_2_pos, double *axis_3_pos, double *axis_4_pos) {
	if (this->hardware_version == 1) {
		*axis_1_pos = steps_to_rad_pos(this->m1.getPositionState(),
				this->m1.getGearRatio(), this->m1.getDirection());
		*axis_2_pos = steps_to_rad_pos(this->m2.getPositionState(),
				this->m2.getGearRatio(), this->m2.getDirection());
		*axis_3_pos = steps_to_rad_pos(this->m3.getPositionState(),
				this->m3.getGearRatio(), this->m3.getDirection());
		*axis_4_pos = steps_to_rad_pos(this->m4.getPositionState(),
				this->m4.getGearRatio(), this->m4.getDirection());
	}
}

void CanCommunication::getCurrentPositionV2(
		double *axis_1_pos, double *axis_2_pos, double *axis_3_pos) {
	if (this->hardware_version == 2) {
		*axis_1_pos = steps_to_rad_pos(this->m1.getPositionState(),
				this->m1.getGearRatio(), this->m1.getDirection());
		*axis_2_pos = steps_to_rad_pos(this->m2.getPositionState(),
				this->m2.getGearRatio(), this->m2.getDirection());
		*axis_3_pos = steps_to_rad_pos(this->m3.getPositionState(),
				this->m3.getGearRatio(), this->m3.getDirection());
	}
}

void CanCommunication::setMicroSteps(std::vector<uint8_t> micro_steps_list) {
	if (micro_steps_list.size() != 4) {
		RCLCPP_WARN(rclcpp::get_logger("CanCommunication"),
				"Micro steps array must have 4 values");
		return;
	}

	for (int i = 0; i < micro_steps_list.size(); i++) {
		this->motors.at(i)->setMicroStepsCommand(micro_steps_list.at(i));
	}

	this->write_micro_steps_enable = true;
}

void CanCommunication::setMaxEffort(std::vector<uint8_t> max_effort_list) {
	if (max_effort_list.size() != 4) {
		RCLCPP_WARN(rclcpp::get_logger("CanCommunication"),
				"Max effort array must have 4 values");
		return;
	}

	for (int i = 0; i < max_effort_list.size(); i++) {
		this->motors.at(i)->setMaxEffortCommand(max_effort_list.at(i));
	}

	this->write_max_effort_enable = true;
}

void CanCommunication::getHardwareStatus(bool *is_connection_ok,
		std::string &error_message, int *calibration_needed,
		bool *calibration_in_progress, std::vector<std::string> &motor_names,
		std::vector<std::string> &motor_types,
		std::vector<int32_t> &temperatures, std::vector<double> &voltages,
		std::vector<int32_t> &hw_errors) {
	*(is_connection_ok) = this->is_can_connection_ok;
	*(calibration_needed) = (this->waiting_for_user_trigger_calibration &&
			this->is_can_connection_ok);
	*(calibration_in_progress) = this->calibration_in_progress;
	error_message = this->debug_error_message;

	motor_names.clear();
	motor_types.clear();
	temperatures.clear();
	voltages.clear();
	hw_errors.clear();

	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			motor_names.push_back(this->motors.at(i)->getName());
			motor_types.push_back("Niryo Stepper");
			temperatures.push_back(this->motors.at(i)->getTemperatureState());
			voltages.push_back(0.0);
			hw_errors.push_back(this->motors.at(i)->getHardwareErrorState());
		}
	}
}

void CanCommunication::getFirmwareVersions(
		std::vector<std::string> &motor_names,
		std::vector<std::string> &firmware_versions) {
	motor_names.clear();
	firmware_versions.clear();

	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			motor_names.push_back(this->motors.at(i)->getName());
			firmware_versions.push_back(
					this->motors.at(i)->getFirmwareVersion());
		}
	}
}

bool CanCommunication::isConnectionOk() {
	return this->is_can_connection_ok;
}

/*
 * Will wait for all required motors to send one CAN frame
 * --> error when
 *  - a motor ID is not allowed
 *  - a required motor is missing
 *  - can't get access to CAN bus
 */
int CanCommunication::scanAndCheck() {
	int counter = 0;

	while (this->hw_is_busy && counter < 100) {
		rclcpp::sleep_for(std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
		counter++;
	}

	if (counter == 100) {
		this->debug_error_message =
				"Failed to scan motors, CAN us is too busy. Will retry...";
		RCLCPP_WARN(rclcpp::get_logger("CanCommunication"),
				"Failed to scan motors, CAN bus is too busy (counter max: %d)",
				counter);
		return CAN_SCAN_BUSY;
	}

	this->hw_is_busy = true;

	// If some motors are disabled, just declare them as connected
	bool m1_ok = !this->m1.isEnabled();
	bool m2_ok = !this->m2.isEnabled();
	bool m3_ok = !this->m3.isEnabled();
	bool m4_ok = !this->m4.isEnabled();
	bool m6_ok = true;
	bool m7_ok = true;

	double time_begin_scan = clock.now().seconds();
	double min_time_to_wait = 0.25;
	double timeout = 0.5;

	while (!m1_ok || !m2_ok || !m3_ok || !m4_ok || !m6_ok || !m7_ok ||
			(clock.now().seconds() - time_begin_scan < min_time_to_wait)) {
		RCLCPP_INFO(rclcpp::get_logger("CanCommunication"), 
			"M1_OK : %d, M2_OK : %d, M3_OK : %d, M4_OK : %d, M6_OK : %d, M7_OK : %d, time: %2f",
			m1_ok, m2_ok, m3_ok, m4_ok, m6_ok, m7_ok, time(NULL) - time_begin_scan);
		rclcpp::sleep_for(std::chrono::milliseconds(1));

		if (this->can->canReadData()) {
			long unsigned int rxId;
			unsigned char len;
			unsigned char rxBuf[8];

			this->can->readMsgBuf(&rxId, &len, rxBuf);

			// Validate ID
			int motor_id =
					rxId & 0x00F;  // 0x101 for ID 1,,, 0x102 for ID 2, ...
			if (motor_id == this->m1.getId()) {
				m1_ok = true;
			} else if (motor_id == this->m2.getId()) {
				m2_ok = true;
			} else if (motor_id == this->m3.getId()) {
				m3_ok = true;
			} else if (this->hardware_version == 1 &&
					motor_id == this->m4.getId()) {
				// m4 only for Niryo One V1
				m4_ok = true;
			} else {
				RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
						"Scan CAN bus: Received CAN frame from wrong ID: %d",
						motor_id);
				this->hw_is_busy = false;
				this->debug_error_message = "Unallowed connected motor: ";
				this->debug_error_message += std::to_string(motor_id);
				RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
						this->debug_error_message.c_str());
				return CAN_SCAN_NOT_ALLOWED;
			}
		}

		if (time(NULL) - time_begin_scan > timeout) {
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					"CAN bus scan failed: motors");
			if (!m1_ok) {
				this->debug_error_message += this->m1.getName() + ", ";
			}
			if (!m2_ok) {
				this->debug_error_message += this->m2.getName() + ", ";
			}
			if (!m3_ok) {
				this->debug_error_message += this->m3.getName() + ", ";
			}
			if (!m4_ok) {
				this->debug_error_message += this->m4.getName() + ", ";
			}
			this->debug_error_message += " are not connected";
			this->is_can_connection_ok = false;
			this->hw_is_busy = false;
			RCLCPP_ERROR(rclcpp::get_logger("CanCommunication"),
					this->debug_error_message.c_str());
			return CAN_SCAN_TIMEOUT;
		}
	}

	this->hw_is_busy = false;
	this->is_can_connection_ok = true;
	this->debug_error_message = "";
	return CAN_SCAN_OK;
}

int CanCommunication::setConveyor(uint8_t id, bool activate) {
	if (id == CAN_MOTOR_CONVEYOR_1_ID) {
		if (activate) {
			this->m6.enable();
			this->is_conveyor_id_1_connected = activate;
		} else {
			this->m6.disable();
		}
		this->conveyor_id_1_state = activate;
	} else if (id == CAN_MOTOR_CONVEYOR_2_ID) {
		if (activate) {
			this->m7.enable();
			this->is_conveyor_id_2_connected = activate;
		} else {
			this->m7.disable();
		}
		this->conveyor_id_2_state = activate;
	} else {
		return CONVEYOR_STATE_SET_ERROR;
	}
	return CONVEYOR_STATE_SET_OK;
}

int CanCommunication::conveyorOn(
		uint8_t id, bool control_on, int16_t speed, int8_t direction) {
	if (id == CAN_MOTOR_CONVEYOR_1_ID) {
		this->is_conveyor_id_1_on = control_on;
		this->conveyor_id_1_speed = speed;
		this->conveyor_id_1_direction = direction;
	} else if (id == CAN_MOTOR_CONVEYOR_2_ID) {
		this->is_conveyor_id_2_on = control_on;
		this->conveyor_id_2_speed = speed;
		this->conveyor_id_2_direction = direction;
	} else {
		return CONVEYOR_CONTROL_ERROR;
	}
	return CONVEYOR_CONTROL_OK;
}

int CanCommunication::updateConveyorId(uint8_t id, uint8_t new_id_up) {
	if (new_id_up != CAN_MOTOR_CONVEYOR_1_ID &&
			new_id_up != CAN_MOTOR_CONVEYOR_2_ID &&
			id != CAN_MOTOR_CONVEYOR_1_ID && id != CAN_MOTOR_CONVEYOR_2_ID) {
		return CONVEYOR_UPDATE_ID_ERROR;
	}

	if ((this->is_conveyor_id_1_connected && id == CAN_MOTOR_CONVEYOR_1_ID) ||
			(this->is_conveyor_id_2_connected &&
					id == CAN_MOTOR_CONVEYOR_2_ID)) {
		this->update_id = true;
		this->new_id = new_id_up;
		this->old_id = id;
		return CONVEYOR_UPDATE_ID_OK;
	}
	return CONVEYOR_UPDATE_ID_ERROR;
}

void CanCommunication::getConveyorFeedBack(uint8_t conveyor_id,
		bool *connection_state, bool *running, int16_t *speed,
		int8_t *direction) {
	if (conveyor_id == CAN_MOTOR_CONVEYOR_1_ID) {
		*connection_state = this->is_conveyor_id_1_connected;
		*running = this->m6.getConveyorControlState();
		*speed = this->m6.getConveyorSpeed();
		*direction = this->m6.getConveyorDirection();
	} else if (conveyor_id == CAN_MOTOR_CONVEYOR_2_ID) {
		*connection_state = this->is_conveyor_id_2_connected;
		*running = this->m7.getConveyorControlState();
		*speed = this->m7.getConveyorSpeed();
		*direction = this->m7.getConveyorDirection();
	}
}

void CanCommunication::resetConveyor(uint8_t conveyor_id) {
	if (conveyor_id == CAN_MOTOR_CONVEYOR_1_ID) {
		this->m6.setConveyorFeedback(false, 0, 1);
		this->is_conveyor_id_1_on = false;
		this->conveyor_id_1_speed = 0;
		this->conveyor_id_1_direction = 1;
	} else if (conveyor_id == CAN_MOTOR_CONVEYOR_2_ID) {
		this->m7.setConveyorFeedback(false, 0, 1);
		this->is_conveyor_id_2_on = false;
		this->conveyor_id_2_speed = 0;
		this->conveyor_id_2_direction = 1;
	}
	this->update_id = false;
}
