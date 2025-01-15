// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/RobotState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/robot_state.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/robot_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'rpy'
#include "niryo_one_msgs/msg/detail/rpy__traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotState & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: rpy
  {
    out << "rpy: ";
    to_flow_style_yaml(msg.rpy, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: rpy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rpy:\n";
    to_block_style_yaml(msg.rpy, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotState & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::RobotState & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::RobotState & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::RobotState>()
{
  return "niryo_one_msgs::msg::RobotState";
}

template<>
inline const char * name<niryo_one_msgs::msg::RobotState>()
{
  return "niryo_one_msgs/msg/RobotState";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::RobotState>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<niryo_one_msgs::msg::RPY>::value> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::RobotState>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<niryo_one_msgs::msg::RPY>::value> {};

template<>
struct is_message<niryo_one_msgs::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
