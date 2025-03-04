#include "niryo_one_driver/ros_interface.hpp"

void RosInterface::init(CommunicationBase *niryo_one_comm,
		RpiDiagnostics *rpi_diagnostics, bool *flag_reset_controllers,
		bool learning_mode_on, int hardware_version) {
	this->comm = niryo_one_comm;
	this->rpi_diagnostics = rpi_diagnostics;
	this->learning_mode_on = learning_mode_on;
	this->flag_reset_controllers = flag_reset_controllers;
	this->hardware_version = hardware_version;
	this->last_connection_up_flag = true;

	this->declare_parameter("image_version", rclcpp::PARAMETER_STRING);
	this->declare_parameter("ros_version", rclcpp::PARAMETER_STRING);
	this->rpi_image_version =
			this->get_parameter("image_version").get_value<std::string>();
	this->ros_niryo_one_version =
			this->get_parameter("ros_version").get_value<std::string>();

	// Trim string
	this->rpi_image_version.erase(
			this->rpi_image_version.find_last_not_of(" \n\r\t") + 1);
	this->ros_niryo_one_version.erase(
			this->ros_niryo_one_version.find_last_not_of(" \n\r\t") + 1);

	RCLCPP_INFO(rclcpp::get_logger("RosInterface"), "Ros interface started.");

	this->startServiceServers();
	this->startPublishers();

	// This flag is used to know if learning mode can be deactivated
	this->calibration_needed = 0;
}

void RosInterface::callbackTestMotors(
		const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res) {
	if (this->motor_test_status == 1) {
		this->test_motor.stopTest();
		this->learning_mode_on = true;
		this->comm->activateLearningMode(this->learning_mode_on);
		return;
	}

	this->motor_test_status = 1;
	if (this->calibration_needed) {
		this->learning_mode_on = false;
		this->comm->activateLearningMode(this->learning_mode_on);

		int calibration_mode = 1;
		std::string result_message = "";
		int result = comm->allowMotorsCalibrationToStart(
				calibration_mode, result_message);

		rclcpp::sleep_for(std::chrono::seconds(1));
		while (calibration_in_progress) {
			rclcpp::sleep_for(std::chrono::milliseconds(50));
		}

		this->learning_mode_on = true;
		rclcpp::sleep_for(std::chrono::seconds(1));
	}

	this->learning_mode_on = false;
	this->comm->activateLearningMode(this->learning_mode_on);

	bool status = this->test_motor.runTest(req->value);

	this->learning_mode_on = true;
	this->comm->activateLearningMode(this->learning_mode_on);

	if (status) {
		this->motor_test_status = 0;
		res->status = 200;
		res->message = "Success";
		RCLCPP_INFO(this->get_logger(), "Motor debug has ended with success");
	} else {
		this->motor_test_status = -1;
		res->status = 400;
		res->message = "Fail";
		RCLCPP_ERROR(this->get_logger(), "Motor debug has ended with failure");
	}
}

void RosInterface::callbackCalibrateMotors(
		const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res) {
	int calibration_mode = req->value;
	std::string result_message = "";
	int result = comm->allowMotorsCalibrationToStart(
			calibration_mode, result_message);

	res->status = result;
	res->message = result_message;

	// Special case here
	// We set flag learning_mode_on, but we don't activate from here
	// learning_mode should be activated in comm, AFTER motors have been calibrated
	// --> This fixes an issue where motors will jump back to a previous cmd after being calibrated
	this->learning_mode_on = true;
}

void RosInterface::callbackRequestNewCalibration(
		const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res) {
	// 1. Activate learning mode
	this->learning_mode_on = true;

	this->comm->activateLearningMode(this->learning_mode_on);

	// publish one time
	std_msgs::msg::Bool msg;
	msg.data = this->learning_mode_on;
	learning_mode_publisher->publish(msg);

	// 2. Set calibration flag (user will have to validate for calibration to start)
	this->comm->requestNewCalibration();

	res->status = 200;
	res->message = "New calibration request has been made, you will be "
				   "requested to confirm it.";
}

/*
 * Deactivating learning mode (= activating motors) is possible only if motors are calibrated
 * Activating learning mode is also possible when waiting for calibration
 */
