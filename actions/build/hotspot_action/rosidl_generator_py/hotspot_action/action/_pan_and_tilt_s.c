// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from hotspot_action:action/PanAndTilt.idl
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
#include "hotspot_action/action/detail/pan_and_tilt__struct.h"
#include "hotspot_action/action/detail/pan_and_tilt__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__goal__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[52];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_Goal", full_classname_dest, 51) == 0);
  }
  hotspot_action__action__PanAndTilt_Goal * ros_message = _ros_message;
  {  // pan
    PyObject * field = PyObject_GetAttrString(_pymsg, "pan");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pan = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__goal__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_Goal */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_Goal");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_Goal * ros_message = (hotspot_action__action__PanAndTilt_Goal *)raw_ros_message;
  {  // pan
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pan);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pan", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt", field);
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
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__result__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[54];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_Result", full_classname_dest, 53) == 0);
  }
  hotspot_action__action__PanAndTilt_Result * ros_message = _ros_message;
  {  // move_finished
    PyObject * field = PyObject_GetAttrString(_pymsg, "move_finished");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->move_finished = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__result__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_Result */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_Result");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_Result * ros_message = (hotspot_action__action__PanAndTilt_Result *)raw_ros_message;
  {  // move_finished
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->move_finished ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "move_finished", field);
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
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__feedback__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_Feedback", full_classname_dest, 55) == 0);
  }
  hotspot_action__action__PanAndTilt_Feedback * ros_message = _ros_message;
  {  // pan_feedback
    PyObject * field = PyObject_GetAttrString(_pymsg, "pan_feedback");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pan_feedback = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tilt_feedback
    PyObject * field = PyObject_GetAttrString(_pymsg, "tilt_feedback");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tilt_feedback = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__feedback__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_Feedback */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_Feedback");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_Feedback * ros_message = (hotspot_action__action__PanAndTilt_Feedback *)raw_ros_message;
  {  // pan_feedback
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pan_feedback);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pan_feedback", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tilt_feedback
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tilt_feedback);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tilt_feedback", field);
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
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool unique_identifier_msgs__msg__uuid__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * unique_identifier_msgs__msg__uuid__convert_to_py(void * raw_ros_message);
bool hotspot_action__action__pan_and_tilt__goal__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * hotspot_action__action__pan_and_tilt__goal__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__send_goal__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_SendGoal_Request", full_classname_dest, 63) == 0);
  }
  hotspot_action__action__PanAndTilt_SendGoal_Request * ros_message = _ros_message;
  {  // goal_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_id");
    if (!field) {
      return false;
    }
    if (!unique_identifier_msgs__msg__uuid__convert_from_py(field, &ros_message->goal_id)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // goal
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal");
    if (!field) {
      return false;
    }
    if (!hotspot_action__action__pan_and_tilt__goal__convert_from_py(field, &ros_message->goal)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__send_goal__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_SendGoal_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_SendGoal_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_SendGoal_Request * ros_message = (hotspot_action__action__PanAndTilt_SendGoal_Request *)raw_ros_message;
  {  // goal_id
    PyObject * field = NULL;
    field = unique_identifier_msgs__msg__uuid__convert_to_py(&ros_message->goal_id);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal
    PyObject * field = NULL;
    field = hotspot_action__action__pan_and_tilt__goal__convert_to_py(&ros_message->goal);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal", field);
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
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool builtin_interfaces__msg__time__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * builtin_interfaces__msg__time__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__send_goal__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_SendGoal_Response", full_classname_dest, 64) == 0);
  }
  hotspot_action__action__PanAndTilt_SendGoal_Response * ros_message = _ros_message;
  {  // accepted
    PyObject * field = PyObject_GetAttrString(_pymsg, "accepted");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->accepted = (Py_True == field);
    Py_DECREF(field);
  }
  {  // stamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "stamp");
    if (!field) {
      return false;
    }
    if (!builtin_interfaces__msg__time__convert_from_py(field, &ros_message->stamp)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__send_goal__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_SendGoal_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_SendGoal_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_SendGoal_Response * ros_message = (hotspot_action__action__PanAndTilt_SendGoal_Response *)raw_ros_message;
  {  // accepted
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->accepted ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "accepted", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // stamp
    PyObject * field = NULL;
    field = builtin_interfaces__msg__time__convert_to_py(&ros_message->stamp);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "stamp", field);
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
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool unique_identifier_msgs__msg__uuid__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * unique_identifier_msgs__msg__uuid__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__get_result__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[65];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_GetResult_Request", full_classname_dest, 64) == 0);
  }
  hotspot_action__action__PanAndTilt_GetResult_Request * ros_message = _ros_message;
  {  // goal_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_id");
    if (!field) {
      return false;
    }
    if (!unique_identifier_msgs__msg__uuid__convert_from_py(field, &ros_message->goal_id)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__get_result__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_GetResult_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_GetResult_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_GetResult_Request * ros_message = (hotspot_action__action__PanAndTilt_GetResult_Request *)raw_ros_message;
  {  // goal_id
    PyObject * field = NULL;
    field = unique_identifier_msgs__msg__uuid__convert_to_py(&ros_message->goal_id);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_id", field);
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
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__functions.h"

bool hotspot_action__action__pan_and_tilt__result__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * hotspot_action__action__pan_and_tilt__result__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__get_result__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[66];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_GetResult_Response", full_classname_dest, 65) == 0);
  }
  hotspot_action__action__PanAndTilt_GetResult_Response * ros_message = _ros_message;
  {  // status
    PyObject * field = PyObject_GetAttrString(_pymsg, "status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->status = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // result
    PyObject * field = PyObject_GetAttrString(_pymsg, "result");
    if (!field) {
      return false;
    }
    if (!hotspot_action__action__pan_and_tilt__result__convert_from_py(field, &ros_message->result)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__get_result__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_GetResult_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_GetResult_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_GetResult_Response * ros_message = (hotspot_action__action__PanAndTilt_GetResult_Response *)raw_ros_message;
  {  // status
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // result
    PyObject * field = NULL;
    field = hotspot_action__action__pan_and_tilt__result__convert_to_py(&ros_message->result);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "result", field);
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
// #include "hotspot_action/action/detail/pan_and_tilt__struct.h"
// already included above
// #include "hotspot_action/action/detail/pan_and_tilt__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool unique_identifier_msgs__msg__uuid__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * unique_identifier_msgs__msg__uuid__convert_to_py(void * raw_ros_message);
bool hotspot_action__action__pan_and_tilt__feedback__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * hotspot_action__action__pan_and_tilt__feedback__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool hotspot_action__action__pan_and_tilt__feedback_message__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[63];
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
    assert(strncmp("hotspot_action.action._pan_and_tilt.PanAndTilt_FeedbackMessage", full_classname_dest, 62) == 0);
  }
  hotspot_action__action__PanAndTilt_FeedbackMessage * ros_message = _ros_message;
  {  // goal_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_id");
    if (!field) {
      return false;
    }
    if (!unique_identifier_msgs__msg__uuid__convert_from_py(field, &ros_message->goal_id)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // feedback
    PyObject * field = PyObject_GetAttrString(_pymsg, "feedback");
    if (!field) {
      return false;
    }
    if (!hotspot_action__action__pan_and_tilt__feedback__convert_from_py(field, &ros_message->feedback)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * hotspot_action__action__pan_and_tilt__feedback_message__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PanAndTilt_FeedbackMessage */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("hotspot_action.action._pan_and_tilt");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PanAndTilt_FeedbackMessage");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  hotspot_action__action__PanAndTilt_FeedbackMessage * ros_message = (hotspot_action__action__PanAndTilt_FeedbackMessage *)raw_ros_message;
  {  // goal_id
    PyObject * field = NULL;
    field = unique_identifier_msgs__msg__uuid__convert_to_py(&ros_message->goal_id);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // feedback
    PyObject * field = NULL;
    field = hotspot_action__action__pan_and_tilt__feedback__convert_to_py(&ros_message->feedback);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "feedback", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
