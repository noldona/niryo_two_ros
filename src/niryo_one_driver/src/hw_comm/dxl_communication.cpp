#include "niryo_one_driver/dxl_communication.hpp"

uint32_t DxlCommunication::rad_pos_to_xl320_pos(double position_rad) {
	return (uint32_t) (double) XL320_MIDDLE_POSITION +
			(position_rad * RADIAN_TO_DEGREE *
					(double) XL320_TOTAL_RANGE_POSITION /
					(double) XL320_TOTAL_ANGLE);
}

double DxlCommunication::xl320_pos_to_rad_pos(uint32_t position_dxl) {
	return (double) (((double) position_dxl - XL320_MIDDLE_POSITION) *
			(double) XL430_TOTAL_ANGLE /
			(RADIAN_TO_DEGREE * (double) XL430_TOTAL_RANGE_POSITION));
}

uint32_t DxlCommunication::rad_pos_to_xl430_pos(double position_rad) {
	return (uint32_t) (double) XL430_MIDDLE_POSITION +
			(position_rad * RADIAN_TO_DEGREE *
					(double) XL430_TOTAL_RANGE_POSITION /
					(double) XL430_TOTAL_ANGLE);
}

double DxlCommunication::xl430_pos_to_rad_pos(uint32_t position_dxl) {
	return (double) (((double) position_dxl - XL430_MIDDLE_POSITION) *
			(double) XL430_TOTAL_ANGLE /
			(RADIAN_TO_DEGREE * (double) XL430_TOTAL_RANGE_POSITION));
}

