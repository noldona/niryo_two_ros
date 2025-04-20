#include "niryo_one_hardware/interface_constants.hpp"

namespace niryo_one_hardware {
	std::map<CommandInterfaces, std::string> command_interface_names = {
			{CommandInterfaces::CALIBRATE_MOTORS_REQUEST_VALUE,
					"calibrate_motors_request_value"},
			{CommandInterfaces::CALIBRATE_MOTORS_RESPONSE_STATUS,
					"calibrate_motors_response_status"},
			{CommandInterfaces::CALIBRATE_MOTORS_RESPONSE_MSSAGE,
					"calibrate_motors_response_message"},
			{CommandInterfaces::ACTIVATE_LEARNING_MODE_REQUEST_VALUE,
					"activate_learning_mode_request_value"},
			{CommandInterfaces::ACTIVATE_LEARNING_MODE_RESPONSE_STATUS,
					"activate_learning_mode_response_status"},
			{CommandInterfaces::ACTIVATE_LEARNING_MODE_RESPONSE_MESSAGE,
					"activate_learning_mode_response_message"}};

	std::map<StateInterfaces, std::string> state_interface_names = {
			{StateInterfaces::LEARNING_MODE, "learning_mode"}};
}  // namespace niryo_one_hardware
