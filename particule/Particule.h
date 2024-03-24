#pragma once
#include <iostream>
#include "../vecteur/Vecteur3D.h"

class Particule
{
    private :
        double masse;
        Vecteur3D position;
        Vecteur3D vitesse;
        // On utilise des Vecteurs3D comme position et vitesse pour pouvoir utiliser
        // les opérations définies dans la classe Vecteur3D

   public :
        Particule(double m, Vecteur3D p, Vecteur3D v)
          : masse(m), position(p), vitesse(v) {}
        // Constructeur de la classe Particule. Pas de constructeur par défaut.

        std::ostream& affiche(std::ostream& sortie) const;
        // Méthode d'affiche des attributs d'une particule
};

std::ostream& operator<<(std::ostream& sortie, Particule const& P);
// Opérateur d'affichage de particules
