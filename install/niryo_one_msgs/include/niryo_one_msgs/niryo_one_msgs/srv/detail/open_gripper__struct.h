// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/OpenGripper.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/open_gripper.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__OPEN_GRIPPER__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__OPEN_GRIPPER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/OpenGripper in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__OpenGripper_Request
{
  uint8_t id;
  int16_t open_position;
  int16_t open_speed;
  int16_t open_hold_torque;
} niryo_one_msgs__srv__OpenGripper_Request;

// Struct for a sequence of niryo_one_msgs__srv__OpenGripper_Request.
typedef struct niryo_one_msgs__srv__OpenGripper_Request__Sequence
{
  niryo_one_msgs__srv__OpenGripper_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__OpenGripper_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/OpenGripper in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__OpenGripper_Response
{
  uint8_t state;
} niryo_one_msgs__srv__OpenGripper_Response;

// Struct for a sequence of niryo_one_msgs__srv__OpenGripper_Response.
typedef struct niryo_one_msgs__srv__OpenGripper_Response__Sequence
{
  niryo_one_msgs__srv__OpenGripper_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__OpenGripper_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__OpenGripper_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__OpenGripper_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/OpenGripper in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__OpenGripper_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__OpenGripper_Request__Sequence request;
  niryo_one_msgs__srv__OpenGripper_Response__Sequence response;
} niryo_one_msgs__srv__OpenGripper_Event;

// Struct for a sequence of niryo_one_msgs__srv__OpenGripper_Event.
typedef struct niryo_one_msgs__srv__OpenGripper_Event__Sequence
{
  niryo_one_msgs__srv__OpenGripper_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__OpenGripper_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__OPEN_GRIPPER__STRUCT_H_