void RosInterface::callbackActivateLearningMode(
		const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res) {
	if (this->comm->isCalibrationInProgress()) {
		res->status = 400;
		res->message = "You can't activate/deactivate learning mode during "
					   "motors calibration";
		return;
	}

	if (this->calibration_needed == 1 ||
			!comm->isConnectionOk()) {  // if can or dxl is disconnected, only allow to activate learning mode
		this->learning_mode_on = true;
	} else {
		this->learning_mode_on = req->value;
	}

	// reset controller if learning mode -> OFF
	// we want motors to start where they physically are, not from the last command
	if (!this->learning_mode_on) {
		*(this->flag_reset_controllers) = true;
		rclcpp::sleep_for(std::chrono::milliseconds(50));
	}

	this->comm->activateLearningMode(this->learning_mode_on);

	// publish one time
	std_msgs::msg::Bool msg;
	msg.data = this->learning_mode_on;
	learning_mode_publisher->publish(msg);

	res->status = 200;
	res->message = (this->learning_mode_on) ? "Activating learning mode" :
											  "Deactivating learning mode";
}

void RosInterface::callbackActivateLeds(
		const std::shared_ptr<niryo_one_msgs::srv::SetLeds::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::SetLeds::Response> res) {
	std::vector<int> leds = req->values;
	std::string message = "";
	bool result = comm->setLeds(leds, message);

	res->status = (result) ? 200 : 400;
	res->message = message;
}

void RosInterface::callbackPingAndSetDxlTool(
		const std::shared_ptr<niryo_one_msgs::srv::PingDxlTool::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::PingDxlTool::Response> res) {
	res->state = comm->pingAndSetDxlTool(req->id, req->name);
}

void RosInterface::callbackPingAndSetConveyor(
		const std::shared_ptr<niryo_one_msgs::srv::SetConveyor::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::SetConveyor::Response> res) {
	std::string message = "";
	res->status = comm->pingAndSetConveyor(req->id, req->activate, message);
	res->message = message;
}

void RosInterface::callbackControlConveyor(
		const std::shared_ptr<niryo_one_msgs::srv::ControlConveyor::Request>
				req,
		std::shared_ptr<niryo_one_msgs::srv::ControlConveyor::Response> res) {
	std::string message = "";
	res->status = comm->moveConveyor(
			req->id, req->control_on, req->speed, req->direction, message);
	res->message = message;
}

void RosInterface::callbackUpdateIdConveyor(
		const std::shared_ptr<niryo_one_msgs::srv::UpdateConveyorId::Request>
				req,
		std::shared_ptr<niryo_one_msgs::srv::UpdateConveyorId::Response> res) {
	std::string message = "";
	res->status = comm->updateIdConveyor(req->old_id, req->new_id, message);
	res->message = message;
}

void RosInterface::callbackOpenGripper(
		const std::shared_ptr<niryo_one_msgs::srv::OpenGripper::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::OpenGripper::Response> res) {
	res->state = comm->openGripper(req->id, req->open_position, req->open_speed,
			req->open_hold_torque);
}

void RosInterface::callbackCloseGripper(
		const std::shared_ptr<niryo_one_msgs::srv::CloseGripper::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::CloseGripper::Response> res) {
	res->state = comm->closeGripper(req->id, req->close_position,
			req->close_speed, req->close_hold_torque, req->close_max_torque);
}

void RosInterface::callbackPullAirVacuumPump(
		const std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump::Request>
				req,
		std::shared_ptr<niryo_one_msgs::srv::PullAirVacuumPump::Response> res) {
	res->state = comm->pullAirVacuumPump(
			req->id, req->pull_air_position, req->pull_air_hold_torque);
}

void RosInterface::callbackPushAirVacuumPump(
		const std::shared_ptr<niryo_one_msgs::srv::PushAirVacuumPump::Request>
				req,
		std::shared_ptr<niryo_one_msgs::srv::PushAirVacuumPump::Response> res) {
	res->state = comm->pushAirVacuumPump(req->id, req->push_air_position);
}

