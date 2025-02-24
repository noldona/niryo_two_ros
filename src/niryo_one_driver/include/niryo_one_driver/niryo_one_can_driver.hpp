#ifndef NIRYO_CAN_DRIVER_H
#define NIRYO_CAN_DRIVER_H

#include "mcp_can_rpi/mcp_can_rpi.h"
#include "rclcpp/rclcpp.hpp"
#include <memory>

#define CAN_CMD_POSITION 0x03
#define CAN_CMD_TORQUE 0x04
#define CAN_CMD_MODE 0x07
#define CAN_CMD_MICRO_STEPS 0x13
#define CAN_CMD_OFFSET 0x14
#define CAN_CMD_CALIBRATE 0x15
#define CAN_CMD_SYNCHRONIZE 0x16
#define CAN_CMD_MAX_EFFORT 0x17
#define CAN_CMD_MOVE_REL 0x18
#define CAN_CMD_RESET 0x19  // not yet implemented

#define CAN_DATA_CONVEYOR_STATE 0x07
#define CAN_DATA_POSITION 0x03
#define CAN_DATA_DIAGNOSTICS 0x08
#define CAN_DATA_CALIBRATION_RESULT 0x09
#define CAN_DATA_FIRMWARE_VERSION 0x10

#define STEPPER_CONTROL_MODE_RELAX 0
#define STEPPER_CONTROL_MODE_STANDARD 1
#define STEPPER_CONVEYOR_OFF 20
#define STEPPER_CONVEYOR_ON 21
#define CAN_UPDATE_CONVEYOR_ID 23
#define STEPPER_CONTROL_MODE_PID_POS 2
#define STEPPER_CONTROL_MODE_TORQUE 3

#define CAN_MODEL_NUMBER 10000

class NiryoCanDriver {
	private:
	std::shared_ptr<MCP_CAN> mcp_can;

	public:
	NiryoCanDriver(int spi_channel, int spi_baudrate, INT8U gpio_can_interrupt);

	bool setupInterruptGpio();
	bool setupSpi();
	INT8U init();
	bool canReadData();
	INT8U readMsgBuf(INT32U *id, INT8U *len, INT8U *buf);

	INT8U sendPositionCommand(int id, int cmd);
	INT8U sendRelativeMoveCommand(int id, int steps, int delay);
	INT8U sendTorqueOnCommand(int id, int torque_on);
	INT8U sendPositionOffsetCommand(
			int id, int cmd, int absolute_steps_at_offset_position);
	INT8U sendCalibrationCommand(
			int i, int offset, int delay, int direction, int timeout);
	INT8U sendSynchronizePositionCommand(int id, bool begin_traj);
	INT8U sendMicroStepsCommand(int id, int micro_steps);
	INT8U sendMaxEffortCommand(int id, int effort);
	// Conveyor functions
	INT8U sendConveyoOnCommand(
			int id, bool conveyor_on, int conveyor_speed, int8_t direction);
	INT8U sendUpdateConveyorId(uint8_t old_id, uint8_t new_id);
};

#endif
