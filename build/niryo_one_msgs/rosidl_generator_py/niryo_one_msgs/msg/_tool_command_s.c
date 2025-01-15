// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from niryo_one_msgs:msg/ToolCommand.idl
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
#include "niryo_one_msgs/msg/detail/tool_command__struct.h"
#include "niryo_one_msgs/msg/detail/tool_command__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool niryo_one_msgs__msg__tool_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[45];
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
    assert(strncmp("niryo_one_msgs.msg._tool_command.ToolCommand", full_classname_dest, 44) == 0);
  }
  niryo_one_msgs__msg__ToolCommand * ros_message = _ros_message;
  {  // tool_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "tool_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->tool_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cmd_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "cmd_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cmd_type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gripper_close_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_close_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_close_speed = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gripper_open_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "gripper_open_speed");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gripper_open_speed = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // activate
    PyObject * field = PyObject_GetAttrString(_pymsg, "activate");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->activate = (Py_True == field);
    Py_DECREF(field);
  }
  {  // gpio
    PyObject * field = PyObject_GetAttrString(_pymsg, "gpio");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gpio = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * niryo_one_msgs__msg__tool_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ToolCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("niryo_one_msgs.msg._tool_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ToolCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  niryo_one_msgs__msg__ToolCommand * ros_message = (niryo_one_msgs__msg__ToolCommand *)raw_ros_message;
  {  // tool_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->tool_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tool_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cmd_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cmd_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cmd_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_close_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gripper_close_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_close_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gripper_open_speed
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gripper_open_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gripper_open_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // activate
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->activate ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "activate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gpio
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gpio);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gpio", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
