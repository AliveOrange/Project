// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from calmcar:msg/BinraryData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__BINRARY_DATA__BUILDER_HPP_
#define CALMCAR__MSG__DETAIL__BINRARY_DATA__BUILDER_HPP_

#include "calmcar/msg/detail/binrary_data__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace calmcar
{

namespace msg
{

namespace builder
{

class Init_BinraryData_data
{
public:
  explicit Init_BinraryData_data(::calmcar::msg::BinraryData & msg)
  : msg_(msg)
  {}
  ::calmcar::msg::BinraryData data(::calmcar::msg::BinraryData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::calmcar::msg::BinraryData msg_;
};

class Init_BinraryData_size
{
public:
  Init_BinraryData_size()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BinraryData_data size(::calmcar::msg::BinraryData::_size_type arg)
  {
    msg_.size = std::move(arg);
    return Init_BinraryData_data(msg_);
  }

private:
  ::calmcar::msg::BinraryData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::calmcar::msg::BinraryData>()
{
  return calmcar::msg::builder::Init_BinraryData_size();
}

}  // namespace calmcar

#endif  // CALMCAR__MSG__DETAIL__BINRARY_DATA__BUILDER_HPP_
