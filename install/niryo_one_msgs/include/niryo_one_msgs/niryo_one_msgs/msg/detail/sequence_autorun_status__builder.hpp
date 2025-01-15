// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence_autorun_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/sequence_autorun_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_SequenceAutorunStatus_sequence_ids
{
public:
  explicit Init_SequenceAutorunStatus_sequence_ids(::niryo_one_msgs::msg::SequenceAutorunStatus & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::SequenceAutorunStatus sequence_ids(::niryo_one_msgs::msg::SequenceAutorunStatus::_sequence_ids_type arg)
  {
    msg_.sequence_ids = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::SequenceAutorunStatus msg_;
};

class Init_SequenceAutorunStatus_mode
{
public:
  explicit Init_SequenceAutorunStatus_mode(::niryo_one_msgs::msg::SequenceAutorunStatus & msg)
  : msg_(msg)
  {}
  Init_SequenceAutorunStatus_sequence_ids mode(::niryo_one_msgs::msg::SequenceAutorunStatus::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_SequenceAutorunStatus_sequence_ids(msg_);
  }

private:
  ::niryo_one_msgs::msg::SequenceAutorunStatus msg_;
};

class Init_SequenceAutorunStatus_enabled
{
public:
  Init_SequenceAutorunStatus_enabled()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SequenceAutorunStatus_mode enabled(::niryo_one_msgs::msg::SequenceAutorunStatus::_enabled_type arg)
  {
    msg_.enabled = std::move(arg);
    return Init_SequenceAutorunStatus_mode(msg_);
  }

private:
  ::niryo_one_msgs::msg::SequenceAutorunStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::SequenceAutorunStatus>()
{
  return niryo_one_msgs::msg::builder::Init_SequenceAutorunStatus_enabled();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__BUILDER_HPP_
