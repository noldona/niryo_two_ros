// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/tool_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
niryo_one_msgs__msg__ToolCommand__init(niryo_one_msgs__msg__ToolCommand * msg)
{
  if (!msg) {
    return false;
  }
  // tool_id
  // cmd_type
  // gripper_close_speed
  // gripper_open_speed
  // activate
  // gpio
  return true;
}

void
niryo_one_msgs__msg__ToolCommand__fini(niryo_one_msgs__msg__ToolCommand * msg)
{
  if (!msg) {
    return;
  }
  // tool_id
  // cmd_type
  // gripper_close_speed
  // gripper_open_speed
  // activate
  // gpio
}

bool
niryo_one_msgs__msg__ToolCommand__are_equal(const niryo_one_msgs__msg__ToolCommand * lhs, const niryo_one_msgs__msg__ToolCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tool_id
  if (lhs->tool_id != rhs->tool_id) {
    return false;
  }
  // cmd_type
  if (lhs->cmd_type != rhs->cmd_type) {
    return false;
  }
  // gripper_close_speed
  if (lhs->gripper_close_speed != rhs->gripper_close_speed) {
    return false;
  }
  // gripper_open_speed
  if (lhs->gripper_open_speed != rhs->gripper_open_speed) {
    return false;
  }
  // activate
  if (lhs->activate != rhs->activate) {
    return false;
  }
  // gpio
  if (lhs->gpio != rhs->gpio) {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__ToolCommand__copy(
  const niryo_one_msgs__msg__ToolCommand * input,
  niryo_one_msgs__msg__ToolCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // tool_id
  output->tool_id = input->tool_id;
  // cmd_type
  output->cmd_type = input->cmd_type;
  // gripper_close_speed
  output->gripper_close_speed = input->gripper_close_speed;
  // gripper_open_speed
  output->gripper_open_speed = input->gripper_open_speed;
  // activate
  output->activate = input->activate;
  // gpio
  output->gpio = input->gpio;
  return true;
}

niryo_one_msgs__msg__ToolCommand *
niryo_one_msgs__msg__ToolCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__ToolCommand * msg = (niryo_one_msgs__msg__ToolCommand *)allocator.allocate(sizeof(niryo_one_msgs__msg__ToolCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__ToolCommand));
  bool success = niryo_one_msgs__msg__ToolCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__ToolCommand__destroy(niryo_one_msgs__msg__ToolCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__ToolCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__ToolCommand__Sequence__init(niryo_one_msgs__msg__ToolCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__ToolCommand * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__ToolCommand *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__ToolCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__ToolCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__ToolCommand__fini(&data[i - 1]);
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
niryo_one_msgs__msg__ToolCommand__Sequence__fini(niryo_one_msgs__msg__ToolCommand__Sequence * array)
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
      niryo_one_msgs__msg__ToolCommand__fini(&array->data[i]);
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

niryo_one_msgs__msg__ToolCommand__Sequence *
niryo_one_msgs__msg__ToolCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__ToolCommand__Sequence * array = (niryo_one_msgs__msg__ToolCommand__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__ToolCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__ToolCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__ToolCommand__Sequence__destroy(niryo_one_msgs__msg__ToolCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__ToolCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__ToolCommand__Sequence__are_equal(const niryo_one_msgs__msg__ToolCommand__Sequence * lhs, const niryo_one_msgs__msg__ToolCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__ToolCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__ToolCommand__Sequence__copy(
  const niryo_one_msgs__msg__ToolCommand__Sequence * input,
  niryo_one_msgs__msg__ToolCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__ToolCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__ToolCommand * data =
      (niryo_one_msgs__msg__ToolCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__ToolCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__ToolCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__ToolCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
