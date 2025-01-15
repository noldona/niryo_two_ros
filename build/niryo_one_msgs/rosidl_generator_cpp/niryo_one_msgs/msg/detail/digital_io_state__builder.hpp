// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:msg/DigitalIOState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/digital_io_state.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__DIGITAL_IO_STATE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__DIGITAL_IO_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/msg/detail/digital_io_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace msg
{

namespace builder
{

class Init_DigitalIOState_states
{
public:
  explicit Init_DigitalIOState_states(::niryo_one_msgs::msg::DigitalIOState & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::msg::DigitalIOState states(::niryo_one_msgs::msg::DigitalIOState::_states_type arg)
  {
    msg_.states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::msg::DigitalIOState msg_;
};

class Init_DigitalIOState_modes
{
public:
  explicit Init_DigitalIOState_modes(::niryo_one_msgs::msg::DigitalIOState & msg)
  : msg_(msg)
  {}
  Init_DigitalIOState_states modes(::niryo_one_msgs::msg::DigitalIOState::_modes_type arg)
  {
    msg_.modes = std::move(arg);
    return Init_DigitalIOState_states(msg_);
  }

private:
  ::niryo_one_msgs::msg::DigitalIOState msg_;
};

class Init_DigitalIOState_names
{
public:
  explicit Init_DigitalIOState_names(::niryo_one_msgs::msg::DigitalIOState & msg)
  : msg_(msg)
  {}
  Init_DigitalIOState_modes names(::niryo_one_msgs::msg::DigitalIOState::_names_type arg)
  {
    msg_.names = std::move(arg);
    return Init_DigitalIOState_modes(msg_);
  }

private:
  ::niryo_one_msgs::msg::DigitalIOState msg_;
};

class Init_DigitalIOState_pins
{
public:
  Init_DigitalIOState_pins()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DigitalIOState_names pins(::niryo_one_msgs::msg::DigitalIOState::_pins_type arg)
  {
    msg_.pins = std::move(arg);
    return Init_DigitalIOState_names(msg_);
  }

private:
  ::niryo_one_msgs::msg::DigitalIOState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::msg::DigitalIOState>()
{
  return niryo_one_msgs::msg::builder::Init_DigitalIOState_pins();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__DIGITAL_IO_STATE__BUILDER_HPP_
