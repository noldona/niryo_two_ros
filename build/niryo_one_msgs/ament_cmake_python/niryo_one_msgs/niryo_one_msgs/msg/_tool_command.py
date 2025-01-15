# generated from rosidl_generator_py/resource/_idl.py.em
# with input from niryo_one_msgs:msg/ToolCommand.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ToolCommand(type):
    """Metaclass of message 'ToolCommand'."""

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
                'niryo_one_msgs.msg.ToolCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tool_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tool_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tool_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tool_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tool_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ToolCommand(metaclass=Metaclass_ToolCommand):
    """Message class 'ToolCommand'."""

    __slots__ = [
        '_tool_id',
        '_cmd_type',
        '_gripper_close_speed',
        '_gripper_open_speed',
        '_activate',
        '_gpio',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'tool_id': 'uint8',
        'cmd_type': 'uint8',
        'gripper_close_speed': 'uint16',
        'gripper_open_speed': 'uint16',
        'activate': 'boolean',
        'gpio': 'uint8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.tool_id = kwargs.get('tool_id', int())
        self.cmd_type = kwargs.get('cmd_type', int())
        self.gripper_close_speed = kwargs.get('gripper_close_speed', int())
        self.gripper_open_speed = kwargs.get('gripper_open_speed', int())
        self.activate = kwargs.get('activate', bool())
        self.gpio = kwargs.get('gpio', int())

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
        if self.tool_id != other.tool_id:
            return False
        if self.cmd_type != other.cmd_type:
            return False
        if self.gripper_close_speed != other.gripper_close_speed:
            return False
        if self.gripper_open_speed != other.gripper_open_speed:
            return False
        if self.activate != other.activate:
            return False
        if self.gpio != other.gpio:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def tool_id(self):
        """Message field 'tool_id'."""
        return self._tool_id

    @tool_id.setter
    def tool_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'tool_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'tool_id' field must be an unsigned integer in [0, 255]"
        self._tool_id = value

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
            assert value >= 0 and value < 256, \
                "The 'cmd_type' field must be an unsigned integer in [0, 255]"
        self._cmd_type = value

    @builtins.property
    def gripper_close_speed(self):
        """Message field 'gripper_close_speed'."""
        return self._gripper_close_speed

    @gripper_close_speed.setter
    def gripper_close_speed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gripper_close_speed' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'gripper_close_speed' field must be an unsigned integer in [0, 65535]"
        self._gripper_close_speed = value

    @builtins.property
    def gripper_open_speed(self):
        """Message field 'gripper_open_speed'."""
        return self._gripper_open_speed

    @gripper_open_speed.setter
    def gripper_open_speed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gripper_open_speed' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'gripper_open_speed' field must be an unsigned integer in [0, 65535]"
        self._gripper_open_speed = value

    @builtins.property
    def activate(self):
        """Message field 'activate'."""
        return self._activate

    @activate.setter
    def activate(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'activate' field must be of type 'bool'"
        self._activate = value

    @builtins.property
    def gpio(self):
        """Message field 'gpio'."""
        return self._gpio

    @gpio.setter
    def gpio(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gpio' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gpio' field must be an unsigned integer in [0, 255]"
        self._gpio = value
