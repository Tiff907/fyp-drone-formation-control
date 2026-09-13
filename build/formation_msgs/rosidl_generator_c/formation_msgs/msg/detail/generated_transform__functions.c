// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from formation_msgs:msg/GeneratedTransform.idl
// generated code does not contain a copyright notice
#include "formation_msgs/msg/detail/generated_transform__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `generated_code`
// Member `plan_description`
#include "rosidl_runtime_c/string_functions.h"
// Member `current_points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
formation_msgs__msg__GeneratedTransform__init(formation_msgs__msg__GeneratedTransform * msg)
{
  if (!msg) {
    return false;
  }
  // generated_code
  if (!rosidl_runtime_c__String__init(&msg->generated_code)) {
    formation_msgs__msg__GeneratedTransform__fini(msg);
    return false;
  }
  // plan_description
  if (!rosidl_runtime_c__String__init(&msg->plan_description)) {
    formation_msgs__msg__GeneratedTransform__fini(msg);
    return false;
  }
  // current_points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->current_points, 0)) {
    formation_msgs__msg__GeneratedTransform__fini(msg);
    return false;
  }
  return true;
}

void
formation_msgs__msg__GeneratedTransform__fini(formation_msgs__msg__GeneratedTransform * msg)
{
  if (!msg) {
    return;
  }
  // generated_code
  rosidl_runtime_c__String__fini(&msg->generated_code);
  // plan_description
  rosidl_runtime_c__String__fini(&msg->plan_description);
  // current_points
  geometry_msgs__msg__Point__Sequence__fini(&msg->current_points);
}

bool
formation_msgs__msg__GeneratedTransform__are_equal(const formation_msgs__msg__GeneratedTransform * lhs, const formation_msgs__msg__GeneratedTransform * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // generated_code
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->generated_code), &(rhs->generated_code)))
  {
    return false;
  }
  // plan_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->plan_description), &(rhs->plan_description)))
  {
    return false;
  }
  // current_points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->current_points), &(rhs->current_points)))
  {
    return false;
  }
  return true;
}

bool
formation_msgs__msg__GeneratedTransform__copy(
  const formation_msgs__msg__GeneratedTransform * input,
  formation_msgs__msg__GeneratedTransform * output)
{
  if (!input || !output) {
    return false;
  }
  // generated_code
  if (!rosidl_runtime_c__String__copy(
      &(input->generated_code), &(output->generated_code)))
  {
    return false;
  }
  // plan_description
  if (!rosidl_runtime_c__String__copy(
      &(input->plan_description), &(output->plan_description)))
  {
    return false;
  }
  // current_points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->current_points), &(output->current_points)))
  {
    return false;
  }
  return true;
}

formation_msgs__msg__GeneratedTransform *
formation_msgs__msg__GeneratedTransform__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__GeneratedTransform * msg = (formation_msgs__msg__GeneratedTransform *)allocator.allocate(sizeof(formation_msgs__msg__GeneratedTransform), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(formation_msgs__msg__GeneratedTransform));
  bool success = formation_msgs__msg__GeneratedTransform__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
formation_msgs__msg__GeneratedTransform__destroy(formation_msgs__msg__GeneratedTransform * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    formation_msgs__msg__GeneratedTransform__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
formation_msgs__msg__GeneratedTransform__Sequence__init(formation_msgs__msg__GeneratedTransform__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__GeneratedTransform * data = NULL;

  if (size) {
    data = (formation_msgs__msg__GeneratedTransform *)allocator.zero_allocate(size, sizeof(formation_msgs__msg__GeneratedTransform), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = formation_msgs__msg__GeneratedTransform__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        formation_msgs__msg__GeneratedTransform__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
formation_msgs__msg__GeneratedTransform__Sequence__fini(formation_msgs__msg__GeneratedTransform__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      formation_msgs__msg__GeneratedTransform__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

formation_msgs__msg__GeneratedTransform__Sequence *
formation_msgs__msg__GeneratedTransform__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__GeneratedTransform__Sequence * array = (formation_msgs__msg__GeneratedTransform__Sequence *)allocator.allocate(sizeof(formation_msgs__msg__GeneratedTransform__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = formation_msgs__msg__GeneratedTransform__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
formation_msgs__msg__GeneratedTransform__Sequence__destroy(formation_msgs__msg__GeneratedTransform__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    formation_msgs__msg__GeneratedTransform__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
formation_msgs__msg__GeneratedTransform__Sequence__are_equal(const formation_msgs__msg__GeneratedTransform__Sequence * lhs, const formation_msgs__msg__GeneratedTransform__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!formation_msgs__msg__GeneratedTransform__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
formation_msgs__msg__GeneratedTransform__Sequence__copy(
  const formation_msgs__msg__GeneratedTransform__Sequence * input,
  formation_msgs__msg__GeneratedTransform__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(formation_msgs__msg__GeneratedTransform);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    formation_msgs__msg__GeneratedTransform * data =
      (formation_msgs__msg__GeneratedTransform *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!formation_msgs__msg__GeneratedTransform__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          formation_msgs__msg__GeneratedTransform__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!formation_msgs__msg__GeneratedTransform__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
