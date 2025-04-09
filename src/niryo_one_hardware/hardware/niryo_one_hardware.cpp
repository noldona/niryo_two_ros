#include "niryo_one_hardware/niryo_one_hardware.hpp"
#include "niryo_one_hardware/utilities.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace niryo_one_hardware {
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
		cfg_.noc_cfg.can_enabled =
				stob(info_.hardware_parameters["can_enabled"]);  // ~can_enabled
		cfg_.noc_cfg.dxl_enabled =
				stob(info_.hardware_parameters["dxl_enabled"]);  // ~dxl_enabled

		// Can Communication config
		RCLCPP_INFO(get_logger(), "Getting Can Communication parameters");
		cfg_.noc_cfg.can_cfg.spi_channel =
				stoi(info_.hardware_parameters["spi_channel"]);  // ~spi_channel
		cfg_.noc_cfg.can_cfg.spi_baudrate = stoi(
				info_.hardware_parameters["spi_baudrate"]);  // ~spi_baudrate
		cfg_.noc_cfg.can_cfg.gpio_can_interrupt = stoi(info_.hardware_parameters
						["gpio_can_interrupt"]);  // ~gpio_can_interrupt

		// Dxl Communication config
		RCLCPP_INFO(get_logger(), "Getting Dxl Communication parameters");
		cfg_.noc_cfg.dxl_cfg.device_name =
				info_.hardware_parameters
						["device_name"];  // ~dxl_uart_device_name
		cfg_.noc_cfg.dxl_cfg.uart_baudrate = stoi(
				info_.hardware_parameters["uart_baudrate"]);  // ~dxl_baudrate

		if (!cfg_.use_sim) {
			if (cfg_.noc_cfg.can_enabled) {
				can.reset(new NiryoCanDriver(cfg_.noc_cfg.can_cfg.spi_channel,
						cfg_.noc_cfg.can_cfg.spi_baudrate,
						cfg_.noc_cfg.can_cfg.gpio_can_interrupt));
			}
		}

		can.reset(new NiryoCanDriver(cfg_.noc_cfg.can_cfg.spi_channel,
				cfg_.noc_cfg.can_cfg.spi_baudrate,
				cfg_.noc_cfg.can_cfg.gpio_can_interrupt));

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

		// if (!cfg_.use_sim) {
		// 	if (cfg_.noc_cfg.can_enabled) {
		// 		can->setupInterruptGpio();
		// 		can->setupSpi();
		// 		if (can->init() != 0) {
		// 			RCLCPP_ERROR(get_logger(), "Failed to initialize CAN");
		// 			return CallbackReturn::ERROR;
		// 		}
		// 	}
		// }

		RCLCPP_INFO(get_logger(), "Successfully configured!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_cleanup(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Cleaning up ...please wait...");

		RCLCPP_INFO(get_logger(), "Successfully cleaned up!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_activate(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Activating ...please wait...");

		// if (!cfg_.use_sim) {
		// 	if (cfg_.noc_cfg.can_enabled) {
		// 	}
		// }

		startup = false;

		RCLCPP_INFO(get_logger(), "Successfully activated!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_deactivate(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Deactivating ...please wait...");

		RCLCPP_INFO(get_logger(), "Successfully deactivated!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_shutdown(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Shutting down ...please wait...");

		RCLCPP_INFO(get_logger(), "Successfully shut down!");

		return CallbackReturn::SUCCESS;
	}

	CallbackReturn NiryoOneHardware::on_error(
			const rclcpp_lifecycle::State & /*previous_state*/) {
		RCLCPP_INFO(get_logger(), "Handling Error ...please wait...");

		RCLCPP_INFO(get_logger(), "Successfully handled error!");

		return CallbackReturn::SUCCESS;
	}

	return_type NiryoOneHardware::read(
			const rclcpp::Time & /*time*/, const rclcpp::Duration &period) {
		// double pos_to_read[6] = {0.0};

		// comm_->getCurrentPosition(pos_to_read);

		for (std::size_t i = 0; i < info_.joints.size(); ++i) {
			const auto name_vel = info_.joints[i].name + "/" +
					hardware_interface::HW_IF_VELOCITY;
			const auto name_pos = info_.joints[i].name + "/" +
					hardware_interface::HW_IF_POSITION;

			// If simulating, echo the commands back out as the state
			// if (cfg_.use_sim) {
			set_state(name_vel, get_command(name_vel));
			set_state(name_pos,
					get_state(name_pos) +
							get_state(name_vel) * period.seconds());
			// } else {
			// 	// 		double prev_pos = get_state(name_pos);
			// 	// 		set_state(name_pos, pos_to_read[i]);
			// 	// 		set_state(name_vel,
			// 	// 				(pos_to_read[i] - prev_pos) / period.seconds());
			// }
		}

		return return_type::OK;
	}

	return_type NiryoOneHardware::write(const rclcpp::Time & /*time*/,
			const rclcpp::Duration & /*period*/) {
		// if (!cfg_.use_sim) {
		// 	double pos_to_write[6] = {
		// 			get_command(info_.joints[0].name + "/" +
		// 					hardware_interface::HW_IF_POSITION),
		// 			get_command(info_.joints[1].name + "/" +
		// 					hardware_interface::HW_IF_POSITION),
		// 			get_command(info_.joints[2].name + "/" +
		// 					hardware_interface::HW_IF_POSITION),
		// 			get_command(info_.joints[3].name + "/" +
		// 					hardware_interface::HW_IF_POSITION),
		// 			get_command(info_.joints[4].name + "/" +
		// 					hardware_interface::HW_IF_POSITION),
		// 			get_command(info_.joints[5].name + "/" +
		// 					hardware_interface::HW_IF_POSITION)};
		// 	RCLCPP_INFO(get_logger(),
		// 			"Writing positions, J1: %d, J2: %d, J3: %d, J4: %d, J5: "
		// 			"%d, J6: %d",
		// 			pos_to_write[0], pos_to_write[1], pos_to_write[2],
		// 			pos_to_write[3], pos_to_write[4], pos_to_write[5]);

		// 	comm_->sendPositionToRobot(pos_to_write);
		// }

		return return_type::OK;
	}
}

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(niryo_one_hardware::NiryoOneHardware,
		hardware_interface::SystemInterface);
