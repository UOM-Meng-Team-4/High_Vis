# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hotspot_action:action/PanAndTilt.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PanAndTilt_Goal(type):
    """Metaclass of message 'PanAndTilt_Goal'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_Goal(metaclass=Metaclass_PanAndTilt_Goal):
    """Message class 'PanAndTilt_Goal'."""

    __slots__ = [
        '_pan',
        '_tilt',
    ]

    _fields_and_field_types = {
        'pan': 'double',
        'tilt': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pan = kwargs.get('pan', float())
        self.tilt = kwargs.get('tilt', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pan != other.pan:
            return False
        if self.tilt != other.tilt:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pan(self):
        """Message field 'pan'."""
        return self._pan

    @pan.setter
    def pan(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pan' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pan' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pan = value

    @builtins.property
    def tilt(self):
        """Message field 'tilt'."""
        return self._tilt

    @tilt.setter
    def tilt(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PanAndTilt_Result(type):
    """Metaclass of message 'PanAndTilt_Result'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_Result(metaclass=Metaclass_PanAndTilt_Result):
    """Message class 'PanAndTilt_Result'."""

    __slots__ = [
        '_move_finished',
    ]

    _fields_and_field_types = {
        'move_finished': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.move_finished = kwargs.get('move_finished', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.move_finished != other.move_finished:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def move_finished(self):
        """Message field 'move_finished'."""
        return self._move_finished

    @move_finished.setter
    def move_finished(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'move_finished' field must be of type 'bool'"
        self._move_finished = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_PanAndTilt_Feedback(type):
    """Metaclass of message 'PanAndTilt_Feedback'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_Feedback(metaclass=Metaclass_PanAndTilt_Feedback):
    """Message class 'PanAndTilt_Feedback'."""

    __slots__ = [
        '_pan_feedback',
        '_tilt_feedback',
    ]

    _fields_and_field_types = {
        'pan_feedback': 'double',
        'tilt_feedback': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pan_feedback = kwargs.get('pan_feedback', float())
        self.tilt_feedback = kwargs.get('tilt_feedback', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pan_feedback != other.pan_feedback:
            return False
        if self.tilt_feedback != other.tilt_feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pan_feedback(self):
        """Message field 'pan_feedback'."""
        return self._pan_feedback

    @pan_feedback.setter
    def pan_feedback(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pan_feedback' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pan_feedback' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pan_feedback = value

    @builtins.property
    def tilt_feedback(self):
        """Message field 'tilt_feedback'."""
        return self._tilt_feedback

    @tilt_feedback.setter
    def tilt_feedback(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tilt_feedback' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tilt_feedback' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tilt_feedback = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PanAndTilt_SendGoal_Request(type):
    """Metaclass of message 'PanAndTilt_SendGoal_Request'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__send_goal__request

            from hotspot_action.action import PanAndTilt
            if PanAndTilt.Goal.__class__._TYPE_SUPPORT is None:
                PanAndTilt.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_SendGoal_Request(metaclass=Metaclass_PanAndTilt_SendGoal_Request):
    """Message class 'PanAndTilt_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'hotspot_action/PanAndTilt_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hotspot_action', 'action'], 'PanAndTilt_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from hotspot_action.action._pan_and_tilt import PanAndTilt_Goal
        self.goal = kwargs.get('goal', PanAndTilt_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from hotspot_action.action._pan_and_tilt import PanAndTilt_Goal
            assert \
                isinstance(value, PanAndTilt_Goal), \
                "The 'goal' field must be a sub message of type 'PanAndTilt_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PanAndTilt_SendGoal_Response(type):
    """Metaclass of message 'PanAndTilt_SendGoal_Response'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_SendGoal_Response(metaclass=Metaclass_PanAndTilt_SendGoal_Response):
    """Message class 'PanAndTilt_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_PanAndTilt_SendGoal(type):
    """Metaclass of service 'PanAndTilt_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__pan_and_tilt__send_goal

            from hotspot_action.action import _pan_and_tilt
            if _pan_and_tilt.Metaclass_PanAndTilt_SendGoal_Request._TYPE_SUPPORT is None:
                _pan_and_tilt.Metaclass_PanAndTilt_SendGoal_Request.__import_type_support__()
            if _pan_and_tilt.Metaclass_PanAndTilt_SendGoal_Response._TYPE_SUPPORT is None:
                _pan_and_tilt.Metaclass_PanAndTilt_SendGoal_Response.__import_type_support__()


class PanAndTilt_SendGoal(metaclass=Metaclass_PanAndTilt_SendGoal):
    from hotspot_action.action._pan_and_tilt import PanAndTilt_SendGoal_Request as Request
    from hotspot_action.action._pan_and_tilt import PanAndTilt_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PanAndTilt_GetResult_Request(type):
    """Metaclass of message 'PanAndTilt_GetResult_Request'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_GetResult_Request(metaclass=Metaclass_PanAndTilt_GetResult_Request):
    """Message class 'PanAndTilt_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PanAndTilt_GetResult_Response(type):
    """Metaclass of message 'PanAndTilt_GetResult_Response'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__get_result__response

            from hotspot_action.action import PanAndTilt
            if PanAndTilt.Result.__class__._TYPE_SUPPORT is None:
                PanAndTilt.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_GetResult_Response(metaclass=Metaclass_PanAndTilt_GetResult_Response):
    """Message class 'PanAndTilt_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'hotspot_action/PanAndTilt_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hotspot_action', 'action'], 'PanAndTilt_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from hotspot_action.action._pan_and_tilt import PanAndTilt_Result
        self.result = kwargs.get('result', PanAndTilt_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
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
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from hotspot_action.action._pan_and_tilt import PanAndTilt_Result
            assert \
                isinstance(value, PanAndTilt_Result), \
                "The 'result' field must be a sub message of type 'PanAndTilt_Result'"
        self._result = value


class Metaclass_PanAndTilt_GetResult(type):
    """Metaclass of service 'PanAndTilt_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__pan_and_tilt__get_result

            from hotspot_action.action import _pan_and_tilt
            if _pan_and_tilt.Metaclass_PanAndTilt_GetResult_Request._TYPE_SUPPORT is None:
                _pan_and_tilt.Metaclass_PanAndTilt_GetResult_Request.__import_type_support__()
            if _pan_and_tilt.Metaclass_PanAndTilt_GetResult_Response._TYPE_SUPPORT is None:
                _pan_and_tilt.Metaclass_PanAndTilt_GetResult_Response.__import_type_support__()


class PanAndTilt_GetResult(metaclass=Metaclass_PanAndTilt_GetResult):
    from hotspot_action.action._pan_and_tilt import PanAndTilt_GetResult_Request as Request
    from hotspot_action.action._pan_and_tilt import PanAndTilt_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_PanAndTilt_FeedbackMessage(type):
    """Metaclass of message 'PanAndTilt_FeedbackMessage'."""

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
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__pan_and_tilt__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__pan_and_tilt__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__pan_and_tilt__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__pan_and_tilt__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__pan_and_tilt__feedback_message

            from hotspot_action.action import PanAndTilt
            if PanAndTilt.Feedback.__class__._TYPE_SUPPORT is None:
                PanAndTilt.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PanAndTilt_FeedbackMessage(metaclass=Metaclass_PanAndTilt_FeedbackMessage):
    """Message class 'PanAndTilt_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'hotspot_action/PanAndTilt_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hotspot_action', 'action'], 'PanAndTilt_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from hotspot_action.action._pan_and_tilt import PanAndTilt_Feedback
        self.feedback = kwargs.get('feedback', PanAndTilt_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from hotspot_action.action._pan_and_tilt import PanAndTilt_Feedback
            assert \
                isinstance(value, PanAndTilt_Feedback), \
                "The 'feedback' field must be a sub message of type 'PanAndTilt_Feedback'"
        self._feedback = value


class Metaclass_PanAndTilt(type):
    """Metaclass of action 'PanAndTilt'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('hotspot_action')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'hotspot_action.action.PanAndTilt')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__pan_and_tilt

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from hotspot_action.action import _pan_and_tilt
            if _pan_and_tilt.Metaclass_PanAndTilt_SendGoal._TYPE_SUPPORT is None:
                _pan_and_tilt.Metaclass_PanAndTilt_SendGoal.__import_type_support__()
            if _pan_and_tilt.Metaclass_PanAndTilt_GetResult._TYPE_SUPPORT is None:
                _pan_and_tilt.Metaclass_PanAndTilt_GetResult.__import_type_support__()
            if _pan_and_tilt.Metaclass_PanAndTilt_FeedbackMessage._TYPE_SUPPORT is None:
                _pan_and_tilt.Metaclass_PanAndTilt_FeedbackMessage.__import_type_support__()


class PanAndTilt(metaclass=Metaclass_PanAndTilt):

    # The goal message defined in the action definition.
    from hotspot_action.action._pan_and_tilt import PanAndTilt_Goal as Goal
    # The result message defined in the action definition.
    from hotspot_action.action._pan_and_tilt import PanAndTilt_Result as Result
    # The feedback message defined in the action definition.
    from hotspot_action.action._pan_and_tilt import PanAndTilt_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from hotspot_action.action._pan_and_tilt import PanAndTilt_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from hotspot_action.action._pan_and_tilt import PanAndTilt_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from hotspot_action.action._pan_and_tilt import PanAndTilt_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
