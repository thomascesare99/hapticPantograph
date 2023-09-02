// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ethercat_msgs:srv/GetSdo.idl
// generated code does not contain a copyright notice

#ifndef ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__TRAITS_HPP_
#define ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ethercat_msgs/srv/detail/get_sdo__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ethercat_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSdo_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: master_id
  {
    out << "master_id: ";
    rosidl_generator_traits::value_to_yaml(msg.master_id, out);
    out << ", ";
  }

  // member: slave_position
  {
    out << "slave_position: ";
    rosidl_generator_traits::value_to_yaml(msg.slave_position, out);
    out << ", ";
  }

  // member: sdo_index
  {
    out << "sdo_index: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_index, out);
    out << ", ";
  }

  // member: sdo_subindex
  {
    out << "sdo_subindex: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_subindex, out);
    out << ", ";
  }

  // member: sdo_data_type
  {
    out << "sdo_data_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_data_type, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSdo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: master_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "master_id: ";
    rosidl_generator_traits::value_to_yaml(msg.master_id, out);
    out << "\n";
  }

  // member: slave_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slave_position: ";
    rosidl_generator_traits::value_to_yaml(msg.slave_position, out);
    out << "\n";
  }

  // member: sdo_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sdo_index: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_index, out);
    out << "\n";
  }

  // member: sdo_subindex
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sdo_subindex: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_subindex, out);
    out << "\n";
  }

  // member: sdo_data_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sdo_data_type: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_data_type, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSdo_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ethercat_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ethercat_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ethercat_msgs::srv::GetSdo_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ethercat_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ethercat_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const ethercat_msgs::srv::GetSdo_Request & msg)
{
  return ethercat_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ethercat_msgs::srv::GetSdo_Request>()
{
  return "ethercat_msgs::srv::GetSdo_Request";
}

template<>
inline const char * name<ethercat_msgs::srv::GetSdo_Request>()
{
  return "ethercat_msgs/srv/GetSdo_Request";
}

template<>
struct has_fixed_size<ethercat_msgs::srv::GetSdo_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ethercat_msgs::srv::GetSdo_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ethercat_msgs::srv::GetSdo_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ethercat_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetSdo_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: sdo_return_message
  {
    out << "sdo_return_message: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_return_message, out);
    out << ", ";
  }

  // member: sdo_return_value_string
  {
    out << "sdo_return_value_string: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_return_value_string, out);
    out << ", ";
  }

  // member: sdo_return_value
  {
    out << "sdo_return_value: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_return_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetSdo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: sdo_return_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sdo_return_message: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_return_message, out);
    out << "\n";
  }

  // member: sdo_return_value_string
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sdo_return_value_string: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_return_value_string, out);
    out << "\n";
  }

  // member: sdo_return_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sdo_return_value: ";
    rosidl_generator_traits::value_to_yaml(msg.sdo_return_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetSdo_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ethercat_msgs

namespace rosidl_generator_traits
{

[[deprecated("use ethercat_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ethercat_msgs::srv::GetSdo_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ethercat_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ethercat_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const ethercat_msgs::srv::GetSdo_Response & msg)
{
  return ethercat_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ethercat_msgs::srv::GetSdo_Response>()
{
  return "ethercat_msgs::srv::GetSdo_Response";
}

template<>
inline const char * name<ethercat_msgs::srv::GetSdo_Response>()
{
  return "ethercat_msgs/srv/GetSdo_Response";
}

template<>
struct has_fixed_size<ethercat_msgs::srv::GetSdo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ethercat_msgs::srv::GetSdo_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ethercat_msgs::srv::GetSdo_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ethercat_msgs::srv::GetSdo>()
{
  return "ethercat_msgs::srv::GetSdo";
}

template<>
inline const char * name<ethercat_msgs::srv::GetSdo>()
{
  return "ethercat_msgs/srv/GetSdo";
}

template<>
struct has_fixed_size<ethercat_msgs::srv::GetSdo>
  : std::integral_constant<
    bool,
    has_fixed_size<ethercat_msgs::srv::GetSdo_Request>::value &&
    has_fixed_size<ethercat_msgs::srv::GetSdo_Response>::value
  >
{
};

template<>
struct has_bounded_size<ethercat_msgs::srv::GetSdo>
  : std::integral_constant<
    bool,
    has_bounded_size<ethercat_msgs::srv::GetSdo_Request>::value &&
    has_bounded_size<ethercat_msgs::srv::GetSdo_Response>::value
  >
{
};

template<>
struct is_service<ethercat_msgs::srv::GetSdo>
  : std::true_type
{
};

template<>
struct is_service_request<ethercat_msgs::srv::GetSdo_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ethercat_msgs::srv::GetSdo_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__TRAITS_HPP_
