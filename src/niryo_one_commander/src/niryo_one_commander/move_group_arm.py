#!/usr/bin/env python

# move_group_arm.py
# Copyright (C) 2018 Niryo
# All rights reserved.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

from rclpy.node import Node
import rclpy.timer
from rclpy.parameter import Parameter
from moveit.core.kinematic_constraints import construct_joint_constraint
from moveit.core.robot_model import RobotModel, JointModelGroup
from moveit.core.robot_state import RobotState
from moveit.core.planning_interface import MotionPlanResponse
from moveit import PlanningComponent, MoveItPy, PlanRequestParameters
from geometry_msgs.msg import PoseStamped, Pose
from tf_transformations import euler_from_quaternion, quaternion_from_euler

# from moveit_msgs.msg import Constraints, JointConstraint    implement tolerance in future
from std_msgs.msg import String

class MoveGroupArm:

    def __init__(self, node:Node):
        self.node = node

        # Get params from rosparams
        reference_frame = self.node.declare_parameter("reference_frame","world").value
        move_group_commander_name = self.node.declare_parameter("move_group_commander_name","arm").value
        allow_replanning = self.node.declare_parameter("allow_replanning",True).value
        goal_joint_tolerance = self.node.declare_parameter("goal_joint_tolerance",0.01).value
        goal_position_tolerance = self.node.declare_parameter("goal_position_tolerance",0.01).value
        goal_orientation_tolerance = self.node.declare_parameter("goal_orientation_tolerance",0.01).value

        # Set reference_frame
        self.reference_frame = reference_frame

        self.stop_publisher = self.node.create_publisher(String, 'trajectory_execution_event', 1)

        # Get Arm MoveGroupCommander
        move_group_arm_ok = False
        while not move_group_arm_ok:
            try:
                self.node.get_logger().info("Trying to create MoveItPy instance...")
                self.robot = MoveItPy(node_name="moveit_py")
                self.robot_model : RobotModel = self.robot.get_robot_model()
                self.joint_model_group : JointModelGroup = self.robot_model.get_joint_model_group(move_group_commander_name)
                self.robot_state = RobotState(self.robot_model)
                self.arm : PlanningComponent = self.robot.get_planning_component(move_group_commander_name)
                self.plan_params = PlanRequestParameters(max_acceleration_scaling_factor=0.1,
                                                        max_velocity_scaling_factor=0.1,
                                                        planner_id="RRTConnectkConfigDefault",
                                                        planning_attempts=10,
                                                        planning_pipeline="planning_pipeline",
                                                        planning_time=5.0)

                move_group_arm_ok = True
            except RuntimeError as e:
                self.node.get_logger().info(str(e))
                self.node.create_rate(1.0).sleep()

        # Get end effector link
        self.end_effector_link = self.joint_model_group.eef_name
        
        # Set pose reference frame
        # self.arm.set_pose_reference_frame(self.reference_frame)

        # Set planning parameters

        # self.arm.allow_replanning(allow_replanning)
        # self.arm.set_goal_joint_tolerance(goal_joint_tolerance)
        # self.arm.set_goal_position_tolerance(goal_position_tolerance)
        # self.arm.set_goal_orientation_tolerance(goal_orientation_tolerance)
        
        self.node.get_logger().info("Successfully connected to move_group." +
                      "\n" + "Started group     : " + str(self.arm.planning_group_name) +
                      "\n" + "Planning_frame    : " + str(self.robot_model.model_frame) +
                      "\n" + "Reference frame   : " + str(self.reference_frame) +
                      "\n" + "End effector link : " + str(self.end_effector_link))

        self.node.get_logger().info("Arm Moveit Commander has been started")

    """
    MoveitCommander documentation :
    http://docs.ros.org/indigo/api/moveit_commander/html/classmoveit__commander_1_1move__group_1_1MoveGroupCommander.html#a63bbf526cd62983ca44536ed6dd16813

    """

    def compute_plan(self):
        self.arm.set_start_state_to_current_state()
        plan : MotionPlanResponse = self.arm.plan(single_plan_parameters=self.plan_params)
        return plan

    def execute(self, plan:MotionPlanResponse, controllers=[]):
        self.robot.execute(plan.trajectory, controllers=controllers)

    def stop(self):
        msg = String()
        msg.data = 'stop'
        self.stop_publisher.publish(msg)
        self.node.get_logger().info("Published STOP to trajectory_execution_event")

    def set_joint_value_target(self, joint_dict):
        self.robot_state.joint_positions = joint_dict
        joint_constraint = construct_joint_constraint(
            robot_state=self.robot_state,
            joint_model_group=self.joint_model_group
        )
        self.arm.set_goal_state(motion_plan_constraints=[joint_constraint])

    def set_position_target(self, x, y, z):
        pose_goal = PoseStamped()
        pose_goal.header.frame_id = self.reference_frame
        pose_goal.pose.position.x = x
        pose_goal.pose.position.y = y
        pose_goal.pose.position.z = z
        pose_goal.pose.orientation.w = 1.0
        self.arm.set_goal_state(pose_stamped_msg=pose_goal, pose_link=self.end_effector_link)

    def set_rpy_target(self, roll, pitch, yaw):
        pose_goal = PoseStamped()
        pose_goal.header.frame_id = self.reference_frame
        pose_goal.pose.orientation = quaternion_from_euler(roll, pitch, yaw)
        self.arm.set_goal_state(pose_stamped_msg=pose_goal, pose_link=self.end_effector_link)

    def set_pose_target(self, x, y, z, roll, pitch, yaw):
        pose_goal = PoseStamped()
        pose_goal.header.frame_id = self.reference_frame
        pose_goal.pose.position.x = x
        pose_goal.pose.position.y = y
        pose_goal.pose.position.z = z
        pose_goal.pose.orientation.x = roll
        pose_goal.pose.orientation.y = pitch
        pose_goal.pose.orientation.z = yaw
        pose_goal.pose.orientation.w = 1.0
        self.arm.set_goal_state(pose_stamped_msg=pose_goal, pose_link=self.end_effector_link)

    def set_pose_quat_target(self, pose:Pose):
        pose_goal = PoseStamped()
        pose_goal.header.frame_id = self.reference_frame
        pose_goal.pose = pose
        self.arm.set_goal_state(pose_stamped_msg=pose_goal, pose_link=self.end_effector_link)

    def set_shift_pose_target(self, axis_number, value):
        self.arm.set_start_state_to_current_state()
        self.robot_state:RobotState = self.arm.get_start_state()
        self.robot_state.update()

        pose_goal = PoseStamped()
        pose_goal.header.frame_id = self.reference_frame
        pose_goal.pose = self.robot_state.get_pose(self.end_effector_link)

        if axis_number in (0,1,2):
            if axis_number == 0:
                pose_goal.pose.position.x += value
            elif axis_number == 1:
                pose_goal.pose.position.y += value
            elif axis_number == 2:
                pose_goal.pose.position.z += value
        elif axis_number in (3,4,5):
            (r, p, y) = euler_from_quaternion(pose_goal.pose.orientation)
            if axis_number == 3:
                r += value
            elif axis_number == 4:
                p += value
            elif axis_number == 5:
                y += value
        
            pose_goal.pose.orientation = quaternion_from_euler(r, p, y)
        self.arm.set_goal_state(pose_stamped_msg=pose_goal, pose_link=self.end_effector_link)

    def set_max_velocity_scaling_factor(self, percentage):
        self.plan_params.max_velocity_scaling_factor = percentage

if __name__ == '__main__':
    pass