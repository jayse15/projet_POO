#include <iostream>
#include "Particule.h"

using namespace std;

ostream& Particule::affiche(ostream& sortie) const {
  sortie << "pos : " << position << "; " << "v: "<< vitesse << "; " << "m : "
  << masse << endl;
  return sortie;
}

ostream& Neon::affiche(ostream& sortie) const {
  sortie << "particule Néon : ";
  Particule::affiche(sortie);
  return sortie;
}

ostream& Argon::affiche(ostream& sortie) const {
  sortie << "particule Argon : ";
  Particule::affiche(sortie);
  return sortie;
}

ostream& operator<<(ostream& sortie, Particule const& P) {
  return P.affiche(sortie);
}
