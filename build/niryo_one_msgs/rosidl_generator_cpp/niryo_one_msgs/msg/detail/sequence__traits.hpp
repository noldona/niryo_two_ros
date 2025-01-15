// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/Sequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/sequence__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Sequence & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: description
  {
    out << "description: ";
    rosidl_generator_traits::value_to_yaml(msg.description, out);
    out << ", ";
  }

  // member: created
  {
    out << "created: ";
    rosidl_generator_traits::value_to_yaml(msg.created, out);
    out << ", ";
  }

  // member: updated
  {
    out << "updated: ";
    rosidl_generator_traits::value_to_yaml(msg.updated, out);
    out << ", ";
  }

  // member: blockly_xml
  {
    out << "blockly_xml: ";
    rosidl_generator_traits::value_to_yaml(msg.blockly_xml, out);
    out << ", ";
  }

  // member: python_code
  {
    out << "python_code: ";
    rosidl_generator_traits::value_to_yaml(msg.python_code, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Sequence & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: description
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "description: ";
    rosidl_generator_traits::value_to_yaml(msg.description, out);
    out << "\n";
  }

  // member: created
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "created: ";
    rosidl_generator_traits::value_to_yaml(msg.created, out);
    out << "\n";
  }

  // member: updated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "updated: ";
    rosidl_generator_traits::value_to_yaml(msg.updated, out);
    out << "\n";
  }

  // member: blockly_xml
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "blockly_xml: ";
    rosidl_generator_traits::value_to_yaml(msg.blockly_xml, out);
    out << "\n";
  }

  // member: python_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "python_code: ";
    rosidl_generator_traits::value_to_yaml(msg.python_code, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Sequence & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::Sequence & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::Sequence & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::Sequence>()
{
  return "niryo_one_msgs::msg::Sequence";
}

template<>
inline const char * name<niryo_one_msgs::msg::Sequence>()
{
  return "niryo_one_msgs/msg/Sequence";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::Sequence>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::Sequence>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::msg::Sequence>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__TRAITS_HPP_
