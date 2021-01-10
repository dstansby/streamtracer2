#ifndef interp_h
#define interp_h

namespace interp
{
double interp_interval(double x, double xp[2], double fp[2]);
double interp_trilinear(double x[3], double f[2][2][2]);
}

#endif
