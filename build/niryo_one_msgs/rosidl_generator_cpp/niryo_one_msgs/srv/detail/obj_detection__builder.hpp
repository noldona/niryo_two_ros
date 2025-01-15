// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/ObjDetection.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/obj_detection.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/obj_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ObjDetection_Request_ret_image
{
public:
  explicit Init_ObjDetection_Request_ret_image(::niryo_one_msgs::srv::ObjDetection_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ObjDetection_Request ret_image(::niryo_one_msgs::srv::ObjDetection_Request::_ret_image_type arg)
  {
    msg_.ret_image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Request msg_;
};

class Init_ObjDetection_Request_workspace_ratio
{
public:
  explicit Init_ObjDetection_Request_workspace_ratio(::niryo_one_msgs::srv::ObjDetection_Request & msg)
  : msg_(msg)
  {}
  Init_ObjDetection_Request_ret_image workspace_ratio(::niryo_one_msgs::srv::ObjDetection_Request::_workspace_ratio_type arg)
  {
    msg_.workspace_ratio = std::move(arg);
    return Init_ObjDetection_Request_ret_image(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Request msg_;
};

class Init_ObjDetection_Request_obj_color
{
public:
  explicit Init_ObjDetection_Request_obj_color(::niryo_one_msgs::srv::ObjDetection_Request & msg)
  : msg_(msg)
  {}
  Init_ObjDetection_Request_workspace_ratio obj_color(::niryo_one_msgs::srv::ObjDetection_Request::_obj_color_type arg)
  {
    msg_.obj_color = std::move(arg);
    return Init_ObjDetection_Request_workspace_ratio(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Request msg_;
};

class Init_ObjDetection_Request_obj_type
{
public:
  Init_ObjDetection_Request_obj_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjDetection_Request_obj_color obj_type(::niryo_one_msgs::srv::ObjDetection_Request::_obj_type_type arg)
  {
    msg_.obj_type = std::move(arg);
    return Init_ObjDetection_Request_obj_color(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ObjDetection_Request>()
{
  return niryo_one_msgs::srv::builder::Init_ObjDetection_Request_obj_type();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ObjDetection_Response_img
{
public:
  explicit Init_ObjDetection_Response_img(::niryo_one_msgs::srv::ObjDetection_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ObjDetection_Response img(::niryo_one_msgs::srv::ObjDetection_Response::_img_type arg)
  {
    msg_.img = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Response msg_;
};

class Init_ObjDetection_Response_obj_color
{
public:
  explicit Init_ObjDetection_Response_obj_color(::niryo_one_msgs::srv::ObjDetection_Response & msg)
  : msg_(msg)
  {}
  Init_ObjDetection_Response_img obj_color(::niryo_one_msgs::srv::ObjDetection_Response::_obj_color_type arg)
  {
    msg_.obj_color = std::move(arg);
    return Init_ObjDetection_Response_img(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Response msg_;
};

class Init_ObjDetection_Response_obj_type
{
public:
  explicit Init_ObjDetection_Response_obj_type(::niryo_one_msgs::srv::ObjDetection_Response & msg)
  : msg_(msg)
  {}
  Init_ObjDetection_Response_obj_color obj_type(::niryo_one_msgs::srv::ObjDetection_Response::_obj_type_type arg)
  {
    msg_.obj_type = std::move(arg);
    return Init_ObjDetection_Response_obj_color(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Response msg_;
};

class Init_ObjDetection_Response_obj_pose
{
public:
  explicit Init_ObjDetection_Response_obj_pose(::niryo_one_msgs::srv::ObjDetection_Response & msg)
  : msg_(msg)
  {}
  Init_ObjDetection_Response_obj_type obj_pose(::niryo_one_msgs::srv::ObjDetection_Response::_obj_pose_type arg)
  {
    msg_.obj_pose = std::move(arg);
    return Init_ObjDetection_Response_obj_type(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Response msg_;
};

class Init_ObjDetection_Response_status
{
public:
  Init_ObjDetection_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjDetection_Response_obj_pose status(::niryo_one_msgs::srv::ObjDetection_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ObjDetection_Response_obj_pose(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ObjDetection_Response>()
{
  return niryo_one_msgs::srv::builder::Init_ObjDetection_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_ObjDetection_Event_response
{
public:
  explicit Init_ObjDetection_Event_response(::niryo_one_msgs::srv::ObjDetection_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::ObjDetection_Event response(::niryo_one_msgs::srv::ObjDetection_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Event msg_;
};

class Init_ObjDetection_Event_request
{
public:
  explicit Init_ObjDetection_Event_request(::niryo_one_msgs::srv::ObjDetection_Event & msg)
  : msg_(msg)
  {}
  Init_ObjDetection_Event_response request(::niryo_one_msgs::srv::ObjDetection_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ObjDetection_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Event msg_;
};

class Init_ObjDetection_Event_info
{
public:
  Init_ObjDetection_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjDetection_Event_request info(::niryo_one_msgs::srv::ObjDetection_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ObjDetection_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::ObjDetection_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::ObjDetection_Event>()
{
  return niryo_one_msgs::srv::builder::Init_ObjDetection_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__OBJ_DETECTION__BUILDER_HPP_
