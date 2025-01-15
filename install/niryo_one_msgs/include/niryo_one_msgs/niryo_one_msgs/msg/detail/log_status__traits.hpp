// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/LogStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/log_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/log_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LogStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: log_size
  {
    out << "log_size: ";
    rosidl_generator_traits::value_to_yaml(msg.log_size, out);
    out << ", ";
  }

  // member: available_disk_size
  {
    out << "available_disk_size: ";
    rosidl_generator_traits::value_to_yaml(msg.available_disk_size, out);
    out << ", ";
  }

  // member: purge_log_on_startup
  {
    out << "purge_log_on_startup: ";
    rosidl_generator_traits::value_to_yaml(msg.purge_log_on_startup, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LogStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: log_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "log_size: ";
    rosidl_generator_traits::value_to_yaml(msg.log_size, out);
    out << "\n";
  }

  // member: available_disk_size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "available_disk_size: ";
    rosidl_generator_traits::value_to_yaml(msg.available_disk_size, out);
    out << "\n";
  }

  // member: purge_log_on_startup
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "purge_log_on_startup: ";
    rosidl_generator_traits::value_to_yaml(msg.purge_log_on_startup, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LogStatus & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::LogStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::LogStatus & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::LogStatus>()
{
  return "niryo_one_msgs::msg::LogStatus";
}

template<>
inline const char * name<niryo_one_msgs::msg::LogStatus>()
{
  return "niryo_one_msgs/msg/LogStatus";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::LogStatus>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::LogStatus>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<niryo_one_msgs::msg::LogStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__LOG_STATUS__TRAITS_HPP_
