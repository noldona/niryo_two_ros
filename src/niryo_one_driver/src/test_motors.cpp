#include "niryo_one_driver/test_motors.hpp"

NiryoOneTestMotor::NiryoOneTestMotor(): Node("test_motors") {
	this->getJointsLimits();

	reset_stepper_publisher = this->create_publisher<std_msgs::msg::Empty>(
			"/niryo_one/steppers_reset_controller", 1000);
	calibrate_motor_client = this->create_client<niryo_one_msgs::srv::SetInt>(
			"/niryo_one/calibrate_motors");

	this->traj_client_ = new TrajClient("/niryo_one_follow_joint_trajectory_"
										"controller/follow_joint_trajectory",
			true);
	joint_state_subscriber =
			this->create_subscription<sensor_msgs::msg::JointState>(
					"/joint_states", 10, &NiryoOneTestMotor::callbackJointSate);

	RCLCPP_INFO(this->get_logger(), "Test motors up");
}

void NiryoOneTestMotor::callbackJointSate(
		const sensor_msgs::msg::JointState &msg) {
	this->_current_joint_pose.resize(this->_n_joints);
	for (int i = 0; i < this->_n_joints; ++i) {
		this->_current_joint_pose[i] = msg.position[i];
	}
}

bool NiryoOneTestMotor::runTest(int nb_loops) {
	enable_test = true;

	RCLCPP_INFO(this->get_logger(), "Reset Controller");
	std_msgs::msg::Empty reset_controller_topic;
	reset_stepper_publisher.publish(reset_controller_topic);
	rclcpp::sleep_for(std::chrono::milliseconds(50));

	bool state;
	state = this->playTrajectory(armExtensionTrajectory(this->pose_start));
	if (!state) {
		return false;
	}

	for (int j = 0; j < nb_loops; j++) {
		for (int i = 0; i < this->_n_joints; ++i) {
			if (this->_joint_has_position_limits[i]) {
				std::vector<double> pose_lower_limit = this->pose_start;
				pose_lower_limit[i] = this->_joint_lower_limits[i];
				state = playTrajectory(
						armExtensionTrajectory(pose_lower_limit));
				if (!state) {
					return false;
				}

				state = playTrajectory(
						armExtensionTrajectory(this->pose_start));
				if (!state) {
					return false;
				}

				std::vector<double> pose_upper_limit = this->pose_start;
				pose_upper_limit[i] = this->_joint_upper_limits[i];
				state = playTrajectory(
						armExtensionTrajectory(pose_upper_limit));
				if (!state) {
					return false;
				}

				state = playTrajectory(
						armExtensionTrajectory(this->pose_start));
				if (!state) {
					return false;
				}
			}
		}
	}
	this->enable_test = false;

	return true;
}

void NiryoOneTestMotor::stopTest() {
	if (this->enable_test) {
		this->enable_test = false;
		RCLCPP_INFO(this->get_logger(), "Reset Controller");
		std_msgs::msg::Empty reset_controller_topic;
		reset_stepper_publisher.publish(reset_controller_topic);
	}
	return;
}

