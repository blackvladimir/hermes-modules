#ifndef COMMON_HERMES_MODULE_H
#define COMMON_HERMES_MODULE_H

#include "hermes2d.h"

using namespace Hermes;
using namespace Hermes::Hermes2D;

class Module
{
public:
  Module(Mesh* mesh);

  // value - { 0 - fn value, 1 - dx, 2 - dy }
  double calculate_point_value(Solution<double>* sln, int value, double x, double y);

  // value - { 0 - fn value, 1 - dx, 2 - dy }
  double calculate_integral(Solution<double>* sln, int value, Hermes::vector<int> elementIDs);
protected:
  Solution<double> sln;
  Mesh* mesh;
};

#endif
