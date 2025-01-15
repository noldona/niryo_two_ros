// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/HardwareStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/hardware_status.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/hardware_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const HardwareStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: rpi_temperature
  {
    out << "rpi_temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.rpi_temperature, out);
    out << ", ";
  }

  // member: hardware_version
  {
    out << "hardware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.hardware_version, out);
    out << ", ";
  }

  // member: connection_up
  {
    out << "connection_up: ";
    rosidl_generator_traits::value_to_yaml(msg.connection_up, out);
    out << ", ";
  }

  // member: error_message
  {
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
    out << ", ";
  }

  // member: calibration_needed
  {
    out << "calibration_needed: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration_needed, out);
    out << ", ";
  }

  // member: calibration_in_progress
  {
    out << "calibration_in_progress: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration_in_progress, out);
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

  // member: motor_types
  {
    if (msg.motor_types.size() == 0) {
      out << "motor_types: []";
    } else {
      out << "motor_types: [";
      size_t pending_items = msg.motor_types.size();
      for (auto item : msg.motor_types) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: temperatures
  {
    if (msg.temperatures.size() == 0) {
      out << "temperatures: []";
    } else {
      out << "temperatures: [";
      size_t pending_items = msg.temperatures.size();
      for (auto item : msg.temperatures) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: voltages
  {
    if (msg.voltages.size() == 0) {
      out << "voltages: []";
    } else {
      out << "voltages: [";
      size_t pending_items = msg.voltages.size();
      for (auto item : msg.voltages) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: hardware_errors
  {
    if (msg.hardware_errors.size() == 0) {
      out << "hardware_errors: []";
    } else {
      out << "hardware_errors: [";
      size_t pending_items = msg.hardware_errors.size();
      for (auto item : msg.hardware_errors) {
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
  const HardwareStatus & msg,
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

  // member: rpi_temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rpi_temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.rpi_temperature, out);
    out << "\n";
  }

  // member: hardware_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hardware_version: ";
    rosidl_generator_traits::value_to_yaml(msg.hardware_version, out);
    out << "\n";
  }

  // member: connection_up
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "connection_up: ";
    rosidl_generator_traits::value_to_yaml(msg.connection_up, out);
    out << "\n";
  }

  // member: error_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_message: ";
    rosidl_generator_traits::value_to_yaml(msg.error_message, out);
    out << "\n";
  }

  // member: calibration_needed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "calibration_needed: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration_needed, out);
    out << "\n";
  }

  // member: calibration_in_progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "calibration_in_progress: ";
    rosidl_generator_traits::value_to_yaml(msg.calibration_in_progress, out);
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

  // member: motor_types
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_types.size() == 0) {
      out << "motor_types: []\n";
    } else {
      out << "motor_types:\n";
      for (auto item : msg.motor_types) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: temperatures
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.temperatures.size() == 0) {
      out << "temperatures: []\n";
    } else {
      out << "temperatures:\n";
      for (auto item : msg.temperatures) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: voltages
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.voltages.size() == 0) {
      out << "voltages: []\n";
    } else {
      out << "voltages:\n";
      for (auto item : msg.voltages) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: hardware_errors
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.hardware_errors.size() == 0) {
      out << "hardware_errors: []\n";
    } else {
      out << "hardware_errors:\n";
      for (auto item : msg.hardware_errors) {
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

inline std::string to_yaml(const HardwareStatus & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::HardwareStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::HardwareStatus & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::HardwareStatus>()
{
  return "niryo_one_msgs::msg::HardwareStatus";
}

template<>
inline const char * name<niryo_one_msgs::msg::HardwareStatus>()
{
  return "niryo_one_msgs/msg/HardwareStatus";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::HardwareStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::HardwareStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::msg::HardwareStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__HARDWARE_STATUS__TRAITS_HPP_
