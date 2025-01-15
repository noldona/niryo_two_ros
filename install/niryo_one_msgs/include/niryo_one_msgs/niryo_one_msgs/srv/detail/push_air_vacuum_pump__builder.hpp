// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/PushAirVacuumPump.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/push_air_vacuum_pump.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__PUSH_AIR_VACUUM_PUMP__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__PUSH_AIR_VACUUM_PUMP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/push_air_vacuum_pump__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_PushAirVacuumPump_Request_push_air_position
{
public:
  explicit Init_PushAirVacuumPump_Request_push_air_position(::niryo_one_msgs::srv::PushAirVacuumPump_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::PushAirVacuumPump_Request push_air_position(::niryo_one_msgs::srv::PushAirVacuumPump_Request::_push_air_position_type arg)
  {
    msg_.push_air_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::PushAirVacuumPump_Request msg_;
};

class Init_PushAirVacuumPump_Request_id
{
public:
  Init_PushAirVacuumPump_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PushAirVacuumPump_Request_push_air_position id(::niryo_one_msgs::srv::PushAirVacuumPump_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_PushAirVacuumPump_Request_push_air_position(msg_);
  }

private:
  ::niryo_one_msgs::srv::PushAirVacuumPump_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::PushAirVacuumPump_Request>()
{
  return niryo_one_msgs::srv::builder::Init_PushAirVacuumPump_Request_id();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_PushAirVacuumPump_Response_state
{
public:
  Init_PushAirVacuumPump_Response_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::niryo_one_msgs::srv::PushAirVacuumPump_Response state(::niryo_one_msgs::srv::PushAirVacuumPump_Response::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::PushAirVacuumPump_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::PushAirVacuumPump_Response>()
{
  return niryo_one_msgs::srv::builder::Init_PushAirVacuumPump_Response_state();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_PushAirVacuumPump_Event_response
{
public:
  explicit Init_PushAirVacuumPump_Event_response(::niryo_one_msgs::srv::PushAirVacuumPump_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::PushAirVacuumPump_Event response(::niryo_one_msgs::srv::PushAirVacuumPump_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::PushAirVacuumPump_Event msg_;
};

class Init_PushAirVacuumPump_Event_request
{
public:
  explicit Init_PushAirVacuumPump_Event_request(::niryo_one_msgs::srv::PushAirVacuumPump_Event & msg)
  : msg_(msg)
  {}
  Init_PushAirVacuumPump_Event_response request(::niryo_one_msgs::srv::PushAirVacuumPump_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_PushAirVacuumPump_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::PushAirVacuumPump_Event msg_;
};

class Init_PushAirVacuumPump_Event_info
{
public:
  Init_PushAirVacuumPump_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PushAirVacuumPump_Event_request info(::niryo_one_msgs::srv::PushAirVacuumPump_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_PushAirVacuumPump_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::PushAirVacuumPump_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::PushAirVacuumPump_Event>()
{
  return niryo_one_msgs::srv::builder::Init_PushAirVacuumPump_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__PUSH_AIR_VACUUM_PUMP__BUILDER_HPP_
