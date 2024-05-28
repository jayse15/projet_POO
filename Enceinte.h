#pragma once
#include <iostream>
#include "SupportADessin.h"
#include "Dessinable.h"
#include "Particule.h"
#include <array>
#include <vector>
#include <map>

class Enceinte : public Dessinable
{
    protected:
        double const hauteur_;
        double const largeur_;
        double const profondeur_;

    public:
        Enceinte (double h = 20, double l = 20, double p = 20) :
          hauteur_(h), largeur_(l), profondeur_(p) {}

        std::ostream& affiche(std::ostream& sortie) const;

        double get_h() const;
        double get_l() const;
        double get_p() const;

        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

        virtual bool collision_paroi(Particule& p, size_t i) const; 
        /* Méthode pour la collision d'une particule sur une paroi. Par défaut
         * nous définissons que l'origine (0,0,0) est sur un coin de l'enceinte.
         * la hauteur est selon z, la largeur selon y et la profondeur selon x.
         * la face 1 est dans le plan x=0, la 2 dans le plan y=0 et la 3 dans le
         * plan z=0. La face 4 est opposée a la 1, la 5 à la 2 et la 6 à la 3. */
    };

std::ostream& operator<<(std::ostream& sortie, Enceinte const& E);


class Grid : public Enceinte {
    private: 
        std::map<std::array<int,3>, std::vector<Particule*>> grille_; 
    public: 
        virtual bool collision_paroi(Particule& p, size_t i) const override;
}; 