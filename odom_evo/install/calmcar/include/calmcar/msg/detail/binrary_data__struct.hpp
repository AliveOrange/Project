// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from calmcar:msg/BinraryData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__BINRARY_DATA__STRUCT_HPP_
#define CALMCAR__MSG__DETAIL__BINRARY_DATA__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__calmcar__msg__BinraryData __attribute__((deprecated))
#else
# define DEPRECATED__calmcar__msg__BinraryData __declspec(deprecated)
#endif

namespace calmcar
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BinraryData_
{
  using Type = BinraryData_<ContainerAllocator>;

  explicit BinraryData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size = 0ull;
    }
  }

  explicit BinraryData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->size = 0ull;
    }
  }

  // field types and members
  using _size_type =
    uint64_t;
  _size_type size;
  using _data_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__size(
    const uint64_t & _arg)
  {
    this->size = _arg;
    return *this;
  }
  Type & set__data(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    calmcar::msg::BinraryData_<ContainerAllocator> *;
  using ConstRawPtr =
    const calmcar::msg::BinraryData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<calmcar::msg::BinraryData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<calmcar::msg::BinraryData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      calmcar::msg::BinraryData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<calmcar::msg::BinraryData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      calmcar::msg::BinraryData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<calmcar::msg::BinraryData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<calmcar::msg::BinraryData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<calmcar::msg::BinraryData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__calmcar__msg__BinraryData
    std::shared_ptr<calmcar::msg::BinraryData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__calmcar__msg__BinraryData
    std::shared_ptr<calmcar::msg::BinraryData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BinraryData_ & other) const
  {
    if (this->size != other.size) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const BinraryData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BinraryData_

// alias to use template instance with default allocator
using BinraryData =
  calmcar::msg::BinraryData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace calmcar

#endif  // CALMCAR__MSG__DETAIL__BINRARY_DATA__STRUCT_HPP_
