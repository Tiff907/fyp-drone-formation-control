# generated from rosidl_generator_py/resource/_idl.py.em
# with input from formation_msgs:msg/DroneState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DroneState(type):
    """Metaclass of message 'DroneState'."""

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
                'formation_msgs.msg.DroneState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__drone_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__drone_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__drone_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__drone_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__drone_state

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DroneState(metaclass=Metaclass_DroneState):
    """Message class 'DroneState'."""

    __slots__ = [
        '_drone_id',
        '_position',
        '_available',
        '_reached_target',
    ]

    _fields_and_field_types = {
        'drone_id': 'int32',
        'position': 'geometry_msgs/Point',
        'available': 'boolean',
        'reached_target': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.drone_id = kwargs.get('drone_id', int())
        from geometry_msgs.msg import Point
        self.position = kwargs.get('position', Point())
        self.available = kwargs.get('available', bool())
        self.reached_target = kwargs.get('reached_target', bool())

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
        if self.drone_id != other.drone_id:
            return False
        if self.position != other.position:
            return False
        if self.available != other.available:
            return False
        if self.reached_target != other.reached_target:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def drone_id(self):
        """Message field 'drone_id'."""
        return self._drone_id

    @drone_id.setter
    def drone_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'drone_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'drone_id' field must be an integer in [-2147483648, 2147483647]"
        self._drone_id = value

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'position' field must be a sub message of type 'Point'"
        self._position = value

    @builtins.property
    def available(self):
        """Message field 'available'."""
        return self._available

    @available.setter
    def available(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'available' field must be of type 'bool'"
        self._available = value

    @builtins.property
    def reached_target(self):
        """Message field 'reached_target'."""
        return self._reached_target

    @reached_target.setter
    def reached_target(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'reached_target' field must be of type 'bool'"
        self._reached_target = value
