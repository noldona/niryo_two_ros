// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/GetTargetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_target_pose.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'GRIP_AUTO'.
static const char * const niryo_one_msgs__srv__GetTargetPose_Request__GRIP_AUTO = "auto";

// Include directives for member types
// Member 'workspace'
// Member 'grip'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetTargetPose in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetTargetPose_Request
{
  rosidl_runtime_c__String workspace;
  rosidl_runtime_c__String grip;
  /// Used if grip_name = GRIP_AUTO
  int32_t tool_id;
  float height_offset;
  float x_rel;
  float y_rel;
  float yaw_rel;
} niryo_one_msgs__srv__GetTargetPose_Request;

// Struct for a sequence of niryo_one_msgs__srv__GetTargetPose_Request.
typedef struct niryo_one_msgs__srv__GetTargetPose_Request__Sequence
{
  niryo_one_msgs__srv__GetTargetPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetTargetPose_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'target_pose'
#include "niryo_one_msgs/msg/detail/robot_state__struct.h"

/// Struct defined in srv/GetTargetPose in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetTargetPose_Response
{
  int32_t status;
  rosidl_runtime_c__String message;
  niryo_one_msgs__msg__RobotState target_pose;
} niryo_one_msgs__srv__GetTargetPose_Response;

// Struct for a sequence of niryo_one_msgs__srv__GetTargetPose_Response.
typedef struct niryo_one_msgs__srv__GetTargetPose_Response__Sequence
{
  niryo_one_msgs__srv__GetTargetPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetTargetPose_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__GetTargetPose_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__GetTargetPose_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetTargetPose in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetTargetPose_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__GetTargetPose_Request__Sequence request;
  niryo_one_msgs__srv__GetTargetPose_Response__Sequence response;
} niryo_one_msgs__srv__GetTargetPose_Event;

// Struct for a sequence of niryo_one_msgs__srv__GetTargetPose_Event.
typedef struct niryo_one_msgs__srv__GetTargetPose_Event__Sequence
{
  niryo_one_msgs__srv__GetTargetPose_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetTargetPose_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__STRUCT_H_
