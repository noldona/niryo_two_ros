// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/PingDxlTool.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/ping_dxl_tool.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__PING_DXL_TOOL__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__PING_DXL_TOOL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/PingDxlTool in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__PingDxlTool_Request
{
  uint8_t id;
  rosidl_runtime_c__String name;
} niryo_one_msgs__srv__PingDxlTool_Request;

// Struct for a sequence of niryo_one_msgs__srv__PingDxlTool_Request.
typedef struct niryo_one_msgs__srv__PingDxlTool_Request__Sequence
{
  niryo_one_msgs__srv__PingDxlTool_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__PingDxlTool_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/PingDxlTool in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__PingDxlTool_Response
{
  uint8_t state;
} niryo_one_msgs__srv__PingDxlTool_Response;

// Struct for a sequence of niryo_one_msgs__srv__PingDxlTool_Response.
typedef struct niryo_one_msgs__srv__PingDxlTool_Response__Sequence
{
  niryo_one_msgs__srv__PingDxlTool_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__PingDxlTool_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__PingDxlTool_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__PingDxlTool_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/PingDxlTool in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__PingDxlTool_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__PingDxlTool_Request__Sequence request;
  niryo_one_msgs__srv__PingDxlTool_Response__Sequence response;
} niryo_one_msgs__srv__PingDxlTool_Event;

// Struct for a sequence of niryo_one_msgs__srv__PingDxlTool_Event.
typedef struct niryo_one_msgs__srv__PingDxlTool_Event__Sequence
{
  niryo_one_msgs__srv__PingDxlTool_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__PingDxlTool_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__PING_DXL_TOOL__STRUCT_H_
