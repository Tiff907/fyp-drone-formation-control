// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/RefinementCmd.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'instruction_text'
#include "rosidl_runtime_c/string.h"
// Member 'current_points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/RefinementCmd in the package formation_msgs.
/**
  * RefinementCmd.msg
  * Natural language refinement instruction plus the point set it applies to.
  *
  * Published by : task_manager_node        (topic: /refinement/command)
  * Subscribed by: llm_interface_node
 */
typedef struct formation_msgs__msg__RefinementCmd
{
  rosidl_runtime_c__String instruction_text;
  geometry_msgs__msg__Point__Sequence current_points;
} formation_msgs__msg__RefinementCmd;

// Struct for a sequence of formation_msgs__msg__RefinementCmd.
typedef struct formation_msgs__msg__RefinementCmd__Sequence
{
  formation_msgs__msg__RefinementCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__RefinementCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CMD__STRUCT_H_
