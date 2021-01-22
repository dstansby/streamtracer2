#include <array>
#include <iostream>
#include <cmath>

#include "interp.h"

#ifndef grid_h
#define grid_h

namespace grid
{
template<const int nx, const int ny, const int nz>
class Grid{
public:
  // Attributes
  std::array <double, 3> GridSpacing;
  const double (&Vecs)[3][nx][ny][nz];
  std::array <double, 3> GridCenter;
  /*
  Constructor

  Parameters
  ----------
  grid_spacing: spacing of the grid in each dimension
  grid_center: location of the origin of the grid
  vecs: vector array
  */
  Grid(const std::array <double, 3> grid_spacing,
       const std::array <double, 3> grid_center,
       const double (&vecs)[3][nx][ny][nz]):
       Vecs(vecs),
       GridSpacing(grid_spacing),
       GridCenter(grid_center)
       {}

  // Methods
  std::array <double, 3> interp(const std::array <double, 3> x){
    /*
    Given point within the grid, interpolate a vector at that point.
    */
    // Calculate which cell this point is in
    const std::array <int, 3> idx = cell_idx(x);
    // Calculate distance along each dimension
    double dist[3];
    for (int i=0; i<3; i++){
      dist[i] = (x[i] / GridSpacing[i]) - idx[i];
    }
    // Get the local cell corner vectors
    double cellVecs[3][2][2][2];
    for (int i=0; i<2; i++){
      for (int j=0; j<2; j++){
        for (int k=0; k<2; k++){
          for (int a=0; a<3; a++){
            cellVecs[a][i][j][k] = Vecs[a][idx[0]+i][idx[1]+j][idx[2]+k];
          }
        }
      }
    }
    // Interpolate over each vector component
    std::array <double, 3> out;
    for (int i=0; i<3; i++){
      out[i] = interp::interp_trilinear(dist, cellVecs[i]);
    }
    return out;
  }

  void RK4_update(std::array <double, 3> &x,
                  const double ds,
                  const int dir){
    /*
    Update a position vector *x* by a single RK4 step along the vector grid.

    Parameters
    ----------
    x: position (updated in place by this method)
    ds: step size
    dir : step direction (must be 1 or -1)
    */
    std::array <double, 3> v;

    // Step 1
    std::array <double, 3> dx1;
    stream_function(x, ds, dir, dx1);
    // Step 2
    std::array <double, 3> x2, dx2;
    for (int i=0; i<3; i++){x2[i] = x[i] + 0.5*dx1[i];}
    stream_function(x2, ds, dir, dx2);
    // Step 3
    std::array <double, 3> x3, dx3;
    for (int i=0; i<3; i++){x3[i] = x[i] + 0.5*dx2[i];}
    stream_function(x3, ds, dir, dx3);
    // Step 4
    std::array <double, 3> x4, dx4;
    for (int i=0; i<3; i++){x4[i] = x[i] + dx3[i];}
    stream_function(x4, ds, dir, dx4);

    // Combine the steps together
    for (int i=0; i<3; i++){
      x[i] = x[i] + (dx1[i] + 2*dx2[i] + 2*dx3[i] + dx4[i]) / 6.;
    }
  }

  bool is_in_bounds(const double x[3]){
    // Check if x is within bounds of the grid
    bool in_bounds = 1;
    int lower_index[3] = {0, 0, 0};
    int upper_index[3] = {nx-1, ny-1, nz-1};
    std::array <double, 3> lower_corner = coordinate(lower_index);
    std::array <double, 3> upper_corner = coordinate(upper_index);
    for (int i=0; i<3; i++){
      in_bounds = in_bounds & (lower_corner[i] <= x[i]);
      in_bounds = in_bounds & (x[i] <= upper_corner[i]);
    }
    return in_bounds;
  }

private:
  std::array <int, 3> cell_idx(const std::array <double, 3> x){
    /*
    Given point within the grid, return the index of the cell
    that it resides in.
    */
    std::array <int, 3> out;
    for (int i=0; i<3; i++){
      out[i] = floor((x[i] - GridCenter[i]) / GridSpacing[i]);
    }
    return out;
  }

  void stream_function(const std::array <double, 3> &x,
                       const double ds,
                       const int dir,
                       std::array <double, 3> &dx_out){
    /*
    Calculate the normalised step vector at position *x*.

    Parameters
    ----------
    x: position
    ds: step size
    dir: step direction
    Ouput
    -----
    dx_out: step vector
    */
    dx_out = interp(x);
    double vmag = std::sqrt(std::pow(dx_out[0], 2) +
                            std::pow(dx_out[1], 2) +
                            std::pow(dx_out[2], 2));
    double step_size = dir * ds / vmag;
    for (int i=0; i<3; i++){
      dx_out[i] = dx_out[i] * step_size;
    }
  }


  std::array <double, 3> coordinate(const int index[3])
  {
    std::array <double, 3> coord;
    for (int i=0; i<3; i++)
    {
      coord[i] = (GridSpacing[i] * index[i]) - GridCenter[i];
    }
    return coord;
  }
};

} // end namespace "grid"
#endif
