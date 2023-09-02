// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ethercat_msgs:srv/SetSdo.idl
// generated code does not contain a copyright notice

#ifndef ETHERCAT_MSGS__SRV__DETAIL__SET_SDO__STRUCT_HPP_
#define ETHERCAT_MSGS__SRV__DETAIL__SET_SDO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ethercat_msgs__srv__SetSdo_Request __attribute__((deprecated))
#else
# define DEPRECATED__ethercat_msgs__srv__SetSdo_Request __declspec(deprecated)
#endif

namespace ethercat_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetSdo_Request_
{
  using Type = SetSdo_Request_<ContainerAllocator>;

  explicit SetSdo_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->master_id = 0;
      this->slave_position = 0;
      this->sdo_index = 0;
      this->sdo_subindex = 0;
      this->sdo_data_type = "";
      this->sdo_value = "";
    }
  }

  explicit SetSdo_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sdo_data_type(_alloc),
    sdo_value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->master_id = 0;
      this->slave_position = 0;
      this->sdo_index = 0;
      this->sdo_subindex = 0;
      this->sdo_data_type = "";
      this->sdo_value = "";
    }
  }

  // field types and members
  using _master_id_type =
    int16_t;
  _master_id_type master_id;
  using _slave_position_type =
    int16_t;
  _slave_position_type slave_position;
  using _sdo_index_type =
    int16_t;
  _sdo_index_type sdo_index;
  using _sdo_subindex_type =
    int16_t;
  _sdo_subindex_type sdo_subindex;
  using _sdo_data_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sdo_data_type_type sdo_data_type;
  using _sdo_value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sdo_value_type sdo_value;

  // setters for named parameter idiom
  Type & set__master_id(
    const int16_t & _arg)
  {
    this->master_id = _arg;
    return *this;
  }
  Type & set__slave_position(
    const int16_t & _arg)
  {
    this->slave_position = _arg;
    return *this;
  }
  Type & set__sdo_index(
    const int16_t & _arg)
  {
    this->sdo_index = _arg;
    return *this;
  }
  Type & set__sdo_subindex(
    const int16_t & _arg)
  {
    this->sdo_subindex = _arg;
    return *this;
  }
  Type & set__sdo_data_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sdo_data_type = _arg;
    return *this;
  }
  Type & set__sdo_value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sdo_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ethercat_msgs__srv__SetSdo_Request
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ethercat_msgs__srv__SetSdo_Request
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetSdo_Request_ & other) const
  {
    if (this->master_id != other.master_id) {
      return false;
    }
    if (this->slave_position != other.slave_position) {
      return false;
    }
    if (this->sdo_index != other.sdo_index) {
      return false;
    }
    if (this->sdo_subindex != other.sdo_subindex) {
      return false;
    }
    if (this->sdo_data_type != other.sdo_data_type) {
      return false;
    }
    if (this->sdo_value != other.sdo_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetSdo_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetSdo_Request_

// alias to use template instance with default allocator
using SetSdo_Request =
  ethercat_msgs::srv::SetSdo_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ethercat_msgs


#ifndef _WIN32
# define DEPRECATED__ethercat_msgs__srv__SetSdo_Response __attribute__((deprecated))
#else
# define DEPRECATED__ethercat_msgs__srv__SetSdo_Response __declspec(deprecated)
#endif

namespace ethercat_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetSdo_Response_
{
  using Type = SetSdo_Response_<ContainerAllocator>;

  explicit SetSdo_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->sdo_return_message = "";
    }
  }

  explicit SetSdo_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : sdo_return_message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->sdo_return_message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _sdo_return_message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _sdo_return_message_type sdo_return_message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__sdo_return_message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->sdo_return_message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ethercat_msgs__srv__SetSdo_Response
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ethercat_msgs__srv__SetSdo_Response
    std::shared_ptr<ethercat_msgs::srv::SetSdo_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetSdo_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->sdo_return_message != other.sdo_return_message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetSdo_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetSdo_Response_

// alias to use template instance with default allocator
using SetSdo_Response =
  ethercat_msgs::srv::SetSdo_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ethercat_msgs

namespace ethercat_msgs
{

namespace srv
{

struct SetSdo
{
  using Request = ethercat_msgs::srv::SetSdo_Request;
  using Response = ethercat_msgs::srv::SetSdo_Response;
};

}  // namespace srv

}  // namespace ethercat_msgs

#endif  // ETHERCAT_MSGS__SRV__DETAIL__SET_SDO__STRUCT_HPP_
