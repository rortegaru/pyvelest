cimport cython
from libc.stdlib cimport free
from c_func cimport get_a_c_string


cdef extern from "velest.h":
     void c_velest()

def r_velest():
	#Exposes a c function to python
    c_velest()


def r_foutput():
cdef char* c_string = NULL
cdef Py_ssize_t length = 0

# get pointer and length from a C function
get_a_c_string(&c_string, &length)

try:
py_bytes_string = c_string[:length] # Performs a copy of the data
finally:
free(c_string)

return py_bytes_string
