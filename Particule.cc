#include "Particule.h"
#include <cmath>

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

double Particule::get_pos(uint i) const {
  return position.get_coord(i);
}

double Particule::get_vit(uint i) const {
  return vitesse.get_coord(i);
}

void Particule::set_pos(uint i, double x) {
  position.set_coord(i, x);
}

void Particule::set_vit(uint i, double x) {
  vitesse.set_coord(i, x);
}
void Particule::evolue(double dt) {
  position+=vitesse*dt;
}

bool Particule::test_contact(Particule const& p) const {
    if ((position-p.position).norme() <= EPSILON) {return true;}
    return false;
}

void Particule::collision_particule(Particule& p, GenerateurAleatoire tirage) {
  if (test_contact(p)) {
    Vecteur3D v_g(vitesse*(masse/(masse + p.masse)) +
                  p.vitesse*(p.masse/(masse+p.masse)));

    double L((vitesse-v_g).norme());
    double z(0);
    double phi(M_PI/3);
    double r(sqrt(L*L - z*z));

    Vecteur3D v_0(r*cos(phi), r*sin(phi), z);
    vitesse = v_g + v_0;
    p.vitesse = v_g - v_0*masse/p.masse;
  }
}

void Particule::collision_particule_save(Particule& p, GenerateurAleatoire tirage) {
  if (test_contact(p)) {
    Vecteur3D v_g(vitesse*(masse/(masse + p.masse)) +
                  p.vitesse*(p.masse/(masse+p.masse)));

    double L((vitesse-v_g).norme());
    double z(tirage.uniforme(-L, L));
    double phi(tirage.uniforme(0, 2*M_PI));
    double r(sqrt(L*L - z*z));

    Vecteur3D v_0(r*cos(phi), r*sin(phi), z);
    vitesse = v_g + v_0;
    p.vitesse = v_g - v_0*masse/p.masse;
  }
}

array<int,3> Particule::pos_floor() const {
  double x_1(floor(position.get_coord(0))); 
  double y_1(floor(position.get_coord(1)));
  double z_1(floor(position.get_coord(2))); 
  int x = int(x_1); 
  int y = int(y_1); 
  int z = int(z_1); 
  array<int,3> partie_entiere(x,y,z);
  return partie_entiere; 
}