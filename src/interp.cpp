#include "interp.h"

namespace interp
{

double interp_trilinear(double x[3], double f[2][2][2])
/*
Perform trilinear interpolation within a normalised cube.

Parameters
----------
x : Sample point. Each component must be in the range [0, 1].
f : Function values a the corner of the normalised cube.
*/
{
  double m_x[3];
  for (int i = 0; i < 3; ++i){
    m_x[i] = 1. - x[i];
  }
  // Inteprolate over first component (x)
  double c[2][2];
  c[0][0] = f[0][0][0] * m_x[0] + f[1][0][0] * x[0];
  c[1][0] = f[0][1][0] * m_x[0] + f[1][1][0] * x[0];
  c[0][1] = f[0][0][1] * m_x[0] + f[1][0][1] * x[0];
  c[1][1] = f[0][1][1] * m_x[0] + f[1][1][1] * x[0];
  // Inteprolate over second component (y)
  double c1[2];
  c1[0] = c[0][0] * m_x[1] + c[1][0] * x[1];
  c1[1] = c[0][1] * m_x[1] + c[1][1] * x[1];
  // Inteprolate over third component (z)
  return c1[0] * m_x[2] + c1[1] * x[2];
}

} // end namespace "interp"
