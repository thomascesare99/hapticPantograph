// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ethercat_msgs:srv/GetSdo.idl
// generated code does not contain a copyright notice
#include "ethercat_msgs/srv/detail/get_sdo__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `sdo_data_type`
#include "rosidl_runtime_c/string_functions.h"

bool
ethercat_msgs__srv__GetSdo_Request__init(ethercat_msgs__srv__GetSdo_Request * msg)
{
  if (!msg) {
    return false;
  }
  // master_id
  // slave_position
  // sdo_index
  // sdo_subindex
  // sdo_data_type
  if (!rosidl_runtime_c__String__init(&msg->sdo_data_type)) {
    ethercat_msgs__srv__GetSdo_Request__fini(msg);
    return false;
  }
  return true;
}

void
ethercat_msgs__srv__GetSdo_Request__fini(ethercat_msgs__srv__GetSdo_Request * msg)
{
  if (!msg) {
    return;
  }
  // master_id
  // slave_position
  // sdo_index
  // sdo_subindex
  // sdo_data_type
  rosidl_runtime_c__String__fini(&msg->sdo_data_type);
}

bool
ethercat_msgs__srv__GetSdo_Request__are_equal(const ethercat_msgs__srv__GetSdo_Request * lhs, const ethercat_msgs__srv__GetSdo_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // master_id
  if (lhs->master_id != rhs->master_id) {
    return false;
  }
  // slave_position
  if (lhs->slave_position != rhs->slave_position) {
    return false;
  }
  // sdo_index
  if (lhs->sdo_index != rhs->sdo_index) {
    return false;
  }
  // sdo_subindex
  if (lhs->sdo_subindex != rhs->sdo_subindex) {
    return false;
  }
  // sdo_data_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sdo_data_type), &(rhs->sdo_data_type)))
  {
    return false;
  }
  return true;
}

bool
ethercat_msgs__srv__GetSdo_Request__copy(
  const ethercat_msgs__srv__GetSdo_Request * input,
  ethercat_msgs__srv__GetSdo_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // master_id
  output->master_id = input->master_id;
  // slave_position
  output->slave_position = input->slave_position;
  // sdo_index
  output->sdo_index = input->sdo_index;
  // sdo_subindex
  output->sdo_subindex = input->sdo_subindex;
  // sdo_data_type
  if (!rosidl_runtime_c__String__copy(
      &(input->sdo_data_type), &(output->sdo_data_type)))
  {
    return false;
  }
  return true;
}

