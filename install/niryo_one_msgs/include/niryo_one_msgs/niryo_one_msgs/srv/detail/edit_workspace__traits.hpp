// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:srv/EditWorkspace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/edit_workspace.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_WORKSPACE__TRAITS_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_WORKSPACE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/srv/detail/edit_workspace__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_origin'
// Member 'pose_1'
// Member 'pose_2'
// Member 'pose_3'
#include "niryo_one_msgs/msg/detail/robot_state__traits.hpp"

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const EditWorkspace_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd
  {
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: pose_origin
  {
    out << "pose_origin: ";
    to_flow_style_yaml(msg.pose_origin, out);
    out << ", ";
  }

  // member: pose_1
  {
    out << "pose_1: ";
    to_flow_style_yaml(msg.pose_1, out);
    out << ", ";
  }

  // member: pose_2
  {
    out << "pose_2: ";
    to_flow_style_yaml(msg.pose_2, out);
    out << ", ";
  }

  // member: pose_3
  {
    out << "pose_3: ";
    to_flow_style_yaml(msg.pose_3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EditWorkspace_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
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

  // member: pose_origin
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_origin:\n";
    to_block_style_yaml(msg.pose_origin, out, indentation + 2);
  }

  // member: pose_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_1:\n";
    to_block_style_yaml(msg.pose_1, out, indentation + 2);
  }

  // member: pose_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_2:\n";
    to_block_style_yaml(msg.pose_2, out, indentation + 2);
  }

  // member: pose_3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_3:\n";
    to_block_style_yaml(msg.pose_3, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EditWorkspace_Request & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::EditWorkspace_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::EditWorkspace_Request & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::EditWorkspace_Request>()
{
  return "niryo_one_msgs::srv::EditWorkspace_Request";
}

template<>
inline const char * name<niryo_one_msgs::srv::EditWorkspace_Request>()
{
  return "niryo_one_msgs/srv/EditWorkspace_Request";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::EditWorkspace_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::EditWorkspace_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::srv::EditWorkspace_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const EditWorkspace_Response & msg,
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
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EditWorkspace_Response & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EditWorkspace_Response & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::EditWorkspace_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::EditWorkspace_Response & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::EditWorkspace_Response>()
{
  return "niryo_one_msgs::srv::EditWorkspace_Response";
}

template<>
inline const char * name<niryo_one_msgs::srv::EditWorkspace_Response>()
{
  return "niryo_one_msgs/srv/EditWorkspace_Response";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::EditWorkspace_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::EditWorkspace_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::srv::EditWorkspace_Response>
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
  const EditWorkspace_Event & msg,
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
  const EditWorkspace_Event & msg,
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

inline std::string to_yaml(const EditWorkspace_Event & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::EditWorkspace_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::EditWorkspace_Event & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::EditWorkspace_Event>()
{
  return "niryo_one_msgs::srv::EditWorkspace_Event";
}

template<>
inline const char * name<niryo_one_msgs::srv::EditWorkspace_Event>()
{
  return "niryo_one_msgs/srv/EditWorkspace_Event";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::EditWorkspace_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::EditWorkspace_Event>
  : std::integral_constant<bool, has_bounded_size<niryo_one_msgs::srv::EditWorkspace_Request>::value && has_bounded_size<niryo_one_msgs::srv::EditWorkspace_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<niryo_one_msgs::srv::EditWorkspace_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<niryo_one_msgs::srv::EditWorkspace>()
{
  return "niryo_one_msgs::srv::EditWorkspace";
}

template<>
inline const char * name<niryo_one_msgs::srv::EditWorkspace>()
{
  return "niryo_one_msgs/srv/EditWorkspace";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::EditWorkspace>
  : std::integral_constant<
    bool,
    has_fixed_size<niryo_one_msgs::srv::EditWorkspace_Request>::value &&
    has_fixed_size<niryo_one_msgs::srv::EditWorkspace_Response>::value
  >
{
};

template<>
struct has_bounded_size<niryo_one_msgs::srv::EditWorkspace>
  : std::integral_constant<
    bool,
    has_bounded_size<niryo_one_msgs::srv::EditWorkspace_Request>::value &&
    has_bounded_size<niryo_one_msgs::srv::EditWorkspace_Response>::value
  >
{
};

template<>
struct is_service<niryo_one_msgs::srv::EditWorkspace>
  : std::true_type
{
};

template<>
struct is_service_request<niryo_one_msgs::srv::EditWorkspace_Request>
  : std::true_type
{
};

template<>
struct is_service_response<niryo_one_msgs::srv::EditWorkspace_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_WORKSPACE__TRAITS_HPP_
