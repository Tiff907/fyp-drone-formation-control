// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/DronePath.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'waypoint_times'
// Member 'formation_start_time'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/DronePath in the package formation_msgs.
/**
  * DronePath.msg
  * Collision-free path for a single drone, output by CBS planning.
  *
  * Published by : mapf_node                (topic: /formation/drone_path)
  * Subscribed by: drone_controller_node    (one instance per drone; filters by drone_id)
  *                task_manager_node        (status/logging)
 */
typedef struct formation_msgs__msg__DronePath
{
  int32_t drone_id;
  geometry_msgs__msg__Point__Sequence waypoints;
  builtin_interfaces__msg__Time__Sequence waypoint_times;
  builtin_interfaces__msg__Time formation_start_time;
} formation_msgs__msg__DronePath;

// Struct for a sequence of formation_msgs__msg__DronePath.
typedef struct formation_msgs__msg__DronePath__Sequence
{
  formation_msgs__msg__DronePath * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__DronePath__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_PATH__STRUCT_H_
