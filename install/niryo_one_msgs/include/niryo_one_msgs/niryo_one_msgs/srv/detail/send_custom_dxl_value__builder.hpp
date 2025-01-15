// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/SendCustomDxlValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/send_custom_dxl_value.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__SEND_CUSTOM_DXL_VALUE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__SEND_CUSTOM_DXL_VALUE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/send_custom_dxl_value__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SendCustomDxlValue_Request_byte_number
{
public:
  explicit Init_SendCustomDxlValue_Request_byte_number(::niryo_one_msgs::srv::SendCustomDxlValue_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SendCustomDxlValue_Request byte_number(::niryo_one_msgs::srv::SendCustomDxlValue_Request::_byte_number_type arg)
  {
    msg_.byte_number = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Request msg_;
};

class Init_SendCustomDxlValue_Request_reg_address
{
public:
  explicit Init_SendCustomDxlValue_Request_reg_address(::niryo_one_msgs::srv::SendCustomDxlValue_Request & msg)
  : msg_(msg)
  {}
  Init_SendCustomDxlValue_Request_byte_number reg_address(::niryo_one_msgs::srv::SendCustomDxlValue_Request::_reg_address_type arg)
  {
    msg_.reg_address = std::move(arg);
    return Init_SendCustomDxlValue_Request_byte_number(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Request msg_;
};

class Init_SendCustomDxlValue_Request_value
{
public:
  explicit Init_SendCustomDxlValue_Request_value(::niryo_one_msgs::srv::SendCustomDxlValue_Request & msg)
  : msg_(msg)
  {}
  Init_SendCustomDxlValue_Request_reg_address value(::niryo_one_msgs::srv::SendCustomDxlValue_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return Init_SendCustomDxlValue_Request_reg_address(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Request msg_;
};

class Init_SendCustomDxlValue_Request_id
{
public:
  explicit Init_SendCustomDxlValue_Request_id(::niryo_one_msgs::srv::SendCustomDxlValue_Request & msg)
  : msg_(msg)
  {}
  Init_SendCustomDxlValue_Request_value id(::niryo_one_msgs::srv::SendCustomDxlValue_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_SendCustomDxlValue_Request_value(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Request msg_;
};

class Init_SendCustomDxlValue_Request_motor_type
{
public:
  Init_SendCustomDxlValue_Request_motor_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendCustomDxlValue_Request_id motor_type(::niryo_one_msgs::srv::SendCustomDxlValue_Request::_motor_type_type arg)
  {
    msg_.motor_type = std::move(arg);
    return Init_SendCustomDxlValue_Request_id(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SendCustomDxlValue_Request>()
{
  return niryo_one_msgs::srv::builder::Init_SendCustomDxlValue_Request_motor_type();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SendCustomDxlValue_Response_message
{
public:
  explicit Init_SendCustomDxlValue_Response_message(::niryo_one_msgs::srv::SendCustomDxlValue_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SendCustomDxlValue_Response message(::niryo_one_msgs::srv::SendCustomDxlValue_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Response msg_;
};

class Init_SendCustomDxlValue_Response_status
{
public:
  Init_SendCustomDxlValue_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendCustomDxlValue_Response_message status(::niryo_one_msgs::srv::SendCustomDxlValue_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SendCustomDxlValue_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SendCustomDxlValue_Response>()
{
  return niryo_one_msgs::srv::builder::Init_SendCustomDxlValue_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_SendCustomDxlValue_Event_response
{
public:
  explicit Init_SendCustomDxlValue_Event_response(::niryo_one_msgs::srv::SendCustomDxlValue_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::SendCustomDxlValue_Event response(::niryo_one_msgs::srv::SendCustomDxlValue_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Event msg_;
};

class Init_SendCustomDxlValue_Event_request
{
public:
  explicit Init_SendCustomDxlValue_Event_request(::niryo_one_msgs::srv::SendCustomDxlValue_Event & msg)
  : msg_(msg)
  {}
  Init_SendCustomDxlValue_Event_response request(::niryo_one_msgs::srv::SendCustomDxlValue_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SendCustomDxlValue_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Event msg_;
};

class Init_SendCustomDxlValue_Event_info
{
public:
  Init_SendCustomDxlValue_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendCustomDxlValue_Event_request info(::niryo_one_msgs::srv::SendCustomDxlValue_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SendCustomDxlValue_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::SendCustomDxlValue_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::SendCustomDxlValue_Event>()
{
  return niryo_one_msgs::srv::builder::Init_SendCustomDxlValue_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__SEND_CUSTOM_DXL_VALUE__BUILDER_HPP_
