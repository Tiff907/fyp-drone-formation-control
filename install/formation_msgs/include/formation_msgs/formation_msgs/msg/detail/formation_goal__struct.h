// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_points'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'assigned_drone_ids'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'point_colors'
#include "std_msgs/msg/detail/color_rgba__struct.h"
// Member 'timestamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/FormationGoal in the package formation_msgs.
/**
  * FormationGoal.msg
  * Final target points after sampling + coordinate mapping + assignment.
  *
  * Published by : assignment_node          (topic: /formation/goal)
  * Subscribed by: mapf_node
  *                task_manager_node        (status/logging)
 */
typedef struct formation_msgs__msg__FormationGoal
{
  geometry_msgs__msg__Point__Sequence target_points;
  rosidl_runtime_c__int32__Sequence assigned_drone_ids;
  std_msgs__msg__ColorRGBA__Sequence point_colors;
  uint32_t formation_id;
  builtin_interfaces__msg__Time timestamp;
} formation_msgs__msg__FormationGoal;

// Struct for a sequence of formation_msgs__msg__FormationGoal.
typedef struct formation_msgs__msg__FormationGoal__Sequence
{
  formation_msgs__msg__FormationGoal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__FormationGoal__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__STRUCT_H_
