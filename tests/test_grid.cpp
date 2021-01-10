#include <array>

#include "catch.hpp"
#include "../src/grid.h"


TEST_CASE( "Grid indexing", "[grid_idxs]" ) {
  // Grid shape
  const int nx = 2;
  const int ny = 3;
  const int nz = 4;
  // Grid spacing
  const std::array <double, 3> grid_spacing = {1, 2, 3};
  // Grid vectors
  const std::array <double, nx * ny * nz * 3> vecs = {0};
  const std::array <double, 3> grid_center = {0, 0, 0};

  // Create grid object
  grid::Grid<nx, 3, 4> grid1(grid_spacing, grid_center, vecs);

  std::array <double, 3> x;
  std::array <int, 3> idxs;

  x = {1, 1.9, 1};
  idxs = grid1.cell_idx(x);
  REQUIRE ( idxs == std::array <int, 3> {1, 0, 0});

  x = {0.9, 2.1, 10.3};
  idxs = grid1.cell_idx(x);
  REQUIRE ( idxs == std::array <int, 3> {0, 1, 3});
}
