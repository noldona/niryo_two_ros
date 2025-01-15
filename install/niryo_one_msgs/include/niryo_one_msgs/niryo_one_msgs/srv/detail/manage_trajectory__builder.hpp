// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/ManageTrajectory.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/manage_trajectory.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_TRAJECTORY__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/manage_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManageTrajectory_Request_trajectory
{
public:
  explicit Init_ManageTrajectory_Request_trajectory(::niryo_one_msgs::srv::ManageTrajectory_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManageTrajectory_Request trajectory(::niryo_one_msgs::srv::ManageTrajectory_Request::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Request msg_;
};

class Init_ManageTrajectory_Request_trajectory_id
{
public:
  explicit Init_ManageTrajectory_Request_trajectory_id(::niryo_one_msgs::srv::ManageTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_ManageTrajectory_Request_trajectory trajectory_id(::niryo_one_msgs::srv::ManageTrajectory_Request::_trajectory_id_type arg)
  {
    msg_.trajectory_id = std::move(arg);
    return Init_ManageTrajectory_Request_trajectory(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Request msg_;
};

class Init_ManageTrajectory_Request_cmd_type
{
public:
  Init_ManageTrajectory_Request_cmd_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManageTrajectory_Request_trajectory_id cmd_type(::niryo_one_msgs::srv::ManageTrajectory_Request::_cmd_type_type arg)
  {
    msg_.cmd_type = std::move(arg);
    return Init_ManageTrajectory_Request_trajectory_id(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManageTrajectory_Request>()
{
  return niryo_one_msgs::srv::builder::Init_ManageTrajectory_Request_cmd_type();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManageTrajectory_Response_trajectory
{
public:
  explicit Init_ManageTrajectory_Response_trajectory(::niryo_one_msgs::srv::ManageTrajectory_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManageTrajectory_Response trajectory(::niryo_one_msgs::srv::ManageTrajectory_Response::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Response msg_;
};

class Init_ManageTrajectory_Response_message
{
public:
  explicit Init_ManageTrajectory_Response_message(::niryo_one_msgs::srv::ManageTrajectory_Response & msg)
  : msg_(msg)
  {}
  Init_ManageTrajectory_Response_trajectory message(::niryo_one_msgs::srv::ManageTrajectory_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ManageTrajectory_Response_trajectory(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Response msg_;
};

class Init_ManageTrajectory_Response_status
{
public:
  Init_ManageTrajectory_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManageTrajectory_Response_message status(::niryo_one_msgs::srv::ManageTrajectory_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ManageTrajectory_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManageTrajectory_Response>()
{
  return niryo_one_msgs::srv::builder::Init_ManageTrajectory_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ManageTrajectory_Event_response
{
public:
  explicit Init_ManageTrajectory_Event_response(::niryo_one_msgs::srv::ManageTrajectory_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ManageTrajectory_Event response(::niryo_one_msgs::srv::ManageTrajectory_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Event msg_;
};

class Init_ManageTrajectory_Event_request
{
public:
  explicit Init_ManageTrajectory_Event_request(::niryo_one_msgs::srv::ManageTrajectory_Event & msg)
  : msg_(msg)
  {}
  Init_ManageTrajectory_Event_response request(::niryo_one_msgs::srv::ManageTrajectory_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ManageTrajectory_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Event msg_;
};

class Init_ManageTrajectory_Event_info
{
public:
  Init_ManageTrajectory_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ManageTrajectory_Event_request info(::niryo_one_msgs::srv::ManageTrajectory_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ManageTrajectory_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::ManageTrajectory_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ManageTrajectory_Event>()
{
  return niryo_one_msgs::srv::builder::Init_ManageTrajectory_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_TRAJECTORY__BUILDER_HPP_
