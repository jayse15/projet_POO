#include "Systeme.h"
#include "utils.h"
#include "Particule.h"
#include "Vecteur3D.h"
#include <iomanip>

using namespace std;

// *****************************************************************************
// Méthodes de la classe Systeme
// *****************************************************************************

ostream& Systeme::affiche(ostream& sortie) const {
    if (particules_.size() == 0) {sortie << "Le système est vide.";}
    else {
        sortie << "Le système est constitué des " << particules_.size() << " particules suivantes: " << endl;
        for (auto const& p : particules_) {
            sortie << endl << *p;
        }
        sortie << endl;
    }
    return sortie;
}

void Systeme::ajouter_particule(Particule* p) {
    particules_.push_back(unique_ptr<Particule>(p));
}

void Systeme::supp_all() {
    particules_.clear();
}

void Systeme::collision_paroi(Particule& p, size_t i) {
    for (size_t j(0); i<=2; ++i) {
        if (p.get_pos(j) < PRECISION) {
            cout << "La particule " << i+1 << " rebondit sur la face " << j+1 << endl;
            p.set_pos(j, 2*p.get_pos(j)-PRECISION);
            p.set_vit(j,-p.get_vit(j));
        }
    }
    if (enceinte_->get_l() - p.get_pos(0) < PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 4" << endl;
        p.set_pos(0,enceinte_->get_l()-PRECISION);
        p.set_vit(0,-p.get_vit(0));
    }
    if (enceinte_->get_h() - p.get_pos(1) < PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 5" << endl;
        p.set_pos(1,enceinte_->get_h()-PRECISION);
        p.set_vit(1,-p.get_vit(1));
    }
    if (enceinte_->get_p() - p.get_pos(2) < PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 6" << endl;
        p.set_pos(2,enceinte_->get_p()-PRECISION);
        p.set_vit(2,-p.get_vit(2));
    }
}

void Systeme::collision_particules(Particule& p, size_t j) {
    if (j < particules_.size()) {
        for (size_t i(j); i < particules_.size(); ++i) {
            if (p.test_contact(*particules_[i])) {
                cout << "La particule " << i+1 << " entre collision avec une autre particule." << endl;
                cout << setw(1) << "avant le choc : " << endl;
                afficher_collision(p, i);
                particules_[i]->collision_particule(p, tirage_);
                cout << setw(1) << "après le choc : " << endl; 
                afficher_collision(p, i);
            }
        }
    }
}

void Systeme::afficher_collision(Particule const& p, size_t i) const{
        cout << setw(3) << "part. " << i+1 << " : : ";
        particules_[i]->Particule::affiche(cout) << endl;
        cout << setw(3) << "autre : : ";
        p.Particule::affiche(cout) << endl;
}

void Systeme::evolue(double dt) {
    for (size_t i(0); i < particules_.size() ; ++i)
    {
        particules_[i]->evolue(dt);
        collision_paroi(*particules_[i], i);
        collision_particules(*particules_[i], i+1);
        cout << *particules_[i] << endl; 
    }
}

void Systeme::initialisation(double masse, uint temperature, enum type_particule, GenerateurAleatoire tirage) {
    double pos_x(tirage.uniforme(0.0,enceinte_->get_l()));
    double pos_y(tirage.uniforme(0.0,enceinte_->get_p()));
    double pos_z(tirage.uniforme(0.0,enceinte_->get_h()));

    double vit_x(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse)));
    double vit_y(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse)));
    double vit_z(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse)));

    Particule* p(new Particule(masse, {pos_x, pos_y, pos_z}, {vit_x ,vit_y ,vit_z }));
    ajouter_particule(p);
}

ostream& operator<<(ostream& sortie, Systeme const& S) {
    S.affiche(sortie);
    return sortie;
}
