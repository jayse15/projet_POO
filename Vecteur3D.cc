#include "Vecteur3D.h"
#include "utils.h"
using namespace std;

void Vecteur3D::set_coord(uint i, double x)
{
  if (i > 2) {cerr << "False indexing !!" << endl;}
  else {vect_[i] = x;}
}

double Vecteur3D::get_coord(uint i) const
{
  if (i > 2) {throw "False indexing !!";}
  return vect_[i];
}

void Vecteur3D::affiche() const
{
  for(auto coord:vect_){cout << coord << " ";}
  cout << endl;
}

bool Vecteur3D::compare(const Vecteur3D& v, double precision) const
{
  for(uint i(0); i<3; i++)
  {
    if(round_to_decimal(v.get_coord(i), precision) !=
       round_to_decimal(this->get_coord(i), precision)) {return false;}
  }
  return true;
}
