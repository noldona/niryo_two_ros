// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:action/RobotMove.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/action/robot_move.h"


#ifndef NIRYO_ONE_MSGS__ACTION__DETAIL__ROBOT_MOVE__STRUCT_H_
#define NIRYO_ONE_MSGS__ACTION__DETAIL__ROBOT_MOVE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cmd'
#include "niryo_one_msgs/msg/detail/robot_move_command__struct.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_Goal
{
  niryo_one_msgs__msg__RobotMoveCommand cmd;
} niryo_one_msgs__action__RobotMove_Goal;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_Goal.
typedef struct niryo_one_msgs__action__RobotMove_Goal__Sequence
{
  niryo_one_msgs__action__RobotMove_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_Result
{
  int32_t status;
  rosidl_runtime_c__String message;
} niryo_one_msgs__action__RobotMove_Result;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_Result.
typedef struct niryo_one_msgs__action__RobotMove_Result__Sequence
{
  niryo_one_msgs__action__RobotMove_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'state'
#include "niryo_one_msgs/msg/detail/robot_state__struct.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_Feedback
{
  niryo_one_msgs__msg__RobotState state;
} niryo_one_msgs__action__RobotMove_Feedback;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_Feedback.
typedef struct niryo_one_msgs__action__RobotMove_Feedback__Sequence
{
  niryo_one_msgs__action__RobotMove_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "niryo_one_msgs/action/detail/robot_move__struct.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  niryo_one_msgs__action__RobotMove_Goal goal;
} niryo_one_msgs__action__RobotMove_SendGoal_Request;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_SendGoal_Request.
typedef struct niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence
{
  niryo_one_msgs__action__RobotMove_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} niryo_one_msgs__action__RobotMove_SendGoal_Response;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_SendGoal_Response.
typedef struct niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence
{
  niryo_one_msgs__action__RobotMove_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__action__RobotMove_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__action__RobotMove_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__action__RobotMove_SendGoal_Request__Sequence request;
  niryo_one_msgs__action__RobotMove_SendGoal_Response__Sequence response;
} niryo_one_msgs__action__RobotMove_SendGoal_Event;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_SendGoal_Event.
typedef struct niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence
{
  niryo_one_msgs__action__RobotMove_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} niryo_one_msgs__action__RobotMove_GetResult_Request;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_GetResult_Request.
typedef struct niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence
{
  niryo_one_msgs__action__RobotMove_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "niryo_one_msgs/action/detail/robot_move__struct.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_GetResult_Response
{
  int8_t status;
  niryo_one_msgs__action__RobotMove_Result result;
} niryo_one_msgs__action__RobotMove_GetResult_Response;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_GetResult_Response.
typedef struct niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence
{
  niryo_one_msgs__action__RobotMove_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__action__RobotMove_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__action__RobotMove_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__action__RobotMove_GetResult_Request__Sequence request;
  niryo_one_msgs__action__RobotMove_GetResult_Response__Sequence response;
} niryo_one_msgs__action__RobotMove_GetResult_Event;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_GetResult_Event.
typedef struct niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence
{
  niryo_one_msgs__action__RobotMove_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "niryo_one_msgs/action/detail/robot_move__struct.h"

/// Struct defined in action/RobotMove in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__RobotMove_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  niryo_one_msgs__action__RobotMove_Feedback feedback;
} niryo_one_msgs__action__RobotMove_FeedbackMessage;

// Struct for a sequence of niryo_one_msgs__action__RobotMove_FeedbackMessage.
typedef struct niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence
{
  niryo_one_msgs__action__RobotMove_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__RobotMove_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__ACTION__DETAIL__ROBOT_MOVE__STRUCT_H_
