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

bool Vecteur3D::operator!=(const Vecteur3D& v) const
{
  return not compare(v);
}

bool Vecteur3D::operator==(const Vecteur3D& v) const 
{
  return compare(v);
}

ostream& operator<<(ostream& sortie, Vecteur3D v) {
  v.affiche();
  return sortie;
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

Vecteur3D Vecteur3D::addition(const Vecteur3D& v) const
{
  Vecteur3D sum;
  for(uint i(0); i<3; i++)
  {
    sum.set_coord(i, this->get_coord(i)+v.get_coord(i));
  }
  return sum;
}

const Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2) {
  return v1.addition(v2); 
}

Vecteur3D Vecteur3D::soustraction(const Vecteur3D& v) const
{
  Vecteur3D diff;
  for(uint i(0); i<3; i++)
  {
    diff.set_coord(i, this->get_coord(i)-v.get_coord(i));
  }
  return diff;
}

Vecteur3D Vecteur3D::oppose() const
{
  Vecteur3D opp;
  for(uint i(0); i<3; i++)
  {
    opp.set_coord(i, (-1)*this->get_coord(i));
  }
  return opp;
}

Vecteur3D Vecteur3D::mult(double lambda) const
{
  Vecteur3D mul;
  for(uint i(0); i<3; i++)
  {
    mul.set_coord(i, lambda*this->get_coord(i));
  }
  return mul;
}

double Vecteur3D::prod_scal(const Vecteur3D& v) const
{
  double scal(0);
  for(uint i(0); i<3; i++) {scal += this->get_coord(i)*v.get_coord(i);}
  return scal;
}

Vecteur3D Vecteur3D::prod_vect(const Vecteur3D& v) const
{
  Vecteur3D prod;

  prod.set_coord(0, this->get_coord(1)*v.get_coord(2) -
                    this->get_coord(2)*v.get_coord(1));
  prod.set_coord(1, this->get_coord(2)*v.get_coord(0) -
                    this->get_coord(0)*v.get_coord(2));
  prod.set_coord(2, this->get_coord(0)*v.get_coord(1) -
                    this->get_coord(1)*v.get_coord(0));

  return prod;
}

double Vecteur3D::norme2() const
{
  return pow(this->get_coord(0), 2) + pow(this->get_coord(1), 2) +
         pow(this->get_coord(2), 2);
}

double Vecteur3D::norme() const
{
  return sqrt(this->norme2());
}

Vecteur3D Vecteur3D::unitaire() const {return this->mult(1/this->norme());}
