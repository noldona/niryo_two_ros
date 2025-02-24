#ifndef NIRYO_HARDWARE_INTERFACE_H
#define NIRYO_HARDWARE_INTERFACE_H

#include "rclcpp/rclcpp.hpp"
#include <hardware_interface/joint_command_interface.hpp>
#include <hardware_interface/joint_state_interface.hpp>
#include <hardware_interface/robot_hw.hpp>
#include <memory>

#include "niryo_one_driver/communication_base.hpp"

class NiryoOneHardwareInterface: public hardware_interface::RobotHW {
	public:
	NiryoOneHardwareInterface(CommunicationBase *niryo_one_comm);

	void read();

	void write();

	// Custom
	void setCommandToCurrentPosition();

	private:
	ros::NodeHandle nh_;

	CommunicationBase *comm;

	hardware_interface::JointStateInterface joint_state_interface;
	hardware_interface::PositionJointInterface joint_position_interface;

	double cmd[6] = {0, 0.64, -1.39, 0, 0, 0};
	double pos[6] = {0, 0.64, -1.39, 0, 0, 0};
	double vel[6] = {0};
	double eff[6] = {0};
};

#endif
