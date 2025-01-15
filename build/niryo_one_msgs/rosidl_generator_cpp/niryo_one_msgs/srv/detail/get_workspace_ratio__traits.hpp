// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:srv/GetWorkspaceRatio.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_workspace_ratio.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_RATIO__TRAITS_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_RATIO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/srv/detail/get_workspace_ratio__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWorkspaceRatio_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: workspace
  {
    out << "workspace: ";
    rosidl_generator_traits::value_to_yaml(msg.workspace, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetWorkspaceRatio_Request & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetWorkspaceRatio_Request & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::GetWorkspaceRatio_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::GetWorkspaceRatio_Request & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::GetWorkspaceRatio_Request>()
{
  return "niryo_one_msgs::srv::GetWorkspaceRatio_Request";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetWorkspaceRatio_Request>()
{
  return "niryo_one_msgs/srv/GetWorkspaceRatio_Request";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetWorkspaceRatio_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::srv::GetWorkspaceRatio_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetWorkspaceRatio_Response & msg,
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

  // member: ratio
  {
    out << "ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.ratio, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetWorkspaceRatio_Response & msg,
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

  // member: ratio
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ratio: ";
    rosidl_generator_traits::value_to_yaml(msg.ratio, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetWorkspaceRatio_Response & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::GetWorkspaceRatio_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::GetWorkspaceRatio_Response & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::GetWorkspaceRatio_Response>()
{
  return "niryo_one_msgs::srv::GetWorkspaceRatio_Response";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetWorkspaceRatio_Response>()
{
  return "niryo_one_msgs/srv/GetWorkspaceRatio_Response";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetWorkspaceRatio_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<niryo_one_msgs::srv::GetWorkspaceRatio_Response>
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
  const GetWorkspaceRatio_Event & msg,
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
  const GetWorkspaceRatio_Event & msg,
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

inline std::string to_yaml(const GetWorkspaceRatio_Event & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::GetWorkspaceRatio_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::GetWorkspaceRatio_Event & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::GetWorkspaceRatio_Event>()
{
  return "niryo_one_msgs::srv::GetWorkspaceRatio_Event";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetWorkspaceRatio_Event>()
{
  return "niryo_one_msgs/srv/GetWorkspaceRatio_Event";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetWorkspaceRatio_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio_Event>
  : std::integral_constant<bool, has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio_Request>::value && has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<niryo_one_msgs::srv::GetWorkspaceRatio_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<niryo_one_msgs::srv::GetWorkspaceRatio>()
{
  return "niryo_one_msgs::srv::GetWorkspaceRatio";
}

template<>
inline const char * name<niryo_one_msgs::srv::GetWorkspaceRatio>()
{
  return "niryo_one_msgs/srv/GetWorkspaceRatio";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::GetWorkspaceRatio>
  : std::integral_constant<
    bool,
    has_fixed_size<niryo_one_msgs::srv::GetWorkspaceRatio_Request>::value &&
    has_fixed_size<niryo_one_msgs::srv::GetWorkspaceRatio_Response>::value
  >
{
};

template<>
struct has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio>
  : std::integral_constant<
    bool,
    has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio_Request>::value &&
    has_bounded_size<niryo_one_msgs::srv::GetWorkspaceRatio_Response>::value
  >
{
};

template<>
struct is_service<niryo_one_msgs::srv::GetWorkspaceRatio>
  : std::true_type
{
};

template<>
struct is_service_request<niryo_one_msgs::srv::GetWorkspaceRatio_Request>
  : std::true_type
{
};

template<>
struct is_service_response<niryo_one_msgs::srv::GetWorkspaceRatio_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_WORKSPACE_RATIO__TRAITS_HPP_
