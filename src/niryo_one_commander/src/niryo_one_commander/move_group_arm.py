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
from rclpy.executors import ExternalShutdownException
import rclpy.timer
import moveit.core.robot_model
from moveit.planning import PlanningComponent
from moveit.planning import MoveItPy
# from moveit.core.robot_model import RobotModel, JointModelGroup

class MoveGroupArm:

    def __init__(self, node:Node, **kwargs):
        self.node = node

        # Get params from rosparams
        reference_frame = self.node.declare_parameter("~reference_frame").value
        move_group_commander_name = self.node.declare_parameter("~move_group_commander_name").value
        allow_replanning = self.node.declare_parameter("~allow_replanning").value
        goal_joint_tolerance = self.node.declare_parameter("~goal_joint_tolerance").value
        goal_position_tolerance = self.node.declare_parameter("~goal_position_tolerance").value
        goal_orientation_tolerance = self.node.declare_parameter("~goal_orientation_tolerance").value

        # Set reference_frame
        self.reference_frame = reference_frame

        # Get Arm MoveGroupCommander
        move_group_arm_ok = False
        while not move_group_arm_ok:
            try:
                self.node.get_logger().info("Trying to get create MoveItPy instance...")
                self.moveit_py = MoveItPy(self.node)
                self.robot_model : moveit.core.robot_model.RobotModel = self.moveit_py.get_robot_model()
                self.joint_model_group : moveit.core.robot_model.JointModelGroup = self.robot_model.get_joint_model_group(move_group_commander_name)
                self.arm = self.moveit_py.get_planning_component(move_group_commander_name)
                
                move_group_arm_ok = True
            except RuntimeError as e:
                self.node.get_logger().info(e)
                rclpy.timer.Rate(1.0).sleep()

        # Get end effector link
        self.end_effector_link = self.joint_model_group.get_end_effector_names()[0]

        # Set pose reference frame
        self.arm.set_pose_reference_frame(self.reference_frame)

        # Set planning parameters
        self.arm.allow_replanning(allow_replanning)
        self.arm.set_goal_joint_tolerance(goal_joint_tolerance)
        self.arm.set_goal_position_tolerance(goal_position_tolerance)
        self.arm.set_goal_orientation_tolerance(goal_orientation_tolerance)

        self.node.get_logger().info("Successfully connected to move_group." +
                      "\n" + "Started group     : " + str(self.arm.get_name()) +
                      "\n" + "Planning_frame    : " + str(self.arm.get_planning_frame()) +
                      "\n" + "Reference frame   : " + str(self.reference_frame) +
                      "\n" + "End effector link : " + str(self.end_effector_link))

        self.node.get_logger().info("Arm Moveit Commander has been started")

    """
    MoveitCommander documentation :
    http://docs.ros.org/indigo/api/moveit_commander/html/classmoveit__commander_1_1move__group_1_1MoveGroupCommander.html#a63bbf526cd62983ca44536ed6dd16813

    """

    def compute_plan(self):
        plan = self.arm.plan()

        if not plan.joint_trajectory.points:
            return None
        return plan

    def execute(self, plan, wait=False):
        self.arm.execute(plan, wait=wait)

    def stop(self):
        self.arm.stop()

    def set_joint_value_target(self, joint_array):
        self.arm.set_joint_value_target(joint_array)

    def set_position_target(self, x, y, z):
        self.arm.set_position_target([x, y, z], self.end_effector_link)

    def set_rpy_target(self, roll, pitch, yaw):
        self.arm.set_rpy_target([roll, pitch, yaw], self.end_effector_link)

    def set_pose_target(self, x, y, z, roll, pitch, yaw):
        self.arm.set_pose_target([x, y, z, roll, pitch, yaw], self.end_effector_link)

    def set_pose_quat_target(self, pose):
        self.arm.set_pose_target(pose, self.end_effector_link)

    def set_shift_pose_target(self, axis_number, value):
        self.arm.shift_pose_target(axis_number, value, self.end_effector_link)

    def set_max_velocity_scaling_factor(self, percentage):
        self.arm.set_max_velocity_scaling_factor(percentage)

def main():
    rclpy.init()
    move_group_arm = MoveGroupArm()

    try:
        rclpy.spin(move_group_arm)
    except (ExternalShutdownException, KeyboardInterrupt):
        pass
    finally:
        move_group_arm.destroy_node()
        rclpy.try_shutdown()

if __name__ == '__main__':
    main()