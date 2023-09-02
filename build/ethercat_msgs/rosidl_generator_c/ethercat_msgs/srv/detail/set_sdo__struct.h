// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ethercat_msgs:srv/SetSdo.idl
// generated code does not contain a copyright notice

#ifndef ETHERCAT_MSGS__SRV__DETAIL__SET_SDO__STRUCT_H_
#define ETHERCAT_MSGS__SRV__DETAIL__SET_SDO__STRUCT_H_

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
// Member 'sdo_value'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetSdo in the package ethercat_msgs.
typedef struct ethercat_msgs__srv__SetSdo_Request
{
  int16_t master_id;
  int16_t slave_position;
  int16_t sdo_index;
  int16_t sdo_subindex;
  rosidl_runtime_c__String sdo_data_type;
  rosidl_runtime_c__String sdo_value;
} ethercat_msgs__srv__SetSdo_Request;

// Struct for a sequence of ethercat_msgs__srv__SetSdo_Request.
typedef struct ethercat_msgs__srv__SetSdo_Request__Sequence
{
  ethercat_msgs__srv__SetSdo_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ethercat_msgs__srv__SetSdo_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'sdo_return_message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetSdo in the package ethercat_msgs.
typedef struct ethercat_msgs__srv__SetSdo_Response
{
  bool success;
  rosidl_runtime_c__String sdo_return_message;
} ethercat_msgs__srv__SetSdo_Response;

// Struct for a sequence of ethercat_msgs__srv__SetSdo_Response.
typedef struct ethercat_msgs__srv__SetSdo_Response__Sequence
{
  ethercat_msgs__srv__SetSdo_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ethercat_msgs__srv__SetSdo_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ETHERCAT_MSGS__SRV__DETAIL__SET_SDO__STRUCT_H_
