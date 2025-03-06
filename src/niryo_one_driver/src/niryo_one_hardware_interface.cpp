#include "niryo_one_driver/niryo_one_hardware_interface.hpp"

NiryoOneHardwareInterface::NiryoOneHardwareInterface(
		CommunicationBase *niryo_one_comm) {
	comm = niryo_one_comm;
	RCLCPP_INFO(rclcpp::get_logger("NiryoOneHardwareInterface"),
			"Starting NiryoOne Hardware Interface...");

	std::vector<hardware_interface::StateInterface> state_interfaces;
	// connect and register joint state interface
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_1", hardware_interface::HW_IF_POSITION, &pos[0]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_1", hardware_interface::HW_IF_VELOCITY, &vel[0]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_1", hardware_interface::HW_IF_EFFORT, &eff[0]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_2", hardware_interface::HW_IF_POSITION, &pos[1]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_2", hardware_interface::HW_IF_VELOCITY, &vel[1]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_2", hardware_interface::HW_IF_EFFORT, &eff[1]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_3", hardware_interface::HW_IF_POSITION, &pos[2]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_3", hardware_interface::HW_IF_VELOCITY, &vel[2]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_3", hardware_interface::HW_IF_EFFORT, &eff[2]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_4", hardware_interface::HW_IF_POSITION, &pos[3]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_4", hardware_interface::HW_IF_VELOCITY, &vel[3]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_4", hardware_interface::HW_IF_EFFORT, &eff[3]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_5", hardware_interface::HW_IF_POSITION, &pos[4]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_5", hardware_interface::HW_IF_VELOCITY, &vel[4]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_5", hardware_interface::HW_IF_EFFORT, &eff[4]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_6", hardware_interface::HW_IF_POSITION, &pos[5]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_6", hardware_interface::HW_IF_VELOCITY, &vel[5]));
	state_interfaces.push_back(hardware_interface::StateInterface(
			"joint_6", hardware_interface::HW_IF_EFFORT, &eff[5]));

	this->joint_state_interface = std::move(state_interfaces);

	// connect and register joint position interface
	std::vector<hardware_interface::CommandInterface> cmd_interfaces;
	cmd_interfaces.push_back(hardware_interface::CommandInterface(
			"joint_1", hardware_interface::HW_IF_POSITION, &cmd[0]));
	cmd_interfaces.push_back(hardware_interface::CommandInterface(
			"joint_2", hardware_interface::HW_IF_POSITION, &cmd[1]));
	cmd_interfaces.push_back(hardware_interface::CommandInterface(
			"joint_3", hardware_interface::HW_IF_POSITION, &cmd[2]));
	cmd_interfaces.push_back(hardware_interface::CommandInterface(
			"joint_4", hardware_interface::HW_IF_POSITION, &cmd[3]));
	cmd_interfaces.push_back(hardware_interface::CommandInterface(
			"joint_5", hardware_interface::HW_IF_POSITION, &cmd[4]));
	cmd_interfaces.push_back(hardware_interface::CommandInterface(
			"joint_6", hardware_interface::HW_IF_POSITION, &cmd[5]));

	this->joint_position_interface = std::move(cmd_interfaces);

	RCLCPP_INFO(rclcpp::get_logger("NiryoOneHardwareInterface"),
			"Interfaces registered.");
}

void NiryoOneHardwareInterface::setCommandToCurrentPosition() {
	joint_position_interface.at(0).set_value(pos[0]);
	joint_position_interface.at(1).set_value(pos[1]);
	joint_position_interface.at(2).set_value(pos[2]);
	joint_position_interface.at(3).set_value(pos[3]);
	joint_position_interface.at(4).set_value(pos[4]);
	joint_position_interface.at(5).set_value(pos[5]);
}

hardware_interface::return_type NiryoOneHardwareInterface::read(
		const rclcpp::Time &time, const rclcpp::Duration &period) {
	//ROS_INFO("Read sensor values");

	double pos_to_read[6] = {0.0};

	comm->getCurrentPosition(pos_to_read);

	pos[0] = pos_to_read[0];
	pos[1] = pos_to_read[1];
	pos[2] = pos_to_read[2];
	pos[3] = pos_to_read[3];
	pos[4] = pos_to_read[4];
	pos[5] = pos_to_read[5];

	return hardware_interface::return_type::OK;
}

hardware_interface::return_type NiryoOneHardwareInterface::write(
		const rclcpp::Time &time, const rclcpp::Duration &period) {
	// for debugging
	//pos[0] = cmd[0];
	//pos[1] = cmd[1];
	//pos[2] = cmd[2];
	//pos[3] = cmd[3];
	//pos[4] = cmd[4];
	//pos[5] = cmd[5];

	comm->sendPositionToRobot(cmd);

	return hardware_interface::return_type::OK;
}
