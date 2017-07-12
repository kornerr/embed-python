
#include <Python.h>

#include <iostream>
#include <string>

const char *pycode = R"(
import time

print('Today is', time.ctime(time.time()))
)";

int main(int argc, char *argv[])
{
    printf("Embed Python\n");

    wchar_t *program = Py_DecodeLocale(argv[0], 0);
    if (!program)
    {
        printf("Cannot decode program name from first CLI argument. Aborting.\n");
        exit(1);
    }
    Py_SetProgramName(program);
    Py_Initialize();

    PyRun_SimpleString(pycode);

    Py_Finalize();
    PyMem_RawFree(program);

    return 0;
}

