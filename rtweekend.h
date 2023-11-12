#ifndef RTWEEKEND_H
#define RTWEEKEND_H

/*
* This file contains constants and helper functions
* used in raytracer in a weekend guide.
*/

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

//Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

//Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.14159265358979;

//Utility Functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    // Return a random real in [0,1]
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    //Returns a random real in [min,max]
    return min + (max-min)*random_double();
}

//Common headers
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif