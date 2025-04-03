#!/usr/bin/env python

# niryo_one_robot_state_publisher.py
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

import rclpy
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from rclpy.timer import Timer
from rclpy.duration import Duration
from rclpy.time import Time
import tf2_ros
from tf2_ros import TransformException, LookupException, ConnectivityException, ExtrapolationException
from niryo_one_commander.moveit_utils import get_rpy_from_quaternion
from tf_transformations import quaternion_from_euler

# from std_msgs.msg import Float64
from niryo_one_msgs.msg import RobotState
from geometry_msgs.msg import Quaternion

PI = 3.14159

class NiryoRobotStatePublisher(Node):

    def __init__(self, **kwargs):
        super().__init__('niryo_one_robot_state_publisher', **kwargs)

        # Tf listener (position + rpy) of end effector tool
        self.position = [0, 0, 0]
        self.rpy = [0, 0, 0]
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer,self)

        # State publisher
        self.niryo_one_robot_state_publisher = self.create_publisher(
            RobotState, '/niryo_one/robot_state', queue_size=10)

        # Get params from rosparams
        rate_tf_listener = self.declare_parameter("/niryo_one/robot_state/rate_tf_listener").value
        rate_publish_state = self.declare_parameter("/niryo_one/robot_state/rate_publish_state").value

        Timer(Duration(1.0 / rate_tf_listener), self.get_robot_pose)
        Timer(Duration(1.0 / rate_publish_state), self.publish_state)

        self.get_logger().info("Started Niryo One robot state publisher")

    @staticmethod
    def get_orientation_from_angles(r, p, y):
        quaternion = quaternion_from_euler(r, p, y)
        orientation = Quaternion()
        orientation.x = quaternion[0]
        orientation.y = quaternion[1]
        orientation.z = quaternion[2]
        orientation.w = quaternion[3]
        return orientation

    def get_robot_pose(self, event):
        try:
            (pos, rot) = self.tf_buffer.lookup_transform('base_link', 'tool_link', Time(0))
            self.position = pos
            self.rpy = get_rpy_from_quaternion(rot)
        except (TransformException, LookupException, ConnectivityException, ExtrapolationException):
            self.get_logger().info("TF fail")

    def publish_state(self, event):
        msg = RobotState()
        msg.position.x = self.position[0]
        msg.position.y = self.position[1]
        msg.position.z = self.position[2]
        msg.rpy.roll = self.rpy[0]
        msg.rpy.pitch = self.rpy[1]
        msg.rpy.yaw = self.rpy[2]
        self.niryo_one_robot_state_publisher.publish(msg)

def main():
    rclpy.init()
    niryo_robot_state_publisher = NiryoRobotStatePublisher()

    try:
        rclpy.spin(niryo_robot_state_publisher)
    except (ExternalShutdownException, KeyboardInterrupt):
        pass
    finally:
        niryo_robot_state_publisher.destroy_node()
        rclpy.try_shutdown()

if __name__ == '__main__':
    main()