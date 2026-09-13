# generated from rosidl_generator_py/resource/_idl.py.em
# with input from formation_msgs:msg/FormationGoal.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'assigned_drone_ids'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FormationGoal(type):
    """Metaclass of message 'FormationGoal'."""

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
            module = import_type_support('formation_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'formation_msgs.msg.FormationGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__formation_goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__formation_goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__formation_goal
            cls._TYPE_SUPPORT = module.type_support_msg__msg__formation_goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__formation_goal

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import ColorRGBA
            if ColorRGBA.__class__._TYPE_SUPPORT is None:
                ColorRGBA.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FormationGoal(metaclass=Metaclass_FormationGoal):
    """Message class 'FormationGoal'."""

    __slots__ = [
        '_target_points',
        '_assigned_drone_ids',
        '_point_colors',
        '_formation_id',
        '_timestamp',
    ]

    _fields_and_field_types = {
        'target_points': 'sequence<geometry_msgs/Point>',
        'assigned_drone_ids': 'sequence<int32>',
        'point_colors': 'sequence<std_msgs/ColorRGBA>',
        'formation_id': 'uint32',
        'timestamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('int32')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'ColorRGBA')),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.target_points = kwargs.get('target_points', [])
        self.assigned_drone_ids = array.array('i', kwargs.get('assigned_drone_ids', []))
        self.point_colors = kwargs.get('point_colors', [])
        self.formation_id = kwargs.get('formation_id', int())
        from builtin_interfaces.msg import Time
        self.timestamp = kwargs.get('timestamp', Time())

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
        if self.target_points != other.target_points:
            return False
        if self.assigned_drone_ids != other.assigned_drone_ids:
            return False
        if self.point_colors != other.point_colors:
            return False
        if self.formation_id != other.formation_id:
            return False
        if self.timestamp != other.timestamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def target_points(self):
        """Message field 'target_points'."""
        return self._target_points

    @target_points.setter
    def target_points(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
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
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'target_points' field must be a set or sequence and each value of type 'Point'"
        self._target_points = value

    @builtins.property
    def assigned_drone_ids(self):
        """Message field 'assigned_drone_ids'."""
        return self._assigned_drone_ids

    @assigned_drone_ids.setter
    def assigned_drone_ids(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'i', \
                "The 'assigned_drone_ids' array.array() must have the type code of 'i'"
            self._assigned_drone_ids = value
            return
        if __debug__:
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
                "The 'assigned_drone_ids' field must be a set or sequence and each value of type 'int' and each integer in [-2147483648, 2147483647]"
        self._assigned_drone_ids = array.array('i', value)

    @builtins.property
    def point_colors(self):
        """Message field 'point_colors'."""
        return self._point_colors

    @point_colors.setter
    def point_colors(self, value):
        if __debug__:
            from std_msgs.msg import ColorRGBA
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
                 all(isinstance(v, ColorRGBA) for v in value) and
                 True), \
                "The 'point_colors' field must be a set or sequence and each value of type 'ColorRGBA'"
        self._point_colors = value

    @builtins.property
    def formation_id(self):
        """Message field 'formation_id'."""
        return self._formation_id

    @formation_id.setter
    def formation_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'formation_id' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'formation_id' field must be an unsigned integer in [0, 4294967295]"
        self._formation_id = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'timestamp' field must be a sub message of type 'Time'"
        self._timestamp = value
