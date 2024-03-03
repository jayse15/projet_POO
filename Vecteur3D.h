#include <iostream>
using namespace std;

typedef unsigned int uint;

class Vecteur3D
{
  private:
  array<double, 3> vect_;

  public:
  void set_coord(uint i, double x);
  void affiche();

};
