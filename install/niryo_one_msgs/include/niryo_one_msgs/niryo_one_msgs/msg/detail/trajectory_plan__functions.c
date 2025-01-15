// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/TrajectoryPlan.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/trajectory_plan__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `trajectory_start`
#include "moveit_msgs/msg/detail/robot_state__functions.h"
// Member `group_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `trajectory`
#include "moveit_msgs/msg/detail/robot_trajectory__functions.h"

bool
niryo_one_msgs__msg__TrajectoryPlan__init(niryo_one_msgs__msg__TrajectoryPlan * msg)
{
  if (!msg) {
    return false;
  }
  // trajectory_start
  if (!moveit_msgs__msg__RobotState__init(&msg->trajectory_start)) {
    niryo_one_msgs__msg__TrajectoryPlan__fini(msg);
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__init(&msg->group_name)) {
    niryo_one_msgs__msg__TrajectoryPlan__fini(msg);
    return false;
  }
  // trajectory
  if (!moveit_msgs__msg__RobotTrajectory__init(&msg->trajectory)) {
    niryo_one_msgs__msg__TrajectoryPlan__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__msg__TrajectoryPlan__fini(niryo_one_msgs__msg__TrajectoryPlan * msg)
{
  if (!msg) {
    return;
  }
  // trajectory_start
  moveit_msgs__msg__RobotState__fini(&msg->trajectory_start);
  // group_name
  rosidl_runtime_c__String__fini(&msg->group_name);
  // trajectory
  moveit_msgs__msg__RobotTrajectory__fini(&msg->trajectory);
}

bool
niryo_one_msgs__msg__TrajectoryPlan__are_equal(const niryo_one_msgs__msg__TrajectoryPlan * lhs, const niryo_one_msgs__msg__TrajectoryPlan * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // trajectory_start
  if (!moveit_msgs__msg__RobotState__are_equal(
      &(lhs->trajectory_start), &(rhs->trajectory_start)))
  {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->group_name), &(rhs->group_name)))
  {
    return false;
  }
  // trajectory
  if (!moveit_msgs__msg__RobotTrajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__TrajectoryPlan__copy(
  const niryo_one_msgs__msg__TrajectoryPlan * input,
  niryo_one_msgs__msg__TrajectoryPlan * output)
{
  if (!input || !output) {
    return false;
  }
  // trajectory_start
  if (!moveit_msgs__msg__RobotState__copy(
      &(input->trajectory_start), &(output->trajectory_start)))
  {
    return false;
  }
  // group_name
  if (!rosidl_runtime_c__String__copy(
      &(input->group_name), &(output->group_name)))
  {
    return false;
  }
  // trajectory
  if (!moveit_msgs__msg__RobotTrajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__msg__TrajectoryPlan *
niryo_one_msgs__msg__TrajectoryPlan__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__TrajectoryPlan * msg = (niryo_one_msgs__msg__TrajectoryPlan *)allocator.allocate(sizeof(niryo_one_msgs__msg__TrajectoryPlan), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__TrajectoryPlan));
  bool success = niryo_one_msgs__msg__TrajectoryPlan__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__TrajectoryPlan__destroy(niryo_one_msgs__msg__TrajectoryPlan * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__TrajectoryPlan__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__TrajectoryPlan__Sequence__init(niryo_one_msgs__msg__TrajectoryPlan__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__TrajectoryPlan * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__TrajectoryPlan *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__TrajectoryPlan), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__TrajectoryPlan__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__TrajectoryPlan__fini(&data[i - 1]);
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
niryo_one_msgs__msg__TrajectoryPlan__Sequence__fini(niryo_one_msgs__msg__TrajectoryPlan__Sequence * array)
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
      niryo_one_msgs__msg__TrajectoryPlan__fini(&array->data[i]);
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

niryo_one_msgs__msg__TrajectoryPlan__Sequence *
niryo_one_msgs__msg__TrajectoryPlan__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__TrajectoryPlan__Sequence * array = (niryo_one_msgs__msg__TrajectoryPlan__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__TrajectoryPlan__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__TrajectoryPlan__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__TrajectoryPlan__Sequence__destroy(niryo_one_msgs__msg__TrajectoryPlan__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__TrajectoryPlan__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__TrajectoryPlan__Sequence__are_equal(const niryo_one_msgs__msg__TrajectoryPlan__Sequence * lhs, const niryo_one_msgs__msg__TrajectoryPlan__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__TrajectoryPlan__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__TrajectoryPlan__Sequence__copy(
  const niryo_one_msgs__msg__TrajectoryPlan__Sequence * input,
  niryo_one_msgs__msg__TrajectoryPlan__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__TrajectoryPlan);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__TrajectoryPlan * data =
      (niryo_one_msgs__msg__TrajectoryPlan *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__TrajectoryPlan__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__TrajectoryPlan__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__TrajectoryPlan__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
