# generated from rosidl_generator_py/resource/_idl.py.em
# with input from hotspot_action:action/Acoustic.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Acoustic_Goal(type):
    """Metaclass of message 'Acoustic_Goal'."""

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
                'hotspot_action.action.Acoustic_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Acoustic_Goal(metaclass=Metaclass_Acoustic_Goal):
    """Message class 'Acoustic_Goal'."""

    __slots__ = [
        '_take_ac_reading',
        '_measurement_point',
        '_pan_position',
        '_tilt_position',
    ]

    _fields_and_field_types = {
        'take_ac_reading': 'boolean',
        'measurement_point': 'int64',
        'pan_position': 'int64',
        'tilt_position': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.take_ac_reading = kwargs.get('take_ac_reading', bool())
        self.measurement_point = kwargs.get('measurement_point', int())
        self.pan_position = kwargs.get('pan_position', int())
        self.tilt_position = kwargs.get('tilt_position', int())

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
        if self.take_ac_reading != other.take_ac_reading:
            return False
        if self.measurement_point != other.measurement_point:
            return False
        if self.pan_position != other.pan_position:
            return False
        if self.tilt_position != other.tilt_position:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def take_ac_reading(self):
        """Message field 'take_ac_reading'."""
        return self._take_ac_reading

    @take_ac_reading.setter
    def take_ac_reading(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'take_ac_reading' field must be of type 'bool'"
        self._take_ac_reading = value

    @builtins.property
    def measurement_point(self):
        """Message field 'measurement_point'."""
        return self._measurement_point

    @measurement_point.setter
    def measurement_point(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'measurement_point' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'measurement_point' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._measurement_point = value

    @builtins.property
    def pan_position(self):
        """Message field 'pan_position'."""
        return self._pan_position

    @pan_position.setter
    def pan_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pan_position' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'pan_position' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._pan_position = value

    @builtins.property
    def tilt_position(self):
        """Message field 'tilt_position'."""
        return self._tilt_position

    @tilt_position.setter
    def tilt_position(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tilt_position' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'tilt_position' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._tilt_position = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Acoustic_Result(type):
    """Metaclass of message 'Acoustic_Result'."""

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
                'hotspot_action.action.Acoustic_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Acoustic_Result(metaclass=Metaclass_Acoustic_Result):
    """Message class 'Acoustic_Result'."""

    __slots__ = [
        '_ac_save_path',
    ]

    _fields_and_field_types = {
        'ac_save_path': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ac_save_path = kwargs.get('ac_save_path', str())

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
        if self.ac_save_path != other.ac_save_path:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ac_save_path(self):
        """Message field 'ac_save_path'."""
        return self._ac_save_path

    @ac_save_path.setter
    def ac_save_path(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'ac_save_path' field must be of type 'str'"
        self._ac_save_path = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_Acoustic_Feedback(type):
    """Metaclass of message 'Acoustic_Feedback'."""

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
                'hotspot_action.action.Acoustic_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Acoustic_Feedback(metaclass=Metaclass_Acoustic_Feedback):
    """Message class 'Acoustic_Feedback'."""

    __slots__ = [
    ]

    _fields_and_field_types = {
    }

    SLOT_TYPES = (
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))

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
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Acoustic_SendGoal_Request(type):
    """Metaclass of message 'Acoustic_SendGoal_Request'."""

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
                'hotspot_action.action.Acoustic_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__send_goal__request

            from hotspot_action.action import Acoustic
            if Acoustic.Goal.__class__._TYPE_SUPPORT is None:
                Acoustic.Goal.__class__.__import_type_support__()

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


class Acoustic_SendGoal_Request(metaclass=Metaclass_Acoustic_SendGoal_Request):
    """Message class 'Acoustic_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'hotspot_action/Acoustic_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hotspot_action', 'action'], 'Acoustic_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from hotspot_action.action._acoustic import Acoustic_Goal
        self.goal = kwargs.get('goal', Acoustic_Goal())

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
            from hotspot_action.action._acoustic import Acoustic_Goal
            assert \
                isinstance(value, Acoustic_Goal), \
                "The 'goal' field must be a sub message of type 'Acoustic_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Acoustic_SendGoal_Response(type):
    """Metaclass of message 'Acoustic_SendGoal_Response'."""

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
                'hotspot_action.action.Acoustic_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__send_goal__response

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


class Acoustic_SendGoal_Response(metaclass=Metaclass_Acoustic_SendGoal_Response):
    """Message class 'Acoustic_SendGoal_Response'."""

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


class Metaclass_Acoustic_SendGoal(type):
    """Metaclass of service 'Acoustic_SendGoal'."""

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
                'hotspot_action.action.Acoustic_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__acoustic__send_goal

            from hotspot_action.action import _acoustic
            if _acoustic.Metaclass_Acoustic_SendGoal_Request._TYPE_SUPPORT is None:
                _acoustic.Metaclass_Acoustic_SendGoal_Request.__import_type_support__()
            if _acoustic.Metaclass_Acoustic_SendGoal_Response._TYPE_SUPPORT is None:
                _acoustic.Metaclass_Acoustic_SendGoal_Response.__import_type_support__()


class Acoustic_SendGoal(metaclass=Metaclass_Acoustic_SendGoal):
    from hotspot_action.action._acoustic import Acoustic_SendGoal_Request as Request
    from hotspot_action.action._acoustic import Acoustic_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Acoustic_GetResult_Request(type):
    """Metaclass of message 'Acoustic_GetResult_Request'."""

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
                'hotspot_action.action.Acoustic_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__get_result__request

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


class Acoustic_GetResult_Request(metaclass=Metaclass_Acoustic_GetResult_Request):
    """Message class 'Acoustic_GetResult_Request'."""

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


class Metaclass_Acoustic_GetResult_Response(type):
    """Metaclass of message 'Acoustic_GetResult_Response'."""

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
                'hotspot_action.action.Acoustic_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__get_result__response

            from hotspot_action.action import Acoustic
            if Acoustic.Result.__class__._TYPE_SUPPORT is None:
                Acoustic.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Acoustic_GetResult_Response(metaclass=Metaclass_Acoustic_GetResult_Response):
    """Message class 'Acoustic_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'hotspot_action/Acoustic_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hotspot_action', 'action'], 'Acoustic_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from hotspot_action.action._acoustic import Acoustic_Result
        self.result = kwargs.get('result', Acoustic_Result())

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
            from hotspot_action.action._acoustic import Acoustic_Result
            assert \
                isinstance(value, Acoustic_Result), \
                "The 'result' field must be a sub message of type 'Acoustic_Result'"
        self._result = value


class Metaclass_Acoustic_GetResult(type):
    """Metaclass of service 'Acoustic_GetResult'."""

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
                'hotspot_action.action.Acoustic_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__acoustic__get_result

            from hotspot_action.action import _acoustic
            if _acoustic.Metaclass_Acoustic_GetResult_Request._TYPE_SUPPORT is None:
                _acoustic.Metaclass_Acoustic_GetResult_Request.__import_type_support__()
            if _acoustic.Metaclass_Acoustic_GetResult_Response._TYPE_SUPPORT is None:
                _acoustic.Metaclass_Acoustic_GetResult_Response.__import_type_support__()


class Acoustic_GetResult(metaclass=Metaclass_Acoustic_GetResult):
    from hotspot_action.action._acoustic import Acoustic_GetResult_Request as Request
    from hotspot_action.action._acoustic import Acoustic_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Acoustic_FeedbackMessage(type):
    """Metaclass of message 'Acoustic_FeedbackMessage'."""

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
                'hotspot_action.action.Acoustic_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__acoustic__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__acoustic__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__acoustic__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__acoustic__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__acoustic__feedback_message

            from hotspot_action.action import Acoustic
            if Acoustic.Feedback.__class__._TYPE_SUPPORT is None:
                Acoustic.Feedback.__class__.__import_type_support__()

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


class Acoustic_FeedbackMessage(metaclass=Metaclass_Acoustic_FeedbackMessage):
    """Message class 'Acoustic_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'hotspot_action/Acoustic_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['hotspot_action', 'action'], 'Acoustic_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from hotspot_action.action._acoustic import Acoustic_Feedback
        self.feedback = kwargs.get('feedback', Acoustic_Feedback())

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
            from hotspot_action.action._acoustic import Acoustic_Feedback
            assert \
                isinstance(value, Acoustic_Feedback), \
                "The 'feedback' field must be a sub message of type 'Acoustic_Feedback'"
        self._feedback = value


class Metaclass_Acoustic(type):
    """Metaclass of action 'Acoustic'."""

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
                'hotspot_action.action.Acoustic')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__acoustic

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from hotspot_action.action import _acoustic
            if _acoustic.Metaclass_Acoustic_SendGoal._TYPE_SUPPORT is None:
                _acoustic.Metaclass_Acoustic_SendGoal.__import_type_support__()
            if _acoustic.Metaclass_Acoustic_GetResult._TYPE_SUPPORT is None:
                _acoustic.Metaclass_Acoustic_GetResult.__import_type_support__()
            if _acoustic.Metaclass_Acoustic_FeedbackMessage._TYPE_SUPPORT is None:
                _acoustic.Metaclass_Acoustic_FeedbackMessage.__import_type_support__()


class Acoustic(metaclass=Metaclass_Acoustic):

    # The goal message defined in the action definition.
    from hotspot_action.action._acoustic import Acoustic_Goal as Goal
    # The result message defined in the action definition.
    from hotspot_action.action._acoustic import Acoustic_Result as Result
    # The feedback message defined in the action definition.
    from hotspot_action.action._acoustic import Acoustic_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from hotspot_action.action._acoustic import Acoustic_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from hotspot_action.action._acoustic import Acoustic_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from hotspot_action.action._acoustic import Acoustic_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
