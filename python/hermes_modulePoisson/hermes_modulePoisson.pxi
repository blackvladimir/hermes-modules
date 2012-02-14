from hermes2d cimport PyMesh
from hermes_modulePoisson cimport *
from hermes_module cimport *

cdef class PyModulePoisson(PyModule):
  def __cinit__(self, mesh, int polynomialDegree, int noOfInitialRefinements, double boundaryTemperature, double thermalConductivity, double volumeHeatSource):
    self.thisptr=<Module*> new ModulePoisson((<PyMesh> mesh).thisptr, polynomialDegree, noOfInitialRefinements, boundaryTemperature, thermalConductivity, volumeHeatSource)
    
  def __dealloc__(self):
    del self.thisptr

  def calculate(self):
    return (<ModulePoisson*> self.thisptr).calculate()
    
  def get_solution(self, int value):
    return (<ModulePoisson*> self.thisptr).get_solution(value).c_str()