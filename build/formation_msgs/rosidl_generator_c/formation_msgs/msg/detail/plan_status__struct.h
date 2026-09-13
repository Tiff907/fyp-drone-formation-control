// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/PlanStatus.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'status_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/PlanStatus in the package formation_msgs.
/**
  * PlanStatus.msg
  * Pass/fail + diagnostic report from any formation_planner stage back to
  * task_manager (e.g. shape rejected, safety check failed and retrying,
  * drone count decremented due to hardware fault).
  *
  * Published by : drone_validator_node     (topic: /formation/plan_status)
  *                assignment_node
  *                mapf_node
  * Subscribed by: task_manager_node
 */
typedef struct formation_msgs__msg__PlanStatus
{
  bool success;
  rosidl_runtime_c__String status_message;
  int32_t usable_drone_count;
} formation_msgs__msg__PlanStatus;

// Struct for a sequence of formation_msgs__msg__PlanStatus.
typedef struct formation_msgs__msg__PlanStatus__Sequence
{
  formation_msgs__msg__PlanStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__PlanStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__STRUCT_H_
