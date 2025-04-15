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

		is_tool_connected = false;

		torque_on = 0;
		should_reboot_motors = false;

		// For hardware loop control
		hw_is_busy = false;
		hw_limited_mode = false;

		read_position_enable = true;
		read_velocity_enable = true;  // Not useful for now
		read_torque_enable = true;
		read_hw_status_enable = true;

		// Change these values according to the current loaded controller (position, velocity, or torque control)
		setControlMode(DXL_CONTROL_MODE_POSITION);
		write_led_enable = true;
		write_torque_on_enable = true;
		write_tool_enable = false;

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
					hardware_interface::InterfaceDescription("niryo_one", info);
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
				(position_rad * RADIAN_TO_DEGREE * (double) XL430_TOTAL_ANGLE) /
						(RADIAN_TO_DEGREE *
								(double) XL430_TOTAL_RANGE_POSITION));
	}

	void NiryoOneHardwareDxl::asyncThread() {
		async_thread_shutdown_ = false;
		while (!async_thread_shutdown_) {
			std::this_thread::sleep_for(std::chrono::nanoseconds(20000000));
		}
	}
}  // namespace niryo_one_hardware

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(niryo_one_hardware::NiryoOneHardwareDxl,
		hardware_interface::SystemInterface);
