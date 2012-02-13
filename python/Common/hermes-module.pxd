from libcpp cimport bool
from libcpp.string cimport string 
from libcpp.set cimport set as cSet
from libcpp.pair cimport pair
from ctypes cimport complex as cComplex
from hermes_common cimport *

include "../translate_exceptions/raise_exception.pxd"

cdef extern from "vector.h" namespace "Hermes":
  cdef cppclass vector[T]:
    vector()
    void push_back(T a)
    cppclass const_iterator:
      pass
    const_iterator begin()
    const_iterator end()
    int size()
    T at(int i)
    void clear()

cdef extern from "Common.h":
  cdef cppclass Module:
    Module(Mesh* mesh)
    double calculate_point_value(Solution[double]* sln, int value, double x, double y)
    double calculate_integral(Solution[double]* sln, int value, vector[int] elementIDs)
    
cdef class PyModule:
  cdef Module * thisptr
    