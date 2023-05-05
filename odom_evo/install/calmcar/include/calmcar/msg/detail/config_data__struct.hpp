// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from calmcar:msg/ConfigData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CONFIG_DATA__STRUCT_HPP_
#define CALMCAR__MSG__DETAIL__CONFIG_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__calmcar__msg__ConfigData __attribute__((deprecated))
#else
# define DEPRECATED__calmcar__msg__ConfigData __declspec(deprecated)
#endif

namespace calmcar
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ConfigData_
{
  using Type = ConfigData_<ContainerAllocator>;

  explicit ConfigData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->methods = 0ul;
      this->value = "";
    }
  }

  explicit ConfigData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->methods = 0ul;
      this->value = "";
    }
  }

  // field types and members
  using _methods_type =
    uint32_t;
  _methods_type methods;
  using _value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _value_type value;

  // setters for named parameter idiom
  Type & set__methods(
    const uint32_t & _arg)
  {
    this->methods = _arg;
    return *this;
  }
  Type & set__value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    calmcar::msg::ConfigData_<ContainerAllocator> *;
  using ConstRawPtr =
    const calmcar::msg::ConfigData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<calmcar::msg::ConfigData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<calmcar::msg::ConfigData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      calmcar::msg::ConfigData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<calmcar::msg::ConfigData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      calmcar::msg::ConfigData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<calmcar::msg::ConfigData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<calmcar::msg::ConfigData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<calmcar::msg::ConfigData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__calmcar__msg__ConfigData
    std::shared_ptr<calmcar::msg::ConfigData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__calmcar__msg__ConfigData
    std::shared_ptr<calmcar::msg::ConfigData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConfigData_ & other) const
  {
    if (this->methods != other.methods) {
      return false;
    }
    if (this->value != other.value) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConfigData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConfigData_

// alias to use template instance with default allocator
using ConfigData =
  calmcar::msg::ConfigData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace calmcar

#endif  // CALMCAR__MSG__DETAIL__CONFIG_DATA__STRUCT_HPP_
