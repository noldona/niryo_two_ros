// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:srv/GetTargetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/get_target_pose.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__STRUCT_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Request __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetTargetPose_Request_
{
  using Type = GetTargetPose_Request_<ContainerAllocator>;

  explicit GetTargetPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->workspace = "";
      this->grip = "";
      this->tool_id = 0l;
      this->height_offset = 0.0f;
      this->x_rel = 0.0f;
      this->y_rel = 0.0f;
      this->yaw_rel = 0.0f;
    }
  }

  explicit GetTargetPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : workspace(_alloc),
    grip(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->workspace = "";
      this->grip = "";
      this->tool_id = 0l;
      this->height_offset = 0.0f;
      this->x_rel = 0.0f;
      this->y_rel = 0.0f;
      this->yaw_rel = 0.0f;
    }
  }

  // field types and members
  using _workspace_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _workspace_type workspace;
  using _grip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _grip_type grip;
  using _tool_id_type =
    int32_t;
  _tool_id_type tool_id;
  using _height_offset_type =
    float;
  _height_offset_type height_offset;
  using _x_rel_type =
    float;
  _x_rel_type x_rel;
  using _y_rel_type =
    float;
  _y_rel_type y_rel;
  using _yaw_rel_type =
    float;
  _yaw_rel_type yaw_rel;

  // setters for named parameter idiom
  Type & set__workspace(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->workspace = _arg;
    return *this;
  }
  Type & set__grip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->grip = _arg;
    return *this;
  }
  Type & set__tool_id(
    const int32_t & _arg)
  {
    this->tool_id = _arg;
    return *this;
  }
  Type & set__height_offset(
    const float & _arg)
  {
    this->height_offset = _arg;
    return *this;
  }
  Type & set__x_rel(
    const float & _arg)
  {
    this->x_rel = _arg;
    return *this;
  }
  Type & set__y_rel(
    const float & _arg)
  {
    this->y_rel = _arg;
    return *this;
  }
  Type & set__yaw_rel(
    const float & _arg)
  {
    this->yaw_rel = _arg;
    return *this;
  }

  // constant declarations
  static const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> GRIP_AUTO;

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Request
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Request
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetTargetPose_Request_ & other) const
  {
    if (this->workspace != other.workspace) {
      return false;
    }
    if (this->grip != other.grip) {
      return false;
    }
    if (this->tool_id != other.tool_id) {
      return false;
    }
    if (this->height_offset != other.height_offset) {
      return false;
    }
    if (this->x_rel != other.x_rel) {
      return false;
    }
    if (this->y_rel != other.y_rel) {
      return false;
    }
    if (this->yaw_rel != other.yaw_rel) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetTargetPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetTargetPose_Request_

// alias to use template instance with default allocator
using GetTargetPose_Request =
  niryo_one_msgs::srv::GetTargetPose_Request_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>
GetTargetPose_Request_<ContainerAllocator>::GRIP_AUTO = "auto";

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'target_pose'
#include "niryo_one_msgs/msg/detail/robot_state__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Response __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetTargetPose_Response_
{
  using Type = GetTargetPose_Response_<ContainerAllocator>;

  explicit GetTargetPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->message = "";
    }
  }

  explicit GetTargetPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    target_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->message = "";
    }
  }

  // field types and members
  using _status_type =
    int32_t;
  _status_type status;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _target_pose_type =
    niryo_one_msgs::msg::RobotState_<ContainerAllocator>;
  _target_pose_type target_pose;

  // setters for named parameter idiom
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__target_pose(
    const niryo_one_msgs::msg::RobotState_<ContainerAllocator> & _arg)
  {
    this->target_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Response
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Response
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetTargetPose_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->target_pose != other.target_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetTargetPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetTargetPose_Response_

// alias to use template instance with default allocator
using GetTargetPose_Response =
  niryo_one_msgs::srv::GetTargetPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Event __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Event __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetTargetPose_Event_
{
  using Type = GetTargetPose_Event_<ContainerAllocator>;

  explicit GetTargetPose_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetTargetPose_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetTargetPose_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::GetTargetPose_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Event
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__GetTargetPose_Event
    std::shared_ptr<niryo_one_msgs::srv::GetTargetPose_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetTargetPose_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetTargetPose_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetTargetPose_Event_

// alias to use template instance with default allocator
using GetTargetPose_Event =
  niryo_one_msgs::srv::GetTargetPose_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs

namespace niryo_one_msgs
{

namespace srv
{

struct GetTargetPose
{
  using Request = niryo_one_msgs::srv::GetTargetPose_Request;
  using Response = niryo_one_msgs::srv::GetTargetPose_Response;
  using Event = niryo_one_msgs::srv::GetTargetPose_Event;
};

}  // namespace srv

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__GET_TARGET_POSE__STRUCT_HPP_
