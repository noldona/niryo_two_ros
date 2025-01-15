// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from niryo_one_msgs:msg/LogStatus.idl
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
#include "niryo_one_msgs/msg/detail/log_status__struct.h"
#include "niryo_one_msgs/msg/detail/log_status__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool niryo_one_msgs__msg__log_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("niryo_one_msgs.msg._log_status.LogStatus", full_classname_dest, 40) == 0);
  }
  niryo_one_msgs__msg__LogStatus * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // log_size
    PyObject * field = PyObject_GetAttrString(_pymsg, "log_size");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->log_size = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // available_disk_size
    PyObject * field = PyObject_GetAttrString(_pymsg, "available_disk_size");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->available_disk_size = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // purge_log_on_startup
    PyObject * field = PyObject_GetAttrString(_pymsg, "purge_log_on_startup");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->purge_log_on_startup = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * niryo_one_msgs__msg__log_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of LogStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("niryo_one_msgs.msg._log_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "LogStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  niryo_one_msgs__msg__LogStatus * ros_message = (niryo_one_msgs__msg__LogStatus *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // log_size
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->log_size);
    {
      int rc = PyObject_SetAttrString(_pymessage, "log_size", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // available_disk_size
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->available_disk_size);
    {
      int rc = PyObject_SetAttrString(_pymessage, "available_disk_size", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // purge_log_on_startup
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->purge_log_on_startup ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "purge_log_on_startup", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
