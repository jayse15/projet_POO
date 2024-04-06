#include <vector>
#include <iostream>
#include "Particule.h"
#include "Enceinte.h"

class Systeme : public Dessinable
{ 
    private : 
        Enceinte* enceinte_; 
        std::vector<Particule*> particules_; 
        
    public : 
        Systeme(double h = 20, double l = 20, double p = 20) {
            *enceinte_ = (h,l,p); 
            particules_ = {}; 
        }

        Systeme(Systeme const&) = delete; 

        Systeme operator=(Systeme const&) = delete; 

        std::ostream& affiche(std::ostream& sortie) const; 

        void ajouter_particule(Particule* const&); 

        void supp_all(); 

        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }
};

std::ostream& operator<<(std::ostream& sortie, Systeme const& S); 