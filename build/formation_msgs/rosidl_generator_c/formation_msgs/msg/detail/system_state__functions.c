// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from formation_msgs:msg/SystemState.idl
// generated code does not contain a copyright notice
#include "formation_msgs/msg/detail/system_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `state`
#include "rosidl_runtime_c/string_functions.h"

bool
formation_msgs__msg__SystemState__init(formation_msgs__msg__SystemState * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    formation_msgs__msg__SystemState__fini(msg);
    return false;
  }
  return true;
}

void
formation_msgs__msg__SystemState__fini(formation_msgs__msg__SystemState * msg)
{
  if (!msg) {
    return;
  }
  // state
  rosidl_runtime_c__String__fini(&msg->state);
}

bool
formation_msgs__msg__SystemState__are_equal(const formation_msgs__msg__SystemState * lhs, const formation_msgs__msg__SystemState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
formation_msgs__msg__SystemState__copy(
  const formation_msgs__msg__SystemState * input,
  formation_msgs__msg__SystemState * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

formation_msgs__msg__SystemState *
formation_msgs__msg__SystemState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__SystemState * msg = (formation_msgs__msg__SystemState *)allocator.allocate(sizeof(formation_msgs__msg__SystemState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(formation_msgs__msg__SystemState));
  bool success = formation_msgs__msg__SystemState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
formation_msgs__msg__SystemState__destroy(formation_msgs__msg__SystemState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    formation_msgs__msg__SystemState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
formation_msgs__msg__SystemState__Sequence__init(formation_msgs__msg__SystemState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__SystemState * data = NULL;

  if (size) {
    data = (formation_msgs__msg__SystemState *)allocator.zero_allocate(size, sizeof(formation_msgs__msg__SystemState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = formation_msgs__msg__SystemState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        formation_msgs__msg__SystemState__fini(&data[i - 1]);
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
formation_msgs__msg__SystemState__Sequence__fini(formation_msgs__msg__SystemState__Sequence * array)
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
      formation_msgs__msg__SystemState__fini(&array->data[i]);
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

formation_msgs__msg__SystemState__Sequence *
formation_msgs__msg__SystemState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__SystemState__Sequence * array = (formation_msgs__msg__SystemState__Sequence *)allocator.allocate(sizeof(formation_msgs__msg__SystemState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = formation_msgs__msg__SystemState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
formation_msgs__msg__SystemState__Sequence__destroy(formation_msgs__msg__SystemState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    formation_msgs__msg__SystemState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
formation_msgs__msg__SystemState__Sequence__are_equal(const formation_msgs__msg__SystemState__Sequence * lhs, const formation_msgs__msg__SystemState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!formation_msgs__msg__SystemState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
formation_msgs__msg__SystemState__Sequence__copy(
  const formation_msgs__msg__SystemState__Sequence * input,
  formation_msgs__msg__SystemState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(formation_msgs__msg__SystemState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    formation_msgs__msg__SystemState * data =
      (formation_msgs__msg__SystemState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!formation_msgs__msg__SystemState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          formation_msgs__msg__SystemState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!formation_msgs__msg__SystemState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
