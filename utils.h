#pragma once
#include <iostream>

typedef unsigned int uint;

constexpr double PRECISION = 1e-10; // utilisée pour la comparaison de vecteurs

constexpr double EPSILON = 1; // =0.1 [nm] (~rayon d'une particule)

constexpr double k_B = 1.38e-23; // constante de Boltzman

double round_to_decimal(double x, double precision = PRECISION);
