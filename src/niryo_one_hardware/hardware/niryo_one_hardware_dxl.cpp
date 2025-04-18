#include "niryo_one_hardware/niryo_one_hardware_dxl.hpp"
#include "niryo_one_hardware/utilities.hpp"

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

namespace niryo_one_hardware {
	CallbackReturn NiryoOneHardwareDxl::on_init(
			const hardware_interface::HardwareInfo &info) {
		if (hardware_interface::SystemInterface::on_init(info) !=
				CallbackReturn::SUCCESS) {
			return CallbackReturn::ERROR;
		}

		// Get hardware parameters
		RCLCPP_INFO(get_logger(), "Getting DXL hardware parameters");
		hardware_version = stoi(info_.hardware_parameters["hardware_version"]);

		if (hardware_version != 1 && hardware_version != 2) {
			RCLCPP_ERROR(get_logger(),
					"Incorrect hardware version, should be 1 or 2");
			return CallbackReturn::ERROR;
		}

		use_sim = stob(info_.hardware_parameters["use_sim"]);
		RCLCPP_INFO(get_logger(), "Using sim: %d", use_sim);
		device_name = info_.hardware_parameters["dxl_uart_device_name"];
		uart_baudrate = stoi(info_.hardware_parameters["dxl_baudrate"]);

		dxl_enabled = stob(info_.hardware_parameters["dxl_enabled"]);
		niryo_one_hw_check_connection_frequency = stod(info_.hardware_parameters
						["niryo_one_hw_check_connection_frequency"]);
		hw_control_loop_frequency = stod(info_.hardware_parameters
						["dxl_hardware_control_loop_frequency"]);
		hw_data_write_frequency =
				stod(info_.hardware_parameters["dxl_hw_write_frequency"]);
		hw_data_read_frequency =
				stod(info_.hardware_parameters["dxl_hw_data_read_frequency"]);
		hw_status_read_frequency =
				stod(info_.hardware_parameters["dxl_hw_status_read_frequency"]);

		dxlPortHandler =
				dynamixel::PortHandler::getPortHandler(device_name.c_str());
		dxlPacketHandler = dynamixel::PacketHandler::getPacketHandler(
				DXL_BUS_PROTOCOL_VERSION);

		xl320.reset(new XL320Driver(dxlPortHandler, dxlPacketHandler));
		xl430.reset(new XL430Driver(dxlPortHandler, dxlPacketHandler));

		is_dxl_connection_ok = false;

		is_tool_connected = true;

		torque_on = 0;
		should_reboot_motors = false;

		// For hardware loop control
		hw_is_busy = false;
		hw_limited_mode = true;

		read_position_enable = true;
		read_velocity_enable = true;  // Not useful for now
		read_torque_enable = true;
		read_hw_status_enable = true;

		// Change these values according to the current loaded controller (position, velocity, or torque control)
		setControlMode(DXL_CONTROL_MODE_POSITION);
		write_led_enable = false;
		write_torque_on_enable = true;
		write_tool_enable = false;

		factory_reset_motor_id = -1;

		return CallbackReturn::SUCCESS;
	}

	std::vector<hardware_interface::InterfaceDescription> NiryoOneHardwareDxl::
			export_unlisted_command_interface_descriptions() {
		std::vector<hardware_interface::InterfaceDescription> interfaces;

		for (std::map<CommandInterfaces, std::string>::iterator iter =
						command_interface_names.begin();
				iter != command_interface_names.end(); ++iter) {
			hardware_interface::InterfaceInfo info;
			info.name = iter->second;
			hardware_interface::InterfaceDescription desc =
					hardware_interface::InterfaceDescription(
							"niryo_one/dxl", info);
			interfaces.push_back(desc);
		}

		return interfaces;
	}

