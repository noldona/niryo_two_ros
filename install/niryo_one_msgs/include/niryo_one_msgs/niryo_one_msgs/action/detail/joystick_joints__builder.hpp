// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:action/JoystickJoints.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/action/joystick_joints.hpp"


#ifndef NIRYO_ONE_MSGS__ACTION__DETAIL__JOYSTICK_JOINTS__BUILDER_HPP_
#define NIRYO_ONE_MSGS__ACTION__DETAIL__JOYSTICK_JOINTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/action/detail/joystick_joints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_Goal_duration
{
public:
  explicit Init_JoystickJoints_Goal_duration(::niryo_one_msgs::action::JoystickJoints_Goal & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::action::JoystickJoints_Goal duration(::niryo_one_msgs::action::JoystickJoints_Goal::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_Goal msg_;
};

class Init_JoystickJoints_Goal_joy_values
{
public:
  Init_JoystickJoints_Goal_joy_values()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickJoints_Goal_duration joy_values(::niryo_one_msgs::action::JoystickJoints_Goal::_joy_values_type arg)
  {
    msg_.joy_values = std::move(arg);
    return Init_JoystickJoints_Goal_duration(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_Goal>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_Goal_joy_values();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_Result_has_succeeded
{
public:
  Init_JoystickJoints_Result_has_succeeded()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::action::JoystickJoints_Result has_succeeded(::niryo_one_msgs::action::JoystickJoints_Result::_has_succeeded_type arg)
  {
    msg_.has_succeeded = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_Result>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_Result_has_succeeded();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_Feedback_is_in_joints_limit
{
public:
  Init_JoystickJoints_Feedback_is_in_joints_limit()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::action::JoystickJoints_Feedback is_in_joints_limit(::niryo_one_msgs::action::JoystickJoints_Feedback::_is_in_joints_limit_type arg)
  {
    msg_.is_in_joints_limit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_Feedback>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_Feedback_is_in_joints_limit();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_SendGoal_Request_goal
{
public:
  explicit Init_JoystickJoints_SendGoal_Request_goal(::niryo_one_msgs::action::JoystickJoints_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Request goal(::niryo_one_msgs::action::JoystickJoints_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Request msg_;
};

class Init_JoystickJoints_SendGoal_Request_goal_id
{
public:
  Init_JoystickJoints_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickJoints_SendGoal_Request_goal goal_id(::niryo_one_msgs::action::JoystickJoints_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_JoystickJoints_SendGoal_Request_goal(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_SendGoal_Request>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_SendGoal_Request_goal_id();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_SendGoal_Response_stamp
{
public:
  explicit Init_JoystickJoints_SendGoal_Response_stamp(::niryo_one_msgs::action::JoystickJoints_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Response stamp(::niryo_one_msgs::action::JoystickJoints_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Response msg_;
};

class Init_JoystickJoints_SendGoal_Response_accepted
{
public:
  Init_JoystickJoints_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickJoints_SendGoal_Response_stamp accepted(::niryo_one_msgs::action::JoystickJoints_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_JoystickJoints_SendGoal_Response_stamp(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_SendGoal_Response>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_SendGoal_Response_accepted();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_SendGoal_Event_response
{
public:
  explicit Init_JoystickJoints_SendGoal_Event_response(::niryo_one_msgs::action::JoystickJoints_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Event response(::niryo_one_msgs::action::JoystickJoints_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Event msg_;
};

class Init_JoystickJoints_SendGoal_Event_request
{
public:
  explicit Init_JoystickJoints_SendGoal_Event_request(::niryo_one_msgs::action::JoystickJoints_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_JoystickJoints_SendGoal_Event_response request(::niryo_one_msgs::action::JoystickJoints_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_JoystickJoints_SendGoal_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Event msg_;
};

class Init_JoystickJoints_SendGoal_Event_info
{
public:
  Init_JoystickJoints_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickJoints_SendGoal_Event_request info(::niryo_one_msgs::action::JoystickJoints_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_JoystickJoints_SendGoal_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_SendGoal_Event>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_SendGoal_Event_info();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_GetResult_Request_goal_id
{
public:
  Init_JoystickJoints_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Request goal_id(::niryo_one_msgs::action::JoystickJoints_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_GetResult_Request>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_GetResult_Request_goal_id();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_GetResult_Response_result
{
public:
  explicit Init_JoystickJoints_GetResult_Response_result(::niryo_one_msgs::action::JoystickJoints_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Response result(::niryo_one_msgs::action::JoystickJoints_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Response msg_;
};

class Init_JoystickJoints_GetResult_Response_status
{
public:
  Init_JoystickJoints_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickJoints_GetResult_Response_result status(::niryo_one_msgs::action::JoystickJoints_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_JoystickJoints_GetResult_Response_result(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_GetResult_Response>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_GetResult_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_GetResult_Event_response
{
public:
  explicit Init_JoystickJoints_GetResult_Event_response(::niryo_one_msgs::action::JoystickJoints_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Event response(::niryo_one_msgs::action::JoystickJoints_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Event msg_;
};

class Init_JoystickJoints_GetResult_Event_request
{
public:
  explicit Init_JoystickJoints_GetResult_Event_request(::niryo_one_msgs::action::JoystickJoints_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_JoystickJoints_GetResult_Event_response request(::niryo_one_msgs::action::JoystickJoints_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_JoystickJoints_GetResult_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Event msg_;
};

class Init_JoystickJoints_GetResult_Event_info
{
public:
  Init_JoystickJoints_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickJoints_GetResult_Event_request info(::niryo_one_msgs::action::JoystickJoints_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_JoystickJoints_GetResult_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_GetResult_Event>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_GetResult_Event_info();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace action
{

namespace builder
{

class Init_JoystickJoints_FeedbackMessage_feedback
{
public:
  explicit Init_JoystickJoints_FeedbackMessage_feedback(::niryo_one_msgs::action::JoystickJoints_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::action::JoystickJoints_FeedbackMessage feedback(::niryo_one_msgs::action::JoystickJoints_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_FeedbackMessage msg_;
};

class Init_JoystickJoints_FeedbackMessage_goal_id
{
public:
  Init_JoystickJoints_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickJoints_FeedbackMessage_feedback goal_id(::niryo_one_msgs::action::JoystickJoints_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_JoystickJoints_FeedbackMessage_feedback(msg_);
  }

private:
  ::niryo_one_msgs::action::JoystickJoints_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::action::JoystickJoints_FeedbackMessage>()
{
  return niryo_one_msgs::action::builder::Init_JoystickJoints_FeedbackMessage_goal_id();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__ACTION__DETAIL__JOYSTICK_JOINTS__BUILDER_HPP_
