// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from formation_msgs:msg/DronePath.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "formation_msgs/msg/detail/drone_path__rosidl_typesupport_introspection_c.h"
#include "formation_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "formation_msgs/msg/detail/drone_path__functions.h"
#include "formation_msgs/msg/detail/drone_path__struct.h"


// Include directives for member types
// Member `waypoints`
#include "geometry_msgs/msg/point.h"
// Member `waypoints`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `waypoint_times`
// Member `formation_start_time`
#include "builtin_interfaces/msg/time.h"
// Member `waypoint_times`
// Member `formation_start_time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  formation_msgs__msg__DronePath__init(message_memory);
}

void formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_fini_function(void * message_memory)
{
  formation_msgs__msg__DronePath__fini(message_memory);
}

size_t formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__size_function__DronePath__waypoints(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_const_function__DronePath__waypoints(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_function__DronePath__waypoints(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__fetch_function__DronePath__waypoints(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_const_function__DronePath__waypoints(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__assign_function__DronePath__waypoints(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_function__DronePath__waypoints(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__resize_function__DronePath__waypoints(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__size_function__DronePath__waypoint_times(
  const void * untyped_member)
{
  const builtin_interfaces__msg__Time__Sequence * member =
    (const builtin_interfaces__msg__Time__Sequence *)(untyped_member);
  return member->size;
}

const void * formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_const_function__DronePath__waypoint_times(
  const void * untyped_member, size_t index)
{
  const builtin_interfaces__msg__Time__Sequence * member =
    (const builtin_interfaces__msg__Time__Sequence *)(untyped_member);
  return &member->data[index];
}

void * formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_function__DronePath__waypoint_times(
  void * untyped_member, size_t index)
{
  builtin_interfaces__msg__Time__Sequence * member =
    (builtin_interfaces__msg__Time__Sequence *)(untyped_member);
  return &member->data[index];
}

void formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__fetch_function__DronePath__waypoint_times(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const builtin_interfaces__msg__Time * item =
    ((const builtin_interfaces__msg__Time *)
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_const_function__DronePath__waypoint_times(untyped_member, index));
  builtin_interfaces__msg__Time * value =
    (builtin_interfaces__msg__Time *)(untyped_value);
  *value = *item;
}

void formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__assign_function__DronePath__waypoint_times(
  void * untyped_member, size_t index, const void * untyped_value)
{
  builtin_interfaces__msg__Time * item =
    ((builtin_interfaces__msg__Time *)
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_function__DronePath__waypoint_times(untyped_member, index));
  const builtin_interfaces__msg__Time * value =
    (const builtin_interfaces__msg__Time *)(untyped_value);
  *item = *value;
}

bool formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__resize_function__DronePath__waypoint_times(
  void * untyped_member, size_t size)
{
  builtin_interfaces__msg__Time__Sequence * member =
    (builtin_interfaces__msg__Time__Sequence *)(untyped_member);
  builtin_interfaces__msg__Time__Sequence__fini(member);
  return builtin_interfaces__msg__Time__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_member_array[4] = {
  {
    "drone_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DronePath, drone_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DronePath, waypoints),  // bytes offset in struct
    NULL,  // default value
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__size_function__DronePath__waypoints,  // size() function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_const_function__DronePath__waypoints,  // get_const(index) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_function__DronePath__waypoints,  // get(index) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__fetch_function__DronePath__waypoints,  // fetch(index, &value) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__assign_function__DronePath__waypoints,  // assign(index, value) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__resize_function__DronePath__waypoints  // resize(index) function pointer
  },
  {
    "waypoint_times",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DronePath, waypoint_times),  // bytes offset in struct
    NULL,  // default value
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__size_function__DronePath__waypoint_times,  // size() function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_const_function__DronePath__waypoint_times,  // get_const(index) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__get_function__DronePath__waypoint_times,  // get(index) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__fetch_function__DronePath__waypoint_times,  // fetch(index, &value) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__assign_function__DronePath__waypoint_times,  // assign(index, value) function pointer
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__resize_function__DronePath__waypoint_times  // resize(index) function pointer
  },
  {
    "formation_start_time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__DronePath, formation_start_time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_members = {
  "formation_msgs__msg",  // message namespace
  "DronePath",  // message name
  4,  // number of fields
  sizeof(formation_msgs__msg__DronePath),
  formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_member_array,  // message members
  formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_init_function,  // function to initialize message memory (memory has to be allocated)
  formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_type_support_handle = {
  0,
  &formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_formation_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, formation_msgs, msg, DronePath)() {
  formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_type_support_handle.typesupport_identifier) {
    formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &formation_msgs__msg__DronePath__rosidl_typesupport_introspection_c__DronePath_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
