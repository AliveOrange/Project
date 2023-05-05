// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from calmcar:msg/BinraryData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__BINRARY_DATA__TRAITS_HPP_
#define CALMCAR__MSG__DETAIL__BINRARY_DATA__TRAITS_HPP_

#include "calmcar/msg/detail/binrary_data__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const calmcar::msg::BinraryData & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const calmcar::msg::BinraryData & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<calmcar::msg::BinraryData>()
{
  return "calmcar::msg::BinraryData";
}

template<>
inline const char * name<calmcar::msg::BinraryData>()
{
  return "calmcar/msg/BinraryData";
}

template<>
struct has_fixed_size<calmcar::msg::BinraryData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<calmcar::msg::BinraryData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<calmcar::msg::BinraryData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CALMCAR__MSG__DETAIL__BINRARY_DATA__TRAITS_HPP_
