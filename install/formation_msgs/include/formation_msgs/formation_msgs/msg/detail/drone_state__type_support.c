// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from formation_msgs:msg/DroneState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "formation_msgs/msg/detail/drone_state__rosidl_typesupport_introspection_c.h"
#include "formation_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "formation_msgs/msg/detail/drone_state__functions.h"
#include "formation_msgs/msg/detail/drone_state__struct.h"


// Include directives for member types
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  formation_msgs__msg__DroneState__init(message_memory);
}

void formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_fini_function(void * message_memory)
{
  formation_msgs__msg__DroneState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_member_array[4] = {
  {
    "drone_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DroneState, drone_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DroneState, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "available",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DroneState, available),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "reached_target",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DroneState, reached_target),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_members = {
  "formation_msgs__msg",  // message namespace
  "DroneState",  // message name
  4,  // number of fields
  sizeof(formation_msgs__msg__DroneState),
  formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_member_array,  // message members
  formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_init_function,  // function to initialize message memory (memory has to be allocated)
  formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle = {
  0,
  &formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_formation_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, formation_msgs, msg, DroneState)() {
  formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle.typesupport_identifier) {
    formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &formation_msgs__msg__DroneState__rosidl_typesupport_introspection_c__DroneState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
