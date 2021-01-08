#include "interp.h"

namespace interp
{

double interp_interval(double x, double xp[2], double fp[2])
/*
Given a sample point within an interval, and the value of a function at the
interval end points, return a linear interpolation of the function.

Parameters
----------
x : sample point
xp : interval start and end points
fp : funciton values at xp
*/
{
  // Fraction along the interval
  double frac = (x - xp[0]) / (xp[1] - xp[0]);
  return fp[0] + frac * (fp[1] - fp[0]);
}

} // end namespace "interp"
