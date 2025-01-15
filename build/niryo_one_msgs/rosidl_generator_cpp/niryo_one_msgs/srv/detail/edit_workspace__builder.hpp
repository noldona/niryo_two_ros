// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from niryo_one_msgs:srv/EditWorkspace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/edit_workspace.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_WORKSPACE__BUILDER_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_WORKSPACE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "niryo_one_msgs/srv/detail/edit_workspace__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_EditWorkspace_Request_pose_3
{
public:
  explicit Init_EditWorkspace_Request_pose_3(::niryo_one_msgs::srv::EditWorkspace_Request & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::EditWorkspace_Request pose_3(::niryo_one_msgs::srv::EditWorkspace_Request::_pose_3_type arg)
  {
    msg_.pose_3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Request msg_;
};

class Init_EditWorkspace_Request_pose_2
{
public:
  explicit Init_EditWorkspace_Request_pose_2(::niryo_one_msgs::srv::EditWorkspace_Request & msg)
  : msg_(msg)
  {}
  Init_EditWorkspace_Request_pose_3 pose_2(::niryo_one_msgs::srv::EditWorkspace_Request::_pose_2_type arg)
  {
    msg_.pose_2 = std::move(arg);
    return Init_EditWorkspace_Request_pose_3(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Request msg_;
};

class Init_EditWorkspace_Request_pose_1
{
public:
  explicit Init_EditWorkspace_Request_pose_1(::niryo_one_msgs::srv::EditWorkspace_Request & msg)
  : msg_(msg)
  {}
  Init_EditWorkspace_Request_pose_2 pose_1(::niryo_one_msgs::srv::EditWorkspace_Request::_pose_1_type arg)
  {
    msg_.pose_1 = std::move(arg);
    return Init_EditWorkspace_Request_pose_2(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Request msg_;
};

class Init_EditWorkspace_Request_pose_origin
{
public:
  explicit Init_EditWorkspace_Request_pose_origin(::niryo_one_msgs::srv::EditWorkspace_Request & msg)
  : msg_(msg)
  {}
  Init_EditWorkspace_Request_pose_1 pose_origin(::niryo_one_msgs::srv::EditWorkspace_Request::_pose_origin_type arg)
  {
    msg_.pose_origin = std::move(arg);
    return Init_EditWorkspace_Request_pose_1(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Request msg_;
};

class Init_EditWorkspace_Request_name
{
public:
  explicit Init_EditWorkspace_Request_name(::niryo_one_msgs::srv::EditWorkspace_Request & msg)
  : msg_(msg)
  {}
  Init_EditWorkspace_Request_pose_origin name(::niryo_one_msgs::srv::EditWorkspace_Request::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_EditWorkspace_Request_pose_origin(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Request msg_;
};

class Init_EditWorkspace_Request_cmd
{
public:
  Init_EditWorkspace_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EditWorkspace_Request_name cmd(::niryo_one_msgs::srv::EditWorkspace_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return Init_EditWorkspace_Request_name(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::EditWorkspace_Request>()
{
  return niryo_one_msgs::srv::builder::Init_EditWorkspace_Request_cmd();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_EditWorkspace_Response_message
{
public:
  explicit Init_EditWorkspace_Response_message(::niryo_one_msgs::srv::EditWorkspace_Response & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::EditWorkspace_Response message(::niryo_one_msgs::srv::EditWorkspace_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Response msg_;
};

class Init_EditWorkspace_Response_status
{
public:
  Init_EditWorkspace_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EditWorkspace_Response_message status(::niryo_one_msgs::srv::EditWorkspace_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_EditWorkspace_Response_message(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::EditWorkspace_Response>()
{
  return niryo_one_msgs::srv::builder::Init_EditWorkspace_Response_status();
}

}  // namespace niryo_one_msgs


namespace niryo_one_msgs
{

namespace srv
{

namespace builder
{

class Init_EditWorkspace_Event_response
{
public:
  explicit Init_EditWorkspace_Event_response(::niryo_one_msgs::srv::EditWorkspace_Event & msg)
  : msg_(msg)
  {}
  ::niryo_one_msgs::srv::EditWorkspace_Event response(::niryo_one_msgs::srv::EditWorkspace_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Event msg_;
};

class Init_EditWorkspace_Event_request
{
public:
  explicit Init_EditWorkspace_Event_request(::niryo_one_msgs::srv::EditWorkspace_Event & msg)
  : msg_(msg)
  {}
  Init_EditWorkspace_Event_response request(::niryo_one_msgs::srv::EditWorkspace_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_EditWorkspace_Event_response(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Event msg_;
};

class Init_EditWorkspace_Event_info
{
public:
  Init_EditWorkspace_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EditWorkspace_Event_request info(::niryo_one_msgs::srv::EditWorkspace_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_EditWorkspace_Event_request(msg_);
  }

private:
  ::niryo_one_msgs::srv::EditWorkspace_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::niryo_one_msgs::srv::EditWorkspace_Event>()
{
  return niryo_one_msgs::srv::builder::Init_EditWorkspace_Event_info();
}

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__EDIT_WORKSPACE__BUILDER_HPP_
