// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from formation_msgs:msg/PlanStatus.idl
// generated code does not contain a copyright notice

#ifndef FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__FUNCTIONS_H_
#define FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "formation_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "formation_msgs/msg/detail/plan_status__struct.h"

/// Initialize msg/PlanStatus message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * formation_msgs__msg__PlanStatus
 * )) before or use
 * formation_msgs__msg__PlanStatus__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__PlanStatus__init(formation_msgs__msg__PlanStatus * msg);

/// Finalize msg/PlanStatus message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__PlanStatus__fini(formation_msgs__msg__PlanStatus * msg);

/// Create msg/PlanStatus message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * formation_msgs__msg__PlanStatus__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
formation_msgs__msg__PlanStatus *
formation_msgs__msg__PlanStatus__create();

/// Destroy msg/PlanStatus message.
/**
 * It calls
 * formation_msgs__msg__PlanStatus__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__PlanStatus__destroy(formation_msgs__msg__PlanStatus * msg);

/// Check for msg/PlanStatus message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__PlanStatus__are_equal(const formation_msgs__msg__PlanStatus * lhs, const formation_msgs__msg__PlanStatus * rhs);

/// Copy a msg/PlanStatus message.
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
formation_msgs__msg__PlanStatus__copy(
  const formation_msgs__msg__PlanStatus * input,
  formation_msgs__msg__PlanStatus * output);

/// Initialize array of msg/PlanStatus messages.
/**
 * It allocates the memory for the number of elements and calls
 * formation_msgs__msg__PlanStatus__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__PlanStatus__Sequence__init(formation_msgs__msg__PlanStatus__Sequence * array, size_t size);

/// Finalize array of msg/PlanStatus messages.
/**
 * It calls
 * formation_msgs__msg__PlanStatus__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__PlanStatus__Sequence__fini(formation_msgs__msg__PlanStatus__Sequence * array);

/// Create array of msg/PlanStatus messages.
/**
 * It allocates the memory for the array and calls
 * formation_msgs__msg__PlanStatus__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
formation_msgs__msg__PlanStatus__Sequence *
formation_msgs__msg__PlanStatus__Sequence__create(size_t size);

/// Destroy array of msg/PlanStatus messages.
/**
 * It calls
 * formation_msgs__msg__PlanStatus__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
void
formation_msgs__msg__PlanStatus__Sequence__destroy(formation_msgs__msg__PlanStatus__Sequence * array);

/// Check for msg/PlanStatus message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_formation_msgs
bool
formation_msgs__msg__PlanStatus__Sequence__are_equal(const formation_msgs__msg__PlanStatus__Sequence * lhs, const formation_msgs__msg__PlanStatus__Sequence * rhs);

/// Copy an array of msg/PlanStatus messages.
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
formation_msgs__msg__PlanStatus__Sequence__copy(
  const formation_msgs__msg__PlanStatus__Sequence * input,
  formation_msgs__msg__PlanStatus__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FORMATION_MSGS__MSG__DETAIL__PLAN_STATUS__FUNCTIONS_H_
