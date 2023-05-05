// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from calmcar:msg/ConfigData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CONFIG_DATA__TRAITS_HPP_
#define CALMCAR__MSG__DETAIL__CONFIG_DATA__TRAITS_HPP_

#include "calmcar/msg/detail/config_data__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const calmcar::msg::ConfigData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: methods
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "methods: ";
    value_to_yaml(msg.methods, out);
    out << "\n";
  }

  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const calmcar::msg::ConfigData & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<calmcar::msg::ConfigData>()
{
  return "calmcar::msg::ConfigData";
}

template<>
inline const char * name<calmcar::msg::ConfigData>()
{
  return "calmcar/msg/ConfigData";
}

template<>
struct has_fixed_size<calmcar::msg::ConfigData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<calmcar::msg::ConfigData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<calmcar::msg::ConfigData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CALMCAR__MSG__DETAIL__CONFIG_DATA__TRAITS_HPP_
