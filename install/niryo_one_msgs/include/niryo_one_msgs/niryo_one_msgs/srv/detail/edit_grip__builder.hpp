// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/EditGrip.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/edit_grip.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_GRIP__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_GRIP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/edit_grip__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_EditGrip_Request_robot_pose
{
public:
  explicit Init_EditGrip_Request_robot_pose(::niryo_one_msgs::srv::EditGrip_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::EditGrip_Request robot_pose(::niryo_one_msgs::srv::EditGrip_Request::_robot_pose_type arg)
  {
    msg_.robot_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Request msg_;
};

class Init_EditGrip_Request_workspace
{
public:
  explicit Init_EditGrip_Request_workspace(::niryo_one_msgs::srv::EditGrip_Request & msg)
  : msg_(msg)
  {}
  Init_EditGrip_Request_robot_pose workspace(::niryo_one_msgs::srv::EditGrip_Request::_workspace_type arg)
  {
    msg_.workspace = std::move(arg);
    return Init_EditGrip_Request_robot_pose(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Request msg_;
};

class Init_EditGrip_Request_name
{
public:
  explicit Init_EditGrip_Request_name(::niryo_one_msgs::srv::EditGrip_Request & msg)
  : msg_(msg)
  {}
  Init_EditGrip_Request_workspace name(::niryo_one_msgs::srv::EditGrip_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_EditGrip_Request_workspace(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Request msg_;
};

class Init_EditGrip_Request_cmd
{
public:
  Init_EditGrip_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EditGrip_Request_name cmd(::niryo_one_msgs::srv::EditGrip_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return Init_EditGrip_Request_name(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::EditGrip_Request>()
{
  return niryo_one_msgs::srv::builder::Init_EditGrip_Request_cmd();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_EditGrip_Response_message
{
public:
  explicit Init_EditGrip_Response_message(::niryo_one_msgs::srv::EditGrip_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::EditGrip_Response message(::niryo_one_msgs::srv::EditGrip_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Response msg_;
};

class Init_EditGrip_Response_status
{
public:
  Init_EditGrip_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EditGrip_Response_message status(::niryo_one_msgs::srv::EditGrip_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_EditGrip_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::EditGrip_Response>()
{
  return niryo_one_msgs::srv::builder::Init_EditGrip_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_EditGrip_Event_response
{
public:
  explicit Init_EditGrip_Event_response(::niryo_one_msgs::srv::EditGrip_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::EditGrip_Event response(::niryo_one_msgs::srv::EditGrip_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Event msg_;
};

class Init_EditGrip_Event_request
{
public:
  explicit Init_EditGrip_Event_request(::niryo_one_msgs::srv::EditGrip_Event & msg)
  : msg_(msg)
  {}
  Init_EditGrip_Event_response request(::niryo_one_msgs::srv::EditGrip_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_EditGrip_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Event msg_;
};

class Init_EditGrip_Event_info
{
public:
  Init_EditGrip_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EditGrip_Event_request info(::niryo_one_msgs::srv::EditGrip_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_EditGrip_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditGrip_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::EditGrip_Event>()
{
  return niryo_one_msgs::srv::builder::Init_EditGrip_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_GRIP__BUILDER_HPP_
