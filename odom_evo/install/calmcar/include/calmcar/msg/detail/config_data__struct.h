// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from calmcar:msg/ConfigData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CONFIG_DATA__STRUCT_H_
#define CALMCAR__MSG__DETAIL__CONFIG_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'value'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/ConfigData in the package calmcar.
typedef struct calmcar__msg__ConfigData
{
  uint32_t methods;
  rosidl_runtime_c__String value;
} calmcar__msg__ConfigData;

// Struct for a sequence of calmcar__msg__ConfigData.
typedef struct calmcar__msg__ConfigData__Sequence
{
  calmcar__msg__ConfigData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} calmcar__msg__ConfigData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CALMCAR__MSG__DETAIL__CONFIG_DATA__STRUCT_H_
