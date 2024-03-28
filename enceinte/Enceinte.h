#pragma once
#include <iostream>

class Enceinte : public Dessinable
{
    private:
        double hauteur_;
        double largeur_;
        double profondeur_;

    public:
        Enceinte (double h = 20, double l = 20, double p = 20){
            hauteur_ = h;
            largeur_ = l;
            profondeur_ = p;
        }

        std::ostream& affiche(std::ostream& sortie) const;

        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }
    };

std::ostream& operator<<(std::ostream& sortie, Enceinte const& E);
