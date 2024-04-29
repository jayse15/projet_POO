#include "Enceinte.h"
#include <iostream>

using namespace std;

double Enceinte::get_h() const{
    return hauteur_;
}

double Enceinte::get_l() const{
    return largeur_;
}

double Enceinte::get_p() const{
    return profondeur_;
}

ostream& Enceinte::affiche(ostream& sortie) const {
    sortie << "Les dimensions de l'enceinte sont: largueur = " << largeur_ <<
    " hauteur = " << hauteur_ << " profondeur = " << profondeur_ << "." << endl;
    return sortie;
}

ostream& operator<<(ostream& sortie, Enceinte const& E) {
    E.affiche(sortie);
    return sortie;
}