	CallbackReturn NiryoOneHardwareDxl::on_configure(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Configuring DXL hardware... please wait...");

		if (!use_sim) {
			// Setup half-duplex direction GPIO
			// See schema http://support.robotis.com/en/product/actuator/dynamixel_x/xl-series_main.htm
			if (!dxlPortHandler->setupGpio()) {
				RCLCPP_ERROR(get_logger(),
						"Failed to setup direction GPIO port for Dynamixel "
						"bus");
				return CallbackReturn::ERROR;
			}

			// Open port
			if (!dxlPortHandler->openPort()) {
				RCLCPP_ERROR(get_logger(),
						"Failed to open UART port for Dynamixel bus");
				return CallbackReturn::ERROR;
			}

			// Set baudrate
			if (!dxlPortHandler->setBaudRate(uart_baudrate)) {
				RCLCPP_ERROR(get_logger(),
						"Failed to set baudrate for Dynamixel bus");
				return CallbackReturn::ERROR;
			}
		}

		async_thread_ = std::make_shared<std::thread>(
				&NiryoOneHardwareDxl::asyncThread, this);

		RCLCPP_INFO(get_logger(), "Successfully configured DXL hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareDxl::on_cleanup(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Cleaning up DXL hardware... please wait...");

		if (async_thread_) {
			async_thread_shutdown_ = true;
			async_thread_->join();
			async_thread_.reset();
		}

		RCLCPP_INFO(get_logger(), "Successfully cleaned up DXL hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareDxl::on_activate(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Activating DXL hardware... please wait...");

		for (auto joint : info_.joints) {
			RCLCPP_INFO(get_logger(), "Joint Name:  %s", joint.name.c_str());
			set_command(joint.name + "/" + hardware_interface::HW_IF_POSITION,
					stod(joint.parameters["home_position"]));
			set_command(
					joint.name + "/" + hardware_interface::HW_IF_VELOCITY, 0);
			set_command(joint.name + "/" + hardware_interface::HW_IF_TORQUE, 0);
			set_command(joint.name + "/led", 0);

			set_state(joint.name + "/" + hardware_interface::HW_IF_POSITION,
					stod(joint.parameters["home_position"]));
			set_state(joint.name + "/" + hardware_interface::HW_IF_VELOCITY, 0);
			set_state(joint.name + "/" + hardware_interface::HW_IF_TORQUE, 0);
			set_state(joint.name + "/" + hardware_interface::HW_IF_TEMPERATURE,
					0);
			set_state(joint.name + "/voltage", 0);
			set_state(joint.name + "/hw_error", 0);
			set_state(joint.name + "/enabled", true);
		}

		dxl_connection_loop_thread.reset(new std::thread(
				std::bind(&NiryoOneHardwareDxl::manageDxlConnection, this)));

		RCLCPP_INFO(get_logger(), "Successfully activated DXL hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareDxl::on_deactivate(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(
				get_logger(), "Deactivating DXL hardware... please wait...");

		RCLCPP_INFO(get_logger(), "Successfully deactivated DXL hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareDxl::on_shutdown(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(
				get_logger(), "Shutting down DXL hardware... please wait...");

		RCLCPP_INFO(get_logger(), "Successfully shutdown DXL hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareDxl::on_error(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(
				get_logger(), "Handling error DXL hardware... please wait...");

		RCLCPP_INFO(get_logger(), "Successfully handled error DXL hardwaare!");

		return CallbackReturn::SUCCESS;
	}

	return_type NiryoOneHardwareDxl::read(
			const rclcpp::Time &time, const rclcpp::Duration &period) {
		return return_type::OK;
	}

	return_type NiryoOneHardwareDxl::write(
			const rclcpp::Time &time, const rclcpp::Duration &period) {
		return return_type::OK;
	}

	void NiryoOneHardwareDxl::manageDxlConnection() {
		if (!dxl_enabled) {
			return;
		}

		checkHardwareVersionFromDxlMotors();

		rclcpp::Rate check_connection_rate =
				rclcpp::Rate(niryo_one_hw_check_connection_frequency);

		while (rclcpp::ok()) {
			if (!is_dxl_connection_ok) {
				RCLCPP_WARN(get_logger(), "Stop DXL HW control");
				stopHardwareControlLoop();
				std::this_thread::sleep_for(std::chrono::milliseconds(100));

				while (scanAndCheck() != DXL_SCAN_OK) {
					// Wait for connection to be up
					RCLCPP_WARN(get_logger(), "Scan to find DXL motors");
					std::this_thread::sleep_for(std::chrono::milliseconds(250));
				}

				RCLCPP_WARN(get_logger(), "Resume DXL HW control");
				setTorqueOn(false);
				activateLearningMode(true);
				startHardwareControlLoop(false);
			} else {
				// DXL connection OK
				if (hw_limited_mode) {
					setTorqueOn(false);
					startHardwareControlLoop(false);
				}
			}

			check_connection_rate.sleep();
		}
	}

	void NiryoOneHardwareDxl::checkHardwareVersionFromDxlMotors() {
		/*
		 * Check if hardware_version is compatible.
		 * The purpose here is retro-compatibility with version 1.
		 * Version 2 is the default.
		 * If the robot is still V1 (old version) we can detect it from
		 * Dynamixel motors setup, and automatically change the version
		 * used without any user input
		 */
		int detected_version = detectVersion();
		while (detected_version < 0) {
			RCLCPP_WARN(get_logger(),
					"Scan to find DXL motors + check hardware version");
			detected_version = detectVersion();
			std::this_thread::sleep_for(std::chrono::milliseconds(250));
		}

		RCLCPP_INFO(get_logger(), "Detected version from hardware: %d",
				detected_version);

		if (detected_version == 0) {
			// Version could not be detected from current hardware setup
			// It seems that some motors have been disabled for debug purposes
			// --> Continue like nothing happened
		} else if ((detected_version != hardware_version)) {
			// Change version (V1->V2 or V2->V1) and reboot
			change_hardware_version_and_reboot(
					hardware_version, detected_version);
		}
	}

