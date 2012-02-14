#ifndef POISSON_DEFINITIONS_H
#define POISSON_DEFINITIONS_H

#define HERMES_REPORT_ALL
#include "hermes2d.h"
#include "../Common/hermes_module.h"

using namespace Hermes;
using namespace Hermes::Hermes2D;
using namespace Hermes::Hermes2D::WeakFormsH1;
using namespace Hermes::Hermes2D::Views;

/* Weak forms */

class CustomWeakFormPoisson : public WeakForm<double>
{
public:
  CustomWeakFormPoisson(Hermes1DFunction<double>* thermalConductivity, Hermes2DFunction<double>* volumeHeatSource);
};

class ModulePoisson : public Module
{
public:
  ModulePoisson(Mesh* mesh, int polynomialDegree, int noOfInitialRefinements, double boundaryTemperature, double thermalConductivity, double volumeHeatSource);

  bool calculate();
  
  // value - { 0 - fn value, 1 - dx, 2 - dy }
  std::string get_solution(int value);
private:
  int polynomialDegree;
  int noOfInitialRefinements;
  double boundaryTemperature;
  double thermalConductivity;
  double volumeHeatSource;
};

#endif
