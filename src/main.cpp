#include <iostream>
#include "interp.h"

int main(int argc, char** argv)
{
  double x = 1.0;
  double xp[2] = {0.0, 2.0};
  double fp[2] = {2.0, 5.0};

  std::cout << interp::interp_interval(x, xp, fp) << std::endl;
  return 0;
}
