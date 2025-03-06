#include "niryo_one_driver/test_motors.hpp"

NiryoOneTestMotor::NiryoOneTestMotor(): Node("test_motors") {
	getJointsLimits();

	reset_stepper_publisher = this->create_publisher<std_msgs::msg::Empty>(
			"/niryo_one/steppers_reset_controller", 1000);
	calibrate_motor_client = this->create_client<niryo_one_msgs::srv::SetInt>(
			"/niryo_one/calibrate_motors");

	traj_client_ = rclcpp_action::create_client<
			control_msgs::action::FollowJointTrajectory>(this,
			"/niryo_one_follow_joint_trajectory_controller/"
			"follow_joint_trajectory");

	joint_state_subscriber =
			this->create_subscription<sensor_msgs::msg::JointState>(
					"/joint_states", 10,
					std::bind(&NiryoOneTestMotor::callbackJointSate, this,
							std::placeholders::_1));

	this->declare_parameter("robot_description", rclcpp::PARAMETER_STRING);

	RCLCPP_INFO(this->get_logger(), "Test motors up");
}

void NiryoOneTestMotor::callbackJointSate(
		const sensor_msgs::msg::JointState::SharedPtr msg) {
	_current_joint_pose.resize(this->_n_joints);
	for (int i = 0; i < this->_n_joints; ++i) {
		this->_current_joint_pose[i] = msg->position[i];
	}
}

bool NiryoOneTestMotor::runTest(int nb_loops) {
	enable_test = true;

	RCLCPP_INFO(this->get_logger(), "Reset Controller");
	std_msgs::msg::Empty reset_controller_topic;
	reset_stepper_publisher->publish(reset_controller_topic);
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
	enable_test = false;

	return true;
}

void NiryoOneTestMotor::stopTest() {
	if (this->enable_test) {
		this->enable_test = false;
		RCLCPP_INFO(this->get_logger(), "Reset Controller");
		std_msgs::msg::Empty reset_controller_topic;
		reset_stepper_publisher->publish(reset_controller_topic);
	}
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
					"'robot_description' parameter (name: %s).",
					this->get_name());
			return false;
		}
	} else {
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
	auto send_goal_options = rclcpp_action::Client<
			control_msgs::action::FollowJointTrajectory>::SendGoalOptions();
	send_goal_options.goal_response_callback = [this](auto future) {
		auto goal_handle = future.get();
		if (!goal_handle) {
			RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
		} else {
			RCLCPP_INFO(this->get_logger(),
					"Goal accepted by server, waiting for result...");
		}
	};
	send_goal_options.result_callback = [this](auto result) {
		switch (result.code) {
			case rclcpp_action::ResultCode::SUCCEEDED:
				RCLCPP_INFO(this->get_logger(), "Goal successed!");
				break;
			case rclcpp_action::ResultCode::ABORTED:
				RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
				break;
			case rclcpp_action::ResultCode::CANCELED:
				RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
				break;
			default:
				RCLCPP_ERROR(this->get_logger(), "Unknown result code");
				break;
		}
	};

	while (!traj_client_->wait_for_action_server(std::chrono::seconds(5))) {
		RCLCPP_INFO(this->get_logger(),
				"Waiting for the joint_trajectory_action server");
	}

	// When to start the trajectory: 1s from now
	goal.trajectory.header.stamp =
			rclcpp::Clock().now() + rclcpp::Duration(std::chrono::seconds(1));
	auto goal_handle_future =
			traj_client_->async_send_goal(goal, send_goal_options);
}

bool NiryoOneTestMotor::playTrajectory(
		control_msgs::action::FollowJointTrajectory_Goal goal) {
	if (!enable_test) {
		return true;
	}

	startTrajectory(goal);

	std::vector<double> rounded_target;
	rounded_target.resize(_n_joints);

	for (int i = 0; i < _n_joints; ++i) {
		rounded_target[i] =
				round(goal.trajectory.points.back().positions[i] * 10) / 10;
	}

	rclcpp::sleep_for(std::chrono::milliseconds(300));
	for (int i = 0; i < _n_joints; ++i) {
		double goal_joint = goal.trajectory.points.back().positions[i];
		if (enable_test &&
				((_current_joint_pose[i] < goal_joint - 0.1) ||
						(_current_joint_pose[i] > goal_joint + 0.1))) {
			return false;
		}
	}

	return true;
}

control_msgs::action::FollowJointTrajectory::Goal
		NiryoOneTestMotor::armExtensionTrajectory(
				std::vector<double> joint_positions) {
	// Our goal variable
	control_msgs::action::FollowJointTrajectory_Goal goal;
	goal.trajectory.joint_names = _joint_names;

	trajectory_msgs::msg::JointTrajectoryPoint point;
	point.positions = joint_positions;
	point.time_from_start = rclcpp::Duration(std::chrono::seconds(3));
	goal.trajectory.points.push_back(point);

	return goal;
}
