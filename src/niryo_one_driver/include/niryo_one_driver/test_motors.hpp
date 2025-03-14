#ifndef NIRYO_TEST_MOTORS_H
#define NIRYO_TEST_MOTORS_H

#include "rclcpp/rclcpp.hpp"
#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <thread>
#include <time.h>
#include <vector>

#include <urdf/model.h>

#include <std_msgs/msg/empty.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include <std_msgs/msg/int64_multi_array.hpp>

#include <action_msgs/msg/goal_status.hpp>
#include <control_msgs/action/follow_joint_trajectory.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <sensor_msgs/msg/joint_state.hpp>

#include "niryo_one_msgs/srv/set_bool.hpp"
#include "niryo_one_msgs/srv/set_int.hpp"

typedef control_msgs::action::FollowJointTrajectory TrajClient;

class NiryoOneTestMotor: public rclcpp::Node {
	private:
	rclcpp::Client<niryo_one_msgs::srv::SetInt>::SharedPtr
			calibrate_motor_client;
	rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr
			joint_state_subscriber;

	rclcpp::Publisher<std_msgs::msg::Empty>::SharedPtr reset_stepper_publisher;

	std::shared_ptr<
			rclcpp_action::Client<control_msgs::action::FollowJointTrajectory>>
			traj_client_;

	std::vector<double> pose_start {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

	bool enable_test;
	int _n_joints = 6;
	std::vector<std::string> _joint_names;
	std::vector<double> _joint_upper_limits;
	std::vector<double> _joint_lower_limits;
	std::vector<double> _joint_has_position_limits;

	std::vector<double> _current_joint_pose;

	public:
	NiryoOneTestMotor();

	void callbackJointSate(const sensor_msgs::msg::JointState::SharedPtr msg);

	bool getJointsLimits();

	bool runTest(int nb_loops);
	void stopTest();
	void startTrajectory(
			control_msgs::action::FollowJointTrajectory::Goal goal);
	bool playTrajectory(control_msgs::action::FollowJointTrajectory::Goal goal);

	control_msgs::action::FollowJointTrajectory::Goal armExtensionTrajectory(
			std::vector<double> joint_positions);
};
#endif
