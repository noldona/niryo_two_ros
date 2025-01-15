# generated from rosidl_generator_py/resource/_idl.py.em
# with input from niryo_one_msgs:msg/RobotMoveCommand.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'joints'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotMoveCommand(type):
    """Metaclass of message 'RobotMoveCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('niryo_one_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'niryo_one_msgs.msg.RobotMoveCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__robot_move_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__robot_move_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__robot_move_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__robot_move_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__robot_move_command

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from niryo_one_msgs.msg import RPY
            if RPY.__class__._TYPE_SUPPORT is None:
                RPY.__class__.__import_type_support__()

            from niryo_one_msgs.msg import ShiftPose
            if ShiftPose.__class__._TYPE_SUPPORT is None:
                ShiftPose.__class__.__import_type_support__()

            from niryo_one_msgs.msg import ToolCommand
            if ToolCommand.__class__._TYPE_SUPPORT is None:
                ToolCommand.__class__.__import_type_support__()

            from niryo_one_msgs.msg import TrajectoryPlan
            if TrajectoryPlan.__class__._TYPE_SUPPORT is None:
                TrajectoryPlan.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotMoveCommand(metaclass=Metaclass_RobotMoveCommand):
    """Message class 'RobotMoveCommand'."""

    __slots__ = [
        '_cmd_type',
        '_joints',
        '_position',
        '_rpy',
        '_shift',
        '_trajectory',
        '_pose_quat',
        '_saved_position_name',
        '_saved_trajectory_id',
        '_tool_cmd',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'cmd_type': 'int32',
        'joints': 'sequence<double>',
        'position': 'geometry_msgs/Point',
        'rpy': 'niryo_one_msgs/RPY',
        'shift': 'niryo_one_msgs/ShiftPose',
        'trajectory': 'niryo_one_msgs/TrajectoryPlan',
        'pose_quat': 'geometry_msgs/Pose',
        'saved_position_name': 'string',
        'saved_trajectory_id': 'int32',
        'tool_cmd': 'niryo_one_msgs/ToolCommand',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'msg'], 'RPY'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'msg'], 'ShiftPose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'msg'], 'TrajectoryPlan'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'msg'], 'ToolCommand'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd_type = kwargs.get('cmd_type', int())
        self.joints = array.array('d', kwargs.get('joints', []))
        from geometry_msgs.msg import Point
        self.position = kwargs.get('position', Point())
        from niryo_one_msgs.msg import RPY
        self.rpy = kwargs.get('rpy', RPY())
        from niryo_one_msgs.msg import ShiftPose
        self.shift = kwargs.get('shift', ShiftPose())
        from niryo_one_msgs.msg import TrajectoryPlan
        self.trajectory = kwargs.get('trajectory', TrajectoryPlan())
        from geometry_msgs.msg import Pose
        self.pose_quat = kwargs.get('pose_quat', Pose())
        self.saved_position_name = kwargs.get('saved_position_name', str())
        self.saved_trajectory_id = kwargs.get('saved_trajectory_id', int())
        from niryo_one_msgs.msg import ToolCommand
        self.tool_cmd = kwargs.get('tool_cmd', ToolCommand())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.cmd_type != other.cmd_type:
            return False
        if self.joints != other.joints:
            return False
        if self.position != other.position:
            return False
        if self.rpy != other.rpy:
            return False
        if self.shift != other.shift:
            return False
        if self.trajectory != other.trajectory:
            return False
        if self.pose_quat != other.pose_quat:
            return False
        if self.saved_position_name != other.saved_position_name:
            return False
        if self.saved_trajectory_id != other.saved_trajectory_id:
            return False
        if self.tool_cmd != other.tool_cmd:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cmd_type(self):
        """Message field 'cmd_type'."""
        return self._cmd_type

    @cmd_type.setter
    def cmd_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'cmd_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'cmd_type' field must be an integer in [-2147483648, 2147483647]"
        self._cmd_type = value

    @builtins.property
    def joints(self):
        """Message field 'joints'."""
        return self._joints

    @joints.setter
    def joints(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'joints' array.array() must have the type code of 'd'"
                self._joints = value
                return
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'joints' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._joints = array.array('d', value)

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'position' field must be a sub message of type 'Point'"
        self._position = value

    @builtins.property
    def rpy(self):
        """Message field 'rpy'."""
        return self._rpy

    @rpy.setter
    def rpy(self, value):
        if self._check_fields:
            from niryo_one_msgs.msg import RPY
            assert \
                isinstance(value, RPY), \
                "The 'rpy' field must be a sub message of type 'RPY'"
        self._rpy = value

    @builtins.property
    def shift(self):
        """Message field 'shift'."""
        return self._shift

    @shift.setter
    def shift(self, value):
        if self._check_fields:
            from niryo_one_msgs.msg import ShiftPose
            assert \
                isinstance(value, ShiftPose), \
                "The 'shift' field must be a sub message of type 'ShiftPose'"
        self._shift = value

    @builtins.property
    def trajectory(self):
        """Message field 'trajectory'."""
        return self._trajectory

    @trajectory.setter
    def trajectory(self, value):
        if self._check_fields:
            from niryo_one_msgs.msg import TrajectoryPlan
            assert \
                isinstance(value, TrajectoryPlan), \
                "The 'trajectory' field must be a sub message of type 'TrajectoryPlan'"
        self._trajectory = value

    @builtins.property
    def pose_quat(self):
        """Message field 'pose_quat'."""
        return self._pose_quat

    @pose_quat.setter
    def pose_quat(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose_quat' field must be a sub message of type 'Pose'"
        self._pose_quat = value

    @builtins.property
    def saved_position_name(self):
        """Message field 'saved_position_name'."""
        return self._saved_position_name

    @saved_position_name.setter
    def saved_position_name(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'saved_position_name' field must be of type 'str'"
        self._saved_position_name = value

    @builtins.property
    def saved_trajectory_id(self):
        """Message field 'saved_trajectory_id'."""
        return self._saved_trajectory_id

    @saved_trajectory_id.setter
    def saved_trajectory_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'saved_trajectory_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'saved_trajectory_id' field must be an integer in [-2147483648, 2147483647]"
        self._saved_trajectory_id = value

    @builtins.property
    def tool_cmd(self):
        """Message field 'tool_cmd'."""
        return self._tool_cmd

    @tool_cmd.setter
    def tool_cmd(self, value):
        if self._check_fields:
            from niryo_one_msgs.msg import ToolCommand
            assert \
                isinstance(value, ToolCommand), \
                "The 'tool_cmd' field must be a sub message of type 'ToolCommand'"
        self._tool_cmd = value
