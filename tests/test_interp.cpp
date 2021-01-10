#include "catch.hpp"
#include "../src/interp.h"


TEST_CASE( "Factorials are computed", "[interp_interval]" ) {
    double x = 1.0;
    double xp[2] = {0.0, 2.0};
    double fp[2] = {3.0, 5.0};

    double interped = interp::interp_interval(x, xp, fp);
    REQUIRE( interped == 4.0 );
}

TEST_CASE( "Trilinear interpolation", "[interp_trilinear]" ) {
    double interped;
    // Case with all zeros at corners
    double x[3] = {0.5, 0.5, 0.5};
    double fp[2][2][2] = {0};

    interped = interp::interp_trilinear(x, fp);
    REQUIRE( interped == 0 );

    // Case with all zeros on one face, ones on another
    for (int i=0; i<2; i++){
      for (int j=0; j<2; j++){
        for (int k=0; k<2; k++){
          fp[i][j][k] = float(i);
        }
      }

    }
    double x1[3] = {0.5, 0.5, 0.5};
    interped = interp::interp_trilinear(x1, fp);
    REQUIRE( interped == 0.5 );

    double x2[3] = {0.75, 0.5, 0.5};
    interped = interp::interp_trilinear(x2, fp);
    REQUIRE( interped == 0.75 );

    double x3[3] = {0.5, 0.75, 0.5};
    interped = interp::interp_trilinear(x3, fp);
    REQUIRE( interped == 0.5 );
}