int DxlCommunication::init(int hardware_version) {
	this->hardware_version = hardware_version;

	if (hardware_version != 1 && hardware_version != 2) {
		this->debug_error_message =
				"Incorrect hardware version, should be 1 or 2";
		RCLCPP_ERROR(this->get_logger(), this->debug_error_message.c_str());
		return -1;
	}

	// Get params from ROS
	this->declare_parameter("dxl_uart_device_name", rclcpp::PARAMETER_STRING);
	this->declare_parameter("dxl_baudrate", rclcpp::PARAMETER_INTEGER);
	this->declare_parameter(
			"dxl_hardware_control_loop_frequency", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter("dxl_hw_write_frequency", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"dxl_hw_data_read_frequency", rclcpp::PARAMETER_DOUBLE);
	this->declare_parameter(
			"dxl_hw_status_read_frequency", rclcpp::PARAMETER_DOUBLE);
	this->device_name = this->get_parameter("dxl_uart_device_name").as_string();
	this->uart_baudrate = this->get_parameter("dxl_baudrate").as_int();
	this->hw_control_loop_frequency =
			this->get_parameter("dxl_hardware_control_loop_frequency")
					.as_double();
	this->hw_data_write_frequency =
			this->get_parameter("dxl_hw_write_frequency").as_double();
	this->hw_data_read_frequency =
			this->get_parameter("dxl_hw_data_read_frequency").as_double();
	this->hw_status_read_frequency =
			this->get_parameter("dxl_hw_status_read_frequency").as_double();

	RCLCPP_INFO(this->get_logger(), "Start Dxl communication (%lf Hz)",
			this->hw_control_loop_frequency);
	RCLCPP_INFO(this->get_logger(), "Writing data on Dxl at %lf Hz",
			this->hw_data_write_frequency);
	RCLCPP_INFO(this->get_logger(), "Reading data from Dxl at %lf Hz",
			this->hw_data_read_frequency);
	RCLCPP_INFO(this->get_logger(),
			"Reading hardware error status from Dxl at %lf Hz",
			this->hw_status_read_frequency);

	this->resetHardwareControlLoopRates();

	this->dxlPortHandler =
			dynamixel::PortHandler::getPortHandler(this->device_name.c_str());
	this->dxlPacketHandler = dynamixel::PacketHandler::getPacketHandler(
			DXL_BUS_PROTOCOL_VERSION);

	this->xl320.reset(
			new XL320Driver(this->dxlPortHandler, this->dxlPacketHandler));
	this->xl430.reset(
			new XL430Driver(this->dxlPortHandler, this->dxlPacketHandler));

	this->is_dxl_connection_ok = false;
	this->debug_error_message =
			"No connection with Dynamixel motors has been made yet";

	// Get required and authorized motor IDs
	this->declare_parameter(
			"dxl_required_motors", rclcpp::PARAMETER_INTEGER_ARRAY);
	this->declare_parameter(
			"dxl_authorized_motors", rclcpp::PARAMETER_INTEGER_ARRAY);
	std::vector<long int> required_dxl_ids =
			this->get_parameter("dxl_required_motors").as_integer_array();
	std::vector<long int> allowed_dxl_ids =
			this->get_parameter("dxl_authorized_motors").as_integer_array();

	this->required_motors_ids.insert(this->required_motors_ids.end(),
			required_dxl_ids.begin(), required_dxl_ids.end());
	this->allowed_motors_ids.insert(this->allowed_motors_ids.end(),
			required_dxl_ids.begin(), required_dxl_ids.end());
	this->allowed_motors_ids.insert(this->allowed_motors_ids.end(),
			allowed_dxl_ids.begin(), allowed_dxl_ids.end());

	// Create motors
	// Hardware version 1 : 2 motors for axis 5, 1 for axis 6, 1 for tool (all XL320)
	if (hardware_version == 1) {
		this->m5_1 = DxlMotorState("Servo Axis 5_1", DXL_MOTOR_5_1_ID,
				MOTOR_TYPE_XL320, XL320_MIDDLE_POSITION);
		this->m5_2 = DxlMotorState("Servo Axis 5_2", DXL_MOTOR_5_2_ID,
				MOTOR_TYPE_XL320, XL320_MIDDLE_POSITION);
	}
	// Hardware version 2 : 1 motor (XL430) for axis 4, 1 (XL430) for axis 5, 1 (XL320) for axis 6, 1 (XL320) for tool
	if (hardware_version == 2) {
		this->m4 = DxlMotorState("Servo Axis 4", DXL_MOTOR_4_ID,
				MOTOR_TYPE_XL430, XL430_MIDDLE_POSITION);
		this->m5 = DxlMotorState("Servo Axis 5", DXL_MOTOR_5_ID,
				MOTOR_TYPE_XL430, XL430_MIDDLE_POSITION);
	}

	this->m6 = DxlMotorState("Servo Axis 6", DXL_MOTOR_6_ID, MOTOR_TYPE_XL320,
			XL320_MIDDLE_POSITION);

	// Enale motors
	if (hardware_version == 1) {
		for (int i = 0; i < required_dxl_ids.size(); i++) {
			if (required_dxl_ids.at(i) == this->m5_1.getId()) {
				this->m5_1.enable();
			} else if (required_dxl_ids.at(i) == this->m5_2.getId()) {
				this->m5_2.enable();
			} else if (required_dxl_ids.at(i) == this->m6.getId()) {
				this->m6.enable();
			} else {
				this->debug_error_message =
						"Incorrect configuration: Wrong ID (" +
						std::to_string(required_dxl_ids.at(i)) +
						") given in ROS param "
						"/niryo_one_motors/dxl_required_motors.";
				RCLCPP_ERROR(
						this->get_logger(), this->debug_error_message.c_str());
				return -1;
			}
		}
	} else if (hardware_version == 2) {
		for (int i = 0; i < required_dxl_ids.size(); i++) {
			if (required_dxl_ids.at(i) == this->m4.getId()) {
				this->m4.enable();
			} else if (required_dxl_ids.at(i) == this->m5.getId()) {
				this->m5.enable();
			} else if (required_dxl_ids.at(i) == this->m6.getId()) {
				this->m6.enable();
			} else {
				this->debug_error_message =
						"Incorrect configuration: Wrong ID (" +
						std::to_string(required_dxl_ids.at(i)) +
						") given in ROS param "
						"/niryo_one_motors/dxl_required_motors.";
				RCLCPP_ERROR(
						this->get_logger(), this->debug_error_message.c_str());
				return -1;
			}
		}
	}

	if (required_dxl_ids.size() == 0) {
		this->debug_error_message =
				"Incorrect configuration: ROS param "
				"/niryo_one_motors/dxl_required_motors should contain a list "
				"with at least one motor.";
		RCLCPP_ERROR(this->get_logger(), this->debug_error_message.c_str());
		return -1;
	}

	// Fill motor array
	if (hardware_version == 1) {
		this->motors.push_back(&this->m5_1);
		this->motors.push_back(&this->m5_2);
	} else if (hardware_version == 2) {
		this->motors.push_back(&this->m4);
		this->motors.push_back(&this->m5);
	}
	this->motors.push_back(&this->m6);

	this->tool = DxlMotorState(
			"No tool conneccted", 0, MOTOR_TYPE_XL320, XL320_MIDDLE_POSITION);
	this->is_tool_connected = false;

	this->torque_on = 0;
	this->should_reboot_motors = false;

	// For hardware control loop
	this->hw_is_busy - false;
	this->hw_limited_mode = true;

	this->read_position_enable = true;
	this->read_velocity_enable = true;  // Not useful for now
	this->read_torque_enable = true;
	this->read_hw_status_enable = true;

	return this->setupCommunication();
}

void DxlCommunication::addCustomDxlCommand(int motor_type, uint8_t id,
		uint32_t value, uint32_t reg_address, uint32_t byte_number) {
	custom_command_queue.push(
			DxlCustomCommand(motor_type, id, value, reg_address, byte_number));
}

void DxlCommunication::rebootMotors() {
	this->should_reboot_motors = true;
}

int DxlCommunication::setupCommunication() {
	RCLCPP_INFO(this->get_logger(), "Dxl: Set port name (%s), baudrate(%d)",
			this->device_name.c_str(), this->uart_baudrate);

	// Setup half-duplex direction GPIO
	// See schema http://support.robotis.com/en/product/actuator/dynamixel_x/xl-series_main.htm
	if (!dxlPortHandler->setupGpio()) {
		RCLCPP_ERROR(this->get_logger(),
				"Failed to setup direction GPIO pin for Dynamixel half-duplex "
				"serial");
		return DXL_FAIL_SETUP_GPIO;
	}

	// Open port
	if (!dxlPortHandler->openPort()) {
		RCLCPP_ERROR(this->get_logger(), "Failed to open the port!");
		return DXL_FAIL_OPEN_PORT;
	}

	// Set baudrate
	if (!dxlPortHandler->setBaudRate(uart_baudrate)) {
		RCLCPP_ERROR(this->get_logger(), "Failed to set baudrate!");
		return DXL_FAIL_PORT_SET_BAUDRATE;
	}

	rclcpp::sleep_for(std::chrono::milliseconds(100));
	return COMM_SUCCESS;
}

bool DxlCommunication::isOnLimitedMode() {
	return this->hw_limited_mode;
}

void DxlCommunication::resetHardwareControlLoopRates() {
	double now = rclcpp::Clock().now().seconds();
	this->time_hw_data_last_read = now;
	this->time_hw_status_last_read = now;
	this->time_hw_status_last_read = now;
}

void DxlCommunication::startHardwareControlLoop(bool limited_mode) {
	RCLCPP_INFO(this->get_logger(), "DXL: Start hardware control loop");
	this->xl320_hw_fail_counter_read = 0;
	this->xl430_hw_fail_counter_read = 0;
	this->write_led_enable = true;
	this->write_torque_on_enable = true;
	this->resetHardwareControlLoopRates();
	this->hw_control_loop_keep_alive = true;

	// Depends on limited_mode flag
	this->write_position_enable = limited_mode;
	this->hw_limited_mode = limited_mode;

	if (!this->hardware_control_loop_thread) {
		RCLCPP_WARN(this->get_logger(), "START ctrl loop thread dxl");
		this->hardware_control_loop_thread.reset(new std::thread(
				std::bind(&DxlCommunication::hardwareControlLoop, this)));
	}
}

void DxlCommunication::stopHardwareControlLoop() {
	for (int i = 0; i < this->motors.size(); i++) {
		this->motors.at(i)->resetState();
	}
	this->tool.resetState();
	this->hw_control_loop_keep_alive = false;
}

void DxlCommunication::hardwareControlRead() {
	std::vector<uint8_t> xl320_id_list;
	std::vector<uint8_t> xl430_id_list;

	// Used to reduce redundant code after
	// Those arrays will contain only enabled motors
	std::vector<DxlMotorState *> xl320_motor_list;
	std::vector<DxlMotorState *> xl430_motor_list;

	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			if (this->motors.at(i)->getType() == MOTOR_TYPE_XL320) {
				xl320_id_list.push_back(this->motors.at(i)->getId());
				xl320_motor_list.push_back(this->motors.at(i));
			} else if (this->motors.at(i)->getType() == MOTOR_TYPE_XL430) {
				xl430_id_list.push_back(this->motors.at(i)->getId());
				xl430_motor_list.push_back(this->motors.at(i));
			}
		}
	}

	if (this->is_tool_connected) {
		xl320_id_list.push_back(this->tool.getId());
		xl320_motor_list.push_back(&this->tool);
	}

	bool can_read_xl320 = (xl320_motor_list.size() > 0);
	bool can_read_xl430 = (xl430_motor_list.size() > 0);

	if (!can_read_xl320 && !can_read_xl430) {
		return;  // No motor, nothing to read
	}

	// We now have all enabled motors separated in 2 categories
	// Read data
	if (rclcpp::Clock().now().seconds() - this->time_hw_data_last_read >
			1.0 / this->hw_data_read_frequency) {
		this->time_hw_data_last_read += 1.0 / this->hw_data_read_frequency;

		// Read position
		if (this->read_position_enable) {
			// Read from XL320 motors
			if (can_read_xl320) {
				std::vector<uint32_t> position_list;
				int read_position_result =
						xl320->syncReadPosition(xl320_id_list, position_list);
				if (read_position_result == COMM_SUCCESS) {
					xl320_hw_fail_counter_read = 0;
					for (int i = 0; i < xl320_motor_list.size(); i++) {
						xl320_motor_list.at(i)->setPositionState(
								position_list.at(i));
					}
				} else {
					xl320_hw_fail_counter_read++;
				}
			}

			// Read from XL430 motors
			if (can_read_xl430) {
				std::vector<uint32_t> position_list;
				int read_position_result =
						xl430->syncReadPosition(xl430_id_list, position_list);
				if (read_position_result == COMM_SUCCESS) {
					xl430_hw_fail_counter_read = 0;
					for (int i = 0; i < xl430_motor_list.size(); i++) {
						xl430_motor_list.at(i)->setPositionState(
								position_list.at(i));
					}
				} else {
					xl430_hw_fail_counter_read++;
				}
			}
		}

		// Read velocity
		if (this->read_velocity_enable) {
			if (can_read_xl320) {
				std::vector<uint32_t> velocity_list;
				int read_velocity_result =
						xl320->syncReadVelocity(xl320_id_list, velocity_list);
				if (read_velocity_result == COMM_SUCCESS) {
					xl320_hw_fail_counter_read = 0;
					for (int i = 0; i < xl320_motor_list.size(); i++) {
						xl320_motor_list.at(i)->setVelocityState(
								velocity_list.at(i));
					}
				} else {
					xl320_hw_fail_counter_read++;
				}
			}

			if (can_read_xl430) {
				std::vector<uint32_t> velocity_list;
				int read_velocity_result =
						xl430->syncReadVelocity(xl430_id_list, velocity_list);
				if (read_velocity_result == COMM_SUCCESS) {
					xl430_hw_fail_counter_read = 0;
					for (int i = 0; i < xl430_motor_list.size(); i++) {
						xl430_motor_list.at(i)->setVelocityState(
								velocity_list.at(i));
					}
				} else {
					xl430_hw_fail_counter_read++;
				}
			}
		}

		// Read load
		if (this->read_torque_enable) {
			if (can_read_xl320) {
				std::vector<uint32_t> torque_list;
				int read_torque_result =
						xl320->syncReadLoad(xl320_id_list, torque_list);
				if (read_torque_result == COMM_SUCCESS) {
					xl320_hw_fail_counter_read = 0;
					for (int i = 0; i < xl320_motor_list.size(); i++) {
						xl320_motor_list.at(i)->setTorqueState(
								torque_list.at(i));
					}
				} else {
					xl320_hw_fail_counter_read++;
				}
			}

			if (can_read_xl430) {
				std::vector<uint32_t> torque_list;
				int read_torque_result =
						xl430->syncReadLoad(xl430_id_list, torque_list);
				if (read_torque_result == COMM_SUCCESS) {
					xl430_hw_fail_counter_read = 0;
					for (int i = 0; i < xl430_motor_list.size(); i++) {
						xl430_motor_list.at(i)->setTorqueState(
								torque_list.at(i));
					}
				} else {
					xl430_hw_fail_counter_read++;
				}
			}
		}
	}

	// Read hardware status
	if (this->read_hw_status_enable) {
		if (rclcpp::Clock().now().seconds() - this->time_hw_status_last_read >
				1.0 / this->hw_status_read_frequency) {
			this->time_hw_data_last_read +=
					1.0 / this->hw_status_read_frequency;

			// Read Temperature
			if (can_read_xl320) {
				std::vector<uint32_t> temperature_list;
				int read_temperature_result = xl320->syncReadTemperature(
						xl320_id_list, temperature_list);
				if (read_temperature_result == COMM_SUCCESS) {
					xl320_hw_fail_counter_read = 0;
					for (int i = 0; i < xl320_motor_list.size(); i++) {
						xl320_motor_list.at(i)->setTemperatureState(
								temperature_list.at(i));
					}
				} else {
					xl320_hw_fail_counter_read++;
				}
			}

			if (can_read_xl430) {
				std::vector<uint32_t> temperature_list;
				int read_temperature_result = xl430->syncReadTemperature(
						xl430_id_list, temperature_list);
				if (read_temperature_result == COMM_SUCCESS) {
					xl430_hw_fail_counter_read = 0;
					for (int i = 0; i < xl430_motor_list.size(); i++) {
						xl430_motor_list.at(i)->setTemperatureState(
								temperature_list.at(i));
					}
				} else {
					xl430_hw_fail_counter_read++;
				}
			}

			// Read voltage
			if (can_read_xl320) {
				std::vector<uint32_t> voltage_list;
				int read_voltage_result =
						xl320->syncReadVoltage(xl320_id_list, voltage_list);
				if (read_voltage_result == COMM_SUCCESS) {
					xl320_hw_fail_counter_read = 0;
					for (int i = 0; i < xl320_motor_list.size(); i++) {
						xl320_motor_list.at(i)->setVoltageState(
								voltage_list.at(i));
					}
				} else {
					xl320_hw_fail_counter_read++;
				}
			}

			if (can_read_xl430) {
				std::vector<uint32_t> voltage_list;
				int read_voltage_result =
						xl430->syncReadVoltage(xl430_id_list, voltage_list);
				if (read_voltage_result == COMM_SUCCESS) {
					xl430_hw_fail_counter_read = 0;
					for (int i = 0; i < xl430_motor_list.size(); i++) {
						xl430_motor_list.at(i)->setVoltageState(
								voltage_list.at(i));
					}
				} else {
					xl430_hw_fail_counter_read++;
				}
			}

			// Read HW Error
			if (can_read_xl320) {
				std::vector<uint32_t> hw_error_list;
				int read_hw_error_result = xl320->syncReadHwErrorStatus(
						xl320_id_list, hw_error_list);
				if (read_hw_error_result == COMM_SUCCESS) {
					xl320_hw_fail_counter_read = 0;
					for (int i = 0; i < xl320_motor_list.size(); i++) {
						xl320_motor_list.at(i)->setHardwareError(
								hw_error_list.at(i));
					}
				} else {
					xl320_hw_fail_counter_read++;
				}
			}

			if (can_read_xl430) {
				std::vector<uint32_t> hw_error_list;
				int read_hw_error_result = xl430->syncReadHwErrorStatus(
						xl430_id_list, hw_error_list);
				if (read_hw_error_result == COMM_SUCCESS) {
					xl430_hw_fail_counter_read = 0;
					for (int i = 0; i < xl430_motor_list.size(); i++) {
						xl430_motor_list.at(i)->setHardwareError(
								hw_error_list.at(i));
					}
				} else {
					xl430_hw_fail_counter_read++;
				}
			}
		}
	}

	if (this->xl320_hw_fail_counter_read > 25 ||
			this->xl430_hw_fail_counter_read > 25) {
		RCLCPP_ERROR(this->get_logger(),
				"Dxl connection problem - Failed to read from Dxl bus");
		this->xl320_hw_fail_counter_read = 0;
		this->xl430_hw_fail_counter_read = 0;
		this->is_dxl_connection_ok = false;
		this->debug_error_message = "Connection problem wtih Dynamixel Bus.";
	}
}

