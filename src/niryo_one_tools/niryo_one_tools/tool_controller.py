#!/usr/bin/env python

import rclpy.action
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
import rclpy
from rclpy.action import ActionServer

from niryo_one_msgs.srv import SetInt

from niryo_one_msgs.action import Tool

from std_msgs.msg import Int32

from niryo_one_tools.tools import *
from niryo_one_tools.tool_ros_command_interface import ToolRosCommandInterface


class ToolController(Node):
    def __init__(self, ros_command_interface):
        super().__init__('niryo_one_tools')

        self.ros_command_interface = ros_command_interface

        self.server = ActionServer(
            self, Tool, 'niryo_one/tool_action', self.tool_on_goal
        )
        self.get_logger().info('Action server started (ToolController)')

        self.change_tool_server = self.create_service(
            SetInt, 'niryo_one/change_tool', self.callback_change_tool)

        self.current_tool_id_publisher = self.create_publisher(
            Int32, '/niryo_one/current_tool_id', 1)

        self.create_timer(0.1, self.publish_current_tool_id)

        self.current_tool = None
        self.available_tools = None
        self.command_list = None
        self.create_tools()

    def create_tools(self):

        # Get params from rosparams
        tool_config_list = self.declare_parameter("tool_list", []).value
        tool_command_list = self.declare_parameter("command_list", []).value

        self.available_tools = []
        self.command_list = tool_command_list

        for tool in tool_config_list:
            new_tool = None

            if tool['type'] == 'gripper':
                new_tool = Gripper(
                    tool['id'], tool['name'], self.ros_command_interface,
                    tool['specs']['open_position'], tool['specs']['open_hold_torque'],
                    tool['specs']['close_position'], tool['specs']['close_hold_torque'],
                    tool['specs']['close_max_torque'])
            elif tool['type'] == 'electromagnet':
                new_tool = Electromagnet(
                    tool['id'], tool['name'], self.ros_command_interface)
            elif tool['type'] == 'vacuum_pump':
                new_tool = VacuumPump(tool['id'], tool['name'], self.ros_command_interface,
                                      tool['specs']['pull_air_position'],
                                      tool['specs']['pull_air_hold_torque'], tool['specs']['push_air_position'])
            else:
                self.get_logger().warn(
                    "ERROR : TYPE NOT RECOGNIZED from tool config list : " + str(tool['type']))
                continue

            self.available_tools.append(new_tool)

            cmds = []

            for cmd in tool['available_commands']:
                try:
                    cmds.append(tool_command_list[cmd])
                except Exception:
                    self.get_logger().warn(str(cmd) + " is not a recognized command")
                    continue

            new_tool.set_available_commands(cmds)

        self.get_logger().info("Detected tools : (id + available commands)")
        for tool in self.available_tools:
            self.get_logger().info(str(tool.get_id()) + ' : ' +
                                   str(tool.get_available_commands()))

    def tool_on_goal(self, goal_handle):
        cmd = goal_handle.request.cmd
        # self.get_logger().info("Tool controller - received goal : " + str(goal))

        if self.current_tool is None:
            goal_handle.abort()
            return self.create_action_result(400, "No tool selected")

        # 1. Check tool id
        if cmd.tool_id != self.current_tool.get_id():
            goal_handle.abort()
            return self.create_action_result(
                400,
                "Wrong tool selected - ID does not match : " + str(
                    self.current_tool.get_id()))

        # 2. Check if current tool is active
        if self.current_tool.is_active:
            goal_handle.abort()
            return self.create_action_result(
                400, "Tool still active, retry later")

        # 3. Check cmd_type (if exists, and is available for selected tool)
        if cmd.cmd_type not in self.current_tool.get_available_commands():
            goal_handle.abort()
            return self.create_action_result(
                400,
                "Command type is not available for current tool (not in " + str(
                    self.current_tool.get_available_commands()) + ")")

        # 3.1 Validate params
        try:
            self.current_tool.validate_command(cmd)
        except ToolValidationException as e:
            goal_handle.abort()
            return self.create_action_result(400, str(e))

        # 4. Execute cmd -> retrieve cmd name in command list and execute on current tool
        self.current_tool.set_as_active()
        success = False
        message = "Error"

        function_name = self.command_list.keys(
        )[self.command_list.values().index(cmd.cmd_type)]
        success, message = getattr(self.current_tool, function_name)(
            cmd)  # Execute function from name

        self.current_tool.set_as_non_active()

        # 5. Return success or error
        if success:
            goal_handle.succeed()
            return self.create_action_result(200, "Tool action successfully finished")
        else:
            self.get_logger().info("Tool controller - error : " + str(message))
            goal_handle.abort()
            return self.create_action_result(400, message)

    def callback_change_tool(self, req):
        new_tool_id = req.value

        # Check if action == detach tool (id == 0)
        if new_tool_id == 0:
            self.ros_command_interface.ping_dxl_tool(0, 'No Dxl Tool')
            self.current_tool = None
            self.publish_current_tool_id(None)
            return self.create_response(200, "Tool has been detached")

        # Check if tool id is null
        if new_tool_id is None:
            return self.create_response(400, "No tool ID provided")

        if self.current_tool is not None:
            if self.current_tool.get_id() == new_tool_id:
                return self.create_response(200, "This tool has already been selected")
            if self.current_tool.is_active:
                return self.create_response(400, "Current tool is still active, please retry later")

        # look for new tool in available tools array
        for tool in self.available_tools:
            if new_tool_id == tool.get_id():
                if tool.get_type() == "gripper" or tool.get_type() == "vacuum_pump":  # extra check for dynamixel tools
                    if not tool.is_connected():
                        return self.create_response(400, "Correct ID but Dynamixel tool is not connected")
                else:
                    self.ros_command_interface.ping_dxl_tool(0,
                                                             'No Dxl Tool')  # remove dxl tool if another kind of tool is selected
                self.current_tool = tool
                self.publish_current_tool_id(None)
                return self.create_response(200, "New tool has been selected, id : " + str(new_tool_id))

        # no tool found in available tools
        return self.create_response(400, "This ID does not match any available tool ID")

    @staticmethod
    def create_action_result(status, message):
        result = Tool.Result()
        result.status = status
        result.message = message
        return result

    @staticmethod
    def create_response(status, message):
        return {'status': status, 'message': message}

    def publish_current_tool_id(self):
        msg = Int32()
        if self.current_tool:
            msg.data = self.current_tool.id
        else:
            msg.data = 0
        self.current_tool_id_publisher.publish(msg)


def main():
    rclpy.init()
    ros_command_interface = ToolRosCommandInterface()
    tc = ToolController(ros_command_interface)

    try:
        rclpy.spin(tc)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        tc.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
