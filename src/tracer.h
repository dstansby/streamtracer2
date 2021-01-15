#include <array>

#include "grid.h"

#ifndef tracer_h
#define tracer_h

namespace tracer
{
template<const int nx, const int ny, const int nz>
class Tracer{
public:
  // Attributes
  grid::Grid <nx, ny, nz> Grid;
  // Reason of termination
  // 0 = still running
  // 1 = ran out of steps
  // 2 = out of bounds
  // -1 = got to vmag = 0
  // -2 = encountered NaN
  int ROT;

  /*
  Constructor

  Parameters
  ----------
  grid_spacing: spacing of the grid in each dimension
  grid_center: location of the origin of the grid
  vecs: vector array
  */
  Tracer(grid::Grid <nx, ny, nz> grid_in):
         Grid(grid_in)
         {}

  /*
  // Methods
  void trace_single(
    std::array <double, 3> x,
    const int max_steps,
    const int dir
  ){
    Trace from a single seed point.
    // Set up output, and populate first point with seed
    double traced[max_steps][3];
    for (int i=0; i<3; i++){
      traced[0][i] = x[i];
    }

    // Trace
    for (int i=1; i<max_steps; i++){
      try{
        RK4_update(x, ds, dir);
      }
      // TODO: define this custom exception
      catch (zero_mag_exception& e){
        ROT = -1;
        break;
      }
      // TODO: check for NaN here
      // TODO: implement check_bounds
      ROT = check_bounds(x);
      if (ROT != 0){
        break;
      }
      // Copy new position vector to output array
      for (int j=0; j<3; j++){
        traced[i][j] = x[j];
      }
    }

    return traced;
    */
  };
} // end namespace "tracer"
#endif
