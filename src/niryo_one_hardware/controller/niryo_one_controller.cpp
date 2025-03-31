#include "niryo_one_hardware/niryo_one_controller.hpp"

#include <algorithm>
#include <memory>
#include <stddef.h>
#include <string>
#include <vector>

#include "rclcpp/qos.hpp"
#include "rclcpp/time.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"

using config_type = controller_interface::interface_configuration_type;

namespace niryo_one_hardware {
	NiryoOneController::NiryoOneController():
		controller_interface::ControllerInterface() {}

	controller_interface::CallbackReturn NiryoOneController::on_init() {
		get_node()->declare_parameter(
				"image_version", rclcpp::PARAMETER_STRING);
		get_node()->declare_parameter("ros_version", rclcpp::PARAMETER_STRING);

		// should have error handling
		joint_names_ =
				auto_declare<std::vector<std::string>>("joints", joint_names_);
		command_interface_types_ = auto_declare<std::vector<std::string>>(
				"command_interfaces", command_interface_types_);
		state_interface_types_ = auto_declare<std::vector<std::string>>(
				"state_interfaces", state_interface_types_);
		gpio_names_ =
				auto_declare<std::vector<std::string>>("gpios", gpio_names_);
		gpio_interface_types_ = auto_declare<std::vector<std::string>>(
				"gpio_interfaces", gpio_interface_types_);

		point_interp_.positions.assign(joint_names_.size(), 0);
		point_interp_.velocities.assign(joint_names_.size(), 0);

		return CallbackReturn::SUCCESS;
	}

	controller_interface::InterfaceConfiguration
			NiryoOneController::command_interface_configuration() const {
		controller_interface::InterfaceConfiguration conf = {
				config_type::INDIVIDUAL, {}};

		conf.names.reserve(
				(joint_names_.size() * command_interface_types_.size()) +
				(gpio_names_.size() * gpio_interface_types_.size()));
		for (const auto &joint_name : joint_names_) {
			for (const auto &interface_type : command_interface_types_) {
				conf.names.push_back(joint_name + "/" + interface_type);
			}
		}
		for (const auto &gpio_name : gpio_names_) {
			for (const auto &interface_type : gpio_interface_types_) {
				conf.names.push_back(gpio_name + "/" + interface_type);
			}
		}

		return conf;
	}

	controller_interface::InterfaceConfiguration
			NiryoOneController::state_interface_configuration() const {
		controller_interface::InterfaceConfiguration conf = {
				config_type::INDIVIDUAL, {}};

		conf.names.reserve(joint_names_.size() * state_interface_types_.size());
		for (const auto &joint_name : joint_names_) {
			for (const auto &interface_type : state_interface_types_) {
				conf.names.push_back(joint_name + "/" + interface_type);
			}
		}

		return conf;
	}

