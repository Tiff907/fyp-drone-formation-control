// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from formation_msgs:msg/UserCommand.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__STRUCT_H_
#define FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/UserCommand in the package formation_msgs.
/**
  * UserCommand.msg
  * Discrete button-press event from the canvas UI.
  * Expected values: START, SUBMIT, LLM_SUBMIT, ACCEPT, REJECT,
  *                   REDRAW_INSTEAD, END
  *
  * Published by : canvas_server_node       (topic: /ui/user_command)
  * Subscribed by: task_manager_node
 */
typedef struct formation_msgs__msg__UserCommand
{
  rosidl_runtime_c__String command;
} formation_msgs__msg__UserCommand;

// Struct for a sequence of formation_msgs__msg__UserCommand.
typedef struct formation_msgs__msg__UserCommand__Sequence
{
  formation_msgs__msg__UserCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} formation_msgs__msg__UserCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__USER_COMMAND__STRUCT_H_
