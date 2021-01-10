#include <array>
#include <iostream>
#include "grid.h"

int main()
{
  const int nx = 2;
  const std::array <double, 3> grid_spacing = {1, 2, 3};
  const std::array <double, nx * 3 * 4 * 3> vecs = {0};
  grid::Grid<nx, 3, 4> grid1(grid_spacing, vecs);
  std::cout << grid1.GridSpacing[0] << std::endl;
  return 0;
}