void DxlCommunication::hardwareControlWrite() {
	std::vector<uint8_t> xl320_id_list;
	std::vector<uint8_t> xl430_id_list;

	// Used to reduce redundant code after
	// Those arrays will contain only enabled motors
	std::vector<DxlMotorState *> xl320_motor_list;
	std::vector<DxlMotorState *> xl430_motor_list;

	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			if (this->motors.at(i)->getType() == MOTOR_TYPE_XL320) {
				xl320_id_list.push_back(this->motors.at(i)->getId());
				xl320_motor_list.push_back(this->motors.at(i));
			} else if (this->motors.at(i)->getType() == MOTOR_TYPE_XL430) {
				xl430_id_list.push_back(this->motors.at(i)->getId());
				xl430_motor_list.push_back(this->motors.at(i));
			}
		}
	}

	// If asked to reboot motores, reboot all motors
	// Even the ones which are not enabled
	// Same command for xl320 and xl430 (depends on protocol, not motor type)
	if (this->should_reboot_motors) {
		for (int i = 0; i < this->motors.size(); i++) {
			RCLCPP_WARN(this->get_logger(), "Reboot Dxl motor with ID: %d",
					this->motors.at(i)->getId());
			this->xl430->reboot(this->motors.at(i)->getId());
		}
		if (this->tool.getId() != 0) {
			RCLCPP_WARN(this->get_logger(), "Reboot Dxl tool with ID: %d",
					this->tool.getId());
			this->xl430->reboot(this->tool.getId());
		}
		this->should_reboot_motors = false;
	}

	if (rclcpp::Clock().now().seconds() - this->time_hw_data_last_write >
			1.0 / this->hw_data_write_frequency) {
		this->time_hw_data_last_write += 1.0 / this->hw_data_write_frequency;

		// Send custom command if any
		if (this->custom_command_queue.size() > 0) {
			DxlCustomCommand cmd = this->custom_command_queue.front();

			RCLCPP_INFO(this->get_logger(),
					"Sending custom command to Dynamixel:\nMotor type: %d, ID: "
					"%d, Value: %d, Address: %d, Size: %d",
					cmd.motor_type, (int) cmd.id, (int) cmd.value,
					(int) cmd.reg_address, (int) cmd.byte_number);

			if (cmd.motor_type == MOTOR_TYPE_XL320) {
				int result = this->xl320->customWrite(
						cmd.id, cmd.value, cmd.reg_address, cmd.byte_number);
				if (result != COMM_SUCCESS) {
					RCLCPP_WARN(this->get_logger(),
							"Failed to write custom command: %d", result);
				}
			} else if (cmd.motor_type == MOTOR_TYPE_XL430) {
				int result = this->xl430->customWrite(
						cmd.id, cmd.value, cmd.reg_address, cmd.byte_number);
				if (result != COMM_SUCCESS) {
					RCLCPP_WARN(this->get_logger(),
							"Failed to write custom command: %d", result);
				}
			} else {
				RCLCPP_ERROR(this->get_logger(),
						"Wrong motor type, should be 1 (XL-320) or 2 "
						"(XL-430).");
			}

			// Remove from queue if successfully sent
			custom_command_queue.pop();
		}
	}

	// Write torque enable (for all motors, including tool)
	if (this->write_torque_on_enable) {
		std::vector<uint32_t> xl320_torque_enable_list;
		for (int i = 0; i < xl320_motor_list.size(); i++) {
			xl320_torque_enable_list.push_back(this->torque_on);
		}

		if (this->is_tool_connected) {
			xl320_id_list.push_back(this->tool.getId());
			xl320_torque_enable_list.push_back(this->torque_on);
		}

		std::vector<uint32_t> xl430_torque_enable_list;
		for (int i = 0; i < xl430_motor_list.size(); i++) {
			xl430_torque_enable_list.push_back(this->torque_on);
		}

		int xl320_result = this->xl320->syncWriteTorqueEnable(
				xl320_id_list, xl320_torque_enable_list);
		int xl430_result = this->xl430->syncWriteTorqueEnable(
				xl430_id_list, xl430_torque_enable_list);

		if (xl320_result != COMM_SUCCESS || xl430_result != COMM_SUCCESS) {
			RCLCPP_WARN(this->get_logger(), "Failed to write torque enable");
		} else {
			this->write_torque_on_enable =
					false;  // Disable writing torque ON/OFF after scucess on all motors
		}

		if (this->is_tool_connected) {
			xl320_id_list.pop_back();
		}
	}

	if (this->torque_on) {
		// Write position (not for tool)
		if (this->write_position_enable) {
			std::vector<uint32_t> xl320_position_list;
			for (int i = 0; i < xl320_motor_list.size(); i++) {
				xl320_position_list.push_back(
						xl320_motor_list.at(i)->getPositionCommand());
			}

			std::vector<uint32_t> xl430_position_list;
			for (int i = 0; i < xl430_motor_list.size(); i++) {
				xl430_position_list.push_back(
						xl430_motor_list.at(i)->getPositionCommand());
			}

			int xl320_result = this->xl320->syncWritePositionGoal(
					xl320_id_list, xl320_position_list);
			int xl430_result = this->xl430->syncWritePositionGoal(
					xl430_id_list, xl430_position_list);

			if (xl320_result != COMM_SUCCESS || xl430_result != COMM_SUCCESS) {
				RCLCPP_WARN(this->get_logger(), "Failed to write position");
			}
		}

		// Write velocity (not for tool)
		if (this->write_velocity_enable) {
			std::vector<uint32_t> xl320_velocity_list;
			for (int i = 0; i < xl320_motor_list.size(); i++) {
				xl320_velocity_list.push_back(
						xl320_motor_list.at(i)->getVelocityCommand());
			}

			std::vector<uint32_t> xl430_velocity_list;
			for (int i = 0; i < xl430_motor_list.size(); i++) {
				xl430_velocity_list.push_back(
						xl430_motor_list.at(i)->getVelocityCommand());
			}

			int xl320_result = this->xl320->syncWriteVelocityGoal(
					xl320_id_list, xl320_velocity_list);
			int xl430_result = this->xl430->syncWriteVelocityGoal(
					xl430_id_list, xl430_velocity_list);

			if (xl320_result != COMM_SUCCESS || xl430_result != COMM_SUCCESS) {
				RCLCPP_WARN(this->get_logger(), "Failed to write velocity");
			}
		}

		// Write torque (not for tool)
		if (this->write_torque_enable) {
			std::vector<uint32_t> xl320_torque_list;
			for (int i = 0; i < xl320_motor_list.size(); i++) {
				xl320_torque_list.push_back(
						xl320_motor_list.at(i)->getTorqueCommand());
			}

			std::vector<uint32_t> xl430_torque_list;
			for (int i = 0; i < xl430_motor_list.size(); i++) {
				xl430_torque_list.push_back(
						xl430_motor_list.at(i)->getTorqueCommand());
			}

			int xl320_result = this->xl320->syncWriteTorqueGoal(
					xl320_id_list, xl320_torque_list);
			int xl430_result = this->xl430->syncWriteTorqueGoal(
					xl430_id_list, xl430_torque_list);

			if (xl320_result != COMM_SUCCESS || xl430_result != COMM_SUCCESS) {
				RCLCPP_WARN(this->get_logger(), "Failed to write torque");
			}
		}

		// Write tool separately = send position, velocity, and torque together
		if (this->write_tool_enable && this->is_tool_connected) {
			rclcpp::sleep_for(std::chrono::milliseconds(5));
			int write_tool_velocity_result = this->xl320->setGoalVelocity(
					this->tool.getId(), this->tool.getVelocityCommand());
			rclcpp::sleep_for(std::chrono::milliseconds(5));
			int write_tool_position_result = this->xl320->setGoalPosition(
					this->tool.getId(), this->tool.getPositionCommand());
			rclcpp::sleep_for(std::chrono::milliseconds(5));
			int write_tool_torque_result = this->xl320->setGoalTorque(
					this->tool.getId(), this->tool.getTorqueCommand());

			if (write_tool_velocity_result != COMM_SUCCESS ||
					write_tool_position_result != COMM_SUCCESS ||
					write_tool_torque_result != COMM_SUCCESS) {
				RCLCPP_WARN(this->get_logger(), "Failed to write tool");
			} else {
				this->write_tool_enable =
						false;  // Disable writing tool after scucess
			}
		}

		// Write led
		if (this->write_led_enable) {
			std::vector<uint32_t> xl320_led_list;
			for (int i = 0; i < xl320_motor_list.size(); i++) {
				xl320_led_list.push_back(
						xl320_motor_list.at(i)->getLedCommand());
			}

			if (this->is_tool_connected) {
				xl320_id_list.push_back(this->tool.getId());
				xl320_led_list.push_back(this->tool.getLedCommand());
			}

			int xl320_result =
					this->xl320->syncWriteLed(xl320_id_list, xl320_led_list);

			if (xl320_result != COMM_SUCCESS) {
				RCLCPP_WARN(this->get_logger(), "Failed to write LED");
			} else {
				this->write_led_enable =
						false;  // Disable writing led after scucess
			}

			if (this->is_tool_connected) {
				xl320_id_list.pop_back();
			}
		}
	}
}

