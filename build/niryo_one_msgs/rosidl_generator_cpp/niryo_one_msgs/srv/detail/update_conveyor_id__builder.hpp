// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/UpdateConveyorId.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/update_conveyor_id.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__UPDATE_CONVEYOR_ID__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__UPDATE_CONVEYOR_ID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/update_conveyor_id__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_UpdateConveyorId_Request_new_id
{
public:
  explicit Init_UpdateConveyorId_Request_new_id(::niryo_one_msgs::srv::UpdateConveyorId_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::UpdateConveyorId_Request new_id(::niryo_one_msgs::srv::UpdateConveyorId_Request::_new_id_type arg)
  {
    msg_.new_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::UpdateConveyorId_Request msg_;
};

class Init_UpdateConveyorId_Request_old_id
{
public:
  Init_UpdateConveyorId_Request_old_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateConveyorId_Request_new_id old_id(::niryo_one_msgs::srv::UpdateConveyorId_Request::_old_id_type arg)
  {
    msg_.old_id = std::move(arg);
    return Init_UpdateConveyorId_Request_new_id(msg_);
  }

private:
  ::niryo_one_msgs::srv::UpdateConveyorId_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::UpdateConveyorId_Request>()
{
  return niryo_one_msgs::srv::builder::Init_UpdateConveyorId_Request_old_id();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_UpdateConveyorId_Response_message
{
public:
  explicit Init_UpdateConveyorId_Response_message(::niryo_one_msgs::srv::UpdateConveyorId_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::UpdateConveyorId_Response message(::niryo_one_msgs::srv::UpdateConveyorId_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::UpdateConveyorId_Response msg_;
};

class Init_UpdateConveyorId_Response_status
{
public:
  Init_UpdateConveyorId_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateConveyorId_Response_message status(::niryo_one_msgs::srv::UpdateConveyorId_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_UpdateConveyorId_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::UpdateConveyorId_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::UpdateConveyorId_Response>()
{
  return niryo_one_msgs::srv::builder::Init_UpdateConveyorId_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_UpdateConveyorId_Event_response
{
public:
  explicit Init_UpdateConveyorId_Event_response(::niryo_one_msgs::srv::UpdateConveyorId_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::UpdateConveyorId_Event response(::niryo_one_msgs::srv::UpdateConveyorId_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::UpdateConveyorId_Event msg_;
};

class Init_UpdateConveyorId_Event_request
{
public:
  explicit Init_UpdateConveyorId_Event_request(::niryo_one_msgs::srv::UpdateConveyorId_Event & msg)
  : msg_(msg)
  {}
  Init_UpdateConveyorId_Event_response request(::niryo_one_msgs::srv::UpdateConveyorId_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_UpdateConveyorId_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::UpdateConveyorId_Event msg_;
};

class Init_UpdateConveyorId_Event_info
{
public:
  Init_UpdateConveyorId_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UpdateConveyorId_Event_request info(::niryo_one_msgs::srv::UpdateConveyorId_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_UpdateConveyorId_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::UpdateConveyorId_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::UpdateConveyorId_Event>()
{
  return niryo_one_msgs::srv::builder::Init_UpdateConveyorId_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__UPDATE_CONVEYOR_ID__BUILDER_HPP_
