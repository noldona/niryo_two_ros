// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/ControlConveyor.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/control_conveyor.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__CONTROL_CONVEYOR__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__CONTROL_CONVEYOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ControlConveyor in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ControlConveyor_Request
{
  uint8_t id;
  bool control_on;
  int16_t speed;
  int8_t direction;
} niryo_one_msgs__srv__ControlConveyor_Request;

// Struct for a sequence of niryo_one_msgs__srv__ControlConveyor_Request.
typedef struct niryo_one_msgs__srv__ControlConveyor_Request__Sequence
{
  niryo_one_msgs__srv__ControlConveyor_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ControlConveyor_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ControlConveyor in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ControlConveyor_Response
{
  uint8_t status;
  rosidl_runtime_c__String message;
} niryo_one_msgs__srv__ControlConveyor_Response;

// Struct for a sequence of niryo_one_msgs__srv__ControlConveyor_Response.
typedef struct niryo_one_msgs__srv__ControlConveyor_Response__Sequence
{
  niryo_one_msgs__srv__ControlConveyor_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ControlConveyor_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__ControlConveyor_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__ControlConveyor_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ControlConveyor in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ControlConveyor_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__ControlConveyor_Request__Sequence request;
  niryo_one_msgs__srv__ControlConveyor_Response__Sequence response;
} niryo_one_msgs__srv__ControlConveyor_Event;

// Struct for a sequence of niryo_one_msgs__srv__ControlConveyor_Event.
typedef struct niryo_one_msgs__srv__ControlConveyor_Event__Sequence
{
  niryo_one_msgs__srv__ControlConveyor_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ControlConveyor_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__CONTROL_CONVEYOR__STRUCT_H_
