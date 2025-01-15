// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/SequenceAutorunStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence_autorun_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/sequence_autorun_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SequenceAutorunStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: enabled
  {
    out << "enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.enabled, out);
    out << ", ";
  }

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: sequence_ids
  {
    if (msg.sequence_ids.size() == 0) {
      out << "sequence_ids: []";
    } else {
      out << "sequence_ids: [";
      size_t pending_items = msg.sequence_ids.size();
      for (auto item : msg.sequence_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SequenceAutorunStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.enabled, out);
    out << "\n";
  }

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: sequence_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sequence_ids.size() == 0) {
      out << "sequence_ids: []\n";
    } else {
      out << "sequence_ids:\n";
      for (auto item : msg.sequence_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SequenceAutorunStatus & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::SequenceAutorunStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::SequenceAutorunStatus & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::SequenceAutorunStatus>()
{
  return "niryo_one_msgs::msg::SequenceAutorunStatus";
}

template<>
inline const char * name<niryo_one_msgs::msg::SequenceAutorunStatus>()
{
  return "niryo_one_msgs/msg/SequenceAutorunStatus";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::SequenceAutorunStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::SequenceAutorunStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::msg::SequenceAutorunStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE_AUTORUN_STATUS__TRAITS_HPP_
