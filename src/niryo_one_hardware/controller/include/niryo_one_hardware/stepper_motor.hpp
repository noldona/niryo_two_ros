#ifndef NIRYO_STEPPER_MOTOR_H
#define NIRYO_STEPPER_MOTOR_H

#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>

#include "controller_interface/controller_interface.hpp"
#include "hardware_interface/types/hardware_interface_type_values.hpp"

#define CONVEYOR_STATE_SET_OK 200
#define CONVEYOR_STATE_SET_ERROR 400
#define CONVEYOR_UPDATE_ID_OK 200
#define CONVEYOR_UPDATE_ID_ERROR 400
#define CONVEYOR_CONTROL_OK 200
#define CONVEYOR_CONTROL_ERROR 400

class StepperMotor {
	public:
	StepperMotor(const std::string name, int id, double gear_ratio,
			double direction, int32_t home_position, int32_t offset_position,
			uint8_t micro_steps, uint8_t max_effort,
			std::reference_wrapper<hardware_interface::LoanedCommandInterface>
					cmd_pos_interface,
			std::reference_wrapper<hardware_interface::LoanedCommandInterface>
					cmd_vel_interface,
			std::reference_wrapper<hardware_interface::LoanedCommandInterface>
					cmd_torque_interface,
			std::reference_wrapper<hardware_interface::LoanedCommandInterface>
					cmd_micro_steps_interface,
			std::reference_wrapper<hardware_interface::LoanedCommandInterface>
					cmd_max_effort_interface,
			std::reference_wrapper<hardware_interface::LoanedStateInterface>
					state_pos_interface,
			std::reference_wrapper<hardware_interface::LoanedStateInterface>
					state_vel_interface,
			std::reference_wrapper<hardware_interface::LoanedStateInterface>
					state_torque_interface,
			std::reference_wrapper<hardware_interface::LoanedStateInterface>
					state_temperature_interface,
			std::reference_wrapper<hardware_interface::LoanedStateInterface>
					state_hw_error_interface):
		cmd_pos_interface_(cmd_pos_interface),
		cmd_vel_interface_(cmd_vel_interface),
		cmd_torque_interface_(cmd_torque_interface),
		cmd_micro_steps_interface_(cmd_micro_steps_interface),
		cmd_max_effort_interface_(cmd_max_effort_interface),
		state_pos_interface_(state_pos_interface),
		state_vel_interface_(state_vel_interface),
		state_torque_interface_(state_torque_interface),
		state_temperature_interface_(state_temperature_interface),
		state_hw_error_interface_(state_hw_error_interface) {
		this->name = name;
		this->id = id;
		this->gear_ratio = gear_ratio;
		this->direction = direction;
		this->home_position = home_position;
		this->offset_position = offset_position;

		is_enabled = false;

		time_last_read = 0.0;

		firmware_version = "0.0.0";
		conveyor_state = 0;
		resetState();
		resetCommand(micro_steps, max_effort);
	}

	void resetState() {
		hw_fail_counter = 0;
	}

	void resetCommand(uint8_t micro_steps, uint8_t max_effort) {
		cmd_pos_interface_.get().set_value((double) home_position);
		cmd_vel_interface_.get().set_value(0.0);
		cmd_torque_interface_.get().set_value(0.0);
		cmd_micro_steps_interface_.get().set_value((double) micro_steps);
		cmd_max_effort_interface_.get().set_value((double) max_effort);
	}

	// Motor properties
	int getId() {
		return id;
	}

	std::string getFirmwareVersion() {
		return firmware_version;
	}

	double getGearRatio() {
		return gear_ratio;
	}

	double getDirection() {
		return direction;
	}

	std::string getName() {
		return name;
	}

	bool isEnabled() {
		return is_enabled;
	}

	double getLastTimeRead() {
		return time_last_read;
	}

	int getHwFailCounter() {
		return hw_fail_counter;
	}

	int32_t getHomePosition() {
		return home_position;
	}

	int32_t getOffsetPosition() {
		return offset_position;
	}

	void setFirmwareVersion(std::string v) {
		firmware_version = v;
	}

	void setGearRatio(double ratio) {
		gear_ratio = ratio;
	}

