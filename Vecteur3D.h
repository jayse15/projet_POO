#pragma once
#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned int uint;

class Vecteur3D
{
  private:
  array<double, 3> vect_;
  // Choix d'un array car le travail en boucle est beaucoup plus simple quand
  // on aimerait traiter plusieurs vecteurs et toutes leurs composantes à la
  // suite.

  public:
  void set_coord(uint i, double x);
  // Met la i-ème composante de this égale à la valeur donnée (0=x, 1=y, 2=z).
  // Message d'erreur si i > 2.

  double get_coord(uint i) const;
  // Retourne la valeur de la i-ème composante de this. Il faut gérer une
  // exception si i > 2.

  void affiche() const;
  // Affiche les 3 coordonnées de this.

  bool compare(const Vecteur3D& v, double precision = 1e-10) const;
  // Retourne true si this et v ont les mêmes composantes au "precision"
  // près, false sinon.

  Vecteur3D addition(const Vecteur3D& v) const;
  // Retourne un vecteur avec comme composantes la somme des composantes de
  // this et de v.

  Vecteur3D soustraction(const Vecteur3D& v) const;
  // Retourne un vecteur avec comme composantes la différence des composantes de
  // this et de v.

  Vecteur3D oppose() const;
  // Retourne un vecteur avec comme composantes l'opposé des composantes de this.

  Vecteur3D mult(double lambda) const;
  // Retourne un vecteur avec comme composantes lambda fois chaque composante de
  // this.

  double prod_scal(const Vecteur3D& v) const;
  // Retourne le produit scalaire de this et de v.

  Vecteur3D prod_vect(const Vecteur3D& v) const;
  // Retourne un vecteur avec composantes associés au produit vectoriel de this
  // et de v.

  double norme2() const;
  // Retourne la norme au carré de this

  double norme() const;
  // Retourne la norme de this.

  Vecteur3D unitaire() const;
  // Retourne le vecteur unitaire associé à this.
};
