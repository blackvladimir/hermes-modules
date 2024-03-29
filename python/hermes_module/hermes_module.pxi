from hermes2d cimport PyMesh, PySolutionReal
from hermes_common cimport *

cdef class PyModule:
  def __cinit__(self, mesh):
    self.thisptr=new Module((<PyMesh> mesh).thisptr)
    
  def __dealloc__(self):
    del self.thisptr

  def calculate_point_value(self, sln, int value, double x, double y):
    return self.thisptr.calculate_point_value(<Solution[double]*> (<PySolutionReal> sln).thisptr, value, x, y)

  def calculate_integral(self, sln, int value, elementIDs):
    cdef vector[int] celementIDs
    cdef int i
    for i in elementIDs:
      celementIDs.push_back(i)
    return self.thisptr.calculate_integral(<Solution[double]*> (<PySolutionReal> sln).thisptr, value, celementIDs)
