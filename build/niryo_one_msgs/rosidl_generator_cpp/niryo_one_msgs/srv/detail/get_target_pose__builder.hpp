// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/GetTargetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_target_pose.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/get_target_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetTargetPose_Request_yaw_rel
{
public:
  explicit Init_GetTargetPose_Request_yaw_rel(::niryo_one_msgs::srv::GetTargetPose_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetTargetPose_Request yaw_rel(::niryo_one_msgs::srv::GetTargetPose_Request::_yaw_rel_type arg)
  {
    msg_.yaw_rel = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Request msg_;
};

class Init_GetTargetPose_Request_y_rel
{
public:
  explicit Init_GetTargetPose_Request_y_rel(::niryo_one_msgs::srv::GetTargetPose_Request & msg)
  : msg_(msg)
  {}
  Init_GetTargetPose_Request_yaw_rel y_rel(::niryo_one_msgs::srv::GetTargetPose_Request::_y_rel_type arg)
  {
    msg_.y_rel = std::move(arg);
    return Init_GetTargetPose_Request_yaw_rel(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Request msg_;
};

class Init_GetTargetPose_Request_x_rel
{
public:
  explicit Init_GetTargetPose_Request_x_rel(::niryo_one_msgs::srv::GetTargetPose_Request & msg)
  : msg_(msg)
  {}
  Init_GetTargetPose_Request_y_rel x_rel(::niryo_one_msgs::srv::GetTargetPose_Request::_x_rel_type arg)
  {
    msg_.x_rel = std::move(arg);
    return Init_GetTargetPose_Request_y_rel(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Request msg_;
};

class Init_GetTargetPose_Request_height_offset
{
public:
  explicit Init_GetTargetPose_Request_height_offset(::niryo_one_msgs::srv::GetTargetPose_Request & msg)
  : msg_(msg)
  {}
  Init_GetTargetPose_Request_x_rel height_offset(::niryo_one_msgs::srv::GetTargetPose_Request::_height_offset_type arg)
  {
    msg_.height_offset = std::move(arg);
    return Init_GetTargetPose_Request_x_rel(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Request msg_;
};

class Init_GetTargetPose_Request_tool_id
{
public:
  explicit Init_GetTargetPose_Request_tool_id(::niryo_one_msgs::srv::GetTargetPose_Request & msg)
  : msg_(msg)
  {}
  Init_GetTargetPose_Request_height_offset tool_id(::niryo_one_msgs::srv::GetTargetPose_Request::_tool_id_type arg)
  {
    msg_.tool_id = std::move(arg);
    return Init_GetTargetPose_Request_height_offset(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Request msg_;
};

class Init_GetTargetPose_Request_grip
{
public:
  explicit Init_GetTargetPose_Request_grip(::niryo_one_msgs::srv::GetTargetPose_Request & msg)
  : msg_(msg)
  {}
  Init_GetTargetPose_Request_tool_id grip(::niryo_one_msgs::srv::GetTargetPose_Request::_grip_type arg)
  {
    msg_.grip = std::move(arg);
    return Init_GetTargetPose_Request_tool_id(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Request msg_;
};

class Init_GetTargetPose_Request_workspace
{
public:
  Init_GetTargetPose_Request_workspace()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTargetPose_Request_grip workspace(::niryo_one_msgs::srv::GetTargetPose_Request::_workspace_type arg)
  {
    msg_.workspace = std::move(arg);
    return Init_GetTargetPose_Request_grip(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetTargetPose_Request>()
{
  return niryo_one_msgs::srv::builder::Init_GetTargetPose_Request_workspace();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetTargetPose_Response_target_pose
{
public:
  explicit Init_GetTargetPose_Response_target_pose(::niryo_one_msgs::srv::GetTargetPose_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetTargetPose_Response target_pose(::niryo_one_msgs::srv::GetTargetPose_Response::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Response msg_;
};

class Init_GetTargetPose_Response_message
{
public:
  explicit Init_GetTargetPose_Response_message(::niryo_one_msgs::srv::GetTargetPose_Response & msg)
  : msg_(msg)
  {}
  Init_GetTargetPose_Response_target_pose message(::niryo_one_msgs::srv::GetTargetPose_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetTargetPose_Response_target_pose(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Response msg_;
};

class Init_GetTargetPose_Response_status
{
public:
  Init_GetTargetPose_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTargetPose_Response_message status(::niryo_one_msgs::srv::GetTargetPose_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GetTargetPose_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetTargetPose_Response>()
{
  return niryo_one_msgs::srv::builder::Init_GetTargetPose_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetTargetPose_Event_response
{
public:
  explicit Init_GetTargetPose_Event_response(::niryo_one_msgs::srv::GetTargetPose_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetTargetPose_Event response(::niryo_one_msgs::srv::GetTargetPose_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Event msg_;
};

class Init_GetTargetPose_Event_request
{
public:
  explicit Init_GetTargetPose_Event_request(::niryo_one_msgs::srv::GetTargetPose_Event & msg)
  : msg_(msg)
  {}
  Init_GetTargetPose_Event_response request(::niryo_one_msgs::srv::GetTargetPose_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetTargetPose_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Event msg_;
};

class Init_GetTargetPose_Event_info
{
public:
  Init_GetTargetPose_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetTargetPose_Event_request info(::niryo_one_msgs::srv::GetTargetPose_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetTargetPose_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetTargetPose_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetTargetPose_Event>()
{
  return niryo_one_msgs::srv::builder::Init_GetTargetPose_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__BUILDER_HPP_