bool NiryoOneTestMotor::getJointsLimits() {
	// Resize vectors
	this->_joint_names.resize(this->_n_joints);
	this->_joint_upper_limits.resize(this->_n_joints);
	this->_joint_lower_limits.resize(this->_n_joints);
	this->_joint_has_position_limits.resize(this->_n_joints);

	// Get limits from URDF
	urdf::ModelSharedPtr urdf(new urdf::Model);
	std::string urdf_str;
	if (this->get_parameter("robot_description",
				urdf_str))  // Check for robot_description in proper namespace
	{
		if (!urdf->initString(urdf_str)) {
			RCLCPP_ERROR(this->get_logger(),
					"Failed to parse URDF contained in "
					"'robot_description' parameter (name: "
							<< this->get_name() << ").");
			return false;
		}
	} else if (
			!urdf->initParam(
					"robot_description"))  // Check for robot_description in root
	{
		RCLCPP_ERROR(this->get_logger(),
				"Failed to parse URDF contained in "
				"'robot_description' parameter");
		return false;
	}
	for (auto i = 0; i < this->_n_joints; i++) {
		// Joints name
		this->_joint_names[i] = "joint_" + std::to_string(i + 1);

		urdf::JointConstSharedPtr urdf_joint =
				urdf->getJoint(this->_joint_names[i]);
		if (urdf_joint) {
			if (urdf_joint->type != urdf::Joint::CONTINUOUS) {
				this->_joint_upper_limits[i] = urdf_joint->limits->upper - 0.2;
				this->_joint_lower_limits[i] = urdf_joint->limits->lower + 0.2;
				this->_joint_has_position_limits[i] = true;
			} else
				this->_joint_has_position_limits[i] = false;
		} else {
			return false;
		}
	}
}

void NiryoOneTestMotor::startTrajectory(
		control_msgs::action::FollowJointTrajectory_Goal goal) {
	RCLCPP_INFO(this->get_logger(), "Send trajectory");
	while (!traj_client_->waitForServer(rclcpp::Duration(5.0))) {
		RCLCPP_INFO(this->get_logger(),
				"Waiting for the joint_trajectory_action server");
	}

	// When to start the trajectory: 1s from now
	goal.trajectory.header.stamp =
			rclcpp::Clock().now() + rclcpp::Duration(1.0);
	this->traj_client_->sendGoal(goal);
}

bool NiryoOneTestMotor::playTrajectory(
		control_msgs::action::FollowJointTrajectory_Goal goal) {
	if (!this->enable_test) {
		return true;
	}

	startTrajectory(goal);

	std::vector<double> rounded_target;
	rounded_target.resize(_n_joints);

	for (int i = 0; i < _n_joints; ++i) {
		rounded_target[i] =
				round(goal.trajectory.points[goal.trajectory.points.size() - 1]
								.positions[i] *
						10) /
				10;
	}
	// Wait for trajectory completion
	while (!getState().isDone() && rclcpp::ok() && this->enable_test) {
		rclcpp::sleep_for(std::chrono::milliseconds(100));
	}

	rclcpp::sleep_for(std::chrono::milliseconds(300));
	for (int i = 0; i < _n_joints; ++i) {
		double goal_joint =
				goal.trajectory.points[goal.trajectory.points.size() - 1]
						.positions[i];
		if (this->enable_test &&
				((this->_current_joint_pose[i] < goal_joint - 0.1) ||
						(this->_current_joint_pose[i] > goal_joint + 0.1))) {
			return false;
		}
	}

	return true;
}

control_msgs::action::FollowJointTrajectory_Goal
		NiryoOneTestMotor::armExtensionTrajectory(
				std::vector<double> joint_positions) {
	// Our goal variable
	control_msgs::action::FollowJointTrajectory_Goal goal;

	// We will have two waypoints in this goal trajectory
	goal.trajectory.points.resize(1);

	// First trajectory point
	int ind = 0;
	goal.trajectory.joint_names.resize(this->_n_joints);
	goal.trajectory.points[ind].positions.resize(this->_n_joints);
	goal.trajectory.points[ind].velocities.resize(this->_n_joints);

	for (int j = 0; j < this->_n_joints; ++j) {
		// First, the joint names, which apply to all waypoints
		goal.trajectory.joint_names[j] = this->_joint_names[j];
		// Positions
		goal.trajectory.points[ind].positions[j] = joint_positions[j];
		// Velocities
		goal.trajectory.points[ind].velocities[j] = 0.0;
	}
	// To be reached 1 second after starting along the trajectory
	goal.trajectory.points[ind].time_from_start = rclcpp::Duration(3);

	return goal;
}

actionlib::SimpleClientGoalState NiryoOneTestMotor::getState() {
	return traj_client_->getState();
}
