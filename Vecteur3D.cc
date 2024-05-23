#include "Vecteur3D.h"
#include "utils.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

// *****************************************************************************
// Méthodes de la classe Vecteur3D
// *****************************************************************************

ostream& Vecteur3D::affiche(ostream& sortie) const{
  for(auto& coord:vect_){sortie << coord << " ";}
  return sortie;
}

void Vecteur3D::set_coord(uint i, double x)
{
  if (i > 2) {throw invalid_argument("False indexing !!");}
  else {vect_[i] = x;}
}

double Vecteur3D::get_coord(uint i) const
{
  if (i > 2) {throw invalid_argument("False indexing !!");}
  return vect_[i];
}

double Vecteur3D::norme2() const
{
  return pow(vect_[0], 2) + pow(vect_[1], 2) + pow(vect_[2], 2);
}

double Vecteur3D::norme() const
{
  return sqrt(this->norme2());
}

// *****************************************************************************
// Opérateurs internes de la classe Vecteur3D
// *****************************************************************************

bool Vecteur3D::operator==(Vecteur3D const& autre) const
{
  for(size_t i(0); i<3; i++)
  {
    if(round_to_decimal(autre.vect_[i]) !=
       round_to_decimal(vect_[i])) {return false;}
  }
  return true;
}

bool Vecteur3D::operator!=(Vecteur3D const& autre) const
{
  return not(*this==autre);
}

const Vecteur3D& Vecteur3D::operator+=(Vecteur3D const& autre) {
  for (uint i(0); i<3; i++) {vect_[i] += autre.vect_[i];}
  return *this;
}


const Vecteur3D& Vecteur3D::operator-=(Vecteur3D const& autre) {
  for (uint i(0); i<3; i++) {vect_[i] -= autre.vect_[i];}
  return *this;
}

const Vecteur3D& Vecteur3D::operator^=(Vecteur3D const& autre) {
  vect_ = {vect_[1]*autre.vect_[2] - vect_[2]*autre.vect_[1],
           vect_[2]*autre.vect_[0] - vect_[0]*autre.vect_[2],
           vect_[0]*autre.vect_[1] - vect_[1]*autre.vect_[0]};
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
  for(uint i(0); i<3; i++) {scal += vect_[i]*v.vect_[i];}
  return scal;
}

Vecteur3D Vecteur3D::operator~() const {return *this/this->norme();}

// *****************************************************************************
// Opérateurs externes de la classe Vecteur3D
// *****************************************************************************

const Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2) {return v1+=v2;}

const Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2) {return v1-=v2;}

const Vecteur3D operator-(Vecteur3D const& autre) {
  Vecteur3D v;
  return v-autre;
}

const Vecteur3D operator^(Vecteur3D v1, Vecteur3D const& v2) {return v1^=v2;}

const Vecteur3D operator*(Vecteur3D v, double const lambda) {return v*=lambda;}

const Vecteur3D operator/(Vecteur3D v, double const lambda) {return v/=lambda;}

ostream& operator<<(ostream& sortie, Vecteur3D const& v) {
  v.affiche(sortie);
  return sortie;
}
