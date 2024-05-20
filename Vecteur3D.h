#pragma once
#include <iostream>
#include <array>

class Vecteur3D
{
  private:
  std::array<double, 3> vect_;
  // Choix d'un array car le travail en boucle est beaucoup plus simple quand
  // on aimerait traiter plusieurs vecteurs et toutes leurs composantes à la
  // suite.

  public:

  Vecteur3D(double x=0, double y=0, double z=0) : vect_({x, y, z}) {}
  // Constructeur et constructeur par défaut de la classe Vecteur3D.
  // Le vecteur par défaut créé est le vecteur nul

  std::ostream& affiche(std::ostream& sortie) const;
  // Méthode d'affichage de Vecteur3D

  void set_coord(uint i, double x);
  // Met la i-ème composante de this égale à la valeur donnée (0=x, 1=y, 2=z).
  // Message d'erreur si i > 2.

  double get_coord(uint i) const;
  // Retourne la valeur de la i-ème composante de this. Il faut gérer une
  // exception si i > 2.

  double norme2() const;
  // Retourne la norme au carré de this

  double norme() const;
  // Retourne la norme de this.

  bool operator==(Vecteur3D const& autre) const;
  // Opérateur de comparaison entre deux vecteurs

  bool operator!=(Vecteur3D const& autre) const;
  // Opérateur de comparaison entre deux vecteurs

  const Vecteur3D& operator+=(Vecteur3D const& autre);
  // Addition par surcharge interne, ajoute à this les composantes du vecteur autre

  const Vecteur3D& operator-=(Vecteur3D const& autre);
  // Soustraction par surcharge interne, retire à this les composantes du vecteur autre

  const Vecteur3D& operator^=(Vecteur3D const& autre);
  // Produit vectoriel par surcharge interne, this devient le produit vectoriel de this et autre

  const Vecteur3D& operator*=(double const lambda);
  // Multiplication par un scalaire par surcharge interne

  const Vecteur3D& operator/=(double const lambda);
  // Division par un scalaire par surcharge interne

  double operator*(Vecteur3D const& v) const;
  // Opérateur interne du produit scalaire entre this et v

  Vecteur3D operator~() const;
  // Retourne le vecteur unitaire associé à this.
};

const Vecteur3D operator+(Vecteur3D v1, Vecteur3D const& v2);
// Opérateur d'addition de vecteurs

const Vecteur3D operator-(Vecteur3D v1, Vecteur3D const& v2);
// Opérateur de soustraction de vecteurs

const Vecteur3D operator-(Vecteur3D const& autre);
// Opérateur de l'opposé de vecteurs

const Vecteur3D operator^(Vecteur3D v, Vecteur3D const& v2);
// Opérateur de produit vectoriel de vecteurs

const Vecteur3D operator*(Vecteur3D v, double const lambda);
// Opérateur de multiplication de vecteurs par scalaires

const Vecteur3D operator/(Vecteur3D v, double const lambda);
// Opérateur de division de vecteurs par scalaires

std::ostream& operator<<(std::ostream& sortie, Vecteur3D const& v);
// Opérateur d'affichage de vecteurs
