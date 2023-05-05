// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from calmcar:msg/CacheData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CACHE_DATA__TRAITS_HPP_
#define CALMCAR__MSG__DETAIL__CACHE_DATA__TRAITS_HPP_

#include "calmcar/msg/detail/cache_data__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const calmcar::msg::CacheData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: methods
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "methods: ";
    value_to_yaml(msg.methods, out);
    out << "\n";
  }

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size: ";
    value_to_yaml(msg.size, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const calmcar::msg::CacheData & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<calmcar::msg::CacheData>()
{
  return "calmcar::msg::CacheData";
}

template<>
inline const char * name<calmcar::msg::CacheData>()
{
  return "calmcar/msg/CacheData";
}

template<>
struct has_fixed_size<calmcar::msg::CacheData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<calmcar::msg::CacheData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<calmcar::msg::CacheData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CALMCAR__MSG__DETAIL__CACHE_DATA__TRAITS_HPP_
