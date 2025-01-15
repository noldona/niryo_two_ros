# generated from rosidl_generator_py/resource/_idl.py.em
# with input from niryo_one_msgs:msg/ConveyorFeedback.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ConveyorFeedback(type):
    """Metaclass of message 'ConveyorFeedback'."""

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
                'niryo_one_msgs.msg.ConveyorFeedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__conveyor_feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__conveyor_feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__conveyor_feedback
            cls._TYPE_SUPPORT = module.type_support_msg__msg__conveyor_feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__conveyor_feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ConveyorFeedback(metaclass=Metaclass_ConveyorFeedback):
    """Message class 'ConveyorFeedback'."""

    __slots__ = [
        '_conveyor_id',
        '_connection_state',
        '_running',
        '_speed',
        '_direction',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'conveyor_id': 'uint8',
        'connection_state': 'boolean',
        'running': 'boolean',
        'speed': 'int16',
        'direction': 'int8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
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
        self.conveyor_id = kwargs.get('conveyor_id', int())
        self.connection_state = kwargs.get('connection_state', bool())
        self.running = kwargs.get('running', bool())
        self.speed = kwargs.get('speed', int())
        self.direction = kwargs.get('direction', int())

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
        if self.conveyor_id != other.conveyor_id:
            return False
        if self.connection_state != other.connection_state:
            return False
        if self.running != other.running:
            return False
        if self.speed != other.speed:
            return False
        if self.direction != other.direction:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def conveyor_id(self):
        """Message field 'conveyor_id'."""
        return self._conveyor_id

    @conveyor_id.setter
    def conveyor_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'conveyor_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'conveyor_id' field must be an unsigned integer in [0, 255]"
        self._conveyor_id = value

    @builtins.property
    def connection_state(self):
        """Message field 'connection_state'."""
        return self._connection_state

    @connection_state.setter
    def connection_state(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'connection_state' field must be of type 'bool'"
        self._connection_state = value

    @builtins.property
    def running(self):
        """Message field 'running'."""
        return self._running

    @running.setter
    def running(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'running' field must be of type 'bool'"
        self._running = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'speed' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'speed' field must be an integer in [-32768, 32767]"
        self._speed = value

    @builtins.property
    def direction(self):
        """Message field 'direction'."""
        return self._direction

    @direction.setter
    def direction(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'direction' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'direction' field must be an integer in [-128, 127]"
        self._direction = value
