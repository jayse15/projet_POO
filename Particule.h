#pragma once
#include <iostream>
#include "utils.h"
#include "Vecteur3D.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "GenerateurAleatoire.h"

class Particule : public Dessinable
{
  protected :
    Vecteur3D position;
    Vecteur3D vitesse;
    const double masse;

    /* On utilise des Vecteurs3D comme position et vitesse pour pouvoir utiliser
     * les opérations définies dans la classe Vecteur3D */

  public :
    Particule(Vecteur3D p, Vecteur3D v, double m)
      : position(p), vitesse(v), masse(m) {}
    // Constructeur de la classe Particule. Pas de constructeur par défaut.

    virtual std::ostream& affiche(std::ostream& sortie) const;
    // Méthode d'affiche des attributs d'une particule

    virtual void dessine_sur(SupportADessin& support) override
    { support.dessine(*this); }

    // "Getters" et "Setters" pour les particules
    double get_pos(size_t i) const;

    double get_vit(size_t i) const;

    double get_masse() const;

    void set_pos(size_t i, double x);

    void set_vit(size_t i, double x);

    void evolue(double dt);
    // Méthode permettant de faire bouger une particule sur un temps dt

    bool test_contact(Particule const& p) const;
    /* Méthode qui test si this et autre sont en contact
     * (différence des normes <= EPSILON). */

    void collision_particule(Particule& p, GenerateurAleatoire tirage,
                             bool ex9 = true);
    /* Méthode qui effectue les changements de vitesse et de direction lorsque
     * this et p entrent en collision. Ici on fixe le zenith à PI/2 et l'azimut
     * à PI/3 (phi=PI/3, z=0). */

    std::array<int, 3> pos_floor() const;
};

std::ostream& operator<<(std::ostream& sortie, Particule const& P);
// Opérateur d'affichage de particules


/******************************************************************************
  Sous classes de Particule
 ******************************************************************************/


class Neon : public Particule
{
  public:
    Neon(Vecteur3D p, Vecteur3D v, double m=0) : Particule(p, v, masse_Neon) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour le néon
};

class Argon : public Particule
{
  public:
    Argon(Vecteur3D p, Vecteur3D v, double m=0) : Particule(p, v, masse_Argon) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour l'argon
};

class Helium : public Particule
{
  public:
    Helium (Vecteur3D p, Vecteur3D v, double m=0) : Particule(p, v, masse_Helium) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour l'hélium
};
