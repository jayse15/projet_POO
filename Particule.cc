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

ostream& Helium::affiche(ostream& sortie) const {
  sortie << "Hélium : "; 
  Particule::affiche(sortie); 
  return sortie;
}

ostream& operator<<(ostream& sortie, Particule const& P) {
  sortie << "particule ";
  return P.affiche(sortie);
}

double Particule::get_pos(unsigned int i) const {
  return position.get_coord(i); 
}

double Particule::get_vit(unsigned int i) const {
  return vitesse.get_coord(i); 
}

void Particule::set_pos(unsigned int i, double x) {
  position.set_coord(i, x);
}

void Particule::set_vit(unsigned int i, double x) {
  vitesse.set_coord(i, x);
}

void Particule::evolue(double dt) {
  Vecteur3D deplacement(vitesse*=dt);
  position+=deplacement; 
}

bool Particule::test_contact(Particule const& autre) const {

}

void Particule::collision_particule(Particule& autre, GenerateurAleatoire tirage) {
  if ((this->position-autre.position).norme() <= EPSILON) {
    Vecteur3D v_g(vitesse*(masse/(masse + autre.masse)) + autre.vitesse*(autre.masse/(masse+autre.masse))); 
    double L((vitesse-v_g).norme());
    double z(tirage.uniforme(-L, L));
    double phi(tirage.uniforme(0, 2*M_PI));
    double r(sqrt(L*L - z*z));
    Vecteur3D v_0(r*cos(phi), r*sin(phi), z); 
    vitesse = v_g + v_0; 
    autre.vitesse = v_g - v_0*masse/autre.masse; 
  }
} 