	int NiryoOneHardwareDxl::detectVersion() {
		int counter = 0;

		while (hw_is_busy && counter < 100) {
			std::this_thread::sleep_for(
					std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
			counter++;
		}

		if (counter == 100) {
			RCLCPP_WARN(get_logger(),
					"Failed to scan motors, DXL bus is too busy (counter max: "
					"%d)",
					counter);
			return -1;
		}

		hw_is_busy = true;

		// 1. Get all IDs from DXL bus
		std::vector<uint8_t> id_list;
		int result = xl320->scan(id_list);
		hw_is_busy = false;

		if (result != COMM_SUCCESS) {
			if (result == COMM_RX_TIMEOUT) {
				RCLCPP_INFO(get_logger(),
						"No Dynamixel motor found. Make sure that motors are "
						"correctly connected and powered on.");
			} else {
				RCLCPP_INFO(get_logger(), "Failed to scan Dynamixel bus.");
			}
			RCLCPP_WARN(get_logger(),
					"Broadcast ping failed, result: %d (-3001: timeout, "
					"-3002: corrupted packet)",
					result);
			return -1;
		}

		// 1.1 Log all IDs found for debug purposes
		RCLCPP_INFO(get_logger(), "Dynamixel broadcast ping - Found IDs:");
		for (std::size_t i = 0; i < id_list.size(); i++) {
			RCLCPP_INFO(get_logger(), "- %d", id_list.at(i));
		}

		// Check if motor (MOTOR_4, Model: XL-430) is connected --> V2
		if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_4_ID) !=
				id_list.end()) {
			// Found the motor in the list, now check if model number matches XL-430 motors
			if (xl430->checkModelNumber(DXL_MOTOR_4_ID) == 0) {
				// We are now sure MOTOR_4 is connected an it is a XL-430 motor
				return 2;  // version 2
			}
		}

