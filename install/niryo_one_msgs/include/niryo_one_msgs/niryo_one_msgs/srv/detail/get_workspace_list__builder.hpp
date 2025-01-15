// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/GetWorkspaceList.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_workspace_list.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_LIST__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_LIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/get_workspace_list__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetWorkspaceList_Request>()
{
  return ::niryo_one_msgs::srv::GetWorkspaceList_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkspaceList_Response_workspaces
{
public:
  Init_GetWorkspaceList_Response_workspaces()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::GetWorkspaceList_Response workspaces(::niryo_one_msgs::srv::GetWorkspaceList_Response::_workspaces_type arg)
  {
    msg_.workspaces = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceList_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetWorkspaceList_Response>()
{
  return niryo_one_msgs::srv::builder::Init_GetWorkspaceList_Response_workspaces();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_GetWorkspaceList_Event_response
{
public:
  explicit Init_GetWorkspaceList_Event_response(::niryo_one_msgs::srv::GetWorkspaceList_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::GetWorkspaceList_Event response(::niryo_one_msgs::srv::GetWorkspaceList_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceList_Event msg_;
};

class Init_GetWorkspaceList_Event_request
{
public:
  explicit Init_GetWorkspaceList_Event_request(::niryo_one_msgs::srv::GetWorkspaceList_Event & msg)
  : msg_(msg)
  {}
  Init_GetWorkspaceList_Event_response request(::niryo_one_msgs::srv::GetWorkspaceList_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetWorkspaceList_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceList_Event msg_;
};

class Init_GetWorkspaceList_Event_info
{
public:
  Init_GetWorkspaceList_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetWorkspaceList_Event_request info(::niryo_one_msgs::srv::GetWorkspaceList_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetWorkspaceList_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::GetWorkspaceList_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::GetWorkspaceList_Event>()
{
  return niryo_one_msgs::srv::builder::Init_GetWorkspaceList_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_LIST__BUILDER_HPP_
