#pragma once
#include <iostream>
#include <cmath>


typedef unsigned int uint;

class Vecteur3D
{
  private:
  std::array<double, 3> vect_;
  // Choix d'un array car le travail en boucle est beaucoup plus simple quand
  // on aimerait traiter plusieurs vecteurs et toutes leurs composantes à la
  // suite.

  public:
  Vecteur3D(double x=0, double y=0, double z=0) {
    set_coord(0, x);
    set_coord(1, y);
    set_coord(2, z);
  }
  // Constructeur et constructeur par défaut de la classe Vecteur3D. 
  // Le vecteur par défaut créé est le vecteur nul

  Vecteur3D(Vecteur3D const& autre) 
    : vect_({autre.get_coord(0), autre.get_coord(1), autre.get_coord(2)}) {} 
  // Constructeur de copie pour la classe Vecteur3D

  void set_coord(uint i, double x);
  // Met la i-ème composante de this égale à la valeur donnée (0=x, 1=y, 2=z).
  // Message d'erreur si i > 2.

  double get_coord(uint i) const;
  // Retourne la valeur de la i-ème composante de this. Il faut gérer une
  // exception si i > 2.

  void affiche() const; 
  // Affiche les 3 coordonnées de this.

  bool operator==(Vecteur3D const& v) const;
  // Opérateur de comparaison entre deux vecteurs

  bool operator!=(Vecteur3D const& v) const;
  // Opérateur de comparaison entre deux vecteurs

  const Vecteur3D& operator+=(Vecteur3D const& autre); 
  // Addition par surcharge interne, ajoute à this les composantes du vecteur autre

  const Vecteur3D& operator-=(Vecteur3D const& autre); 
  // Soustraction par surcharge interne, retire à this les composantes du vecteur autre

  bool compare(const Vecteur3D& v, double precision = 1e-10) const;
  // Retourne true si this et v ont les mêmes composantes à une "precision"
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

  Vecteur3D operator*=(double const lambda);
  // Opérateur de la multiplication scalaire

  double prod_scal(const Vecteur3D& v) const;
  // Retourne le produit scalaire de this et de v
  
  double operator*(const Vecteur3D& v) const; 
  // Opérateur du produit scalaire entre this et v

  Vecteur3D prod_vect(const Vecteur3D& v) const;
  // Retourne un vecteur avec composantes associés au produit vectoriel de this
  // et de v.

  Vecteur3D operator^(const Vecteur3D& v) const; 
  // Operateur du produit vectoriel entre this et v

  double norme2() const;
  // Retourne la norme au carré de this

  double norme() const;
  // Retourne la norme de this.

  Vecteur3D unitaire() const;
  // Retourne le vecteur unitaire associé à this.

  Vecteur3D operator~() const; 
};
