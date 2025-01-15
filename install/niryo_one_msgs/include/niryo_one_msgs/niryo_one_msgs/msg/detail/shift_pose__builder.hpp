// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/ShiftPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/shift_pose.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/shift_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_ShiftPose_value
{
public:
  explicit Init_ShiftPose_value(::niryo_one_msgs::msg::ShiftPose & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::ShiftPose value(::niryo_one_msgs::msg::ShiftPose::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::ShiftPose msg_;
};

class Init_ShiftPose_axis_number
{
public:
  Init_ShiftPose_axis_number()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ShiftPose_value axis_number(::niryo_one_msgs::msg::ShiftPose::_axis_number_type arg)
  {
    msg_.axis_number = std::move(arg);
    return Init_ShiftPose_value(msg_);
  }

private:
  ::niryo_one_msgs::msg::ShiftPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::ShiftPose>()
{
  return niryo_one_msgs::msg::builder::Init_ShiftPose_axis_number();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__BUILDER_HPP_
