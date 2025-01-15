// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/tool_command.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/tool_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ToolCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: tool_id
  {
    out << "tool_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_id, out);
    out << ", ";
  }

  // member: cmd_type
  {
    out << "cmd_type: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_type, out);
    out << ", ";
  }

  // member: gripper_close_speed
  {
    out << "gripper_close_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_close_speed, out);
    out << ", ";
  }

  // member: gripper_open_speed
  {
    out << "gripper_open_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_open_speed, out);
    out << ", ";
  }

  // member: activate
  {
    out << "activate: ";
    rosidl_generator_traits::value_to_yaml(msg.activate, out);
    out << ", ";
  }

  // member: gpio
  {
    out << "gpio: ";
    rosidl_generator_traits::value_to_yaml(msg.gpio, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ToolCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tool_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tool_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_id, out);
    out << "\n";
  }

  // member: cmd_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_type: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_type, out);
    out << "\n";
  }

  // member: gripper_close_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_close_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_close_speed, out);
    out << "\n";
  }

  // member: gripper_open_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gripper_open_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.gripper_open_speed, out);
    out << "\n";
  }

  // member: activate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "activate: ";
    rosidl_generator_traits::value_to_yaml(msg.activate, out);
    out << "\n";
  }

  // member: gpio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gpio: ";
    rosidl_generator_traits::value_to_yaml(msg.gpio, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ToolCommand & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::ToolCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::ToolCommand & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::ToolCommand>()
{
  return "niryo_one_msgs::msg::ToolCommand";
}

template<>
inline const char * name<niryo_one_msgs::msg::ToolCommand>()
{
  return "niryo_one_msgs/msg/ToolCommand";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::ToolCommand>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::ToolCommand>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<niryo_one_msgs::msg::ToolCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__TOOL_COMMAND__TRAITS_HPP_
