// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from calmcar:msg/ConfigData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CONFIG_DATA__BUILDER_HPP_
#define CALMCAR__MSG__DETAIL__CONFIG_DATA__BUILDER_HPP_

#include "calmcar/msg/detail/config_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace calmcar
{

namespace msg
{

namespace builder
{

class Init_ConfigData_value
{
public:
  explicit Init_ConfigData_value(::calmcar::msg::ConfigData & msg)
  : msg_(msg)
  {}
  ::calmcar::msg::ConfigData value(::calmcar::msg::ConfigData::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::calmcar::msg::ConfigData msg_;
};

class Init_ConfigData_methods
{
public:
  Init_ConfigData_methods()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ConfigData_value methods(::calmcar::msg::ConfigData::_methods_type arg)
  {
    msg_.methods = std::move(arg);
    return Init_ConfigData_value(msg_);
  }

private:
  ::calmcar::msg::ConfigData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::calmcar::msg::ConfigData>()
{
  return calmcar::msg::builder::Init_ConfigData_methods();
}

}  // namespace calmcar

#endif  // CALMCAR__MSG__DETAIL__CONFIG_DATA__BUILDER_HPP_
