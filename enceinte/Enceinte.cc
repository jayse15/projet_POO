#include <iostream>
#include "Enceinte.h"

using namespace std; 


ostream& Enceinte::affiche(ostream& sortie) const {
    sortie << "Les dimensions de l'enceinte sont: largueur = " << largeur_ << " hauteur = " << hauteur_ << " profondeur = " << profondeur_ << "." << endl; 
    return sortie; 
}


ostream& operator<<(ostream& sortie, Enceinte const& E) {
    E.affiche(sortie); 
    return sortie; 
}
