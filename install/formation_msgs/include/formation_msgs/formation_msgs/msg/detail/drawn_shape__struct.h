// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/DrawnShape.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'raw_points'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'stroke_colors'
#include "std_msgs/msg/detail/color_rgba__struct.h"

/// Struct defined in msg/DrawnShape in the package formation_msgs.
/**
  * DrawnShape.msg
  * Raw stroke data captured from the canvas, before sampling.
  *
  * Published by : canvas_server_node       (topic: /formation/drawn_shape)
  * Subscribed by: task_manager_node        -> forwarded into formation_planner pipeline
  *                shape_sampling_node      (on task_manager dispatch)
 */
typedef struct formation_msgs__msg__DrawnShape
{
  geometry_msgs__msg__Point__Sequence raw_points;
  std_msgs__msg__ColorRGBA__Sequence stroke_colors;
} formation_msgs__msg__DrawnShape;

// Struct for a sequence of formation_msgs__msg__DrawnShape.
typedef struct formation_msgs__msg__DrawnShape__Sequence
{
  formation_msgs__msg__DrawnShape * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__DrawnShape__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__DRAWN_SHAPE__STRUCT_H_
