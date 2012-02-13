#define HERMES_REPORT_ALL
#include "definitions.h"

// This example shows how to solve a simple PDE that describes stationary 
// heat transfer in an object consisting of two materials (aluminum and 
// copper). The object is heated by constant volumetric heat sources
// (generated, for example, by a DC electric current). The temperature 
// on the boundary is fixed. We will learn how to:
//
//   - load the mesh,
//   - perform initial refinements,
//   - create a H1 space over the mesh,
//   - define weak formulation,
//   - select a matrix solver,
//   - assemble and solve the matrix system,
//   - output the solution and element orders in VTK format 
//     (to be visualized, e.g., using Paraview),
//   - visualize the solution using Hermes' native OpenGL-based functionality.
//
// PDE: Poisson equation -div(LAMBDA grad u) - VOLUME_HEAT_SRC = 0.
//
// Boundary conditions: Dirichlet u(x, y) = FIXED_BDY_TEMP on the boundary.
//
// Geometry: L-Shape domain (see file domain.mesh). 
//
// The following parameters can be changed:

// Matrix solver: SOLVER_AMESOS, SOLVER_AZTECOO, SOLVER_MUMPS,
// SOLVER_PETSC, SOLVER_SUPERLU, SOLVER_UMFPACK.
MatrixSolverType matrix_solver = SOLVER_UMFPACK;  

bool calculate(Mesh* mesh, int polynomialDegree, int noOfInitialRefinements, double boundaryTemperature, double thermalConductivity, double volumeHeatSource, bool wantFunctionValues, bool wantDx, bool wantDy)
{
  // Perform initial mesh refinements (optional).
  for (int i = 0; i < noOfInitialRefinements; i++) 
    mesh->refine_all_elements();

  // Initialize the weak formulation.
  CustomWeakFormPoisson wf(new Hermes1DFunction<double>(thermalConductivity), 
                           new Hermes2DFunction<double>(-volumeHeatSource));
  
  // Initialize essential boundary conditions.
  DefaultEssentialBCConst<double> bc_essential(
      Hermes::vector<std::string>("Bottom", "Inner", "Outer", "Left"), boundaryTemperature);
  EssentialBCs<double> bcs(&bc_essential);

  // Create an H1 space with default shapeset.
  H1Space<double> space(mesh, &bcs, polynomialDegree);
  
  // Initialize the FE problem.
  DiscreteProblem<double> dp(&wf, &space);

  // Initialize Newton solver.
  NewtonSolver<double> newton(&dp, matrix_solver);

  // Perform Newton's iteration.
  try
  {
    newton.solve();
  }
  catch(Hermes::Exceptions::Exception e)
  {
    e.printMsg();
    error("Newton's iteration failed.");
    return false;
  }

  // Translate the resulting coefficient vector into a Solution.
  Solution<double> sln;
  Solution<double>::vector_to_solution(newton.get_sln_vector(), &space, &sln);


  // Output solution in VTK format.
  Linearizer lin;
  if(wantFunctionValues)
    lin.save_solution_vtk(&sln, "sln-fn.vtk", "Temperature", true, H2D_FN_VAL_0);
  if(wantDx)
    lin.save_solution_vtk(&sln, "sln-dx.vtk", "D(Temperature)Dx", true, H2D_FN_DX_0);
  if(wantDy)
    lin.save_solution_vtk(&sln, "sln-dy.vtk", "D(Temperature)Dy", true, H2D_FN_DY_0);

  return true;
}

