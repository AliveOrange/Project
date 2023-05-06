// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from calmcar:msg/BinraryData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__BINRARY_DATA__STRUCT_H_
#define CALMCAR__MSG__DETAIL__BINRARY_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/BinraryData in the package calmcar.
typedef struct calmcar__msg__BinraryData
{
  uint64_t size;
  rosidl_runtime_c__uint8__Sequence data;
} calmcar__msg__BinraryData;

// Struct for a sequence of calmcar__msg__BinraryData.
typedef struct calmcar__msg__BinraryData__Sequence
{
  calmcar__msg__BinraryData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} calmcar__msg__BinraryData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CALMCAR__MSG__DETAIL__BINRARY_DATA__STRUCT_H_
