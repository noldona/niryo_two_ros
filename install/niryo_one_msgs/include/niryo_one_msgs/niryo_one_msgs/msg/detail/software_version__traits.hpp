// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/software_version.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/software_version__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SoftwareVersion & msg,
  std::ostream & out)
{
  out << "{";
  // member: rpi_image_version
  {
    out << "rpi_image_version: ";
    rosidl_generator_traits::value_to_yaml(msg.rpi_image_version, out);
    out << ", ";
  }

  // member: ros_niryo_one_version
  {
    out << "ros_niryo_one_version: ";
    rosidl_generator_traits::value_to_yaml(msg.ros_niryo_one_version, out);
    out << ", ";
  }

  // member: motor_names
  {
    if (msg.motor_names.size() == 0) {
      out << "motor_names: []";
    } else {
      out << "motor_names: [";
      size_t pending_items = msg.motor_names.size();
      for (auto item : msg.motor_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: stepper_firmware_versions
  {
    if (msg.stepper_firmware_versions.size() == 0) {
      out << "stepper_firmware_versions: []";
    } else {
      out << "stepper_firmware_versions: [";
      size_t pending_items = msg.stepper_firmware_versions.size();
      for (auto item : msg.stepper_firmware_versions) {
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
  const SoftwareVersion & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: rpi_image_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rpi_image_version: ";
    rosidl_generator_traits::value_to_yaml(msg.rpi_image_version, out);
    out << "\n";
  }

  // member: ros_niryo_one_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ros_niryo_one_version: ";
    rosidl_generator_traits::value_to_yaml(msg.ros_niryo_one_version, out);
    out << "\n";
  }

  // member: motor_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_names.size() == 0) {
      out << "motor_names: []\n";
    } else {
      out << "motor_names:\n";
      for (auto item : msg.motor_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: stepper_firmware_versions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.stepper_firmware_versions.size() == 0) {
      out << "stepper_firmware_versions: []\n";
    } else {
      out << "stepper_firmware_versions:\n";
      for (auto item : msg.stepper_firmware_versions) {
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

inline std::string to_yaml(const SoftwareVersion & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::SoftwareVersion & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::SoftwareVersion & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::SoftwareVersion>()
{
  return "niryo_one_msgs::msg::SoftwareVersion";
}

template<>
inline const char * name<niryo_one_msgs::msg::SoftwareVersion>()
{
  return "niryo_one_msgs/msg/SoftwareVersion";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::SoftwareVersion>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::SoftwareVersion>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::msg::SoftwareVersion>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SOFTWARE_VERSION__TRAITS_HPP_
