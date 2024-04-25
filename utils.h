#pragma once
#include <iostream>

typedef unsigned int uint;

constexpr double PRECISION = 1e-10;

constexpr double EPSILON = 1e-11; 

double round_to_decimal(double x, double precision = PRECISION);
