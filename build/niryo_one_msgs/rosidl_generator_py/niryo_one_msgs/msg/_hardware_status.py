# generated from rosidl_generator_py/resource/_idl.py.em
# with input from niryo_one_msgs:msg/HardwareStatus.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

# Member 'temperatures'
# Member 'voltages'
# Member 'hardware_errors'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HardwareStatus(type):
    """Metaclass of message 'HardwareStatus'."""

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
                'niryo_one_msgs.msg.HardwareStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hardware_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hardware_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hardware_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hardware_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hardware_status

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HardwareStatus(metaclass=Metaclass_HardwareStatus):
    """Message class 'HardwareStatus'."""

    __slots__ = [
        '_header',
        '_rpi_temperature',
        '_hardware_version',
        '_connection_up',
        '_error_message',
        '_calibration_needed',
        '_calibration_in_progress',
        '_motor_names',
        '_motor_types',
        '_temperatures',
        '_voltages',
        '_hardware_errors',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'rpi_temperature': 'int32',
        'hardware_version': 'int32',
        'connection_up': 'boolean',
        'error_message': 'string',
        'calibration_needed': 'int32',
        'calibration_in_progress': 'boolean',
        'motor_names': 'sequence<string>',
        'motor_types': 'sequence<string>',
        'temperatures': 'sequence<int32>',
        'voltages': 'sequence<double>',
        'hardware_errors': 'sequence<int32>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
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
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.rpi_temperature = kwargs.get('rpi_temperature', int())
        self.hardware_version = kwargs.get('hardware_version', int())
        self.connection_up = kwargs.get('connection_up', bool())
        self.error_message = kwargs.get('error_message', str())
        self.calibration_needed = kwargs.get('calibration_needed', int())
        self.calibration_in_progress = kwargs.get('calibration_in_progress', bool())
        self.motor_names = kwargs.get('motor_names', [])
        self.motor_types = kwargs.get('motor_types', [])
        self.temperatures = array.array('i', kwargs.get('temperatures', []))
        self.voltages = array.array('d', kwargs.get('voltages', []))
        self.hardware_errors = array.array('i', kwargs.get('hardware_errors', []))

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
        if self.header != other.header:
            return False
        if self.rpi_temperature != other.rpi_temperature:
            return False
        if self.hardware_version != other.hardware_version:
            return False
        if self.connection_up != other.connection_up:
            return False
        if self.error_message != other.error_message:
            return False
        if self.calibration_needed != other.calibration_needed:
            return False
        if self.calibration_in_progress != other.calibration_in_progress:
            return False
        if self.motor_names != other.motor_names:
            return False
        if self.motor_types != other.motor_types:
            return False
        if self.temperatures != other.temperatures:
            return False
        if self.voltages != other.voltages:
            return False
        if self.hardware_errors != other.hardware_errors:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def rpi_temperature(self):
        """Message field 'rpi_temperature'."""
        return self._rpi_temperature

    @rpi_temperature.setter
    def rpi_temperature(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'rpi_temperature' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'rpi_temperature' field must be an integer in [-2147483648, 2147483647]"
        self._rpi_temperature = value

    @builtins.property
    def hardware_version(self):
        """Message field 'hardware_version'."""
        return self._hardware_version

    @hardware_version.setter
    def hardware_version(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'hardware_version' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'hardware_version' field must be an integer in [-2147483648, 2147483647]"
        self._hardware_version = value

    @builtins.property
    def connection_up(self):
        """Message field 'connection_up'."""
        return self._connection_up

    @connection_up.setter
    def connection_up(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'connection_up' field must be of type 'bool'"
        self._connection_up = value

    @builtins.property
    def error_message(self):
        """Message field 'error_message'."""
        return self._error_message

    @error_message.setter
    def error_message(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'error_message' field must be of type 'str'"
        self._error_message = value

    @builtins.property
    def calibration_needed(self):
        """Message field 'calibration_needed'."""
        return self._calibration_needed

    @calibration_needed.setter
    def calibration_needed(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'calibration_needed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'calibration_needed' field must be an integer in [-2147483648, 2147483647]"
        self._calibration_needed = value

    @builtins.property
    def calibration_in_progress(self):
        """Message field 'calibration_in_progress'."""
        return self._calibration_in_progress

    @calibration_in_progress.setter
    def calibration_in_progress(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'calibration_in_progress' field must be of type 'bool'"
        self._calibration_in_progress = value

    @builtins.property
    def motor_names(self):
        """Message field 'motor_names'."""
        return self._motor_names

    @motor_names.setter
    def motor_names(self, value):
        if self._check_fields:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'motor_names' field must be a set or sequence and each value of type 'str'"
        self._motor_names = value

    @builtins.property
    def motor_types(self):
        """Message field 'motor_types'."""
        return self._motor_types

    @motor_types.setter
    def motor_types(self, value):
        if self._check_fields:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'motor_types' field must be a set or sequence and each value of type 'str'"
        self._motor_types = value

    @builtins.property
    def temperatures(self):
        """Message field 'temperatures'."""
        return self._temperatures

    @temperatures.setter
    def temperatures(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'i', \
                    "The 'temperatures' array.array() must have the type code of 'i'"
                self._temperatures = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'temperatures' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._temperatures = array.array('i', value)

    @builtins.property
    def voltages(self):
        """Message field 'voltages'."""
        return self._voltages

    @voltages.setter
    def voltages(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'd', \
                    "The 'voltages' array.array() must have the type code of 'd'"
                self._voltages = value
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
                "The 'voltages' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._voltages = array.array('d', value)

    @builtins.property
    def hardware_errors(self):
        """Message field 'hardware_errors'."""
        return self._hardware_errors

    @hardware_errors.setter
    def hardware_errors(self, value):
        if self._check_fields:
            if isinstance(value, array.array):
                assert value.typecode == 'i', \
                    "The 'hardware_errors' array.array() must have the type code of 'i'"
                self._hardware_errors = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= -2147483648 and val < 2147483648 for val in value)), \
                "The 'hardware_errors' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._hardware_errors = array.array('i', value)
