#pragma once
#include <iostream>

typedef unsigned int uint;

constexpr double PRECISION = 1e-10;

double round_to_decimal(double x, double precision = PRECISION);
