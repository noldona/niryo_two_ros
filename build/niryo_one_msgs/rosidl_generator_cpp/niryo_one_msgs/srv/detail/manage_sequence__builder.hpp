// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/ManageSequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/manage_sequence.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_SEQUENCE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_SEQUENCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/manage_sequence__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManageSequence_Request_sequence
{
public:
  explicit Init_ManageSequence_Request_sequence(::niryo_one_msgs::srv::ManageSequence_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManageSequence_Request sequence(::niryo_one_msgs::srv::ManageSequence_Request::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Request msg_;
};

class Init_ManageSequence_Request_sequence_id
{
public:
  explicit Init_ManageSequence_Request_sequence_id(::niryo_one_msgs::srv::ManageSequence_Request & msg)
  : msg_(msg)
  {}
  Init_ManageSequence_Request_sequence sequence_id(::niryo_one_msgs::srv::ManageSequence_Request::_sequence_id_type arg)
  {
    msg_.sequence_id = std::move(arg);
    return Init_ManageSequence_Request_sequence(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Request msg_;
};

class Init_ManageSequence_Request_cmd_type
{
public:
  Init_ManageSequence_Request_cmd_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManageSequence_Request_sequence_id cmd_type(::niryo_one_msgs::srv::ManageSequence_Request::_cmd_type_type arg)
  {
    msg_.cmd_type = std::move(arg);
    return Init_ManageSequence_Request_sequence_id(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManageSequence_Request>()
{
  return niryo_one_msgs::srv::builder::Init_ManageSequence_Request_cmd_type();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManageSequence_Response_sequence
{
public:
  explicit Init_ManageSequence_Response_sequence(::niryo_one_msgs::srv::ManageSequence_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManageSequence_Response sequence(::niryo_one_msgs::srv::ManageSequence_Response::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Response msg_;
};

class Init_ManageSequence_Response_message
{
public:
  explicit Init_ManageSequence_Response_message(::niryo_one_msgs::srv::ManageSequence_Response & msg)
  : msg_(msg)
  {}
  Init_ManageSequence_Response_sequence message(::niryo_one_msgs::srv::ManageSequence_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ManageSequence_Response_sequence(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Response msg_;
};

class Init_ManageSequence_Response_status
{
public:
  Init_ManageSequence_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManageSequence_Response_message status(::niryo_one_msgs::srv::ManageSequence_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ManageSequence_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManageSequence_Response>()
{
  return niryo_one_msgs::srv::builder::Init_ManageSequence_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManageSequence_Event_response
{
public:
  explicit Init_ManageSequence_Event_response(::niryo_one_msgs::srv::ManageSequence_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManageSequence_Event response(::niryo_one_msgs::srv::ManageSequence_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Event msg_;
};

class Init_ManageSequence_Event_request
{
public:
  explicit Init_ManageSequence_Event_request(::niryo_one_msgs::srv::ManageSequence_Event & msg)
  : msg_(msg)
  {}
  Init_ManageSequence_Event_response request(::niryo_one_msgs::srv::ManageSequence_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ManageSequence_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Event msg_;
};

class Init_ManageSequence_Event_info
{
public:
  Init_ManageSequence_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManageSequence_Event_request info(::niryo_one_msgs::srv::ManageSequence_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ManageSequence_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageSequence_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManageSequence_Event>()
{
  return niryo_one_msgs::srv::builder::Init_ManageSequence_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_SEQUENCE__BUILDER_HPP_
