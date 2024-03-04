#include "utils.h"
using namespace std;


double round_to_decimal(double x, double precision)
{
  return round(x/precision)*precision;
}
