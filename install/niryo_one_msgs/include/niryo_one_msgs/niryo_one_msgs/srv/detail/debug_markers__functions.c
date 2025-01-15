// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:srv/DebugMarkers.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/srv/detail/debug_markers__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
niryo_one_msgs__srv__DebugMarkers_Request__init(niryo_one_msgs__srv__DebugMarkers_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
niryo_one_msgs__srv__DebugMarkers_Request__fini(niryo_one_msgs__srv__DebugMarkers_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
niryo_one_msgs__srv__DebugMarkers_Request__are_equal(const niryo_one_msgs__srv__DebugMarkers_Request * lhs, const niryo_one_msgs__srv__DebugMarkers_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__srv__DebugMarkers_Request__copy(
  const niryo_one_msgs__srv__DebugMarkers_Request * input,
  niryo_one_msgs__srv__DebugMarkers_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

niryo_one_msgs__srv__DebugMarkers_Request *
niryo_one_msgs__srv__DebugMarkers_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Request * msg = (niryo_one_msgs__srv__DebugMarkers_Request *)allocator.allocate(sizeof(niryo_one_msgs__srv__DebugMarkers_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__srv__DebugMarkers_Request));
  bool success = niryo_one_msgs__srv__DebugMarkers_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__srv__DebugMarkers_Request__destroy(niryo_one_msgs__srv__DebugMarkers_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__srv__DebugMarkers_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__srv__DebugMarkers_Request__Sequence__init(niryo_one_msgs__srv__DebugMarkers_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Request * data = NULL;

  if (size) {
    data = (niryo_one_msgs__srv__DebugMarkers_Request *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__srv__DebugMarkers_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__srv__DebugMarkers_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__srv__DebugMarkers_Request__fini(&data[i - 1]);
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
niryo_one_msgs__srv__DebugMarkers_Request__Sequence__fini(niryo_one_msgs__srv__DebugMarkers_Request__Sequence * array)
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
      niryo_one_msgs__srv__DebugMarkers_Request__fini(&array->data[i]);
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

niryo_one_msgs__srv__DebugMarkers_Request__Sequence *
niryo_one_msgs__srv__DebugMarkers_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Request__Sequence * array = (niryo_one_msgs__srv__DebugMarkers_Request__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__srv__DebugMarkers_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__srv__DebugMarkers_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__srv__DebugMarkers_Request__Sequence__destroy(niryo_one_msgs__srv__DebugMarkers_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__srv__DebugMarkers_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__srv__DebugMarkers_Request__Sequence__are_equal(const niryo_one_msgs__srv__DebugMarkers_Request__Sequence * lhs, const niryo_one_msgs__srv__DebugMarkers_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__srv__DebugMarkers_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__srv__DebugMarkers_Request__Sequence__copy(
  const niryo_one_msgs__srv__DebugMarkers_Request__Sequence * input,
  niryo_one_msgs__srv__DebugMarkers_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__srv__DebugMarkers_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__srv__DebugMarkers_Request * data =
      (niryo_one_msgs__srv__DebugMarkers_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__srv__DebugMarkers_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__srv__DebugMarkers_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__srv__DebugMarkers_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `img`
#include "sensor_msgs/msg/detail/compressed_image__functions.h"

bool
niryo_one_msgs__srv__DebugMarkers_Response__init(niryo_one_msgs__srv__DebugMarkers_Response * msg)
{
  if (!msg) {
    return false;
  }
  // markers_detected
  // img
  if (!sensor_msgs__msg__CompressedImage__init(&msg->img)) {
    niryo_one_msgs__srv__DebugMarkers_Response__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__srv__DebugMarkers_Response__fini(niryo_one_msgs__srv__DebugMarkers_Response * msg)
{
  if (!msg) {
    return;
  }
  // markers_detected
  // img
  sensor_msgs__msg__CompressedImage__fini(&msg->img);
}

bool
niryo_one_msgs__srv__DebugMarkers_Response__are_equal(const niryo_one_msgs__srv__DebugMarkers_Response * lhs, const niryo_one_msgs__srv__DebugMarkers_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // markers_detected
  if (lhs->markers_detected != rhs->markers_detected) {
    return false;
  }
  // img
  if (!sensor_msgs__msg__CompressedImage__are_equal(
      &(lhs->img), &(rhs->img)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__srv__DebugMarkers_Response__copy(
  const niryo_one_msgs__srv__DebugMarkers_Response * input,
  niryo_one_msgs__srv__DebugMarkers_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // markers_detected
  output->markers_detected = input->markers_detected;
  // img
  if (!sensor_msgs__msg__CompressedImage__copy(
      &(input->img), &(output->img)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__srv__DebugMarkers_Response *
niryo_one_msgs__srv__DebugMarkers_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Response * msg = (niryo_one_msgs__srv__DebugMarkers_Response *)allocator.allocate(sizeof(niryo_one_msgs__srv__DebugMarkers_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__srv__DebugMarkers_Response));
  bool success = niryo_one_msgs__srv__DebugMarkers_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__srv__DebugMarkers_Response__destroy(niryo_one_msgs__srv__DebugMarkers_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__srv__DebugMarkers_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__srv__DebugMarkers_Response__Sequence__init(niryo_one_msgs__srv__DebugMarkers_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Response * data = NULL;

  if (size) {
    data = (niryo_one_msgs__srv__DebugMarkers_Response *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__srv__DebugMarkers_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__srv__DebugMarkers_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__srv__DebugMarkers_Response__fini(&data[i - 1]);
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
niryo_one_msgs__srv__DebugMarkers_Response__Sequence__fini(niryo_one_msgs__srv__DebugMarkers_Response__Sequence * array)
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
      niryo_one_msgs__srv__DebugMarkers_Response__fini(&array->data[i]);
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

niryo_one_msgs__srv__DebugMarkers_Response__Sequence *
niryo_one_msgs__srv__DebugMarkers_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Response__Sequence * array = (niryo_one_msgs__srv__DebugMarkers_Response__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__srv__DebugMarkers_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__srv__DebugMarkers_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__srv__DebugMarkers_Response__Sequence__destroy(niryo_one_msgs__srv__DebugMarkers_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__srv__DebugMarkers_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__srv__DebugMarkers_Response__Sequence__are_equal(const niryo_one_msgs__srv__DebugMarkers_Response__Sequence * lhs, const niryo_one_msgs__srv__DebugMarkers_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__srv__DebugMarkers_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__srv__DebugMarkers_Response__Sequence__copy(
  const niryo_one_msgs__srv__DebugMarkers_Response__Sequence * input,
  niryo_one_msgs__srv__DebugMarkers_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__srv__DebugMarkers_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__srv__DebugMarkers_Response * data =
      (niryo_one_msgs__srv__DebugMarkers_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__srv__DebugMarkers_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__srv__DebugMarkers_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__srv__DebugMarkers_Response__copy(
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
// #include "niryo_one_msgs/srv/detail/debug_markers__functions.h"

bool
niryo_one_msgs__srv__DebugMarkers_Event__init(niryo_one_msgs__srv__DebugMarkers_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    niryo_one_msgs__srv__DebugMarkers_Event__fini(msg);
    return false;
  }
  // request
  if (!niryo_one_msgs__srv__DebugMarkers_Request__Sequence__init(&msg->request, 0)) {
    niryo_one_msgs__srv__DebugMarkers_Event__fini(msg);
    return false;
  }
  // response
  if (!niryo_one_msgs__srv__DebugMarkers_Response__Sequence__init(&msg->response, 0)) {
    niryo_one_msgs__srv__DebugMarkers_Event__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__srv__DebugMarkers_Event__fini(niryo_one_msgs__srv__DebugMarkers_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  niryo_one_msgs__srv__DebugMarkers_Request__Sequence__fini(&msg->request);
  // response
  niryo_one_msgs__srv__DebugMarkers_Response__Sequence__fini(&msg->response);
}

bool
niryo_one_msgs__srv__DebugMarkers_Event__are_equal(const niryo_one_msgs__srv__DebugMarkers_Event * lhs, const niryo_one_msgs__srv__DebugMarkers_Event * rhs)
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
  if (!niryo_one_msgs__srv__DebugMarkers_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__srv__DebugMarkers_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__srv__DebugMarkers_Event__copy(
  const niryo_one_msgs__srv__DebugMarkers_Event * input,
  niryo_one_msgs__srv__DebugMarkers_Event * output)
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
  if (!niryo_one_msgs__srv__DebugMarkers_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__srv__DebugMarkers_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__srv__DebugMarkers_Event *
niryo_one_msgs__srv__DebugMarkers_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Event * msg = (niryo_one_msgs__srv__DebugMarkers_Event *)allocator.allocate(sizeof(niryo_one_msgs__srv__DebugMarkers_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__srv__DebugMarkers_Event));
  bool success = niryo_one_msgs__srv__DebugMarkers_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__srv__DebugMarkers_Event__destroy(niryo_one_msgs__srv__DebugMarkers_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__srv__DebugMarkers_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__srv__DebugMarkers_Event__Sequence__init(niryo_one_msgs__srv__DebugMarkers_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Event * data = NULL;

  if (size) {
    data = (niryo_one_msgs__srv__DebugMarkers_Event *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__srv__DebugMarkers_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__srv__DebugMarkers_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__srv__DebugMarkers_Event__fini(&data[i - 1]);
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
niryo_one_msgs__srv__DebugMarkers_Event__Sequence__fini(niryo_one_msgs__srv__DebugMarkers_Event__Sequence * array)
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
      niryo_one_msgs__srv__DebugMarkers_Event__fini(&array->data[i]);
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

niryo_one_msgs__srv__DebugMarkers_Event__Sequence *
niryo_one_msgs__srv__DebugMarkers_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__DebugMarkers_Event__Sequence * array = (niryo_one_msgs__srv__DebugMarkers_Event__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__srv__DebugMarkers_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__srv__DebugMarkers_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__srv__DebugMarkers_Event__Sequence__destroy(niryo_one_msgs__srv__DebugMarkers_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__srv__DebugMarkers_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__srv__DebugMarkers_Event__Sequence__are_equal(const niryo_one_msgs__srv__DebugMarkers_Event__Sequence * lhs, const niryo_one_msgs__srv__DebugMarkers_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__srv__DebugMarkers_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__srv__DebugMarkers_Event__Sequence__copy(
  const niryo_one_msgs__srv__DebugMarkers_Event__Sequence * input,
  niryo_one_msgs__srv__DebugMarkers_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__srv__DebugMarkers_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__srv__DebugMarkers_Event * data =
      (niryo_one_msgs__srv__DebugMarkers_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__srv__DebugMarkers_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__srv__DebugMarkers_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__srv__DebugMarkers_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
