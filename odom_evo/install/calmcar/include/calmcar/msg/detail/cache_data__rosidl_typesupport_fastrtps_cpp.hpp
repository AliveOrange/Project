// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from calmcar:msg/CacheData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CACHE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define CALMCAR__MSG__DETAIL__CACHE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "calmcar/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "calmcar/msg/detail/cache_data__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace calmcar
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_calmcar
cdr_serialize(
  const calmcar::msg::CacheData & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_calmcar
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  calmcar::msg::CacheData & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_calmcar
get_serialized_size(
  const calmcar::msg::CacheData & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_calmcar
max_serialized_size_CacheData(
  bool & full_bounded,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace calmcar

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_calmcar
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, calmcar, msg, CacheData)();

#ifdef __cplusplus
}
#endif

#endif  // CALMCAR__MSG__DETAIL__CACHE_DATA__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
