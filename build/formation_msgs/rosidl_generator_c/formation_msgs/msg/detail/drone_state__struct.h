// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/DroneState.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/DroneState in the package formation_msgs.
/**
  * DroneState.msg
  * Per-drone status report.
  *
  * Published by : pose_publisher_node      (topic: /drone/state)
  * Subscribed by: drone_validator_node     (checks availability for M count)
  *                task_manager_node        (checks reached_target during Executing)
 */
typedef struct formation_msgs__msg__DroneState
{
  int32_t drone_id;
  geometry_msgs__msg__Point position;
  bool available;
  bool reached_target;
} formation_msgs__msg__DroneState;

// Struct for a sequence of formation_msgs__msg__DroneState.
typedef struct formation_msgs__msg__DroneState__Sequence
{
  formation_msgs__msg__DroneState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__DroneState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_STATE__STRUCT_H_