ethercat_msgs__srv__GetSdo_Request *
ethercat_msgs__srv__GetSdo_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ethercat_msgs__srv__GetSdo_Request * msg = (ethercat_msgs__srv__GetSdo_Request *)allocator.allocate(sizeof(ethercat_msgs__srv__GetSdo_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ethercat_msgs__srv__GetSdo_Request));
  bool success = ethercat_msgs__srv__GetSdo_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ethercat_msgs__srv__GetSdo_Request__destroy(ethercat_msgs__srv__GetSdo_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ethercat_msgs__srv__GetSdo_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ethercat_msgs__srv__GetSdo_Request__Sequence__init(ethercat_msgs__srv__GetSdo_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ethercat_msgs__srv__GetSdo_Request * data = NULL;

  if (size) {
    data = (ethercat_msgs__srv__GetSdo_Request *)allocator.zero_allocate(size, sizeof(ethercat_msgs__srv__GetSdo_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ethercat_msgs__srv__GetSdo_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ethercat_msgs__srv__GetSdo_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ethercat_msgs__srv__GetSdo_Request__Sequence__fini(ethercat_msgs__srv__GetSdo_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ethercat_msgs__srv__GetSdo_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ethercat_msgs__srv__GetSdo_Request__Sequence *
ethercat_msgs__srv__GetSdo_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ethercat_msgs__srv__GetSdo_Request__Sequence * array = (ethercat_msgs__srv__GetSdo_Request__Sequence *)allocator.allocate(sizeof(ethercat_msgs__srv__GetSdo_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ethercat_msgs__srv__GetSdo_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ethercat_msgs__srv__GetSdo_Request__Sequence__destroy(ethercat_msgs__srv__GetSdo_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ethercat_msgs__srv__GetSdo_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ethercat_msgs__srv__GetSdo_Request__Sequence__are_equal(const ethercat_msgs__srv__GetSdo_Request__Sequence * lhs, const ethercat_msgs__srv__GetSdo_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ethercat_msgs__srv__GetSdo_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ethercat_msgs__srv__GetSdo_Request__Sequence__copy(
  const ethercat_msgs__srv__GetSdo_Request__Sequence * input,
  ethercat_msgs__srv__GetSdo_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ethercat_msgs__srv__GetSdo_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ethercat_msgs__srv__GetSdo_Request * data =
      (ethercat_msgs__srv__GetSdo_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ethercat_msgs__srv__GetSdo_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ethercat_msgs__srv__GetSdo_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ethercat_msgs__srv__GetSdo_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `sdo_return_message`
// Member `sdo_return_value_string`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
ethercat_msgs__srv__GetSdo_Response__init(ethercat_msgs__srv__GetSdo_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // sdo_return_message
  if (!rosidl_runtime_c__String__init(&msg->sdo_return_message)) {
    ethercat_msgs__srv__GetSdo_Response__fini(msg);
    return false;
  }
  // sdo_return_value_string
  if (!rosidl_runtime_c__String__init(&msg->sdo_return_value_string)) {
    ethercat_msgs__srv__GetSdo_Response__fini(msg);
    return false;
  }
  // sdo_return_value
  return true;
}

void
ethercat_msgs__srv__GetSdo_Response__fini(ethercat_msgs__srv__GetSdo_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // sdo_return_message
  rosidl_runtime_c__String__fini(&msg->sdo_return_message);
  // sdo_return_value_string
  rosidl_runtime_c__String__fini(&msg->sdo_return_value_string);
  // sdo_return_value
}

bool
ethercat_msgs__srv__GetSdo_Response__are_equal(const ethercat_msgs__srv__GetSdo_Response * lhs, const ethercat_msgs__srv__GetSdo_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // sdo_return_message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sdo_return_message), &(rhs->sdo_return_message)))
  {
    return false;
  }
  // sdo_return_value_string
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->sdo_return_value_string), &(rhs->sdo_return_value_string)))
  {
    return false;
  }
  // sdo_return_value
  if (lhs->sdo_return_value != rhs->sdo_return_value) {
    return false;
  }
  return true;
}

bool
ethercat_msgs__srv__GetSdo_Response__copy(
  const ethercat_msgs__srv__GetSdo_Response * input,
  ethercat_msgs__srv__GetSdo_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // sdo_return_message
  if (!rosidl_runtime_c__String__copy(
      &(input->sdo_return_message), &(output->sdo_return_message)))
  {
    return false;
  }
  // sdo_return_value_string
  if (!rosidl_runtime_c__String__copy(
      &(input->sdo_return_value_string), &(output->sdo_return_value_string)))
  {
    return false;
  }
  // sdo_return_value
  output->sdo_return_value = input->sdo_return_value;
  return true;
}

ethercat_msgs__srv__GetSdo_Response *
ethercat_msgs__srv__GetSdo_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ethercat_msgs__srv__GetSdo_Response * msg = (ethercat_msgs__srv__GetSdo_Response *)allocator.allocate(sizeof(ethercat_msgs__srv__GetSdo_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ethercat_msgs__srv__GetSdo_Response));
  bool success = ethercat_msgs__srv__GetSdo_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ethercat_msgs__srv__GetSdo_Response__destroy(ethercat_msgs__srv__GetSdo_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ethercat_msgs__srv__GetSdo_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ethercat_msgs__srv__GetSdo_Response__Sequence__init(ethercat_msgs__srv__GetSdo_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ethercat_msgs__srv__GetSdo_Response * data = NULL;

  if (size) {
    data = (ethercat_msgs__srv__GetSdo_Response *)allocator.zero_allocate(size, sizeof(ethercat_msgs__srv__GetSdo_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ethercat_msgs__srv__GetSdo_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ethercat_msgs__srv__GetSdo_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ethercat_msgs__srv__GetSdo_Response__Sequence__fini(ethercat_msgs__srv__GetSdo_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ethercat_msgs__srv__GetSdo_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ethercat_msgs__srv__GetSdo_Response__Sequence *
ethercat_msgs__srv__GetSdo_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ethercat_msgs__srv__GetSdo_Response__Sequence * array = (ethercat_msgs__srv__GetSdo_Response__Sequence *)allocator.allocate(sizeof(ethercat_msgs__srv__GetSdo_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ethercat_msgs__srv__GetSdo_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ethercat_msgs__srv__GetSdo_Response__Sequence__destroy(ethercat_msgs__srv__GetSdo_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ethercat_msgs__srv__GetSdo_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ethercat_msgs__srv__GetSdo_Response__Sequence__are_equal(const ethercat_msgs__srv__GetSdo_Response__Sequence * lhs, const ethercat_msgs__srv__GetSdo_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ethercat_msgs__srv__GetSdo_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ethercat_msgs__srv__GetSdo_Response__Sequence__copy(
  const ethercat_msgs__srv__GetSdo_Response__Sequence * input,
  ethercat_msgs__srv__GetSdo_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ethercat_msgs__srv__GetSdo_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ethercat_msgs__srv__GetSdo_Response * data =
      (ethercat_msgs__srv__GetSdo_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ethercat_msgs__srv__GetSdo_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ethercat_msgs__srv__GetSdo_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ethercat_msgs__srv__GetSdo_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
