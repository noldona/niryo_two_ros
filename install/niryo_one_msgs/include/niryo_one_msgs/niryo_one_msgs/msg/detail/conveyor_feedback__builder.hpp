// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/conveyor_feedback.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/conveyor_feedback__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_ConveyorFeedback_direction
{
public:
  explicit Init_ConveyorFeedback_direction(::niryo_one_msgs::msg::ConveyorFeedback & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::ConveyorFeedback direction(::niryo_one_msgs::msg::ConveyorFeedback::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::ConveyorFeedback msg_;
};

class Init_ConveyorFeedback_speed
{
public:
  explicit Init_ConveyorFeedback_speed(::niryo_one_msgs::msg::ConveyorFeedback & msg)
  : msg_(msg)
  {}
  Init_ConveyorFeedback_direction speed(::niryo_one_msgs::msg::ConveyorFeedback::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_ConveyorFeedback_direction(msg_);
  }

private:
  ::niryo_one_msgs::msg::ConveyorFeedback msg_;
};

class Init_ConveyorFeedback_running
{
public:
  explicit Init_ConveyorFeedback_running(::niryo_one_msgs::msg::ConveyorFeedback & msg)
  : msg_(msg)
  {}
  Init_ConveyorFeedback_speed running(::niryo_one_msgs::msg::ConveyorFeedback::_running_type arg)
  {
    msg_.running = std::move(arg);
    return Init_ConveyorFeedback_speed(msg_);
  }

private:
  ::niryo_one_msgs::msg::ConveyorFeedback msg_;
};

class Init_ConveyorFeedback_connection_state
{
public:
  explicit Init_ConveyorFeedback_connection_state(::niryo_one_msgs::msg::ConveyorFeedback & msg)
  : msg_(msg)
  {}
  Init_ConveyorFeedback_running connection_state(::niryo_one_msgs::msg::ConveyorFeedback::_connection_state_type arg)
  {
    msg_.connection_state = std::move(arg);
    return Init_ConveyorFeedback_running(msg_);
  }

private:
  ::niryo_one_msgs::msg::ConveyorFeedback msg_;
};

class Init_ConveyorFeedback_conveyor_id
{
public:
  Init_ConveyorFeedback_conveyor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConveyorFeedback_connection_state conveyor_id(::niryo_one_msgs::msg::ConveyorFeedback::_conveyor_id_type arg)
  {
    msg_.conveyor_id = std::move(arg);
    return Init_ConveyorFeedback_connection_state(msg_);
  }

private:
  ::niryo_one_msgs::msg::ConveyorFeedback msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::ConveyorFeedback>()
{
  return niryo_one_msgs::msg::builder::Init_ConveyorFeedback_conveyor_id();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__BUILDER_HPP_
