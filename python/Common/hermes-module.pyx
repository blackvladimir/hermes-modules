include "../translate_exceptions/raise_exception.pxi"

import hermes_common
import hermes2d

cdef class PyModule:
  def __cinit__(self, mesh):
    if (type(self)!=PyModule):
      return
    self.thisptr=new Module((<hermes2d.PyMesh> mesh).thisptr)
  def __dealloc__(self):
    del self.thisptr

  def calculate_point_value(self, sln, int value, double x, double y):
    return self.thisptr.calculate_point_value((<hermes2d.PySolutionReal> sln).thisptr, value, x, y)

  def calculate_integral(self, sln, int value, elementIDs):
    cdef vector[int] celementIDs
    cdef int i
    for i in elementIDs:
      celementIDs.push_back(i)
    return self.thisptr.calculate_integral((<hermes2d.PySolutionReal> sln).thisptr, value, celementIDs)