// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from calmcar:msg/ConfigData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "calmcar/msg/detail/config_data__rosidl_typesupport_introspection_c.h"
#include "calmcar/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "calmcar/msg/detail/config_data__functions.h"
#include "calmcar/msg/detail/config_data__struct.h"


// Include directives for member types
// Member `value`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ConfigData__rosidl_typesupport_introspection_c__ConfigData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  calmcar__msg__ConfigData__init(message_memory);
}

void ConfigData__rosidl_typesupport_introspection_c__ConfigData_fini_function(void * message_memory)
{
  calmcar__msg__ConfigData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_member_array[2] = {
  {
    "methods",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar__msg__ConfigData, methods),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar__msg__ConfigData, value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_members = {
  "calmcar__msg",  // message namespace
  "ConfigData",  // message name
  2,  // number of fields
  sizeof(calmcar__msg__ConfigData),
  ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_member_array,  // message members
  ConfigData__rosidl_typesupport_introspection_c__ConfigData_init_function,  // function to initialize message memory (memory has to be allocated)
  ConfigData__rosidl_typesupport_introspection_c__ConfigData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_type_support_handle = {
  0,
  &ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_calmcar
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, calmcar, msg, ConfigData)() {
  if (!ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_type_support_handle.typesupport_identifier) {
    ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ConfigData__rosidl_typesupport_introspection_c__ConfigData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
