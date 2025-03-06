#ifndef NIRYO_HARDWARE_INTERFACE_H
#define NIRYO_HARDWARE_INTERFACE_H

#include <memory>
// #include <hardware_interface/command_interface.hpp>
// #include <hardware_interface/state_interface.hpp>
#include <hardware_interface/resource_manager.hpp>
#include <hardware_interface/system_interface.hpp>
#include <rclcpp/rclcpp.hpp>

#include "niryo_one_driver/communication_base.hpp"

class NiryoOneHardwareResourceManager:
	public hardware_interface::ResourceManager {
	public:
	NiryoOneHardwareResourceManager(
			rclcpp::node_interfaces::NodeClockInterface::SharedPtr
					clock_interface,
			rclcpp::node_interfaces::NodeLoggingInterface::SharedPtr
					logger_interface):
		hardware_interface::ResourceManager(clock_interface, logger_interface) {
	}

	bool shutdown_components() {
		return true;
	}

	private:
};

class NiryoOneHardwareInterface: public hardware_interface::SystemInterface {
	public:
	NiryoOneHardwareInterface(CommunicationBase *niryo_one_comm);

	hardware_interface::return_type read(
			const rclcpp::Time &time, const rclcpp::Duration &period);

	hardware_interface::return_type write(
			const rclcpp::Time &time, const rclcpp::Duration &period);

	// custom
	void setCommandToCurrentPosition();
	bool shutdown_components() {
		return true;
	}

	private:
	CommunicationBase *comm;

	std::vector<hardware_interface::StateInterface> joint_state_interface;
	std::vector<hardware_interface::CommandInterface> joint_position_interface;

	double cmd[6] = {0, 0.64, -1.39, 0, 0, 0};
	double pos[6] = {0, 0.64, -1.39, 0, 0, 0};
	double vel[6] = {0};
	double eff[6] = {0};
};

#endif
