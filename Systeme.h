#pragma once
#include <vector>
#include <iostream>
#include "GenerateurAleatoire.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Enceinte.h"

class Particule;

class Systeme : public Dessinable
{
    private :
        unique_ptr<Enceinte> enceinte_;
        std::vector<unique_ptr<Particule>> particules_;
        // On utilise des pointeurs pour le polymorphisme. Comme on fait de
        // l'allocation dynamique, on utilise des unique_ptr puisque chaque
        // objet dans le système est unique et ne sera pas affecté ou
        GenerateurAleatoire tirage_;
        enum type_particule {};

    public :
        Systeme(double h = 20, double l = 20, double p = 20) :
          enceinte_(make_unique<Enceinte>(h,l,p)), particules_{}, tirage_() {}
        // Constructeur et constructeur par défaut de la classe Systeme.
        // Le systeme par défaut crée est une enceinte

        Systeme(Systeme const& s) = delete;
        // Pas de copie de systèmes

        Systeme operator=(Systeme const& s) = delete;
        // Pas d'affectation de systèmes

        std::ostream& affiche(std::ostream& sortie) const;
        // Méthode d'affichage d'un système. Affiche le nombre de particules et
        // les affiche une par une.

        void ajouter_particule(Particule const& p);
        // Ajoute une particule au système

        void supp_all();
        // Désalloue et éfface toutes les particules du système

        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }
        // Méthode pour dessiner le système sur un support à dessin quelconque

        void collision_paroi(Particule&, uint);
        // Méthode pour la collision d'une particule sur une paroi. Par défaut
        // nous définissons que la hauteur de l'enceinte est le long de l'axe z,
        // donc la troisième coordonnées d'un Vecteur3D. La longueur est le long
        // de l'axe x, donc la première coordonnée, et la profondeur le long de
        // l'axe y, donc la deuxième coordonnée.
        // La paroi 1 est la ...

        void collision_particules(Particule& p, size_t i);
        // Méthode pour la collision entre particules. Lorsque deux particules
        // se trovent à une distance EPSILON (voir utils.h) elles sont renvoyés
        // dans des directions aléatoires et avec des vitesses calculées avec
        // la conservation de la quantité de mouvement

        void afficher_collision(Particule const& p, size_t i,
                                std::ostream& sortie) const;

        void initialisation(double masse, uint temperature, enum type_particule,
                            GenerateurAleatoire tirage);

        void evolue(double dt, ostream& sortie);

};

std::ostream& operator<<(std::ostream& sortie, Systeme const& S);
