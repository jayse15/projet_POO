#include "Systeme.h"

using namespace std; 

ostream& Systeme::affiche(ostream& sortie) const {
    if (particules_.size() == 0) {sortie << "Le système est vide.";}
    else {
        sortie << "Le système est constitué des " << particules_.size() << " particules suivantes: " << endl; 
        for (auto element : particules_) {
            cout << *element << endl; 
        }
    }
    return sortie; 
}

ostream& operator<<(ostream& sortie, Systeme S) {
    S.affiche(sortie); 
    return sortie; 
}

Systeme Systeme::ajouter_particule(Particule* const& P) {
    particules_.push_back(P); 
    return *this; 
}

Systeme Systeme::supp_all() {
    particules_.clear(); 
}
