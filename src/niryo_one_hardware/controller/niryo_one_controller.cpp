#include "niryo_one_hardware/niryo_one_controller.hpp"
#include "niryo_one_hardware/utilities.hpp"

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
		// should have error handling
		can_joint_names_ = auto_declare<std::vector<std::string>>(
				"can_joints", can_joint_names_);
		can_command_interface_types_ = auto_declare<std::vector<std::string>>(
				"can_command_interfaces", can_command_interface_types_);
		can_state_interface_types_ = auto_declare<std::vector<std::string>>(
				"can_state_interfaces", can_state_interface_types_);

		dxl_joint_names_ = auto_declare<std::vector<std::string>>(
				"dxl_joints", dxl_joint_names_);
		dxl_command_interface_types_ = auto_declare<std::vector<std::string>>(
				"dxl_command_interfaces", dxl_command_interface_types_);
		dxl_state_interface_types_ = auto_declare<std::vector<std::string>>(
				"dxl_state_interfaces", dxl_state_interface_types_);

		point_interp_.positions.assign(
				can_joint_names_.size() + dxl_joint_names_.size(), 0);
		point_interp_.velocities.assign(
				can_joint_names_.size() + dxl_joint_names_.size(), 0);

		return CallbackReturn::SUCCESS;
	}

	controller_interface::InterfaceConfiguration
			NiryoOneController::command_interface_configuration() const {
		controller_interface::InterfaceConfiguration conf = {
				config_type::INDIVIDUAL, {}};

		conf.names.reserve((can_joint_names_.size() *
								   can_command_interface_types_.size()) +
				(dxl_joint_names_.size() *
						dxl_command_interface_types_.size()) +
				(command_interface_names.size()));

		// CAN motors
		for (const auto &joint_name : can_joint_names_) {
			for (const auto &interface_type : can_command_interface_types_) {
				conf.names.push_back(joint_name + "/" + interface_type);
			}
		}

		// DXL motors
		for (const auto &joint_name : dxl_joint_names_) {
			for (const auto &interface_type : dxl_command_interface_types_) {
				conf.names.push_back(joint_name + "/" + interface_type);
			}
		}

		for (std::map<CommandInterfaces, std::string>::iterator iter =
						command_interface_names.begin();
				iter != command_interface_names.end(); ++iter) {
			conf.names.push_back("niryo_one/can/" + iter->second);
		}

		for (std::map<CommandInterfaces, std::string>::iterator iter =
						command_interface_names.begin();
				iter != command_interface_names.end(); ++iter) {
			conf.names.push_back("niryo_one/dxl/" + iter->second);
		}

		return conf;
	}

	controller_interface::InterfaceConfiguration
			NiryoOneController::state_interface_configuration() const {
		controller_interface::InterfaceConfiguration conf = {
				config_type::INDIVIDUAL, {}};

		conf.names.reserve(
				(can_joint_names_.size() * can_state_interface_types_.size()) +
				(dxl_joint_names_.size() * dxl_state_interface_types_.size()) +
				(state_interface_names.size()));

		for (const auto &joint_name : can_joint_names_) {
			for (const auto &interface_type : can_state_interface_types_) {
				conf.names.push_back(joint_name + "/" + interface_type);
			}
		}

		for (const auto &joint_name : dxl_joint_names_) {
			for (const auto &interface_type : dxl_state_interface_types_) {
				conf.names.push_back(joint_name + "/" + interface_type);
			}
		}

		// for (std::map<StateInterfaces, std::string>::iterator iter =
		// 				state_interface_names.begin();
		// 		iter != state_interface_names.end(); ++iter) {
		// 	conf.names.push_back("niryo_one/" + iter->second);
		// }

		return conf;
	}

	controller_interface::CallbackReturn NiryoOneController::on_configure(
			const rclcpp_lifecycle::State &) {
		RCLCPP_INFO(get_node()->get_logger(),
				"Configuring controller... please wait...");

		createSubscribers();
		createPublishers();
		createServices();

		RCLCPP_INFO(get_node()->get_logger(),
				"Successfully configured controller!");

		return CallbackReturn::SUCCESS;
	}

	controller_interface::CallbackReturn NiryoOneController::on_activate(
			const rclcpp_lifecycle::State &) {
		RCLCPP_INFO(get_node()->get_logger(),
				"Activating controller... please wait...");

		// clear out vectors in case of restart
		joint_position_command_interface_.clear();
		joint_velocity_command_interface_.clear();
		joint_position_state_interface_.clear();
		joint_velocity_state_interface_.clear();

		// assign command interfaces
		for (auto &interface : command_interfaces_) {
			if (interface.get_prefix_name() == "niryo_one/can" ||
					interface.get_prefix_name() == "niryo_one/dxl") {
				command_interface_map_["niryo_one"]->push_back(interface);
			} else {
				command_interface_map_[interface.get_interface_name()]
						->push_back(interface);
			}
		}

		// assign state interfaces
		for (auto &interface : state_interfaces_) {
			state_interface_map_[interface.get_interface_name()]->push_back(
					interface);
		}

		RCLCPP_INFO(
				get_node()->get_logger(), "Successfully activated controller!");

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
			// RCLCPP_INFO(get_node()->get_logger(), "New message");
			trajectory_msg_ = *traj_msg_external_point_ptr_.readFromRT();
			joint_state_msg_ = *joint_msg_external_ptr_.readFromRT();
			start_time_ = time;
			new_msg_ = false;
		}

		if (trajectory_msg_ != nullptr) {
			// RCLCPP_INFO(get_node()->get_logger(), "Got trajectory");
			interpolate_trajectory_point(
					*trajectory_msg_, time - start_time_, point_interp_);
			for (size_t i = 0; i < joint_position_command_interface_.size();
					i++) {
				std::ignore =
						joint_position_command_interface_[i].get().set_value(
								point_interp_.positions[i]);
			}
			for (size_t i = 0; i < joint_velocity_command_interface_.size();
					i++) {
				std::ignore =
						joint_velocity_command_interface_[i].get().set_value(
								point_interp_.velocities[i]);
			}
		}

		if (joint_state_msg_ != nullptr) {
			// RCLCPP_INFO(get_node()->get_logger(), "Got joint state");
			for (size_t i = 0; i < joint_position_command_interface_.size();
					i++) {
				std::ignore =
						joint_position_command_interface_[i].get().set_value(
								joint_state_msg_->position[i]);
			}
		}

		return controller_interface::return_type::OK;
	}

	controller_interface::CallbackReturn NiryoOneController::on_deactivate(
			const rclcpp_lifecycle::State &) {
		release_interfaces();

		return CallbackReturn::SUCCESS;
	}

	template<typename T> bool NiryoOneController::waitForAsyncCommand(
			std::function<T(void)> get_value) {
		const auto maximum_retries = 10;
		int retries = 0;
		while (get_value() == ASYNC_WAITING) {
			RCLCPP_INFO(get_node()->get_logger(), "Retry: %d", retries);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			retries++;

			if (retries > maximum_retries) return false;
		}
		return true;
	}

	void NiryoOneController::createSubscribers() {
		auto joint_trajectory_callback =
				[this](std::shared_ptr<trajectory_msgs::msg::JointTrajectory>
								traj_msg) -> void {
			// RCLCPP_INFO(get_node()->get_logger(), "Received trajectory");
			traj_msg_external_point_ptr_.writeFromNonRT(traj_msg);
			new_msg_ = true;
		};
		joint_command_subscriber_ =
				get_node()
						->create_subscription<
								trajectory_msgs::msg::JointTrajectory>(
								"/niryo_one/joint_trajectory",
								rclcpp::SystemDefaultsQoS(),
								joint_trajectory_callback);

		auto joint_state_callback =
				[this](std::shared_ptr<sensor_msgs::msg::JointState> joint_msg)
				-> void {
			// RCLCPP_INFO(get_node()->get_logger(), "Received Joint State");
			joint_msg_external_ptr_.writeFromNonRT(joint_msg);
			new_msg_ = true;
		};
		joint_state_subscriber_ =
				get_node()->create_subscription<sensor_msgs::msg::JointState>(
						"/niryo_one/joint_states", rclcpp::SystemDefaultsQoS(),
						joint_state_callback);
	}

	void NiryoOneController::createPublishers() {}

	void NiryoOneController::createServices() {
		calibrate_motors_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"/niryo_one/calibrate_motors",
						std::bind(&NiryoOneController::callbackCalibrateMotors,
								this, std::placeholders::_1,
								std::placeholders::_2));
		request_new_calibration_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"/niryo_one/request_new_calibration",
						std::bind(&NiryoOneController::
										  callbackRequestNewCalibration,
								this, std::placeholders::_1,
								std::placeholders::_2));

		test_motors_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"/niryo_one/test_motors",
						std::bind(&NiryoOneController::callbackTestMotors, this,
								std::placeholders::_1, std::placeholders::_2));

		activate_learning_mode_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/activate_learning_mode",
						std::bind(&NiryoOneController::
										  callbackActivateLearningMode,
								this, std::placeholders::_1,
								std::placeholders::_2));
		activate_leds_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::SetLeds>(
						"niryo_one/set_dxl_leds",
						std::bind(&NiryoOneController::callbackActivateLeds,
								this, std::placeholders::_1,
								std::placeholders::_2));

		ping_and_set_dxl_tool_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::PingDxlTool>(
						"niryo_one/tools/ping_and_set_dxl_tool",
						std::bind(
								&NiryoOneController::callbackPingAndSetDxlTool,
								this, std::placeholders::_1,
								std::placeholders::_2));

		open_gripper_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::OpenGripper>(
						"niryo_one/tools/open_gripper",
						std::bind(&NiryoOneController::callbackOpenGripper,
								this, std::placeholders::_1,
								std::placeholders::_2));
		close_gripper_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::CloseGripper>(
						"niryo_one/tools/close_gripper",
						std::bind(&NiryoOneController::callbackCloseGripper,
								this, std::placeholders::_1,
								std::placeholders::_2));
		pull_air_vacuum_pump_srv_ =
				get_node()
						->create_service<
								niryo_one_msgs::srv::PullAirVacuumPump>(
								"niryo_one/tools/pull_air_vacuum_pump",
								std::bind(&NiryoOneController::
												  callbackPullAirVacuumPump,
										this, std::placeholders::_1,
										std::placeholders::_2));
		push_air_vacuum_pump_srv_ =
				get_node()
						->create_service<
								niryo_one_msgs::srv::PushAirVacuumPump>(
								"niryo_one/tools/push_air_vacuum_pump",
								std::bind(&NiryoOneController::
												  callbackPushAirVacuumPump,
										this, std::placeholders::_1,
										std::placeholders::_2));

		change_hardware_version_srv_ =
				get_node()
						->create_service<
								niryo_one_msgs::srv::ChangeHardwareVersion>(
								"niryo_one/change_hardware_version",
								std::bind(&NiryoOneController::
												  callbackChangeHardwareVersion,
										this, std::placeholders::_1,
										std::placeholders::_2));
		send_custom_dxl_value_srv_ =
				get_node()
						->create_service<
								niryo_one_msgs::srv::SendCustomDxlValue>(
								"niryo_one/send_custom_dxl_value",
								std::bind(&NiryoOneController::
												  callbackSendCustomDxlValue,
										this, std::placeholders::_1,
										std::placeholders::_2));
		reboot_motors_srv_ =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/reboot_motors",
						std::bind(&NiryoOneController::callbackRebootMotors,
								this, std::placeholders::_1,
								std::placeholders::_2));

		factory_reset_motor_srv =
				get_node()->create_service<niryo_one_msgs::srv::SetInt>(
						"niryo_one/factory_reset_motor",
						std::bind(
								&NiryoOneController::callbackFactoryResetMotor,
								this, std::placeholders::_1,
								std::placeholders::_2));
	}

	void NiryoOneController::callbackCalibrateMotors(
			const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
			niryo_one_msgs::srv::SetInt::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Calibrating motors");

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::CALIBRATE_MOTORS_RESPONSE_STATUS]
								.get()
								.set_value(ASYNC_WAITING);
		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::CALIBRATE_MOTORS_REQUEST_VALUE]
								.get()
								.set_value(req->value);

		if (!waitForAsyncCommand<double>([&]() -> double {
				return niryo_one_command_interface_
						[CommandInterfaces::CALIBRATE_MOTORS_RESPONSE_STATUS]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
			})) {
			RCLCPP_WARN(get_node()->get_logger(),
					"Could not verify that motors were calibrated");
		}

		res->status =
				niryo_one_command_interface_
						[CommandInterfaces::CALIBRATE_MOTORS_RESPONSE_STATUS]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
		if (res->status == 200) {
			res->message = "Calibration is starting";
		}

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::CALIBRATE_MOTORS_RESPONSE_STATUS]
								.get()
								.set_value(ASYNC_NONE);
	}

	void NiryoOneController::callbackRequestNewCalibration(
			const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
			niryo_one_msgs::srv::SetInt::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Requesting new calibration");

		auto async_res = niryo_one_msgs::srv::SetInt::Response();
		async_res.status = ASYNC_WAITING;
		auto async_res_ptr =
				std::make_shared<niryo_one_msgs::srv::SetInt::Response>(
						async_res);

		// std::ignore =
		// 		command_interfaces_
		// 				[CommandInterfaces::REQUEST_NEW_CALIBRATION_REQUEST]
		// 						.set_value<niryo_one_msgs::srv::SetInt::
		// 										Response::SharedPtr>(
		// 								async_res_ptr);
		// std::ignore =
		// 		command_interfaces_
		// 				[CommandInterfaces::REQUEST_NEW_CALIBRATION_RESPONSE]
		// 						.set_value<niryo_one_msgs::srv::SetInt::
		// 										Request::SharedPtr>(req);

		// if (!waitForAsyncCommand<
		// 			niryo_one_msgs::srv::SetInt::Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::SetInt::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::
		// 										REQUEST_NEW_CALIBRATION_RESPONSE]
		// 								.get_optional<
		// 										niryo_one_msgs::srv::SetInt::
		// 												Response::SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(),
		// 			"Could not verify that request for calibration was made");
		// }

		// res = command_interfaces_
		// 			  [CommandInterfaces::REQUEST_NEW_CALIBRATION_RESPONSE]
		// 					  .get_optional<niryo_one_msgs::srv::SetInt::
		// 									  Response::SharedPtr>()
		// 					  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::REQUEST_NEW_CALIBRATION_RESPONSE]
		// 		.set_value<niryo_one_msgs::srv::SetInt::Request::SharedPtr>(
		// 				nullptr);
	}

	void NiryoOneController::callbackTestMotors(
			const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
			niryo_one_msgs::srv::SetInt::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Testing motors");

		auto async_res = niryo_one_msgs::srv::SetInt::Response();
		async_res.status = ASYNC_WAITING;
		auto async_res_ptr =
				std::make_shared<niryo_one_msgs::srv::SetInt::Response>(
						async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::TEST_MOTORS_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::SetInt::Response::
		// 								SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::TEST_MOTORS_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::SetInt::Request::
		// 								SharedPtr>(req);

		// if (!waitForAsyncCommand<
		// 			niryo_one_msgs::srv::SetInt::Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::SetInt::Response::SharedPtr {
		// 				return command_interfaces_[CommandInterfaces::
		// 												   TEST_MOTORS_RESPONSE]
		// 						.get_optional<niryo_one_msgs::srv::SetInt::
		// 										Response::SharedPtr>()
		// 						.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(),
		// 			"Could not verify that motors were tested");
		// }

		// res = command_interfaces_[CommandInterfaces::TEST_MOTORS_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::SetInt::Response::
		// 							  SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::TEST_MOTORS_REQUEST]
		// 		.set_value<niryo_one_msgs::srv::SetInt::Request::SharedPtr>(
		// 				nullptr);
	}

	void NiryoOneController::callbackActivateLearningMode(
			const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
			niryo_one_msgs::srv::SetInt::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Activating learning mode");

		int dxl_offset = command_interface_names.size();

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS]
								.get()
								.set_value(ASYNC_WAITING);
		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_REQUEST_VALUE]
								.get()
								.set_value(req->value);

		if (!waitForAsyncCommand<double>([&]() -> double {
				return niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
			})) {
			RCLCPP_WARN(get_node()->get_logger(),
					"Could not verify that CAN activated learning mode");
		}

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.set_value(ASYNC_WAITING);
		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_REQUEST_VALUE +
								dxl_offset]
								.get()
								.set_value(req->value);

		if (!waitForAsyncCommand<double>([&]() -> double {
				return niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
			})) {
			RCLCPP_WARN(get_node()->get_logger(),
					"Could not verify that DXL activate learning mode");
		}

		int can_status =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
		int dxl_status =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);

		if (can_status == 200) {
			res->status = dxl_status;
		} else {
			res->status = can_status;
		}

		if (res->status == 400) {
			res->message = "You can't activate/deactivate learning mode during "
						   "motors calibration";
		} else if (res->status == 200) {
			res->message = (req->value) ? "Activating learning mode" :
										  "Deactivating learning mode";
		}

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS]
								.get()
								.set_value(ASYNC_NONE);
		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										ACTIVATE_LEARNING_MODE_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.set_value(ASYNC_NONE);
	}

	void NiryoOneController::callbackActivateLeds(
			const niryo_one_msgs::srv::SetLeds::Request::SharedPtr req,
			niryo_one_msgs::srv::SetLeds::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Activating LEDs");

		auto async_res = niryo_one_msgs::srv::SetLeds::Response();
		async_res.status = ASYNC_WAITING;
		auto async_res_ptr =
				std::make_shared<niryo_one_msgs::srv::SetLeds::Response>(
						async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::ACTIVATE_LEDS_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::SetLeds::Response::
		// 								SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::ACTIVATE_LEDS_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::SetLeds::Request::
		// 								SharedPtr>(req);

		// if (!waitForAsyncCommand<
		// 			niryo_one_msgs::srv::SetLeds::Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::SetLeds::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::ACTIVATE_LEDS_RESPONSE]
		// 								.get_optional<
		// 										niryo_one_msgs::srv::SetLeds::
		// 												Response::SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::ACTIVATE_LEDS_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::SetLeds::Response::
		// 							  SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::ACTIVATE_LEDS_REQUEST]
		// 		.set_value<niryo_one_msgs::srv::SetLeds::Request::SharedPtr>(
		// 				nullptr);
	}

	void NiryoOneController::callbackPingAndSetDxlTool(
			const niryo_one_msgs::srv::PingDxlTool::Request::SharedPtr req,
			niryo_one_msgs::srv::PingDxlTool::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Pinging and setting DXL tool");

		auto async_res = niryo_one_msgs::srv::PingDxlTool::Response();
		async_res.state = ASYNC_WAITING;
		auto async_res_ptr =
				std::make_shared<niryo_one_msgs::srv::PingDxlTool::Response>(
						async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::PING_DXL_TOOL_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::PingDxlTool::Response::
		// 								SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::PING_DXL_TOOL_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::PingDxlTool::Request::
		// 								SharedPtr>(req);

		// if (!waitForAsyncCommand<
		// 			niryo_one_msgs::srv::PingDxlTool::Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::PingDxlTool::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::PING_DXL_TOOL_RESPONSE]
		// 								.get_optional<niryo_one_msgs::srv::
		// 												PingDxlTool::Response::
		// 														SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::PING_DXL_TOOL_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::PingDxlTool::Response::
		// 							  SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::PING_DXL_TOOL_REQUEST]
		// 		.set_value<
		// 				niryo_one_msgs::srv::PingDxlTool::Request::SharedPtr>(
		// 				nullptr);
	}

	void NiryoOneController::callbackOpenGripper(
			const niryo_one_msgs::srv::OpenGripper::Request::SharedPtr req,
			niryo_one_msgs::srv::OpenGripper::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Testing motors");

		auto async_res = niryo_one_msgs::srv::OpenGripper::Response();
		async_res.state = ASYNC_WAITING;
		auto async_res_ptr =
				std::make_shared<niryo_one_msgs::srv::OpenGripper::Response>(
						async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::OPEN_GRIPPER_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::OpenGripper::Response::
		// 								SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::OPEN_GRIPPER_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::OpenGripper::Request::
		// 								SharedPtr>(req);

		// if (!waitForAsyncCommand<
		// 			niryo_one_msgs::srv::OpenGripper::Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::OpenGripper::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::OPEN_GRIPPER_RESPONSE]
		// 								.get_optional<niryo_one_msgs::srv::
		// 												OpenGripper::Response::
		// 														SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::OPEN_GRIPPER_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::OpenGripper::Response::
		// 							  SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::OPEN_GRIPPER_REQUEST]
		// 		.set_value<
		// 				niryo_one_msgs::srv::OpenGripper::Request::SharedPtr>(
		// 				nullptr);
	}

	void NiryoOneController::callbackCloseGripper(
			const niryo_one_msgs::srv::CloseGripper::Request::SharedPtr req,
			niryo_one_msgs::srv::CloseGripper::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Testing motors");

		auto async_res = niryo_one_msgs::srv::CloseGripper::Response();
		async_res.state = ASYNC_WAITING;
		auto async_res_ptr =
				std::make_shared<niryo_one_msgs::srv::CloseGripper::Response>(
						async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::CLOSE_GRIPPER_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::CloseGripper::Response::
		// 								SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::CLOSE_GRIPPER_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::CloseGripper::Request::
		// 								SharedPtr>(req);

		// if (!waitForAsyncCommand<
		// 			niryo_one_msgs::srv::CloseGripper::Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::CloseGripper::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::CLOSE_GRIPPER_RESPONSE]
		// 								.get_optional<niryo_one_msgs::srv::
		// 												CloseGripper::Response::
		// 														SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::CLOSE_GRIPPER_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::CloseGripper::
		// 							  Response::SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::CLOSE_GRIPPER_REQUEST]
		// 		.set_value<
		// 				niryo_one_msgs::srv::CloseGripper::Request::SharedPtr>(
		// 				nullptr);
	}

	void NiryoOneController::callbackPullAirVacuumPump(
			const niryo_one_msgs::srv::PullAirVacuumPump::Request::SharedPtr
					req,
			niryo_one_msgs::srv::PullAirVacuumPump::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Testing motors");

		auto async_res = niryo_one_msgs::srv::PullAirVacuumPump::Response();
		async_res.state = ASYNC_WAITING;
		auto async_res_ptr = std::make_shared<
				niryo_one_msgs::srv::PullAirVacuumPump::Response>(async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									PULL_AIR_VACUUM_PUMP_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::PullAirVacuumPump::
		// 								Response::SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									PULL_AIR_VACUUM_PUMP_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::PullAirVacuumPump::
		// 								Request::SharedPtr>(req);

		// if (!waitForAsyncCommand<niryo_one_msgs::srv::PullAirVacuumPump::
		// 					Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::PullAirVacuumPump::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::
		// 										PULL_AIR_VACUUM_PUMP_RESPONSE]
		// 								.get_optional<niryo_one_msgs::srv::
		// 												PullAirVacuumPump::Response::
		// 														SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::
		// 								  PULL_AIR_VACUUM_PUMP_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::PullAirVacuumPump::
		// 							  Response::SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::PULL_AIR_VACUUM_PUMP_REQUEST]
		// 		.set_value<niryo_one_msgs::srv::PullAirVacuumPump::Request::
		// 						SharedPtr>(nullptr);
	}

	void NiryoOneController::callbackPushAirVacuumPump(
			const niryo_one_msgs::srv::PushAirVacuumPump::Request::SharedPtr
					req,
			niryo_one_msgs::srv::PushAirVacuumPump::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Testing motors");

		auto async_res = niryo_one_msgs::srv::PushAirVacuumPump::Response();
		async_res.state = ASYNC_WAITING;
		auto async_res_ptr = std::make_shared<
				niryo_one_msgs::srv::PushAirVacuumPump::Response>(async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									PUSH_AIR_VACUUM_PUMP_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::PushAirVacuumPump::
		// 								Response::SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									PUSH_AIR_VACUUM_PUMP_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::PushAirVacuumPump::
		// 								Request::SharedPtr>(req);

		// if (!waitForAsyncCommand<niryo_one_msgs::srv::PushAirVacuumPump::
		// 					Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::PushAirVacuumPump::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::
		// 										PUSH_AIR_VACUUM_PUMP_RESPONSE]
		// 								.get_optional<niryo_one_msgs::srv::
		// 												PushAirVacuumPump::Response::
		// 														SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::
		// 								  PUSH_AIR_VACUUM_PUMP_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::PushAirVacuumPump::
		// 							  Response::SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::PUSH_AIR_VACUUM_PUMP_REQUEST]
		// 		.set_value<niryo_one_msgs::srv::PushAirVacuumPump::Request::
		// 						SharedPtr>(nullptr);
	}

	void NiryoOneController::callbackChangeHardwareVersion(
			const niryo_one_msgs::srv::ChangeHardwareVersion::Request::SharedPtr
					req,
			niryo_one_msgs::srv::ChangeHardwareVersion::Response::SharedPtr
					res) {
		RCLCPP_INFO(get_node()->get_logger(), "Testing motors");

		auto async_res = niryo_one_msgs::srv::ChangeHardwareVersion::Response();
		async_res.status = ASYNC_WAITING;
		auto async_res_ptr = std::make_shared<
				niryo_one_msgs::srv::ChangeHardwareVersion::Response>(
				async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									CHANGE_HANDWARE_VERSION_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::ChangeHardwareVersion::
		// 								Response::SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									CHANGE_HARDWARE_VERSION_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::ChangeHardwareVersion::
		// 								Request::SharedPtr>(req);

		// if (!waitForAsyncCommand<niryo_one_msgs::srv::ChangeHardwareVersion::
		// 					Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::ChangeHardwareVersion::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::
		// 										CHANGE_HANDWARE_VERSION_RESPONSE]
		// 								.get_optional<niryo_one_msgs::srv::
		// 												ChangeHardwareVersion::
		// 														Response::
		// 																SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::
		// 								  CHANGE_HANDWARE_VERSION_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::ChangeHardwareVersion::
		// 							  Response::SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::CHANGE_HARDWARE_VERSION_REQUEST]
		// 		.set_value<niryo_one_msgs::srv::ChangeHardwareVersion::Request::
		// 						SharedPtr>(nullptr);
	}

	void NiryoOneController::callbackSendCustomDxlValue(
			const niryo_one_msgs::srv::SendCustomDxlValue::Request::SharedPtr
					req,
			niryo_one_msgs::srv::SendCustomDxlValue::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Testing motors");

		auto async_res = niryo_one_msgs::srv::SendCustomDxlValue::Response();
		async_res.status = ASYNC_WAITING;
		auto async_res_ptr = std::make_shared<
				niryo_one_msgs::srv::SendCustomDxlValue::Response>(async_res);

		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									SEND_CUSTOM_DXL_VALUE_RESPONSE]
		// 				.set_value<niryo_one_msgs::srv::SendCustomDxlValue::
		// 								Response::SharedPtr>(async_res_ptr);
		// std::ignore =
		// 		command_interfaces_[CommandInterfaces::
		// 									SEND_CUSTOM_DXL_VALUE_REQUEST]
		// 				.set_value<niryo_one_msgs::srv::SendCustomDxlValue::
		// 								Request::SharedPtr>(req);

		// if (!waitForAsyncCommand<niryo_one_msgs::srv::SendCustomDxlValue::
		// 					Response::SharedPtr>(
		// 			[&]() -> niryo_one_msgs::srv::SendCustomDxlValue::Response::SharedPtr {
		// 				return command_interfaces_
		// 						[CommandInterfaces::
		// 										SEND_CUSTOM_DXL_VALUE_RESPONSE]
		// 								.get_optional<niryo_one_msgs::srv::
		// 												SendCustomDxlValue::Response::
		// 														SharedPtr>()
		// 								.value_or(async_res_ptr);
		// 			})) {
		// 	RCLCPP_WARN(get_node()->get_logger(), "Could not verify that ");
		// }

		// res = command_interfaces_[CommandInterfaces::
		// 								  SEND_CUSTOM_DXL_VALUE_RESPONSE]
		// 			  .get_optional<niryo_one_msgs::srv::SendCustomDxlValue::
		// 							  Response::SharedPtr>()
		// 			  .value_or(async_res_ptr);
		// command_interfaces_[CommandInterfaces::SEND_CUSTOM_DXL_VALUE_REQUEST]
		// 		.set_value<niryo_one_msgs::srv::SendCustomDxlValue::Request::
		// 						SharedPtr>(nullptr);
	}

	void NiryoOneController::callbackRebootMotors(
			const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
			niryo_one_msgs::srv::SetInt::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Rebooting motors");

		int dxl_offset = command_interface_names.size();

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::REBOOT_MOTORS_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.set_value(ASYNC_WAITING);
		std::ignore = niryo_one_command_interface_
							  [CommandInterfaces::REBOOT_MOTORS_REQUEST_VALUE +
									  dxl_offset]
									  .get()
									  .set_value(req->value);

		if (!waitForAsyncCommand<double>([&]() -> double {
				return niryo_one_command_interface_
						[CommandInterfaces::REBOOT_MOTORS_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
			})) {
			RCLCPP_WARN(get_node()->get_logger(),
					"Could not verify that motors were rebooted");
		}

		res->status =
				niryo_one_command_interface_
						[CommandInterfaces::REBOOT_MOTORS_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
		if (res->status == 200) {
			res->message = "OK";
		}

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::REBOOT_MOTORS_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.set_value(ASYNC_NONE);
	}

	void NiryoOneController::callbackFactoryResetMotor(
			const niryo_one_msgs::srv::SetInt::Request::SharedPtr req,
			niryo_one_msgs::srv::SetInt::Response::SharedPtr res) {
		RCLCPP_INFO(get_node()->get_logger(), "Factory resetting motor");

		int dxl_offset = command_interface_names.size();

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										FACTORY_RESET_MOTOR_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.set_value(ASYNC_WAITING);
		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::FACTORY_RESET_MOTOR_REQUEST_VALUE +
								dxl_offset]
								.get()
								.set_value(req->value);

		if (!waitForAsyncCommand<double>([&]() -> double {
				return niryo_one_command_interface_
						[CommandInterfaces::
										FACTORY_RESET_MOTOR_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
			})) {
			RCLCPP_WARN(get_node()->get_logger(),
					"Could not verify that motor was factory reset");
		}

		res->status =
				niryo_one_command_interface_
						[CommandInterfaces::
										FACTORY_RESET_MOTOR_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.get_optional<double>()
								.value_or(ASYNC_WAITING);
		if (res->status == 200) {
			res->message = "OK";
		}

		std::ignore =
				niryo_one_command_interface_
						[CommandInterfaces::
										FACTORY_RESET_MOTOR_RESPONSE_STATUS +
								dxl_offset]
								.get()
								.set_value(ASYNC_NONE);
	}

}  // namespace niryo_one

#include "pluginlib/class_list_macros.hpp"

PLUGINLIB_EXPORT_CLASS(niryo_one_hardware::NiryoOneController,
		controller_interface::ControllerInterface)
