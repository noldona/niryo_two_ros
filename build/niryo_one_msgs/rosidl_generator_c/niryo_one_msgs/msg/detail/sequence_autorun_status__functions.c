// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/sequence_autorun_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sequence_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
niryo_one_msgs__msg__SequenceAutorunStatus__init(niryo_one_msgs__msg__SequenceAutorunStatus * msg)
{
  if (!msg) {
    return false;
  }
  // enabled
  // mode
  // sequence_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->sequence_ids, 0)) {
    niryo_one_msgs__msg__SequenceAutorunStatus__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__msg__SequenceAutorunStatus__fini(niryo_one_msgs__msg__SequenceAutorunStatus * msg)
{
  if (!msg) {
    return;
  }
  // enabled
  // mode
  // sequence_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->sequence_ids);
}

bool
niryo_one_msgs__msg__SequenceAutorunStatus__are_equal(const niryo_one_msgs__msg__SequenceAutorunStatus * lhs, const niryo_one_msgs__msg__SequenceAutorunStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // enabled
  if (lhs->enabled != rhs->enabled) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // sequence_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->sequence_ids), &(rhs->sequence_ids)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__SequenceAutorunStatus__copy(
  const niryo_one_msgs__msg__SequenceAutorunStatus * input,
  niryo_one_msgs__msg__SequenceAutorunStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // enabled
  output->enabled = input->enabled;
  // mode
  output->mode = input->mode;
  // sequence_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->sequence_ids), &(output->sequence_ids)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__msg__SequenceAutorunStatus *
niryo_one_msgs__msg__SequenceAutorunStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__SequenceAutorunStatus * msg = (niryo_one_msgs__msg__SequenceAutorunStatus *)allocator.allocate(sizeof(niryo_one_msgs__msg__SequenceAutorunStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__SequenceAutorunStatus));
  bool success = niryo_one_msgs__msg__SequenceAutorunStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__SequenceAutorunStatus__destroy(niryo_one_msgs__msg__SequenceAutorunStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__SequenceAutorunStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__init(niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__SequenceAutorunStatus * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__SequenceAutorunStatus *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__SequenceAutorunStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__SequenceAutorunStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__SequenceAutorunStatus__fini(&data[i - 1]);
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
niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__fini(niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * array)
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
      niryo_one_msgs__msg__SequenceAutorunStatus__fini(&array->data[i]);
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

niryo_one_msgs__msg__SequenceAutorunStatus__Sequence *
niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * array = (niryo_one_msgs__msg__SequenceAutorunStatus__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__SequenceAutorunStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__destroy(niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__are_equal(const niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * lhs, const niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__SequenceAutorunStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__SequenceAutorunStatus__Sequence__copy(
  const niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * input,
  niryo_one_msgs__msg__SequenceAutorunStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__SequenceAutorunStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__SequenceAutorunStatus * data =
      (niryo_one_msgs__msg__SequenceAutorunStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__SequenceAutorunStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__SequenceAutorunStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__SequenceAutorunStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
