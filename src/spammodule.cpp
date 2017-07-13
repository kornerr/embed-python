
#include <Python.h>

// Method.

static PyObject *spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    if (!PyArg_ParseTuple(args, "s", &command))
        return 0;
    int result = system(command);
    return PyLong_FromLong(result);
}

// Method table.

static PyMethodDef SpamMethods[] =
{
    {"system", spam_system, METH_VARARGS, "Execute a shell command"},
    {0, 0, 0, 0}
};

// Module definition structure.

static struct PyModuleDef spammodule =
{
    PyModuleDef_HEAD_INIT,
    "spam", // Module name.
    0, // Module documentation.
    -1, // Size of per-interpreter state of the module. Here we keep the state in global variables.
    SpamMethods
};

PyMODINIT_FUNC PyInit_spam()
{
    return PyModule_Create(&spammodule);
}
