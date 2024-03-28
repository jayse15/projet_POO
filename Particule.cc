#include <iostream>
#include "Particule.h"

using namespace std;

ostream& Particule::affiche(ostream& sortie) const {
  sortie << "pos : " << position << "; " << "v: "<< vitesse << "; " << "m : "
  << masse;
  return sortie;
}

ostream& Neon::affiche(ostream& sortie) const {
  sortie << "Néon : ";
  Particule::affiche(sortie);
  return sortie;
}

ostream& Argon::affiche(ostream& sortie) const {
  sortie << "Argon : ";
  Particule::affiche(sortie);
  return sortie;
}

ostream& operator<<(ostream& sortie, Particule const& P) {
  sortie << "particule ";
  return P.affiche(sortie);
}
