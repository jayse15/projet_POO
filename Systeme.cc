#include "Systeme.h"
#include "utils.h"
#include "Particule.h"

using namespace std;

// *****************************************************************************
// Méthodes de la classe Systeme
// *****************************************************************************

ostream& Systeme::affiche(ostream& sortie) const {
    if (particules_.size() == 0) {sortie << "Le système est vide.";}
    else {
        sortie << "Le système est constitué des " << particules_.size() <<
                  " particules suivantes: " << endl;
        for (auto& p : particules_) {
            sortie << *p << endl;
        }
        sortie << endl;
    }
    return sortie;
}

void Systeme::ajouter_particule(Particule const& p) {
    particules_.push_back(make_unique<Particule>(p));
}

void Systeme::supp_all() {
    particules_.clear();
}

void Systeme::collision_paroi(Particule& p, uint i) {
    if (p.get_pos(0) <= EPSILON) {
        cout << "La particule " << i+1 << " rebondit sur la face 1" << endl;
        p.set_pos(0, 2*p.get_pos(0)-EPSILON);
        p.set_vit(0,-p.get_vit(0));
    }
    if (p.get_pos(1) <= EPSILON) {
        cout << "La particule " << i+1 << " rebondit sur la face 2" << endl;
        p.set_pos(1, 2*p.get_pos(1)-EPSILON);
        p.set_vit(1,-p.get_vit(1));
    }
    if (p.get_pos(2) <= EPSILON) {
        cout << "La particule " << i+1 << " rebondit sur la face 3" << endl;
        p.set_pos(2, 2*p.get_pos(2)-EPSILON);
        p.set_vit(2,-p.get_vit(2));
    }
    if (p.get_pos(0) >= enceinte_->get_l()-EPSILON) {
        cout << "La particule " << i+1 << " rebondit sur la face 4" << endl;
        p.set_pos(0,enceinte_->get_l()-EPSILON);
        p.set_vit(0,-p.get_vit(0));
    }
    if (p.get_pos(1) >= enceinte_->get_p()-EPSILON) {
        cout << "La particule " << i+1 << " rebondit sur la face 5" << endl;
        p.set_pos(1,enceinte_->get_p()-EPSILON);
        p.set_vit(1,-p.get_vit(1));
    }
    if (p.get_pos(2) >= enceinte_->get_h()-EPSILON) {
        cout << "La particule " << i+1 << " rebondit sur la face 6" << endl;
        p.set_pos(2,enceinte_->get_h()-EPSILON);
        p.set_vit(2,-p.get_vit(2));
    }
}

void Systeme::collision_particules(Particule& p, size_t i) {
    if (i < particules_.size()) {
        for (i; i < particules_.size(); ++i) {
            afficher_collision(p, i);
            p.collision_particule(*particules_[i], tirage_);
            afficher_collision(p, i);
        }
    }
}

void Systeme::afficher_collision(Particule const& p, size_t i, ostream& sortie) const{
     if (p.test_contact(*particules_[i])) {
        sortie << "La particule " << i+1
               << " entre collision avec une autre particule." << endl
               << "avant le choc : " << endl << "part. " << i+1 << " : : "
               << *particules_[i] << endl << "autre : : " << p << endl;
    }
}

void Systeme::evolue(double dt, ostream& sortie) {
    for (size_t i(0); i < particules_.size() ; ++i)
    {
        particules_[i]->evolue(dt);
        collision_paroi(*particules_[i], i);
        collision_particules(*particules_[i], i+1);
        particules_[i]->affiche(cout) << endl;
    }
}

void Systeme::initialisation(double masse, uint temperature, enum type_particule,
                            GenerateurAleatoire tirage) {
    double pos_x(tirage.uniforme(0.0,enceinte_->get_l()));
    double pos_y(tirage.uniforme(0.0,enceinte_->get_p()));
    double pos_z(tirage.uniforme(0.0,enceinte_->get_h()));

    double vit_x(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse)));
    double vit_y(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse)));
    double vit_z(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse)));

    Particule p(masse, {pos_x, pos_y, pos_z}, {vit_x, vit_y, vit_z});

    ajouter_particule(p);
}

ostream& operator<<(ostream& sortie, Systeme const& S) {
    S.affiche(sortie);
    return sortie;
}
