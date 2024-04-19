// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hotspot_action:action/Nav.idl
// generated code does not contain a copyright notice
#include "hotspot_action/action/detail/nav__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hotspot_action__action__Nav_Goal__init(hotspot_action__action__Nav_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // coordinate_x
  // coordinate_y
  return true;
}

void
hotspot_action__action__Nav_Goal__fini(hotspot_action__action__Nav_Goal * msg)
{
  if (!msg) {
    return;
  }
  // coordinate_x
  // coordinate_y
}

bool
hotspot_action__action__Nav_Goal__are_equal(const hotspot_action__action__Nav_Goal * lhs, const hotspot_action__action__Nav_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // coordinate_x
  if (lhs->coordinate_x != rhs->coordinate_x) {
    return false;
  }
  // coordinate_y
  if (lhs->coordinate_y != rhs->coordinate_y) {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_Goal__copy(
  const hotspot_action__action__Nav_Goal * input,
  hotspot_action__action__Nav_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // coordinate_x
  output->coordinate_x = input->coordinate_x;
  // coordinate_y
  output->coordinate_y = input->coordinate_y;
  return true;
}

hotspot_action__action__Nav_Goal *
hotspot_action__action__Nav_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Goal * msg = (hotspot_action__action__Nav_Goal *)allocator.allocate(sizeof(hotspot_action__action__Nav_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_Goal));
  bool success = hotspot_action__action__Nav_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_Goal__destroy(hotspot_action__action__Nav_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_Goal__Sequence__init(hotspot_action__action__Nav_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Goal * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_Goal *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_Goal__fini(&data[i - 1]);
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
hotspot_action__action__Nav_Goal__Sequence__fini(hotspot_action__action__Nav_Goal__Sequence * array)
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
      hotspot_action__action__Nav_Goal__fini(&array->data[i]);
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

hotspot_action__action__Nav_Goal__Sequence *
hotspot_action__action__Nav_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Goal__Sequence * array = (hotspot_action__action__Nav_Goal__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_Goal__Sequence__destroy(hotspot_action__action__Nav_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_Goal__Sequence__are_equal(const hotspot_action__action__Nav_Goal__Sequence * lhs, const hotspot_action__action__Nav_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_Goal__Sequence__copy(
  const hotspot_action__action__Nav_Goal__Sequence * input,
  hotspot_action__action__Nav_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_Goal * data =
      (hotspot_action__action__Nav_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
hotspot_action__action__Nav_Result__init(hotspot_action__action__Nav_Result * msg)
{
  if (!msg) {
    return false;
  }
  // mp_reached
  return true;
}

void
hotspot_action__action__Nav_Result__fini(hotspot_action__action__Nav_Result * msg)
{
  if (!msg) {
    return;
  }
  // mp_reached
}

bool
hotspot_action__action__Nav_Result__are_equal(const hotspot_action__action__Nav_Result * lhs, const hotspot_action__action__Nav_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mp_reached
  if (lhs->mp_reached != rhs->mp_reached) {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_Result__copy(
  const hotspot_action__action__Nav_Result * input,
  hotspot_action__action__Nav_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // mp_reached
  output->mp_reached = input->mp_reached;
  return true;
}

hotspot_action__action__Nav_Result *
hotspot_action__action__Nav_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Result * msg = (hotspot_action__action__Nav_Result *)allocator.allocate(sizeof(hotspot_action__action__Nav_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_Result));
  bool success = hotspot_action__action__Nav_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_Result__destroy(hotspot_action__action__Nav_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_Result__Sequence__init(hotspot_action__action__Nav_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Result * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_Result *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_Result__fini(&data[i - 1]);
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
hotspot_action__action__Nav_Result__Sequence__fini(hotspot_action__action__Nav_Result__Sequence * array)
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
      hotspot_action__action__Nav_Result__fini(&array->data[i]);
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

hotspot_action__action__Nav_Result__Sequence *
hotspot_action__action__Nav_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Result__Sequence * array = (hotspot_action__action__Nav_Result__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_Result__Sequence__destroy(hotspot_action__action__Nav_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_Result__Sequence__are_equal(const hotspot_action__action__Nav_Result__Sequence * lhs, const hotspot_action__action__Nav_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_Result__Sequence__copy(
  const hotspot_action__action__Nav_Result__Sequence * input,
  hotspot_action__action__Nav_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_Result * data =
      (hotspot_action__action__Nav_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
hotspot_action__action__Nav_Feedback__init(hotspot_action__action__Nav_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // time_to_mp
  return true;
}

void
hotspot_action__action__Nav_Feedback__fini(hotspot_action__action__Nav_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // time_to_mp
}

bool
hotspot_action__action__Nav_Feedback__are_equal(const hotspot_action__action__Nav_Feedback * lhs, const hotspot_action__action__Nav_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time_to_mp
  if (lhs->time_to_mp != rhs->time_to_mp) {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_Feedback__copy(
  const hotspot_action__action__Nav_Feedback * input,
  hotspot_action__action__Nav_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // time_to_mp
  output->time_to_mp = input->time_to_mp;
  return true;
}

hotspot_action__action__Nav_Feedback *
hotspot_action__action__Nav_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Feedback * msg = (hotspot_action__action__Nav_Feedback *)allocator.allocate(sizeof(hotspot_action__action__Nav_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_Feedback));
  bool success = hotspot_action__action__Nav_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_Feedback__destroy(hotspot_action__action__Nav_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_Feedback__Sequence__init(hotspot_action__action__Nav_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Feedback * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_Feedback *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_Feedback__fini(&data[i - 1]);
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
hotspot_action__action__Nav_Feedback__Sequence__fini(hotspot_action__action__Nav_Feedback__Sequence * array)
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
      hotspot_action__action__Nav_Feedback__fini(&array->data[i]);
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

hotspot_action__action__Nav_Feedback__Sequence *
hotspot_action__action__Nav_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_Feedback__Sequence * array = (hotspot_action__action__Nav_Feedback__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_Feedback__Sequence__destroy(hotspot_action__action__Nav_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_Feedback__Sequence__are_equal(const hotspot_action__action__Nav_Feedback__Sequence * lhs, const hotspot_action__action__Nav_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_Feedback__Sequence__copy(
  const hotspot_action__action__Nav_Feedback__Sequence * input,
  hotspot_action__action__Nav_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_Feedback * data =
      (hotspot_action__action__Nav_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "hotspot_action/action/detail/nav__functions.h"

bool
hotspot_action__action__Nav_SendGoal_Request__init(hotspot_action__action__Nav_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    hotspot_action__action__Nav_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!hotspot_action__action__Nav_Goal__init(&msg->goal)) {
    hotspot_action__action__Nav_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
hotspot_action__action__Nav_SendGoal_Request__fini(hotspot_action__action__Nav_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  hotspot_action__action__Nav_Goal__fini(&msg->goal);
}

bool
hotspot_action__action__Nav_SendGoal_Request__are_equal(const hotspot_action__action__Nav_SendGoal_Request * lhs, const hotspot_action__action__Nav_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!hotspot_action__action__Nav_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_SendGoal_Request__copy(
  const hotspot_action__action__Nav_SendGoal_Request * input,
  hotspot_action__action__Nav_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!hotspot_action__action__Nav_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

hotspot_action__action__Nav_SendGoal_Request *
hotspot_action__action__Nav_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_SendGoal_Request * msg = (hotspot_action__action__Nav_SendGoal_Request *)allocator.allocate(sizeof(hotspot_action__action__Nav_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_SendGoal_Request));
  bool success = hotspot_action__action__Nav_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_SendGoal_Request__destroy(hotspot_action__action__Nav_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_SendGoal_Request__Sequence__init(hotspot_action__action__Nav_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_SendGoal_Request * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_SendGoal_Request *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_SendGoal_Request__fini(&data[i - 1]);
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
hotspot_action__action__Nav_SendGoal_Request__Sequence__fini(hotspot_action__action__Nav_SendGoal_Request__Sequence * array)
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
      hotspot_action__action__Nav_SendGoal_Request__fini(&array->data[i]);
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

hotspot_action__action__Nav_SendGoal_Request__Sequence *
hotspot_action__action__Nav_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_SendGoal_Request__Sequence * array = (hotspot_action__action__Nav_SendGoal_Request__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_SendGoal_Request__Sequence__destroy(hotspot_action__action__Nav_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_SendGoal_Request__Sequence__are_equal(const hotspot_action__action__Nav_SendGoal_Request__Sequence * lhs, const hotspot_action__action__Nav_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_SendGoal_Request__Sequence__copy(
  const hotspot_action__action__Nav_SendGoal_Request__Sequence * input,
  hotspot_action__action__Nav_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_SendGoal_Request * data =
      (hotspot_action__action__Nav_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
hotspot_action__action__Nav_SendGoal_Response__init(hotspot_action__action__Nav_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    hotspot_action__action__Nav_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
hotspot_action__action__Nav_SendGoal_Response__fini(hotspot_action__action__Nav_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
hotspot_action__action__Nav_SendGoal_Response__are_equal(const hotspot_action__action__Nav_SendGoal_Response * lhs, const hotspot_action__action__Nav_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_SendGoal_Response__copy(
  const hotspot_action__action__Nav_SendGoal_Response * input,
  hotspot_action__action__Nav_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

hotspot_action__action__Nav_SendGoal_Response *
hotspot_action__action__Nav_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_SendGoal_Response * msg = (hotspot_action__action__Nav_SendGoal_Response *)allocator.allocate(sizeof(hotspot_action__action__Nav_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_SendGoal_Response));
  bool success = hotspot_action__action__Nav_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_SendGoal_Response__destroy(hotspot_action__action__Nav_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_SendGoal_Response__Sequence__init(hotspot_action__action__Nav_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_SendGoal_Response * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_SendGoal_Response *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_SendGoal_Response__fini(&data[i - 1]);
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
hotspot_action__action__Nav_SendGoal_Response__Sequence__fini(hotspot_action__action__Nav_SendGoal_Response__Sequence * array)
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
      hotspot_action__action__Nav_SendGoal_Response__fini(&array->data[i]);
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

hotspot_action__action__Nav_SendGoal_Response__Sequence *
hotspot_action__action__Nav_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_SendGoal_Response__Sequence * array = (hotspot_action__action__Nav_SendGoal_Response__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_SendGoal_Response__Sequence__destroy(hotspot_action__action__Nav_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_SendGoal_Response__Sequence__are_equal(const hotspot_action__action__Nav_SendGoal_Response__Sequence * lhs, const hotspot_action__action__Nav_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_SendGoal_Response__Sequence__copy(
  const hotspot_action__action__Nav_SendGoal_Response__Sequence * input,
  hotspot_action__action__Nav_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_SendGoal_Response * data =
      (hotspot_action__action__Nav_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
hotspot_action__action__Nav_GetResult_Request__init(hotspot_action__action__Nav_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    hotspot_action__action__Nav_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
hotspot_action__action__Nav_GetResult_Request__fini(hotspot_action__action__Nav_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
hotspot_action__action__Nav_GetResult_Request__are_equal(const hotspot_action__action__Nav_GetResult_Request * lhs, const hotspot_action__action__Nav_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_GetResult_Request__copy(
  const hotspot_action__action__Nav_GetResult_Request * input,
  hotspot_action__action__Nav_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

hotspot_action__action__Nav_GetResult_Request *
hotspot_action__action__Nav_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_GetResult_Request * msg = (hotspot_action__action__Nav_GetResult_Request *)allocator.allocate(sizeof(hotspot_action__action__Nav_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_GetResult_Request));
  bool success = hotspot_action__action__Nav_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_GetResult_Request__destroy(hotspot_action__action__Nav_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_GetResult_Request__Sequence__init(hotspot_action__action__Nav_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_GetResult_Request * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_GetResult_Request *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_GetResult_Request__fini(&data[i - 1]);
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
hotspot_action__action__Nav_GetResult_Request__Sequence__fini(hotspot_action__action__Nav_GetResult_Request__Sequence * array)
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
      hotspot_action__action__Nav_GetResult_Request__fini(&array->data[i]);
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

hotspot_action__action__Nav_GetResult_Request__Sequence *
hotspot_action__action__Nav_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_GetResult_Request__Sequence * array = (hotspot_action__action__Nav_GetResult_Request__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_GetResult_Request__Sequence__destroy(hotspot_action__action__Nav_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_GetResult_Request__Sequence__are_equal(const hotspot_action__action__Nav_GetResult_Request__Sequence * lhs, const hotspot_action__action__Nav_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_GetResult_Request__Sequence__copy(
  const hotspot_action__action__Nav_GetResult_Request__Sequence * input,
  hotspot_action__action__Nav_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_GetResult_Request * data =
      (hotspot_action__action__Nav_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "hotspot_action/action/detail/nav__functions.h"

bool
hotspot_action__action__Nav_GetResult_Response__init(hotspot_action__action__Nav_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!hotspot_action__action__Nav_Result__init(&msg->result)) {
    hotspot_action__action__Nav_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
hotspot_action__action__Nav_GetResult_Response__fini(hotspot_action__action__Nav_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  hotspot_action__action__Nav_Result__fini(&msg->result);
}

bool
hotspot_action__action__Nav_GetResult_Response__are_equal(const hotspot_action__action__Nav_GetResult_Response * lhs, const hotspot_action__action__Nav_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!hotspot_action__action__Nav_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_GetResult_Response__copy(
  const hotspot_action__action__Nav_GetResult_Response * input,
  hotspot_action__action__Nav_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!hotspot_action__action__Nav_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

hotspot_action__action__Nav_GetResult_Response *
hotspot_action__action__Nav_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_GetResult_Response * msg = (hotspot_action__action__Nav_GetResult_Response *)allocator.allocate(sizeof(hotspot_action__action__Nav_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_GetResult_Response));
  bool success = hotspot_action__action__Nav_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_GetResult_Response__destroy(hotspot_action__action__Nav_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_GetResult_Response__Sequence__init(hotspot_action__action__Nav_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_GetResult_Response * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_GetResult_Response *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_GetResult_Response__fini(&data[i - 1]);
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
hotspot_action__action__Nav_GetResult_Response__Sequence__fini(hotspot_action__action__Nav_GetResult_Response__Sequence * array)
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
      hotspot_action__action__Nav_GetResult_Response__fini(&array->data[i]);
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

hotspot_action__action__Nav_GetResult_Response__Sequence *
hotspot_action__action__Nav_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_GetResult_Response__Sequence * array = (hotspot_action__action__Nav_GetResult_Response__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_GetResult_Response__Sequence__destroy(hotspot_action__action__Nav_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_GetResult_Response__Sequence__are_equal(const hotspot_action__action__Nav_GetResult_Response__Sequence * lhs, const hotspot_action__action__Nav_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_GetResult_Response__Sequence__copy(
  const hotspot_action__action__Nav_GetResult_Response__Sequence * input,
  hotspot_action__action__Nav_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_GetResult_Response * data =
      (hotspot_action__action__Nav_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "hotspot_action/action/detail/nav__functions.h"

bool
hotspot_action__action__Nav_FeedbackMessage__init(hotspot_action__action__Nav_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    hotspot_action__action__Nav_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!hotspot_action__action__Nav_Feedback__init(&msg->feedback)) {
    hotspot_action__action__Nav_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
hotspot_action__action__Nav_FeedbackMessage__fini(hotspot_action__action__Nav_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  hotspot_action__action__Nav_Feedback__fini(&msg->feedback);
}

bool
hotspot_action__action__Nav_FeedbackMessage__are_equal(const hotspot_action__action__Nav_FeedbackMessage * lhs, const hotspot_action__action__Nav_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!hotspot_action__action__Nav_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
hotspot_action__action__Nav_FeedbackMessage__copy(
  const hotspot_action__action__Nav_FeedbackMessage * input,
  hotspot_action__action__Nav_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!hotspot_action__action__Nav_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

hotspot_action__action__Nav_FeedbackMessage *
hotspot_action__action__Nav_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_FeedbackMessage * msg = (hotspot_action__action__Nav_FeedbackMessage *)allocator.allocate(sizeof(hotspot_action__action__Nav_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hotspot_action__action__Nav_FeedbackMessage));
  bool success = hotspot_action__action__Nav_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hotspot_action__action__Nav_FeedbackMessage__destroy(hotspot_action__action__Nav_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hotspot_action__action__Nav_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hotspot_action__action__Nav_FeedbackMessage__Sequence__init(hotspot_action__action__Nav_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_FeedbackMessage * data = NULL;

  if (size) {
    data = (hotspot_action__action__Nav_FeedbackMessage *)allocator.zero_allocate(size, sizeof(hotspot_action__action__Nav_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hotspot_action__action__Nav_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hotspot_action__action__Nav_FeedbackMessage__fini(&data[i - 1]);
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
hotspot_action__action__Nav_FeedbackMessage__Sequence__fini(hotspot_action__action__Nav_FeedbackMessage__Sequence * array)
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
      hotspot_action__action__Nav_FeedbackMessage__fini(&array->data[i]);
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

hotspot_action__action__Nav_FeedbackMessage__Sequence *
hotspot_action__action__Nav_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hotspot_action__action__Nav_FeedbackMessage__Sequence * array = (hotspot_action__action__Nav_FeedbackMessage__Sequence *)allocator.allocate(sizeof(hotspot_action__action__Nav_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hotspot_action__action__Nav_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hotspot_action__action__Nav_FeedbackMessage__Sequence__destroy(hotspot_action__action__Nav_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hotspot_action__action__Nav_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hotspot_action__action__Nav_FeedbackMessage__Sequence__are_equal(const hotspot_action__action__Nav_FeedbackMessage__Sequence * lhs, const hotspot_action__action__Nav_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hotspot_action__action__Nav_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hotspot_action__action__Nav_FeedbackMessage__Sequence__copy(
  const hotspot_action__action__Nav_FeedbackMessage__Sequence * input,
  hotspot_action__action__Nav_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hotspot_action__action__Nav_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hotspot_action__action__Nav_FeedbackMessage * data =
      (hotspot_action__action__Nav_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hotspot_action__action__Nav_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hotspot_action__action__Nav_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hotspot_action__action__Nav_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
