#!/usr/bin/env python

# position_manager.py 
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


import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from niryo_one_commander.position.position import Position
from niryo_one_commander.niryo_one_file_exception import NiryoOneFileException
from niryo_one_commander.position.position_file_handler import PositionFileHandler
from niryo_one_commander.position.position_command_type import PositionCommandType
from niryo_one_commander.robot_commander_exception import RobotCommanderException
from niryo_one_commander.parameters_validation import ParametersValidation
from niryo_one_commander.moveit_utils import get_rpy_from_quaternion

from niryo_one_msgs.msg import Position as PositionMessage
from niryo_one_msgs.msg import Sequence as SequenceMessage
from niryo_one_msgs.srv import GetPositionList
from niryo_one_msgs.srv import ManagePosition
from niryo_one_msgs.msg import RPY
from geometry_msgs.msg import Point
from geometry_msgs.msg import Quaternion
from moveit_msgs.msg import RobotState
from moveit_msgs.srv import GetPositionFK
from std_msgs.msg import Header


class PositionManager:

    def __init__(self, node:Node, position_dir):
        self.node = node
        
        self.fh = PositionFileHandler(position_dir)
        self.manage_position_server = self.node.create_service(ManagePosition, 
                                                    '/niryo_one/position/manage_position',
                                                    self.callback_manage_position)
        self.node.get_logger().info("Service manage position created")

        self.get_position_list_server = self.node.create_service(
            GetPositionList, '/niryo_one/position/get_position_list', self.callback_get_position_list)
        self.node.get_logger().info("Get list position created")

        self.validation = self.node.declare_parameter("/niryo_one/robot_command_validation",True).value
        self.parameters_validation = ParametersValidation(self.node, self.validation)

        self.fk_client = self.node.create_client(GetPositionFK, 'compute_fk')
        while not self.fk_client.wait_for_service(timeout_sec=2.0):
            self.node.get_logger().error('Service call failed, waiting again...')

    @staticmethod
    def create_position_response(status, message, position:PositionMessage=None):
        position_msg = PositionMessage()
        if position is not None:
            position_msg.name = position.name
            position_msg.joints = position.joints
            position_msg.rpy = Position.RPY(position.rpy.roll, position.rpy.pitch, position.rpy.yaw)
            position_msg.point = Position.Point(position.point.x, position.point.y, position.point.z)
            position_msg.quaternion = Position.Quaternion(position.quaternion.x, position.quaternion.y,
                                                          position.quaternion.z, position.quaternion.w)
        return {'status': status, 'message': message, 'position': position_msg}
    
    @staticmethod
    def create_sequence_response(status, message, sequence:SequenceMessage=None):
        seq_msg = SequenceMessage()
        if sequence is not None:
            seq_msg.id = sequence.id
            seq_msg.name = sequence.name
            seq_msg.description = sequence.description
            seq_msg.created = sequence.created
            seq_msg.updated = sequence.updated
            seq_msg.blockly_xml = sequence.blockly_xml
            seq_msg.python_code = sequence.python_code
        return {'status': status, 'message': message, 'sequence': seq_msg}


    def callback_manage_position(self, req:ManagePosition.Request):
        cmd_type = req.cmd_type
        position_name = req.position_name
        position_msg = req.position
        rpy = Position.RPY(position_msg.rpy.roll, position_msg.rpy.pitch, position_msg.rpy.yaw)
        point = Position.Point(position_msg.point.x, position_msg.point.y, position_msg.point.z)
        quaternion = Position.Quaternion(position_msg.quaternion.x, position_msg.quaternion.y,
                                         position_msg.quaternion.z,
                                         position_msg.quaternion.w)
        position_data = Position(name=position_msg.name,
                                 joints=position_msg.joints, rpy=rpy, point=point, quaternion=quaternion)

        # GET an existing position 
        if cmd_type == PositionCommandType.GET:
            pos = self.get_position(position_name)
            if pos is None:
                return self.create_position_response(400, "No position found with name : " + str(position_name))
            return self.create_position_response(200, "Position has been found", pos)

        # CREATE new position    
        elif cmd_type == PositionCommandType.CREATE:
            (new_position_name, msg) = self.create_new_position(position_data)
            if new_position_name is None:
                return self.create_position_response(400, msg)
            new_position = self.get_position(new_position_name)
            if new_position is None:
                return self.create_position_response(400, "Failed to create new position")
            return self.create_position_response(200, msg, new_position)

        # UPDATE existing sequence
        elif cmd_type == PositionCommandType.UPDATE:
            pos = self.get_position(position_name)
            if pos is None:
                return self.create_position_response(400, "No position found with name : " + position_name)
            (success, update_msg) = self.update_position(pos, position_data)
            if not success:
                return self.create_position_response(400, update_msg)
            return self.create_position_response(200, update_msg, pos)

        # DELETE sequence
        elif cmd_type == PositionCommandType.DELETE:
            success = self.delete_position(position_name)
            if not success:
                return self.create_position_response(400, "Could not delete position with name : " + position_name)
            return self.create_position_response(200, "Position has been deleted")

        # Wrong cmd_type 
        else:
            return self.create_sequence_response(400, "Wrong command type")

    def delete_position(self, position_name):
        try:
            self.fh.remove_position(position_name)
        except NiryoOneFileException as e:
            return False
        return True

    def update_position(self, position:Position, position_data:Position):
        try:
            self.parameters_validation.validate_joints(position_data.joints)
        except RobotCommanderException as e:
            self.node.get_logger().warn("Invalid joints value when updating position : " + str(e.message))
            return False, "Could not update position : " + str(e.message)
        position.joints = position_data.joints
        (position.point, position.rpy, position.quaternion) = self.get_forward_kinematic(position.joints)
        try:
            self.fh.write_position(position)
        except NiryoOneFileException as e:
            return False, "Could not update position : " + str(e)
        return True, "Position has been updated"

    def get_position(self, position_name):
        try:
            return self.fh.read_position(position_name)
        except NiryoOneFileException as e:
            return None

    def create_new_position(self, position:Position):
        position.name = position.name.rstrip()
        if not self.fh.check_position_name(position.name):
            return None, "Failed to create new position : position " + str(position.name) + " already exists"
        try:
            self.parameters_validation.validate_joints(position.joints)
        except RobotCommanderException as e:
            self.node.get_logger().warn("Invalid joints values when creating position : " + str(e.message))
            return None, "Failed to create new position : " + str(e.message)
        try:
            (position.point, position.rpy, position.quaternion) = self.get_forward_kinematic(position.joints)
            self.fh.write_position(position)
            return position.name, "Position has been created"
        except NiryoOneFileException as e:
            return None, "Failed to create new position : " + str(e)

    def callback_get_position_list(self, req=None):
        pos_list = self.get_all_positions()
        msg_list = []
        for pos in pos_list:
            position_msg = PositionMessage()
            position_msg.name = pos.name
            position_msg.joints = pos.joints
            position_msg.rpy = Position.RPY(pos.rpy.roll, pos.rpy.pitch, pos.rpy.yaw)
            position_msg.point = Position.Point(pos.point.x, pos.point.y, pos.point.z)
            position_msg.quaternion = Position.Quaternion(pos.quaternion.x, pos.quaternion.y,
                                                          pos.quaternion.z, pos.quaternion.w)
            msg_list.append(position_msg)
        return {'positions': msg_list}

    def get_all_positions(self):
        filenames = self.fh.get_all_filenames()
        position_list = []
        for f in filenames:
            try:
                position_name = self.fh.position_name_from_filename(f)
                pos = self.get_position(position_name)
                if pos is not None:
                    position_list.append(pos)
            except NiryoOneFileException as e:
                pass
        return position_list
    
    def get_forward_kinematic(self, joints:GetPositionFK.Request):
        fk_link = ['base_link', 'tool_link']
        joint_names = ['joint_1', 'joint_2', 'joint_3', 'joint_4', 'joint_5', 'joint_6']
        header = Header(0, self.node.get_clock().now().to_msg(), "/world")
        rs = RobotState()
        rs.joint_state.name = joint_names
        rs.joint_state.position = joints
        moveit_fk_request = GetPositionFK.Request(header, fk_link, rs)
        
        while not self.fk_client.wait_for_service(timeout_sec=2.0):
            self.node.get_logger().warn('Niryo ROS Forward Kinematic service is not up!')

        future = self.fk_client.call_async(moveit_fk_request)
        response:GetPositionFK.Response = future.result()
    
        quaternion = [response.pose_stamped[1].pose.orientation.x, response.pose_stamped[1].pose.orientation.y,
                    response.pose_stamped[1].pose.orientation.z, response.pose_stamped[1].pose.orientation.w]
        rpy = get_rpy_from_quaternion(quaternion)
        quaternion = Position.Quaternion(round(quaternion[0], 3), round(quaternion[1], 3), round(quaternion[2], 3),
                                        round(quaternion[3], 3))
        point = Position.Point(round(response.pose_stamped[1].pose.position.x, 3),
                            round(response.pose_stamped[1].pose.position.y, 3),
                            round(response.pose_stamped[1].pose.position.z, 3))
        rpy = Position.RPY(round(rpy[0], 3), round(rpy[1], 3), round(rpy[2], 3))
        self.node.get_logger().info("kinematic forward has been calculated ")
        return point, rpy, quaternion

if __name__ == '__main__':
    pass
