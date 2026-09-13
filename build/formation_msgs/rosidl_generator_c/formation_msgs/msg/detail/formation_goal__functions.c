// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from formation_msgs:msg/FormationGoal.idl
// generated code does not contain a copyright notice
#include "formation_msgs/msg/detail/formation_goal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_points`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `assigned_drone_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `point_colors`
#include "std_msgs/msg/detail/color_rgba__functions.h"
// Member `timestamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
formation_msgs__msg__FormationGoal__init(formation_msgs__msg__FormationGoal * msg)
{
  if (!msg) {
    return false;
  }
  // target_points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->target_points, 0)) {
    formation_msgs__msg__FormationGoal__fini(msg);
    return false;
  }
  // assigned_drone_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->assigned_drone_ids, 0)) {
    formation_msgs__msg__FormationGoal__fini(msg);
    return false;
  }
  // point_colors
  if (!std_msgs__msg__ColorRGBA__Sequence__init(&msg->point_colors, 0)) {
    formation_msgs__msg__FormationGoal__fini(msg);
    return false;
  }
  // formation_id
  // timestamp
  if (!builtin_interfaces__msg__Time__init(&msg->timestamp)) {
    formation_msgs__msg__FormationGoal__fini(msg);
    return false;
  }
  return true;
}

void
formation_msgs__msg__FormationGoal__fini(formation_msgs__msg__FormationGoal * msg)
{
  if (!msg) {
    return;
  }
  // target_points
  geometry_msgs__msg__Point__Sequence__fini(&msg->target_points);
  // assigned_drone_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->assigned_drone_ids);
  // point_colors
  std_msgs__msg__ColorRGBA__Sequence__fini(&msg->point_colors);
  // formation_id
  // timestamp
  builtin_interfaces__msg__Time__fini(&msg->timestamp);
}

bool
formation_msgs__msg__FormationGoal__are_equal(const formation_msgs__msg__FormationGoal * lhs, const formation_msgs__msg__FormationGoal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->target_points), &(rhs->target_points)))
  {
    return false;
  }
  // assigned_drone_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->assigned_drone_ids), &(rhs->assigned_drone_ids)))
  {
    return false;
  }
  // point_colors
  if (!std_msgs__msg__ColorRGBA__Sequence__are_equal(
      &(lhs->point_colors), &(rhs->point_colors)))
  {
    return false;
  }
  // formation_id
  if (lhs->formation_id != rhs->formation_id) {
    return false;
  }
  // timestamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->timestamp), &(rhs->timestamp)))
  {
    return false;
  }
  return true;
}

bool
formation_msgs__msg__FormationGoal__copy(
  const formation_msgs__msg__FormationGoal * input,
  formation_msgs__msg__FormationGoal * output)
{
  if (!input || !output) {
    return false;
  }
  // target_points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->target_points), &(output->target_points)))
  {
    return false;
  }
  // assigned_drone_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->assigned_drone_ids), &(output->assigned_drone_ids)))
  {
    return false;
  }
  // point_colors
  if (!std_msgs__msg__ColorRGBA__Sequence__copy(
      &(input->point_colors), &(output->point_colors)))
  {
    return false;
  }
  // formation_id
  output->formation_id = input->formation_id;
  // timestamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->timestamp), &(output->timestamp)))
  {
    return false;
  }
  return true;
}

formation_msgs__msg__FormationGoal *
formation_msgs__msg__FormationGoal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__FormationGoal * msg = (formation_msgs__msg__FormationGoal *)allocator.allocate(sizeof(formation_msgs__msg__FormationGoal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(formation_msgs__msg__FormationGoal));
  bool success = formation_msgs__msg__FormationGoal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
formation_msgs__msg__FormationGoal__destroy(formation_msgs__msg__FormationGoal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    formation_msgs__msg__FormationGoal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
formation_msgs__msg__FormationGoal__Sequence__init(formation_msgs__msg__FormationGoal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__FormationGoal * data = NULL;

  if (size) {
    data = (formation_msgs__msg__FormationGoal *)allocator.zero_allocate(size, sizeof(formation_msgs__msg__FormationGoal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = formation_msgs__msg__FormationGoal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        formation_msgs__msg__FormationGoal__fini(&data[i - 1]);
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
formation_msgs__msg__FormationGoal__Sequence__fini(formation_msgs__msg__FormationGoal__Sequence * array)
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
      formation_msgs__msg__FormationGoal__fini(&array->data[i]);
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

formation_msgs__msg__FormationGoal__Sequence *
formation_msgs__msg__FormationGoal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__FormationGoal__Sequence * array = (formation_msgs__msg__FormationGoal__Sequence *)allocator.allocate(sizeof(formation_msgs__msg__FormationGoal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = formation_msgs__msg__FormationGoal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
formation_msgs__msg__FormationGoal__Sequence__destroy(formation_msgs__msg__FormationGoal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    formation_msgs__msg__FormationGoal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
formation_msgs__msg__FormationGoal__Sequence__are_equal(const formation_msgs__msg__FormationGoal__Sequence * lhs, const formation_msgs__msg__FormationGoal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!formation_msgs__msg__FormationGoal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
formation_msgs__msg__FormationGoal__Sequence__copy(
  const formation_msgs__msg__FormationGoal__Sequence * input,
  formation_msgs__msg__FormationGoal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(formation_msgs__msg__FormationGoal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    formation_msgs__msg__FormationGoal * data =
      (formation_msgs__msg__FormationGoal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!formation_msgs__msg__FormationGoal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          formation_msgs__msg__FormationGoal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!formation_msgs__msg__FormationGoal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
