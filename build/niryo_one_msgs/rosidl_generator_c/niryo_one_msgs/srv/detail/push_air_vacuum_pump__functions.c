// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from niryo_one_msgs:srv/PushAirVacuumPump.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/srv/detail/push_air_vacuum_pump__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
niryo_one_msgs__srv__PushAirVacuumPump_Request__init(niryo_one_msgs__srv__PushAirVacuumPump_Request * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // push_air_position
  return true;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Request__fini(niryo_one_msgs__srv__PushAirVacuumPump_Request * msg)
{
  if (!msg) {
    return;
  }
  // id
  // push_air_position
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Request__are_equal(const niryo_one_msgs__srv__PushAirVacuumPump_Request * lhs, const niryo_one_msgs__srv__PushAirVacuumPump_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // push_air_position
  if (lhs->push_air_position != rhs->push_air_position) {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Request__copy(
  const niryo_one_msgs__srv__PushAirVacuumPump_Request * input,
  niryo_one_msgs__srv__PushAirVacuumPump_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // push_air_position
  output->push_air_position = input->push_air_position;
  return true;
}

niryo_one_msgs__srv__PushAirVacuumPump_Request *
niryo_one_msgs__srv__PushAirVacuumPump_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Request * msg = (niryo_one_msgs__srv__PushAirVacuumPump_Request *)allocator.allocate(sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Request));
  bool success = niryo_one_msgs__srv__PushAirVacuumPump_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Request__destroy(niryo_one_msgs__srv__PushAirVacuumPump_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__srv__PushAirVacuumPump_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__init(niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Request * data = NULL;

  if (size) {
    data = (niryo_one_msgs__srv__PushAirVacuumPump_Request *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__srv__PushAirVacuumPump_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__srv__PushAirVacuumPump_Request__fini(&data[i - 1]);
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
niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__fini(niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * array)
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
      niryo_one_msgs__srv__PushAirVacuumPump_Request__fini(&array->data[i]);
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

niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence *
niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * array = (niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__destroy(niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__are_equal(const niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * lhs, const niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__srv__PushAirVacuumPump_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__copy(
  const niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * input,
  niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__srv__PushAirVacuumPump_Request * data =
      (niryo_one_msgs__srv__PushAirVacuumPump_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__srv__PushAirVacuumPump_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__srv__PushAirVacuumPump_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__srv__PushAirVacuumPump_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
niryo_one_msgs__srv__PushAirVacuumPump_Response__init(niryo_one_msgs__srv__PushAirVacuumPump_Response * msg)
{
  if (!msg) {
    return false;
  }
  // state
  return true;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Response__fini(niryo_one_msgs__srv__PushAirVacuumPump_Response * msg)
{
  if (!msg) {
    return;
  }
  // state
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Response__are_equal(const niryo_one_msgs__srv__PushAirVacuumPump_Response * lhs, const niryo_one_msgs__srv__PushAirVacuumPump_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Response__copy(
  const niryo_one_msgs__srv__PushAirVacuumPump_Response * input,
  niryo_one_msgs__srv__PushAirVacuumPump_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  return true;
}

niryo_one_msgs__srv__PushAirVacuumPump_Response *
niryo_one_msgs__srv__PushAirVacuumPump_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Response * msg = (niryo_one_msgs__srv__PushAirVacuumPump_Response *)allocator.allocate(sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Response));
  bool success = niryo_one_msgs__srv__PushAirVacuumPump_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Response__destroy(niryo_one_msgs__srv__PushAirVacuumPump_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__srv__PushAirVacuumPump_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__init(niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Response * data = NULL;

  if (size) {
    data = (niryo_one_msgs__srv__PushAirVacuumPump_Response *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__srv__PushAirVacuumPump_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__srv__PushAirVacuumPump_Response__fini(&data[i - 1]);
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
niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__fini(niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * array)
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
      niryo_one_msgs__srv__PushAirVacuumPump_Response__fini(&array->data[i]);
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

niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence *
niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * array = (niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__destroy(niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__are_equal(const niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * lhs, const niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__srv__PushAirVacuumPump_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__copy(
  const niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * input,
  niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__srv__PushAirVacuumPump_Response * data =
      (niryo_one_msgs__srv__PushAirVacuumPump_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__srv__PushAirVacuumPump_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__srv__PushAirVacuumPump_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__srv__PushAirVacuumPump_Response__copy(
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
// #include "niryo_one_msgs/srv/detail/push_air_vacuum_pump__functions.h"

bool
niryo_one_msgs__srv__PushAirVacuumPump_Event__init(niryo_one_msgs__srv__PushAirVacuumPump_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(msg);
    return false;
  }
  // request
  if (!niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__init(&msg->request, 0)) {
    niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(msg);
    return false;
  }
  // response
  if (!niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__init(&msg->response, 0)) {
    niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(msg);
    return false;
  }
  return true;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(niryo_one_msgs__srv__PushAirVacuumPump_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__fini(&msg->request);
  // response
  niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__fini(&msg->response);
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Event__are_equal(const niryo_one_msgs__srv__PushAirVacuumPump_Event * lhs, const niryo_one_msgs__srv__PushAirVacuumPump_Event * rhs)
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
  if (!niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Event__copy(
  const niryo_one_msgs__srv__PushAirVacuumPump_Event * input,
  niryo_one_msgs__srv__PushAirVacuumPump_Event * output)
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
  if (!niryo_one_msgs__srv__PushAirVacuumPump_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!niryo_one_msgs__srv__PushAirVacuumPump_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

niryo_one_msgs__srv__PushAirVacuumPump_Event *
niryo_one_msgs__srv__PushAirVacuumPump_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Event * msg = (niryo_one_msgs__srv__PushAirVacuumPump_Event *)allocator.allocate(sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Event));
  bool success = niryo_one_msgs__srv__PushAirVacuumPump_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Event__destroy(niryo_one_msgs__srv__PushAirVacuumPump_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__init(niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Event * data = NULL;

  if (size) {
    data = (niryo_one_msgs__srv__PushAirVacuumPump_Event *)allocator.zero_allocate(size, sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = niryo_one_msgs__srv__PushAirVacuumPump_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(&data[i - 1]);
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
niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__fini(niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * array)
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
      niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(&array->data[i]);
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

niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence *
niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * array = (niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence *)allocator.allocate(sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__destroy(niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__are_equal(const niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * lhs, const niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!niryo_one_msgs__srv__PushAirVacuumPump_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence__copy(
  const niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * input,
  niryo_one_msgs__srv__PushAirVacuumPump_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(niryo_one_msgs__srv__PushAirVacuumPump_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    niryo_one_msgs__srv__PushAirVacuumPump_Event * data =
      (niryo_one_msgs__srv__PushAirVacuumPump_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!niryo_one_msgs__srv__PushAirVacuumPump_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          niryo_one_msgs__srv__PushAirVacuumPump_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!niryo_one_msgs__srv__PushAirVacuumPump_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
