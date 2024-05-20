#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include "GenerateurAleatoire.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Enceinte.h"

class Particule;

class Systeme : public Dessinable
{
    private :
        std::unique_ptr<Enceinte> enceinte_;
        std::vector<std::unique_ptr<Particule>> particules_;
        // On utilise des pointeurs pour le polymorphisme. Comme on fait de
        // l'allocation dynamique, on utilise des unique_ptr puisque chaque
        // objet dans le système est unique et ne sera pas affecté ou déplacé.
        GenerateurAleatoire tirage_;
        enum type_particule {};

    public :
        Systeme(double h = 20, double l = 20, double p = 20) :
          enceinte_(std::make_unique<Enceinte>(h,l,p)), particules_{}, tirage_() {}
        // Constructeur et constructeur par défaut de la classe Systeme.
        // Le systeme par défaut crée possède une enceinte de dimensions 20x20x20
        // et sans aucune particule.

        Systeme(Systeme const& s) = delete;
        // Pas de copie de systèmes.

        Systeme operator=(Systeme const& s) = delete;
        // Pas d'affectation de systèmes.

        std::ostream& affiche(std::ostream& sortie) const;
        // Méthode d'affichage d'un système. Affiche le nombre de particules et
        // les affiche une par une.

        void ajouter_particule(Particule* p);
        // Ajoute une particule au système.

        void supp_all();
        // Désalloue et éfface toutes les particules du système

        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }
        // Méthode pour dessiner le système sur un support à dessin quelconque

        void collision_paroi(Particule& p, size_t i);
        // Méthode pour la collision d'une particule sur une paroi. Par défaut
        // nous définissons que l'origine (0,0,0) est sur un coin de l'enceinte.
        // la hauteur est selon z, la largeur selon y et la profondeur selon x.
        // la face 1 est dans le plan x=0, la 2 dans le plan y=0 et la 3 dans le
        // plan z=0. La face 4 est opposée a la 1, la 5 à la 2 et la 6 à la 3.

        void collision_particules(Particule& p, size_t i);
        // Méthode pour la collision entre particules. Lorsque deux particules
        // se trovent à une distance EPSILON (voir utils.h) elles sont renvoyés
        // dans des directions aléatoires et avec des vitesses calculées avec
        // la conservation de la quantité de mouvement

        void afficher_collision(Particule const& p, size_t i) const;
        // Affiche le résultat de la collision de la particule p avec la i-ème
        // particule du système.

        void evolue(double dt);
        // Fait evoluer le système sur un temps dt en faisant evoluer chaque
        // particule sur un temps dt

        template<typename T>
        void initialisation(double masse, uint temperature,
                            GenerateurAleatoire tirage);
        // Méthode d'initialisation aléatoire d'une particule a partir de la
        // température du système. Le template nous permet de choisir le type de
        // particule.

};

std::ostream& operator<<(std::ostream& sortie, Systeme const& S);
