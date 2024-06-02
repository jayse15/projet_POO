#pragma once
#include <iostream>
#include "SupportADessin.h"
#include "Dessinable.h"

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
    };

std::ostream& operator<<(std::ostream& sortie, Enceinte const& E);
