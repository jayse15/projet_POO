#include "utils.h"
#include <cmath>
#include <iostream>
using namespace std;

double round_to_decimal(double x, double precision)
{
  return round(x/precision)*precision;
}
