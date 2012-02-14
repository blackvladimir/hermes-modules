from libcpp cimport bool
from libcpp.string cimport string

from hermes2d cimport Mesh
from hermes_common cimport *
from hermes_module cimport *

cdef extern from "definitions.h":
  cdef cppclass ModulePoisson: #public Module
    ModulePoisson(Mesh* mesh, int polynomialDegree, int noOfInitialRefinements, double boundaryTemperature, double thermalConductivity, double volumeHeatSource)
    bool calculate()
    string get_solution(int value)