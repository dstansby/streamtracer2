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
  std::array <int, 3> cell_idx(std::array <double, 3> x){
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

  const std::array <double, 3> interp(const std::array < double, 3> x){
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
            cellVecs[i][j][k][a] = Vecs[a][idx[0]+i][idx[1]+j][idx[2]+k];
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
};

} // end namespace "grid"
#endif