		// Check if motor (MOTOR_5, Model: XL-430) is connected --> V2
		if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_5_ID) !=
				id_list.end()) {
			// Found the motor in the list, now check if model number matches XL-430 motors
			if (xl430->checkModelNumber(DXL_MOTOR_5_ID) == 0) {
				// We are now sure MOTOR_5 is connected and it is a XL430 motor
				return 2;  // version 2
			}
		}

		// Check if motor (MOTOR_5_1, Model: XL-320) is connected --> V1
		if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_5_1_ID) !=
				id_list.end()) {
			// Found the motor in the list, now check if model number matches XL-320 motors
			if (xl320->checkModelNumber(DXL_MOTOR_5_1_ID) == 0) {
				// We are now sure MOTOR5_1 is connected and it is a XL-320 motor
				return 1;  // version 1
			}
		}

		// Check if motor (MOTOR_5_2, Model: XL-320) is connected --> V1
		if (std::find(id_list.begin(), id_list.end(), DXL_MOTOR_5_2_ID) !=
				id_list.end()) {
			// Found the motor in the list, now check if model number matches XL-320 motors
			if (xl320->checkModelNumber(DXL_MOTOR_5_2_ID) == 0) {
				// We are now sure MOTOR5_1 is connected and it is a XL-320 motor
				return 1;  // version 1
			}
		}

		// If no motor from V1 or V2 has been found, it means some motors have
		// disabled for debug purposes, and we can't know (from hardware) which
		// version we have.
		return 0;
	}

	void NiryoOneHardwareDxl::stopHardwareControlLoop() {
		for (auto joint : info_.joints) {
			set_state(joint.name + "/" + hardware_interface::HW_IF_POSITION,
					stod(joint.parameters["home_position"]));
			set_state(joint.name + "/" + hardware_interface::HW_IF_VELOCITY, 0);
			set_state(joint.name + "/" + hardware_interface::HW_IF_TORQUE, 0);
			set_state(joint.name + "/" + hardware_interface::HW_IF_TEMPERATURE,
					0);
			set_state(joint.name + "/voltage", 0);
			set_state(joint.name + "/hw_error", 0);
			set_state(joint.name + "/enabled", true);
		}
		hw_control_loop_keep_alive = false;
	}

	int NiryoOneHardwareDxl::scanAndCheck() {
		int counter = 0;

		while (hw_is_busy && counter < 100) {
			std::this_thread::sleep_for(
					std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
			counter++;
		}

		if (counter == 100) {
			RCLCPP_WARN(get_logger(),
					"Failed to scan motors, DXL bus is too busy (counter max: "
					"%d). Will retry..",
					counter);
			return COMM_PORT_BUSY;
		}

		hw_is_busy = true;

		// 1. Get all IDs from DXL bus
		std::vector<uint8_t> id_list;
		int result = xl320->scan(id_list);
		hw_is_busy = false;

		if (result != COMM_SUCCESS) {
			if (result == COMM_RX_TIMEOUT) {
				RCLCPP_INFO(get_logger(),
						"No Dynamixel motor found. Make sure that motors are "
						"correctly connected and powered on.");
			} else {
				RCLCPP_INFO(get_logger(), "Failed to scan Dynamixel bus.");
			}
			RCLCPP_WARN(get_logger(),
					"Boradcast ping failed, result: %d (-3001: timeout, -3002: "
					"corrupted packet)",
					result);
			return result;
		}

		// 1.1 Log all IDs found for debug purposes
		RCLCPP_INFO(get_logger(), "Dynamixel broadcast ping - Found IDs:");
		for (std::size_t i = 0; i < id_list.size(); i++) {
			RCLCPP_INFO(get_logger(), "- %d", id_list.at(i));
		}

		// 2. Check that IDs correspond to niryo_one motors ID list
		std::vector<uint8_t> missing_motor_ids;

		for (auto joint : info_.joints) {
			if (std::find(id_list.begin(), id_list.end(),
						stoi(joint.parameters["id"])) == id_list.end()) {
				if (stoi(joint.parameters["id"]) != 0) {
					missing_motor_ids.push_back(stoi(joint.parameters["id"]));
				}
			}
		}

		if (missing_motor_ids.size() > 0) {
			std::string debug_message =
					"Missing Dynamixel motor(s) on the robot: ";
			for (auto joint : info_.joints) {
				if (std::find(missing_motor_ids.begin(),
							missing_motor_ids.end(),
							stoi(joint.parameters["id"])) !=
						missing_motor_ids.end()) {
					debug_message += joint.parameters["name"] + ", ";
				}
			}

			RCLCPP_INFO(get_logger(), debug_message.c_str());
			return DXL_SCAN_MISSING_MOTOR;
		}

		// 3. Cheeck that there is no unwanted motor
		std::vector<uint8_t> unallowed_motor_ids;
		for (auto joint : info_.joints) {
			allowed_motors_ids.push_back(stoi(joint.parameters["id"]));
		}

		for (std::size_t i = 0; i < id_list.size(); i++) {
			if (std::find(allowed_motors_ids.begin(), allowed_motors_ids.end(),
						id_list.at(i)) == allowed_motors_ids.end()) {
				unallowed_motor_ids.push_back(id_list.at(i));
			}
		}

		if (unallowed_motor_ids.size() > 0) {
			std::string debug_message =
					"Unallowed Dynamixel motor(s) on the robot: ";
			for (std::size_t i = 0; i < unallowed_motor_ids.size(); i++) {
				debug_message += std::to_string(unallowed_motor_ids.at(i));
				if (i != unallowed_motor_ids.size() - 1) {
					debug_message += ", ";
				}
			}
			RCLCPP_ERROR(get_logger(), debug_message.c_str());
			return DXL_SCAN_UNALLOWED_MOTOR;
		}

		is_dxl_connection_ok = true;
		return DXL_SCAN_OK;
	}

	void NiryoOneHardwareDxl::setTorqueOn(bool on) {
		if (hw_limited_mode) {
			// Only allowed to actiate torque if limited_mode is OFF
			torque_on = false;
			write_torque_on_enable = true;
		} else {
			torque_on = on;
			write_torque_on_enable = true;
		}
	}

	void NiryoOneHardwareDxl::activateLearningMode(bool activate) {
		setTorqueOn(!activate);
	}

	void NiryoOneHardwareDxl::startHardwareControlLoop(bool limited_mode) {
		RCLCPP_INFO(get_logger(), "DXL: Start hardware control loop");
		xl320_hw_fail_counter_read = 0;
		xl430_hw_fail_counter_read = 0;
		write_led_enable = false;
		write_torque_on_enable = true;
		resetHardwareControlLoopRates();
		hw_control_loop_keep_alive = true;

		// Depends on limited_mode flag
		write_position_enable != limited_mode;
		hw_limited_mode = limited_mode;
	}

	void NiryoOneHardwareDxl::resetHardwareControlLoopRates() {
		double now = get_clock()->now().seconds();
		time_hw_data_last_write = now;
		time_hw_data_last_read = now;
		time_hw_status_last_read = now;
	}

	uint32_t NiryoOneHardwareDxl::rad_pos_to_xl320_pos(double position_rad) {
		return (uint32_t) ((double) XL320_MIDDLE_POSITION +
				(position_rad * RADIAN_TO_DEGREE *
						(double) XL320_TOTAL_RANGE_POSITION) /
						(double) XL320_TOTAL_ANGLE);
	}

	double NiryoOneHardwareDxl::xl320_pos_to_rad_pos(uint32_t position_dxl) {
		return (double) ((((double) position_dxl - XL320_MIDDLE_POSITION) *
								 (double) XL320_TOTAL_ANGLE) /
				(RADIAN_TO_DEGREE * (double) XL320_TOTAL_RANGE_POSITION));
	}

	uint32_t NiryoOneHardwareDxl::rad_pos_to_xl430_pos(double position_rad) {
		return (uint32_t) ((double) XL430_MIDDLE_POSITION +
				(position_rad * RADIAN_TO_DEGREE *
						(double) XL430_TOTAL_RANGE_POSITION) /
						(double) XL430_TOTAL_ANGLE);
	}

	double NiryoOneHardwareDxl::xl430_pos_to_rad_pos(uint32_t position_dxl) {
		return (double) ((((double) position_dxl - XL430_MIDDLE_POSITION) *
								 (double) XL430_TOTAL_ANGLE) /
				(RADIAN_TO_DEGREE * (double) XL430_TOTAL_RANGE_POSITION));
	}

	void NiryoOneHardwareDxl::asyncThread() {
		async_thread_shutdown_ = false;
		while (!async_thread_shutdown_) {
			activateLearningMode();
			rebootMotors();
			factoryResetMotor();
			std::this_thread::sleep_for(std::chrono::nanoseconds(20000000));
		}
	}

	void NiryoOneHardwareDxl::activateLearningMode() {
		int32_t status =
				unlisted_commands_
						.at(CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS)
						->get_optional<double>()
						.value_or(ASYNC_NONE);

		if (status == ASYNC_WAITING) {
			bool learning_mode_on;
			learning_mode_on =
					unlisted_commands_
							.at(CommandInterfaces::
											ACTIVATE_LEARNING_MODE_REQUEST_VALUE)
							->get_optional<double>()
							.value();

			RCLCPP_INFO(get_logger(), "Activating Learning Mode - DXL: %d",
					learning_mode_on);
			activateLearningMode(learning_mode_on);

			// Publish one time
			std::ignore =
					unlisted_commands_
							.at(CommandInterfaces::
											ACTIVATE_LEARNING_MODE_RESPONSE_STATUS)
							->set_value(200);
		}
	}

	void NiryoOneHardwareDxl::rebootMotors() {
		int32_t status =
				unlisted_commands_
						.at(CommandInterfaces::REBOOT_MOTORS_RESPONSE_STATUS)
						->get_optional<double>()
						.value_or(ASYNC_NONE);

		if (status == ASYNC_WAITING) {
			RCLCPP_INFO(get_logger(), "Rebooting motors");
			should_reboot_motors = true;

			std::ignore = unlisted_commands_
								  .at(CommandInterfaces::
												  REBOOT_MOTORS_RESPONSE_STATUS)
								  ->set_value(200);
		}
	}

	void NiryoOneHardwareDxl::factoryResetMotor() {
		int32_t status =
				unlisted_commands_
						.at(CommandInterfaces::
										FACTORY_RESET_MOTOR_RESPONSE_STATUS)
						->get_optional<double>()
						.value_or(ASYNC_NONE);

		if (status == ASYNC_WAITING) {
			uint8_t motor_id =
					unlisted_commands_
							.at(CommandInterfaces::
											FACTORY_RESET_MOTOR_REQUEST_VALUE)
							->get_optional<double>()
							.value();
			RCLCPP_INFO(get_logger(), "Factory resetting motor %d", motor_id);

			factory_reset_motor_id = motor_id;

			std::ignore =
					unlisted_commands_
							.at(CommandInterfaces::
											FACTORY_RESET_MOTOR_RESPONSE_STATUS)
							->set_value(200);
		}
	}

	void NiryoOneHardwareDxl::hardwareControlRead() {
		std::vector<uint8_t> xl320_id_list;
		std::vector<uint8_t> xl430_id_list;

		// Used to reduce redundant code after these arrays will
		// contain only enabled motors
		std::vector<hardware_interface::ComponentInfo> xl320_motor_list;
		std::vector<hardware_interface::ComponentInfo> xl430_motor_list;

		for (auto joint : info_.joints) {
			if (get_state(joint.name + "/enabled")) {
				if (stoi(joint.parameters["type"]) == MOTOR_TYPE_XL320) {
					if (stoi(joint.parameters["id"]) != 0) {
						xl320_id_list.push_back(stoi(joint.parameters["id"]));
						xl320_motor_list.push_back(joint);
					}
				} else if (stoi(joint.parameters["type"]) == MOTOR_TYPE_XL430) {
					xl430_id_list.push_back(stoi(joint.parameters["id"]));
					xl430_motor_list.push_back(joint);
				}
			}
		}

		bool can_read_xl320 = (xl320_motor_list.size() > 0);
		bool can_read_xl430 = (xl430_motor_list.size() > 0);

		if (!can_read_xl320 && !can_read_xl430) {
			return;  // No motor, nothing to read
		}

		// We now have all enabled motors separated in 2 categories
		// Read data
		if (get_clock()->now().seconds() - time_hw_data_last_read >
				1.0 / hw_data_read_frequency) {
			time_hw_data_last_read += 1.0 / hw_data_read_frequency;

			// Read position
			if (read_position_enable) {
				// Read from XL320 motors
				if (can_read_xl320) {
					std::vector<uint32_t> position_list;
					int read_position_result = xl320->syncReadPosition(
							xl320_id_list, position_list);
					if (read_position_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl320_motor_list.size();
								i++) {
							double rad_pos =
									xl320_pos_to_rad_pos(position_list.at(i));
							set_state(xl320_motor_list.at(i).name + "/" +
											hardware_interface::HW_IF_POSITION,
									rad_pos);
						}
					} else {
						xl320_hw_fail_counter_read++;
					}
				}

				// Read from XL430 motors
				if (can_read_xl430) {
					std::vector<uint32_t> position_list;
					int read_position_result = xl430->syncReadPosition(
							xl430_id_list, position_list);
					if (read_position_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl430_motor_list.size();
								i++) {
							double rad_pos =
									xl430_pos_to_rad_pos(position_list.at(i));
							set_state(xl430_motor_list.at(i).name + "/" +
											hardware_interface::HW_IF_POSITION,
									rad_pos);
						}
					} else {
						xl430_hw_fail_counter_read++;
					}
				}
			}

			// Read velocity
			if (read_velocity_enable) {
				// Read from XL320 motors
				if (can_read_xl320) {
					std::vector<uint32_t> velocity_list;
					int read_velocity_result = xl320->syncReadVelocity(
							xl320_id_list, velocity_list);
					if (read_velocity_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl320_motor_list.size();
								i++) {
							set_state(xl320_motor_list.at(i).name + "/" +
											hardware_interface::HW_IF_VELOCITY,
									velocity_list.at(i));
						}
					} else {
						xl320_hw_fail_counter_read++;
					}
				}

				// Read from XL430 motors
				if (can_read_xl430) {
					std::vector<uint32_t> velocity_list;
					int read_velocity_result = xl430->syncReadVelocity(
							xl430_id_list, velocity_list);
					if (read_velocity_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl430_motor_list.size();
								i++) {
							set_state(xl430_motor_list.at(i).name + "/" +
											hardware_interface::HW_IF_VELOCITY,
									velocity_list.at(i));
						}
					} else {
						xl430_hw_fail_counter_read++;
					}
				}
			}

			// Read Torque
			if (read_torque_enable) {
				// Read from XL320 motors
				if (can_read_xl320) {
					std::vector<uint32_t> torque_list;
					int read_torque_result =
							xl320->syncReadLoad(xl320_id_list, torque_list);
					if (read_torque_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl320_motor_list.size();
								i++) {
							set_state(xl320_motor_list.at(i).name + "/" +
											hardware_interface::HW_IF_TORQUE,
									torque_list.at(i));
						}
					} else {
						xl320_hw_fail_counter_read++;
					}
				}

				// Read from XL430 motors
				if (can_read_xl430) {
					std::vector<uint32_t> torque_list;
					int read_torque_result =
							xl430->syncReadLoad(xl430_id_list, torque_list);
					if (read_torque_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl430_motor_list.size();
								i++) {
							set_state(xl430_motor_list.at(i).name + "/" +
											hardware_interface::HW_IF_TORQUE,
									torque_list.at(i));
						}
					} else {
						xl430_hw_fail_counter_read++;
					}
				}
			}
		}

		// Read hardware status
		if (read_hw_status_enable) {
			if (get_clock()->now().seconds() - time_hw_status_last_read >
					1.0 / hw_status_read_frequency) {
				time_hw_status_last_read += 1.0 / hw_status_read_frequency;

				// Read temperature
				// Read from XL320 motors
				if (can_read_xl320) {
					std::vector<uint32_t> temperature_list;
					int read_temperature_result = xl320->syncReadTemperature(
							xl320_id_list, temperature_list);
					if (read_temperature_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl320_motor_list.size();
								i++) {
							set_state(xl320_motor_list.at(i).name + "/" +
											hardware_interface::
													HW_IF_TEMPERATURE,
									temperature_list.at(i));
						}
					} else {
						xl320_hw_fail_counter_read++;
					}
				}

				// Read from XL430 motors
				if (can_read_xl430) {
					std::vector<uint32_t> temperature_list;
					int read_temperature_result = xl430->syncReadTemperature(
							xl430_id_list, temperature_list);
					if (read_temperature_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl430_motor_list.size();
								i++) {
							set_state(xl430_motor_list.at(i).name + "/" +
											hardware_interface::
													HW_IF_TEMPERATURE,
									temperature_list.at(i));
						}
					} else {
						xl430_hw_fail_counter_read++;
					}
				}

				// Read voltage
				// Read from XL320 motors
				if (can_read_xl320) {
					std::vector<uint32_t> voltage_list;
					int read_voltage_result =
							xl320->syncReadVoltage(xl320_id_list, voltage_list);
					if (read_voltage_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl320_motor_list.size();
								i++) {
							set_state(xl320_motor_list.at(i).name + "/voltage",
									voltage_list.at(i));
						}
					} else {
						xl320_hw_fail_counter_read++;
					}
				}

				// Read from XL430 motors
				if (can_read_xl430) {
					std::vector<uint32_t> voltage_list;
					int read_voltage_result =
							xl430->syncReadVoltage(xl430_id_list, voltage_list);
					if (read_voltage_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl430_motor_list.size();
								i++) {
							set_state(xl430_motor_list.at(i).name + "/voltage",
									voltage_list.at(i));
						}
					} else {
						xl430_hw_fail_counter_read++;
					}
				}

				// Read HW error
				// Read from XL320 motors
				if (can_read_xl320) {
					std::vector<uint32_t> hw_error_list;
					int read_hw_error_result = xl320->syncReadHwErrorStatus(
							xl320_id_list, hw_error_list);
					if (read_hw_error_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl320_motor_list.size();
								i++) {
							set_state(xl320_motor_list.at(i).name + "/hw_error",
									hw_error_list.at(i));
						}
					} else {
						xl320_hw_fail_counter_read++;
					}
				}

				// Read from XL430 motors
				if (can_read_xl430) {
					std::vector<uint32_t> hw_error_list;
					int read_hw_error_result = xl430->syncReadHwErrorStatus(
							xl430_id_list, hw_error_list);
					if (read_hw_error_result == COMM_SUCCESS) {
						xl320_hw_fail_counter_read = 0;
						for (std::size_t i = 0; i < xl430_motor_list.size();
								i++) {
							set_state(xl430_motor_list.at(i).name + "/hw_error",
									hw_error_list.at(i));
						}
					} else {
						xl430_hw_fail_counter_read++;
					}
				}
			}
		}

		if (xl320_hw_fail_counter_read > 25 ||
				xl430_hw_fail_counter_read > 25) {
			RCLCPP_ERROR(get_logger(),
					"DXL connection problem - Failed to read from DXL bus");
			xl320_hw_fail_counter_read = 0;
			xl430_hw_fail_counter_read = 0;
			is_dxl_connection_ok = false;
		}
	}

	void NiryoOneHardwareDxl::hardwareControlWrite() {
		std::vector<uint8_t> xl320_id_list;
		std::vector<uint8_t> xl430_id_list;

		// Used to reduce redundant code after these arrays will
		// contain only enabled motors
		std::vector<hardware_interface::ComponentInfo> xl320_motor_list;
		std::vector<hardware_interface::ComponentInfo> xl430_motor_list;
		hardware_interface::ComponentInfo tool;

		for (auto joint : info_.joints) {
			if (get_state(joint.name + "/enabled")) {
				if (stoi(joint.parameters["type"]) == MOTOR_TYPE_XL320) {
					if (stoi(joint.parameters["id"]) != 0) {
						xl320_id_list.push_back(stoi(joint.parameters["id"]));
						xl320_motor_list.push_back(joint);
						if (joint.name == "tool") {
							tool = joint;
						}
					}
				} else if (stoi(joint.parameters["type"]) == MOTOR_TYPE_XL430) {
					xl430_id_list.push_back(stoi(joint.parameters["id"]));
					xl430_motor_list.push_back(joint);
				}
			}
		}

		// If asked to reboot motors, reboot all motors
		// Even the ones which are not enabled
		// Same command for xl320 and xl430 (depends on protocol, not motor type)
		if (should_reboot_motors) {
			for (auto joint : info_.joints) {
				RCLCPP_WARN(get_logger(), "Reboot DXL motor with ID: %s",
						joint.parameters["id"]);
				xl430->reboot(stoi(joint.parameters["id"]));
			}
			should_reboot_motors = false;
		}

		if (factory_reset_motor_id != -1) {
			xl430->factoryReset(factory_reset_motor_id, uart_baudrate);
			factory_reset_motor_id = -1;
		}

		if (get_clock()->now().seconds() - time_hw_data_last_write >
				1.0 / hw_data_write_frequency) {
			time_hw_data_last_write += 1.0 / hw_data_write_frequency;

			// Send custom command if any
			if (custom_command_queue.size() > 0) {
				DxlCustomCommand cmd = custom_command_queue.front();

				RCLCPP_INFO(get_logger(),
						"Sending custom command to Dynamixel:\nMotor type: %d, "
						"ID: %d, Value: %d, Address: %d, Size: %d",
						cmd.motor_type, (int) cmd.id, (int) cmd.value,
						(int) cmd.reg_address, (int) cmd.byte_number);

				if (cmd.motor_type == MOTOR_TYPE_XL320) {
					int result = xl320->customWrite(cmd.id, cmd.value,
							cmd.reg_address, cmd.byte_number);
					if (result != COMM_SUCCESS) {
						RCLCPP_WARN(get_logger(),
								"Failed to write custom command: %d", result);
					}
				} else if (cmd.motor_type == MOTOR_TYPE_XL430) {
					int result = xl430->customWrite(cmd.id, cmd.value,
							cmd.reg_address, cmd.byte_number);
					if (result != COMM_SUCCESS) {
						RCLCPP_WARN(get_logger(),
								"Failed to write custom command: %d", result);
					}
				} else {
					RCLCPP_WARN(get_logger(),
							"Wrong motor type, should be 1 (XL-320) or 2 "
							"(XL-430).");
				}

				// Remove from queue if successfully sent
				custom_command_queue.pop();
			}

			// Write torque enable (for all motors, including tool)
			if (write_torque_on_enable) {
				RCLCPP_INFO(get_logger(), "Writing torque");
				std::vector<uint32_t> xl320_torque_enable_list;
				for (auto joint : xl320_motor_list) {
					xl320_torque_enable_list.push_back(torque_on);
				}

				std::vector<uint32_t> xl430_torque_enable_list;
				for (auto joint : xl430_motor_list) {
					xl430_torque_enable_list.push_back(torque_on);
				}

				int xl320_result = xl320->syncWriteTorqueEnable(
						xl320_id_list, xl320_torque_enable_list);
				int xl430_result = xl430->syncWriteTorqueEnable(
						xl430_id_list, xl430_torque_enable_list);

				if (xl320_result != COMM_SUCCESS ||
						xl430_result != COMM_SUCCESS) {
					RCLCPP_WARN(get_logger(), "Failed to write torque enable");
				} else {
					write_torque_on_enable =
							false;  // Disable writing torque ON/OFF after success on all motors
				}

				if (is_tool_connected) {
					xl320_id_list.pop_back();
				}
			}

			if (torque_on) {
				// Write position (not for tool)
				if (write_position_enable) {
					// RCLCPP_INFO(get_logger(), "Writing position");
					std::vector<uint32_t> xl320_position_list;
					for (auto joint : xl320_motor_list) {
						double pos = rad_pos_to_xl320_pos(
								get_command(joint.name + "/" +
										hardware_interface::HW_IF_POSITION));
						// RCLCPP_INFO(get_logger(), "Joint: %s - Position: %d",
						// 		joint.name.c_str(),
						// 		get_command(joint.name + "/" +
						// 				hardware_interface::HW_IF_POSITION));
						xl320_position_list.push_back(pos);
					}

					std::vector<uint32_t> xl430_position_list;
					for (auto joint : xl430_motor_list) {
						double pos = rad_pos_to_xl430_pos(
								get_command(joint.name + "/" +
										hardware_interface::HW_IF_POSITION));
						// RCLCPP_INFO(get_logger(), "Joint: %s - Position: %d",
						// 		joint.name.c_str(),
						// 		get_command(joint.name + "/" +
						// 				hardware_interface::HW_IF_POSITION));
						xl430_position_list.push_back(pos);
					}

					int xl320_result = xl320->syncWritePositionGoal(
							xl320_id_list, xl320_position_list);
					int xl430_result = xl430->syncWritePositionGoal(
							xl430_id_list, xl430_position_list);

					if (xl320_result != COMM_SUCCESS ||
							xl430_result != COMM_SUCCESS) {
						RCLCPP_WARN(get_logger(), "Failed to write position");
					}
				}

				// Write velocity (not for tool)
				if (write_velocity_enable) {
					std::vector<uint32_t> xl320_velocity_list;
					for (auto joint : xl320_motor_list) {
						xl320_velocity_list.push_back(get_command(joint.name +
								"/" + hardware_interface::HW_IF_VELOCITY));
					}

					std::vector<uint32_t> xl430_velocity_list;
					for (auto joint : xl430_motor_list) {
						xl430_velocity_list.push_back(get_command(joint.name +
								"/" + hardware_interface::HW_IF_VELOCITY));
					}

					int xl320_result = xl320->syncWriteVelocityGoal(
							xl320_id_list, xl320_velocity_list);
					int xl430_result = xl430->syncWriteVelocityGoal(
							xl430_id_list, xl430_velocity_list);

					if (xl320_result != COMM_SUCCESS ||
							xl430_result != COMM_SUCCESS) {
						RCLCPP_WARN(get_logger(), "Failed to write velocity");
					}
				}

				// Write torque (not for tool)
				if (write_torque_enable) {
					std::vector<uint32_t> xl320_torque_list;
					for (auto joint : xl320_motor_list) {
						xl320_torque_list.push_back(get_command(joint.name +
								"/" + hardware_interface::HW_IF_TORQUE));
					}

					std::vector<uint32_t> xl430_torque_list;
					for (auto joint : xl430_motor_list) {
						xl430_torque_list.push_back(get_command(joint.name +
								"/" + hardware_interface::HW_IF_TORQUE));
					}

					int xl320_result = xl320->syncWriteTorqueGoal(
							xl320_id_list, xl320_torque_list);
					int xl430_result = xl430->syncWriteTorqueGoal(
							xl430_id_list, xl430_torque_list);

					if (xl320_result != COMM_SUCCESS ||
							xl430_result != COMM_SUCCESS) {
						RCLCPP_WARN(get_logger(), "Failed to write torque");
					}
				}

				// Write tool separately - Send position, velocity, and torque torgether
				if (write_tool_enable && is_tool_connected) {
					std::this_thread::sleep_for(std::chrono::milliseconds(5));
					int write_tool_velocity_result = xl320->setGoalVelocity(
							stoi(tool.parameters["id"]),
							get_command(tool.name + "/" +
									hardware_interface::HW_IF_VELOCITY));
					std::this_thread::sleep_for(std::chrono::milliseconds(5));
					int write_tool_position_result = xl320->setGoalPosition(
							stoi(tool.parameters["id"]),
							get_command(tool.name + "/" +
									hardware_interface::HW_IF_POSITION));
					std::this_thread::sleep_for(std::chrono::milliseconds(5));
					int write_tool_torque_result =
							xl320->setGoalTorque(stoi(tool.parameters["id"]),
									get_command(tool.name + "/" +
											hardware_interface::HW_IF_TORQUE));

					if (write_tool_velocity_result != COMM_SUCCESS ||
							write_tool_position_result != COMM_SUCCESS ||
							write_tool_torque_result != COMM_SUCCESS) {
						RCLCPP_WARN(get_logger(), "Failed to write on tool");
					} else {
						write_tool_enable =
								false;  // Disable writing on tool after success
					}
				}
			}

			if (write_led_enable) {
				std::vector<uint32_t> xl320_led_list;
				for (auto joint : xl320_motor_list) {
					xl320_led_list.push_back(get_command(joint.name + "/led"));
				}

				if (is_tool_connected) {
					xl320_id_list.push_back(stoi(tool.parameters["id"]));
					xl320_led_list.push_back(get_command(tool.name + "/led"));
				}

				int xl320_result =
						xl320->syncWriteLed(xl320_id_list, xl320_led_list);

				if (xl320_result != COMM_SUCCESS) {
					RCLCPP_WARN(get_logger(), "Failed to write LED");
				} else {
					write_led_enable =
							false;  // Diable writing LED after success on all motors
				}

				if (is_tool_connected) {
					xl320_id_list.pop_back();
				}
			}
		}
	}

}  // namespace niryo_one_hardware

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(niryo_one_hardware::NiryoOneHardwareDxl,
		hardware_interface::SystemInterface);
