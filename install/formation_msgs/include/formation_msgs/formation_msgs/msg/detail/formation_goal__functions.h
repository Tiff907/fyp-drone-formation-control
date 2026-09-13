// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__FUNCTIONS_H_
#define FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "formation_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "formation_msgs/msg/detail/formation_goal__struct.h"

/// Initialize msg/FormationGoal message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * formation_msgs__msg__FormationGoal
 * )) before or use
 * formation_msgs__msg__FormationGoal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__FormationGoal__init(formation_msgs__msg__FormationGoal * msg);

/// Finalize msg/FormationGoal message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__FormationGoal__fini(formation_msgs__msg__FormationGoal * msg);

/// Create msg/FormationGoal message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * formation_msgs__msg__FormationGoal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
formation_msgs__msg__FormationGoal *
formation_msgs__msg__FormationGoal__create();

/// Destroy msg/FormationGoal message.
/**
 * It calls
 * formation_msgs__msg__FormationGoal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__FormationGoal__destroy(formation_msgs__msg__FormationGoal * msg);

/// Check for msg/FormationGoal message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__FormationGoal__are_equal(const formation_msgs__msg__FormationGoal * lhs, const formation_msgs__msg__FormationGoal * rhs);

/// Copy a msg/FormationGoal message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__FormationGoal__copy(
  const formation_msgs__msg__FormationGoal * input,
  formation_msgs__msg__FormationGoal * output);

/// Initialize array of msg/FormationGoal messages.
/**
 * It allocates the memory for the number of elements and calls
 * formation_msgs__msg__FormationGoal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__FormationGoal__Sequence__init(formation_msgs__msg__FormationGoal__Sequence * array, size_t size);

/// Finalize array of msg/FormationGoal messages.
/**
 * It calls
 * formation_msgs__msg__FormationGoal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__FormationGoal__Sequence__fini(formation_msgs__msg__FormationGoal__Sequence * array);

/// Create array of msg/FormationGoal messages.
/**
 * It allocates the memory for the array and calls
 * formation_msgs__msg__FormationGoal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
formation_msgs__msg__FormationGoal__Sequence *
formation_msgs__msg__FormationGoal__Sequence__create(size_t size);

/// Destroy array of msg/FormationGoal messages.
/**
 * It calls
 * formation_msgs__msg__FormationGoal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__FormationGoal__Sequence__destroy(formation_msgs__msg__FormationGoal__Sequence * array);

/// Check for msg/FormationGoal message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__FormationGoal__Sequence__are_equal(const formation_msgs__msg__FormationGoal__Sequence * lhs, const formation_msgs__msg__FormationGoal__Sequence * rhs);

/// Copy an array of msg/FormationGoal messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__FormationGoal__Sequence__copy(
  const formation_msgs__msg__FormationGoal__Sequence * input,
  formation_msgs__msg__FormationGoal__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__FORMATION_GOAL__FUNCTIONS_H_
