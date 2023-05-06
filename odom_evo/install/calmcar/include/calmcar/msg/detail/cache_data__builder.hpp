// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from calmcar:msg/CacheData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CACHE_DATA__BUILDER_HPP_
#define CALMCAR__MSG__DETAIL__CACHE_DATA__BUILDER_HPP_

#include "calmcar/msg/detail/cache_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace calmcar
{

namespace msg
{

namespace builder
{

class Init_CacheData_data
{
public:
  explicit Init_CacheData_data(::calmcar::msg::CacheData & msg)
  : msg_(msg)
  {}
  ::calmcar::msg::CacheData data(::calmcar::msg::CacheData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::calmcar::msg::CacheData msg_;
};

class Init_CacheData_size
{
public:
  explicit Init_CacheData_size(::calmcar::msg::CacheData & msg)
  : msg_(msg)
  {}
  Init_CacheData_data size(::calmcar::msg::CacheData::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_CacheData_data(msg_);
  }

private:
  ::calmcar::msg::CacheData msg_;
};

class Init_CacheData_methods
{
public:
  explicit Init_CacheData_methods(::calmcar::msg::CacheData & msg)
  : msg_(msg)
  {}
  Init_CacheData_size methods(::calmcar::msg::CacheData::_methods_type arg)
  {
    msg_.methods = std::move(arg);
    return Init_CacheData_size(msg_);
  }

private:
  ::calmcar::msg::CacheData msg_;
};

class Init_CacheData_type
{
public:
  Init_CacheData_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CacheData_methods type(::calmcar::msg::CacheData::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_CacheData_methods(msg_);
  }

private:
  ::calmcar::msg::CacheData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::calmcar::msg::CacheData>()
{
  return calmcar::msg::builder::Init_CacheData_type();
}

}  // namespace calmcar

#endif  // CALMCAR__MSG__DETAIL__CACHE_DATA__BUILDER_HPP_
