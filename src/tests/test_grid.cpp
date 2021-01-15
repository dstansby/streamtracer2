#include <array>

#include "catch.hpp"
#include "../grid.h"


TEST_CASE( "Interpolation", "[interp]" ) {
  // Grid shape
  // This is just a simple cube
  const int nx = 2;
  const int ny = 2;
  const int nz = 2;
  // Grid spacing, different in each dimension
  const std::array <double, 3> grid_spacing = {1, 2, 3};
  // Grid vectors
  // Populate with 5 in the x direction, 0 in {y, z} directions
  double vecs[3][nx][ny][nz];
  for (int i=0; i<nx; i++){
    for (int j=0; j<ny; j++){
      for (int k=0; k<nz; k++){
        // Set to zero on z=0 face
        vecs[0][i][j][k] = 5.*k;
        vecs[1][i][j][k] = 0.;
        vecs[2][i][j][k] = 0.;
      }
    }
  }
  const std::array <double, 3> grid_center = {0, 0, 0};

  // Create grid object
  grid::Grid<nx, ny, nz> grid1(grid_spacing, grid_center, vecs);

  std::array <double, 3> x;
  std::array <double, 3> interped;

  x = {1, 2, 0};
  interped = grid1.interp(x);
  REQUIRE( interped == std::array<double, 3> {0, 0, 0});

  x = {1, 2, 3};
  interped = grid1.interp(x);
  REQUIRE( interped == std::array<double, 3> {5, 0, 0});

  x = {1, 2, 2};
  interped = grid1.interp(x);
  REQUIRE( interped[0] == Approx(5.*2./3.));
  REQUIRE( interped[1] == 0.);
  REQUIRE( interped[2] == 0.);
}
