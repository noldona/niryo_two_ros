// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:srv/ManagePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/manage_position.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__STRUCT_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "niryo_one_msgs/msg/detail/position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__ManagePosition_Request __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__ManagePosition_Request __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ManagePosition_Request_
{
  using Type = ManagePosition_Request_<ContainerAllocator>;

  explicit ManagePosition_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_type = 0l;
      this->position_name = "";
    }
  }

  explicit ManagePosition_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position_name(_alloc),
    position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd_type = 0l;
      this->position_name = "";
    }
  }

  // field types and members
  using _cmd_type_type =
    int32_t;
  _cmd_type_type cmd_type;
  using _position_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _position_name_type position_name;
  using _position_type =
    niryo_one_msgs::msg::Position_<ContainerAllocator>;
  _position_type position;

  // setters for named parameter idiom
  Type & set__cmd_type(
    const int32_t & _arg)
  {
    this->cmd_type = _arg;
    return *this;
  }
  Type & set__position_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->position_name = _arg;
    return *this;
  }
  Type & set__position(
    const niryo_one_msgs::msg::Position_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__ManagePosition_Request
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__ManagePosition_Request
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ManagePosition_Request_ & other) const
  {
    if (this->cmd_type != other.cmd_type) {
      return false;
    }
    if (this->position_name != other.position_name) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const ManagePosition_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ManagePosition_Request_

// alias to use template instance with default allocator
using ManagePosition_Request =
  niryo_one_msgs::srv::ManagePosition_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'position'
// already included above
// #include "niryo_one_msgs/msg/detail/position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__ManagePosition_Response __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__ManagePosition_Response __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ManagePosition_Response_
{
  using Type = ManagePosition_Response_<ContainerAllocator>;

  explicit ManagePosition_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->message = "";
    }
  }

  explicit ManagePosition_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    position(_alloc, _init)
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
  using _position_type =
    niryo_one_msgs::msg::Position_<ContainerAllocator>;
  _position_type position;

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
  Type & set__position(
    const niryo_one_msgs::msg::Position_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__ManagePosition_Response
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__ManagePosition_Response
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ManagePosition_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const ManagePosition_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ManagePosition_Response_

// alias to use template instance with default allocator
using ManagePosition_Response =
  niryo_one_msgs::srv::ManagePosition_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__ManagePosition_Event __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__ManagePosition_Event __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ManagePosition_Event_
{
  using Type = ManagePosition_Event_<ContainerAllocator>;

  explicit ManagePosition_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ManagePosition_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ManagePosition_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::ManagePosition_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__ManagePosition_Event
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__ManagePosition_Event
    std::shared_ptr<niryo_one_msgs::srv::ManagePosition_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ManagePosition_Event_ & other) const
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
  bool operator!=(const ManagePosition_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ManagePosition_Event_

// alias to use template instance with default allocator
using ManagePosition_Event =
  niryo_one_msgs::srv::ManagePosition_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs

namespace niryo_one_msgs
{

namespace srv
{

struct ManagePosition
{
  using Request = niryo_one_msgs::srv::ManagePosition_Request;
  using Response = niryo_one_msgs::srv::ManagePosition_Response;
  using Event = niryo_one_msgs::srv::ManagePosition_Event;
};

}  // namespace srv

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__MANAGE_POSITION__STRUCT_HPP_
