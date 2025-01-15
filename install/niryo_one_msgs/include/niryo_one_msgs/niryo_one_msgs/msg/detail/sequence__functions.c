// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/Sequence.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/sequence__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `name`
// Member `description`
// Member `blockly_xml`
// Member `python_code`
#include "rosidl_runtime_c/string_functions.h"

bool
niryo_one_msgs__msg__Sequence__init(niryo_one_msgs__msg__Sequence * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // name
  if (!rosidl_runtime_c__String__init(&msg->name)) {
    niryo_one_msgs__msg__Sequence__fini(msg);
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__init(&msg->description)) {
    niryo_one_msgs__msg__Sequence__fini(msg);
    return false;
  }
  // created
  // updated
  // blockly_xml
  if (!rosidl_runtime_c__String__init(&msg->blockly_xml)) {
    niryo_one_msgs__msg__Sequence__fini(msg);
    return false;
  }
  // python_code
  if (!rosidl_runtime_c__String__init(&msg->python_code)) {
    niryo_one_msgs__msg__Sequence__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__msg__Sequence__fini(niryo_one_msgs__msg__Sequence * msg)
{
  if (!msg) {
    return;
  }
  // id
  // name
  rosidl_runtime_c__String__fini(&msg->name);
  // description
  rosidl_runtime_c__String__fini(&msg->description);
  // created
  // updated
  // blockly_xml
  rosidl_runtime_c__String__fini(&msg->blockly_xml);
  // python_code
  rosidl_runtime_c__String__fini(&msg->python_code);
}

bool
niryo_one_msgs__msg__Sequence__are_equal(const niryo_one_msgs__msg__Sequence * lhs, const niryo_one_msgs__msg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->name), &(rhs->name)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->description), &(rhs->description)))
  {
    return false;
  }
  // created
  if (lhs->created != rhs->created) {
    return false;
  }
  // updated
  if (lhs->updated != rhs->updated) {
    return false;
  }
  // blockly_xml
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->blockly_xml), &(rhs->blockly_xml)))
  {
    return false;
  }
  // python_code
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->python_code), &(rhs->python_code)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__Sequence__copy(
  const niryo_one_msgs__msg__Sequence * input,
  niryo_one_msgs__msg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // name
  if (!rosidl_runtime_c__String__copy(
      &(input->name), &(output->name)))
  {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__copy(
      &(input->description), &(output->description)))
  {
    return false;
  }
  // created
  output->created = input->created;
  // updated
  output->updated = input->updated;
  // blockly_xml
  if (!rosidl_runtime_c__String__copy(
      &(input->blockly_xml), &(output->blockly_xml)))
  {
    return false;
  }
  // python_code
  if (!rosidl_runtime_c__String__copy(
      &(input->python_code), &(output->python_code)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__msg__Sequence *
niryo_one_msgs__msg__Sequence__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__Sequence * msg = (niryo_one_msgs__msg__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__Sequence), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__Sequence));
  bool success = niryo_one_msgs__msg__Sequence__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__Sequence__destroy(niryo_one_msgs__msg__Sequence * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__Sequence__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__Sequence__Sequence__init(niryo_one_msgs__msg__Sequence__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__Sequence * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__Sequence *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__Sequence), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__Sequence__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__Sequence__fini(&data[i - 1]);
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
niryo_one_msgs__msg__Sequence__Sequence__fini(niryo_one_msgs__msg__Sequence__Sequence * array)
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
      niryo_one_msgs__msg__Sequence__fini(&array->data[i]);
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

niryo_one_msgs__msg__Sequence__Sequence *
niryo_one_msgs__msg__Sequence__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__Sequence__Sequence * array = (niryo_one_msgs__msg__Sequence__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__Sequence__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__Sequence__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__Sequence__Sequence__destroy(niryo_one_msgs__msg__Sequence__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__Sequence__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__Sequence__Sequence__are_equal(const niryo_one_msgs__msg__Sequence__Sequence * lhs, const niryo_one_msgs__msg__Sequence__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__Sequence__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__Sequence__Sequence__copy(
  const niryo_one_msgs__msg__Sequence__Sequence * input,
  niryo_one_msgs__msg__Sequence__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__Sequence);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__Sequence * data =
      (niryo_one_msgs__msg__Sequence *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__Sequence__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__Sequence__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__Sequence__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
