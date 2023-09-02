// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ethercat_msgs:srv/GetSdo.idl
// generated code does not contain a copyright notice

#ifndef ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__STRUCT_H_
#define ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'sdo_data_type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetSdo in the package ethercat_msgs.
typedef struct ethercat_msgs__srv__GetSdo_Request
{
  int16_t master_id;
  uint16_t slave_position;
  uint16_t sdo_index;
  uint8_t sdo_subindex;
  rosidl_runtime_c__String sdo_data_type;
} ethercat_msgs__srv__GetSdo_Request;

// Struct for a sequence of ethercat_msgs__srv__GetSdo_Request.
typedef struct ethercat_msgs__srv__GetSdo_Request__Sequence
{
  ethercat_msgs__srv__GetSdo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ethercat_msgs__srv__GetSdo_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'sdo_return_message'
// Member 'sdo_return_value_string'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetSdo in the package ethercat_msgs.
typedef struct ethercat_msgs__srv__GetSdo_Response
{
  bool success;
  rosidl_runtime_c__String sdo_return_message;
  rosidl_runtime_c__String sdo_return_value_string;
  double sdo_return_value;
} ethercat_msgs__srv__GetSdo_Response;

// Struct for a sequence of ethercat_msgs__srv__GetSdo_Response.
typedef struct ethercat_msgs__srv__GetSdo_Response__Sequence
{
  ethercat_msgs__srv__GetSdo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ethercat_msgs__srv__GetSdo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__STRUCT_H_
