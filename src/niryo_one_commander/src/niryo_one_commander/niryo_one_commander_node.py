#!/usr/bin/env python

# niryo_one_commander_node.py
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
from rclpy.node import Node
from rclpy.executors import ExternalShutdownException
from position_manager import PositionManager
from trajectory_manager import TrajectoryManager
from niryo_one_robot_state_publisher import NiryoRobotStatePublisher
from robot_commander import RobotCommander

class NiryoOneCommanderNode(Node):

    def __init__(self, **kwargs):
        super().__init__('niryo_one_commander_node', **kwargs)

        # Publish robot state (position, orientation, tool)
        self.niryo_one_robot_state_publisher = NiryoRobotStatePublisher(self)

        # Position Manager
        positions_dir = self.declare_parameter("~positions_dir").value
        self.pos_manager = PositionManager(self, positions_dir)
        # trajectory_manager
        trajectories_dir = self.declare_parameter("~trajectories_dir").value
        self.traj_manager = TrajectoryManager(self, trajectories_dir)
        # robot commander
        self.robot_commander = RobotCommander(self, self.pos_manager, self.traj_manager)
        self.robot_commander.start()

def main():
    rclpy.init()
    niryo_one_commander_node = NiryoOneCommanderNode()

    try:
        rclpy.spin(niryo_one_commander_node)
    except (ExternalShutdownException, KeyboardInterrupt):
        pass
    finally:
        niryo_one_commander_node.destroy_node()
        rclpy.try_shutdown()

if __name__ == '__main__':
    main()
