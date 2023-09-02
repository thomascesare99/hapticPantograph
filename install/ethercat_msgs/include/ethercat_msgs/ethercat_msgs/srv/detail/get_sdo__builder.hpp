// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ethercat_msgs:srv/GetSdo.idl
// generated code does not contain a copyright notice

#ifndef ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__BUILDER_HPP_
#define ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ethercat_msgs/srv/detail/get_sdo__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ethercat_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSdo_Request_sdo_data_type
{
public:
  explicit Init_GetSdo_Request_sdo_data_type(::ethercat_msgs::srv::GetSdo_Request & msg)
  : msg_(msg)
  {}
  ::ethercat_msgs::srv::GetSdo_Request sdo_data_type(::ethercat_msgs::srv::GetSdo_Request::_sdo_data_type_type arg)
  {
    msg_.sdo_data_type = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Request msg_;
};

class Init_GetSdo_Request_sdo_subindex
{
public:
  explicit Init_GetSdo_Request_sdo_subindex(::ethercat_msgs::srv::GetSdo_Request & msg)
  : msg_(msg)
  {}
  Init_GetSdo_Request_sdo_data_type sdo_subindex(::ethercat_msgs::srv::GetSdo_Request::_sdo_subindex_type arg)
  {
    msg_.sdo_subindex = std::move(arg);
    return Init_GetSdo_Request_sdo_data_type(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Request msg_;
};

class Init_GetSdo_Request_sdo_index
{
public:
  explicit Init_GetSdo_Request_sdo_index(::ethercat_msgs::srv::GetSdo_Request & msg)
  : msg_(msg)
  {}
  Init_GetSdo_Request_sdo_subindex sdo_index(::ethercat_msgs::srv::GetSdo_Request::_sdo_index_type arg)
  {
    msg_.sdo_index = std::move(arg);
    return Init_GetSdo_Request_sdo_subindex(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Request msg_;
};

class Init_GetSdo_Request_slave_position
{
public:
  explicit Init_GetSdo_Request_slave_position(::ethercat_msgs::srv::GetSdo_Request & msg)
  : msg_(msg)
  {}
  Init_GetSdo_Request_sdo_index slave_position(::ethercat_msgs::srv::GetSdo_Request::_slave_position_type arg)
  {
    msg_.slave_position = std::move(arg);
    return Init_GetSdo_Request_sdo_index(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Request msg_;
};

class Init_GetSdo_Request_master_id
{
public:
  Init_GetSdo_Request_master_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSdo_Request_slave_position master_id(::ethercat_msgs::srv::GetSdo_Request::_master_id_type arg)
  {
    msg_.master_id = std::move(arg);
    return Init_GetSdo_Request_slave_position(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ethercat_msgs::srv::GetSdo_Request>()
{
  return ethercat_msgs::srv::builder::Init_GetSdo_Request_master_id();
}

}  // namespace ethercat_msgs


namespace ethercat_msgs
{

namespace srv
{

namespace builder
{

class Init_GetSdo_Response_sdo_return_value
{
public:
  explicit Init_GetSdo_Response_sdo_return_value(::ethercat_msgs::srv::GetSdo_Response & msg)
  : msg_(msg)
  {}
  ::ethercat_msgs::srv::GetSdo_Response sdo_return_value(::ethercat_msgs::srv::GetSdo_Response::_sdo_return_value_type arg)
  {
    msg_.sdo_return_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Response msg_;
};

class Init_GetSdo_Response_sdo_return_value_string
{
public:
  explicit Init_GetSdo_Response_sdo_return_value_string(::ethercat_msgs::srv::GetSdo_Response & msg)
  : msg_(msg)
  {}
  Init_GetSdo_Response_sdo_return_value sdo_return_value_string(::ethercat_msgs::srv::GetSdo_Response::_sdo_return_value_string_type arg)
  {
    msg_.sdo_return_value_string = std::move(arg);
    return Init_GetSdo_Response_sdo_return_value(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Response msg_;
};

class Init_GetSdo_Response_sdo_return_message
{
public:
  explicit Init_GetSdo_Response_sdo_return_message(::ethercat_msgs::srv::GetSdo_Response & msg)
  : msg_(msg)
  {}
  Init_GetSdo_Response_sdo_return_value_string sdo_return_message(::ethercat_msgs::srv::GetSdo_Response::_sdo_return_message_type arg)
  {
    msg_.sdo_return_message = std::move(arg);
    return Init_GetSdo_Response_sdo_return_value_string(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Response msg_;
};

class Init_GetSdo_Response_success
{
public:
  Init_GetSdo_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetSdo_Response_sdo_return_message success(::ethercat_msgs::srv::GetSdo_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetSdo_Response_sdo_return_message(msg_);
  }

private:
  ::ethercat_msgs::srv::GetSdo_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ethercat_msgs::srv::GetSdo_Response>()
{
  return ethercat_msgs::srv::builder::Init_GetSdo_Response_success();
}

}  // namespace ethercat_msgs

#endif  // ETHERCAT_MSGS__SRV__DETAIL__GET_SDO__BUILDER_HPP_
