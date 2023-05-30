#include <Python.h>
#include <floatobject.h>

void print_python_list(PyObject *p) {
    PyListObject *list = (PyListObject *)p;

    if (!PyList_Check(p)) {
        printf("[*] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = list->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", allocated);

    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(p, i);
        printf("Element %ld: ", i);

        if (PyBytes_Check(item)) {
            printf("bytes\n");
            
            PyBytesObject *bytes = (PyBytesObject *)item;

            if (!PyBytes_Check(item)) {
                printf("[.] Invalid Bytes Object\n");
                continue;
            }

            Py_ssize_t size = PyBytes_Size(item);
            char *string = PyBytes_AsString(item);

            printf("[.] bytes object info\n");
            printf("  size: %ld\n", size);
            printf("  trying string: %s\n", string);

            printf("  first 10 bytes:");
            Py_ssize_t j;
            for (j = 0; j < size && j < 10; j++) {
                printf(" %.2x", (unsigned char)string[j]);
            }
            printf("\n");
        } else if (PyFloat_Check(item)) {
            printf("float\n");
            
            PyFloatObject *f = (PyFloatObject *)item;

            if (!PyFloat_Check(item)) {
                printf("[.] Invalid Float Object\n");
                continue;
            }

            printf("[.] float object info\n");
            printf("  value: %f\n", f->ob_fval);
        } else if (PyLong_Check(item)) {
            printf("int\n");
        } else if (PyList_Check(item)) {
            printf("list\n");
        } else if (PyTuple_Check(item)) {
            printf("tuple\n");
        } else if (PyUnicode_Check(item)) {
            printf("str\n");
        } else {
            printf("unknown\n");
        }
    }
}

int main() {
    PyObject *p;
    Py_Initialize();

    // Your code here

    Py_Finalize();
    return 0;
}

