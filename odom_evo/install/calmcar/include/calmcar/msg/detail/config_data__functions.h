// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from calmcar:msg/ConfigData.idl
// generated code does not contain a copyright notice

#ifndef CALMCAR__MSG__DETAIL__CONFIG_DATA__FUNCTIONS_H_
#define CALMCAR__MSG__DETAIL__CONFIG_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "calmcar/msg/rosidl_generator_c__visibility_control.h"

#include "calmcar/msg/detail/config_data__struct.h"

/// Initialize msg/ConfigData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * calmcar__msg__ConfigData
 * )) before or use
 * calmcar__msg__ConfigData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
bool
calmcar__msg__ConfigData__init(calmcar__msg__ConfigData * msg);

/// Finalize msg/ConfigData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
void
calmcar__msg__ConfigData__fini(calmcar__msg__ConfigData * msg);

/// Create msg/ConfigData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * calmcar__msg__ConfigData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
calmcar__msg__ConfigData *
calmcar__msg__ConfigData__create();

/// Destroy msg/ConfigData message.
/**
 * It calls
 * calmcar__msg__ConfigData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
void
calmcar__msg__ConfigData__destroy(calmcar__msg__ConfigData * msg);

/// Check for msg/ConfigData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
bool
calmcar__msg__ConfigData__are_equal(const calmcar__msg__ConfigData * lhs, const calmcar__msg__ConfigData * rhs);

/// Copy a msg/ConfigData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
bool
calmcar__msg__ConfigData__copy(
  const calmcar__msg__ConfigData * input,
  calmcar__msg__ConfigData * output);

/// Initialize array of msg/ConfigData messages.
/**
 * It allocates the memory for the number of elements and calls
 * calmcar__msg__ConfigData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
bool
calmcar__msg__ConfigData__Sequence__init(calmcar__msg__ConfigData__Sequence * array, size_t size);

/// Finalize array of msg/ConfigData messages.
/**
 * It calls
 * calmcar__msg__ConfigData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
void
calmcar__msg__ConfigData__Sequence__fini(calmcar__msg__ConfigData__Sequence * array);

/// Create array of msg/ConfigData messages.
/**
 * It allocates the memory for the array and calls
 * calmcar__msg__ConfigData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
calmcar__msg__ConfigData__Sequence *
calmcar__msg__ConfigData__Sequence__create(size_t size);

/// Destroy array of msg/ConfigData messages.
/**
 * It calls
 * calmcar__msg__ConfigData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
void
calmcar__msg__ConfigData__Sequence__destroy(calmcar__msg__ConfigData__Sequence * array);

/// Check for msg/ConfigData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
bool
calmcar__msg__ConfigData__Sequence__are_equal(const calmcar__msg__ConfigData__Sequence * lhs, const calmcar__msg__ConfigData__Sequence * rhs);

/// Copy an array of msg/ConfigData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_calmcar
bool
calmcar__msg__ConfigData__Sequence__copy(
  const calmcar__msg__ConfigData__Sequence * input,
  calmcar__msg__ConfigData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CALMCAR__MSG__DETAIL__CONFIG_DATA__FUNCTIONS_H_
