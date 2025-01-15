// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/ShiftPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/shift_pose.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/shift_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ShiftPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: axis_number
  {
    out << "axis_number: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_number, out);
    out << ", ";
  }

  // member: value
  {
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ShiftPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: axis_number
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "axis_number: ";
    rosidl_generator_traits::value_to_yaml(msg.axis_number, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    rosidl_generator_traits::value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ShiftPose & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::ShiftPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::ShiftPose & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::ShiftPose>()
{
  return "niryo_one_msgs::msg::ShiftPose";
}

template<>
inline const char * name<niryo_one_msgs::msg::ShiftPose>()
{
  return "niryo_one_msgs/msg/ShiftPose";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::ShiftPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::ShiftPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<niryo_one_msgs::msg::ShiftPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SHIFT_POSE__TRAITS_HPP_
