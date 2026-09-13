// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/RefinementCandidate.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'candidate_points'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'candidate_colors'
#include "std_msgs/msg/detail/color_rgba__struct.h"
// Member 'plan_description'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RefinementCandidate in the package formation_msgs.
/**
  * RefinementCandidate.msg
  * Proposed shape returned by the LLM refinement pipeline, pending user
  * ACCEPT / REJECT / REDRAW INSTEAD review.
  *
  * Published by : coords_adjust_node       (topic: /refinement/candidate)
  * Subscribed by: task_manager_node
  *                canvas_server_node       (renders dashed overlay to user)
 */
typedef struct formation_msgs__msg__RefinementCandidate
{
  geometry_msgs__msg__Point__Sequence candidate_points;
  std_msgs__msg__ColorRGBA__Sequence candidate_colors;
  rosidl_runtime_c__String plan_description;
} formation_msgs__msg__RefinementCandidate;

// Struct for a sequence of formation_msgs__msg__RefinementCandidate.
typedef struct formation_msgs__msg__RefinementCandidate__Sequence
{
  formation_msgs__msg__RefinementCandidate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__RefinementCandidate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__REFINEMENT_CANDIDATE__STRUCT_H_
