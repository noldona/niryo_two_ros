#include "niryo_one_hardware/niryo_one_hardware_can.hpp"
#include "niryo_one_hardware/utilities.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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
	CallbackReturn NiryoOneHardwareCan::on_init(
			const hardware_interface::HardwareInfo &info) {
		if (hardware_interface::SystemInterface::on_init(info) !=
				CallbackReturn::SUCCESS) {
			return CallbackReturn::ERROR;
		}

		// Get hardware parameters
		RCLCPP_INFO(get_logger(), "Getting CAN hardware parameters");
		hardware_version = stoi(info_.hardware_parameters["hardware_version"]);

		if (hardware_version != 1 && hardware_version != 2) {
			RCLCPP_ERROR(get_logger(),
					"Incorrect hardware_version, should be 1 or 2");
			return CallbackReturn::ERROR;
		}

		use_sim = stob(info_.hardware_parameters["use_sim"]);
		RCLCPP_INFO(get_logger(), "Using sim: %d", use_sim);
		spi_channel = stoi(info_.hardware_parameters["spi_channel"]);
		spi_baudrate = stoi(info_.hardware_parameters["spi_baudrate"]);
		gpio_can_interrupt =
				stoi(info_.hardware_parameters["gpio_can_interrupt"]);
		RCLCPP_INFO(get_logger(),
				"SPI Channel: %d, Baudrate: %d, GPIO CAN Interrupt: %d",
				spi_channel, spi_baudrate, gpio_can_interrupt);

		can_enabled = stob(info_.hardware_parameters["can_enabled"]);
		niryo_one_hw_check_connection_frequency = stod(info_.hardware_parameters
						["niryo_one_hw_check_connection_frequency"]);
		hw_control_loop_frequency = stod(
				info_.hardware_parameters["can_hw_control_loop_frequency"]);
		hw_write_frequency =
				stod(info_.hardware_parameters["can_hw_write_frequency"]);
		hw_check_connection_frequency = stod(
				info_.hardware_parameters["can_hw_check_connection_frequency"]);

		calibration_timeout =
				stoi(info_.hardware_parameters["calibration_timeout"]);

		// Start CAN driver
		can.reset(new NiryoCanDriver(
				spi_channel, spi_baudrate, gpio_can_interrupt));

		is_can_connection_ok = false;
		hw_is_busy = false;

		async_thread_shutdown_ = false;
		initialized_ = false;

		torque_on = 0;

		hw_is_busy = false;
		hw_limited_mode = true;

		write_position_enable = true;
		write_torque_enable = false;
		write_torque_on_enable = true;

		write_synchronize_enable = false;
		write_micro_steps_enable = true;
		write_max_effort_enable = true;

		waiting_for_user_trigger_calibration = false;
		steppers_calibration_mode =
				CAN_STEPPERS_CALIBRATION_MODE_AUTO;  // default
		write_synchronize_begin_traj = true;
		calibration_in_progress = false;

		return CallbackReturn::SUCCESS;
	}

	std::vector<hardware_interface::InterfaceDescription> NiryoOneHardwareCan::
			export_unlisted_command_interface_descriptions() {
		std::vector<hardware_interface::InterfaceDescription> interfaces;

		for (std::map<CommandInterfaces, std::string>::iterator iter =
						command_interface_names.begin();
				iter != command_interface_names.end(); ++iter) {
			hardware_interface::InterfaceInfo info;
			info.name = iter->second;
			hardware_interface::InterfaceDescription desc =
					hardware_interface::InterfaceDescription("niryo_one", info);
			interfaces.push_back(desc);
		}

		return interfaces;
	}

	CallbackReturn NiryoOneHardwareCan::on_configure(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Configuring CAN hardware... please wait...");

		if (!use_sim) {
			if (can->setupInterruptGpio() != CAN_OK) {
				RCLCPP_ERROR(get_logger(), "Failed to start GPIO for CAN bus");
				return CallbackReturn::ERROR;
			}

			if (can->setupSpi() != CAN_OK) {
				RCLCPP_ERROR(get_logger(),
						"Failed to start SPI communication for CAN bus");
				return CallbackReturn::ERROR;
			}

			if (can->init() != CAN_OK) {
				RCLCPP_ERROR(get_logger(), "Failed to initialize CAN bus");
				return CallbackReturn::ERROR;
			}
		}

		async_thread_ = std::make_shared<std::thread>(
				&NiryoOneHardwareCan::asyncThread, this);

		RCLCPP_INFO(get_logger(), "Successfully configured CAN hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareCan::on_cleanup(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Cleaning up CAN hardware... please wait...");

		if (async_thread_) {
			async_thread_shutdown_ = true;
			async_thread_->join();
			async_thread_.reset();
		}

		RCLCPP_INFO(get_logger(), "Successfully cleaned up CAN hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareCan::on_activate(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Activating CAN hardware... please wait...");

		for (auto joint : info_.joints) {
			set_command(joint.name + "/" + hardware_interface::HW_IF_POSITION,
					rad_pos_to_steps(stod(joint.parameters["home_position"]),
							stod(joint.parameters["gear_ratio"]),
							stod(joint.parameters["direction"])));
			set_command(joint.name + "/mirco_steps", 8);
			set_command(joint.name + "/max_effort",
					stod(joint.parameters["max_effort"]));
			set_state(joint.name + "/enabled", true);
		}

		can_connection_loop_thread.reset(new std::thread(
				std::bind(&NiryoOneHardwareCan::manageCanConnection, this)));

		RCLCPP_INFO(get_logger(), "Successfully activated CAN hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareCan::on_deactivate(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(
				get_logger(), "Deactivating CAN hardware... please wait...");

		RCLCPP_INFO(get_logger(), "Successfully deactivated CAN hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareCan::on_shutdown(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(
				get_logger(), "Shutting down CAN hardware... please wait...");

		RCLCPP_INFO(get_logger(), "Successfully shut down CAN hardware!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardwareCan::on_error(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(
				get_logger(), "Handling error CAN hardware... please wait...");

		RCLCPP_INFO(get_logger(), "Successfully handled error CAN hardware!");

		return CallbackReturn::SUCCESS;
	}

	return_type NiryoOneHardwareCan::read(
			const rclcpp::Time & /*time*/, const rclcpp::Duration &period) {
		// RCLCPP_INFO(get_logger(), "Reading");
		if (use_sim) {
			for (auto joint : info_.joints) {
				const auto name_pos =
						joint.name + "/" + hardware_interface::HW_IF_POSITION;
				const auto name_vel =
						joint.name + "/" + hardware_interface::HW_IF_VELOCITY;
				const auto name_tor =
						joint.name + "/" + hardware_interface::HW_IF_TORQUE;
				const auto name_temp = joint.name + "/" +
						hardware_interface::HW_IF_TEMPERATURE;
				const auto name_enabled = joint.name + "/" + "enabled";

				// If simulating, echo the commands back out as the state
				double prev_pos = get_state(name_pos);
				set_state(name_pos, get_command(name_pos));
				set_state(name_vel,
						(prev_pos - get_command(name_pos)) * period.seconds());
				set_state(name_tor, get_command(name_tor));
				set_state(name_temp, 0);
				set_state(name_enabled, 1);
			}
		} else {
			if (!hw_is_busy && hw_control_loop_keep_alive) {
				hw_is_busy = true;
				hardwareControlRead();
				hardwareControlCheckConnection();

				hw_is_busy = false;
			}
		}

		return return_type::OK;
	}

	return_type NiryoOneHardwareCan::write(const rclcpp::Time & /*time*/,
			const rclcpp::Duration & /*period*/) {
		// RCLCPP_INFO(get_logger(), "Writing");
		if (use_sim) {
			// Do nothing. Simulation is handled in read
		} else {
			if (!hw_is_busy && hw_control_loop_keep_alive) {
				hw_is_busy = true;

				hardwareControlWrite();

				hw_is_busy = false;
			}
		}

		return return_type::OK;
	}

	void NiryoOneHardwareCan::manageCanConnection() {
		if (!can_enabled) {
			return;
		}

		rclcpp::Rate check_connection_rate =
				rclcpp::Rate(niryo_one_hw_check_connection_frequency);
		bool motors_ok = false;

		while (rclcpp::ok()) {
			if (!is_can_connection_ok || new_calibration_requested) {
				new_calibration_requested = false;
				RCLCPP_WARN(get_logger(), "Stop CAN HW control");
				stopHardwareControlLoop();
				std::this_thread::sleep_for(std::chrono::milliseconds(100));

				while (scanAndCheck() != CAN_SCAN_OK) {
					// Wait for connection to be up
					RCLCPP_WARN(
							get_logger(), "Scan to find stepper motors ...");
					std::this_thread::sleep_for(std::chrono::milliseconds(250));
				}

				// Once connected, set calibration flag
				RCLCPP_INFO(get_logger(), "Set calibration flag");
				waiting_for_user_trigger_calibration = false;

				// Deactivate motors
				setTorqueOn(false);

				startHardwareControlLoop(true);  // Limited mode
				motors_ok = false;

				if (!motors_ok) {
					int calibration_step1_result =
							CAN_STEPPERS_CALIBRATION_FAIL;
					int calibration_step2_result =
							CAN_STEPPERS_CALIBRATION_FAIL;

					// RCLCPP_INFO(get_logger(), "Starting Calibration");
					calibration_step1_result = calibrateMotors(1);
					if (calibration_step1_result ==
							CAN_STEPPERS_CALIBRATION_OK) {
						calibration_step2_result = calibrateMotors(2);
					}

					if (calibration_step1_result ==
									CAN_STEPPERS_CALIBRATION_OK &&
							calibration_step2_result ==
									CAN_STEPPERS_CALIBRATION_OK) {
						RCLCPP_INFO(get_logger(), "Calibration completed");
						motors_ok = true;
						new_calibration_requested = false;
						activateLearningMode(true);
					} else {
						RCLCPP_INFO(get_logger(),
								"Calibration failed, trying again");
						// Calibration is not OK, wait and retry
						if (!is_can_connection_ok) {
							while (scanAndCheck() != CAN_SCAN_OK) {
								// Wait for connection to be up
								RCLCPP_WARN(get_logger(),
										"Scan to find stepper motors...");
								std::this_thread::sleep_for(
										std::chrono::milliseconds(250));
							}
						}

						// Last calibration has failed, reset flag
						if (calibration_step1_result !=
								CAN_STEPPERS_CALIBRATION_WAITING_USER_INPUT) {
							waiting_for_user_trigger_calibration = true;
							// Go back to limited mode (during calibration, HW control loop is stopped)
							startHardwareControlLoop(true);
						}

						// std::this_thread::sleep_for(std::chrono::milliseconds(250));
					}
				}

				if (motors_ok) {
					RCLCPP_WARN(get_logger(), "Resume CAN HW control");
					activateLearningMode(true);
					startHardwareControlLoop(false);
				}
			} else {
				// CAN connection OK and calibrated
				if (hw_limited_mode) {
					setTorqueOn(false);
					startHardwareControlLoop(false);
				}
			}
			check_connection_rate.sleep();
		}
	}

	int NiryoOneHardwareCan::scanAndCheck() {
		int counter = 0;

		while (hw_is_busy && counter < 100) {
			std::this_thread::sleep_for(
					std::chrono::microseconds(TIME_TO_WAIT_IF_BUSY));
			counter++;
		}

		if (counter == 100) {
			RCLCPP_WARN(get_logger(),
					"Failed to scan motors, CAN bus is too busy (counter "
					"max: %d)",
					counter);
			return CAN_SCAN_BUSY;
		}

		hw_is_busy = true;

		// If some motors are diabled, just declare them as connected;
		bool m1_ok = false;
		bool m2_ok = false;
		bool m3_ok = false;

		double time_begin_scan = get_clock()->now().seconds();
		double min_time_to_wait = 0.25;
		double timeout = 0.5;

		while (!m1_ok || !m2_ok || !m3_ok ||
				(get_clock()->now().seconds() - time_begin_scan <
						min_time_to_wait)) {
			std::this_thread::sleep_for(
					std::chrono::milliseconds(1));  /// Check at 1000 Hz

			if (can->canReadData()) {
				long unsigned int rxId;
				unsigned char len;
				unsigned char rxBuf[8];

				can->readMsgBuf(&rxId, &len, rxBuf);

				// Validate ID
				int motor_id =
						rxId & 0x00F;  // 0x101 for ID 1, 0x102 for ID 2, ...
				if (motor_id == stoi(info_.joints[0].parameters["id"])) {
					m1_ok = true;
				} else if (motor_id == stoi(info_.joints[1].parameters["id"])) {
					m2_ok = true;
				} else if (motor_id == stoi(info_.joints[2].parameters["id"])) {
					m3_ok = true;
				} else {
					RCLCPP_ERROR(get_logger(),
							"Scan CAN bus: Receieved CAN frame with wrong ID: "
							"%d",
							motor_id);
					hw_is_busy = false;
					RCLCPP_ERROR(get_logger(), "Unallowed connected motor: %d",
							motor_id);
					return CAN_SCAN_NOT_ALLOWED;
				}
			}

			if (get_clock()->now().seconds() - time_begin_scan > timeout) {
				RCLCPP_ERROR(get_logger(), "CAN scan timeout");
				std::string msg = "CAN bus scan failed: motors ";
				if (!m1_ok) {
					msg += info_.joints[0].parameters["name"] + ", ";
				}
				if (!m2_ok) {
					msg += info_.joints[1].parameters["name"] + ", ";
				}
				if (!m3_ok) {
					msg += info_.joints[2].parameters["name"] + ", ";
				}
				RCLCPP_ERROR(get_logger(), msg.c_str());
				is_can_connection_ok = false;
				hw_is_busy = false;
				return CAN_SCAN_TIMEOUT;
			}
		}

		hw_is_busy = false;
		is_can_connection_ok = true;
		return CAN_SCAN_OK;
	}

	void NiryoOneHardwareCan::stopHardwareControlLoop() {
		for (auto joint : info_.joints) {
			const auto name_pos =
					joint.name + "/" + hardware_interface::HW_IF_POSITION;
			const auto name_vel =
					joint.name + "/" + hardware_interface::HW_IF_VELOCITY;
			const auto name_tor =
					joint.name + "/" + hardware_interface::HW_IF_TORQUE;
			const auto name_temp =
					joint.name + "/" + hardware_interface::HW_IF_TEMPERATURE;
			const auto name_hw_error = joint.name + "/hardware_error";
			const auto name_enabled = joint.name + "/enabled";

			set_state(name_pos, stod(joint.parameters["home_position"]));
			set_state(name_vel, 0.0);
			set_state(name_tor, 0.0);
			set_state(name_temp, 0.0);
			set_state(name_hw_error, 0.0);
			// set_state(name_enabled, 0.0);
		}

		hw_control_loop_keep_alive = false;
	}

	void NiryoOneHardwareCan::setTorqueOn(bool on) {
		if (!on && is_can_connection_ok &&
				waiting_for_user_trigger_calibration &&
				!calibration_in_progress) {
			RCLCPP_INFO(get_logger(),
					"On: %d, Can Connection OK: %d, Waiting for User Trigger "
					"Calibration: %d, Calibration In Progress: %d",
					on, is_can_connection_ok,
					waiting_for_user_trigger_calibration,
					calibration_in_progress);
			RCLCPP_INFO(get_logger(), "Setting torque OFF");
			can->sendTorqueOnCommand(CAN_BROADCAST_ID,
					false);  // Only to deactivate motors when waiting for calibration
		} else if (hw_limited_mode) {
			RCLCPP_INFO(get_logger(), "Setting torque OFF, write enable true");
			torque_on = false;
			write_torque_on_enable = true;
		} else {
			RCLCPP_INFO(get_logger(), "Setting torque ON, write enable true");
			torque_on = on;
			write_torque_on_enable = true;
		}
	}

	void NiryoOneHardwareCan::startHardwareControlLoop(bool limited_mode) {
		RCLCPP_INFO(get_logger(), "CAN: Start hardware loop control");
		write_torque_on_enable = true;
		write_micro_steps_enable = true;
		write_max_effort_enable = true;

		// Reset hardware control loop rates
		time_hw_last_write = get_clock()->now().seconds();
		time_hw_last_check_connection = get_clock()->now().seconds();

		// Depends on limited_mode flag
		write_position_enable = !limited_mode;
		write_synchronize_enable = !limited_mode;
		hw_limited_mode = limited_mode;
		hw_control_loop_keep_alive = true;
	}

	void NiryoOneHardwareCan::activateLearningMode(bool activate) {
		setTorqueOn(!activate);
	}

	int NiryoOneHardwareCan::calibrateMotors(int calibration_step) {
		if (!is_can_connection_ok) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		// This flag should be cleared by a user action to continue
		if (waiting_for_user_trigger_calibration) {
			return CAN_STEPPERS_CALIBRATION_WAITING_USER_INPUT;
		}

		RCLCPP_INFO(get_logger(),
				"START Calibrationg stepper motors, step number %d",
				calibration_step);
		stopHardwareControlLoop();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		// If user wants to do a manual calibration, just send offset to current position
		if (steppers_calibration_mode == CAN_STEPPERS_CALIBRATION_MODE_MANUAL) {
			if (calibration_step > 1) {
				return CAN_STEPPERS_CALIBRATION_OK;
			}
			calibration_in_progress = true;
			int result = manualCalibration();
			calibration_in_progress = false;
			return result;
		} else if (steppers_calibration_mode ==
				CAN_STEPPERS_CALIBRATION_MODE_AUTO) {
			if (calibration_step == 1) {
				calibration_in_progress = true;
				int result = autoCalibrationStep1();
				return result;
			} else if (calibration_step == 2) {
				int result = autoCalibrationStep2();
				calibration_in_progress = false;
				return result;
			}
		}

		return CAN_STEPPERS_CALIBRATION_FAIL;
	}

	int NiryoOneHardwareCan::manualCalibration() {
		std::vector<int> motor_id_list;
		std::vector<int> steps_list;

		if (!get_motors_calibration_offsets(motor_id_list, steps_list)) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		for (auto joint : info_.joints) {
			if (get_state(joint.name + "/enabled")) {
				// Compute step offset to send
				int offset_to_send = 0;
				int sensor_offset_steps = 0;
				int absolute_steps_at_offset_position = 0;
				int offset_steps = stoi(joint.parameters["offset_position"]);
				for (std::size_t j = 0; j < motor_id_list.size(); j++) {
					if (stoi(joint.parameters["id"]) == motor_id_list[j]) {
						sensor_offset_steps = steps_list[j];
						break;
					}
				}

				if (stoi(joint.parameters["id"]) == 1 ||
						stoi(joint.parameters["id"]) == 2) {
					// Position 0.0
					offset_to_send =
							(sensor_offset_steps - offset_steps) % 1600;
					if (offset_to_send < 0) {
						offset_to_send += 1600;
					}
					absolute_steps_at_offset_position = offset_to_send;
				} else if (stoi(joint.parameters["id"]) == 3) {
					// Max position
					offset_to_send = sensor_offset_steps - offset_steps;
					absolute_steps_at_offset_position = sensor_offset_steps;
				}

				RCLCPP_INFO(get_logger(), "Motor %d - sending offset: %d",
						stoi(joint.parameters["id"]), offset_to_send);
				if (can->sendPositionOffsetCommand(stoi(joint.parameters["id"]),
							offset_to_send,
							absolute_steps_at_offset_position) != CAN_OK) {
					return CAN_STEPPERS_CALIBRATION_FAIL;
				}
			}
		}

		return CAN_STEPPERS_CALIBRATION_OK;
	}

	int NiryoOneHardwareCan::autoCalibrationStep1() {
		// 0. Torque ON for motor 2
		if (can->sendTorqueOnCommand(
					stoi(info_.joints[1].parameters["id"]), true) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		// 1. Move axis 3 up
		if (relativeMoveMotor(info_.joints[2],
					rad_pos_to_steps(0.5,
							stod(info_.joints[2].parameters["gear_ratio"]),
							stod(info_.joints[2].parameters["direction"])),
					1500, true) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		return CAN_STEPPERS_CALIBRATION_OK;
	}

	int NiryoOneHardwareCan::autoCalibrationStep2() {
		std::vector<int> sensor_offset_ids;
		std::vector<int>
				sensor_offset_steps;  // Absolute steps at offset position

		// 2. Send calibration cmd 1 + 2 + 3
		RCLCPP_INFO(get_logger(), "Sending calibration for Joint 1");
		if (sendCalibrationCommandForOneMotor(
					info_.joints[0], 800, 1, calibration_timeout) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		RCLCPP_INFO(get_logger(), "Sending calibration for Joint 2");
		if (sendCalibrationCommandForOneMotor(
					info_.joints[1], 1100, 1, calibration_timeout) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		RCLCPP_INFO(get_logger(), "Sending calibration for Joint 3");
		if (hardware_version == 2) {
			if (sendCalibrationCommandForOneMotor(info_.joints[2], 1100, -1,
						calibration_timeout) != CAN_OK) {
				return CAN_STEPPERS_CALIBRATION_FAIL;
			}
		}

		// 2.1 Wait calibration result
		if (getCalibrationResults(info_.joints, calibration_timeout,
					sensor_offset_ids,
					sensor_offset_steps) != CAN_STEPPERS_CALIBRATION_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		// 3. Move motor 1 to 0.0
		if (relativeMoveMotor(info_.joints[0],
					-stoi(info_.joints[0].parameters["offset_position"]), 1300,
					false) != CAN_OK) {
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		// 3.1 Wait for motors to finish moving (at least m4, so we can start m3 calibration)
		// For HW version 2, just wait for m1 to be at home position
		if (hardware_version == 1) {
			// TODO: Make this work with hardware version 1
		} else if (hardware_version == 2) {
			std::this_thread::sleep_for(std::chrono::seconds(
					(int) (abs(stod(info_.joints[0]
										   .parameters["offset_position"])) *
							1300 / 1000000)));
		}

		// 3.2 Move axis 2 to home position after axis 1
		// --> in case a gripper is attached, so it won't collide with the base while moving
		if (hardware_version == 2) {
			if (relativeMoveMotor(info_.joints[1],
						-stod(info_.joints[2].parameters["offset_position"]),
						3000, false) != CAN_OK) {
				return CAN_STEPPERS_CALIBRATION_FAIL;
			}
			std::this_thread::sleep_for(std::chrono::seconds(
					(int) (abs(stod(info_.joints[1]
										   .parameters["offset_position"])) *
									3000 / 1000000 +
							0.5)));
		}

		// 5. Send calibration cmd m3 (only for HW version 1)
		if (hardware_version == 1) {
			// TODO: this
		}

		// 6. Write sensors_offset_steps_to_file
		set_motors_calibration_offsets(sensor_offset_ids, sensor_offset_steps);

		return CAN_STEPPERS_CALIBRATION_OK;
	}

	int NiryoOneHardwareCan::relativeMoveMotor(
			hardware_interface::ComponentInfo joint, int steps, int delay,
			bool wait) {
		if (!get_state(joint.name + "/enabled")) {
			return CAN_OK;
		}

		if (can->sendTorqueOnCommand(stoi(joint.parameters["id"]), true) !=
				CAN_OK) {
			RCLCPP_ERROR(get_logger(), "Failed to send torque ON to motor %d",
					stoi(joint.parameters["id"]));
			return CAN_FAIL;
		}

		if (can->sendRelativeMoveCommand(
					stoi(joint.parameters["id"]), steps, delay) != CAN_OK) {
			RCLCPP_ERROR(get_logger(),
					"Relative Move motor failed for motor %d",
					stoi(joint.parameters["id"]));
			return CAN_FAIL;
		}

		if (wait) {
			std::this_thread::sleep_for(std::chrono::seconds(
					(int) (steps * delay / 1000000 + 0.5)));
		}

		return CAN_OK;
	}

	int32_t NiryoOneHardwareCan::rad_pos_to_steps(
			double position_rad, double gear_ratio, double direction) {
		return (int32_t) ((200.0 * 8.0 * gear_ratio * position_rad *
								  RADIAN_TO_DEGREE / 360.0) *
				direction);
	}

	double NiryoOneHardwareCan::steps_to_rad_pos(
			int32_t steps, double gear_ratio, double direction) {
		return (double) ((double) steps * 360.0 /
					   (200.0 * 8.0 * gear_ratio * RADIAN_TO_DEGREE)) *
				direction;
	}

	int NiryoOneHardwareCan::sendCalibrationCommandForOneMotor(
			hardware_interface::ComponentInfo joint, int delay_between_steps,
			int calibration_direction, int calibr_timeout) {
		if (!get_state(joint.name + "/enabled")) {
			return CAN_OK;
		}

		RCLCPP_INFO(get_logger(),
				"Sending Calibration, Joint %d, Offset Position: %d, Delay: "
				"%d, Direction: %d, Timeout: %d",
				stoi(joint.parameters["id"]),
				rad_pos_to_steps(stod(joint.parameters["offset_position"]),
						stod(joint.parameters["gear_ratio"]),
						stod(joint.parameters["direction"])),
				delay_between_steps,
				stoi(joint.parameters["direction"]) * calibration_direction,
				calibr_timeout);
		if (can->sendCalibrationCommand(stoi(joint.parameters["id"]),
					rad_pos_to_steps(stod(joint.parameters["offset_position"]),
							stod(joint.parameters["gear_ratio"]),
							stod(joint.parameters["direction"])),
					delay_between_steps,
					stoi(joint.parameters["direction"]) * calibration_direction,
					calibr_timeout) != CAN_OK) {
			RCLCPP_ERROR(get_logger(),
					"Failed to send calibration command for motor: %d",
					stoi(joint.parameters["id"]));
			return CAN_STEPPERS_CALIBRATION_FAIL;
		}

		return CAN_OK;
	}

	int NiryoOneHardwareCan::getCalibrationResults(
			std::vector<hardware_interface::ComponentInfo> joints,
			int calibr_timeout, std::vector<int> &sensor_offset_ids,
			std::vector<int> &sensor_offset_steps) {
		std::vector<int> motors_ids;
		std::vector<bool> calibration_results;

		for (auto joint : joints) {
			if (get_state(joint.name + "/enabled")) {
				motors_ids.push_back(stoi(joint.parameters["id"]));
				calibration_results.push_back(false);
			}
		}

		double time_begin_calibration = get_clock()->now().seconds();
		double timeout = time_begin_calibration + (double) calibr_timeout;
		RCLCPP_INFO(get_logger(), "Waiting for motor calibration");

		while (get_clock()->now().seconds() < timeout) {
			std::this_thread::sleep_for(
					std::chrono::microseconds(500));  // Check at 2000 Hz

			// Check if success
			bool success = true;
			for (std::size_t i = 0; i < calibration_results.size(); i++) {
				if (calibration_results[i] == false) {
					success = false;
				}
			}
			if (success) {
				return CAN_STEPPERS_CALIBRATION_OK;
			}

			if (can->canReadData()) {
				long unsigned int rxId;
				unsigned char len;
				unsigned char rxBuf[8];

				can->readMsgBuf(&rxId, &len, rxBuf);

				// 1. Get motor ID
				int motor_id =
						rxId & 0x00F;  // 0x101 for ID 1, 0x102 for ID 2, ...

				// 2. Check if motor ID is in array
				for (std::size_t i = 0; i < motors_ids.size(); i++) {
					if (motors_ids[i] == motor_id) {
						if (len == 2) {
							// 3. Check control byte
							int control_byte = rxBuf[0];

							// Only check this frame
							if (control_byte == CAN_DATA_CALIBRATION_RESULT) {
								int result = rxBuf[1];

								if (result ==
										CAN_STEPPERS_CALIBRATION_TIMEOUT) {
									RCLCPP_ERROR(get_logger(),
											"Motor %d has calibration timeout",
											motor_id);
									return result;
								} else if (result ==
										CAN_STEPPERS_CALIBRATION_BAD_PARAM) {
									RCLCPP_ERROR(get_logger(),
											"Bad params given to motor %d",
											motor_id);
									return result;
								} else if (result ==
										CAN_STEPPERS_CALIBRATION_OK) {
									RCLCPP_INFO(get_logger(),
											"Motor %d calibration OK",
											motor_id);
									calibration_results[i] = true;
								}
							}
						} else if (len == 4) {
							// New firmware version ->get result + absolute sensor steps at offset position
							// 3. Check control byte
							int control_byte = rxBuf[0];

							// Only check this frame
							if (control_byte == CAN_DATA_CALIBRATION_RESULT) {
								int result = rxBuf[1];

								if (result ==
										CAN_STEPPERS_CALIBRATION_TIMEOUT) {
									RCLCPP_ERROR(get_logger(),
											"Motor %d had calibration timeout",
											motor_id);
									return result;
								} else if (result ==
										CAN_STEPPERS_CALIBRATION_BAD_PARAM) {
									RCLCPP_ERROR(get_logger(),
											"Bad params given to motor %d",
											motor_id);
									return result;
								} else if (result ==
										CAN_STEPPERS_CALIBRATION_OK) {
									RCLCPP_INFO(get_logger(),
											"Motor %d - Calibration OK",
											motor_id);
									int steps_at_offset_pos =
											(rxBuf[2] << 8) + rxBuf[3];
									RCLCPP_INFO(get_logger(),
											"Motor %d - Absolute steps at "
											"offset position: %d",
											motor_id, steps_at_offset_pos);
									sensor_offset_ids.push_back(motor_id);
									sensor_offset_steps.push_back(
											steps_at_offset_pos);
									calibration_results[i] = true;

									// Keep torque on for axis 2
									// (if torsion spring is too strong the axis might move too much for the following calibration steps)
									if (motor_id ==
											stoi(joints[1].parameters["id"])) {
										can->sendTorqueOnCommand(
												stoi(joints[1].parameters
																["id"]),
												true);
									}

									// Keep torque on for axis 1
									if (motor_id ==
											stoi(joints[0].parameters["id"])) {
										can->sendTorqueOnCommand(
												stoi(joints[0].parameters
																["id"]),
												true);
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

	void NiryoOneHardwareCan::asyncThread() {
		async_thread_shutdown_ = false;
		while (!async_thread_shutdown_) {
			calibrateMotors();
			requestNewCalibration();
			testMotors();
			activateLearningMode();
			activateLeds();
			pingAndSetDxlTool();
			openGripper();
			closeGripper();
			pullAirVacuumPump();
			pushAirVacuumPump();
			changeHardwareVersion();
			rebootMotors();
			std::this_thread::sleep_for(std::chrono::nanoseconds(20000000));
		}
	}

	void NiryoOneHardwareCan::calibrateMotors() {
		int32_t status =
				unlisted_commands_
						.at(CommandInterfaces::CALIBRATE_MOTORS_RESPONSE_STATUS)
						->get_optional<double>()
						.value_or(ASYNC_NONE);
		if (status == ASYNC_WAITING) {
			int calibration_mode =
					unlisted_commands_
							.at(CommandInterfaces::
											CALIBRATE_MOTORS_REQUEST_VALUE)
							->get_optional<double>()
							.value();

			std::string result_message = "";
			int result = allowMotorsCalibrationToStart(
					calibration_mode, result_message);

			std::ignore =
					unlisted_commands_
							.at(CommandInterfaces::
											CALIBRATE_MOTORS_RESPONSE_STATUS)
							->set_value(result);
		}
	}

	void NiryoOneHardwareCan::requestNewCalibration() {
		// auto req =
		// 		unlisted_commands_
		// 				.at(CommandInterfaces::REQUEST_NEW_CALIBRATION_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::SetInt::Request::
		// 								SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::SetInt::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::SetInt::Response::SharedPtr();

		// 	unlisted_commands_
		// 			.at(CommandInterfaces::REQUEST_NEW_CALIBRATION_RESPONSE)
		// 			->set_value<
		// 					niryo_one_msgs::srv::SetInt::Response::SharedPtr>(
		// 					res);
		// }
	}

	void NiryoOneHardwareCan::testMotors() {
		// auto req =
		// 		unlisted_commands_.at(CommandInterfaces::TEST_MOTORS_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::SetInt::Request::
		// 								SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::SetInt::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::SetInt::Response::SharedPtr();

		// 	// if (motor_test_status == 1) {
		// 	// 	test_motor.stopTest();
		// 	// 	activateLearningMode(true);
		// 	// 	return true;
		// 	// }

		// 	// motor_test_status = 1;
		// 	// // if (calibration_needed) {
		// 	// // 	activateLearningMode(false);

		// 	// // 	int calibration_mode = CAN_STEPPERS_CALIBRATION_MODE_AUTO;
		// 	// // 	std::string result_message = "";
		// 	// // 	int result = allowMotorsCalibrationToStart(
		// 	// // 			calibration_mode, result_message);

		// 	// // 	std::this_thread::sleep_for(std::chrono::seconds(1));
		// 	// // 	while (calibration_in_progress) {
		// 	// // 		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		// 	// // 	}

		// 	// // 	std::this_thread::sleep_for(std::chrono::seconds(1));
		// 	// // }

		// 	// activateLearningMode(false);

		// 	// bool status = test_motor.runTest(req->value);

		// 	// activateLearningMode(true);

		// 	// if (status) {
		// 	// 	motor_test_status = 0;
		// 	// 	res->status = 200;
		// 	// 	res->message = "Success";
		// 	// 	RCLCPP_INFO(get_logger(), "Motor debug has ended with sucess");
		// 	// } else {
		// 	// 	motor_test_status = 1;
		// 	// 	res->status = 400;
		// 	// 	res->message = "Fail";
		// 	// 	RCLCPP_INFO(get_logger(), "Motor debug has ended with failure");
		// 	// }

		// 	unlisted_commands_.at(CommandInterfaces::TEST_MOTORS_RESPONSE)
		// 			->set_value<
		// 					niryo_one_msgs::srv::SetInt::Response::SharedPtr>(
		// 					res);
		// }
	}

	void NiryoOneHardwareCan::activateLearningMode() {
		int32_t status =
				unlisted_commands_
						.at(CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS)
						->get_optional<double>()
						.value_or(ASYNC_NONE);

		if (status == ASYNC_WAITING) {
			if (calibration_in_progress) {
				std::ignore =
						unlisted_commands_
								.at(ACTIVATE_LEARNING_MODE_RESPONSE_STATUS)
								->set_value(400);
			} else {
				bool learning_mode_on;
				// if (calibration_needed == 1 || is_can_connection_ok) {
				// 	// If CAN or DXL is disconnected, only allow activate learning mode
				// 	learning_mode_on = true;
				// } else {
				learning_mode_on =
						unlisted_commands_
								.at(CommandInterfaces::
												ACTIVATE_LEARNING_MODE_REQUEST_VALUE)
								->get_optional<double>()
								.value();
				// }

				activateLearningMode(learning_mode_on);

				// Publish one time
				std::ignore =
						unlisted_commands_
								.at(CommandInterfaces::
												ACTIVATE_LEARNING_MODE_RESPONSE_STATUS)
								->set_value(300);
			}
		}
	}

	void NiryoOneHardwareCan::activateLeds() {
		// auto req =
		// 		unlisted_commands_.at(CommandInterfaces::ACTIVATE_LEDS_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::SetLeds::Request::
		// 								SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::SetLeds::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::SetLeds::Response::SharedPtr();

		// 	unlisted_commands_.at(CommandInterfaces::ACTIVATE_LEDS_RESPONSE)
		// 			->set_value<
		// 					niryo_one_msgs::srv::SetLeds::Response::SharedPtr>(
		// 					res);
		// }
	}

	void NiryoOneHardwareCan::pingAndSetDxlTool() {
		// auto req =
		// 		unlisted_commands_.at(CommandInterfaces::PING_DXL_TOOL_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::PingDxlTool::
		// 								Request::SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::PingDxlTool::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::PingDxlTool::Response::SharedPtr();

		// 	unlisted_commands_.at(CommandInterfaces::PING_DXL_TOOL_RESPONSE)
		// 			->set_value<niryo_one_msgs::srv::PingDxlTool::Response::
		// 							SharedPtr>(res);
		// }
	}

	void NiryoOneHardwareCan::openGripper() {
		// auto req =
		// 		unlisted_commands_.at(CommandInterfaces::OPEN_GRIPPER_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::OpenGripper::
		// 								Request::SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::OpenGripper::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::OpenGripper::Response::SharedPtr();

		// 	unlisted_commands_.at(CommandInterfaces::OPEN_GRIPPER_RESPONSE)
		// 			->set_value<niryo_one_msgs::srv::OpenGripper::Response::
		// 							SharedPtr>(res);
		// }
	}

	void NiryoOneHardwareCan::closeGripper() {
		// auto req =
		// 		unlisted_commands_.at(CommandInterfaces::CLOSE_GRIPPER_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::CloseGripper::
		// 								Request::SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::CloseGripper::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::CloseGripper::Response::SharedPtr();

		// 	unlisted_commands_.at(CommandInterfaces::CLOSE_GRIPPER_RESPONSE)
		// 			->set_value<niryo_one_msgs::srv::CloseGripper::Response::
		// 							SharedPtr>(res);
		// }
	}

	void NiryoOneHardwareCan::pullAirVacuumPump() {
		// auto req =
		// 		unlisted_commands_
		// 				.at(CommandInterfaces::PULL_AIR_VACUUM_PUMP_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::PullAirVacuumPump::
		// 								Request::SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::PullAirVacuumPump::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::PullAirVacuumPump::Response::
		// 					SharedPtr();

		// 	unlisted_commands_
		// 			.at(CommandInterfaces::PULL_AIR_VACUUM_PUMP_RESPONSE)
		// 			->set_value<niryo_one_msgs::srv::PullAirVacuumPump::
		// 							Response::SharedPtr>(res);
		// }
	}

	void NiryoOneHardwareCan::pushAirVacuumPump() {
		// auto req =
		// 		unlisted_commands_
		// 				.at(CommandInterfaces::PUSH_AIR_VACUUM_PUMP_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::PushAirVacuumPump::
		// 								Request::SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::PushAirVacuumPump::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::PushAirVacuumPump::Response::
		// 					SharedPtr();

		// 	unlisted_commands_
		// 			.at(CommandInterfaces::PUSH_AIR_VACUUM_PUMP_RESPONSE)
		// 			->set_value<niryo_one_msgs::srv::PushAirVacuumPump::
		// 							Response::SharedPtr>(res);
		// }
	}

	void NiryoOneHardwareCan::changeHardwareVersion() {
		// auto req =
		// 		unlisted_commands_
		// 				.at(CommandInterfaces::CHANGE_HARDWARE_VERSION_REQUEST)
		// 				->get_optional<
		// 						niryo_one_msgs::srv::ChangeHardwareVersion::
		// 								Request::SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::ChangeHardwareVersion::Response::SharedPtr
		// 			res = niryo_one_msgs::srv::ChangeHardwareVersion::Response::
		// 					SharedPtr();

		// 	unlisted_commands_
		// 			.at(CommandInterfaces::CHANGE_HANDWARE_VERSION_RESPONSE)
		// 			->set_value<niryo_one_msgs::srv::ChangeHardwareVersion::
		// 							Response::SharedPtr>(res);
		// }
	}

	void NiryoOneHardwareCan::rebootMotors() {
		// auto req =
		// 		unlisted_commands_.at(CommandInterfaces::REBOOT_MOTORS_REQUEST)
		// 				->get_optional<niryo_one_msgs::srv::SetInt::Request::
		// 								SharedPtr>()
		// 				.value_or(nullptr);
		// if (req != nullptr) {
		// 	niryo_one_msgs::srv::SetInt::Response::SharedPtr res =
		// 			niryo_one_msgs::srv::SetInt::Response::SharedPtr();

		// 	unlisted_commands_.at(CommandInterfaces::REBOOT_MOTORS_RESPONSE)
		// 			->set_value<
		// 					niryo_one_msgs::srv::SetInt::Response::SharedPtr>(
		// 					res);
		// }
	}

	int NiryoOneHardwareCan::allowMotorsCalibrationToStart(
			int mode, std::string &result_message) {
		if (can_enabled) {
			if (mode == CAN_STEPPERS_CALIBRATION_MODE_MANUAL) {
				RCLCPP_INFO(get_logger(),
						"Allowing Motor Calibration: Manual calibration");
				if (!canProcessManualCalibration()) {
					// set_command("niryo_one/calibrate_motors_async_status", 400);
					return 400;
				}
			}
			validateMotorsCalibrationFromUserInput(mode);
		}

		result_message = "Calibration is starting";
		return 200;
	}

	bool NiryoOneHardwareCan::canProcessManualCalibration() {
		// 1. Check if motors firmware version is OK
		for (auto joint : info_.joints) {
			if (get_state(joint.name + "/enabled")) {
				int v_major =
						(int) get_state(joint.name + "/firmware_version_major");
				int v_minor =
						(int) get_state(joint.name + "/firmware_version_minor");
				int v_patch =
						(int) get_state(joint.name + "/firmware_version_patch");
				std::string firmware_version = "";
				firmware_version += std::to_string(v_major) + ".";
				firmware_version += std::to_string(v_minor) + ".";
				firmware_version += std::to_string(v_patch);
				RCLCPP_INFO(get_logger(), "Joint: %s, Firmware: %s",
						joint.parameters["id"].c_str(),
						firmware_version.c_str());

				if (firmware_version.length() == 0) {
					RCLCPP_WARN(get_logger(),
							"Can't process manual calibration: No firmware "
							"version available for motor %d. Make sure all "
							"motors are connected.",
							stoi(joint.parameters["id"]));
					return false;
				}
				if (stoi(firmware_version.substr(0, 1)) < 2) {
					RCLCPP_WARN(get_logger(),
							"Can't process manual calibration: You need to "
							"upgrade stepper firmware for motor %d.",
							stoi(joint.parameters["id"]));
					return false;
				}
			}
		}

		// 2. Check if motor offset values have been previously saved (with auto calibration)
		std::vector<int> motor_id_list;
		std::vector<int> steps_list;
		if (!get_motors_calibration_offsets(motor_id_list, steps_list)) {
			RCLCPP_WARN(get_logger(),
					"Can't process manual calibration: You need to make one "
					"auto calibration before using the manual calibration.");
			return false;
		}

		// 3. Check if all connected motors have a motor offset value
		for (auto joint : info_.joints) {
			if (get_state(joint.name + "/enabled")) {
				for (std::size_t j = 0; j < motor_id_list.size(); j++) {
					if (motor_id_list[j] == stoi(joint.parameters["id"])) {
						break;
					}
					if (j == motor_id_list.size() - 1) {
						RCLCPP_WARN(get_logger(),
								"Can't process manual calibration: Motor "
								"%d does not have a saved offset value, "
								"you need to do one auto calibration.",
								stoi(joint.parameters["id"]));
						return false;
					}
				}
			}
		}

		return true;
	}

	void NiryoOneHardwareCan::validateMotorsCalibrationFromUserInput(int mode) {
		waiting_for_user_trigger_calibration = false;
		if (mode == CAN_STEPPERS_CALIBRATION_MODE_MANUAL ||
				mode == CAN_STEPPERS_CALIBRATION_MODE_AUTO) {
			steppers_calibration_mode = mode;
		}
	}

	void NiryoOneHardwareCan::hardwareControlRead() {
		if (can->canReadData()) {
			long unsigned int rxId;
			unsigned char len;
			unsigned char rxBuf[8];

			can->readMsgBuf(&rxId, &len, rxBuf);

			// o. This functionality will come later, to allow user to plug
			// other CAN devices to RPI
			// Development to do here: check if id >= 0x20
			// IDs between 0x00 and 0x1F are reserved for Niryo One core
			// communication.
			// Those are lower IDs with higher priority, to ensure connection
			// with motors is always up.
			if (rxId >= 0x020) {
				// Send frame to another place and return
				// RCLCPP_INFO(get_logger(), "Frame will be sent somewhere else.");
				// return;
			}

			// 1. Validate motor ID
			int motor_id = rxId & 0x0F;  // 0x11 for ID 1, 0x12 for ID 2, ...

			// TODO: handle conveyor belts

			bool motor_found = false;
			for (auto joint : info_.joints) {
				if (motor_id == stoi(joint.parameters["id"])) {
					set_state(joint.name + "/last_time_read",
							get_clock()->now().seconds());
					motor_found = true;
					break;
				}
			}

			if (!motor_found) {
				RCLCPP_ERROR(get_logger(),
						"Received CAN frame with wrong ID: %d", motor_id);
				is_can_connection_ok = false;
				return;
			}

			// 1.1 If ID OK, check control byte and fill data
			int control_byte = rxBuf[0];

			if (control_byte == CAN_DATA_POSITION) {
				// RCLCPP_INFO(get_logger(), "Reading position data");
				// Check length
				if (len != 4) {
					RCLCPP_ERROR(get_logger(),
							"Position CAN frame should contain 4 data bytes");
					return;
				}

				int32_t pos = (rxBuf[1] << 16) + (rxBuf[2] << 8) + rxBuf[3];
				if (pos & (1 << 15)) {
					pos = -1 * ((-pos + 1) & 0xFFFF);
				}

				// Fill data
				for (auto joint : info_.joints) {
					if (motor_id == stoi(joint.parameters["id"]) &&
							get_state(joint.name + "/enabled")) {
						double rad_pos = steps_to_rad_pos(pos,
								stod(joint.parameters["gear_ratio"]),
								stod(joint.parameters["direction"]));
						set_state(joint.name + "/" +
										hardware_interface::HW_IF_POSITION,
								rad_pos);
						break;
					}
				}
			} else if (control_byte == CAN_DATA_DIAGNOSTICS) {
				// Check data length
				if (len != 4) {
					RCLCPP_ERROR(get_logger(),
							"Diagnostic CAN frame should contain 4 data bytes");
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

				// Fill data
				for (auto joint : info_.joints) {
					if (motor_id == stoi(joint.parameters["id"]) &&
							get_state(joint.name + "/enabled")) {
						set_state(joint.name + "/" +
										hardware_interface::HW_IF_TEMPERATURE,
								driver_temp);
						break;
					}
				}
			} else if (control_byte == CAN_DATA_FIRMWARE_VERSION) {
				if (len != 4) {
					RCLCPP_ERROR(get_logger(),
							"Firmware version frame should contain 4 bytes");
					return;
				}

				int v_major = rxBuf[1];
				int v_minor = rxBuf[2];
				int v_patch = rxBuf[3];

				// Fill data
				for (auto joint : info_.joints) {
					if (motor_id == stoi(joint.parameters["id"]) &&
							get_state(joint.name + "/enabled")) {
						set_state(joint.name + "/firmware_version_major",
								v_major);
						set_state(joint.name + "/firmware_version_minor",
								v_minor);
						set_state(joint.name + "/firmware_version_patch",
								v_patch);
						break;
					}
				}
			} else if (control_byte == CAN_DATA_CONVEYOR_STATE) {
				// TODO: handle conveyor belts
			}
		}
	}

	void NiryoOneHardwareCan::hardwareControlWrite() {
		// Write torque ON/OFF
		if (write_torque_on_enable) {
			if (can->sendTorqueOnCommand(CAN_BROADCAST_ID, torque_on) !=
					CAN_OK) {
				RCLCPP_ERROR(get_logger(), "Failed to send torque on");
			} else {
				write_torque_on_enable = false;
			}
		}

		// Write synchronize position
		if (write_synchronize_enable) {
			bool synchronize_write_success = true;

			for (auto joint : info_.joints) {
				if (get_state(joint.name + "/enabled")) {
					if (can->sendSynchronizePositionCommand(
								stoi(joint.parameters["id"]),
								write_synchronize_begin_traj) != CAN_OK) {
						synchronize_write_success = false;
					}
				}
			}

			if (synchronize_write_success) {
				write_synchronize_enable =
						false;  // Disable writing after success
			} else {
				RCLCPP_ERROR(get_logger(),
						"Failed to send synchronize position command");
			}
		}

		// Write position
		if (write_position_enable) {
			// RCLCPP_INFO(get_logger(), "Writing position");
			for (auto joint : info_.joints) {
				double pos = rad_pos_to_steps(
						get_command(joint.name + "/" +
								hardware_interface::HW_IF_POSITION),
						stod(joint.parameters["gear_ratio"]),
						stod(joint.parameters["direction"]));
				// RCLCPP_INFO(get_logger(), "Name: %s, Enabled: %f, Position: %f",
				// 		joint.name.c_str(), get_state(joint.name + "/enabled"),
				// 		pos);
				if (get_state(joint.name + "/enabled")) {
					if (can->sendPositionCommand(
								stoi(joint.parameters["id"]), pos) != CAN_OK) {
						RCLCPP_ERROR(get_logger(), "Failed to send position");
					}
				}
			}
		}

		// Write micro steps
		if (write_micro_steps_enable) {
			bool mirco_steps_write_success = true;
			for (auto joint : info_.joints) {
				if (get_state(joint.name + "/enabled")) {
					if (can->sendMicroStepsCommand(stoi(joint.parameters["id"]),
								get_command(joint.name + "/mirco_steps")) !=
							CAN_OK) {
						mirco_steps_write_success = false;
					}
				}
			}

			if (mirco_steps_write_success) {
				write_micro_steps_enable =
						false;  // Disable writing after success
			} else {
				RCLCPP_ERROR(get_logger(), "Failed to send micro steps");
			}
		}

		// Write max effort
		if (write_max_effort_enable) {
			bool max_effort_write_success = true;
			for (auto joint : info_.joints) {
				if (get_state(joint.name + "/enabled")) {
					if (can->sendMaxEffortCommand(stoi(joint.parameters["id"]),
								get_command(joint.name + "/max_effort")) !=
							CAN_OK) {
						max_effort_write_success = false;
					}
				}
			}

			if (max_effort_write_success) {
				write_max_effort_enable = false;
			} else {
				RCLCPP_ERROR(get_logger(), "Failed to send max effort");
			}
		}
	}

	void NiryoOneHardwareCan::hardwareControlCheckConnection() {
		if (!is_can_connection_ok) {
			return;  // Don't check if connection is already lost
		}

		double time_now = get_clock()->now().seconds();
		if (hw_check_connection_frequency > 5.0) {
			hw_check_connection_frequency = 5.0;
		}

		double timeout_read = 1.0 / hw_check_connection_frequency;
		int max_fail_counter = (int) (hw_check_connection_frequency + 0.5);

		for (auto joint : info_.joints) {
			if (get_state(joint.name + "/enabled")) {
				if (time_now - get_state(joint.name + "/last_time_read") >
						timeout_read *
										get_state(joint.name +
												"/hw_fail_counter") +
								1) {
					RCLCPP_ERROR(get_logger(),
							"CAN connection problem with motor %d, hw fail "
							"counter: %f",
							stoi(joint.parameters["id"]),
							get_state(joint.name + "/hw_fail_counter"));
					if (get_state(joint.name + "/hw_fail_counter") >=
							max_fail_counter) {
						is_can_connection_ok = false;
						RCLCPP_ERROR(get_logger(),
								"Connection problem with CAN bus. "
								"Motor %d is not connected;",
								stoi(joint.parameters["id"]));
						return;
					}

					set_state(joint.name + "/hw_fail_counter",
							get_state(joint.name + "/hw_fail_counter") + 1);
				} else {
					set_state(joint.name + "/hw_fail_counter", 0);
				}
			}
		}
	}
}

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(niryo_one_hardware::NiryoOneHardwareCan,
		hardware_interface::SystemInterface);
