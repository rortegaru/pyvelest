cimport cython
import numpy as np
cimport numpy as np



DTYPE = np.float
ctypedef np.float_t DTYPE_t


cdef extern from "velest.h":
     void c_velest()

def r_velest():
	#Exposes a c function to python
    c_velest()



