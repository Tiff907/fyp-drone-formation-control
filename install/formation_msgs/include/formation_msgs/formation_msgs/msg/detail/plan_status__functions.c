// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from formation_msgs:msg/PlanStatus.idl
// generated code does not contain a copyright notice
#include "formation_msgs/msg/detail/plan_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `status_message`
#include "rosidl_runtime_c/string_functions.h"

bool
formation_msgs__msg__PlanStatus__init(formation_msgs__msg__PlanStatus * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // status_message
  if (!rosidl_runtime_c__String__init(&msg->status_message)) {
    formation_msgs__msg__PlanStatus__fini(msg);
    return false;
  }
  // usable_drone_count
  return true;
}

void
formation_msgs__msg__PlanStatus__fini(formation_msgs__msg__PlanStatus * msg)
{
  if (!msg) {
    return;
  }
  // success
  // status_message
  rosidl_runtime_c__String__fini(&msg->status_message);
  // usable_drone_count
}

bool
formation_msgs__msg__PlanStatus__are_equal(const formation_msgs__msg__PlanStatus * lhs, const formation_msgs__msg__PlanStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // status_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status_message), &(rhs->status_message)))
  {
    return false;
  }
  // usable_drone_count
  if (lhs->usable_drone_count != rhs->usable_drone_count) {
    return false;
  }
  return true;
}

bool
formation_msgs__msg__PlanStatus__copy(
  const formation_msgs__msg__PlanStatus * input,
  formation_msgs__msg__PlanStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // status_message
  if (!rosidl_runtime_c__String__copy(
      &(input->status_message), &(output->status_message)))
  {
    return false;
  }
  // usable_drone_count
  output->usable_drone_count = input->usable_drone_count;
  return true;
}

formation_msgs__msg__PlanStatus *
formation_msgs__msg__PlanStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__PlanStatus * msg = (formation_msgs__msg__PlanStatus *)allocator.allocate(sizeof(formation_msgs__msg__PlanStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(formation_msgs__msg__PlanStatus));
  bool success = formation_msgs__msg__PlanStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
formation_msgs__msg__PlanStatus__destroy(formation_msgs__msg__PlanStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    formation_msgs__msg__PlanStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
formation_msgs__msg__PlanStatus__Sequence__init(formation_msgs__msg__PlanStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__PlanStatus * data = NULL;

  if (size) {
    data = (formation_msgs__msg__PlanStatus *)allocator.zero_allocate(size, sizeof(formation_msgs__msg__PlanStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = formation_msgs__msg__PlanStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        formation_msgs__msg__PlanStatus__fini(&data[i - 1]);
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
formation_msgs__msg__PlanStatus__Sequence__fini(formation_msgs__msg__PlanStatus__Sequence * array)
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
      formation_msgs__msg__PlanStatus__fini(&array->data[i]);
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

formation_msgs__msg__PlanStatus__Sequence *
formation_msgs__msg__PlanStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__PlanStatus__Sequence * array = (formation_msgs__msg__PlanStatus__Sequence *)allocator.allocate(sizeof(formation_msgs__msg__PlanStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = formation_msgs__msg__PlanStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
formation_msgs__msg__PlanStatus__Sequence__destroy(formation_msgs__msg__PlanStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    formation_msgs__msg__PlanStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
formation_msgs__msg__PlanStatus__Sequence__are_equal(const formation_msgs__msg__PlanStatus__Sequence * lhs, const formation_msgs__msg__PlanStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!formation_msgs__msg__PlanStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
formation_msgs__msg__PlanStatus__Sequence__copy(
  const formation_msgs__msg__PlanStatus__Sequence * input,
  formation_msgs__msg__PlanStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(formation_msgs__msg__PlanStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    formation_msgs__msg__PlanStatus * data =
      (formation_msgs__msg__PlanStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!formation_msgs__msg__PlanStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          formation_msgs__msg__PlanStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!formation_msgs__msg__PlanStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
