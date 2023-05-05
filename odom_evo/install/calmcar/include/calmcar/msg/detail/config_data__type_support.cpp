// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from calmcar:msg/ConfigData.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "calmcar/msg/detail/config_data__struct.hpp"
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

void ConfigData_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) calmcar::msg::ConfigData(_init);
}

void ConfigData_fini_function(void * message_memory)
{
  auto typed_message = static_cast<calmcar::msg::ConfigData *>(message_memory);
  typed_message->~ConfigData();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ConfigData_message_member_array[2] = {
  {
    "methods",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar::msg::ConfigData, methods),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "value",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar::msg::ConfigData, value),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ConfigData_message_members = {
  "calmcar::msg",  // message namespace
  "ConfigData",  // message name
  2,  // number of fields
  sizeof(calmcar::msg::ConfigData),
  ConfigData_message_member_array,  // message members
  ConfigData_init_function,  // function to initialize message memory (memory has to be allocated)
  ConfigData_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ConfigData_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ConfigData_message_members,
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
get_message_type_support_handle<calmcar::msg::ConfigData>()
{
  return &::calmcar::msg::rosidl_typesupport_introspection_cpp::ConfigData_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, calmcar, msg, ConfigData)() {
  return &::calmcar::msg::rosidl_typesupport_introspection_cpp::ConfigData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
