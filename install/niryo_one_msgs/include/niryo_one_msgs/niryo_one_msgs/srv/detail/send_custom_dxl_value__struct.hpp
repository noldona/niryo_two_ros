// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:srv/SendCustomDxlValue.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/srv/send_custom_dxl_value.hpp"


#ifndef NIRYO_ONE_MSGS__SRV__DETAIL__SEND_CUSTOM_DXL_VALUE__STRUCT_HPP_
#define NIRYO_ONE_MSGS__SRV__DETAIL__SEND_CUSTOM_DXL_VALUE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Request __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Request __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendCustomDxlValue_Request_
{
  using Type = SendCustomDxlValue_Request_<ContainerAllocator>;

  explicit SendCustomDxlValue_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_type = 0l;
      this->id = 0;
      this->value = 0l;
      this->reg_address = 0l;
      this->byte_number = 0l;
    }
  }

  explicit SendCustomDxlValue_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_type = 0l;
      this->id = 0;
      this->value = 0l;
      this->reg_address = 0l;
      this->byte_number = 0l;
    }
  }

  // field types and members
  using _motor_type_type =
    int32_t;
  _motor_type_type motor_type;
  using _id_type =
    uint8_t;
  _id_type id;
  using _value_type =
    int32_t;
  _value_type value;
  using _reg_address_type =
    int32_t;
  _reg_address_type reg_address;
  using _byte_number_type =
    int32_t;
  _byte_number_type byte_number;

  // setters for named parameter idiom
  Type & set__motor_type(
    const int32_t & _arg)
  {
    this->motor_type = _arg;
    return *this;
  }
  Type & set__id(
    const uint8_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__value(
    const int32_t & _arg)
  {
    this->value = _arg;
    return *this;
  }
  Type & set__reg_address(
    const int32_t & _arg)
  {
    this->reg_address = _arg;
    return *this;
  }
  Type & set__byte_number(
    const int32_t & _arg)
  {
    this->byte_number = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Request
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Request
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendCustomDxlValue_Request_ & other) const
  {
    if (this->motor_type != other.motor_type) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    if (this->reg_address != other.reg_address) {
      return false;
    }
    if (this->byte_number != other.byte_number) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendCustomDxlValue_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendCustomDxlValue_Request_

// alias to use template instance with default allocator
using SendCustomDxlValue_Request =
  niryo_one_msgs::srv::SendCustomDxlValue_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Response __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Response __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendCustomDxlValue_Response_
{
  using Type = SendCustomDxlValue_Response_<ContainerAllocator>;

  explicit SendCustomDxlValue_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0l;
      this->message = "";
    }
  }

  explicit SendCustomDxlValue_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
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

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Response
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Response
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendCustomDxlValue_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendCustomDxlValue_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendCustomDxlValue_Response_

// alias to use template instance with default allocator
using SendCustomDxlValue_Response =
  niryo_one_msgs::srv::SendCustomDxlValue_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Event __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Event __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendCustomDxlValue_Event_
{
  using Type = SendCustomDxlValue_Event_<ContainerAllocator>;

  explicit SendCustomDxlValue_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SendCustomDxlValue_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::SendCustomDxlValue_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<niryo_one_msgs::srv::SendCustomDxlValue_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Event
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__srv__SendCustomDxlValue_Event
    std::shared_ptr<niryo_one_msgs::srv::SendCustomDxlValue_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendCustomDxlValue_Event_ & other) const
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
  bool operator!=(const SendCustomDxlValue_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendCustomDxlValue_Event_

// alias to use template instance with default allocator
using SendCustomDxlValue_Event =
  niryo_one_msgs::srv::SendCustomDxlValue_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace niryo_one_msgs

namespace niryo_one_msgs
{

namespace srv
{

struct SendCustomDxlValue
{
  using Request = niryo_one_msgs::srv::SendCustomDxlValue_Request;
  using Response = niryo_one_msgs::srv::SendCustomDxlValue_Response;
  using Event = niryo_one_msgs::srv::SendCustomDxlValue_Event;
};

}  // namespace srv

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__SRV__DETAIL__SEND_CUSTOM_DXL_VALUE__STRUCT_HPP_
