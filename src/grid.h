#include <array>

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
  // Constructor
  Grid(const std::array <double, 3> grid_spacing,
       const std::array <double, nx * ny * nz * 3> &vecs){
         GridSpacing = grid_spacing;
         Vecs = vecs;
       };
};

} // end namespace "grid"
#endif
