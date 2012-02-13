#define HERMES_REPORT_ALL
#include "common.h"

// value - { 0 - fn value, 1 - dx, 2 - dy }
double calculate_point_value(Solution<double>* sln, int value, double x, double y)
{
  if(value == 0)
    return sln->get_pt_value(x, y, H2D_FN_VAL_0);

  if(value == 0)
    return sln->get_pt_value(x, y, H2D_FN_DX_0);

  if(value == 0)
    return sln->get_pt_value(x, y, H2D_FN_DY_0);
}

// dummy so far
double calculate_integral(Solution<double>* sln, int value, Hermes::vector<int> elementIDs)
{
  double result = 0.;
  for(int i = 0; i < elementIDs.size(); i++)
  {
    Element* e = sln->get_mesh()->get_element(elementIDs[i]);
    double x = 0.;
    double y = 0.;
    if(e->get_num_surf() == 3)
    {
      x = (e->vn[0]->x + e->vn[1]->x + e->vn[2]->x) / 3;
      y = (e->vn[0]->y + e->vn[1]->y + e->vn[2]->y) / 3;
    } 
    else
    {
      x = (e->vn[0]->x + e->vn[1]->x + e->vn[2]->x + e->vn[3]->x) / 4;
      y = (e->vn[0]->y + e->vn[1]->y + e->vn[2]->y + e->vn[3]->y) / 4;
    }   

    result += calculate_point_value(sln, value, x, y) * e->get_area();
  }
}
