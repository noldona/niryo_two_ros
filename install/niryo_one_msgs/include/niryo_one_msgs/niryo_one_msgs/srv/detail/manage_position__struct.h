// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/ManagePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/manage_position.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'position_name'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "niryo_one_msgs/msg/detail/position__struct.h"

/// Struct defined in srv/ManagePosition in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ManagePosition_Request
{
  int32_t cmd_type;
  rosidl_runtime_c__String position_name;
  niryo_one_msgs__msg__Position position;
} niryo_one_msgs__srv__ManagePosition_Request;

// Struct for a sequence of niryo_one_msgs__srv__ManagePosition_Request.
typedef struct niryo_one_msgs__srv__ManagePosition_Request__Sequence
{
  niryo_one_msgs__srv__ManagePosition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ManagePosition_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'position'
// already included above
// #include "niryo_one_msgs/msg/detail/position__struct.h"

/// Struct defined in srv/ManagePosition in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ManagePosition_Response
{
  int32_t status;
  rosidl_runtime_c__String message;
  niryo_one_msgs__msg__Position position;
} niryo_one_msgs__srv__ManagePosition_Response;

// Struct for a sequence of niryo_one_msgs__srv__ManagePosition_Response.
typedef struct niryo_one_msgs__srv__ManagePosition_Response__Sequence
{
  niryo_one_msgs__srv__ManagePosition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ManagePosition_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__ManagePosition_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__ManagePosition_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ManagePosition in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__ManagePosition_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__ManagePosition_Request__Sequence request;
  niryo_one_msgs__srv__ManagePosition_Response__Sequence response;
} niryo_one_msgs__srv__ManagePosition_Event;

// Struct for a sequence of niryo_one_msgs__srv__ManagePosition_Event.
typedef struct niryo_one_msgs__srv__ManagePosition_Event__Sequence
{
  niryo_one_msgs__srv__ManagePosition_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__ManagePosition_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__STRUCT_H_
