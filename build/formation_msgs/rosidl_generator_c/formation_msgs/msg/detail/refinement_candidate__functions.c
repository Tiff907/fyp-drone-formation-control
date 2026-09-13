// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from formation_msgs:msg/RefinementCandidate.idl
// generated code does not contain a copyright notice
#include "formation_msgs/msg/detail/refinement_candidate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `candidate_points`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `candidate_colors`
#include "std_msgs/msg/detail/color_rgba__functions.h"
// Member `plan_description`
#include "rosidl_runtime_c/string_functions.h"

bool
formation_msgs__msg__RefinementCandidate__init(formation_msgs__msg__RefinementCandidate * msg)
{
  if (!msg) {
    return false;
  }
  // candidate_points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->candidate_points, 0)) {
    formation_msgs__msg__RefinementCandidate__fini(msg);
    return false;
  }
  // candidate_colors
  if (!std_msgs__msg__ColorRGBA__Sequence__init(&msg->candidate_colors, 0)) {
    formation_msgs__msg__RefinementCandidate__fini(msg);
    return false;
  }
  // plan_description
  if (!rosidl_runtime_c__String__init(&msg->plan_description)) {
    formation_msgs__msg__RefinementCandidate__fini(msg);
    return false;
  }
  return true;
}

void
formation_msgs__msg__RefinementCandidate__fini(formation_msgs__msg__RefinementCandidate * msg)
{
  if (!msg) {
    return;
  }
  // candidate_points
  geometry_msgs__msg__Point__Sequence__fini(&msg->candidate_points);
  // candidate_colors
  std_msgs__msg__ColorRGBA__Sequence__fini(&msg->candidate_colors);
  // plan_description
  rosidl_runtime_c__String__fini(&msg->plan_description);
}

bool
formation_msgs__msg__RefinementCandidate__are_equal(const formation_msgs__msg__RefinementCandidate * lhs, const formation_msgs__msg__RefinementCandidate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // candidate_points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->candidate_points), &(rhs->candidate_points)))
  {
    return false;
  }
  // candidate_colors
  if (!std_msgs__msg__ColorRGBA__Sequence__are_equal(
      &(lhs->candidate_colors), &(rhs->candidate_colors)))
  {
    return false;
  }
  // plan_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->plan_description), &(rhs->plan_description)))
  {
    return false;
  }
  return true;
}

bool
formation_msgs__msg__RefinementCandidate__copy(
  const formation_msgs__msg__RefinementCandidate * input,
  formation_msgs__msg__RefinementCandidate * output)
{
  if (!input || !output) {
    return false;
  }
  // candidate_points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->candidate_points), &(output->candidate_points)))
  {
    return false;
  }
  // candidate_colors
  if (!std_msgs__msg__ColorRGBA__Sequence__copy(
      &(input->candidate_colors), &(output->candidate_colors)))
  {
    return false;
  }
  // plan_description
  if (!rosidl_runtime_c__String__copy(
      &(input->plan_description), &(output->plan_description)))
  {
    return false;
  }
  return true;
}

formation_msgs__msg__RefinementCandidate *
formation_msgs__msg__RefinementCandidate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__RefinementCandidate * msg = (formation_msgs__msg__RefinementCandidate *)allocator.allocate(sizeof(formation_msgs__msg__RefinementCandidate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(formation_msgs__msg__RefinementCandidate));
  bool success = formation_msgs__msg__RefinementCandidate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
formation_msgs__msg__RefinementCandidate__destroy(formation_msgs__msg__RefinementCandidate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    formation_msgs__msg__RefinementCandidate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
formation_msgs__msg__RefinementCandidate__Sequence__init(formation_msgs__msg__RefinementCandidate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__RefinementCandidate * data = NULL;

  if (size) {
    data = (formation_msgs__msg__RefinementCandidate *)allocator.zero_allocate(size, sizeof(formation_msgs__msg__RefinementCandidate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = formation_msgs__msg__RefinementCandidate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        formation_msgs__msg__RefinementCandidate__fini(&data[i - 1]);
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
formation_msgs__msg__RefinementCandidate__Sequence__fini(formation_msgs__msg__RefinementCandidate__Sequence * array)
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
      formation_msgs__msg__RefinementCandidate__fini(&array->data[i]);
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

formation_msgs__msg__RefinementCandidate__Sequence *
formation_msgs__msg__RefinementCandidate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  formation_msgs__msg__RefinementCandidate__Sequence * array = (formation_msgs__msg__RefinementCandidate__Sequence *)allocator.allocate(sizeof(formation_msgs__msg__RefinementCandidate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = formation_msgs__msg__RefinementCandidate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
formation_msgs__msg__RefinementCandidate__Sequence__destroy(formation_msgs__msg__RefinementCandidate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    formation_msgs__msg__RefinementCandidate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
formation_msgs__msg__RefinementCandidate__Sequence__are_equal(const formation_msgs__msg__RefinementCandidate__Sequence * lhs, const formation_msgs__msg__RefinementCandidate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!formation_msgs__msg__RefinementCandidate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
formation_msgs__msg__RefinementCandidate__Sequence__copy(
  const formation_msgs__msg__RefinementCandidate__Sequence * input,
  formation_msgs__msg__RefinementCandidate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(formation_msgs__msg__RefinementCandidate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    formation_msgs__msg__RefinementCandidate * data =
      (formation_msgs__msg__RefinementCandidate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!formation_msgs__msg__RefinementCandidate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          formation_msgs__msg__RefinementCandidate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!formation_msgs__msg__RefinementCandidate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
