// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/HardwareStatus.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/hardware_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `error_message`
// Member `motor_names`
// Member `motor_types`
#include "rosidl_runtime_c/string_functions.h"
// Member `temperatures`
// Member `voltages`
// Member `hardware_errors`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
niryo_one_msgs__msg__HardwareStatus__init(niryo_one_msgs__msg__HardwareStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
    return false;
  }
  // rpi_temperature
  // hardware_version
  // connection_up
  // error_message
  if (!rosidl_runtime_c__String__init(&msg->error_message)) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
    return false;
  }
  // calibration_needed
  // calibration_in_progress
  // motor_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->motor_names, 0)) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
    return false;
  }
  // motor_types
  if (!rosidl_runtime_c__String__Sequence__init(&msg->motor_types, 0)) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
    return false;
  }
  // temperatures
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->temperatures, 0)) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
    return false;
  }
  // voltages
  if (!rosidl_runtime_c__double__Sequence__init(&msg->voltages, 0)) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
    return false;
  }
  // hardware_errors
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->hardware_errors, 0)) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__msg__HardwareStatus__fini(niryo_one_msgs__msg__HardwareStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // rpi_temperature
  // hardware_version
  // connection_up
  // error_message
  rosidl_runtime_c__String__fini(&msg->error_message);
  // calibration_needed
  // calibration_in_progress
  // motor_names
  rosidl_runtime_c__String__Sequence__fini(&msg->motor_names);
  // motor_types
  rosidl_runtime_c__String__Sequence__fini(&msg->motor_types);
  // temperatures
  rosidl_runtime_c__int32__Sequence__fini(&msg->temperatures);
  // voltages
  rosidl_runtime_c__double__Sequence__fini(&msg->voltages);
  // hardware_errors
  rosidl_runtime_c__int32__Sequence__fini(&msg->hardware_errors);
}

bool
niryo_one_msgs__msg__HardwareStatus__are_equal(const niryo_one_msgs__msg__HardwareStatus * lhs, const niryo_one_msgs__msg__HardwareStatus * rhs)
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
  // rpi_temperature
  if (lhs->rpi_temperature != rhs->rpi_temperature) {
    return false;
  }
  // hardware_version
  if (lhs->hardware_version != rhs->hardware_version) {
    return false;
  }
  // connection_up
  if (lhs->connection_up != rhs->connection_up) {
    return false;
  }
  // error_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_message), &(rhs->error_message)))
  {
    return false;
  }
  // calibration_needed
  if (lhs->calibration_needed != rhs->calibration_needed) {
    return false;
  }
  // calibration_in_progress
  if (lhs->calibration_in_progress != rhs->calibration_in_progress) {
    return false;
  }
  // motor_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->motor_names), &(rhs->motor_names)))
  {
    return false;
  }
  // motor_types
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->motor_types), &(rhs->motor_types)))
  {
    return false;
  }
  // temperatures
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->temperatures), &(rhs->temperatures)))
  {
    return false;
  }
  // voltages
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->voltages), &(rhs->voltages)))
  {
    return false;
  }
  // hardware_errors
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->hardware_errors), &(rhs->hardware_errors)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__HardwareStatus__copy(
  const niryo_one_msgs__msg__HardwareStatus * input,
  niryo_one_msgs__msg__HardwareStatus * output)
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
  // rpi_temperature
  output->rpi_temperature = input->rpi_temperature;
  // hardware_version
  output->hardware_version = input->hardware_version;
  // connection_up
  output->connection_up = input->connection_up;
  // error_message
  if (!rosidl_runtime_c__String__copy(
      &(input->error_message), &(output->error_message)))
  {
    return false;
  }
  // calibration_needed
  output->calibration_needed = input->calibration_needed;
  // calibration_in_progress
  output->calibration_in_progress = input->calibration_in_progress;
  // motor_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->motor_names), &(output->motor_names)))
  {
    return false;
  }
  // motor_types
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->motor_types), &(output->motor_types)))
  {
    return false;
  }
  // temperatures
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->temperatures), &(output->temperatures)))
  {
    return false;
  }
  // voltages
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->voltages), &(output->voltages)))
  {
    return false;
  }
  // hardware_errors
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->hardware_errors), &(output->hardware_errors)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__msg__HardwareStatus *
niryo_one_msgs__msg__HardwareStatus__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__HardwareStatus * msg = (niryo_one_msgs__msg__HardwareStatus *)allocator.allocate(sizeof(niryo_one_msgs__msg__HardwareStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__HardwareStatus));
  bool success = niryo_one_msgs__msg__HardwareStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__HardwareStatus__destroy(niryo_one_msgs__msg__HardwareStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__HardwareStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__HardwareStatus__Sequence__init(niryo_one_msgs__msg__HardwareStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__HardwareStatus * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__HardwareStatus *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__HardwareStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__HardwareStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__HardwareStatus__fini(&data[i - 1]);
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
niryo_one_msgs__msg__HardwareStatus__Sequence__fini(niryo_one_msgs__msg__HardwareStatus__Sequence * array)
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
      niryo_one_msgs__msg__HardwareStatus__fini(&array->data[i]);
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

niryo_one_msgs__msg__HardwareStatus__Sequence *
niryo_one_msgs__msg__HardwareStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__HardwareStatus__Sequence * array = (niryo_one_msgs__msg__HardwareStatus__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__HardwareStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__HardwareStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__HardwareStatus__Sequence__destroy(niryo_one_msgs__msg__HardwareStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__HardwareStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__HardwareStatus__Sequence__are_equal(const niryo_one_msgs__msg__HardwareStatus__Sequence * lhs, const niryo_one_msgs__msg__HardwareStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__HardwareStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__HardwareStatus__Sequence__copy(
  const niryo_one_msgs__msg__HardwareStatus__Sequence * input,
  niryo_one_msgs__msg__HardwareStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__HardwareStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__HardwareStatus * data =
      (niryo_one_msgs__msg__HardwareStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__HardwareStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__HardwareStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__HardwareStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
