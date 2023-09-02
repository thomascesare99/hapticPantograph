// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ethercat_msgs:srv/GetSdo.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ethercat_msgs/srv/detail/get_sdo__struct.h"
#include "ethercat_msgs/srv/detail/get_sdo__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ethercat_msgs__srv__get_sdo__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ethercat_msgs.srv._get_sdo.GetSdo_Request", full_classname_dest, 41) == 0);
  }
  ethercat_msgs__srv__GetSdo_Request * ros_message = _ros_message;
  {  // master_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "master_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->master_id = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // slave_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "slave_position");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->slave_position = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sdo_index
    PyObject * field = PyObject_GetAttrString(_pymsg, "sdo_index");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sdo_index = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sdo_subindex
    PyObject * field = PyObject_GetAttrString(_pymsg, "sdo_subindex");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sdo_subindex = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sdo_data_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "sdo_data_type");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->sdo_data_type, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ethercat_msgs__srv__get_sdo__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GetSdo_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ethercat_msgs.srv._get_sdo");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GetSdo_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ethercat_msgs__srv__GetSdo_Request * ros_message = (ethercat_msgs__srv__GetSdo_Request *)raw_ros_message;
  {  // master_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->master_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "master_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // slave_position
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->slave_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "slave_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sdo_index
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sdo_index);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sdo_index", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sdo_subindex
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sdo_subindex);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sdo_subindex", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sdo_data_type
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->sdo_data_type.data,
      strlen(ros_message->sdo_data_type.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sdo_data_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "ethercat_msgs/srv/detail/get_sdo__struct.h"
// already included above
// #include "ethercat_msgs/srv/detail/get_sdo__functions.h"

// already included above
// #include "rosidl_runtime_c/string.h"
// already included above
// #include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ethercat_msgs__srv__get_sdo__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[43];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ethercat_msgs.srv._get_sdo.GetSdo_Response", full_classname_dest, 42) == 0);
  }
  ethercat_msgs__srv__GetSdo_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }
  {  // sdo_return_message
    PyObject * field = PyObject_GetAttrString(_pymsg, "sdo_return_message");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->sdo_return_message, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // sdo_return_value_string
    PyObject * field = PyObject_GetAttrString(_pymsg, "sdo_return_value_string");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->sdo_return_value_string, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // sdo_return_value
    PyObject * field = PyObject_GetAttrString(_pymsg, "sdo_return_value");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->sdo_return_value = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ethercat_msgs__srv__get_sdo__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GetSdo_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ethercat_msgs.srv._get_sdo");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GetSdo_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ethercat_msgs__srv__GetSdo_Response * ros_message = (ethercat_msgs__srv__GetSdo_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sdo_return_message
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->sdo_return_message.data,
      strlen(ros_message->sdo_return_message.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sdo_return_message", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sdo_return_value_string
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->sdo_return_value_string.data,
      strlen(ros_message->sdo_return_value_string.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "sdo_return_value_string", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sdo_return_value
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->sdo_return_value);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sdo_return_value", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
