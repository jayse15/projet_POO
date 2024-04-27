#pragma once
#include <iostream>

typedef unsigned int uint;

constexpr double PRECISION = 1e-10;

constexpr double EPSILON = 0.01; // =0.001 nm

double round_to_decimal(double x, double precision = PRECISION);
