cimport cython
import numpy as np
cimport numpy as np



DTYPE = np.float
ctypedef np.float_t DTYPE_t


cdef extern from "velest.h":
     void velesta()

def c_velest():
	#Exposes a c function to python
     velesta()



