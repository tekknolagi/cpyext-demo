#include "Python.h"

PyObject* inc(PyObject* module, PyObject* obj) {
  (void)module;
  long obj_int = PyLong_AsLong(obj);
  if (obj_int == -1 && PyErr_Occurred()) {
    return NULL;
  }
  return PyLong_FromLong(obj_int+1);
}

static PyMethodDef myext_methods[] = {
    {"inc", inc, METH_O, "Add one to an int"},
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
