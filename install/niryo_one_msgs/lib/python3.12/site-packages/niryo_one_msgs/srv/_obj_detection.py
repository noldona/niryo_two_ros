# generated from rosidl_generator_py/resource/_idl.py.em
# with input from niryo_one_msgs:srv/ObjDetection.idl
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


class Metaclass_ObjDetection_Request(type):
    """Metaclass of message 'ObjDetection_Request'."""

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
                'niryo_one_msgs.srv.ObjDetection_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__obj_detection__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__obj_detection__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__obj_detection__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__obj_detection__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__obj_detection__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObjDetection_Request(metaclass=Metaclass_ObjDetection_Request):
    """Message class 'ObjDetection_Request'."""

    __slots__ = [
        '_obj_type',
        '_obj_color',
        '_workspace_ratio',
        '_ret_image',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'obj_type': 'string',
        'obj_color': 'string',
        'workspace_ratio': 'float',
        'ret_image': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
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
        self.obj_type = kwargs.get('obj_type', str())
        self.obj_color = kwargs.get('obj_color', str())
        self.workspace_ratio = kwargs.get('workspace_ratio', float())
        self.ret_image = kwargs.get('ret_image', bool())

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
        if self.obj_type != other.obj_type:
            return False
        if self.obj_color != other.obj_color:
            return False
        if self.workspace_ratio != other.workspace_ratio:
            return False
        if self.ret_image != other.ret_image:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def obj_type(self):
        """Message field 'obj_type'."""
        return self._obj_type

    @obj_type.setter
    def obj_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'obj_type' field must be of type 'str'"
        self._obj_type = value

    @builtins.property
    def obj_color(self):
        """Message field 'obj_color'."""
        return self._obj_color

    @obj_color.setter
    def obj_color(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'obj_color' field must be of type 'str'"
        self._obj_color = value

    @builtins.property
    def workspace_ratio(self):
        """Message field 'workspace_ratio'."""
        return self._workspace_ratio

    @workspace_ratio.setter
    def workspace_ratio(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'workspace_ratio' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'workspace_ratio' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._workspace_ratio = value

    @builtins.property
    def ret_image(self):
        """Message field 'ret_image'."""
        return self._ret_image

    @ret_image.setter
    def ret_image(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'ret_image' field must be of type 'bool'"
        self._ret_image = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ObjDetection_Response(type):
    """Metaclass of message 'ObjDetection_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'SUCCESSFUL': 1,
        'VIDEO_STREAM_NOT_RUNNING': -1,
        'OBJECT_NOT_FOUND': -2,
        'MARKERS_NOT_FOUND': -3,
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
                'niryo_one_msgs.srv.ObjDetection_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__obj_detection__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__obj_detection__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__obj_detection__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__obj_detection__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__obj_detection__response

            from niryo_one_msgs.msg import ObjectPose
            if ObjectPose.__class__._TYPE_SUPPORT is None:
                ObjectPose.__class__.__import_type_support__()

            from sensor_msgs.msg import CompressedImage
            if CompressedImage.__class__._TYPE_SUPPORT is None:
                CompressedImage.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'SUCCESSFUL': cls.__constants['SUCCESSFUL'],
            'VIDEO_STREAM_NOT_RUNNING': cls.__constants['VIDEO_STREAM_NOT_RUNNING'],
            'OBJECT_NOT_FOUND': cls.__constants['OBJECT_NOT_FOUND'],
            'MARKERS_NOT_FOUND': cls.__constants['MARKERS_NOT_FOUND'],
        }

    @property
    def SUCCESSFUL(self):
        """Message constant 'SUCCESSFUL'."""
        return Metaclass_ObjDetection_Response.__constants['SUCCESSFUL']

    @property
    def VIDEO_STREAM_NOT_RUNNING(self):
        """Message constant 'VIDEO_STREAM_NOT_RUNNING'."""
        return Metaclass_ObjDetection_Response.__constants['VIDEO_STREAM_NOT_RUNNING']

    @property
    def OBJECT_NOT_FOUND(self):
        """Message constant 'OBJECT_NOT_FOUND'."""
        return Metaclass_ObjDetection_Response.__constants['OBJECT_NOT_FOUND']

    @property
    def MARKERS_NOT_FOUND(self):
        """Message constant 'MARKERS_NOT_FOUND'."""
        return Metaclass_ObjDetection_Response.__constants['MARKERS_NOT_FOUND']


class ObjDetection_Response(metaclass=Metaclass_ObjDetection_Response):
    """
    Message class 'ObjDetection_Response'.

    Constants:
      SUCCESSFUL
      VIDEO_STREAM_NOT_RUNNING
      OBJECT_NOT_FOUND
      MARKERS_NOT_FOUND
    """

    __slots__ = [
        '_status',
        '_obj_pose',
        '_obj_type',
        '_obj_color',
        '_img',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'status': 'int32',
        'obj_pose': 'niryo_one_msgs/ObjectPose',
        'obj_type': 'string',
        'obj_color': 'string',
        'img': 'sensor_msgs/CompressedImage',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'msg'], 'ObjectPose'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'CompressedImage'),  # noqa: E501
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
        from niryo_one_msgs.msg import ObjectPose
        self.obj_pose = kwargs.get('obj_pose', ObjectPose())
        self.obj_type = kwargs.get('obj_type', str())
        self.obj_color = kwargs.get('obj_color', str())
        from sensor_msgs.msg import CompressedImage
        self.img = kwargs.get('img', CompressedImage())

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
        if self.obj_pose != other.obj_pose:
            return False
        if self.obj_type != other.obj_type:
            return False
        if self.obj_color != other.obj_color:
            return False
        if self.img != other.img:
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
    def obj_pose(self):
        """Message field 'obj_pose'."""
        return self._obj_pose

    @obj_pose.setter
    def obj_pose(self, value):
        if self._check_fields:
            from niryo_one_msgs.msg import ObjectPose
            assert \
                isinstance(value, ObjectPose), \
                "The 'obj_pose' field must be a sub message of type 'ObjectPose'"
        self._obj_pose = value

    @builtins.property
    def obj_type(self):
        """Message field 'obj_type'."""
        return self._obj_type

    @obj_type.setter
    def obj_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'obj_type' field must be of type 'str'"
        self._obj_type = value

    @builtins.property
    def obj_color(self):
        """Message field 'obj_color'."""
        return self._obj_color

    @obj_color.setter
    def obj_color(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'obj_color' field must be of type 'str'"
        self._obj_color = value

    @builtins.property
    def img(self):
        """Message field 'img'."""
        return self._img

    @img.setter
    def img(self, value):
        if self._check_fields:
            from sensor_msgs.msg import CompressedImage
            assert \
                isinstance(value, CompressedImage), \
                "The 'img' field must be a sub message of type 'CompressedImage'"
        self._img = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ObjDetection_Event(type):
    """Metaclass of message 'ObjDetection_Event'."""

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
                'niryo_one_msgs.srv.ObjDetection_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__obj_detection__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__obj_detection__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__obj_detection__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__obj_detection__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__obj_detection__event

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


class ObjDetection_Event(metaclass=Metaclass_ObjDetection_Event):
    """Message class 'ObjDetection_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<niryo_one_msgs/ObjDetection_Request, 1>',
        'response': 'sequence<niryo_one_msgs/ObjDetection_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'srv'], 'ObjDetection_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['niryo_one_msgs', 'srv'], 'ObjDetection_Response'), 1),  # noqa: E501
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
            from niryo_one_msgs.srv import ObjDetection_Request
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
                 all(isinstance(v, ObjDetection_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ObjDetection_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from niryo_one_msgs.srv import ObjDetection_Response
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
                 all(isinstance(v, ObjDetection_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ObjDetection_Response'"
        self._response = value


class Metaclass_ObjDetection(type):
    """Metaclass of service 'ObjDetection'."""

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
                'niryo_one_msgs.srv.ObjDetection')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__obj_detection

            from niryo_one_msgs.srv import _obj_detection
            if _obj_detection.Metaclass_ObjDetection_Request._TYPE_SUPPORT is None:
                _obj_detection.Metaclass_ObjDetection_Request.__import_type_support__()
            if _obj_detection.Metaclass_ObjDetection_Response._TYPE_SUPPORT is None:
                _obj_detection.Metaclass_ObjDetection_Response.__import_type_support__()
            if _obj_detection.Metaclass_ObjDetection_Event._TYPE_SUPPORT is None:
                _obj_detection.Metaclass_ObjDetection_Event.__import_type_support__()


class ObjDetection(metaclass=Metaclass_ObjDetection):
    from niryo_one_msgs.srv._obj_detection import ObjDetection_Request as Request
    from niryo_one_msgs.srv._obj_detection import ObjDetection_Response as Response
    from niryo_one_msgs.srv._obj_detection import ObjDetection_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
