#include "Vecteur3D.h"
#include "utils.h"
using namespace std;

// *****************************************************************************
// Méthodes de la classe Vecteur3D
// *****************************************************************************

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

ostream& Vecteur3D::affiche(ostream& sortie) const
{
  for(auto coord:vect_){sortie << coord << " ";}
  return sortie;
}

bool Vecteur3D::compare(Vecteur3D const& autre, double precision) const
{
  for(uint i(0); i<3; i++)
  {
    if(round_to_decimal(autre.get_coord(i), precision) !=
       round_to_decimal(vect_[i], precision)) {return false;}
  }
  return true;
}

// *****************************************************************************
// Opérateurs internes de la classe Vecteur3D
// *****************************************************************************

bool Vecteur3D::operator==(Vecteur3D const& autre) const
{
  return this->compare(autre);
}

bool Vecteur3D::operator!=(Vecteur3D const& autre) const
{
  return not this->compare(autre);
}

const Vecteur3D& Vecteur3D::operator+=(Vecteur3D const& autre) {
  for (uint i(0); i<3; i++) {vect_[i] += autre.get_coord(i);}
  return *this;
}


const Vecteur3D& Vecteur3D::operator-=(Vecteur3D const& autre) {
  for (uint i(0); i<3; i++) {vect_[i] -= autre.get_coord(i);}
  return *this;
}

const Vecteur3D& Vecteur3D::operator^=(Vecteur3D const& autre) {
  vect_ = {vect_[1]*autre.get_coord(2) - vect_[2]*autre.get_coord(1),
           vect_[2]*autre.get_coord(0) - vect_[0]*autre.get_coord(2),
           vect_[0]*autre.get_coord(1) - vect_[1]*autre.get_coord(0)};
  return *this;
}

const Vecteur3D& Vecteur3D::operator*=(double const lambda) {
  for (uint i(0); i<3; i++) {vect_[i] *= lambda;}
  return *this;
}

const Vecteur3D& Vecteur3D::operator/=(double const lambda) {
  return *this*=(1/lambda);
}

double Vecteur3D::operator*(Vecteur3D const& v) const{
  double scal(0);
  for(uint i(0); i<3; i++) {scal += vect_[i]*v.get_coord(i);}
  return scal;
}

double Vecteur3D::norme2() const
{
  return pow(vect_[0], 2) + pow(vect_[1], 2) + pow(vect_[2], 2);
}

double Vecteur3D::norme() const
{
  return sqrt(this->norme2());
}

Vecteur3D Vecteur3D::operator~() const {return *this/this->norme();}

// *****************************************************************************
// Opérateurs externes de la classe Vecteur3D
// *****************************************************************************

const Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2) {return v1+=v2;}

const Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2) {return v1-=v2;}

const Vecteur3D operator^(Vecteur3D v1, Vecteur3D const& v2) {return v1^=v2;}

const Vecteur3D operator-(Vecteur3D const& autre) {
  Vecteur3D v;
  return v-autre;
}

const Vecteur3D operator*(Vecteur3D v, double const lambda) {return v*=lambda;}

const Vecteur3D operator/(Vecteur3D v, double const lambda) {return v/=lambda;}

ostream& operator<<(ostream& sortie, Vecteur3D const& v) {
  return v.affiche(sortie);
}
