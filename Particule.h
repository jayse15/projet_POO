#pragma once
#include <iostream>
#include "Vecteur3D.h"
#include "utils.h"
#include "Dessinable.h"
#include "SupportADessin.h"

class Particule : public Dessinable
{
  protected :
    double masse;
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

    double get_pos(unsigned int) const;

    double get_vit(unsigned int) const;

    void set_pos(unsigned int, double);

    void set_vit(unsigned int, double);

    void evolue(double);
    // Méthode permettant de faire bouger une particule d'un temps dt

    virtual void collision_particule(Particule const &); 
};

std::ostream& operator<<(std::ostream& sortie, Particule const& P);
// Opérateur d'affichage de particules

class Neon : public Particule
{
  public:
    Neon(double m, Vecteur3D p, Vecteur3D v) : Particule(m, p, v) {}
    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour le néon
};

class Argon : public Particule
{
  public:
    Argon(double m, Vecteur3D p, Vecteur3D v) : Particule(m, p, v) {}
    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour l'argon
};

class Helium : public Particule
{
  public:
    Helium(double m, Vecteur3D p, Vecteur3D v) : Particule(m, p, v) {}
    std::ostream& affiche(std::ostream& sortie) const override;
    // Méthode d'affiche pour l'hélium
};
