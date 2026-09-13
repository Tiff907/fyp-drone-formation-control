// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/DroneSetpoint.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'led_color'
#include "std_msgs/msg/detail/color_rgba__struct.h"

/// Struct defined in msg/DroneSetpoint in the package formation_msgs.
/**
  * DroneSetpoint.msg
  * Current target position for a single drone at this control tick,
  * interpolated from DronePath by drone_controller_node.
  *
  * Published by : drone_controller_node    (topic: /drone/setpoint)
  * Subscribed by: sim_bridge_node OR fylo_bridge_node (whichever is active)
 */
typedef struct formation_msgs__msg__DroneSetpoint
{
  int32_t drone_id;
  geometry_msgs__msg__Point target_position;
  std_msgs__msg__ColorRGBA led_color;
} formation_msgs__msg__DroneSetpoint;

// Struct for a sequence of formation_msgs__msg__DroneSetpoint.
typedef struct formation_msgs__msg__DroneSetpoint__Sequence
{
  formation_msgs__msg__DroneSetpoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__DroneSetpoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__DRONE_SETPOINT__STRUCT_H_
