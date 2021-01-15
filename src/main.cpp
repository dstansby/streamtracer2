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
  double vecs[3][nx][ny][nz];
  // Grid vectors
  for (int i=0; i<nx; i++){
    for (int j=0; j<ny; j++){
      for (int k=0; k<nz; k++){
        vecs[0][i][j][k] = 5.;
        vecs[1][i][j][k] = 0.;
        vecs[2][i][j][k] = 0.;
      }
    }
  }
  const std::array <double, 3> grid_center = {0, 0, 0};

  // Create grid object
  grid::Grid<nx, 3, 4> grid1(grid_spacing, grid_center, vecs);

  std::array <double, 3> x = {0.7, 1.9, 1};
  int dir = 1;
  double s = 0.1;
  grid1.RK4_update(x, s, dir);
  for (int i=0; i<3; ++i){
    std::cout << x[i] << std::endl;
  }
  return 0;
}
