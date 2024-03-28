#include <vector>
#include <iostream>
#include "../particule/Particule.h"
#include "../enceinte/Enceinte.h"

class Systeme 
{ 
    private : 
        Enceinte* enceinte_; 
        std::vector<Particule*> particules_; 
        
    public : 
        Systeme(double h = 20, double l = 20, double p = 20) {
            *enceinte_ = (h,l,p); 
            particules_; 
        }

        std::ostream& affiche(std::ostream& sortie) const; 

        Systeme ajouter_particule(Particule* const&); 

        Systeme supp_all(); 
};

std::ostream& operator<<(std::ostream& sortie, Systeme const& S); 