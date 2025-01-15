// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/ManagePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/manage_position.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/manage_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManagePosition_Request_position
{
public:
  explicit Init_ManagePosition_Request_position(::niryo_one_msgs::srv::ManagePosition_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManagePosition_Request position(::niryo_one_msgs::srv::ManagePosition_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Request msg_;
};

class Init_ManagePosition_Request_position_name
{
public:
  explicit Init_ManagePosition_Request_position_name(::niryo_one_msgs::srv::ManagePosition_Request & msg)
  : msg_(msg)
  {}
  Init_ManagePosition_Request_position position_name(::niryo_one_msgs::srv::ManagePosition_Request::_position_name_type arg)
  {
    msg_.position_name = std::move(arg);
    return Init_ManagePosition_Request_position(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Request msg_;
};

class Init_ManagePosition_Request_cmd_type
{
public:
  Init_ManagePosition_Request_cmd_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManagePosition_Request_position_name cmd_type(::niryo_one_msgs::srv::ManagePosition_Request::_cmd_type_type arg)
  {
    msg_.cmd_type = std::move(arg);
    return Init_ManagePosition_Request_position_name(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManagePosition_Request>()
{
  return niryo_one_msgs::srv::builder::Init_ManagePosition_Request_cmd_type();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManagePosition_Response_position
{
public:
  explicit Init_ManagePosition_Response_position(::niryo_one_msgs::srv::ManagePosition_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManagePosition_Response position(::niryo_one_msgs::srv::ManagePosition_Response::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Response msg_;
};

class Init_ManagePosition_Response_message
{
public:
  explicit Init_ManagePosition_Response_message(::niryo_one_msgs::srv::ManagePosition_Response & msg)
  : msg_(msg)
  {}
  Init_ManagePosition_Response_position message(::niryo_one_msgs::srv::ManagePosition_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ManagePosition_Response_position(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Response msg_;
};

class Init_ManagePosition_Response_status
{
public:
  Init_ManagePosition_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManagePosition_Response_message status(::niryo_one_msgs::srv::ManagePosition_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ManagePosition_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManagePosition_Response>()
{
  return niryo_one_msgs::srv::builder::Init_ManagePosition_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManagePosition_Event_response
{
public:
  explicit Init_ManagePosition_Event_response(::niryo_one_msgs::srv::ManagePosition_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManagePosition_Event response(::niryo_one_msgs::srv::ManagePosition_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Event msg_;
};

class Init_ManagePosition_Event_request
{
public:
  explicit Init_ManagePosition_Event_request(::niryo_one_msgs::srv::ManagePosition_Event & msg)
  : msg_(msg)
  {}
  Init_ManagePosition_Event_response request(::niryo_one_msgs::srv::ManagePosition_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ManagePosition_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Event msg_;
};

class Init_ManagePosition_Event_info
{
public:
  Init_ManagePosition_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManagePosition_Event_request info(::niryo_one_msgs::srv::ManagePosition_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ManagePosition_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManagePosition_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManagePosition_Event>()
{
  return niryo_one_msgs::srv::builder::Init_ManagePosition_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__BUILDER_HPP_
