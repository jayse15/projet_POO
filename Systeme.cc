#include "Systeme.h"
#include "utils.h"
#include <iostream>

using namespace std;

ostream& Systeme::affiche(ostream& sortie) const {
    if (particules_.size() == 0) {sortie << "Le système est vide.";}
    else {
        sortie << "Le système est constitué des " << particules_.size() << " particules suivantes: " << endl;
        for (auto element : particules_) {
            cout << *element << endl;
        }
    }
    return sortie;
}

ostream& operator<<(ostream& sortie, Systeme const& S) {
    S.affiche(sortie);
    return sortie;
}

void Systeme::ajouter_particule(Particule* const& P) {
    particules_.push_back(P);
}

void Systeme::supp_all() {
    particules_.clear();
}

void Systeme::collision_paroi(Particule p) {
    if (p.get_pos(2) - enceinte_->get_h() >= PRECISION) {
        p.set_pos(2,2*enceinte_->get_h()-p.get_pos(2));
        p.set_vit(2,-p.get_vit(2));
        }
    if (p.get_pos(0) - enceinte_->get_l() >= PRECISION) {
        p.set_pos(0,2*enceinte_->get_l()-p.get_pos(0));
        p.set_vit(0,-p.get_vit(0));
        }
    if (p.get_pos(1) - enceinte_->get_p() >= PRECISION) {
        p.set_pos(1,2*enceinte_->get_p()-p.get_pos(1));
        p.set_vit(1,-p.get_vit(1));
    }
}
// Par défaut nous définissons que la hauteur de l'enceinte est le long de l'axe z, donc la troisième coordonnées d'un Vecteur3D
// la longueur est le long de l'axe x, donc la première coordonnée, et la profondeur le long de l'axe y, donc la deuxième coordonnée.

void Systeme::collision_particules(Particule p, int j) {
    if (j >= particules_.size()) {
        for (int i(j); i < particules_.size(); ++i) {
            p.collision_particule(*particules_[i], tirage_);
        }
    }
}

void Systeme::evolue(double dt) {
    for (int j(0); j < particules_.size() - 1; ++j)
    {
        particules_[j]->evolue(dt);
        collision_paroi(*particules_[j]);
        collision_particules(*particules_[j], j+1);
    }
}
