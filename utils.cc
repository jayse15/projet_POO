#include "utils.h"
#include <cmath>

using namespace std;

double round_to_decimal(double x, double precision)
{
  return round(x/precision)*precision;
}

int kroneckerDelta(int i, int j) {
    if (i == j) {return 1;}
    {return 0;}
}
