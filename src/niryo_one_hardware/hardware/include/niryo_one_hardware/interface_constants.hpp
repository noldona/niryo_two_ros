#ifndef INTERFACE_CONSTANTS_H
#define INTERFACE_CONSTANTS_H

#include <map>
#include <string>
#include <vector>

namespace niryo_one_hardware {
	enum CommandInterfaces {
		CALIBRATE_MOTORS_REQUEST_VALUE = 0,
		CALIBRATE_MOTORS_RESPONSE_STATUS,
		CALIBRATE_MOTORS_RESPONSE_MSSAGE,
		ACTIVATE_LEARNING_MODE_REQUEST_VALUE,
		ACTIVATE_LEARNING_MODE_RESPONSE_STATUS,
		ACTIVATE_LEARNING_MODE_RESPONSE_MESSAGE,
	};

	extern std::map<CommandInterfaces, std::string> command_interface_names;

	enum StateInterfaces { LEARNING_MODE = 0 };

	extern std::map<StateInterfaces, std::string> state_interface_names;

	static constexpr double ASYNC_NONE = -1.0;
	static constexpr double ASYNC_WAITING = 2.0;
}  // namespace niryo_one_hardware

#endif
