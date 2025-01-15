// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from niryo_one_msgs:msg/SoftwareVersion.idl
// generated code does not contain a copyright notice
#include "niryo_one_msgs/msg/detail/software_version__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "niryo_one_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "niryo_one_msgs/msg/detail/software_version__struct.h"
#include "niryo_one_msgs/msg/detail/software_version__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // motor_names, ros_niryo_one_version, rpi_image_version, stepper_firmware_versions
#include "rosidl_runtime_c/string_functions.h"  // motor_names, ros_niryo_one_version, rpi_image_version, stepper_firmware_versions

// forward declare type support functions


using _SoftwareVersion__ros_msg_type = niryo_one_msgs__msg__SoftwareVersion;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_niryo_one_msgs__msg__SoftwareVersion(
  const niryo_one_msgs__msg__SoftwareVersion * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: rpi_image_version
  {
    const rosidl_runtime_c__String * str = &ros_message->rpi_image_version;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: ros_niryo_one_version
  {
    const rosidl_runtime_c__String * str = &ros_message->ros_niryo_one_version;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: motor_names
  {
    size_t size = ros_message->motor_names.size;
    auto array_ptr = ros_message->motor_names.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: stepper_firmware_versions
  {
    size_t size = ros_message->stepper_firmware_versions.size;
    auto array_ptr = ros_message->stepper_firmware_versions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_deserialize_niryo_one_msgs__msg__SoftwareVersion(
  eprosima::fastcdr::Cdr & cdr,
  niryo_one_msgs__msg__SoftwareVersion * ros_message)
{
  // Field name: rpi_image_version
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->rpi_image_version.data) {
      rosidl_runtime_c__String__init(&ros_message->rpi_image_version);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->rpi_image_version,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'rpi_image_version'\n");
      return false;
    }
  }

  // Field name: ros_niryo_one_version
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ros_niryo_one_version.data) {
      rosidl_runtime_c__String__init(&ros_message->ros_niryo_one_version);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ros_niryo_one_version,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ros_niryo_one_version'\n");
      return false;
    }
  }

  // Field name: motor_names
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->motor_names.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->motor_names);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->motor_names, size)) {
      fprintf(stderr, "failed to create array for field 'motor_names'");
      return false;
    }
    auto array_ptr = ros_message->motor_names.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'motor_names'\n");
        return false;
      }
    }
  }

  // Field name: stepper_firmware_versions
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->stepper_firmware_versions.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->stepper_firmware_versions);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->stepper_firmware_versions, size)) {
      fprintf(stderr, "failed to create array for field 'stepper_firmware_versions'");
      return false;
    }
    auto array_ptr = ros_message->stepper_firmware_versions.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'stepper_firmware_versions'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_niryo_one_msgs__msg__SoftwareVersion(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SoftwareVersion__ros_msg_type * ros_message = static_cast<const _SoftwareVersion__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: rpi_image_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->rpi_image_version.size + 1);

  // Field name: ros_niryo_one_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ros_niryo_one_version.size + 1);

  // Field name: motor_names
  {
    size_t array_size = ros_message->motor_names.size;
    auto array_ptr = ros_message->motor_names.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  // Field name: stepper_firmware_versions
  {
    size_t array_size = ros_message->stepper_firmware_versions.size;
    auto array_ptr = ros_message->stepper_firmware_versions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_niryo_one_msgs__msg__SoftwareVersion(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: rpi_image_version
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: ros_niryo_one_version
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: motor_names
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: stepper_firmware_versions
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs__msg__SoftwareVersion;
    is_plain =
      (
      offsetof(DataType, stepper_firmware_versions) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
bool cdr_serialize_key_niryo_one_msgs__msg__SoftwareVersion(
  const niryo_one_msgs__msg__SoftwareVersion * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: rpi_image_version
  {
    const rosidl_runtime_c__String * str = &ros_message->rpi_image_version;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: ros_niryo_one_version
  {
    const rosidl_runtime_c__String * str = &ros_message->ros_niryo_one_version;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: motor_names
  {
    size_t size = ros_message->motor_names.size;
    auto array_ptr = ros_message->motor_names.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: stepper_firmware_versions
  {
    size_t size = ros_message->stepper_firmware_versions.size;
    auto array_ptr = ros_message->stepper_firmware_versions.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t get_serialized_size_key_niryo_one_msgs__msg__SoftwareVersion(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SoftwareVersion__ros_msg_type * ros_message = static_cast<const _SoftwareVersion__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: rpi_image_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->rpi_image_version.size + 1);

  // Field name: ros_niryo_one_version
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ros_niryo_one_version.size + 1);

  // Field name: motor_names
  {
    size_t array_size = ros_message->motor_names.size;
    auto array_ptr = ros_message->motor_names.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  // Field name: stepper_firmware_versions
  {
    size_t array_size = ros_message->stepper_firmware_versions.size;
    auto array_ptr = ros_message->stepper_firmware_versions.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_niryo_one_msgs
size_t max_serialized_size_key_niryo_one_msgs__msg__SoftwareVersion(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: rpi_image_version
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: ros_niryo_one_version
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: motor_names
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: stepper_firmware_versions
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = niryo_one_msgs__msg__SoftwareVersion;
    is_plain =
      (
      offsetof(DataType, stepper_firmware_versions) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _SoftwareVersion__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const niryo_one_msgs__msg__SoftwareVersion * ros_message = static_cast<const niryo_one_msgs__msg__SoftwareVersion *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_niryo_one_msgs__msg__SoftwareVersion(ros_message, cdr);
}

static bool _SoftwareVersion__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  niryo_one_msgs__msg__SoftwareVersion * ros_message = static_cast<niryo_one_msgs__msg__SoftwareVersion *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_niryo_one_msgs__msg__SoftwareVersion(cdr, ros_message);
}

static uint32_t _SoftwareVersion__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_niryo_one_msgs__msg__SoftwareVersion(
      untyped_ros_message, 0));
}

static size_t _SoftwareVersion__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_niryo_one_msgs__msg__SoftwareVersion(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SoftwareVersion = {
  "niryo_one_msgs::msg",
  "SoftwareVersion",
  _SoftwareVersion__cdr_serialize,
  _SoftwareVersion__cdr_deserialize,
  _SoftwareVersion__get_serialized_size,
  _SoftwareVersion__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SoftwareVersion__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SoftwareVersion,
  get_message_typesupport_handle_function,
  &niryo_one_msgs__msg__SoftwareVersion__get_type_hash,
  &niryo_one_msgs__msg__SoftwareVersion__get_type_description,
  &niryo_one_msgs__msg__SoftwareVersion__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, niryo_one_msgs, msg, SoftwareVersion)() {
  return &_SoftwareVersion__type_support;
}

#if defined(__cplusplus)
}
#endif