	void setDirection(double dir) {
		direction = dir;
	}

	void enable() {
		is_enabled = true;
	}

	void disable() {
		is_enabled = false;
	}

	void setLastTimeRead(double t) {
		time_last_read = t;
	}

	void setHwFailCounter(int c) {
		hw_fail_counter = c;
	}

	// Getters - State
	int32_t getPositionState() {
		return (int32_t) state_pos_interface_.get().get_value();
	}

	int32_t getVelocityState() {
		return (int32_t) state_vel_interface_.get().get_value();
	}

	int32_t getTorqueState() {
		return (int32_t) state_torque_interface_.get().get_value();
	}

	int32_t getTemperatureState() {
		return (int32_t) state_temperature_interface_.get().get_value();
	}

	int32_t getHardwareErrorState() {
		return (int32_t) state_hw_error_interface_.get().get_value();
	}

	// Getters - Command
	int32_t getPositionCommand() {
		return cmd_pos_interface_.get().get_value();
	}

	int32_t getVelocityCommand() {
		return cmd_vel_interface_.get().get_value();
	}

	int32_t getTorqueCommand() {
		return cmd_torque_interface_.get().get_value();
	}

	uint8_t getMicroStepsCommand() {
		return cmd_micro_steps_interface_.get().get_value();
	}

	uint8_t getMaxEffortCommand() {
		return cmd_max_effort_interface_.get().get_value();
	}

	// Setters - Command
	void setPositionCommand(int32_t pos) {
		cmd_pos_interface_.get().set_value((double) pos);
	}

	void setVelocityCommand(int32_t vel) {
		cmd_vel_interface_.get().set_value((double) vel);
	}

	void setTorqueCommand(int32_t torque) {
		cmd_torque_interface_.get().set_value((double) torque);
	}

	void setMicroStepsCommand(uint8_t micro) {
		cmd_micro_steps_interface_.get().set_value((double) micro);
	}

	void setMaxEffortCommand(uint8_t max) {
		cmd_max_effort_interface_.get().set_value((double) max);
	}

	// Getter - Conveyor
	int getConveyorState() {
		return conveyor_state;
	}

	bool getConveyorControlState() {
		return conveyor_running;
	}

	int16_t getConveyorSpeed() {
		return conveyor_speed;
	}

	int8_t getConveyorDirection() {
		return conveyor_direction;
	}

	// Setter - Conveyor
	void setConveyorState(int state) {
		conveyor_state = state;
	}

	void setConveyorFeedback(bool running, int16_t speed, int8_t direction) {
		conveyor_running = running;
		conveyor_speed = speed;
		conveyor_direction = direction;
	}

	private:
	std::string name;
	int id;
	std::string firmware_version;
	double gear_ratio;
	int32_t offset_position;
	int32_t home_position;
	double direction;
	bool is_enabled;

	double time_last_read;  // Used for ping purpose
	int hw_fail_counter;  // Keeps consecutive ping failures

	int conveyor_state;
	bool conveyor_running = false;
	int16_t conveyor_speed = 0;
	int8_t conveyor_direction = 1;

	std::reference_wrapper<hardware_interface::LoanedCommandInterface>
			cmd_pos_interface_;
	std::reference_wrapper<hardware_interface::LoanedCommandInterface>
			cmd_vel_interface_;
	std::reference_wrapper<hardware_interface::LoanedCommandInterface>
			cmd_torque_interface_;
	std::reference_wrapper<hardware_interface::LoanedCommandInterface>
			cmd_micro_steps_interface_;
	std::reference_wrapper<hardware_interface::LoanedCommandInterface>
			cmd_max_effort_interface_;

	std::reference_wrapper<hardware_interface::LoanedStateInterface>
			state_pos_interface_;
	std::reference_wrapper<hardware_interface::LoanedStateInterface>
			state_vel_interface_;
	std::reference_wrapper<hardware_interface::LoanedStateInterface>
			state_torque_interface_;
	std::reference_wrapper<hardware_interface::LoanedStateInterface>
			state_temperature_interface_;
	std::reference_wrapper<hardware_interface::LoanedStateInterface>
			state_hw_error_interface_;
};

#endif
