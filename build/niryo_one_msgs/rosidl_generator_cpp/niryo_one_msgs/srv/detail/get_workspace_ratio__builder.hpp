// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/GetWorkspaceRatio.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_workspace_ratio.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_RATIO__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_RATIO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/get_workspace_ratio__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkspaceRatio_Request_workspace
{
public:
  Init_GetWorkspaceRatio_Request_workspace()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Request workspace(::niryo_one_msgs::srv::GetWorkspaceRatio_Request::_workspace_type arg)
  {
    msg_.workspace = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetWorkspaceRatio_Request>()
{
  return niryo_one_msgs::srv::builder::Init_GetWorkspaceRatio_Request_workspace();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkspaceRatio_Response_ratio
{
public:
  explicit Init_GetWorkspaceRatio_Response_ratio(::niryo_one_msgs::srv::GetWorkspaceRatio_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Response ratio(::niryo_one_msgs::srv::GetWorkspaceRatio_Response::_ratio_type arg)
  {
    msg_.ratio = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Response msg_;
};

class Init_GetWorkspaceRatio_Response_message
{
public:
  explicit Init_GetWorkspaceRatio_Response_message(::niryo_one_msgs::srv::GetWorkspaceRatio_Response & msg)
  : msg_(msg)
  {}
  Init_GetWorkspaceRatio_Response_ratio message(::niryo_one_msgs::srv::GetWorkspaceRatio_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetWorkspaceRatio_Response_ratio(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Response msg_;
};

class Init_GetWorkspaceRatio_Response_status
{
public:
  Init_GetWorkspaceRatio_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWorkspaceRatio_Response_message status(::niryo_one_msgs::srv::GetWorkspaceRatio_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GetWorkspaceRatio_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetWorkspaceRatio_Response>()
{
  return niryo_one_msgs::srv::builder::Init_GetWorkspaceRatio_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkspaceRatio_Event_response
{
public:
  explicit Init_GetWorkspaceRatio_Event_response(::niryo_one_msgs::srv::GetWorkspaceRatio_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Event response(::niryo_one_msgs::srv::GetWorkspaceRatio_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Event msg_;
};

class Init_GetWorkspaceRatio_Event_request
{
public:
  explicit Init_GetWorkspaceRatio_Event_request(::niryo_one_msgs::srv::GetWorkspaceRatio_Event & msg)
  : msg_(msg)
  {}
  Init_GetWorkspaceRatio_Event_response request(::niryo_one_msgs::srv::GetWorkspaceRatio_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetWorkspaceRatio_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Event msg_;
};

class Init_GetWorkspaceRatio_Event_info
{
public:
  Init_GetWorkspaceRatio_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWorkspaceRatio_Event_request info(::niryo_one_msgs::srv::GetWorkspaceRatio_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetWorkspaceRatio_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceRatio_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetWorkspaceRatio_Event>()
{
  return niryo_one_msgs::srv::builder::Init_GetWorkspaceRatio_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_RATIO__BUILDER_HPP_
