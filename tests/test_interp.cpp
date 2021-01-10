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
    double x[3] = {0.5, 0.5, 0.5};
    double fp[2][2][2] = {0};

    double interped = interp::interp_trilinear(x, fp);
    REQUIRE( interped == 0 );
}
