// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:action/RobotMove.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/action/detail/robot_move__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `cmd`
#include "niryo_one_msgs/msg/detail/robot_move_command__functions.h"

bool
niryo_one_msgs__action__RobotMove_Goal__init(niryo_one_msgs__action__RobotMove_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // cmd
  if (!niryo_one_msgs__msg__RobotMoveCommand__init(&msg->cmd)) {
    niryo_one_msgs__action__RobotMove_Goal__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_Goal__fini(niryo_one_msgs__action__RobotMove_Goal * msg)
{
  if (!msg) {
    return;
  }
  // cmd
  niryo_one_msgs__msg__RobotMoveCommand__fini(&msg->cmd);
}

bool
niryo_one_msgs__action__RobotMove_Goal__are_equal(const niryo_one_msgs__action__RobotMove_Goal * lhs, const niryo_one_msgs__action__RobotMove_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd
  if (!niryo_one_msgs__msg__RobotMoveCommand__are_equal(
      &(lhs->cmd), &(rhs->cmd)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_Goal__copy(
  const niryo_one_msgs__action__RobotMove_Goal * input,
  niryo_one_msgs__action__RobotMove_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd
  if (!niryo_one_msgs__msg__RobotMoveCommand__copy(
      &(input->cmd), &(output->cmd)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_Goal *
niryo_one_msgs__action__RobotMove_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Goal * msg = (niryo_one_msgs__action__RobotMove_Goal *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_Goal));
  bool success = niryo_one_msgs__action__RobotMove_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_Goal__destroy(niryo_one_msgs__action__RobotMove_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_Goal__Sequence__init(niryo_one_msgs__action__RobotMove_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Goal * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_Goal *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_Goal__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_Goal__Sequence__fini(niryo_one_msgs__action__RobotMove_Goal__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_Goal__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_Goal__Sequence *
niryo_one_msgs__action__RobotMove_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Goal__Sequence * array = (niryo_one_msgs__action__RobotMove_Goal__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_Goal__Sequence__destroy(niryo_one_msgs__action__RobotMove_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_Goal__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_Goal__Sequence * lhs, const niryo_one_msgs__action__RobotMove_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_Goal__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_Goal__Sequence * input,
  niryo_one_msgs__action__RobotMove_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_Goal * data =
      (niryo_one_msgs__action__RobotMove_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
niryo_one_msgs__action__RobotMove_Result__init(niryo_one_msgs__action__RobotMove_Result * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    niryo_one_msgs__action__RobotMove_Result__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_Result__fini(niryo_one_msgs__action__RobotMove_Result * msg)
{
  if (!msg) {
    return;
  }
  // status
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
niryo_one_msgs__action__RobotMove_Result__are_equal(const niryo_one_msgs__action__RobotMove_Result * lhs, const niryo_one_msgs__action__RobotMove_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_Result__copy(
  const niryo_one_msgs__action__RobotMove_Result * input,
  niryo_one_msgs__action__RobotMove_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_Result *
niryo_one_msgs__action__RobotMove_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Result * msg = (niryo_one_msgs__action__RobotMove_Result *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_Result));
  bool success = niryo_one_msgs__action__RobotMove_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_Result__destroy(niryo_one_msgs__action__RobotMove_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_Result__Sequence__init(niryo_one_msgs__action__RobotMove_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Result * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_Result *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_Result__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_Result__Sequence__fini(niryo_one_msgs__action__RobotMove_Result__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_Result__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_Result__Sequence *
niryo_one_msgs__action__RobotMove_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Result__Sequence * array = (niryo_one_msgs__action__RobotMove_Result__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_Result__Sequence__destroy(niryo_one_msgs__action__RobotMove_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_Result__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_Result__Sequence * lhs, const niryo_one_msgs__action__RobotMove_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_Result__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_Result__Sequence * input,
  niryo_one_msgs__action__RobotMove_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_Result * data =
      (niryo_one_msgs__action__RobotMove_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `state`
#include "niryo_one_msgs/msg/detail/robot_state__functions.h"

bool
niryo_one_msgs__action__RobotMove_Feedback__init(niryo_one_msgs__action__RobotMove_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!niryo_one_msgs__msg__RobotState__init(&msg->state)) {
    niryo_one_msgs__action__RobotMove_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_Feedback__fini(niryo_one_msgs__action__RobotMove_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // state
  niryo_one_msgs__msg__RobotState__fini(&msg->state);
}

bool
niryo_one_msgs__action__RobotMove_Feedback__are_equal(const niryo_one_msgs__action__RobotMove_Feedback * lhs, const niryo_one_msgs__action__RobotMove_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (!niryo_one_msgs__msg__RobotState__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_Feedback__copy(
  const niryo_one_msgs__action__RobotMove_Feedback * input,
  niryo_one_msgs__action__RobotMove_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  if (!niryo_one_msgs__msg__RobotState__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_Feedback *
niryo_one_msgs__action__RobotMove_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Feedback * msg = (niryo_one_msgs__action__RobotMove_Feedback *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_Feedback));
  bool success = niryo_one_msgs__action__RobotMove_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_Feedback__destroy(niryo_one_msgs__action__RobotMove_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_Feedback__Sequence__init(niryo_one_msgs__action__RobotMove_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Feedback * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_Feedback *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_Feedback__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_Feedback__Sequence__fini(niryo_one_msgs__action__RobotMove_Feedback__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_Feedback__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_Feedback__Sequence *
niryo_one_msgs__action__RobotMove_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_Feedback__Sequence * array = (niryo_one_msgs__action__RobotMove_Feedback__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_Feedback__Sequence__destroy(niryo_one_msgs__action__RobotMove_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_Feedback__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_Feedback__Sequence * lhs, const niryo_one_msgs__action__RobotMove_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_Feedback__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_Feedback__Sequence * input,
  niryo_one_msgs__action__RobotMove_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_Feedback * data =
      (niryo_one_msgs__action__RobotMove_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_Feedback__copy(
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
// #include "niryo_one_msgs/action/detail/robot_move__functions.h"

bool
niryo_one_msgs__action__RobotMove_SendGoal_Request__init(niryo_one_msgs__action__RobotMove_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    niryo_one_msgs__action__RobotMove_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!niryo_one_msgs__action__RobotMove_Goal__init(&msg->goal)) {
    niryo_one_msgs__action__RobotMove_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Request__fini(niryo_one_msgs__action__RobotMove_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  niryo_one_msgs__action__RobotMove_Goal__fini(&msg->goal);
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Request__are_equal(const niryo_one_msgs__action__RobotMove_SendGoal_Request * lhs, const niryo_one_msgs__action__RobotMove_SendGoal_Request * rhs)
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
  if (!niryo_one_msgs__action__RobotMove_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Request__copy(
  const niryo_one_msgs__action__RobotMove_SendGoal_Request * input,
  niryo_one_msgs__action__RobotMove_SendGoal_Request * output)
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
  if (!niryo_one_msgs__action__RobotMove_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_SendGoal_Request *
niryo_one_msgs__action__RobotMove_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Request * msg = (niryo_one_msgs__action__RobotMove_SendGoal_Request *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Request));
  bool success = niryo_one_msgs__action__RobotMove_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Request__destroy(niryo_one_msgs__action__RobotMove_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__init(niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Request * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_SendGoal_Request *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_SendGoal_Request__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__fini(niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_SendGoal_Request__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence *
niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * array = (niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__destroy(niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * lhs, const niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * input,
  niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_SendGoal_Request * data =
      (niryo_one_msgs__action__RobotMove_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_SendGoal_Request__copy(
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
niryo_one_msgs__action__RobotMove_SendGoal_Response__init(niryo_one_msgs__action__RobotMove_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    niryo_one_msgs__action__RobotMove_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Response__fini(niryo_one_msgs__action__RobotMove_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Response__are_equal(const niryo_one_msgs__action__RobotMove_SendGoal_Response * lhs, const niryo_one_msgs__action__RobotMove_SendGoal_Response * rhs)
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
niryo_one_msgs__action__RobotMove_SendGoal_Response__copy(
  const niryo_one_msgs__action__RobotMove_SendGoal_Response * input,
  niryo_one_msgs__action__RobotMove_SendGoal_Response * output)
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

niryo_one_msgs__action__RobotMove_SendGoal_Response *
niryo_one_msgs__action__RobotMove_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Response * msg = (niryo_one_msgs__action__RobotMove_SendGoal_Response *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Response));
  bool success = niryo_one_msgs__action__RobotMove_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Response__destroy(niryo_one_msgs__action__RobotMove_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__init(niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Response * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_SendGoal_Response *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_SendGoal_Response__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__fini(niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_SendGoal_Response__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence *
niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * array = (niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__destroy(niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * lhs, const niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * input,
  niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_SendGoal_Response * data =
      (niryo_one_msgs__action__RobotMove_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "niryo_one_msgs/action/detail/robot_move__functions.h"

bool
niryo_one_msgs__action__RobotMove_SendGoal_Event__init(niryo_one_msgs__action__RobotMove_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(niryo_one_msgs__action__RobotMove_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Event__are_equal(const niryo_one_msgs__action__RobotMove_SendGoal_Event * lhs, const niryo_one_msgs__action__RobotMove_SendGoal_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Event__copy(
  const niryo_one_msgs__action__RobotMove_SendGoal_Event * input,
  niryo_one_msgs__action__RobotMove_SendGoal_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_SendGoal_Event *
niryo_one_msgs__action__RobotMove_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Event * msg = (niryo_one_msgs__action__RobotMove_SendGoal_Event *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Event));
  bool success = niryo_one_msgs__action__RobotMove_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Event__destroy(niryo_one_msgs__action__RobotMove_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__init(niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Event * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_SendGoal_Event *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__fini(niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence *
niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * array = (niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__destroy(niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * lhs, const niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * input,
  niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_SendGoal_Event * data =
      (niryo_one_msgs__action__RobotMove_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_SendGoal_Event__copy(
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
niryo_one_msgs__action__RobotMove_GetResult_Request__init(niryo_one_msgs__action__RobotMove_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    niryo_one_msgs__action__RobotMove_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Request__fini(niryo_one_msgs__action__RobotMove_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Request__are_equal(const niryo_one_msgs__action__RobotMove_GetResult_Request * lhs, const niryo_one_msgs__action__RobotMove_GetResult_Request * rhs)
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
niryo_one_msgs__action__RobotMove_GetResult_Request__copy(
  const niryo_one_msgs__action__RobotMove_GetResult_Request * input,
  niryo_one_msgs__action__RobotMove_GetResult_Request * output)
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

niryo_one_msgs__action__RobotMove_GetResult_Request *
niryo_one_msgs__action__RobotMove_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Request * msg = (niryo_one_msgs__action__RobotMove_GetResult_Request *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_GetResult_Request));
  bool success = niryo_one_msgs__action__RobotMove_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Request__destroy(niryo_one_msgs__action__RobotMove_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__init(niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Request * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_GetResult_Request *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_GetResult_Request__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__fini(niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_GetResult_Request__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence *
niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * array = (niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__destroy(niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * lhs, const niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * input,
  niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_GetResult_Request * data =
      (niryo_one_msgs__action__RobotMove_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_GetResult_Request__copy(
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
// #include "niryo_one_msgs/action/detail/robot_move__functions.h"

bool
niryo_one_msgs__action__RobotMove_GetResult_Response__init(niryo_one_msgs__action__RobotMove_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!niryo_one_msgs__action__RobotMove_Result__init(&msg->result)) {
    niryo_one_msgs__action__RobotMove_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Response__fini(niryo_one_msgs__action__RobotMove_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  niryo_one_msgs__action__RobotMove_Result__fini(&msg->result);
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Response__are_equal(const niryo_one_msgs__action__RobotMove_GetResult_Response * lhs, const niryo_one_msgs__action__RobotMove_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!niryo_one_msgs__action__RobotMove_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Response__copy(
  const niryo_one_msgs__action__RobotMove_GetResult_Response * input,
  niryo_one_msgs__action__RobotMove_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!niryo_one_msgs__action__RobotMove_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_GetResult_Response *
niryo_one_msgs__action__RobotMove_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Response * msg = (niryo_one_msgs__action__RobotMove_GetResult_Response *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_GetResult_Response));
  bool success = niryo_one_msgs__action__RobotMove_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Response__destroy(niryo_one_msgs__action__RobotMove_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__init(niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Response * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_GetResult_Response *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_GetResult_Response__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__fini(niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_GetResult_Response__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence *
niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * array = (niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__destroy(niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * lhs, const niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * input,
  niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_GetResult_Response * data =
      (niryo_one_msgs__action__RobotMove_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "niryo_one_msgs/action/detail/robot_move__functions.h"

bool
niryo_one_msgs__action__RobotMove_GetResult_Event__init(niryo_one_msgs__action__RobotMove_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    niryo_one_msgs__action__RobotMove_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__init(&msg->request, 0)) {
    niryo_one_msgs__action__RobotMove_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__init(&msg->response, 0)) {
    niryo_one_msgs__action__RobotMove_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Event__fini(niryo_one_msgs__action__RobotMove_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__fini(&msg->request);
  // response
  niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__fini(&msg->response);
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Event__are_equal(const niryo_one_msgs__action__RobotMove_GetResult_Event * lhs, const niryo_one_msgs__action__RobotMove_GetResult_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Event__copy(
  const niryo_one_msgs__action__RobotMove_GetResult_Event * input,
  niryo_one_msgs__action__RobotMove_GetResult_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_GetResult_Event *
niryo_one_msgs__action__RobotMove_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Event * msg = (niryo_one_msgs__action__RobotMove_GetResult_Event *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_GetResult_Event));
  bool success = niryo_one_msgs__action__RobotMove_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Event__destroy(niryo_one_msgs__action__RobotMove_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__init(niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Event * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_GetResult_Event *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_GetResult_Event__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__fini(niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_GetResult_Event__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence *
niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * array = (niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__destroy(niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * lhs, const niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * input,
  niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_GetResult_Event * data =
      (niryo_one_msgs__action__RobotMove_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_GetResult_Event__copy(
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
// #include "niryo_one_msgs/action/detail/robot_move__functions.h"

bool
niryo_one_msgs__action__RobotMove_FeedbackMessage__init(niryo_one_msgs__action__RobotMove_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    niryo_one_msgs__action__RobotMove_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!niryo_one_msgs__action__RobotMove_Feedback__init(&msg->feedback)) {
    niryo_one_msgs__action__RobotMove_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__action__RobotMove_FeedbackMessage__fini(niryo_one_msgs__action__RobotMove_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  niryo_one_msgs__action__RobotMove_Feedback__fini(&msg->feedback);
}

bool
niryo_one_msgs__action__RobotMove_FeedbackMessage__are_equal(const niryo_one_msgs__action__RobotMove_FeedbackMessage * lhs, const niryo_one_msgs__action__RobotMove_FeedbackMessage * rhs)
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
  if (!niryo_one_msgs__action__RobotMove_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_FeedbackMessage__copy(
  const niryo_one_msgs__action__RobotMove_FeedbackMessage * input,
  niryo_one_msgs__action__RobotMove_FeedbackMessage * output)
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
  if (!niryo_one_msgs__action__RobotMove_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__action__RobotMove_FeedbackMessage *
niryo_one_msgs__action__RobotMove_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_FeedbackMessage * msg = (niryo_one_msgs__action__RobotMove_FeedbackMessage *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__action__RobotMove_FeedbackMessage));
  bool success = niryo_one_msgs__action__RobotMove_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__action__RobotMove_FeedbackMessage__destroy(niryo_one_msgs__action__RobotMove_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__action__RobotMove_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__init(niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_FeedbackMessage * data = NULL;

  if (size) {
    data = (niryo_one_msgs__action__RobotMove_FeedbackMessage *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__action__RobotMove_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__action__RobotMove_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__action__RobotMove_FeedbackMessage__fini(&data[i - 1]);
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
niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__fini(niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * array)
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
      niryo_one_msgs__action__RobotMove_FeedbackMessage__fini(&array->data[i]);
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

niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence *
niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * array = (niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__destroy(niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__are_equal(const niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * lhs, const niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence__copy(
  const niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * input,
  niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__action__RobotMove_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__action__RobotMove_FeedbackMessage * data =
      (niryo_one_msgs__action__RobotMove_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__action__RobotMove_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__action__RobotMove_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__action__RobotMove_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
