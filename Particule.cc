
#include <iostream>
#include "Particule.h"

using namespace std;

ostream& Particule::affiche(ostream& sortie) const {
    sortie << "pos : " << position << "; " << "v: "<< vitesse << "; " << "m : " << masse << endl;
    return sortie;
}

ostream& operator<<(ostream& sortie, Particule const& P) {
    return P.affiche(sortie);
}
