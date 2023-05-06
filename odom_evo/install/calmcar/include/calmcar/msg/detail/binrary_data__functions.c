// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from calmcar:msg/BinraryData.idl
// generated code does not contain a copyright notice
#include "calmcar/msg/detail/binrary_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
calmcar__msg__BinraryData__init(calmcar__msg__BinraryData * msg)
{
  if (!msg) {
    return false;
  }
  // size
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    calmcar__msg__BinraryData__fini(msg);
    return false;
  }
  return true;
}

void
calmcar__msg__BinraryData__fini(calmcar__msg__BinraryData * msg)
{
  if (!msg) {
    return;
  }
  // size
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
calmcar__msg__BinraryData__are_equal(const calmcar__msg__BinraryData * lhs, const calmcar__msg__BinraryData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // size
  if (lhs->size != rhs->size) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
calmcar__msg__BinraryData__copy(
  const calmcar__msg__BinraryData * input,
  calmcar__msg__BinraryData * output)
{
  if (!input || !output) {
    return false;
  }
  // size
  output->size = input->size;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

calmcar__msg__BinraryData *
calmcar__msg__BinraryData__create()
{
  calmcar__msg__BinraryData * msg = (calmcar__msg__BinraryData *)malloc(sizeof(calmcar__msg__BinraryData));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(calmcar__msg__BinraryData));
  bool success = calmcar__msg__BinraryData__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
calmcar__msg__BinraryData__destroy(calmcar__msg__BinraryData * msg)
{
  if (msg) {
    calmcar__msg__BinraryData__fini(msg);
  }
  free(msg);
}


bool
calmcar__msg__BinraryData__Sequence__init(calmcar__msg__BinraryData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  calmcar__msg__BinraryData * data = NULL;
  if (size) {
    data = (calmcar__msg__BinraryData *)calloc(size, sizeof(calmcar__msg__BinraryData));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = calmcar__msg__BinraryData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        calmcar__msg__BinraryData__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
calmcar__msg__BinraryData__Sequence__fini(calmcar__msg__BinraryData__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      calmcar__msg__BinraryData__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

calmcar__msg__BinraryData__Sequence *
calmcar__msg__BinraryData__Sequence__create(size_t size)
{
  calmcar__msg__BinraryData__Sequence * array = (calmcar__msg__BinraryData__Sequence *)malloc(sizeof(calmcar__msg__BinraryData__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = calmcar__msg__BinraryData__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
calmcar__msg__BinraryData__Sequence__destroy(calmcar__msg__BinraryData__Sequence * array)
{
  if (array) {
    calmcar__msg__BinraryData__Sequence__fini(array);
  }
  free(array);
}

bool
calmcar__msg__BinraryData__Sequence__are_equal(const calmcar__msg__BinraryData__Sequence * lhs, const calmcar__msg__BinraryData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!calmcar__msg__BinraryData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
calmcar__msg__BinraryData__Sequence__copy(
  const calmcar__msg__BinraryData__Sequence * input,
  calmcar__msg__BinraryData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(calmcar__msg__BinraryData);
    calmcar__msg__BinraryData * data =
      (calmcar__msg__BinraryData *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!calmcar__msg__BinraryData__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          calmcar__msg__BinraryData__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!calmcar__msg__BinraryData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
