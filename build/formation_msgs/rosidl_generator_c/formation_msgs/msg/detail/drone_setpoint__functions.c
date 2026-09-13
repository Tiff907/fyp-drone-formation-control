// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from formation_msgs:msg/DroneSetpoint.idl
// generated code does not contain a copyright notice
#include "formation_msgs/msg/detail/drone_setpoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `led_color`
#include "std_msgs/msg/detail/color_rgba__functions.h"

bool
formation_msgs__msg__DroneSetpoint__init(formation_msgs__msg__DroneSetpoint * msg)
{
  if (!msg) {
    return false;
  }
  // drone_id
  // target_position
  if (!geometry_msgs__msg__Point__init(&msg->target_position)) {
    formation_msgs__msg__DroneSetpoint__fini(msg);
    return false;
  }
  // led_color
  if (!std_msgs__msg__ColorRGBA__init(&msg->led_color)) {
    formation_msgs__msg__DroneSetpoint__fini(msg);
    return false;
  }
  return true;
}

void
formation_msgs__msg__DroneSetpoint__fini(formation_msgs__msg__DroneSetpoint * msg)
{
  if (!msg) {
    return;
  }
  // drone_id
  // target_position
  geometry_msgs__msg__Point__fini(&msg->target_position);
  // led_color
  std_msgs__msg__ColorRGBA__fini(&msg->led_color);
}

bool
formation_msgs__msg__DroneSetpoint__are_equal(const formation_msgs__msg__DroneSetpoint * lhs, const formation_msgs__msg__DroneSetpoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // drone_id
  if (lhs->drone_id != rhs->drone_id) {
    return false;
  }
  // target_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->target_position), &(rhs->target_position)))
  {
    return false;
  }
  // led_color
  if (!std_msgs__msg__ColorRGBA__are_equal(
      &(lhs->led_color), &(rhs->led_color)))
  {
    return false;
  }
  return true;
}

bool
formation_msgs__msg__DroneSetpoint__copy(
  const formation_msgs__msg__DroneSetpoint * input,
  formation_msgs__msg__DroneSetpoint * output)
{
  if (!input || !output) {
    return false;
  }
  // drone_id
  output->drone_id = input->drone_id;
  // target_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->target_position), &(output->target_position)))
  {
    return false;
  }
  // led_color
  if (!std_msgs__msg__ColorRGBA__copy(
      &(input->led_color), &(output->led_color)))
  {
    return false;
  }
  return true;
}

formation_msgs__msg__DroneSetpoint *
formation_msgs__msg__DroneSetpoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__DroneSetpoint * msg = (formation_msgs__msg__DroneSetpoint *)allocator.allocate(sizeof(formation_msgs__msg__DroneSetpoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(formation_msgs__msg__DroneSetpoint));
  bool success = formation_msgs__msg__DroneSetpoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
formation_msgs__msg__DroneSetpoint__destroy(formation_msgs__msg__DroneSetpoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    formation_msgs__msg__DroneSetpoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
formation_msgs__msg__DroneSetpoint__Sequence__init(formation_msgs__msg__DroneSetpoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__DroneSetpoint * data = NULL;

  if (size) {
    data = (formation_msgs__msg__DroneSetpoint *)allocator.zero_allocate(size, sizeof(formation_msgs__msg__DroneSetpoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = formation_msgs__msg__DroneSetpoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        formation_msgs__msg__DroneSetpoint__fini(&data[i - 1]);
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
formation_msgs__msg__DroneSetpoint__Sequence__fini(formation_msgs__msg__DroneSetpoint__Sequence * array)
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
      formation_msgs__msg__DroneSetpoint__fini(&array->data[i]);
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

formation_msgs__msg__DroneSetpoint__Sequence *
formation_msgs__msg__DroneSetpoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__DroneSetpoint__Sequence * array = (formation_msgs__msg__DroneSetpoint__Sequence *)allocator.allocate(sizeof(formation_msgs__msg__DroneSetpoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = formation_msgs__msg__DroneSetpoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
formation_msgs__msg__DroneSetpoint__Sequence__destroy(formation_msgs__msg__DroneSetpoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    formation_msgs__msg__DroneSetpoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
formation_msgs__msg__DroneSetpoint__Sequence__are_equal(const formation_msgs__msg__DroneSetpoint__Sequence * lhs, const formation_msgs__msg__DroneSetpoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!formation_msgs__msg__DroneSetpoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
formation_msgs__msg__DroneSetpoint__Sequence__copy(
  const formation_msgs__msg__DroneSetpoint__Sequence * input,
  formation_msgs__msg__DroneSetpoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(formation_msgs__msg__DroneSetpoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    formation_msgs__msg__DroneSetpoint * data =
      (formation_msgs__msg__DroneSetpoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!formation_msgs__msg__DroneSetpoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          formation_msgs__msg__DroneSetpoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!formation_msgs__msg__DroneSetpoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
