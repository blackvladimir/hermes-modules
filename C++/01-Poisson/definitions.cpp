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
