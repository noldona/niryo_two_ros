// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/software_version__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `rpi_image_version`
// Member `ros_niryo_one_version`
// Member `motor_names`
// Member `stepper_firmware_versions`
#include "rosidl_runtime_c/string_functions.h"

bool
niryo_one_msgs__msg__SoftwareVersion__init(niryo_one_msgs__msg__SoftwareVersion * msg)
{
  if (!msg) {
    return false;
  }
  // rpi_image_version
  if (!rosidl_runtime_c__String__init(&msg->rpi_image_version)) {
    niryo_one_msgs__msg__SoftwareVersion__fini(msg);
    return false;
  }
  // ros_niryo_one_version
  if (!rosidl_runtime_c__String__init(&msg->ros_niryo_one_version)) {
    niryo_one_msgs__msg__SoftwareVersion__fini(msg);
    return false;
  }
  // motor_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->motor_names, 0)) {
    niryo_one_msgs__msg__SoftwareVersion__fini(msg);
    return false;
  }
  // stepper_firmware_versions
  if (!rosidl_runtime_c__String__Sequence__init(&msg->stepper_firmware_versions, 0)) {
    niryo_one_msgs__msg__SoftwareVersion__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__msg__SoftwareVersion__fini(niryo_one_msgs__msg__SoftwareVersion * msg)
{
  if (!msg) {
    return;
  }
  // rpi_image_version
  rosidl_runtime_c__String__fini(&msg->rpi_image_version);
  // ros_niryo_one_version
  rosidl_runtime_c__String__fini(&msg->ros_niryo_one_version);
  // motor_names
  rosidl_runtime_c__String__Sequence__fini(&msg->motor_names);
  // stepper_firmware_versions
  rosidl_runtime_c__String__Sequence__fini(&msg->stepper_firmware_versions);
}

bool
niryo_one_msgs__msg__SoftwareVersion__are_equal(const niryo_one_msgs__msg__SoftwareVersion * lhs, const niryo_one_msgs__msg__SoftwareVersion * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // rpi_image_version
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->rpi_image_version), &(rhs->rpi_image_version)))
  {
    return false;
  }
  // ros_niryo_one_version
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->ros_niryo_one_version), &(rhs->ros_niryo_one_version)))
  {
    return false;
  }
  // motor_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->motor_names), &(rhs->motor_names)))
  {
    return false;
  }
  // stepper_firmware_versions
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->stepper_firmware_versions), &(rhs->stepper_firmware_versions)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__msg__SoftwareVersion__copy(
  const niryo_one_msgs__msg__SoftwareVersion * input,
  niryo_one_msgs__msg__SoftwareVersion * output)
{
  if (!input || !output) {
    return false;
  }
  // rpi_image_version
  if (!rosidl_runtime_c__String__copy(
      &(input->rpi_image_version), &(output->rpi_image_version)))
  {
    return false;
  }
  // ros_niryo_one_version
  if (!rosidl_runtime_c__String__copy(
      &(input->ros_niryo_one_version), &(output->ros_niryo_one_version)))
  {
    return false;
  }
  // motor_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->motor_names), &(output->motor_names)))
  {
    return false;
  }
  // stepper_firmware_versions
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->stepper_firmware_versions), &(output->stepper_firmware_versions)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__msg__SoftwareVersion *
niryo_one_msgs__msg__SoftwareVersion__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__SoftwareVersion * msg = (niryo_one_msgs__msg__SoftwareVersion *)allocator.allocate(sizeof(niryo_one_msgs__msg__SoftwareVersion), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__msg__SoftwareVersion));
  bool success = niryo_one_msgs__msg__SoftwareVersion__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__msg__SoftwareVersion__destroy(niryo_one_msgs__msg__SoftwareVersion * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__msg__SoftwareVersion__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__msg__SoftwareVersion__Sequence__init(niryo_one_msgs__msg__SoftwareVersion__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__SoftwareVersion * data = NULL;

  if (size) {
    data = (niryo_one_msgs__msg__SoftwareVersion *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__msg__SoftwareVersion), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__msg__SoftwareVersion__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__msg__SoftwareVersion__fini(&data[i - 1]);
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
niryo_one_msgs__msg__SoftwareVersion__Sequence__fini(niryo_one_msgs__msg__SoftwareVersion__Sequence * array)
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
      niryo_one_msgs__msg__SoftwareVersion__fini(&array->data[i]);
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

niryo_one_msgs__msg__SoftwareVersion__Sequence *
niryo_one_msgs__msg__SoftwareVersion__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__msg__SoftwareVersion__Sequence * array = (niryo_one_msgs__msg__SoftwareVersion__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__msg__SoftwareVersion__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__msg__SoftwareVersion__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__msg__SoftwareVersion__Sequence__destroy(niryo_one_msgs__msg__SoftwareVersion__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__msg__SoftwareVersion__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__msg__SoftwareVersion__Sequence__are_equal(const niryo_one_msgs__msg__SoftwareVersion__Sequence * lhs, const niryo_one_msgs__msg__SoftwareVersion__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__msg__SoftwareVersion__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__msg__SoftwareVersion__Sequence__copy(
  const niryo_one_msgs__msg__SoftwareVersion__Sequence * input,
  niryo_one_msgs__msg__SoftwareVersion__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__msg__SoftwareVersion);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__msg__SoftwareVersion * data =
      (niryo_one_msgs__msg__SoftwareVersion *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__msg__SoftwareVersion__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__msg__SoftwareVersion__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__msg__SoftwareVersion__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