void RosInterface::callbackChangeHardwareVersion(
		const std::shared_ptr<
				niryo_one_msgs::srv::ChangeHardwareVersion::Request>
				req,
		std::shared_ptr<niryo_one_msgs::srv::ChangeHardwareVersion::Response>
				res) {
	int result = change_hardware_version_and_reboot(
			shared_from_this(), req->old_version, req->new_version);
	if (result == CHANGE_HW_VERSION_OK) {
		res->status = 200;
		res->message = "Successfully changed hardware version.";
	} else if (result == CHANGE_HW_VERSION_FAIL) {
		res->status = 400;
		res->message = "Failed to change hardware version, please check "
					   "the ROS logs";
	} else if (result == CHANGE_HW_VERSION_NOT_ARM) {
		res->status = 400;
		res->message =
				"Not allowed to change hardware version on non-ARM system";
	}
}

void RosInterface::callbackSendCustomDxlValue(
		const std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue::Request>
				req,
		std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue::Response>
				res) {
	// pre-check motor type
	if (req->motor_type != 1 && req->motor_type != 2) {
		res->status = 400;
		res->message = "Invalid motor type: should be 1 (XL-320) or 2 (XL-430)";
		return;
	}

	this->comm->addCustomDxlCommand(req->motor_type, req->id, req->value,
			req->reg_address, req->byte_number);

	res->status = 200;
	res->message = "OK";
}

void RosInterface::callbackRebootMotors(
		const std::shared_ptr<niryo_one_msgs::srv::SetInt::Request> req,
		std::shared_ptr<niryo_one_msgs::srv::SetInt::Response> res) {
	this->comm->rebootMotors();
	res->status = 200;
	res->message = "OK";
}

void RosInterface::startServiceServers() {
	this->calibrate_motors_server =
			this->create_service<niryo_one_msgs::srv::SetInt>(
					"niryo_one/calibrate_motors",
					std::bind(&RosInterface::callbackCalibrateMotors, this,
							std::placeholders::_1, std::placeholders::_2));
	this->request_new_calibration_server =
			this->create_service<niryo_one_msgs::srv::SetInt>(
					"niryo_one/request_new_calibration",
					std::bind(&RosInterface::callbackRequestNewCalibration,
							this, std::placeholders::_1,
							std::placeholders::_2));

	this->test_motors_server =
			this->create_service<niryo_one_msgs::srv::SetInt>(
					"niryo_one/test_motors",
					std::bind(&RosInterface::callbackTestMotors, this,
							std::placeholders::_1, std::placeholders::_2));

	this->activate_learning_mode_server =
			this->create_service<niryo_one_msgs::srv::SetInt>(
					"niryo_one/activate_learning_mode",
					std::bind(&RosInterface::callbackActivateLearningMode, this,
							std::placeholders::_1, std::placeholders::_2));
	this->activate_leds_server =
			this->create_service<niryo_one_msgs::srv::SetLeds>(
					"niryo_one/activate_leds",
					std::bind(&RosInterface::callbackActivateLeds, this,
							std::placeholders::_1, std::placeholders::_2));

	this->ping_and_set_dxl_tool_server =
			this->create_service<niryo_one_msgs::srv::PingDxlTool>(
					"niryo_one/tools/ping_and_set_dxl_tool",
					std::bind(&RosInterface::callbackPingAndSetDxlTool, this,
							std::placeholders::_1, std::placeholders::_2));

	// steppers service test
	this->ping_and_set_stepper_server =
			this->create_service<niryo_one_msgs::srv::SetConveyor>(
					"niryo_one/tools/ping_and_set_conveyor",
					std::bind(&RosInterface::callbackPingAndSetConveyor, this,
							std::placeholders::_1, std::placeholders::_2));
	this->control_conveyor_server =
			this->create_service<niryo_one_msgs::srv::ControlConveyor>(
					"niryo_one/kits/control_conveyor",
					std::bind(&RosInterface::callbackControlConveyor, this,
							std::placeholders::_1, std::placeholders::_2));
	this->update_conveyor_id_server =
			this->create_service<niryo_one_msgs::srv::UpdateConveyorId>(
					"niryo_one/kits/update_conveyor_id",
					std::bind(&RosInterface::callbackUpdateIdConveyor, this,
							std::placeholders::_1, std::placeholders::_2));

	this->open_gripper_server =
			this->create_service<niryo_one_msgs::srv::OpenGripper>(
					"niryo_one/tools/open_gripper",
					std::bind(&RosInterface::callbackOpenGripper, this,
							std::placeholders::_1, std::placeholders::_2));
	this->close_gripper_server =
			this->create_service<niryo_one_msgs::srv::CloseGripper>(
					"niryo_one/tools/close_gripper",
					std::bind(&RosInterface::callbackCloseGripper, this,
							std::placeholders::_1, std::placeholders::_2));
	this->pull_air_vacuum_pump_server =
			this->create_service<niryo_one_msgs::srv::PullAirVacuumPump>(
					"niryo_one/tools/pull_air_vacuum_pump",
					std::bind(&RosInterface::callbackPullAirVacuumPump, this,
							std::placeholders::_1, std::placeholders::_2));
	this->push_air_vacuum_pump_server =
			this->create_service<niryo_one_msgs::srv::PushAirVacuumPump>(
					"niryo_one/tools/push_air_vacuum_pump",
					std::bind(&RosInterface::callbackPushAirVacuumPump, this,
							std::placeholders::_1, std::placeholders::_2));

	this->change_hardware_version_server =
			this->create_service<niryo_one_msgs::srv::ChangeHardwareVersion>(
					"niryo_one/change_hardware_version",
					std::bind(&RosInterface::callbackChangeHardwareVersion,
							this, std::placeholders::_1,
							std::placeholders::_2));
	this->send_custom_dxl_value_server =
			this->create_service<niryo_one_msgs::srv::SendCustomDxlValue>(
					"niryo_one/send_custom_dxl_value",
					std::bind(&RosInterface::callbackSendCustomDxlValue, this,
							std::placeholders::_1, std::placeholders::_2));
	this->reboot_motors_server =
			this->create_service<niryo_one_msgs::srv::SetInt>(
					"niryo_one/reboot_motors",
					std::bind(&RosInterface::callbackRebootMotors, this,
							std::placeholders::_1, std::placeholders::_2));
}

