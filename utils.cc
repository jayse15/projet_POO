#include "utils.h"
#include <cmath>

using namespace std;

double round_to_decimal(double x, double precision)
{
  return round(x/precision)*precision;
}
