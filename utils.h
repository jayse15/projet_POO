#pragma once
#include <iostream>

typedef unsigned int uint;

constexpr double PRECISION = 1e-10;

constexpr double EPSILON = 1; // =0.001 nm

constexpr double k_B = 1.38e-23; 

constexpr double masse_Neon  = 20.1797; 

constexpr double masse_Argon  = 39.948; 

constexpr double masse_Helium  = 4.002602; 

double round_to_decimal(double x, double precision = PRECISION);