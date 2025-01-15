// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:msg/RobotMoveCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/robot_move_command.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__TRAITS_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/msg/detail/robot_move_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'rpy'
#include "niryo_one_msgs/msg/detail/rpy__traits.hpp"
// Member 'shift'
#include "niryo_one_msgs/msg/detail/shift_pose__traits.hpp"
// Member 'trajectory'
#include "niryo_one_msgs/msg/detail/trajectory_plan__traits.hpp"
// Member 'pose_quat'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'tool_cmd'
#include "niryo_one_msgs/msg/detail/tool_command__traits.hpp"

namespace niryo_one_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotMoveCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd_type
  {
    out << "cmd_type: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_type, out);
    out << ", ";
  }

  // member: joints
  {
    if (msg.joints.size() == 0) {
      out << "joints: []";
    } else {
      out << "joints: [";
      size_t pending_items = msg.joints.size();
      for (auto item : msg.joints) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

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
    out << ", ";
  }

  // member: shift
  {
    out << "shift: ";
    to_flow_style_yaml(msg.shift, out);
    out << ", ";
  }

  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
    out << ", ";
  }

  // member: pose_quat
  {
    out << "pose_quat: ";
    to_flow_style_yaml(msg.pose_quat, out);
    out << ", ";
  }

  // member: saved_position_name
  {
    out << "saved_position_name: ";
    rosidl_generator_traits::value_to_yaml(msg.saved_position_name, out);
    out << ", ";
  }

  // member: saved_trajectory_id
  {
    out << "saved_trajectory_id: ";
    rosidl_generator_traits::value_to_yaml(msg.saved_trajectory_id, out);
    out << ", ";
  }

  // member: tool_cmd
  {
    out << "tool_cmd: ";
    to_flow_style_yaml(msg.tool_cmd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotMoveCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_type: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_type, out);
    out << "\n";
  }

  // member: joints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joints.size() == 0) {
      out << "joints: []\n";
    } else {
      out << "joints:\n";
      for (auto item : msg.joints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

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

  // member: shift
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "shift:\n";
    to_block_style_yaml(msg.shift, out, indentation + 2);
  }

  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }

  // member: pose_quat
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_quat:\n";
    to_block_style_yaml(msg.pose_quat, out, indentation + 2);
  }

  // member: saved_position_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "saved_position_name: ";
    rosidl_generator_traits::value_to_yaml(msg.saved_position_name, out);
    out << "\n";
  }

  // member: saved_trajectory_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "saved_trajectory_id: ";
    rosidl_generator_traits::value_to_yaml(msg.saved_trajectory_id, out);
    out << "\n";
  }

  // member: tool_cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tool_cmd:\n";
    to_block_style_yaml(msg.tool_cmd, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotMoveCommand & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::msg::RobotMoveCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::msg::RobotMoveCommand & msg)
{
  return niryo_one_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::msg::RobotMoveCommand>()
{
  return "niryo_one_msgs::msg::RobotMoveCommand";
}

template<>
inline const char * name<niryo_one_msgs::msg::RobotMoveCommand>()
{
  return "niryo_one_msgs/msg/RobotMoveCommand";
}

template<>
struct has_fixed_size<niryo_one_msgs::msg::RobotMoveCommand>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::msg::RobotMoveCommand>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::msg::RobotMoveCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__ROBOT_MOVE_COMMAND__TRAITS_HPP_
