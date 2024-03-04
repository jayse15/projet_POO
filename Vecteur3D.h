#include <iostream>
using namespace std;

typedef unsigned int uint;

class Vecteur3D
{
  private:
  array<double, 3> vect_;

  public:
  void set_coord(uint i, double x);
  double get_coord(uint i) const;
  void affiche() const;
  bool compare(const Vecteur3D& v, double precision = 1e-10) const;

};
