#!/usr/bin/env python

# moveit_utils.py
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

import tf_transformations
from niryo_one_commander.position.position import Position

def get_rpy_from_quaternion(rot):
    PI = 3.14159
    euler = tf_transformations.euler_from_quaternion(rot)
    rpy = [0, 0, 0]
    rpy[0] = euler[0]
    rpy[1] = euler[1]
    rpy[2] = euler[2]

    # force angle between -moveit_fk = self.fk_client.call_async(req)PI/PI
    for i, angle in enumerate(rpy):
        if angle > PI:
            rpy[i] = angle % (2 * PI) - 2 * PI
        elif angle < -PI:
            rpy[i] = angle % (2 * PI)
    return rpy


if __name__ == '__main__':
    pass
