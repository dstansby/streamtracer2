#include <array>
#include <algorithm>
#include <iostream>

#include "grid.h"

int main()
{
  // Grid shape
  const int nx = 2;
  const int ny = 3;
  const int nz = 4;
  // Grid spacing
  const std::array <double, 3> grid_spacing = {1, 2, 3};
  // Grid vectors
  double vecs[3][nx][ny][nz] = {[0 ... 2][0 ... 1][0 ... 2][0 ... 3] = 5};
  const std::array <double, 3> grid_center = {0, 0, 0};

  // Create grid object
  grid::Grid<nx, 3, 4> grid1(grid_spacing, grid_center, vecs);

  std::array <double, 3> x = {1, 1.9, 1};
  for (int i=0; i<3; ++i){
    std::cout << grid1.interp(x)[i] << std::endl;
  }
  return 0;
}
