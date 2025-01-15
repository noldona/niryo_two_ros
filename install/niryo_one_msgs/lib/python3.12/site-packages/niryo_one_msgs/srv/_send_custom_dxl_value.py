# generated from rosidl_generator_py/resource/_idl.py.em
# with input from niryo_one_msgs:srv/SendCustomDxlValue.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SendCustomDxlValue_Request(type):
    """Metaclass of message 'SendCustomDxlValue_Request'."""

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
                'niryo_one_msgs.srv.SendCustomDxlValue_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__send_custom_dxl_value__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__send_custom_dxl_value__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__send_custom_dxl_value__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__send_custom_dxl_value__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__send_custom_dxl_value__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SendCustomDxlValue_Request(metaclass=Metaclass_SendCustomDxlValue_Request):
    """Message class 'SendCustomDxlValue_Request'."""

    __slots__ = [
        '_motor_type',
        '_id',
        '_value',
        '_reg_address',
        '_byte_number',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'motor_type': 'int32',
        'id': 'uint8',
        'value': 'int32',
        'reg_address': 'int32',
        'byte_number': 'int32',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
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
        self.motor_type = kwargs.get('motor_type', int())
        self.id = kwargs.get('id', int())
        self.value = kwargs.get('value', int())
        self.reg_address = kwargs.get('reg_address', int())
        self.byte_number = kwargs.get('byte_number', int())

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
        if self.motor_type != other.motor_type:
            return False
        if self.id != other.id:
            return False
        if self.value != other.value:
            return False
        if self.reg_address != other.reg_address:
            return False
        if self.byte_number != other.byte_number:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def motor_type(self):
        """Message field 'motor_type'."""
        return self._motor_type

    @motor_type.setter
    def motor_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'motor_type' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'motor_type' field must be an integer in [-2147483648, 2147483647]"
        self._motor_type = value

    @builtins.property  # noqa: A003
    def id(self):  # noqa: A003
        """Message field 'id'."""
        return self._id

    @id.setter  # noqa: A003
    def id(self, value):  # noqa: A003
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'id' field must be an unsigned integer in [0, 255]"
        self._id = value

    @builtins.property
    def value(self):
        """Message field 'value'."""
        return self._value

    @value.setter
    def value(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'value' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'value' field must be an integer in [-2147483648, 2147483647]"
        self._value = value

    @builtins.property
    def reg_address(self):
        """Message field 'reg_address'."""
        return self._reg_address

    @reg_address.setter
    def reg_address(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'reg_address' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'reg_address' field must be an integer in [-2147483648, 2147483647]"
        self._reg_address = value

    @builtins.property
    def byte_number(self):
        """Message field 'byte_number'."""
        return self._byte_number

    @byte_number.setter
    def byte_number(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'byte_number' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'byte_number' field must be an integer in [-2147483648, 2147483647]"
        self._byte_number = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SendCustomDxlValue_Response(type):
    """Metaclass of message 'SendCustomDxlValue_Response'."""

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
                'niryo_one_msgs.srv.SendCustomDxlValue_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__send_custom_dxl_value__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__send_custom_dxl_value__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__send_custom_dxl_value__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__send_custom_dxl_value__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__send_custom_dxl_value__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SendCustomDxlValue_Response(metaclass=Metaclass_SendCustomDxlValue_Response):
    """Message class 'SendCustomDxlValue_Response'."""

    __slots__ = [
        '_status',
        '_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'status': 'int32',
        'message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.status = kwargs.get('status', int())
        self.message = kwargs.get('message', str())

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
        if self.status != other.status:
            return False
        if self.message != other.message:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'status' field must be an integer in [-2147483648, 2147483647]"
        self._status = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_SendCustomDxlValue_Event(type):
    """Metaclass of message 'SendCustomDxlValue_Event'."""

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
                'niryo_one_msgs.srv.SendCustomDxlValue_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__send_custom_dxl_value__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__send_custom_dxl_value__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__send_custom_dxl_value__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__send_custom_dxl_value__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__send_custom_dxl_value__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SendCustomDxlValue_Event(metaclass=Metaclass_SendCustomDxlValue_Event):
    """Message class 'SendCustomDxlValue_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<niryo_one_msgs/SendCustomDxlValue_Request, 1>',
        'response': 'sequence<niryo_one_msgs/SendCustomDxlValue_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'srv'], 'SendCustomDxlValue_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'srv'], 'SendCustomDxlValue_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from niryo_one_msgs.srv import SendCustomDxlValue_Request
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
                 len(value) <= 1 and
                 all(isinstance(v, SendCustomDxlValue_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'SendCustomDxlValue_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from niryo_one_msgs.srv import SendCustomDxlValue_Response
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
                 len(value) <= 1 and
                 all(isinstance(v, SendCustomDxlValue_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'SendCustomDxlValue_Response'"
        self._response = value


class Metaclass_SendCustomDxlValue(type):
    """Metaclass of service 'SendCustomDxlValue'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('niryo_one_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'niryo_one_msgs.srv.SendCustomDxlValue')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__send_custom_dxl_value

            from niryo_one_msgs.srv import _send_custom_dxl_value
            if _send_custom_dxl_value.Metaclass_SendCustomDxlValue_Request._TYPE_SUPPORT is None:
                _send_custom_dxl_value.Metaclass_SendCustomDxlValue_Request.__import_type_support__()
            if _send_custom_dxl_value.Metaclass_SendCustomDxlValue_Response._TYPE_SUPPORT is None:
                _send_custom_dxl_value.Metaclass_SendCustomDxlValue_Response.__import_type_support__()
            if _send_custom_dxl_value.Metaclass_SendCustomDxlValue_Event._TYPE_SUPPORT is None:
                _send_custom_dxl_value.Metaclass_SendCustomDxlValue_Event.__import_type_support__()


class SendCustomDxlValue(metaclass=Metaclass_SendCustomDxlValue):
    from niryo_one_msgs.srv._send_custom_dxl_value import SendCustomDxlValue_Request as Request
    from niryo_one_msgs.srv._send_custom_dxl_value import SendCustomDxlValue_Response as Response
    from niryo_one_msgs.srv._send_custom_dxl_value import SendCustomDxlValue_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