	controller_interface::CallbackReturn NiryoOneController::on_configure(
			const rclcpp_lifecycle::State &) {
		auto callback = [this](const std::shared_ptr<
								trajectory_msgs::msg::JointTrajectory>
										traj_msg) -> void {
			traj_msg_external_point_ptr_.writeFromNonRT(traj_msg);
			RCLCPP_INFO(get_node()->get_logger(), "Recieved trajectory");
			new_msg_ = true;
		};
		joint_command_subscriber_ =
				get_node()
						->create_subscription<
								trajectory_msgs::msg::JointTrajectory>(
								"~/joint_trajectory",
								rclcpp::SystemDefaultsQoS(), callback);

		auto calibrate_motors_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SetInt::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::SetInt::Response>
								res) -> void {
			calibrate_motors_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Calibrate Motors request");
			new_msg_ = true;
		};
		calibrate_motors_server =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/calibrate_motors",
						calibrate_motors_callback);

		auto request_new_calibration_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SetInt::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::SetInt::Response>
								res) -> void {
			request_new_calibration_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Request New Calibration request");
			new_msg_ = true;
		};
		request_new_calibration_server =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/request_new_calibration",
						request_new_calibration_callback);

		auto test_motors_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SetInt::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::SetInt::Response>
								res) -> void {
			test_motors_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(
					get_node()->get_logger(), "Receieved Test Motors request");
			new_msg_ = true;
		};
		test_motors_server =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/test_motors", test_motors_callback);

		auto activate_learning_mode_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SetInt::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::SetInt::Response>
								res) -> void {
			activate_learning_mode_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Activate Learning Mode request");
			new_msg_ = true;
		};
		activate_learning_mode_server =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/activate_learning_mode",
						activate_learning_mode_callback);

		auto activate_leds_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SetLeds::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::SetLeds::Response>
								res) -> void {
			activate_leds_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Activate LEDs request");
			new_msg_ = true;
		};
		activate_leds_server =
				get_node()->create_service<niryo_one_msgs::srv::SetLeds>(
						"niryo_one/set_dxl_leds",
						activate_learning_mode_callback);

		auto ping_and_set_dxl_tool_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::PingDxlTool::Request>
								req,
						std::shared_ptr<
								niryo_one_msgs::srv::PingDxlTool::Response>
								res) -> void {
			ping_and_set_dxl_tool_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Ping and Set DXL Tool request");
			new_msg_ = true;
		};
		ping_and_set_dxl_tool_server =
				get_node()->create_service<niryo_one_msgs::srv::PingDxlTool>(
						"niryo_one/tools/ping_and_set_dxl_tool",
						ping_and_set_dxl_tool_callback);

		auto ping_and_set_stepper_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SetConveyor::Request>
								req,
						std::shared_ptr<
								niryo_one_msgs::srv::SetConveyor::Response>
								res) -> void {
			ping_and_set_stepper_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Ping and Set Stepper request");
			new_msg_ = true;
		};
		ping_and_set_stepper_server =
				get_node()->create_service<niryo_one_msgs::srv::SetConveyor>(
						"niryo_one/kits/ping_and_set_conveyor",
						ping_and_set_stepper_callback);

		auto control_conveyor_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::ControlConveyor::Request>
								req,
						std::shared_ptr<
								niryo_one_msgs::srv::ControlConveyor::Response>
								res) -> void {
			control_conveyor_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Control Conveyor request");
			new_msg_ = true;
		};
		control_conveyor_server =
				get_node()
						->create_service<niryo_one_msgs::srv::ControlConveyor>(
								"niryo_one/kits/control_conveyor",
								control_conveyor_callback);

		auto update_conveyor_id_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::UpdateConveyorId::Request>
								req,
						std::shared_ptr<
								niryo_one_msgs::srv::UpdateConveyorId::Response>
								res) -> void {
			update_conveyor_id_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Update Conveyor ID request");
			new_msg_ = true;
		};
		update_conveyor_id_server =
				get_node()
						->create_service<niryo_one_msgs::srv::UpdateConveyorId>(
								"niryo_one/kits/update_conveyor_id",
								update_conveyor_id_callback);

		auto open_gripper_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::OpenGripper::Request>
								req,
						std::shared_ptr<
								niryo_one_msgs::srv::OpenGripper::Response>
								res) -> void {
			open_gripper_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(
					get_node()->get_logger(), "Receieved Open Gripper request");
			new_msg_ = true;
		};
		open_gripper_server =
				get_node()->create_service<niryo_one_msgs::srv::OpenGripper>(
						"niryo_one/tools/open_gripper", open_gripper_callback);

		auto close_gripper_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::CloseGripper::Request>
								req,
						std::shared_ptr<
								niryo_one_msgs::srv::CloseGripper::Response>
								res) -> void {
			close_gripper_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Close Gripper request");
			new_msg_ = true;
		};
		close_gripper_server =
				get_node()->create_service<niryo_one_msgs::srv::CloseGripper>(
						"niryo_one/tools/close_gripper",
						close_gripper_callback);

		auto pull_air_vacuum_pump_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::PullAirVacuumPump::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump::
										Response>
								res) -> void {
			pull_air_vacuum_pump_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Pull Air Vacuum Pump request");
			new_msg_ = true;
		};
		pull_air_vacuum_pump_server =
				get_node()
						->create_service<
								niryo_one_msgs::srv::PullAirVacuumPump>(
								"niryo_one/tools/pull_air_vacuum_pump",
								pull_air_vacuum_pump_callback);

		auto push_air_vacuum_pump_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::PushAirVacuumPump::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::PushAirVacuumPump::
										Response>
								res) -> void {
			push_air_vacuum_pump_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Push Air Vacuum Pump request");
			new_msg_ = true;
		};
		push_air_vacuum_pump_server =
				get_node()
						->create_service<
								niryo_one_msgs::srv::PushAirVacuumPump>(
								"niryo_one/tools/push_air_vacuum_pump",
								push_air_vacuum_pump_callback);

		auto change_hardware_version_callback =
				[this](const std::shared_ptr<niryo_one_msgs::srv::
									   ChangeHardwareVersion::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::
										ChangeHardwareVersion::Response>
								res) -> void {
			change_hardware_version_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Change Hardware Version request");
			new_msg_ = true;
		};
		change_hardware_version_server =
				get_node()
						->create_service<
								niryo_one_msgs::srv::ChangeHardwareVersion>(
								"niryo_one/change_hardware_version",
								change_hardware_version_callback);

		auto send_custom_dxl_vaue_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SendCustomDxlValue::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::
										SendCustomDxlValue::Response>
								res) -> void {
			send_custom_dxl_value_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Send Custom DXL Value request");
			new_msg_ = true;
		};
		send_custom_dxl_value_server =
				get_node()
						->create_service<
								niryo_one_msgs::srv::SendCustomDxlValue>(
								"niryo_one/send_custom_dxl_value",
								send_custom_dxl_vaue_callback);

		auto reboot_motors_callback =
				[this](const std::shared_ptr<
							   niryo_one_msgs::srv::SetInt::Request>
								req,
						std::shared_ptr<niryo_one_msgs::srv::SetInt::Response>
								res) -> void {
			reboot_motors_external_ptr_.writeFromNonRT(req);
			RCLCPP_INFO(get_node()->get_logger(),
					"Receieved Reboot Motors request");
			new_msg_ = true;
		};
		reboot_motors_server =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/reboot_motors", reboot_motors_callback);

		return CallbackReturn::SUCCESS;
	}

	controller_interface::CallbackReturn NiryoOneController::on_activate(
			const rclcpp_lifecycle::State &) {
		// clear out vectors in case of restart
		joint_position_command_interface_.clear();
		joint_velocity_command_interface_.clear();
		joint_position_state_interface_.clear();
		joint_velocity_state_interface_.clear();
		gpio_command_interface_.clear();

		// assign command interfaces
		for (auto &interface : command_interfaces_) {
			command_interface_map_[interface.get_interface_name()]->push_back(
					interface);
		}

		// assign state interfaces
		for (auto &interface : state_interfaces_) {
			state_interface_map_[interface.get_interface_name()]->push_back(
					interface);
		}

		return CallbackReturn::SUCCESS;
	}

	void interpolate_point(
			const trajectory_msgs::msg::JointTrajectoryPoint &point_1,
			const trajectory_msgs::msg::JointTrajectoryPoint &point_2,
			trajectory_msgs::msg::JointTrajectoryPoint &point_interp,
			double delta) {
		for (size_t i = 0; i < point_1.positions.size(); i++) {
			point_interp.positions[i] = delta * point_2.positions[i] +
					(1.0 - delta) * point_2.positions[i];
		}
		for (size_t i = 0; i < point_1.positions.size(); i++) {
			point_interp.velocities[i] = delta * point_2.velocities[i] +
					(1.0 - delta) * point_2.velocities[i];
		}
	}

	void interpolate_trajectory_point(
			const trajectory_msgs::msg::JointTrajectory &traj_msg,
			const rclcpp::Duration &cur_time,
			trajectory_msgs::msg::JointTrajectoryPoint &point_interp) {
		double traj_len = traj_msg.points.size();
		auto last_time = traj_msg.points[traj_len - 1].time_from_start;
		double total_time = last_time.sec + last_time.nanosec * 1E-9;

		size_t ind = cur_time.seconds() * (traj_len / total_time);
		ind = std::min(static_cast<double>(ind), traj_len - 2);
		double delta = cur_time.seconds() - ind * (total_time / traj_len);
		interpolate_point(traj_msg.points[ind], traj_msg.points[ind + 1],
				point_interp, delta);
	}

	controller_interface::return_type NiryoOneController::update(
			const rclcpp::Time &time, const rclcpp::Duration & /*period*/) {
		if (new_msg_) {
			trajectory_msg_ = *traj_msg_external_point_ptr_.readFromRT();
			start_time_ = time;

			calibrate_motors_msg_ =
					*calibrate_motors_external_ptr_.readFromRT();
			request_new_calibration_msg_ =
					*request_new_calibration_external_ptr_.readFromRT();

			test_motors_msg_ = *test_motors_external_ptr_.readFromRT();

			activate_learning_mode_msg_ =
					*activate_learning_mode_external_ptr_.readFromRT();
			activate_leds_msg_ = *activate_leds_external_ptr_.readFromRT();

			ping_and_set_dxl_tool_msg_ =
					*ping_and_set_dxl_tool_external_ptr_.readFromRT();

			ping_and_set_stepper_msg_ =
					*ping_and_set_stepper_external_ptr_.readFromRT();
			control_conveyor_msg_ =
					*control_conveyor_external_ptr_.readFromRT();
			update_conveyor_id_msg_ =
					*update_conveyor_id_external_ptr_.readFromRT();

			open_gripper_msg_ = *open_gripper_external_ptr_.readFromRT();
			close_gripper_msg_ = *close_gripper_external_ptr_.readFromRT();
			pull_air_vacuum_pump_msg_ =
					*pull_air_vacuum_pump_external_ptr_.readFromRT();
			push_air_vacuum_pump_msg_ =
					*push_air_vacuum_pump_external_ptr_.readFromRT();

			change_hardware_version_msg_ =
					*change_hardware_version_external_ptr_.readFromRT();
			send_custom_dxl_value_msg_ =
					*send_custom_dxl_value_external_ptr_.readFromRT();
			reboot_motors_msg_ = *reboot_motors_external_ptr_.readFromRT();

			new_msg_ = false;
		}

		if (trajectory_msg_ != nullptr) {
			interpolate_trajectory_point(
					*trajectory_msg_, time - start_time_, point_interp_);
			for (size_t i = 0; i < joint_position_command_interface_.size();
					i++) {
				joint_position_command_interface_[i].get().set_value(
						point_interp_.positions[i]);
			}
			for (size_t i = 0; i < joint_velocity_command_interface_.size();
					i++) {
				joint_velocity_command_interface_[i].get().set_value(
						point_interp_.velocities[i]);
			}
		}

		if (calibrate_motors_msg_ != nullptr) {
			gpio_command_interface_[0].get().set_value(calibrate_motors_msg_);
		}

		return controller_interface::return_type::OK;
	}

	controller_interface::CallbackReturn NiryoOneController::on_deactivate(
			const rclcpp_lifecycle::State &) {
		release_interfaces();

		return CallbackReturn::SUCCESS;
	}
}  // namespace niryo_one

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(niryo_one_hardware::NiryoOneController,
		controller_interface::ControllerInterface)
