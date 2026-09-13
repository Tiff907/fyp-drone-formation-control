// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'state'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SystemState in the package formation_msgs.
/**
  * SystemState.msg
  * Current FSM state, broadcast so the UI (and any other interested node)
  * can reflect system status without querying task_manager directly.
  * Expected values: IDLE, HOVERING, PLANNING, EXECUTING, HOLDING,
  *                  REFINING, LANDING, ERROR
  *
  * Published by : task_manager_node        (topic: /system/state)
  * Subscribed by: canvas_server_node       (enables/disables UI controls)
 */
typedef struct formation_msgs__msg__SystemState
{
  rosidl_runtime_c__String state;
} formation_msgs__msg__SystemState;

// Struct for a sequence of formation_msgs__msg__SystemState.
typedef struct formation_msgs__msg__SystemState__Sequence
{
  formation_msgs__msg__SystemState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__SystemState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__SYSTEM_STATE__STRUCT_H_
