// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from formation_msgs:msg/RefinementCmd.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "formation_msgs/msg/detail/refinement_cmd__rosidl_typesupport_introspection_c.h"
#include "formation_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "formation_msgs/msg/detail/refinement_cmd__functions.h"
#include "formation_msgs/msg/detail/refinement_cmd__struct.h"


// Include directives for member types
// Member `instruction_text`
#include "rosidl_runtime_c/string_functions.h"
// Member `current_points`
#include "geometry_msgs/msg/point.h"
// Member `current_points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  formation_msgs__msg__RefinementCmd__init(message_memory);
}

void formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_fini_function(void * message_memory)
{
  formation_msgs__msg__RefinementCmd__fini(message_memory);
}

size_t formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__size_function__RefinementCmd__current_points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__get_const_function__RefinementCmd__current_points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__get_function__RefinementCmd__current_points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__fetch_function__RefinementCmd__current_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__get_const_function__RefinementCmd__current_points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__assign_function__RefinementCmd__current_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__get_function__RefinementCmd__current_points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__resize_function__RefinementCmd__current_points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_member_array[2] = {
  {
    "instruction_text",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__RefinementCmd, instruction_text),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(formation_msgs__msg__RefinementCmd, current_points),  // bytes offset in struct
    NULL,  // default value
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__size_function__RefinementCmd__current_points,  // size() function pointer
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__get_const_function__RefinementCmd__current_points,  // get_const(index) function pointer
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__get_function__RefinementCmd__current_points,  // get(index) function pointer
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__fetch_function__RefinementCmd__current_points,  // fetch(index, &value) function pointer
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__assign_function__RefinementCmd__current_points,  // assign(index, value) function pointer
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__resize_function__RefinementCmd__current_points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_members = {
  "formation_msgs__msg",  // message namespace
  "RefinementCmd",  // message name
  2,  // number of fields
  sizeof(formation_msgs__msg__RefinementCmd),
  formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_member_array,  // message members
  formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_init_function,  // function to initialize message memory (memory has to be allocated)
  formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_type_support_handle = {
  0,
  &formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_formation_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, formation_msgs, msg, RefinementCmd)() {
  formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_type_support_handle.typesupport_identifier) {
    formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &formation_msgs__msg__RefinementCmd__rosidl_typesupport_introspection_c__RefinementCmd_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
