#include "niryo_one_hardware/niryo_one_hardware.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace niryo_one_hardware {
	bool stob(std::string str) {
		bool result;
		std::istringstream(str) >> std::boolalpha >> result;
		return result;
	}

	std::vector<int> stovi(std::string str, char delimiter = ',') {
		std::string s;
		std::vector<int> result;
		std::stringstream ss(str);
		while (getline(ss, s, delimiter)) {
			result.push_back(stoi(s));
		}
		return result;
	}

	CallbackReturn NiryoOneHardware::on_init(
			const hardware_interface::HardwareInfo &info) {
		if (hardware_interface::SystemInterface::on_init(info) !=
				CallbackReturn::SUCCESS) {
			return CallbackReturn::ERROR;
		}

		// Get hardware parameters
		RCLCPP_INFO(get_logger(), "Getting hardware parameters");
		cfg_.hardware_version = stoi(info_.hardware_parameters
						["hardware_version"]);  // /niryo_one/hardware_version
		cfg_.use_sim = stob(
				info_.hardware_parameters["use_sim"]);  // ~fake_communication

		// Fake communication config
		RCLCPP_INFO(get_logger(), "Getting Fake Communication parameters");
		cfg_.fc_cfg.pos_0 = stod(info_.hardware_parameters
						["stepper_1_home_position"]);  // /niryo_one/motors/stepper_1_home_position
		cfg_.fc_cfg.pos_1 = stod(info_.hardware_parameters
						["stepper_2_home_position"]);  // /niryo_one/motors/stepper_2_home_position
		cfg_.fc_cfg.pos_2 = stod(info_.hardware_parameters
						["stepper_3_home_position"]);  // /niryo_one/motors/stepper_3_home_position
		cfg_.fc_cfg.pos_3 = stod(info_.hardware_parameters
						["stepper_4_home_position"]);  // /niryo_one/motors/stepper_4_home_position

		// Niryo One Communication config
		RCLCPP_INFO(get_logger(), "Getting Niryo One Communication parameters");
		cfg_.noc_cfg.can_enabled =
				stob(info_.hardware_parameters["can_enabled"]);  // ~can_enabled
		cfg_.noc_cfg.dxl_enabled =
				stob(info_.hardware_parameters["dxl_enabled"]);  // ~dxl_enabled
		cfg_.noc_cfg.niryo_one_hw_check_connection_frequency = stod(
				info_.hardware_parameters
						["niryo_one_hw_check_connection_"
						 "frequency"]);  // ~niryo_one_hw_check_connection_frequency
		cfg_.noc_cfg.reboot = stob(info_.hardware_parameters
						["reboot"]);  // /niryo_one/reboot_when_auto_change_version

		// Can Communication config
		RCLCPP_INFO(get_logger(), "Getting Can Communication parameters");
		cfg_.noc_cfg.can_cfg.spi_channel =
				stoi(info_.hardware_parameters["spi_channel"]);  // ~spi_channel
		cfg_.noc_cfg.can_cfg.spi_baudrate = stoi(
				info_.hardware_parameters["spi_baudrate"]);  // ~spi_baudrate
		cfg_.noc_cfg.can_cfg.gpio_can_interrupt = stoi(info_.hardware_parameters
						["gpio_can_interrupt"]);  // ~gpio_can_interrupt
		cfg_.noc_cfg.can_cfg.hw_control_loop_frequency = stod(
				info_.hardware_parameters
						["can_hw_control_loop_frequency"]);  // ~can_hardware_control_loop_frequency
		cfg_.noc_cfg.can_cfg.hw_write_frequency = stod(info_.hardware_parameters
						["can_hw_write_frequency"]);  // ~can_hardware_write_frequency
		cfg_.noc_cfg.can_cfg.hw_check_connection_frequency = stod(
				info_.hardware_parameters
						["can_hw_check_connection_"
						 "frequency"]);  // ~can_hardware_check_connection_frequency
		cfg_.noc_cfg.can_cfg.calibration_timeout = stoi(
				info_.hardware_parameters
						["calibration_timeout"]);  // ~calibration_timeout
		cfg_.noc_cfg.can_cfg.required_steppers_ids = stovi(
				info_.hardware_parameters
						["required_steppers_ids"]);  // /niryo_one/motors/can_required_motors
		cfg_.noc_cfg.can_cfg.allowed_steppers_ids = stovi(
				info_.hardware_parameters
						["allowed_steppers_ids"]);  // /niryo_one/motors/can_authorized_motors
		cfg_.noc_cfg.can_cfg.gear_ratio_1 = stod(info_.hardware_parameters
						["gear_ratio_1"]);  // /niryo_one/motors/stepper_1_gear_ratio
		cfg_.noc_cfg.can_cfg.gear_ratio_2 = stod(info_.hardware_parameters
						["gear_ratio_2"]);  // /niryo_one/motors/stepper_2_gear_ratio
		cfg_.noc_cfg.can_cfg.gear_ratio_3 = stod(info_.hardware_parameters
						["gear_ratio_3"]);  // /niryo_one/motors/stepper_3_gear_ratio
		cfg_.noc_cfg.can_cfg.gear_ratio_4 = stod(info_.hardware_parameters
						["gear_ratio_4"]);  // /niryo_one/motors/stepper_4_gear_ratio
		cfg_.noc_cfg.can_cfg.gear_ratio_6 = stod(info_.hardware_parameters
						["gear_ratio_6"]);  // /niryo_one/motors/stepper_6_gear_ratio
		cfg_.noc_cfg.can_cfg.gear_ratio_7 = stod(info_.hardware_parameters
						["gear_ratio_7"]);  // /niryo_one/motors/stepper_7_gear_ratio
		cfg_.noc_cfg.can_cfg.home_position_1 = stod(info_.hardware_parameters
						["home_position_1"]);  // /niryo_one/motors/stepper_1_home_position
		cfg_.noc_cfg.can_cfg.home_position_2 = stod(info_.hardware_parameters
						["home_position_2"]);  // /niryo_one/motors/stepper_2_home_position
		cfg_.noc_cfg.can_cfg.home_position_3 = stod(info_.hardware_parameters
						["home_position_3"]);  // /niryo_one/motors/stepper_3_home_position
		cfg_.noc_cfg.can_cfg.home_position_4 = stod(info_.hardware_parameters
						["home_position_4"]);  // /niryo_one/motors/stepper_4_home_position
		cfg_.noc_cfg.can_cfg.offset_position_1 = stod(info_.hardware_parameters
						["offset_position_1"]);  // /niryo_one/motors/stepper_1_offset_position
		cfg_.noc_cfg.can_cfg.offset_position_2 = stod(info_.hardware_parameters
						["offset_position_2"]);  // /niryo_one/motors/stepper_2_offset_position
		cfg_.noc_cfg.can_cfg.offset_position_3 = stod(info_.hardware_parameters
						["offset_position_3"]);  // /niryo_one/motors/stepper_3_offset_position
		cfg_.noc_cfg.can_cfg.offset_position_4 = stod(info_.hardware_parameters
						["offset_position_4"]);  // /niryo_one/motors/stepper_4_offset_position
		cfg_.noc_cfg.can_cfg.direction_1 = stod(info_.hardware_parameters
						["direction_1"]);  // /niryo_one/motors/stepper_1_direction
		cfg_.noc_cfg.can_cfg.direction_2 = stod(info_.hardware_parameters
						["direction_2"]);  // /niryo_one/motors/stepper_2_direction
		cfg_.noc_cfg.can_cfg.direction_3 = stod(info_.hardware_parameters
						["direction_3"]);  // /niryo_one/motors/stepper_3_direction
		cfg_.noc_cfg.can_cfg.direction_4 = stod(info_.hardware_parameters
						["direction_4"]);  // /niryo_one/motors/stepper_4_direction
		cfg_.noc_cfg.can_cfg.max_effort_1 = stoi(info_.hardware_parameters
						["max_effort_1"]);  // /niryo_one/motors/stepper_1_max_effort
		cfg_.noc_cfg.can_cfg.max_effort_2 = stoi(info_.hardware_parameters
						["max_effort_2"]);  // /niryo_one/motors/stepper_2_max_effort
		cfg_.noc_cfg.can_cfg.max_effort_3 = stoi(info_.hardware_parameters
						["max_effort_3"]);  // /niryo_one/motors/stepper_3_max_effort
		cfg_.noc_cfg.can_cfg.max_effort_4 = stoi(info_.hardware_parameters
						["max_effort_4"]);  // /niryo_one/motors/stepper_4_max_effort
		cfg_.noc_cfg.can_cfg.max_effort_6 = stoi(info_.hardware_parameters
						["max_effort_6"]);  // /niryo_one/motors/stepper_6_max_effort
		cfg_.noc_cfg.can_cfg.max_effort_7 = stoi(info_.hardware_parameters
						["max_effort_7"]);  // /niryo_one/motors/stepper_7_max_effort

		// Dxl Communication config
		RCLCPP_INFO(get_logger(), "Getting Dxl Communication parameters");
		cfg_.noc_cfg.dxl_cfg.device_name =
				info_.hardware_parameters
						["device_name"];  // ~dxl_uart_device_name
		cfg_.noc_cfg.dxl_cfg.uart_baudrate = stoi(
				info_.hardware_parameters["uart_baudrate"]);  // ~dxl_baudrate
		cfg_.noc_cfg.dxl_cfg.hw_control_loop_frequency = stod(
				info_.hardware_parameters
						["dxl_hw_control_loop_frequency"]);  // ~dxl_hardware_control_loop_frequency
		cfg_.noc_cfg.dxl_cfg.hw_write_frequency = stod(info_.hardware_parameters
						["dxl_hw_write_frequency"]);  // ~dxl_hw_write_frequency
		cfg_.noc_cfg.dxl_cfg.hw_data_read_frequency = stod(
				info_.hardware_parameters
						["dxl_hw_data_read_frequency"]);  // ~dxl_hw_data_read_frequency
		cfg_.noc_cfg.dxl_cfg.hw_status_read_frequency = stod(
				info_.hardware_parameters
						["dxl_hw_status_read_frequency"]);  // ~dxl_hw_status_read_frequency
		cfg_.noc_cfg.dxl_cfg.required_dxl_ids = stovi(info_.hardware_parameters
						["required_dxl_ids"]);  // /niryo_one/motors/dxl_required_motors
		cfg_.noc_cfg.dxl_cfg.allowed_dxl_ids = stovi(info_.hardware_parameters
						["allowed_dxl_ids"]);  // /niryo_one/motors/dxl_authorized_motors

		if (cfg_.use_sim) {
			comm_.reset(
					new FakeCommunication(cfg_.hardware_version, cfg_.fc_cfg));
		} else {
			comm_.reset(new NiryoOneCommunication(
					cfg_.hardware_version, cfg_.noc_cfg));
		}

		startup = true;

		return hardware_interface::CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_configure(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Configuring ...please wait...");

		// // Reset values always when configuring hardware
		// for (const auto &[name, descr] : joint_state_interfaces_) {
		// 	set_state(name, 0.0);
		// }
		// for (const auto &[name, descr] : joint_command_interfaces_) {
		// 	set_command(name, 0.0);
		// }

		RCLCPP_INFO(get_logger(), "Successfully configured!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_cleanup(
			const rclcpp_lifecycle::State &previous_state) {
		RCLCPP_INFO(get_logger(), "Cleaning up ...please wait...");

		RCLCPP_INFO(get_logger(), "Successfully cleaned up!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_activate(
			const rclcpp_lifecycle::State &previous_state) {
		RCLCPP_INFO(get_logger(), "Activating ...please wait...");

		comm_->manageHardwareConnection();
		comm_->activateLearningMode(startup);
		startup = false;

		RCLCPP_INFO(get_logger(), "Successfully activated!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_deactivate(
			const rclcpp_lifecycle::State &previous_state) {
		RCLCPP_INFO(get_logger(), "Deactivating ...please wait...");

		comm_->stopHardwareControlLoop();

		RCLCPP_INFO(get_logger(), "Successfully deactivated!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_shutdown(
			const rclcpp_lifecycle::State &previous_state) {
		RCLCPP_INFO(get_logger(), "Shutting down ...please wait...");

		RCLCPP_INFO(get_logger(), "Successfully shut down!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_error(
			const rclcpp_lifecycle::State &previous_state) {
		RCLCPP_INFO(get_logger(), "Handling Error ...please wait...");

		RCLCPP_INFO(get_logger(), "Successfully handled error!");

		return CallbackReturn::SUCCESS;
	}

	return_type NiryoOneHardware::read(
			const rclcpp::Time & /*time*/, const rclcpp::Duration &period) {
		for (std::size_t i = 0; i < info_.joints.size(); ++i) {
			const auto name_vel = info_.joints[i].name + "/" +
					hardware_interface::HW_IF_VELOCITY;
			const auto name_pos = info_.joints[i].name + "/" +
					hardware_interface::HW_IF_POSITION;

			// If simulating, echo the commands back out as the state
			set_state(name_vel, get_command(name_vel));
			set_state(name_pos,
					get_state(name_pos) +
							get_state(name_vel) * period.seconds());
		}

		return return_type::OK;
	}

	return_type NiryoOneHardware::write(const rclcpp::Time & /*time*/,
			const rclcpp::Duration & /*period*/) {
		return return_type::OK;
	}
}

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(niryo_one_hardware::NiryoOneHardware,
		hardware_interface::SystemInterface)
