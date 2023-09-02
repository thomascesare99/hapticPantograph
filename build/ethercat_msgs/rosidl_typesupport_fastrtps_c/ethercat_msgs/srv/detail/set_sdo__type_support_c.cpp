// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ethercat_msgs:srv/SetSdo.idl
// generated code does not contain a copyright notice
#include "ethercat_msgs/srv/detail/set_sdo__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ethercat_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ethercat_msgs/srv/detail/set_sdo__struct.h"
#include "ethercat_msgs/srv/detail/set_sdo__functions.h"
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

#include "rosidl_runtime_c/string.h"  // sdo_data_type, sdo_value
#include "rosidl_runtime_c/string_functions.h"  // sdo_data_type, sdo_value

// forward declare type support functions


using _SetSdo_Request__ros_msg_type = ethercat_msgs__srv__SetSdo_Request;

static bool _SetSdo_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetSdo_Request__ros_msg_type * ros_message = static_cast<const _SetSdo_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: master_id
  {
    cdr << ros_message->master_id;
  }

  // Field name: slave_position
  {
    cdr << ros_message->slave_position;
  }

  // Field name: sdo_index
  {
    cdr << ros_message->sdo_index;
  }

  // Field name: sdo_subindex
  {
    cdr << ros_message->sdo_subindex;
  }

  // Field name: sdo_data_type
  {
    const rosidl_runtime_c__String * str = &ros_message->sdo_data_type;
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

  // Field name: sdo_value
  {
    const rosidl_runtime_c__String * str = &ros_message->sdo_value;
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

  return true;
}

static bool _SetSdo_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetSdo_Request__ros_msg_type * ros_message = static_cast<_SetSdo_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: master_id
  {
    cdr >> ros_message->master_id;
  }

  // Field name: slave_position
  {
    cdr >> ros_message->slave_position;
  }

  // Field name: sdo_index
  {
    cdr >> ros_message->sdo_index;
  }

  // Field name: sdo_subindex
  {
    cdr >> ros_message->sdo_subindex;
  }

  // Field name: sdo_data_type
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sdo_data_type.data) {
      rosidl_runtime_c__String__init(&ros_message->sdo_data_type);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sdo_data_type,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sdo_data_type'\n");
      return false;
    }
  }

  // Field name: sdo_value
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sdo_value.data) {
      rosidl_runtime_c__String__init(&ros_message->sdo_value);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sdo_value,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sdo_value'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ethercat_msgs
size_t get_serialized_size_ethercat_msgs__srv__SetSdo_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetSdo_Request__ros_msg_type * ros_message = static_cast<const _SetSdo_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name master_id
  {
    size_t item_size = sizeof(ros_message->master_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name slave_position
  {
    size_t item_size = sizeof(ros_message->slave_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sdo_index
  {
    size_t item_size = sizeof(ros_message->sdo_index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sdo_subindex
  {
    size_t item_size = sizeof(ros_message->sdo_subindex);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sdo_data_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sdo_data_type.size + 1);
  // field.name sdo_value
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sdo_value.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _SetSdo_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ethercat_msgs__srv__SetSdo_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ethercat_msgs
size_t max_serialized_size_ethercat_msgs__srv__SetSdo_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: master_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: slave_position
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: sdo_index
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: sdo_subindex
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: sdo_data_type
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
  // member: sdo_value
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

  return current_alignment - initial_alignment;
}

static size_t _SetSdo_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ethercat_msgs__srv__SetSdo_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetSdo_Request = {
  "ethercat_msgs::srv",
  "SetSdo_Request",
  _SetSdo_Request__cdr_serialize,
  _SetSdo_Request__cdr_deserialize,
  _SetSdo_Request__get_serialized_size,
  _SetSdo_Request__max_serialized_size
};

static rosidl_message_type_support_t _SetSdo_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetSdo_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ethercat_msgs, srv, SetSdo_Request)() {
  return &_SetSdo_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ethercat_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ethercat_msgs/srv/detail/set_sdo__struct.h"
// already included above
// #include "ethercat_msgs/srv/detail/set_sdo__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

// already included above
// #include "rosidl_runtime_c/string.h"  // sdo_return_message
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // sdo_return_message

// forward declare type support functions


using _SetSdo_Response__ros_msg_type = ethercat_msgs__srv__SetSdo_Response;

static bool _SetSdo_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SetSdo_Response__ros_msg_type * ros_message = static_cast<const _SetSdo_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  // Field name: sdo_return_message
  {
    const rosidl_runtime_c__String * str = &ros_message->sdo_return_message;
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

  return true;
}

static bool _SetSdo_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SetSdo_Response__ros_msg_type * ros_message = static_cast<_SetSdo_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  // Field name: sdo_return_message
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->sdo_return_message.data) {
      rosidl_runtime_c__String__init(&ros_message->sdo_return_message);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->sdo_return_message,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'sdo_return_message'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ethercat_msgs
size_t get_serialized_size_ethercat_msgs__srv__SetSdo_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SetSdo_Response__ros_msg_type * ros_message = static_cast<const _SetSdo_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name sdo_return_message
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->sdo_return_message.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _SetSdo_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ethercat_msgs__srv__SetSdo_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ethercat_msgs
size_t max_serialized_size_ethercat_msgs__srv__SetSdo_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: sdo_return_message
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

  return current_alignment - initial_alignment;
}

static size_t _SetSdo_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ethercat_msgs__srv__SetSdo_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SetSdo_Response = {
  "ethercat_msgs::srv",
  "SetSdo_Response",
  _SetSdo_Response__cdr_serialize,
  _SetSdo_Response__cdr_deserialize,
  _SetSdo_Response__get_serialized_size,
  _SetSdo_Response__max_serialized_size
};

static rosidl_message_type_support_t _SetSdo_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SetSdo_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ethercat_msgs, srv, SetSdo_Response)() {
  return &_SetSdo_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ethercat_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ethercat_msgs/srv/set_sdo.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SetSdo__callbacks = {
  "ethercat_msgs::srv",
  "SetSdo",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ethercat_msgs, srv, SetSdo_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ethercat_msgs, srv, SetSdo_Response)(),
};

static rosidl_service_type_support_t SetSdo__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &SetSdo__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ethercat_msgs, srv, SetSdo)() {
  return &SetSdo__handle;
}

#if defined(__cplusplus)
}
#endif
