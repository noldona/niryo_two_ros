// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from niryo_one_msgs:srv/DebugMarkers.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/debug_markers.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__DEBUG_MARKERS__TRAITS_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__DEBUG_MARKERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "niryo_one_msgs/srv/detail/debug_markers__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DebugMarkers_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DebugMarkers_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DebugMarkers_Request & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::DebugMarkers_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::DebugMarkers_Request & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::DebugMarkers_Request>()
{
  return "niryo_one_msgs::srv::DebugMarkers_Request";
}

template<>
inline const char * name<niryo_one_msgs::srv::DebugMarkers_Request>()
{
  return "niryo_one_msgs/srv/DebugMarkers_Request";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::DebugMarkers_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::DebugMarkers_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<niryo_one_msgs::srv::DebugMarkers_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'img'
#include "sensor_msgs/msg/detail/compressed_image__traits.hpp"

namespace niryo_one_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const DebugMarkers_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: markers_detected
  {
    out << "markers_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.markers_detected, out);
    out << ", ";
  }

  // member: img
  {
    out << "img: ";
    to_flow_style_yaml(msg.img, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DebugMarkers_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: markers_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "markers_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.markers_detected, out);
    out << "\n";
  }

  // member: img
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "img:\n";
    to_block_style_yaml(msg.img, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DebugMarkers_Response & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::DebugMarkers_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::DebugMarkers_Response & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::DebugMarkers_Response>()
{
  return "niryo_one_msgs::srv::DebugMarkers_Response";
}

template<>
inline const char * name<niryo_one_msgs::srv::DebugMarkers_Response>()
{
  return "niryo_one_msgs/srv/DebugMarkers_Response";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::DebugMarkers_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::CompressedImage>::value> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::DebugMarkers_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::CompressedImage>::value> {};

template<>
struct is_message<niryo_one_msgs::srv::DebugMarkers_Response>
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
  const DebugMarkers_Event & msg,
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
  const DebugMarkers_Event & msg,
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

inline std::string to_yaml(const DebugMarkers_Event & msg, bool use_flow_style = false)
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
  const niryo_one_msgs::srv::DebugMarkers_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  niryo_one_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use niryo_one_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const niryo_one_msgs::srv::DebugMarkers_Event & msg)
{
  return niryo_one_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<niryo_one_msgs::srv::DebugMarkers_Event>()
{
  return "niryo_one_msgs::srv::DebugMarkers_Event";
}

template<>
inline const char * name<niryo_one_msgs::srv::DebugMarkers_Event>()
{
  return "niryo_one_msgs/srv/DebugMarkers_Event";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::DebugMarkers_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<niryo_one_msgs::srv::DebugMarkers_Event>
  : std::integral_constant<bool, has_bounded_size<niryo_one_msgs::srv::DebugMarkers_Request>::value && has_bounded_size<niryo_one_msgs::srv::DebugMarkers_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<niryo_one_msgs::srv::DebugMarkers_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<niryo_one_msgs::srv::DebugMarkers>()
{
  return "niryo_one_msgs::srv::DebugMarkers";
}

template<>
inline const char * name<niryo_one_msgs::srv::DebugMarkers>()
{
  return "niryo_one_msgs/srv/DebugMarkers";
}

template<>
struct has_fixed_size<niryo_one_msgs::srv::DebugMarkers>
  : std::integral_constant<
    bool,
    has_fixed_size<niryo_one_msgs::srv::DebugMarkers_Request>::value &&
    has_fixed_size<niryo_one_msgs::srv::DebugMarkers_Response>::value
  >
{
};

template<>
struct has_bounded_size<niryo_one_msgs::srv::DebugMarkers>
  : std::integral_constant<
    bool,
    has_bounded_size<niryo_one_msgs::srv::DebugMarkers_Request>::value &&
    has_bounded_size<niryo_one_msgs::srv::DebugMarkers_Response>::value
  >
{
};

template<>
struct is_service<niryo_one_msgs::srv::DebugMarkers>
  : std::true_type
{
};

template<>
struct is_service_request<niryo_one_msgs::srv::DebugMarkers_Request>
  : std::true_type
{
};

template<>
struct is_service_response<niryo_one_msgs::srv::DebugMarkers_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__DEBUG_MARKERS__TRAITS_HPP_
