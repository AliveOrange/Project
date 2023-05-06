// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from calmcar:msg/BinraryData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "calmcar/msg/detail/binrary_data__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace calmcar
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BinraryData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) calmcar::msg::BinraryData(_init);
}

void BinraryData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<calmcar::msg::BinraryData *>(message_memory);
  typed_message->~BinraryData();
}

size_t size_function__BinraryData__data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__BinraryData__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__BinraryData__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void resize_function__BinraryData__data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BinraryData_message_member_array[2] = {
  {
    "size",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar::msg::BinraryData, size),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar::msg::BinraryData, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__BinraryData__data,  // size() function pointer
    get_const_function__BinraryData__data,  // get_const(index) function pointer
    get_function__BinraryData__data,  // get(index) function pointer
    resize_function__BinraryData__data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BinraryData_message_members = {
  "calmcar::msg",  // message namespace
  "BinraryData",  // message name
  2,  // number of fields
  sizeof(calmcar::msg::BinraryData),
  BinraryData_message_member_array,  // message members
  BinraryData_init_function,  // function to initialize message memory (memory has to be allocated)
  BinraryData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BinraryData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BinraryData_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace calmcar


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<calmcar::msg::BinraryData>()
{
  return &::calmcar::msg::rosidl_typesupport_introspection_cpp::BinraryData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, calmcar, msg, BinraryData)() {
  return &::calmcar::msg::rosidl_typesupport_introspection_cpp::BinraryData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
