#!/usr/bin/env python

# tool_commander.py
# Copyright (C) 2017 Niryo
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
from rclpy.action import ActionClient

from niryo_one_msgs.action import Tool

from niryo_one_commander.command_status import CommandStatus
from niryo_one_commander.robot_commander_exception import RobotCommanderException
from actionlib_msgs.msg import GoalStatus


class ToolCommander:

    def __init__(self, node: Node):
        self.node = node

        self.action_client = ActionClient(
            self, Tool, 'niryo_one/tool_action')
        self.node.get_logger().info("Waiting for action server : niryo_one/tool_action...")
        self.action_client.wait_for_server()
        self.node.get_logger().info("Found action server : niryo_one/tool_action")

        self.node.get_logger().info("Tool Commander has been started")

    def send_tool_command(self, cmd):
        goal = self.create_goal(cmd)
        self.action_client.wait_for_server()
        send_goal_future = self.action_client.send_goal_async(goal, feedback_callback=self.feedback_callback)
        send_goal_future.add_done_callback(self.goal_response_callback)
        self.node.get_logger().info("Tool command sent")

        # if goal has been rejected/aborted, stop tracking it and return error
        if self.has_problem():
            result_future = self.action_client.get_result_async(self.goal_handle)
            result = result_future.result().result
            message = result.message  # user-defined status text
            self.goal_handle = None    # stop tracking
            raise RobotCommanderException(CommandStatus.TOOL_FAILED, message)
    
    def goal_response_callback(self, future):
        self.goal_handle = future.result()
        if not self.goal_handle.accepted:
            self.node.get_logger().info('Goal rejected :(')
            raise RobotCommanderException(CommandStatus.TOOL_FAILED, 'Goal rejected')

        self.node.get_logger().info('Goal accepted :)')

        self.get_result_future = self.goal_handle.get_result_async()
        self.get_result_future.add_done_callback(self.get_result_callback)

    def get_result_callback(self, future):
        result = future.result().result
        self.node.get_logger().info('Result: ' + str(result))

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.node.get_logger().info('Received feedback: ' + str(feedback))

    def stop_tool_command(self):
        pass
        # todo cancel goal

    @staticmethod
    def create_goal(cmd):
        goal = Tool.Goal()
        goal.cmd = cmd
        return goal

    # Returns LOST if this SimpleActionClient isn't tracking a goal. 
    # see documentation : http://docs.ros.org/diamondback/api/actionlib/html/classactionlib_1_1simple__action__client_1_1SimpleActionClient.html#a6bdebdd9f43a470ecd361d2c8b743188
    def get_command_status(self):
        if self.goal_handle is None:
            return GoalStatus.LOST
        return self.goal_handle.status

    def has_problem(self):
        status = self.get_command_status()
        # self.node.get_logger().info("STATUS : " + str(status))
        return status == GoalStatus.ABORTED or status == GoalStatus.REJECTED
