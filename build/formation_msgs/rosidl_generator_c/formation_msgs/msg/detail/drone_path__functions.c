// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from formation_msgs:msg/DronePath.idl
// generated code does not contain a copyright notice
#include "formation_msgs/msg/detail/drone_path__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `waypoints`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `waypoint_times`
// Member `formation_start_time`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
formation_msgs__msg__DronePath__init(formation_msgs__msg__DronePath * msg)
{
  if (!msg) {
    return false;
  }
  // drone_id
  // waypoints
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->waypoints, 0)) {
    formation_msgs__msg__DronePath__fini(msg);
    return false;
  }
  // waypoint_times
  if (!builtin_interfaces__msg__Time__Sequence__init(&msg->waypoint_times, 0)) {
    formation_msgs__msg__DronePath__fini(msg);
    return false;
  }
  // formation_start_time
  if (!builtin_interfaces__msg__Time__init(&msg->formation_start_time)) {
    formation_msgs__msg__DronePath__fini(msg);
    return false;
  }
  return true;
}

void
formation_msgs__msg__DronePath__fini(formation_msgs__msg__DronePath * msg)
{
  if (!msg) {
    return;
  }
  // drone_id
  // waypoints
  geometry_msgs__msg__Point__Sequence__fini(&msg->waypoints);
  // waypoint_times
  builtin_interfaces__msg__Time__Sequence__fini(&msg->waypoint_times);
  // formation_start_time
  builtin_interfaces__msg__Time__fini(&msg->formation_start_time);
}

bool
formation_msgs__msg__DronePath__are_equal(const formation_msgs__msg__DronePath * lhs, const formation_msgs__msg__DronePath * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // drone_id
  if (lhs->drone_id != rhs->drone_id) {
    return false;
  }
  // waypoints
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->waypoints), &(rhs->waypoints)))
  {
    return false;
  }
  // waypoint_times
  if (!builtin_interfaces__msg__Time__Sequence__are_equal(
      &(lhs->waypoint_times), &(rhs->waypoint_times)))
  {
    return false;
  }
  // formation_start_time
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->formation_start_time), &(rhs->formation_start_time)))
  {
    return false;
  }
  return true;
}

bool
formation_msgs__msg__DronePath__copy(
  const formation_msgs__msg__DronePath * input,
  formation_msgs__msg__DronePath * output)
{
  if (!input || !output) {
    return false;
  }
  // drone_id
  output->drone_id = input->drone_id;
  // waypoints
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->waypoints), &(output->waypoints)))
  {
    return false;
  }
  // waypoint_times
  if (!builtin_interfaces__msg__Time__Sequence__copy(
      &(input->waypoint_times), &(output->waypoint_times)))
  {
    return false;
  }
  // formation_start_time
  if (!builtin_interfaces__msg__Time__copy(
      &(input->formation_start_time), &(output->formation_start_time)))
  {
    return false;
  }
  return true;
}

formation_msgs__msg__DronePath *
formation_msgs__msg__DronePath__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__DronePath * msg = (formation_msgs__msg__DronePath *)allocator.allocate(sizeof(formation_msgs__msg__DronePath), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(formation_msgs__msg__DronePath));
  bool success = formation_msgs__msg__DronePath__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
formation_msgs__msg__DronePath__destroy(formation_msgs__msg__DronePath * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    formation_msgs__msg__DronePath__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
formation_msgs__msg__DronePath__Sequence__init(formation_msgs__msg__DronePath__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__DronePath * data = NULL;

  if (size) {
    data = (formation_msgs__msg__DronePath *)allocator.zero_allocate(size, sizeof(formation_msgs__msg__DronePath), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = formation_msgs__msg__DronePath__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        formation_msgs__msg__DronePath__fini(&data[i - 1]);
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
formation_msgs__msg__DronePath__Sequence__fini(formation_msgs__msg__DronePath__Sequence * array)
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
      formation_msgs__msg__DronePath__fini(&array->data[i]);
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

formation_msgs__msg__DronePath__Sequence *
formation_msgs__msg__DronePath__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__DronePath__Sequence * array = (formation_msgs__msg__DronePath__Sequence *)allocator.allocate(sizeof(formation_msgs__msg__DronePath__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = formation_msgs__msg__DronePath__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
formation_msgs__msg__DronePath__Sequence__destroy(formation_msgs__msg__DronePath__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    formation_msgs__msg__DronePath__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
formation_msgs__msg__DronePath__Sequence__are_equal(const formation_msgs__msg__DronePath__Sequence * lhs, const formation_msgs__msg__DronePath__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!formation_msgs__msg__DronePath__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
formation_msgs__msg__DronePath__Sequence__copy(
  const formation_msgs__msg__DronePath__Sequence * input,
  formation_msgs__msg__DronePath__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(formation_msgs__msg__DronePath);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    formation_msgs__msg__DronePath * data =
      (formation_msgs__msg__DronePath *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!formation_msgs__msg__DronePath__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          formation_msgs__msg__DronePath__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!formation_msgs__msg__DronePath__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
