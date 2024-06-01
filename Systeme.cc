#include "Systeme.h"
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
    for (size_t j(0); j<=2; ++j) {
        if (p.get_pos(j) < PRECISION) {
            cout << "La particule " << i << " rebondit sur la face " << j+1 << endl;
            p.set_pos(j, 2*p.get_pos(j)-PRECISION);
            p.set_vit(j,-p.get_vit(j));
        }
    }
    if (enceinte_.get_l() - p.get_pos(0) < PRECISION) {
        cout << "La particule " << i << " rebondit sur la face 4" << endl;
        p.set_pos(0,2*enceinte_.get_l()-PRECISION);
        p.set_vit(0,-p.get_vit(0));
    }
    if (enceinte_.get_h() - p.get_pos(1) < PRECISION) {
        cout << "La particule " << i << " rebondit sur la face 5" << endl;
        p.set_pos(1,2*enceinte_.get_h()-PRECISION);
        p.set_vit(1,-p.get_vit(1));
    }
    if (enceinte_.get_p() - p.get_pos(2) < PRECISION) {
        cout << "La particule " << i << " rebondit sur la face 6" << endl;
        p.set_pos(2,2*enceinte_.get_p()-PRECISION);
        p.set_vit(2,-p.get_vit(2));
    }
}

void Systeme::collision_particules(Particule& p, size_t i) {
    if (i < particules_.size()) {
        for (;i < particules_.size(); ++i) {
            if (p.test_contact(*particules_[i])) {
                cout << "La particule " << i+1 <<
                " entre en collision avec une autre particule." << endl;
                cout << " avant le choc : " << endl;
                afficher_collision(p, i);
                particules_[i]->collision_particule(p, tirage_);
                cout << " après le choc : " << endl;
                afficher_collision(p, i);
            }
        }
    }
}

void Systeme::afficher_collision(Particule const& p, size_t i) const {
        cout << setw(3) << "" << "part. " << i+1 << " : : ";
        particules_[i]->Particule::affiche(cout) << endl;
        cout << setw(3) << "" << "autre : : ";
        p.Particule::affiche(cout) << endl;
}

void Systeme::evolue(double dt, SupportADessin& s) {
    for (auto& p:particules_) {p->evolue(dt);}
    for (size_t i(0); i < particules_.size() ; ++i){
        collision_paroi(*particules_[i], i+1);
        collision_particules(*particules_[i], i+1);
        particules_[i]->dessine_sur(s);
    }
}

// *****************************************************************************
// Méthodes de la classe Grid
// *****************************************************************************

void Grid::ajouter_map(const Particule& p, size_t index) {
    grille_[p.pos_floor()].insert(index);

}

void Grid::retirer_map(Particule& p, size_t i) {
  for (auto& pair : grille_) {
          auto& mySet = pair.second;
          if (pair.second.find(i) != pair.second.end()) {
              pair.second.erase(i);
              break;
          }
      }
}

void Grid::ajouter_particule(Particule* p) {
    Systeme::ajouter_particule(p);
    ajouter_map(*p, particules_.size()-1);
}

void Grid::supp_all() {
    Systeme::supp_all();
    grille_.clear();
}

void Grid::collision_paroi(Particule& p, size_t i) {
    retirer_map(p,i);
    Systeme::collision_paroi(p,i);
    ajouter_map(p,i);
}

void Grid::collision_particules(Particule& p, size_t i) {
    for (auto& case_ : grille_){
        for (auto& index : case_.second){
            cout << "La particule " << i+1 <<
                    " entre en collision avec une autre particule." << endl;
            cout << " avant le choc : " << endl;
            afficher_collision(p, i);
            particules_[case_.second[j]]->collision_particule(p, tirage_);
            cout << " après le choc : " << endl;
            afficher_collision(p, i);
        }
    }




}

void evolue(double dt, SupportADessin& s) {

}

void Grid::evolue(double dt, SupportADessin& s) {
    for (size_t i(0); i < particules_.size(); ++i) {
        retirer_map(*particules_[i], i);
        particules_[i]->evolue(dt);
        ajouter_map(*particules_[i], i);
    }
    for (size_t i(0); i < particules_.size() ; ++i){
        collision_paroi(*particules_[i], i+1);
        collision_particules(*particules_[i], i);
        particules_[i]->dessine_sur(s);
    }
}


ostream& operator<<(ostream& sortie, Systeme const& S) {
    S.affiche(sortie);
    return sortie;
}
