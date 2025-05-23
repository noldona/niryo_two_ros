#include "niryo_one_hardware/niryo_one_can_driver.hpp"

NiryoCanDriver::NiryoCanDriver(
		int spi_channel, int spi_baudrate, INT8U gpio_can_interrupt) {
	RCLCPP_INFO(rclcpp::get_logger("Niryo One Driver"),
			"Setting up CAN connection");
	mcp_can.reset(new MCP_CAN(spi_channel, spi_baudrate, gpio_can_interrupt));
}

bool NiryoCanDriver::setupInterruptGpio() {
	RCLCPP_INFO(rclcpp::get_logger("Niryo One Driver"), "Setting up CAN GPIO");
	if (!mcp_can->setupInterruptGpio()) {
		printf("Failed to start gpio");
		return CAN_GPIO_FAILINIT;
	}
	return CAN_OK;
}

bool NiryoCanDriver::setupSpi() {
	RCLCPP_INFO(rclcpp::get_logger("Niryo One Driver"), "Setting up SPI");
	if (!mcp_can->setupSpi()) {
		printf("Failed to start spi");
		return CAN_SPI_FAILINIT;
	}
	return CAN_OK;
}

INT8U NiryoCanDriver::init() {
	// no mask or filter used, receive all messages from CAN bus
	// messages with ids != motor_id will be sent to another ROS interface
	// so we can use many CAN devices with this only driver
	int result = mcp_can->begin(MCP_ANY, CAN_1000KBPS, MCP_16MHZ);
	RCLCPP_INFO(rclcpp::get_logger("Niryo One Can Driver"),
			"Result begin can : %d", result);

	if (result != CAN_OK) {
		RCLCPP_ERROR(rclcpp::get_logger("Niryo One Can Driver"),
				"Failed to init MCP2515 (CAN bus)");
		return result;
	}

	// set mode to normal
	mcp_can->setMode(MCP_NORMAL);

	rclcpp::sleep_for(std::chrono::milliseconds(50));
	return result;
}

bool NiryoCanDriver::canReadData() {
	return mcp_can->canReadData();
}

INT8U NiryoCanDriver::readMsgBuf(INT32U *id, INT8U *len, INT8U *buf) {
	return mcp_can->readMsgBuf(id, len, buf);
}

INT8U NiryoCanDriver::sendPositionCommand(int id, int cmd) {
	uint8_t data[4] = {CAN_CMD_POSITION, (uint8_t) ((cmd >> 16) & 0xFF),
			(uint8_t) ((cmd >> 8) & 0xFF), (uint8_t) (cmd & 0XFF)};
	return mcp_can->sendMsgBuf(id, 0, 4, data);
}

INT8U NiryoCanDriver::sendRelativeMoveCommand(int id, int steps, int delay) {
	uint8_t data[7] = {CAN_CMD_MOVE_REL, (uint8_t) ((steps >> 16) & 0xFF),
			(uint8_t) ((steps >> 8) & 0xFF), (uint8_t) (steps & 0XFF),
			(uint8_t) ((delay >> 16) & 0xFF), (uint8_t) ((delay >> 8) & 0xFF),
			(uint8_t) (delay & 0XFF)};
	return mcp_can->sendMsgBuf(id, 0, 7, data);
}

INT8U NiryoCanDriver::sendTorqueOnCommand(int id, int torque_on) {
	uint8_t data[2] = {0};
	data[0] = CAN_CMD_MODE;
	data[1] = (torque_on) ? STEPPER_CONTROL_MODE_STANDARD :
							STEPPER_CONTROL_MODE_RELAX;
	return mcp_can->sendMsgBuf(id, 0, 2, data);
}
INT8U NiryoCanDriver::sendConveyoOnCommand(
		int id, bool conveyor_on, int conveyor_speed, int8_t direction) {
	uint8_t data[4] = {0};
	data[0] = CAN_CMD_MODE;
	if (conveyor_on) {
		data[1] = STEPPER_CONVEYOR_ON;
	} else {
		data[1] = STEPPER_CONVEYOR_OFF;
	}
	data[2] = conveyor_speed;
	data[3] = direction;

	return mcp_can->sendMsgBuf(id, 0, 4, data);
}
INT8U NiryoCanDriver::sendUpdateConveyorId(uint8_t old_id, uint8_t new_id) {
	RCLCPP_ERROR(
			rclcpp::get_logger("Niryo One Can Driver"), "new id : %d", new_id);
	uint8_t data[3] = {0};
	data[0] = CAN_CMD_MODE;
	data[1] = CAN_UPDATE_CONVEYOR_ID;
	data[2] = new_id;
	return mcp_can->sendMsgBuf(old_id, 0, 3, data);
}

INT8U NiryoCanDriver::sendPositionOffsetCommand(
		int id, int cmd, int absolute_steps_at_offset_position) {
	uint8_t data[6] = {CAN_CMD_OFFSET, (uint8_t) ((cmd >> 16) & 0xFF),
			(uint8_t) ((cmd >> 8) & 0xFF), (uint8_t) (cmd & 0XFF),
			(uint8_t) ((absolute_steps_at_offset_position >> 8) & 0xFF),
			(uint8_t) (absolute_steps_at_offset_position & 0xFF)};
	return mcp_can->sendMsgBuf(id, 0, 6, data);
}

INT8U NiryoCanDriver::sendCalibrationCommand(
		int id, int offset, int delay, int direction, int timeout) {
	direction = (direction == 1) ? 1 : 0;

	uint8_t data[8] = {CAN_CMD_CALIBRATE, (uint8_t) ((offset >> 16) & 0xFF),
			(uint8_t) ((offset >> 8) & 0xFF), (uint8_t) (offset & 0XFF),
			(uint8_t) ((delay >> 8) & 0xFF), (uint8_t) (delay & 0xFF),
			(uint8_t) direction, (uint8_t) timeout};
	return mcp_can->sendMsgBuf(id, 0, 8, data);
}

INT8U NiryoCanDriver::sendSynchronizePositionCommand(int id, bool begin_traj) {
	uint8_t data[2] = {CAN_CMD_SYNCHRONIZE, (uint8_t) begin_traj};
	return mcp_can->sendMsgBuf(id, 0, 2, data);
}

INT8U NiryoCanDriver::sendMicroStepsCommand(int id, int micro_steps) {
	uint8_t data[2] = {CAN_CMD_MICRO_STEPS, (uint8_t) micro_steps};
	return mcp_can->sendMsgBuf(id, 0, 2, data);
}

INT8U NiryoCanDriver::sendMaxEffortCommand(int id, int effort) {
	uint8_t data[2] = {CAN_CMD_MAX_EFFORT, (uint8_t) effort};
	return mcp_can->sendMsgBuf(id, 0, 2, data);
}
