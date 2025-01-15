// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:srv/GetWorkspaceRobotPoses.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_workspace_robot_poses.h"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_ROBOT_POSES__STRUCT_H_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_ROBOT_POSES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'workspace'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetWorkspaceRobotPoses in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetWorkspaceRobotPoses_Request
{
  rosidl_runtime_c__String workspace;
} niryo_one_msgs__srv__GetWorkspaceRobotPoses_Request;

// Struct for a sequence of niryo_one_msgs__srv__GetWorkspaceRobotPoses_Request.
typedef struct niryo_one_msgs__srv__GetWorkspaceRobotPoses_Request__Sequence
{
  niryo_one_msgs__srv__GetWorkspaceRobotPoses_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetWorkspaceRobotPoses_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'pose_origin'
// Member 'pose_1'
// Member 'pose_2'
// Member 'pose_3'
#include "niryo_one_msgs/msg/detail/robot_state__struct.h"

/// Struct defined in srv/GetWorkspaceRobotPoses in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetWorkspaceRobotPoses_Response
{
  int32_t status;
  rosidl_runtime_c__String message;
  niryo_one_msgs__msg__RobotState pose_origin;
  niryo_one_msgs__msg__RobotState pose_1;
  niryo_one_msgs__msg__RobotState pose_2;
  niryo_one_msgs__msg__RobotState pose_3;
} niryo_one_msgs__srv__GetWorkspaceRobotPoses_Response;

// Struct for a sequence of niryo_one_msgs__srv__GetWorkspaceRobotPoses_Response.
typedef struct niryo_one_msgs__srv__GetWorkspaceRobotPoses_Response__Sequence
{
  niryo_one_msgs__srv__GetWorkspaceRobotPoses_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetWorkspaceRobotPoses_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetWorkspaceRobotPoses in the package niryo_one_msgs.
typedef struct niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__srv__GetWorkspaceRobotPoses_Request__Sequence request;
  niryo_one_msgs__srv__GetWorkspaceRobotPoses_Response__Sequence response;
} niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event;

// Struct for a sequence of niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event.
typedef struct niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event__Sequence
{
  niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__srv__GetWorkspaceRobotPoses_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_ROBOT_POSES__STRUCT_H_
