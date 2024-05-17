#pragma once
#include <iostream>

typedef unsigned int uint;

constexpr double PRECISION = 1e-10; // utilisée pour la comparaison de vecteurs

constexpr double EPSILON = 1; // =0.1 [nm] (~rayon d'une particule)

constexpr double k_B = 1.38e-23; // constante de Boltzman

constexpr double masse_Neon  = 20.1797; 

constexpr double masse_Argon  = 39.948; 

constexpr double masse_Helium  = 4.002602; 

double round_to_decimal(double x, double precision = PRECISION);