void DxlCommunication::hardwareControlLoop() {
	rclcpp::Rate hw_control_loop_rate =
			rclcpp::Rate(this->hw_control_loop_frequency);

	while (rclcpp::ok()) {
		if (!this->hw_is_busy && this->hw_control_loop_keep_alive) {
			this->hw_is_busy = true;

			this->hardwareControlRead();
			this->hardwareControlWrite();

			this->hw_is_busy = false;
			hw_control_loop_rate.sleep();
		} else {
			rclcpp::sleep_for(std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
			this->resetHardwareControlLoopRates();
		}
	}
}

/*
 * Only use this method during calibration!!
 * This will make all Dynamixels go to their home position
 * so the axis 3 will be correctly calibrated
 */
void DxlCommunication::moveAllMotorsToHomePosition() {
	// 1. Set cmd home position
	if (this->hardware_version == 1) {
		this->m5_1.setPositionCommand(XL320_MIDDLE_POSITION);
		this->m5_2.setPositionCommand(XL320_MIDDLE_POSITION);
		this->m6.setPositionCommand(XL320_MIDDLE_POSITION);
	} else if (this->hardware_version == 2) {
		this->m4.setPositionCommand(XL430_MIDDLE_POSITION);
		this->m5.setPositionCommand(XL430_MIDDLE_POSITION);
		this->m6.setPositionCommand(XL320_MIDDLE_POSITION);
	}

	// If motor disabled, pos_state = pos_cmd (echo position)
	for (int i = 0; i < this->motors.size(); i++) {
		if (!this->motors.at(i)->isEnabled()) {
			this->motors.at(i)->setPositionState(
					this->motors.at(i)->getPositionCommand());
		}
	}

	// 2. Set torque on (override default). Motors will be deactivated after calibration is finished
	this->torque_on = true;
	this->write_torque_on_enable = true;
}

void DxlCommunication::setControlMode(int control_mode) {
	this->write_position_enable = (control_mode == DXL_CONTROL_MODE_POSITION);
	this->write_velocity_enable =
			(control_mode == DXL_CONTROL_MODE_VELOCITY);  // Not implemented yet
	this->write_torque_enable =
			(control_mode == DXL_CONTROL_MODE_TORQUE);  // Not implemented yet
}

void DxlCommunication::setGoalPositionV1(double axis_5_pos, double axis_6_pos) {
	if (this->hardware_version == 1) {
		this->m5_1.setPositionCommand(this->rad_pos_to_xl320_pos(axis_5_pos));
		this->m5_2.setPositionCommand(
				XL320_MIDDLE_POSITION * 2 - this->m5_1.getPositionCommand());
		this->m6.setPositionCommand(this->rad_pos_to_xl320_pos(axis_6_pos));

		// If motor disabled, pos_state = pos_cmd (echo position)
		for (int i = 0; i < this->motors.size(); i++) {
			if (!this->motors.at(i)->isEnabled()) {
				this->motors.at(i)->setPositionState(
						this->motors.at(i)->getPositionCommand());
			}
		}
	}
}

void DxlCommunication::setGoalPositionV2(
		double axis_4_pos, double axis_5_pos, double axis_6_pos) {
	if (this->hardware_version == 2) {
		this->m4.setPositionCommand(this->rad_pos_to_xl430_pos(axis_4_pos));
		// m5 for V2 is placed at the previous m5_2 place
		this->m5.setPositionCommand(XL430_MIDDLE_POSITION * 2 -
				this->rad_pos_to_xl320_pos(axis_5_pos));
		this->m6.setPositionCommand(this->rad_pos_to_xl320_pos(axis_6_pos));

		// If motor disabled, pos_state = pos_cmd (echo position)
		for (int i = 0; i < this->motors.size(); i++) {
			if (!this->motors.at(i)->isEnabled()) {
				this->motors.at(i)->setPositionState(
						this->motors.at(i)->getPositionCommand());
			}
		}
	}
}

void DxlCommunication::getCurrentPositionV1(
		double *axis_5_pos, double *axis_6_pos) {
	if (this->hardware_version == 1) {
		if (this->m5_1.isEnabled()) {
			*axis_5_pos =
					this->xl320_pos_to_rad_pos(this->m5_1.getPositionState());
		} else {
			// In case motor 5_1 is disabled, take motor 5_2 (symmetric) position for axis 5
			*axis_5_pos = this->xl320_pos_to_rad_pos(
					XL320_MIDDLE_POSITION * 2 - this->m5_2.getPositionState());
		}
		*axis_6_pos = this->xl320_pos_to_rad_pos(this->m6.getPositionState());
	}
}

void DxlCommunication::getCurrentPositionV2(
		double *axis_4_pos, double *axis_5_pos, double *axis_6_pos) {
	if (this->hardware_version == 2) {
		*axis_4_pos = this->xl430_pos_to_rad_pos(this->m4.getPositionState());
		*axis_5_pos = this->xl320_pos_to_rad_pos(
				XL430_MIDDLE_POSITION * 2 - this->m5.getPositionState());
		*axis_6_pos = this->xl320_pos_to_rad_pos(this->m6.getPositionState());
	}
}

void DxlCommunication::getHardwareStatus(bool *is_connection_ok,
		std::string &error_message, int *calibration_needed,
		bool *calibration_in_progress, std::vector<std::string> &motor_names,
		std::vector<std::string> &motor_types,
		std::vector<int32_t> &temperatures, std::vector<double> &voltages,
		std::vector<int32_t> &hw_errors) {
	*(is_connection_ok) = this->is_dxl_connection_ok;
	*(calibration_needed) = 0;  // No need for calibrating dxl motors
	*(calibration_in_progress) = false;  // No need for calibrating dxl motors
	error_message = this->debug_error_message;

	motor_names.clear();
	motor_types.clear();
	temperatures.clear();
	voltages.clear();
	hw_errors.clear();

	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			motor_names.push_back(this->motors.at(i)->getName());
			if (this->motors.at(i)->getType() == MOTOR_TYPE_XL320) {
				motor_types.push_back("DXL XL-320");
			} else if (this->motors.at(i)->getType() == MOTOR_TYPE_XL430) {
				motor_types.push_back("DXL XL-430");
			}
			temperatures.push_back(this->motors.at(i)->getTemperatureState());
			voltages.push_back(this->motors.at(i)->getVoltageState() / 10.0);
			hw_errors.push_back(this->motors.at(i)->getHardwareErrorState());
		}
	}

	if (this->is_tool_connected) {
		motor_names.push_back(this->tool.getName());
		motor_types.push_back("DXL XL-320");
		temperatures.push_back(this->tool.getTemperatureState());
		voltages.push_back(this->tool.getVoltageState() / 10.0);
		hw_errors.push_back(this->tool.getHardwareErrorState());
	}
}

