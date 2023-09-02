// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ethercat_msgs:srv/SetSdo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ethercat_msgs/srv/detail/set_sdo__rosidl_typesupport_introspection_c.h"
#include "ethercat_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ethercat_msgs/srv/detail/set_sdo__functions.h"
#include "ethercat_msgs/srv/detail/set_sdo__struct.h"


// Include directives for member types
// Member `sdo_data_type`
// Member `sdo_value`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ethercat_msgs__srv__SetSdo_Request__init(message_memory);
}

void ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_fini_function(void * message_memory)
{
  ethercat_msgs__srv__SetSdo_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_member_array[6] = {
  {
    "master_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Request, master_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "slave_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Request, slave_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sdo_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Request, sdo_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sdo_subindex",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Request, sdo_subindex),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sdo_data_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Request, sdo_data_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sdo_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Request, sdo_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_members = {
  "ethercat_msgs__srv",  // message namespace
  "SetSdo_Request",  // message name
  6,  // number of fields
  sizeof(ethercat_msgs__srv__SetSdo_Request),
  ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_member_array,  // message members
  ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_type_support_handle = {
  0,
  &ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ethercat_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ethercat_msgs, srv, SetSdo_Request)() {
  if (!ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_type_support_handle.typesupport_identifier) {
    ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ethercat_msgs__srv__SetSdo_Request__rosidl_typesupport_introspection_c__SetSdo_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ethercat_msgs/srv/detail/set_sdo__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ethercat_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ethercat_msgs/srv/detail/set_sdo__functions.h"
// already included above
// #include "ethercat_msgs/srv/detail/set_sdo__struct.h"


// Include directives for member types
// Member `sdo_return_message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ethercat_msgs__srv__SetSdo_Response__init(message_memory);
}

void ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_fini_function(void * message_memory)
{
  ethercat_msgs__srv__SetSdo_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "sdo_return_message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ethercat_msgs__srv__SetSdo_Response, sdo_return_message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_members = {
  "ethercat_msgs__srv",  // message namespace
  "SetSdo_Response",  // message name
  2,  // number of fields
  sizeof(ethercat_msgs__srv__SetSdo_Response),
  ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_member_array,  // message members
  ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_type_support_handle = {
  0,
  &ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ethercat_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ethercat_msgs, srv, SetSdo_Response)() {
  if (!ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_type_support_handle.typesupport_identifier) {
    ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ethercat_msgs__srv__SetSdo_Response__rosidl_typesupport_introspection_c__SetSdo_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ethercat_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ethercat_msgs/srv/detail/set_sdo__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_service_members = {
  "ethercat_msgs__srv",  // service namespace
  "SetSdo",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_Request_message_type_support_handle,
  NULL  // response message
  // ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_Response_message_type_support_handle
};

static rosidl_service_type_support_t ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_service_type_support_handle = {
  0,
  &ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ethercat_msgs, srv, SetSdo_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ethercat_msgs, srv, SetSdo_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ethercat_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ethercat_msgs, srv, SetSdo)() {
  if (!ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_service_type_support_handle.typesupport_identifier) {
    ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ethercat_msgs, srv, SetSdo_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ethercat_msgs, srv, SetSdo_Response)()->data;
  }

  return &ethercat_msgs__srv__detail__set_sdo__rosidl_typesupport_introspection_c__SetSdo_service_type_support_handle;
}
