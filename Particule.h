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
    const double masse;
    Vecteur3D position;
    Vecteur3D vitesse;
    // On utilise des Vecteurs3D comme position et vitesse pour pouvoir utiliser
    // les opérations définies dans la classe Vecteur3D

  public :
    Particule(double m, Vecteur3D p, Vecteur3D v)
      : masse(m), position(p), vitesse(v) {}
    // Constructeur de la classe Particule. Pas de constructeur par défaut.

    virtual std::ostream& affiche(std::ostream& sortie) const;
    // Méthode d'affiche des attributs d'une particule

    virtual void dessine_sur(SupportADessin& support) override
    { support.dessine(*this); }

    double get_pos(uint i) const;

    double get_vit(uint i) const;

    void set_pos(uint i, double x);

    void set_vit(uint i, double x);

    void evolue(double dt);
    // Méthode permettant de faire bouger une particule d'un temps dt

    bool test_contact(Particule const& autre) const;

    void collision_particule(Particule& p, GenerateurAleatoire tirage);

    void collision_particule_save(Particule& p, GenerateurAleatoire tirage);

    void collision_paroi(Enceinte const& E, size_t i);
    // Méthode pour la collision contre une paroi. Par défaut nous définissons
    // que l'origine (0,0,0) est sur un coin de l'enceinte. la hauteur est selon
    // z, la largeur selon y et la profondeur selon x.la face 1 est dans le plan
    // x=0, la 2 dans le plan y=0 et la 3 dans le plan z=0. La face 4 est
    // opposée a la 1, la 5 à la 2 et la 6 à la 3.
};

std::ostream& operator<<(std::ostream& sortie, Particule const& P);
// Opérateur d'affichage de particules

class Neon : public Particule
{
  private:
    static constexpr double masse = masse_Neon;

  public:
    Neon(Vecteur3D p, Vecteur3D v) : Particule(masse_Neon, p, v) {}
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
    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour l'hélium

    static double get_masse() {return masse;}
};