bool DxlCommunication::isConnectionOk() {
	return is_dxl_connection_ok;
}

void DxlCommunication::setTorqueOn(bool on) {
	if (this->hw_limited_mode) {
		// Only allow to activate torque if limited_mode is OFF
		torque_on = false;
		write_torque_on_enable = true;
	} else {
		torque_on = on;
		write_torque_on_enable = true;
	}
}

void DxlCommunication::setLeds(std::vector<int> &leds) {
	if (leds.size() < this->motors.size() + 1) {
		RCLCPP_WARN(this->get_logger(), "Led array must contain %d values",
				(int) this->motors.size() + 1);
		return;
	}

	int index_counter = 0;

	for (int i = 0; i < this->motors.size(); i++) {
		if (this->motors.at(i)->isEnabled()) {
			if (leds.at(index_counter) >= 0 && leds.at(index_counter) <= 7) {
				this->motors.at(i)->setLedCommand(leds.at(index_counter));
			}
			index_counter++;
		}
	}

	if (leds.at(index_counter) >= 0 && leds.at(index_counter) <= 7) {
		this->tool.setLedCommand(leds.at(index_counter));
	}

	write_led_enable = true;
}

void DxlCommunication::setTool(uint8_t id, std::string name) {
	this->is_tool_connected = (id > 0);
	this->tool.setId(id);  // id "0" means no tool
	this->tool.setName(name);
	this->tool.resetState();
	this->tool.resetCommand();

	RCLCPP_INFO(this->get_logger(), "Set tool with id : %d", tool.getId());
}

