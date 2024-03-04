#pragma once
#include <iostream>
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
  // Met la i-ème composante du vecteur égale à la valeur donnée (0=x, 1=y, 2=z).
  // Message d'erreur si i > 2.

  double get_coord(uint i) const;
  // Retourne la valeur de la i-ème composante du vecteur. Il faut gérer une
  // exception si i > 2.

  void affiche() const;
  // Affiche les 3 coordonnées du vecteur.

  bool compare(const Vecteur3D& v, double precision = 1e-10) const;
  // Retourne true si le vecteur et v ont les mêmes composantes au "precision"
  // près, false sinon.

};
