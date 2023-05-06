// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from calmcar:msg/CacheData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "calmcar/msg/detail/cache_data__rosidl_typesupport_introspection_c.h"
#include "calmcar/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "calmcar/msg/detail/cache_data__functions.h"
#include "calmcar/msg/detail/cache_data__struct.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CacheData__rosidl_typesupport_introspection_c__CacheData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  calmcar__msg__CacheData__init(message_memory);
}

void CacheData__rosidl_typesupport_introspection_c__CacheData_fini_function(void * message_memory)
{
  calmcar__msg__CacheData__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CacheData__rosidl_typesupport_introspection_c__CacheData_message_member_array[4] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar__msg__CacheData, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "methods",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar__msg__CacheData, methods),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar__msg__CacheData, size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(calmcar__msg__CacheData, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CacheData__rosidl_typesupport_introspection_c__CacheData_message_members = {
  "calmcar__msg",  // message namespace
  "CacheData",  // message name
  4,  // number of fields
  sizeof(calmcar__msg__CacheData),
  CacheData__rosidl_typesupport_introspection_c__CacheData_message_member_array,  // message members
  CacheData__rosidl_typesupport_introspection_c__CacheData_init_function,  // function to initialize message memory (memory has to be allocated)
  CacheData__rosidl_typesupport_introspection_c__CacheData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CacheData__rosidl_typesupport_introspection_c__CacheData_message_type_support_handle = {
  0,
  &CacheData__rosidl_typesupport_introspection_c__CacheData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_calmcar
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, calmcar, msg, CacheData)() {
  if (!CacheData__rosidl_typesupport_introspection_c__CacheData_message_type_support_handle.typesupport_identifier) {
    CacheData__rosidl_typesupport_introspection_c__CacheData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CacheData__rosidl_typesupport_introspection_c__CacheData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