int DxlCommunication::pingAndSetTool(uint8_t id, std::string name) {
	if (id == 0) {
		// Detach tool
		setTool(0, "No Dxl Tool");
		return TOOL_STATE_PING_OK;
	}

	while (this->hw_is_busy) {
		rclcpp::sleep_for(std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
	}
	this->hw_is_busy = true;

	int retries = 3;
	int ping_result = COMM_RX_FAIL;

	while (retries > 0) {
		ping_result = this->xl320->ping(id);
		if (ping_result == COMM_SUCCESS) {
			retries = 0;
		} else {
			retries--;
		}
	}

	RCLCPP_INFO(this->get_logger(), "Ping Tool : ping result for id (%d) : %d",
			id, ping_result);

	this->hw_is_busy = false;

	if (ping_result != COMM_SUCCESS) {
		RCLCPP_WARN(this->get_logger(), "Could not find tool with id: %d", id);
		this->setTool(0, "No Dxl Tool");  // No tool detected
		return TOOL_STATE_PING_ERROR;
	}

	this->setTool(
			id, name);  // if ping successful, we update current attached tool
	return TOOL_STATE_PING_OK;
}

/*
 * This method should be called in a different thread than control loop
 */
int DxlCommunication::openGripper(uint8_t id, uint16_t open_position,
		uint16_t open_speed, uint16_t open_hold_torque) {
	// check gripper id, in case no ping has been done before, or wrong id given
	if (id != this->tool.getId()) {
		return TOOL_STATE_WRONG_ID;
	}

	// set gripper pos, vel and torque
	this->tool.setVelocityCommand(open_speed);
	this->tool.setPositionCommand(open_position);
	this->tool.setTorqueCommand(1023);
	this->write_tool_enable = true;

	// Calculate open duration
	int dxl_speed = open_speed * XL320_STEPS_FOR_1_SPEED;  // Position . sec-1
	int dxl_steps_to_do = abs((int) open_position -
			(int) this->tool.getPositionState());  // Position
	double seconds_to_wait =
			(double) dxl_steps_to_do / (double) dxl_speed;  // Sec

	rclcpp::sleep_for(
			std::chrono::milliseconds((int) ((seconds_to_wait + 0.25) * 1000)));

	// Set hold torque
	this->tool.setTorqueCommand(open_hold_torque);
	this->write_tool_enable = true;

	return GRIPPER_STATE_OPEN;
}

/*
 * Close position must be lower than open position (from mechanical design)
 * This method should be called in a different thread than control loop
 */
int DxlCommunication::closeGripper(uint8_t id, uint16_t close_position,
		uint16_t close_speed, uint16_t close_hold_torque,
		uint16_t close_max_torque) {
	// Check gripper id, in case no ping has been done before, or wrong id given
	if (id != this->tool.getId()) {
		return TOOL_STATE_WRONG_ID;
	}

	int position_command = (close_position < 50) ? 0 : close_position - 50;

	// Set gripper pos, vel and torque
	this->tool.setVelocityCommand(close_speed);
	this->tool.setPositionCommand(position_command);
	this->tool.setTorqueCommand(close_max_torque);
	this->write_tool_enable = true;

	// Calculate close duration
	int dxl_speed = close_speed * XL320_STEPS_FOR_1_SPEED;  // Position . sec-1
	int dxl_steps_to_do = abs((int) close_position -
			(int) this->tool.getPositionState());  // Position
	double seconds_to_wait =
			(double) dxl_steps_to_do / (double) dxl_speed;  // Sec

	rclcpp::sleep_for(
			std::chrono::milliseconds((int) ((seconds_to_wait + 0.25) * 1000)));

	// Set hold torque and position
	this->tool.setTorqueCommand(close_hold_torque);
	this->tool.setPositionCommand(close_position);
	this->write_tool_enable = true;

	return GRIPPER_STATE_CLOSE;
}

/*
 * This method should be called in a different thread than control loop
 */
int DxlCommunication::pullAirVacuumPump(
		uint8_t id, uint16_t pull_air_position, uint16_t pull_air_hold_torque) {
	// check gripper id, in case no ping has been done before, or wrong id given
	if (id != this->tool.getId()) {
		return TOOL_STATE_WRONG_ID;
	}

	int pull_air_velocity = 1023;

	// Set vacuum pump pos, vel and torque
	this->tool.setVelocityCommand(pull_air_velocity);
	this->tool.setPositionCommand(pull_air_position);
	this->tool.setTorqueCommand(1023);
	this->write_tool_enable = true;

	// Calculate pull air duration
	int dxl_speed =
			pull_air_velocity * XL320_STEPS_FOR_1_SPEED;  // Position . sec-1
	int dxl_steps_to_do = abs((int) pull_air_position -
			(int) this->tool.getPositionState());  // Position
	double seconds_to_wait =
			(double) dxl_steps_to_do / (double) dxl_speed;  // Sec

	rclcpp::sleep_for(
			std::chrono::milliseconds((int) ((seconds_to_wait + 0.25) * 1000)));

	// Set hold torque
	this->tool.setTorqueCommand(pull_air_hold_torque);
	this->write_tool_enable = true;

	return VACUUM_PUMP_STATE_PULLED;
}

/*
 * This method should be called in a different thread than control loop
 */
int DxlCommunication::pushAirVacuumPump(
		uint8_t id, uint16_t push_air_position) {
	// Check gripper id, in case no ping has been done before, or wrong id given
	if (id != this->tool.getId()) {
		return TOOL_STATE_WRONG_ID;
	}

	int push_air_velocity = 1023;

	// Set vacuum pump pos, vel and torque
	this->tool.setVelocityCommand(push_air_velocity);
	this->tool.setPositionCommand(push_air_position);
	this->tool.setTorqueCommand(1023);
	this->write_tool_enable = true;

	// Calculate push air duration
	int dxl_speed =
			push_air_velocity * XL320_STEPS_FOR_1_SPEED;  // Position . sec-1
	int dxl_steps_to_do = abs((int) push_air_position -
			(int) this->tool.getPositionState());  // Position
	double seconds_to_wait =
			(double) dxl_steps_to_do / (double) dxl_speed;  // Sec

	rclcpp::sleep_for(
			std::chrono::milliseconds((int) ((seconds_to_wait + 0.25) * 1000)));

	// Set torque to 0
	this->tool.setTorqueCommand(0);
	this->write_tool_enable = true;

	return VACUUM_PUMP_STATE_PUSHED;
}

int DxlCommunication::scanAndCheck() {
	int counter = 0;

	while (hw_is_busy && counter < 100) {
		rclcpp::sleep_for(std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
		counter++;
	}

	if (counter == 100) {
		this->debug_error_message = "Failed to scan motors, Dynamixel bus is "
									"too busy. Will retry...";
		RCLCPP_WARN(this->get_logger(),
				"Failed to scan motors, dxl bus is too busy (counter max : "
				"%d). Will retry...",
				counter);
		return COMM_PORT_BUSY;
	}

	this->hw_is_busy = true;

	// 1. Get all ids from dxl bus
	std::vector<uint8_t> id_list;
	int result = xl320->scan(id_list);
	this->hw_is_busy = false;

	if (result != COMM_SUCCESS) {
		if (result == COMM_RX_TIMEOUT) {  // -3001
			this->debug_error_message =
					"No Dynamixel motor found. Make sure that motors are "
					"correctly connected and powered on.";
		} else {  // -3002 or other
			this->debug_error_message = "Failed to scan Dynamixel bus.";
		}
		RCLCPP_WARN(this->get_logger(),
				"Broadcast ping failed, result : %d (-3001: timeout, -3002: "
				"corrupted packet)",
				result);
		return result;
	}

	// 1.1 Log all IDs found for debug purposes
	RCLCPP_INFO(this->get_logger(), "Dynamixel broadcast ping - Found IDs:");
	for (int i = 0; i < id_list.size(); i++) {
		RCLCPP_INFO(this->get_logger(), "- %d", id_list.at(i));
	}

	// 2. Check that ids correspond to niryo_one motors id list
	std::vector<uint8_t> missing_motor_ids;

	for (int i = 0; i < this->required_motors_ids.size(); i++) {
		if (std::find(id_list.begin(), id_list.end(),
					this->required_motors_ids.at(i)) == id_list.end()) {
			missing_motor_ids.push_back(this->required_motors_ids.at(i));
		}
	}

	if (this->is_tool_connected) {
		if (std::find(id_list.begin(), id_list.end(), tool.getId()) ==
				id_list.end()) {
			missing_motor_ids.push_back(tool.getId());
		}
	}

	if (missing_motor_ids.size() > 0) {
		this->debug_error_message =
				"Missing Dynamixel motor(s) on the robot : ";
		for (int i = 0; i < this->motors.size(); i++) {
			if (std::find(missing_motor_ids.begin(), missing_motor_ids.end(),
						this->motors.at(i)->getId()) !=
					missing_motor_ids.end()) {
				this->debug_error_message += this->motors.at(i)->getName();
				this->debug_error_message += ", ";
			}
		}

		if (std::find(missing_motor_ids.begin(), missing_motor_ids.end(),
					this->tool.getId()) != missing_motor_ids.end()) {
			this->debug_error_message += this->tool.getName();
		}

		RCLCPP_ERROR(
				this->get_logger(), "%s", this->debug_error_message.c_str());
		return DXL_SCAN_MISSING_MOTOR;
	}

	// 3. Check that there is no unwanted motor
	std::vector<uint8_t> unallowed_motor_ids;

	for (int i = 0; i < id_list.size(); i++) {
		if (std::find(this->allowed_motors_ids.begin(),
					this->allowed_motors_ids.end(),
					id_list.at(i)) == this->allowed_motors_ids.end()) {
			unallowed_motor_ids.push_back(id_list.at(i));
		}
	}

	if (unallowed_motor_ids.size() > 0) {
		this->debug_error_message =
				"Unallowed Dynamixel motor(s) on the robot : ";
		for (int i = 0; i < unallowed_motor_ids.size(); i++) {
			this->debug_error_message +=
					std::to_string(unallowed_motor_ids.at(i));
			if (i != unallowed_motor_ids.size() - 1) {
				this->debug_error_message += ", ";
			}
		}
		RCLCPP_ERROR(
				this->get_logger(), "%s", this->debug_error_message.c_str());
		return DXL_SCAN_UNALLOWED_MOTOR;
	}

	this->is_dxl_connection_ok = true;
	this->debug_error_message = "";
	return DXL_SCAN_OK;
}

int DxlCommunication::detectVersion() {
	int counter = 0;

	while (this->hw_is_busy && counter < 100) {
		rclcpp::sleep_for(std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
		counter++;
	}

	if (counter == 100) {
		this->debug_error_message = "Failed to scan motors, Dynamixel bus is "
									"too busy. Will retry...";
		RCLCPP_WARN(this->get_logger(),
				"Failed to scan motors, dxl bus is too busy (counter max : %d)",
				counter);
		return -1;
	}

	this->hw_is_busy = true;

	// 1. Get all ids from dxl bus
	std::vector<uint8_t> id_list;
	int result = xl320->scan(id_list);
	this->hw_is_busy = false;

	if (result != COMM_SUCCESS) {
		if (result == COMM_RX_TIMEOUT) {  // -3001
			this->debug_error_message =
					"No Dynamixel motor found. Make sure that motors are "
					"correctly connected and powered on.";
		} else {  // -3002 or other
			this->debug_error_message = "Failed to scan Dynamixel bus.";
		}
		RCLCPP_WARN(this->get_logger(),
				"Broadcast ping failed , result : %d (-3001: timeout, -3002: "
				"corrupted packet)",
				result);
		return -1;
	}

	// 1.1 Log all IDs found for debug purposes
	RCLCPP_INFO(this->get_logger(), "Dynamixel broadcast ping - Found IDs:");
	for (int i = 0; i < id_list.size(); i++) {
		RCLCPP_INFO(this->get_logger(), "- %d", id_list.at(i));
	}

	// Check if motor (MOTOR_4, Model : XL-430) is connected --> V2
	if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_4_ID) !=
			id_list.end()) {
		// Found the motor in the list, now check if model number matches XL-430 motors
		if (this->xl430->checkModelNumber(DXL_MOTOR_4_ID) == 0) {
			// We are now sure MOTOR_4 is connected and it is a XL-430 motor
			return 2;  // --> version 2
		}
	}

	// Check if motor (MOTOR_5, Model : XL-430) is connected --> V2
	if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_5_ID) !=
			id_list.end()) {
		// found the motor in the list, now check if model number matches XL-430 motors
		if (this->xl430->checkModelNumber(DXL_MOTOR_5_ID) == 0) {
			// we are now sure MOTOR_5 is connected and it is a XL-430 motor
			return 2;  // --> version 2
		}
	}

	// Check if motor (MOTOR_5_1, Model : XL-320) is connected --> V1
	if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_5_1_ID) !=
			id_list.end()) {
		// found the motor in the list, now check if model number matches XL-320 motors
		if (this->xl320->checkModelNumber(DXL_MOTOR_5_1_ID) == 0) {
			// we are now sure MOTOR_5_1 is connected and it is a XL-320 motor
			return 1;  // --> version 1
		}
	}

	// Check if motor (MOTOR_5_2, Model : XL-320) is connected --> V1
	if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_5_2_ID) !=
			id_list.end()) {
		// found the motor in the list, now check if model number matches XL-320 motors
		if (this->xl320->checkModelNumber(DXL_MOTOR_5_2_ID) == 0) {
			// we are now sure MOTOR_5_2 is connected and it is a XL-320 motor
			return 1;  // --> version 1
		}
	}

	// if no motor from V1 or V2 has been found, it means some motors have been disabled
	// for debug purposes, and we can't know (from hardware) which version we have.
	return 0;
}
