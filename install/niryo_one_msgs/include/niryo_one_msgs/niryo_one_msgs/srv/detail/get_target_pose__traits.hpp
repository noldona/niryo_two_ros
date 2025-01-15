// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:srv/GetTargetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_target_pose.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__TRAITS_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/srv/detail/get_target_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetTargetPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: workspace
  {
    out << "workspace: ";
    rosidl_generator_traits::value_to_yaml(msg.workspace, out);
    out << ", ";
  }

  // member: grip
  {
    out << "grip: ";
    rosidl_generator_traits::value_to_yaml(msg.grip, out);
    out << ", ";
  }

  // member: tool_id
  {
    out << "tool_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_id, out);
    out << ", ";
  }

  // member: height_offset
  {
    out << "height_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.height_offset, out);
    out << ", ";
  }

  // member: x_rel
  {
    out << "x_rel: ";
    rosidl_generator_traits::value_to_yaml(msg.x_rel, out);
    out << ", ";
  }

  // member: y_rel
  {
    out << "y_rel: ";
    rosidl_generator_traits::value_to_yaml(msg.y_rel, out);
    out << ", ";
  }

  // member: yaw_rel
  {
    out << "yaw_rel: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rel, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetTargetPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: workspace
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "workspace: ";
    rosidl_generator_traits::value_to_yaml(msg.workspace, out);
    out << "\n";
  }

  // member: grip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grip: ";
    rosidl_generator_traits::value_to_yaml(msg.grip, out);
    out << "\n";
  }

  // member: tool_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tool_id: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_id, out);
    out << "\n";
  }

  // member: height_offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "height_offset: ";
    rosidl_generator_traits::value_to_yaml(msg.height_offset, out);
    out << "\n";
  }

  // member: x_rel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_rel: ";
    rosidl_generator_traits::value_to_yaml(msg.x_rel, out);
    out << "\n";
  }

  // member: y_rel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_rel: ";
    rosidl_generator_traits::value_to_yaml(msg.y_rel, out);
    out << "\n";
  }

  // member: yaw_rel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_rel: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rel, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetTargetPose_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace niryo_one_msgs

namespace rosidl_generator_traits
{

[[deprecated("use niryo_one_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const niryo_one_msgs::srv::GetTargetPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::GetTargetPose_Request & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::GetTargetPose_Request>()
{
  return "niryo_one_msgs::srv::GetTargetPose_Request";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetTargetPose_Request>()
{
  return "niryo_one_msgs/srv/GetTargetPose_Request";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetTargetPose_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetTargetPose_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::srv::GetTargetPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'target_pose'
#include "niryo_one_msgs/msg/detail/robot_state__traits.hpp"

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetTargetPose_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: target_pose
  {
    out << "target_pose: ";
    to_flow_style_yaml(msg.target_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetTargetPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: target_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_pose:\n";
    to_block_style_yaml(msg.target_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetTargetPose_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace niryo_one_msgs

namespace rosidl_generator_traits
{

[[deprecated("use niryo_one_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const niryo_one_msgs::srv::GetTargetPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::GetTargetPose_Response & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::GetTargetPose_Response>()
{
  return "niryo_one_msgs::srv::GetTargetPose_Response";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetTargetPose_Response>()
{
  return "niryo_one_msgs/srv/GetTargetPose_Response";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetTargetPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetTargetPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::srv::GetTargetPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetTargetPose_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
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
  const GetTargetPose_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetTargetPose_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace niryo_one_msgs

namespace rosidl_generator_traits
{

[[deprecated("use niryo_one_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const niryo_one_msgs::srv::GetTargetPose_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::GetTargetPose_Event & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::GetTargetPose_Event>()
{
  return "niryo_one_msgs::srv::GetTargetPose_Event";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetTargetPose_Event>()
{
  return "niryo_one_msgs/srv/GetTargetPose_Event";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetTargetPose_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetTargetPose_Event>
  : std::integral_constant<bool, has_bounded_size<niryo_one_msgs::srv::GetTargetPose_Request>::value && has_bounded_size<niryo_one_msgs::srv::GetTargetPose_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<niryo_one_msgs::srv::GetTargetPose_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<niryo_one_msgs::srv::GetTargetPose>()
{
  return "niryo_one_msgs::srv::GetTargetPose";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetTargetPose>()
{
  return "niryo_one_msgs/srv/GetTargetPose";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetTargetPose>
  : std::integral_constant<
    bool,
    has_fixed_size<niryo_one_msgs::srv::GetTargetPose_Request>::value &&
    has_fixed_size<niryo_one_msgs::srv::GetTargetPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetTargetPose>
  : std::integral_constant<
    bool,
    has_bounded_size<niryo_one_msgs::srv::GetTargetPose_Request>::value &&
    has_bounded_size<niryo_one_msgs::srv::GetTargetPose_Response>::value
  >
{
};

template<>
struct is_service<niryo_one_msgs::srv::GetTargetPose>
  : std::true_type
{
};

template<>
struct is_service_request<niryo_one_msgs::srv::GetTargetPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<niryo_one_msgs::srv::GetTargetPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__TRAITS_HPP_