void RosInterface::publishHardwareStatus() {
	this->declare_parameter(
			"publish_hw_status_frequency", rclcpp::PARAMETER_DOUBLE);
	double publish_hw_status_frequency =
			this->get_parameter("publish_hw_status_frequency").as_double();
	rclcpp::Rate publish_hardware_status_rate =
			rclcpp::Rate(publish_hw_status_frequency);

	while (rclcpp::ok()) {
		rclcpp::Time time_now = this->now();

		bool connection_up = false;

		std::string error_message;
		std::vector<std::string> motor_names;
		std::vector<std::string> motor_types;
		std::vector<int32_t> temperatures;
		std::vector<double> voltages;
		std::vector<int32_t> hw_errors;

		this->comm->getHardwareStatus(&connection_up, error_message,
				&this->calibration_needed, &this->calibration_in_progress,
				motor_names, motor_types, temperatures, voltages, hw_errors);

		if (connection_up && !this->last_connection_up_flag) {
			this->learning_mode_on = true;
			this->comm->activateLearningMode(this->learning_mode_on);

			// publish one time
			std_msgs::msg::Bool msg;
			msg.data = this->learning_mode_on;
			learning_mode_publisher->publish(msg);
		}
		this->last_connection_up_flag = connection_up;

		niryo_one_msgs::msg::HardwareStatus msg;
		msg.header.stamp = this->now();
		msg.rpi_temperature = this->rpi_diagnostics->getRpiCpuTemperature();
		msg.hardware_version = this->hardware_version;
		msg.connection_up = connection_up;
		if (this->motor_test_status < 0) {
			error_message += " motor test error";
		}
		msg.error_message = error_message;
		msg.calibration_needed = this->calibration_needed;
		msg.calibration_in_progress = this->calibration_in_progress;
		msg.motor_names = motor_names;
		msg.motor_types = motor_types;
		msg.temperatures = temperatures;
		msg.voltages = voltages;
		msg.hardware_errors = hw_errors;

		hardware_status_publisher->publish(msg);

		publish_hardware_status_rate.sleep();
	}
}

void RosInterface::publishSoftwareVersion() {
	this->declare_parameter(
			"publish_software_version_frequency", rclcpp::PARAMETER_DOUBLE);
	double publish_software_version_frequency =
			this->get_parameter("publish_software_version_frequency")
					.as_double();
	rclcpp::Rate publish_software_version_rate =
			rclcpp::Rate(publish_software_version_frequency);

	while (rclcpp::ok()) {
		std::vector<std::string> motor_names;
		std::vector<std::string> firmware_versions;
		this->comm->getFirmwareVersions(motor_names, firmware_versions);

		niryo_one_msgs::msg::SoftwareVersion msg;
		msg.motor_names = motor_names;
		msg.stepper_firmware_versions = firmware_versions;
		msg.rpi_image_version = this->rpi_image_version;
		msg.ros_niryo_one_version = this->ros_niryo_one_version;

		software_version_publisher->publish(msg);
		publish_software_version_rate.sleep();
	}
}

