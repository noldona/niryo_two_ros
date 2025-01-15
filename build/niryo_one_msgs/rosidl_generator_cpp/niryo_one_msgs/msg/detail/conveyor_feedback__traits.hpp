// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/ConveyorFeedback.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/conveyor_feedback.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/conveyor_feedback__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ConveyorFeedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: conveyor_id
  {
    out << "conveyor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.conveyor_id, out);
    out << ", ";
  }

  // member: connection_state
  {
    out << "connection_state: ";
    rosidl_generator_traits::value_to_yaml(msg.connection_state, out);
    out << ", ";
  }

  // member: running
  {
    out << "running: ";
    rosidl_generator_traits::value_to_yaml(msg.running, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: direction
  {
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ConveyorFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: conveyor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "conveyor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.conveyor_id, out);
    out << "\n";
  }

  // member: connection_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connection_state: ";
    rosidl_generator_traits::value_to_yaml(msg.connection_state, out);
    out << "\n";
  }

  // member: running
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "running: ";
    rosidl_generator_traits::value_to_yaml(msg.running, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: direction
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "direction: ";
    rosidl_generator_traits::value_to_yaml(msg.direction, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ConveyorFeedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace niryo_one_msgs

namespace rosidl_generator_traits
{

[[deprecated("use niryo_one_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const niryo_one_msgs::msg::ConveyorFeedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::ConveyorFeedback & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::ConveyorFeedback>()
{
  return "niryo_one_msgs::msg::ConveyorFeedback";
}

template<>
inline const char * name<niryo_one_msgs::msg::ConveyorFeedback>()
{
  return "niryo_one_msgs/msg/ConveyorFeedback";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::ConveyorFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::ConveyorFeedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<niryo_one_msgs::msg::ConveyorFeedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__CONVEYOR_FEEDBACK__TRAITS_HPP_
