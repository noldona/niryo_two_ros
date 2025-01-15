// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/RobotMoveCommand.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/robot_move_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `joints`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `rpy`
#include "niryo_one_msgs/msg/detail/rpy__functions.h"
// Member `shift`
#include "niryo_one_msgs/msg/detail/shift_pose__functions.h"
// Member `trajectory`
#include "niryo_one_msgs/msg/detail/trajectory_plan__functions.h"
// Member `pose_quat`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `saved_position_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `tool_cmd`
#include "niryo_one_msgs/msg/detail/tool_command__functions.h"

bool
niryo_one_msgs__msg__RobotMoveCommand__init(niryo_one_msgs__msg__RobotMoveCommand * msg)
{
  if (!msg) {
    return false;
  }
  // cmd_type
  // joints
  if (!rosidl_runtime_c__double__Sequence__init(&msg->joints, 0)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  // rpy
  if (!niryo_one_msgs__msg__RPY__init(&msg->rpy)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  // shift
  if (!niryo_one_msgs__msg__ShiftPose__init(&msg->shift)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  // trajectory
  if (!niryo_one_msgs__msg__TrajectoryPlan__init(&msg->trajectory)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  // pose_quat
  if (!geometry_msgs__msg__Pose__init(&msg->pose_quat)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  // saved_position_name
  if (!rosidl_runtime_c__String__init(&msg->saved_position_name)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  // saved_trajectory_id
  // tool_cmd
  if (!niryo_one_msgs__msg__ToolCommand__init(&msg->tool_cmd)) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__msg__RobotMoveCommand__fini(niryo_one_msgs__msg__RobotMoveCommand * msg)
{
  if (!msg) {
    return;
  }
  // cmd_type
  // joints
  rosidl_runtime_c__double__Sequence__fini(&msg->joints);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // rpy
  niryo_one_msgs__msg__RPY__fini(&msg->rpy);
  // shift
  niryo_one_msgs__msg__ShiftPose__fini(&msg->shift);
  // trajectory
  niryo_one_msgs__msg__TrajectoryPlan__fini(&msg->trajectory);
  // pose_quat
  geometry_msgs__msg__Pose__fini(&msg->pose_quat);
  // saved_position_name
  rosidl_runtime_c__String__fini(&msg->saved_position_name);
  // saved_trajectory_id
  // tool_cmd
  niryo_one_msgs__msg__ToolCommand__fini(&msg->tool_cmd);
}

bool
niryo_one_msgs__msg__RobotMoveCommand__are_equal(const niryo_one_msgs__msg__RobotMoveCommand * lhs, const niryo_one_msgs__msg__RobotMoveCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd_type
  if (lhs->cmd_type != rhs->cmd_type) {
    return false;
  }
  // joints
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->joints), &(rhs->joints)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // rpy
  if (!niryo_one_msgs__msg__RPY__are_equal(
      &(lhs->rpy), &(rhs->rpy)))
  {
    return false;
  }
  // shift
  if (!niryo_one_msgs__msg__ShiftPose__are_equal(
      &(lhs->shift), &(rhs->shift)))
  {
    return false;
  }
  // trajectory
  if (!niryo_one_msgs__msg__TrajectoryPlan__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  // pose_quat
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->pose_quat), &(rhs->pose_quat)))
  {
    return false;
  }
  // saved_position_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->saved_position_name), &(rhs->saved_position_name)))
  {
    return false;
  }
  // saved_trajectory_id
  if (lhs->saved_trajectory_id != rhs->saved_trajectory_id) {
    return false;
  }
  // tool_cmd
  if (!niryo_one_msgs__msg__ToolCommand__are_equal(
      &(lhs->tool_cmd), &(rhs->tool_cmd)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__RobotMoveCommand__copy(
  const niryo_one_msgs__msg__RobotMoveCommand * input,
  niryo_one_msgs__msg__RobotMoveCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd_type
  output->cmd_type = input->cmd_type;
  // joints
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->joints), &(output->joints)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // rpy
  if (!niryo_one_msgs__msg__RPY__copy(
      &(input->rpy), &(output->rpy)))
  {
    return false;
  }
  // shift
  if (!niryo_one_msgs__msg__ShiftPose__copy(
      &(input->shift), &(output->shift)))
  {
    return false;
  }
  // trajectory
  if (!niryo_one_msgs__msg__TrajectoryPlan__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  // pose_quat
  if (!geometry_msgs__msg__Pose__copy(
      &(input->pose_quat), &(output->pose_quat)))
  {
    return false;
  }
  // saved_position_name
  if (!rosidl_runtime_c__String__copy(
      &(input->saved_position_name), &(output->saved_position_name)))
  {
    return false;
  }
  // saved_trajectory_id
  output->saved_trajectory_id = input->saved_trajectory_id;
  // tool_cmd
  if (!niryo_one_msgs__msg__ToolCommand__copy(
      &(input->tool_cmd), &(output->tool_cmd)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__msg__RobotMoveCommand *
niryo_one_msgs__msg__RobotMoveCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__RobotMoveCommand * msg = (niryo_one_msgs__msg__RobotMoveCommand *)allocator.allocate(sizeof(niryo_one_msgs__msg__RobotMoveCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__RobotMoveCommand));
  bool success = niryo_one_msgs__msg__RobotMoveCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__RobotMoveCommand__destroy(niryo_one_msgs__msg__RobotMoveCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__RobotMoveCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__RobotMoveCommand__Sequence__init(niryo_one_msgs__msg__RobotMoveCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__RobotMoveCommand * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__RobotMoveCommand *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__RobotMoveCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__RobotMoveCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__RobotMoveCommand__fini(&data[i - 1]);
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
niryo_one_msgs__msg__RobotMoveCommand__Sequence__fini(niryo_one_msgs__msg__RobotMoveCommand__Sequence * array)
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
      niryo_one_msgs__msg__RobotMoveCommand__fini(&array->data[i]);
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

niryo_one_msgs__msg__RobotMoveCommand__Sequence *
niryo_one_msgs__msg__RobotMoveCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__RobotMoveCommand__Sequence * array = (niryo_one_msgs__msg__RobotMoveCommand__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__RobotMoveCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__RobotMoveCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__RobotMoveCommand__Sequence__destroy(niryo_one_msgs__msg__RobotMoveCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__RobotMoveCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__RobotMoveCommand__Sequence__are_equal(const niryo_one_msgs__msg__RobotMoveCommand__Sequence * lhs, const niryo_one_msgs__msg__RobotMoveCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__RobotMoveCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__RobotMoveCommand__Sequence__copy(
  const niryo_one_msgs__msg__RobotMoveCommand__Sequence * input,
  niryo_one_msgs__msg__RobotMoveCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__RobotMoveCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__RobotMoveCommand * data =
      (niryo_one_msgs__msg__RobotMoveCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__RobotMoveCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__RobotMoveCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__RobotMoveCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
