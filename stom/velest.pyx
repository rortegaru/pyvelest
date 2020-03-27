from libc.stdlib cimport free,malloc
from libc.stdio cimport printf
from libc.string cimport strcpy,strlen
#from c_func cimport get_a_c_string
#from c_func cimport c_call_returning_a_c_string


#import numpy as np
#cimport numpy as np

#DTYPE = np.float
#ctypedef np.float_t DTYPE_t


cdef extern from "velest.h":
     void c_velest()
     int getsizeoutput()
     void getoutput(char *)

def r_velest():	#Exposes a c function to python
    c_velest()

cdef bytes  b_get_output():
   cdef int m=getsizeoutput()
   cdef char* c_string=<char *> malloc((m+1) * sizeof(char))
   if not c_string:
      raise MemoryError()
   getoutput(c_string)
   cdef bytes py_string=c_string
   return py_string
#  printf("%s \n",c_string)


#cdef c_get_output():
#   cdef char* c_string=NULL
#   cdef Py_ssize_t length=0
#   get_a_c_string(&c_string,&length)
#3   try:
#    py_bytes_string=c_string[:length]
#  finally:
#    free(c_string)
#  return py_bytes_string

def r_output():
    pbytes=b_get_output()
    b=pbytes.decode('utf8')
    return b

