// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from niryo_one_msgs:action/Sequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/action/sequence.h"


#ifndef NIRYO_ONE_MSGS__ACTION__DETAIL__SEQUENCE__STRUCT_H_
#define NIRYO_ONE_MSGS__ACTION__DETAIL__SEQUENCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sequence'
#include "niryo_one_msgs/msg/detail/sequence__struct.h"

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_Goal
{
  int32_t cmd_type;
  int32_t sequence_id;
  niryo_one_msgs__msg__Sequence sequence;
} niryo_one_msgs__action__Sequence_Goal;

// Struct for a sequence of niryo_one_msgs__action__Sequence_Goal.
typedef struct niryo_one_msgs__action__Sequence_Goal__Sequence
{
  niryo_one_msgs__action__Sequence_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_Result
{
  int32_t status;
  rosidl_runtime_c__String message;
} niryo_one_msgs__action__Sequence_Result;

// Struct for a sequence of niryo_one_msgs__action__Sequence_Result.
typedef struct niryo_one_msgs__action__Sequence_Result__Sequence
{
  niryo_one_msgs__action__Sequence_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_Feedback
{
  uint8_t structure_needs_at_least_one_member;
} niryo_one_msgs__action__Sequence_Feedback;

// Struct for a sequence of niryo_one_msgs__action__Sequence_Feedback.
typedef struct niryo_one_msgs__action__Sequence_Feedback__Sequence
{
  niryo_one_msgs__action__Sequence_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "niryo_one_msgs/action/detail/sequence__struct.h"

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  niryo_one_msgs__action__Sequence_Goal goal;
} niryo_one_msgs__action__Sequence_SendGoal_Request;

// Struct for a sequence of niryo_one_msgs__action__Sequence_SendGoal_Request.
typedef struct niryo_one_msgs__action__Sequence_SendGoal_Request__Sequence
{
  niryo_one_msgs__action__Sequence_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} niryo_one_msgs__action__Sequence_SendGoal_Response;

// Struct for a sequence of niryo_one_msgs__action__Sequence_SendGoal_Response.
typedef struct niryo_one_msgs__action__Sequence_SendGoal_Response__Sequence
{
  niryo_one_msgs__action__Sequence_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__action__Sequence_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__action__Sequence_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__action__Sequence_SendGoal_Request__Sequence request;
  niryo_one_msgs__action__Sequence_SendGoal_Response__Sequence response;
} niryo_one_msgs__action__Sequence_SendGoal_Event;

// Struct for a sequence of niryo_one_msgs__action__Sequence_SendGoal_Event.
typedef struct niryo_one_msgs__action__Sequence_SendGoal_Event__Sequence
{
  niryo_one_msgs__action__Sequence_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} niryo_one_msgs__action__Sequence_GetResult_Request;

// Struct for a sequence of niryo_one_msgs__action__Sequence_GetResult_Request.
typedef struct niryo_one_msgs__action__Sequence_GetResult_Request__Sequence
{
  niryo_one_msgs__action__Sequence_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "niryo_one_msgs/action/detail/sequence__struct.h"

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_GetResult_Response
{
  int8_t status;
  niryo_one_msgs__action__Sequence_Result result;
} niryo_one_msgs__action__Sequence_GetResult_Response;

// Struct for a sequence of niryo_one_msgs__action__Sequence_GetResult_Response.
typedef struct niryo_one_msgs__action__Sequence_GetResult_Response__Sequence
{
  niryo_one_msgs__action__Sequence_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  niryo_one_msgs__action__Sequence_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  niryo_one_msgs__action__Sequence_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  niryo_one_msgs__action__Sequence_GetResult_Request__Sequence request;
  niryo_one_msgs__action__Sequence_GetResult_Response__Sequence response;
} niryo_one_msgs__action__Sequence_GetResult_Event;

// Struct for a sequence of niryo_one_msgs__action__Sequence_GetResult_Event.
typedef struct niryo_one_msgs__action__Sequence_GetResult_Event__Sequence
{
  niryo_one_msgs__action__Sequence_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "niryo_one_msgs/action/detail/sequence__struct.h"

/// Struct defined in action/Sequence in the package niryo_one_msgs.
typedef struct niryo_one_msgs__action__Sequence_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  niryo_one_msgs__action__Sequence_Feedback feedback;
} niryo_one_msgs__action__Sequence_FeedbackMessage;

// Struct for a sequence of niryo_one_msgs__action__Sequence_FeedbackMessage.
typedef struct niryo_one_msgs__action__Sequence_FeedbackMessage__Sequence
{
  niryo_one_msgs__action__Sequence_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} niryo_one_msgs__action__Sequence_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIRYO_ONE_MSGS__ACTION__DETAIL__SEQUENCE__STRUCT_H_
