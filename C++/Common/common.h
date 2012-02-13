#include "hermes2d.h"

using namespace Hermes;
using namespace Hermes::Hermes2D;

double calculate_point_value(Solution<double>* sln, int value, double x, double y);

double calculate_integral(Solution<double>* sln, int value, Hermes::vector<int> elementIDs);
