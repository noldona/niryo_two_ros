// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/ProcessState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/process_state.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/process_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_ProcessState_is_active
{
public:
  explicit Init_ProcessState_is_active(::niryo_one_msgs::msg::ProcessState & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::ProcessState is_active(::niryo_one_msgs::msg::ProcessState::_is_active_type arg)
  {
    msg_.is_active = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::ProcessState msg_;
};

class Init_ProcessState_name
{
public:
  Init_ProcessState_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessState_is_active name(::niryo_one_msgs::msg::ProcessState::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_ProcessState_is_active(msg_);
  }

private:
  ::niryo_one_msgs::msg::ProcessState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::ProcessState>()
{
  return niryo_one_msgs::msg::builder::Init_ProcessState_name();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__PROCESS_STATE__BUILDER_HPP_
