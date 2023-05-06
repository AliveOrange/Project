// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from calmcar:msg/CacheData.idl
// generated code does not contain a copyright notice
#include "calmcar/msg/detail/cache_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
calmcar__msg__CacheData__init(calmcar__msg__CacheData * msg)
{
  if (!msg) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    calmcar__msg__CacheData__fini(msg);
    return false;
  }
  // methods
  // size
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    calmcar__msg__CacheData__fini(msg);
    return false;
  }
  return true;
}

void
calmcar__msg__CacheData__fini(calmcar__msg__CacheData * msg)
{
  if (!msg) {
    return;
  }
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // methods
  // size
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
calmcar__msg__CacheData__are_equal(const calmcar__msg__CacheData * lhs, const calmcar__msg__CacheData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // methods
  if (lhs->methods != rhs->methods) {
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
calmcar__msg__CacheData__copy(
  const calmcar__msg__CacheData * input,
  calmcar__msg__CacheData * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // methods
  output->methods = input->methods;
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

calmcar__msg__CacheData *
calmcar__msg__CacheData__create()
{
  calmcar__msg__CacheData * msg = (calmcar__msg__CacheData *)malloc(sizeof(calmcar__msg__CacheData));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(calmcar__msg__CacheData));
  bool success = calmcar__msg__CacheData__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
calmcar__msg__CacheData__destroy(calmcar__msg__CacheData * msg)
{
  if (msg) {
    calmcar__msg__CacheData__fini(msg);
  }
  free(msg);
}


bool
calmcar__msg__CacheData__Sequence__init(calmcar__msg__CacheData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  calmcar__msg__CacheData * data = NULL;
  if (size) {
    data = (calmcar__msg__CacheData *)calloc(size, sizeof(calmcar__msg__CacheData));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = calmcar__msg__CacheData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        calmcar__msg__CacheData__fini(&data[i - 1]);
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
calmcar__msg__CacheData__Sequence__fini(calmcar__msg__CacheData__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      calmcar__msg__CacheData__fini(&array->data[i]);
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

calmcar__msg__CacheData__Sequence *
calmcar__msg__CacheData__Sequence__create(size_t size)
{
  calmcar__msg__CacheData__Sequence * array = (calmcar__msg__CacheData__Sequence *)malloc(sizeof(calmcar__msg__CacheData__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = calmcar__msg__CacheData__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
calmcar__msg__CacheData__Sequence__destroy(calmcar__msg__CacheData__Sequence * array)
{
  if (array) {
    calmcar__msg__CacheData__Sequence__fini(array);
  }
  free(array);
}

bool
calmcar__msg__CacheData__Sequence__are_equal(const calmcar__msg__CacheData__Sequence * lhs, const calmcar__msg__CacheData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!calmcar__msg__CacheData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
calmcar__msg__CacheData__Sequence__copy(
  const calmcar__msg__CacheData__Sequence * input,
  calmcar__msg__CacheData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(calmcar__msg__CacheData);
    calmcar__msg__CacheData * data =
      (calmcar__msg__CacheData *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!calmcar__msg__CacheData__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          calmcar__msg__CacheData__fini(&data[i]);
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
    if (!calmcar__msg__CacheData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
