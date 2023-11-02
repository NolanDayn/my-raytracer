#ifndef RTWEEKEND_H
#define RTWEEKEND_H

/*
* This file contains constants and helper functions
* used in raytracer in a weekend guide.
*/

#include <cmath>
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

//Common headers
#include "interval.h"
#include "ray.h"
#include "vec3.h"

#endif