# generated from rosidl_generator_py/resource/_idl.py.em
# with input from niryo_one_msgs:srv/GetTargetPose.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetTargetPose_Request(type):
    """Metaclass of message 'GetTargetPose_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'GRIP_AUTO': 'auto',
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
                'niryo_one_msgs.srv.GetTargetPose_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_target_pose__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_target_pose__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_target_pose__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_target_pose__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_target_pose__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'GRIP_AUTO': cls.__constants['GRIP_AUTO'],
        }

    @property
    def GRIP_AUTO(self):
        """Message constant 'GRIP_AUTO'."""
        return Metaclass_GetTargetPose_Request.__constants['GRIP_AUTO']


class GetTargetPose_Request(metaclass=Metaclass_GetTargetPose_Request):
    """
    Message class 'GetTargetPose_Request'.

    Constants:
      GRIP_AUTO
    """

    __slots__ = [
        '_workspace',
        '_grip',
        '_tool_id',
        '_height_offset',
        '_x_rel',
        '_y_rel',
        '_yaw_rel',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'workspace': 'string',
        'grip': 'string',
        'tool_id': 'int32',
        'height_offset': 'float',
        'x_rel': 'float',
        'y_rel': 'float',
        'yaw_rel': 'float',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.workspace = kwargs.get('workspace', str())
        self.grip = kwargs.get('grip', str())
        self.tool_id = kwargs.get('tool_id', int())
        self.height_offset = kwargs.get('height_offset', float())
        self.x_rel = kwargs.get('x_rel', float())
        self.y_rel = kwargs.get('y_rel', float())
        self.yaw_rel = kwargs.get('yaw_rel', float())

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
        if self.workspace != other.workspace:
            return False
        if self.grip != other.grip:
            return False
        if self.tool_id != other.tool_id:
            return False
        if self.height_offset != other.height_offset:
            return False
        if self.x_rel != other.x_rel:
            return False
        if self.y_rel != other.y_rel:
            return False
        if self.yaw_rel != other.yaw_rel:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def workspace(self):
        """Message field 'workspace'."""
        return self._workspace

    @workspace.setter
    def workspace(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'workspace' field must be of type 'str'"
        self._workspace = value

    @builtins.property
    def grip(self):
        """Message field 'grip'."""
        return self._grip

    @grip.setter
    def grip(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'grip' field must be of type 'str'"
        self._grip = value

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
            assert value >= -2147483648 and value < 2147483648, \
                "The 'tool_id' field must be an integer in [-2147483648, 2147483647]"
        self._tool_id = value

    @builtins.property
    def height_offset(self):
        """Message field 'height_offset'."""
        return self._height_offset

    @height_offset.setter
    def height_offset(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'height_offset' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'height_offset' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._height_offset = value

    @builtins.property
    def x_rel(self):
        """Message field 'x_rel'."""
        return self._x_rel

    @x_rel.setter
    def x_rel(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'x_rel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x_rel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x_rel = value

    @builtins.property
    def y_rel(self):
        """Message field 'y_rel'."""
        return self._y_rel

    @y_rel.setter
    def y_rel(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'y_rel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y_rel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y_rel = value

    @builtins.property
    def yaw_rel(self):
        """Message field 'yaw_rel'."""
        return self._yaw_rel

    @yaw_rel.setter
    def yaw_rel(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'yaw_rel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw_rel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw_rel = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetTargetPose_Response(type):
    """Metaclass of message 'GetTargetPose_Response'."""

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
                'niryo_one_msgs.srv.GetTargetPose_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_target_pose__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_target_pose__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_target_pose__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_target_pose__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_target_pose__response

            from niryo_one_msgs.msg import RobotState
            if RobotState.__class__._TYPE_SUPPORT is None:
                RobotState.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetTargetPose_Response(metaclass=Metaclass_GetTargetPose_Response):
    """Message class 'GetTargetPose_Response'."""

    __slots__ = [
        '_status',
        '_message',
        '_target_pose',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'status': 'int32',
        'message': 'string',
        'target_pose': 'niryo_one_msgs/RobotState',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'msg'], 'RobotState'),  # noqa: E501
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
        from niryo_one_msgs.msg import RobotState
        self.target_pose = kwargs.get('target_pose', RobotState())

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
        if self.target_pose != other.target_pose:
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

    @builtins.property
    def target_pose(self):
        """Message field 'target_pose'."""
        return self._target_pose

    @target_pose.setter
    def target_pose(self, value):
        if self._check_fields:
            from niryo_one_msgs.msg import RobotState
            assert \
                isinstance(value, RobotState), \
                "The 'target_pose' field must be a sub message of type 'RobotState'"
        self._target_pose = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetTargetPose_Event(type):
    """Metaclass of message 'GetTargetPose_Event'."""

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
                'niryo_one_msgs.srv.GetTargetPose_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_target_pose__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_target_pose__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_target_pose__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_target_pose__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_target_pose__event

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


class GetTargetPose_Event(metaclass=Metaclass_GetTargetPose_Event):
    """Message class 'GetTargetPose_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<niryo_one_msgs/GetTargetPose_Request, 1>',
        'response': 'sequence<niryo_one_msgs/GetTargetPose_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'srv'], 'GetTargetPose_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'srv'], 'GetTargetPose_Response'), 1),  # noqa: E501
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
            from niryo_one_msgs.srv import GetTargetPose_Request
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
                 all(isinstance(v, GetTargetPose_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'GetTargetPose_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from niryo_one_msgs.srv import GetTargetPose_Response
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
                 all(isinstance(v, GetTargetPose_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'GetTargetPose_Response'"
        self._response = value


class Metaclass_GetTargetPose(type):
    """Metaclass of service 'GetTargetPose'."""

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
                'niryo_one_msgs.srv.GetTargetPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_target_pose

            from niryo_one_msgs.srv import _get_target_pose
            if _get_target_pose.Metaclass_GetTargetPose_Request._TYPE_SUPPORT is None:
                _get_target_pose.Metaclass_GetTargetPose_Request.__import_type_support__()
            if _get_target_pose.Metaclass_GetTargetPose_Response._TYPE_SUPPORT is None:
                _get_target_pose.Metaclass_GetTargetPose_Response.__import_type_support__()
            if _get_target_pose.Metaclass_GetTargetPose_Event._TYPE_SUPPORT is None:
                _get_target_pose.Metaclass_GetTargetPose_Event.__import_type_support__()


class GetTargetPose(metaclass=Metaclass_GetTargetPose):
    from niryo_one_msgs.srv._get_target_pose import GetTargetPose_Request as Request
    from niryo_one_msgs.srv._get_target_pose import GetTargetPose_Response as Response
    from niryo_one_msgs.srv._get_target_pose import GetTargetPose_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
