#include "definitions.h"

/* Weak forms */

CustomWeakFormPoisson::CustomWeakFormPoisson(Hermes1DFunction<double>* thermalConductivity, Hermes2DFunction<double>* volumeHeatSource) : WeakForm<double>(1)
{
  // Jacobian forms.
  add_matrix_form(new DefaultJacobianDiffusion<double>(0, 0, HERMES_ANY, thermalConductivity));

  // Residual forms.
  add_vector_form(new DefaultResidualDiffusion<double>(0, HERMES_ANY, thermalConductivity));
  add_vector_form(new DefaultVectorFormVol<double>(0, HERMES_ANY, volumeHeatSource));
};


ModulePoisson::ModulePoisson(Mesh* mesh, int polynomialDegree, int noOfInitialRefinements, double boundaryTemperature, double thermalConductivity, double volumeHeatSource) : Module(mesh), polynomialDegree(polynomialDegree), noOfInitialRefinements(noOfInitialRefinements), boundaryTemperature(boundaryTemperature), thermalConductivity(thermalConductivity), volumeHeatSource(volumeHeatSource)
{
}

bool ModulePoisson::calculate()
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
  NewtonSolver<double> newton(&dp, SOLVER_UMFPACK);

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
  Solution<double>::vector_to_solution(newton.get_sln_vector(), &space, &sln);

  return true;
}

std::string ModulePoisson::get_solution(int value)
{
  // Output solution in VTK format.
  Linearizer lin;
  if(value == 0)
    return lin.save_solution_vtk_to_stream(&sln, "Temperature", true, H2D_FN_VAL_0);
  else if(value == 1)
    return lin.save_solution_vtk_to_stream(&sln, "D(Temperature)Dx", true, H2D_FN_DX_0);
  else if(value == 2)
    return lin.save_solution_vtk_to_stream(&sln, "D(Temperature)Dy", true, H2D_FN_DY_0);
}



