#!/usr/bin/env python

from niryo_one_tools.tools import ROS_COMMUNICATION_PROBLEM
import rclpy
from rclpy.node import Node

from niryo_one_msgs.srv import PingDxlTool
from niryo_one_msgs.srv import OpenGripper
from niryo_one_msgs.srv import CloseGripper
from niryo_one_msgs.srv import PullAirVacuumPump
from niryo_one_msgs.srv import PushAirVacuumPump
from niryo_one_msgs.srv import SetDigitalIO


class ToolRosCommandInterface(Node):

    def __init__(self):
        super().__init__('niryo_one_tools_interface')

        self.service_ping_dxl_tool = self.create_client(
            PingDxlTool, 'niryo_one/tools/ping_and_set_dxl_tool')

        self.service_open_gripper = self.create_client(
            OpenGripper, 'niryo_one/tools/open_gripper')
        self.service_close_gripper = self.create_client(
            CloseGripper, 'niryo_one/tools/close_gripper')

        self.service_pull_air_vacuum_pump = self.create_client(
            PullAirVacuumPump, 'niryo_one/tools/pull_air_vacuum_pump')
        self.service_push_air_vacuum_pump = self.create_client(
            PushAirVacuumPump, 'niryo_one/tools/push_air_vacuum_pump')

        self.service_setup_digital_output_tool = self.create_client(
            SetDigitalIO, 'niryo_one/rpi/set_digital_io_mode')
        self.service_activate_digital_output_tool = self.create_client(
            SetDigitalIO, 'niryo_one/rpi/set_digital_io_state')

        self.service_ping_dxl_tool.wait_for_service(timeout_sec=1.0)
        self.service_open_gripper.wait_for_service(timeout_sec=1.0)
        self.service_close_gripper.wait_for_service(timeout_sec=1.0)
        self.service_pull_air_vacuum_pump.wait_for_service(timeout_sec=1.0)
        self.service_push_air_vacuum_pump.wait_for_service(timeout_sec=1.0)

        self.get_logger().info(
            "Interface between Tools Controller and Ros Control has been started.")

    def ping_dxl_tool(self, tool_id, tool_name):
        try:
            if tool_id == 0:
                tool_name = "No Dxl Tool"
            resp = self.service_ping_dxl_tool(tool_id, tool_name)
            return resp.state
        except rclpy.ServiceException:
            return ROS_COMMUNICATION_PROBLEM

    def open_gripper(self, gripper_id, open_position, open_speed, open_hold_torque):
        try:
            resp = self.service_open_gripper(
                gripper_id, open_position, open_speed, open_hold_torque)
            return resp.state
        except rclpy.ServiceException:
            return ROS_COMMUNICATION_PROBLEM

    def close_gripper(self, gripper_id, close_position, close_speed, close_hold_torque, close_max_torque):
        try:
            resp = self.service_close_gripper(gripper_id, close_position, close_speed, close_hold_torque,
                                              close_max_torque)
            return resp.state
        except rclpy.ServiceException:
            return ROS_COMMUNICATION_PROBLEM

    def pull_air_vacuum_pump(self, vp_id, vp_pull_air_position, vp_pull_air_hold_torque):
        try:
            resp = self.service_pull_air_vacuum_pump(
                vp_id, vp_pull_air_position, vp_pull_air_hold_torque)
            return resp.state
        except rclpy.ServiceException:
            return ROS_COMMUNICATION_PROBLEM

    def push_air_vacuum_pump(self, vp_id, vp_push_air_position):
        try:
            resp = self.service_push_air_vacuum_pump(
                vp_id, vp_push_air_position)
            return resp.state
        except rclpy.ServiceException:
            return ROS_COMMUNICATION_PROBLEM

    def digital_output_tool_setup(self, gpio_pin):
        try:
            self.service_setup_digital_output_tool.wait_for_service(timeout_sec=2)
        except rclpy.ROSException:
            return 400, "Digital IO panel service is not connected"
        try:
            resp = self.service_setup_digital_output_tool(
                gpio_pin, 0)  # set output
            return resp.status, resp.message
        except rclpy.ServiceException:
            return 400, "Digital IO panel service failed"

    def digital_output_tool_activate(self, gpio_pin, activate):
        try:
            self.service_activate_digital_output_tool.wait_for_service(timeout_sec=2)
        except rclpy.ROSException:
            return 400, "Digital IO panel service is not connected"
        try:
            resp = self.service_activate_digital_output_tool(
                gpio_pin, activate)
            return resp.status, resp.message
        except rclpy.ServiceException:
            return 400, "Digital IO panel service failed"
