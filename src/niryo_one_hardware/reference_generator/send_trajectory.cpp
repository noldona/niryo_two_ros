#include <kdl/chainfksolverpos_recursive.hpp>
#include <kdl/chainiksolvervel_pinv.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/tree.hpp>
#include <kdl_parser/kdl_parser.hpp>
#include <rclcpp/rclcpp.hpp>
#include <trajectory_msgs/msg/joint_trajectory.hpp>
#include <trajectory_msgs/msg/joint_trajectory_point.hpp>

#include "niryo_one_msgs/srv/set_int.hpp"

int main(int argc, char **argv) {
	rclcpp::init(argc, argv);
	auto node = std::make_shared<rclcpp::Node>("send_trajectory");
	auto pub = node->create_publisher<trajectory_msgs::msg::JointTrajectory>(
			"/niryo_one/joint_trajectory", 10);

	auto client = node->create_client<niryo_one_msgs::srv::SetInt>(
			"niryo_one/activate_learning_mode");

	// Get robot description
	auto robot_param = rclcpp::Parameter();
	node->declare_parameter(
			"robot_description", rclcpp::ParameterType::PARAMETER_STRING);
	node->get_parameter("robot_description", robot_param);
	auto robot_description = robot_param.as_string();

	// Create kinematic chain
	KDL::Tree robot_tree;
	KDL::Chain chain;
	kdl_parser::treeFromString(robot_description, robot_tree);
	robot_tree.getChain("base_link", "tool_link", chain);

	auto joint_positions = KDL::JntArray(chain.getNrOfJoints());
	auto joint_velocities = KDL::JntArray(chain.getNrOfJoints());
	auto twist = KDL::Twist();
	// Create KDL solvers
	auto ik_vel_solver_ =
			std::make_shared<KDL::ChainIkSolverVel_pinv>(chain, 0.0000001);

	trajectory_msgs::msg::JointTrajectory trajectory_msg;
	trajectory_msg.header.stamp = node->now();
	for (size_t i = 0; i < chain.getNrOfSegments(); i++) {
		auto joint = chain.getSegment(i).getJoint();
		if (joint.getType() != KDL::Joint::Fixed) {
			trajectory_msg.joint_names.push_back(joint.getName());
		}
	}

	trajectory_msgs::msg::JointTrajectoryPoint trajectory_point_msg;
	trajectory_point_msg.positions.resize(chain.getNrOfJoints());
	trajectory_point_msg.velocities.resize(chain.getNrOfJoints());

	double total_time = 3.0;
	int trajectory_len = 200;
	int loop_rate = trajectory_len / total_time;
	double dt = 1.0 / loop_rate;

	for (int i = 0; i < trajectory_len; i++) {
		// Set endpoint twist
		double t = i;
		twist.vel.x(2 * 0.3 * cos(2 * M_PI * t / trajectory_len));
		twist.vel.y(-0.3 * sin(2 * M_PI * t / trajectory_len));

		// Convert cart to joint velocities
		ik_vel_solver_->CartToJnt(joint_positions, twist, joint_velocities);

		// Copy to trajectory_point_msg
		std::memcpy(trajectory_point_msg.positions.data(),
				joint_positions.data.data(),
				trajectory_point_msg.positions.size() * sizeof(double));
		std::memcpy(trajectory_point_msg.velocities.data(),
				joint_velocities.data.data(),
				trajectory_point_msg.velocities.size() * sizeof(double));

		// Integrate joint velocities
		joint_positions.data += joint_velocities.data * dt;

		// Set timing information
		trajectory_point_msg.time_from_start.sec = i / loop_rate;
		trajectory_point_msg.time_from_start.nanosec = static_cast<int>(1E9 /
				loop_rate *
				static_cast<double>(t -
						loop_rate *
								(i / loop_rate)));  // Implicit integer division

		trajectory_msg.points.push_back(trajectory_point_msg);
	}

	// Send zero velocities in the end
	std::fill(trajectory_point_msg.velocities.begin(),
			trajectory_point_msg.velocities.end(), 0.0);
	trajectory_point_msg.time_from_start.sec = trajectory_len / loop_rate;
	trajectory_point_msg.time_from_start.nanosec =
			static_cast<int>(1E9 / loop_rate *
					static_cast<double>(trajectory_len -
							loop_rate * (trajectory_len / loop_rate)));
	trajectory_msg.points.push_back(trajectory_point_msg);

	// Disable learning mode
	auto req = std::make_shared<niryo_one_msgs::srv::SetInt::Request>();
	req->value = false;
	while (!client->wait_for_service()) {
		RCLCPP_INFO(node->get_logger(),
				"Waiting for service to become available...");
	}
	auto result = client->async_send_request(req);

	// Send trajectory
	RCLCPP_INFO(node->get_logger(), "Publishing trajectory");
	pub->publish(trajectory_msg);

	// Enable learning mode
	req->value = true;
	result = client->async_send_request(req);

	while (rclcpp::ok()) {
	}

	return 0;
}
