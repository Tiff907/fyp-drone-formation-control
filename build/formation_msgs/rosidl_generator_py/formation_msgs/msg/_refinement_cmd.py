# generated from rosidl_generator_py/resource/_idl.py.em
# with input from formation_msgs:msg/RefinementCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RefinementCmd(type):
    """Metaclass of message 'RefinementCmd'."""

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
                'formation_msgs.msg.RefinementCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__refinement_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__refinement_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__refinement_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__refinement_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__refinement_cmd

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


class RefinementCmd(metaclass=Metaclass_RefinementCmd):
    """Message class 'RefinementCmd'."""

    __slots__ = [
        '_instruction_text',
        '_current_points',
    ]

    _fields_and_field_types = {
        'instruction_text': 'string',
        'current_points': 'sequence<geometry_msgs/Point>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.instruction_text = kwargs.get('instruction_text', str())
        self.current_points = kwargs.get('current_points', [])

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
        if self.instruction_text != other.instruction_text:
            return False
        if self.current_points != other.current_points:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def instruction_text(self):
        """Message field 'instruction_text'."""
        return self._instruction_text

    @instruction_text.setter
    def instruction_text(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'instruction_text' field must be of type 'str'"
        self._instruction_text = value

    @builtins.property
    def current_points(self):
        """Message field 'current_points'."""
        return self._current_points

    @current_points.setter
    def current_points(self, value):
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
                "The 'current_points' field must be a set or sequence and each value of type 'Point'"
        self._current_points = value
