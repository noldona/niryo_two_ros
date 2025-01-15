// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/MatlabMoveResult.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/matlab_move_result.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__MATLAB_MOVE_RESULT__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__MATLAB_MOVE_RESULT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/matlab_move_result__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_MatlabMoveResult_message
{
public:
  explicit Init_MatlabMoveResult_message(::niryo_one_msgs::msg::MatlabMoveResult & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::MatlabMoveResult message(::niryo_one_msgs::msg::MatlabMoveResult::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::MatlabMoveResult msg_;
};

class Init_MatlabMoveResult_status
{
public:
  Init_MatlabMoveResult_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MatlabMoveResult_message status(::niryo_one_msgs::msg::MatlabMoveResult::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MatlabMoveResult_message(msg_);
  }

private:
  ::niryo_one_msgs::msg::MatlabMoveResult msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::MatlabMoveResult>()
{
  return niryo_one_msgs::msg::builder::Init_MatlabMoveResult_status();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__MATLAB_MOVE_RESULT__BUILDER_HPP_
