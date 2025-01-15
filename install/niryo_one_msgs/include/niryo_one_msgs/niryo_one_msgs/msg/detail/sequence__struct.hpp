// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from niryo_one_msgs:msg/Sequence.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "niryo_one_msgs/msg/sequence.hpp"


#ifndef NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__STRUCT_HPP_
#define NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__niryo_one_msgs__msg__Sequence __attribute__((deprecated))
#else
# define DEPRECATED__niryo_one_msgs__msg__Sequence __declspec(deprecated)
#endif

namespace niryo_one_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Sequence_
{
  using Type = Sequence_<ContainerAllocator>;

  explicit Sequence_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->name = "";
      this->description = "";
      this->created = 0l;
      this->updated = 0l;
      this->blockly_xml = "";
      this->python_code = "";
    }
  }

  explicit Sequence_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : name(_alloc),
    description(_alloc),
    blockly_xml(_alloc),
    python_code(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->name = "";
      this->description = "";
      this->created = 0l;
      this->updated = 0l;
      this->blockly_xml = "";
      this->python_code = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _name_type name;
  using _description_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _description_type description;
  using _created_type =
    int32_t;
  _created_type created;
  using _updated_type =
    int32_t;
  _updated_type updated;
  using _blockly_xml_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _blockly_xml_type blockly_xml;
  using _python_code_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _python_code_type python_code;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->name = _arg;
    return *this;
  }
  Type & set__description(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->description = _arg;
    return *this;
  }
  Type & set__created(
    const int32_t & _arg)
  {
    this->created = _arg;
    return *this;
  }
  Type & set__updated(
    const int32_t & _arg)
  {
    this->updated = _arg;
    return *this;
  }
  Type & set__blockly_xml(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->blockly_xml = _arg;
    return *this;
  }
  Type & set__python_code(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->python_code = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    niryo_one_msgs::msg::Sequence_<ContainerAllocator> *;
  using ConstRawPtr =
    const niryo_one_msgs::msg::Sequence_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::Sequence_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      niryo_one_msgs::msg::Sequence_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__niryo_one_msgs__msg__Sequence
    std::shared_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__niryo_one_msgs__msg__Sequence
    std::shared_ptr<niryo_one_msgs::msg::Sequence_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Sequence_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->name != other.name) {
      return false;
    }
    if (this->description != other.description) {
      return false;
    }
    if (this->created != other.created) {
      return false;
    }
    if (this->updated != other.updated) {
      return false;
    }
    if (this->blockly_xml != other.blockly_xml) {
      return false;
    }
    if (this->python_code != other.python_code) {
      return false;
    }
    return true;
  }
  bool operator!=(const Sequence_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Sequence_

// alias to use template instance with default allocator
using Sequence =
  niryo_one_msgs::msg::Sequence_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace niryo_one_msgs

#endif  // NIRYO_ONE_MSGS__MSG__DETAIL__SEQUENCE__STRUCT_HPP_
