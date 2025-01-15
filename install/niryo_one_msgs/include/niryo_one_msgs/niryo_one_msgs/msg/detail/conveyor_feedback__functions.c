// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/conveyor_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
niryo_one_msgs__msg__ConveyorFeedback__init(niryo_one_msgs__msg__ConveyorFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // conveyor_id
  // connection_state
  // running
  // speed
  // direction
  return true;
}

void
niryo_one_msgs__msg__ConveyorFeedback__fini(niryo_one_msgs__msg__ConveyorFeedback * msg)
{
  if (!msg) {
    return;
  }
  // conveyor_id
  // connection_state
  // running
  // speed
  // direction
}

bool
niryo_one_msgs__msg__ConveyorFeedback__are_equal(const niryo_one_msgs__msg__ConveyorFeedback * lhs, const niryo_one_msgs__msg__ConveyorFeedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // conveyor_id
  if (lhs->conveyor_id != rhs->conveyor_id) {
    return false;
  }
  // connection_state
  if (lhs->connection_state != rhs->connection_state) {
    return false;
  }
  // running
  if (lhs->running != rhs->running) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // direction
  if (lhs->direction != rhs->direction) {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__ConveyorFeedback__copy(
  const niryo_one_msgs__msg__ConveyorFeedback * input,
  niryo_one_msgs__msg__ConveyorFeedback * output)
{
  if (!input || !output) {
    return false;
  }
  // conveyor_id
  output->conveyor_id = input->conveyor_id;
  // connection_state
  output->connection_state = input->connection_state;
  // running
  output->running = input->running;
  // speed
  output->speed = input->speed;
  // direction
  output->direction = input->direction;
  return true;
}

niryo_one_msgs__msg__ConveyorFeedback *
niryo_one_msgs__msg__ConveyorFeedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__ConveyorFeedback * msg = (niryo_one_msgs__msg__ConveyorFeedback *)allocator.allocate(sizeof(niryo_one_msgs__msg__ConveyorFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__ConveyorFeedback));
  bool success = niryo_one_msgs__msg__ConveyorFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__ConveyorFeedback__destroy(niryo_one_msgs__msg__ConveyorFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__ConveyorFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__ConveyorFeedback__Sequence__init(niryo_one_msgs__msg__ConveyorFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__ConveyorFeedback * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__ConveyorFeedback *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__ConveyorFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__ConveyorFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__ConveyorFeedback__fini(&data[i - 1]);
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
niryo_one_msgs__msg__ConveyorFeedback__Sequence__fini(niryo_one_msgs__msg__ConveyorFeedback__Sequence * array)
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
      niryo_one_msgs__msg__ConveyorFeedback__fini(&array->data[i]);
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

niryo_one_msgs__msg__ConveyorFeedback__Sequence *
niryo_one_msgs__msg__ConveyorFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__ConveyorFeedback__Sequence * array = (niryo_one_msgs__msg__ConveyorFeedback__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__ConveyorFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__ConveyorFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__ConveyorFeedback__Sequence__destroy(niryo_one_msgs__msg__ConveyorFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__ConveyorFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__ConveyorFeedback__Sequence__are_equal(const niryo_one_msgs__msg__ConveyorFeedback__Sequence * lhs, const niryo_one_msgs__msg__ConveyorFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__ConveyorFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__ConveyorFeedback__Sequence__copy(
  const niryo_one_msgs__msg__ConveyorFeedback__Sequence * input,
  niryo_one_msgs__msg__ConveyorFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__ConveyorFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__ConveyorFeedback * data =
      (niryo_one_msgs__msg__ConveyorFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__ConveyorFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__ConveyorFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__ConveyorFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
