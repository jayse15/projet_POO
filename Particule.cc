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

bool Particule::test_contact(Particule const& autre) const {
    if ((position-autre.position).norme() <= EPSILON) {return true;}
    return false;
}

void Particule::collision_particule(Particule& autre, GenerateurAleatoire tirage) {
  if (test_contact(autre)) {
    Vecteur3D v_g(vitesse*(masse/(masse + autre.masse)) +
                  autre.vitesse*(autre.masse/(masse+autre.masse)));

    double L((vitesse-v_g).norme());
    double z(0);
    double phi(M_PI/3);
    double r(sqrt(L*L - z*z));

    Vecteur3D v_0(r*cos(phi), r*sin(phi), z);
    vitesse = v_g + v_0;
    autre.vitesse = v_g - v_0*masse/autre.masse;
  }
}

void Particule::collision_particule_save(Particule& autre, GenerateurAleatoire tirage) {
  if (test_contact(autre)) {
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

void Particule::collision_paroi(Enceinte const& E, size_t i) {
    for (size_t j(0); j<=2; ++j) {
      Vecteur3D V_J{kroneckerDelta(0,j), kroneckerDelta(1,j),
                    kroneckerDelta(2,j)};
      double posj(position*V_J);
      double vitj(vitesse*V_J);
        if (posj < PRECISION) {
            cout << "La particule " << i << " rebondit sur la face " << j+1 << endl;
            position-= V_J*(2*posj*-PRECISION);
            vitesse-= V_J*(2*vitj);
        }
        if (E.get_l() - posj < PRECISION) {
        cout << "La particule " << i << " rebondit sur la face " << j+4 << endl;
        p.set_pos(0,enceinte_->get_l()-PRECISION);
        p.set_vit(0,-p.get_vit(0));
        }
    }
}
