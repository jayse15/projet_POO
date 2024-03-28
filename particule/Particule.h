#pragma once
#include <iostream>
#include "../vecteur/Vecteur3D.h"
#include "../dessinable/Dessinable.h"

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