void RosInterface::publishLearningMode() {
	this->declare_parameter(
			"publish_learning_mode_frequency", rclcpp::PARAMETER_DOUBLE);
	double publish_learning_mode_frequency =
			this->get_parameter("publish_learning_mode_frequency").as_double();
	rclcpp::Rate publish_learning_mode_rate =
			rclcpp::Rate(publish_learning_mode_frequency);

	while (rclcpp::ok()) {
		std_msgs::msg::Bool msg;
		msg.data = this->learning_mode_on;
		learning_mode_publisher->publish(msg);
		publish_learning_mode_rate.sleep();
	}
}

void RosInterface::publishConveyor1Feedback() {
	double publish_conveyor_feedback_frequency = 2.0;
	rclcpp::Rate publish_conveyor_feedback_rate =
			rclcpp::Rate(publish_conveyor_feedback_frequency);

	while (rclcpp::ok()) {
		niryo_one_msgs::msg::ConveyorFeedback msg;
		bool connection_state;
		bool running;
		int16_t speed;
		int8_t direction;
		this->comm->getConveyorFeedBack(
				6, &connection_state, &running, &speed, &direction);
		msg.conveyor_id = 6;
		msg.connection_state = connection_state;
		msg.running = running;
		msg.speed = speed;
		msg.direction = direction;

		conveyor_1_feedback_publisher->publish(msg);
		publish_conveyor_feedback_rate.sleep();
	}
}

void RosInterface::publishConveyor2Feedback() {
	double publish_conveyor_feedback_frequency = 2.0;
	rclcpp::Rate publish_conveyor_feedback_rate =
			rclcpp::Rate(publish_conveyor_feedback_frequency);

	while (rclcpp::ok()) {
		niryo_one_msgs::msg::ConveyorFeedback msg;
		bool connection_state;
		bool running;
		int16_t speed;
		int8_t direction;
		this->comm->getConveyorFeedBack(
				7, &connection_state, &running, &speed, &direction);
		msg.conveyor_id = 7;
		msg.connection_state = connection_state;
		msg.running = running;
		msg.speed = speed;
		msg.direction = direction;

		this->conveyor_2_feedback_publisher->publish(msg);
		publish_conveyor_feedback_rate.sleep();
	}
}

void RosInterface::startPublishers() {
	this->hardware_status_publisher =
			this->create_publisher<niryo_one_msgs::msg::HardwareStatus>(
					"niryo_one/hardware_status", 10);
	this->publish_hardware_status_thread.reset(new std::thread(
			std::bind(&RosInterface::publishHardwareStatus, this)));

	this->software_version_publisher =
			this->create_publisher<niryo_one_msgs::msg::SoftwareVersion>(
					"niryo_one/software_version", 10);
	this->publish_software_version_thread.reset(new std::thread(
			std::bind(&RosInterface::publishSoftwareVersion, this)));

	this->learning_mode_publisher = this->create_publisher<std_msgs::msg::Bool>(
			"niryo_one/learning_mode", 10);
	this->publish_learning_mode_thread.reset(new std::thread(
			std::bind(&RosInterface::publishLearningMode, this)));

	this->conveyor_1_feedback_publisher =
			this->create_publisher<niryo_one_msgs::msg::ConveyorFeedback>(
					"niryo_one/kits/conveyor_1_feedback", 10);
	this->publish_conveyor_1_feedback_thread.reset(new std::thread(
			std::bind(&RosInterface::publishConveyor1Feedback, this)));

	this->conveyor_2_feedback_publisher =
			this->create_publisher<niryo_one_msgs::msg::ConveyorFeedback>(
					"niryo_one/kits/conveyor_2_feedback", 10);
	this->publish_conveyor_2_feedback_thread.reset(new std::thread(
			std::bind(&RosInterface::publishConveyor2Feedback, this)));
}
