#include <array>
#include <math.h>

#ifndef grid_h
#define grid_h

namespace grid
{
template<const int nx, const int ny, const int nz>
class Grid{
public:
  // Attributes
  std::array <double, 3> GridSpacing;
  std::array <double, nx * ny * nz * 3> Vecs;
  std::array <double, 3> GridCenter;
  // Constructor
  Grid(const std::array <double, 3> grid_spacing,
       const std::array <double, 3> grid_center,
       const std::array <double, nx * ny * nz * 3> &vecs){
         /*
         Parameters
         ----------
         grid_spacing: spacing of the grid in each dimension
         grid_center: location of the origin of the grid
         vecs: vector array
         */
         GridSpacing = grid_spacing;
         Vecs = vecs;
         GridCenter = grid_center;
       };

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
};

} // end namespace "grid"
#endif
