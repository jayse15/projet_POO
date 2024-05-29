#pragma once
#include <iostream>
#include "utils.h"
#include "Vecteur3D.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "GenerateurAleatoire.h"
#include <cmath>

class Particule : public Dessinable
{
  protected :
    const double masse;
    Vecteur3D position;
    Vecteur3D vitesse;

    /* On utilise des Vecteurs3D comme position et vitesse pour pouvoir utiliser
     * les opérations définies dans la classe Vecteur3D */

  public :
    Particule(double m, Vecteur3D p, Vecteur3D v)
      : masse(m), position(p), vitesse(v) {}
    // Constructeur de la classe Particule. Pas de constructeur par défaut.

    Particule(double temp, double m, Enceinte& E, GenerateurAleatoire& tirage)
      : masse(m) {
        position = {tirage.uniforme(0.0, E.get_l()),
                    tirage.uniforme(0.0, E.get_p()),
                    tirage.uniforme(0.0, E.get_h())};

        double maxwell(sqrt(1000 * R / m * temp));

        vitesse = {tirage.gaussienne(0.0, maxwell),
                   tirage.gaussienne(0.0, maxwell),
                   tirage.gaussienne(0.0, maxwell)};
      }
    /* Constructeur de la classe particule sur la base de la température et les
     * dimensions d'une enceinte. */

    virtual std::ostream& affiche(std::ostream& sortie) const;
    // Méthode d'affiche des attributs d'une particule

    virtual void dessine_sur(SupportADessin& support) override
    { support.dessine(*this); }

    // "Getters" et "Setters" pour les particules
    double get_pos(uint i) const;

    double get_vit(uint i) const;

    void set_pos(uint i, double x);

    void set_vit(uint i, double x);

    void evolue(double dt);
    // Méthode permettant de faire bouger une particule sur un temps dt

    bool test_contact(Particule const& p) const;
    /* Méthode qui test si this et autre sont en contact
     * (différence des normes <= EPSILON). */

    void collision_particule(Particule& p, GenerateurAleatoire tirage,
                             bool ex9 = true);
    /* Méthode qui effectue les changements de vitesse et de direction lorsque
     * this et p entrent en collision. Avec ex9 = true on fixe le zenith à PI/2
     * et l'azimut à PI/3 (phi=PI/3, z=0), sinon ils sont tirés aléatoirement. */

};

std::ostream& operator<<(std::ostream& sortie, Particule const& P);
// Opérateur d'affichage de particules


/******************************************************************************
  Sous classes de Particule
 ******************************************************************************/


class Neon : public Particule
{
  private:
    static constexpr double masse = masse_Neon;

  public:
    Neon(Vecteur3D p, Vecteur3D v) : Particule(masse_Neon, p, v) {}

    Neon(double temp, Enceinte& E, GenerateurAleatoire& tirage) :
      Particule(temp, masse, E, tirage) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour le néon

    static double get_masse() {return masse;}
};

class Argon : public Particule
{
  private:
    static constexpr double masse = masse_Argon;

  public:
    Argon(Vecteur3D p, Vecteur3D v) : Particule(masse_Argon, p, v) {}

    Argon(double temp, Enceinte& E, GenerateurAleatoire& tirage) :
      Particule(temp, masse, E, tirage) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour l'argon

    static double get_masse() {return masse;}
};

class Helium : public Particule
{
  private:
    static constexpr double masse = masse_Helium;

  public:
    Helium(Vecteur3D p, Vecteur3D v) : Particule(masse_Helium, p, v) {}

    Helium(double temp, Enceinte& E, GenerateurAleatoire& tirage) :
      Particule(temp, masse, E, tirage) {}

    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour l'hélium

    static double get_masse() {return masse;}
};
