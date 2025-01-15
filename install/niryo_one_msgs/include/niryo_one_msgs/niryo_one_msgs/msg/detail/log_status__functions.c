// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/LogStatus.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/log_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
niryo_one_msgs__msg__LogStatus__init(niryo_one_msgs__msg__LogStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    niryo_one_msgs__msg__LogStatus__fini(msg);
    return false;
  }
  // log_size
  // available_disk_size
  // purge_log_on_startup
  return true;
}

void
niryo_one_msgs__msg__LogStatus__fini(niryo_one_msgs__msg__LogStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // log_size
  // available_disk_size
  // purge_log_on_startup
}

bool
niryo_one_msgs__msg__LogStatus__are_equal(const niryo_one_msgs__msg__LogStatus * lhs, const niryo_one_msgs__msg__LogStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // log_size
  if (lhs->log_size != rhs->log_size) {
    return false;
  }
  // available_disk_size
  if (lhs->available_disk_size != rhs->available_disk_size) {
    return false;
  }
  // purge_log_on_startup
  if (lhs->purge_log_on_startup != rhs->purge_log_on_startup) {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__LogStatus__copy(
  const niryo_one_msgs__msg__LogStatus * input,
  niryo_one_msgs__msg__LogStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // log_size
  output->log_size = input->log_size;
  // available_disk_size
  output->available_disk_size = input->available_disk_size;
  // purge_log_on_startup
  output->purge_log_on_startup = input->purge_log_on_startup;
  return true;
}

niryo_one_msgs__msg__LogStatus *
niryo_one_msgs__msg__LogStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__LogStatus * msg = (niryo_one_msgs__msg__LogStatus *)allocator.allocate(sizeof(niryo_one_msgs__msg__LogStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__LogStatus));
  bool success = niryo_one_msgs__msg__LogStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__LogStatus__destroy(niryo_one_msgs__msg__LogStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__LogStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__LogStatus__Sequence__init(niryo_one_msgs__msg__LogStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__LogStatus * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__LogStatus *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__LogStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__LogStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__LogStatus__fini(&data[i - 1]);
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
niryo_one_msgs__msg__LogStatus__Sequence__fini(niryo_one_msgs__msg__LogStatus__Sequence * array)
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
      niryo_one_msgs__msg__LogStatus__fini(&array->data[i]);
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

niryo_one_msgs__msg__LogStatus__Sequence *
niryo_one_msgs__msg__LogStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__LogStatus__Sequence * array = (niryo_one_msgs__msg__LogStatus__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__LogStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__LogStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__LogStatus__Sequence__destroy(niryo_one_msgs__msg__LogStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__LogStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__LogStatus__Sequence__are_equal(const niryo_one_msgs__msg__LogStatus__Sequence * lhs, const niryo_one_msgs__msg__LogStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__LogStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__LogStatus__Sequence__copy(
  const niryo_one_msgs__msg__LogStatus__Sequence * input,
  niryo_one_msgs__msg__LogStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__LogStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__LogStatus * data =
      (niryo_one_msgs__msg__LogStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__LogStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__LogStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__LogStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
