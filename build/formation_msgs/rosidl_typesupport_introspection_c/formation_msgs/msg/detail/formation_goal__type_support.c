// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "formation_msgs/msg/detail/formation_goal__rosidl_typesupport_introspection_c.h"
#include "formation_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "formation_msgs/msg/detail/formation_goal__functions.h"
#include "formation_msgs/msg/detail/formation_goal__struct.h"


// Include directives for member types
// Member `target_points`
#include "geometry_msgs/msg/point.h"
// Member `target_points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"
// Member `assigned_drone_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `point_colors`
#include "std_msgs/msg/color_rgba.h"
// Member `point_colors`
#include "std_msgs/msg/detail/color_rgba__rosidl_typesupport_introspection_c.h"
// Member `timestamp`
#include "builtin_interfaces/msg/time.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  formation_msgs__msg__FormationGoal__init(message_memory);
}

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_fini_function(void * message_memory)
{
  formation_msgs__msg__FormationGoal__fini(message_memory);
}

size_t formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__size_function__FormationGoal__target_points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__target_points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__target_points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__fetch_function__FormationGoal__target_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__target_points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__assign_function__FormationGoal__target_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__target_points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__resize_function__FormationGoal__target_points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

size_t formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__size_function__FormationGoal__assigned_drone_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__assigned_drone_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__assigned_drone_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__fetch_function__FormationGoal__assigned_drone_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__assigned_drone_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__assign_function__FormationGoal__assigned_drone_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__assigned_drone_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__resize_function__FormationGoal__assigned_drone_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__size_function__FormationGoal__point_colors(
  const void * untyped_member)
{
  const std_msgs__msg__ColorRGBA__Sequence * member =
    (const std_msgs__msg__ColorRGBA__Sequence *)(untyped_member);
  return member->size;
}

const void * formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__point_colors(
  const void * untyped_member, size_t index)
{
  const std_msgs__msg__ColorRGBA__Sequence * member =
    (const std_msgs__msg__ColorRGBA__Sequence *)(untyped_member);
  return &member->data[index];
}

void * formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__point_colors(
  void * untyped_member, size_t index)
{
  std_msgs__msg__ColorRGBA__Sequence * member =
    (std_msgs__msg__ColorRGBA__Sequence *)(untyped_member);
  return &member->data[index];
}

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__fetch_function__FormationGoal__point_colors(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const std_msgs__msg__ColorRGBA * item =
    ((const std_msgs__msg__ColorRGBA *)
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__point_colors(untyped_member, index));
  std_msgs__msg__ColorRGBA * value =
    (std_msgs__msg__ColorRGBA *)(untyped_value);
  *value = *item;
}

void formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__assign_function__FormationGoal__point_colors(
  void * untyped_member, size_t index, const void * untyped_value)
{
  std_msgs__msg__ColorRGBA * item =
    ((std_msgs__msg__ColorRGBA *)
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__point_colors(untyped_member, index));
  const std_msgs__msg__ColorRGBA * value =
    (const std_msgs__msg__ColorRGBA *)(untyped_value);
  *item = *value;
}

bool formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__resize_function__FormationGoal__point_colors(
  void * untyped_member, size_t size)
{
  std_msgs__msg__ColorRGBA__Sequence * member =
    (std_msgs__msg__ColorRGBA__Sequence *)(untyped_member);
  std_msgs__msg__ColorRGBA__Sequence__fini(member);
  return std_msgs__msg__ColorRGBA__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_member_array[5] = {
  {
    "target_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__FormationGoal, target_points),  // bytes offset in struct
    NULL,  // default value
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__size_function__FormationGoal__target_points,  // size() function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__target_points,  // get_const(index) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__target_points,  // get(index) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__fetch_function__FormationGoal__target_points,  // fetch(index, &value) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__assign_function__FormationGoal__target_points,  // assign(index, value) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__resize_function__FormationGoal__target_points  // resize(index) function pointer
  },
  {
    "assigned_drone_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__FormationGoal, assigned_drone_ids),  // bytes offset in struct
    NULL,  // default value
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__size_function__FormationGoal__assigned_drone_ids,  // size() function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__assigned_drone_ids,  // get_const(index) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__assigned_drone_ids,  // get(index) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__fetch_function__FormationGoal__assigned_drone_ids,  // fetch(index, &value) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__assign_function__FormationGoal__assigned_drone_ids,  // assign(index, value) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__resize_function__FormationGoal__assigned_drone_ids  // resize(index) function pointer
  },
  {
    "point_colors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__FormationGoal, point_colors),  // bytes offset in struct
    NULL,  // default value
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__size_function__FormationGoal__point_colors,  // size() function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_const_function__FormationGoal__point_colors,  // get_const(index) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__get_function__FormationGoal__point_colors,  // get(index) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__fetch_function__FormationGoal__point_colors,  // fetch(index, &value) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__assign_function__FormationGoal__point_colors,  // assign(index, value) function pointer
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__resize_function__FormationGoal__point_colors  // resize(index) function pointer
  },
  {
    "formation_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__FormationGoal, formation_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__FormationGoal, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_members = {
  "formation_msgs__msg",  // message namespace
  "FormationGoal",  // message name
  5,  // number of fields
  sizeof(formation_msgs__msg__FormationGoal),
  formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_member_array,  // message members
  formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_init_function,  // function to initialize message memory (memory has to be allocated)
  formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_type_support_handle = {
  0,
  &formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_formation_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, formation_msgs, msg, FormationGoal)() {
  formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, ColorRGBA)();
  formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_type_support_handle.typesupport_identifier) {
    formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &formation_msgs__msg__FormationGoal__rosidl_typesupport_introspection_c__FormationGoal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
