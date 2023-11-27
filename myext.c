#include "Python.h"

long inc_impl(long arg) {
  return arg+1;
}

PyObject* inc(PyObject* module, PyObject* obj) {
  (void)module;
  long obj_int = PyLong_AsLong(obj);
  if (obj_int == -1 && PyErr_Occurred()) {
    return NULL;
  }
  long result = inc_impl(obj_int);
  return PyLong_FromLong(result);
}

enum ObjectType {
  T_OBJECT,
  T_INT,
};

struct TypedMethodMetadata {
  enum ObjectType arg_type;
  enum ObjectType ret_type;
  void* underlying_func;
  const char ml_name[100];
};

struct TypedMethodMetadata inc_sig = {
  .arg_type = T_INT,
  .ret_type = T_INT,
  .underlying_func = inc_impl,
  .ml_name = "inc",
};

static PyMethodDef myext_methods[] = {
    {inc_sig.ml_name, inc, METH_O, "Add one to an int"},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef myext_definition = {
    PyModuleDef_HEAD_INIT, "myext",
    "A Python module that shows CFBolz how to write C extensions.", -1,
    myext_methods,
    NULL,
    NULL,
    NULL,
    NULL};

PyMODINIT_FUNC PyInit_myext(void) {
  return PyModule_Create(&myext_definition);
}
