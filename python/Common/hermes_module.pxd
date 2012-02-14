from libcpp cimport bool
from libcpp.string cimport string 
from libcpp.set cimport set as cSet
from libcpp.pair cimport pair
from ctypes cimport complex as cComplex

from hermes2d cimport Mesh, Solution
from hermes_common cimport *

cdef extern from "hermes_module.h":
  cdef cppclass Module:
    Module(Mesh* mesh)
    double calculate_point_value(Solution[double]* sln, int value, double x, double y)
    double calculate_integral(Solution[double]* sln, int value, vector[int] elementIDs)