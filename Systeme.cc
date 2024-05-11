#include "Systeme.h"
#include "utils.h"
#include "Particule.h"

using namespace std;

ostream& Systeme::affiche(ostream& sortie) const {
    if (particules_.size() == 0) {sortie << "Le système est vide.";}
    else {
        sortie << "Le système est constitué des " << particules_.size() << " particules suivantes: " << endl;
        for (auto element : particules_) {
            cout << *element << endl;
        }
        cout << endl; 
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

void Systeme::collision_paroi(Particule& p, unsigned int i) {
    if (p.get_pos(0) <= PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 1" << endl;  
        p.set_pos(0, -p.get_pos(0)); 
        p.set_vit(0,-p.get_vit(0));
    }
    if (p.get_pos(1) <= PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 2" << endl;  
        p.set_pos(1, -p.get_pos(1)); 
        p.set_vit(1,-p.get_vit(1));
    }
    if (p.get_pos(2) <= PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 3" << endl;  
        p.set_pos(2, -p.get_pos(2)); 
        p.set_vit(2,-p.get_vit(2));
    }
    if (p.get_pos(0) - enceinte_->get_l() >= PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 4" << endl;  
        p.set_pos(0,2*enceinte_->get_l()-p.get_pos(0));
        p.set_vit(0,-p.get_vit(0));
    }
    if (p.get_pos(1) - enceinte_->get_p() >= PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 5" << endl;  
        p.set_pos(1,2*enceinte_->get_p()-p.get_pos(1));
        p.set_vit(1,-p.get_vit(1));
    }
    if (p.get_pos(2) - enceinte_->get_h() >= PRECISION) {
        cout << "La particule " << i+1 << " rebondit sur la face 6" << endl;  
        p.set_pos(2,2*enceinte_->get_h()-p.get_pos(2));
        p.set_vit(2,-p.get_vit(2));
    }
}
// Par défaut nous définissons que la hauteur de l'enceinte est le long de l'axe z, donc la troisième coordonnées d'un Vecteur3D
// la longueur est le long de l'axe x, donc la première coordonnée, et la profondeur le long de l'axe y, donc la deuxième coordonnée.
// La paroi 1 est la ...

void Systeme::collision_particules(Particule& p, int j) {
    if (j >= particules_.size()) {
        for (int i(j); i < particules_.size(); ++i) {
            afficher_collision(p, i);
            p.collision_particule(*particules_[i], tirage_);
            afficher_collision(p, i);
        }
    }
}

void Systeme::afficher_collision(Particule const& p, unsigned int i) const{
     if (p.test_contact(*particules_[i])) {
        cout << "La particule " << i+1 << " entre collision avec une autre particule." << endl;
        cout << "avant le choc : " << endl; 
        cout << "part. " << i+1 << " : : "; 
        particules_[i]->Particule::affiche(cout) << endl; 
        cout << "autre : : "; 
        p.Particule::affiche(cout) << endl; 
    }
}

void Systeme::evolue(double dt) {
    for (int j(0); j < particules_.size() ; ++j)
    {
        particules_[j]->evolue(dt);
        collision_paroi(*particules_[j], j);
        collision_particules(*particules_[j], j+1);
        particules_[j]->affiche(cout) << endl; 
    }
}

void Systeme::initialisation(double masse, unsigned int temperature, enum type_particule, GenerateurAleatoire tirage) {
    double pos_x(tirage.uniforme(0.0,enceinte_->get_l())); 
    double pos_y(tirage.uniforme(0.0,enceinte_->get_p())); 
    double pos_z(tirage.uniforme(0.0,enceinte_->get_h())); 

    double vit_x(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse))); 
    double vit_y(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse))); 
    double vit_z(tirage.gaussienne(0.0,sqrt(k_B * temperature / masse))); 
    
    Particule p(masse, {pos_x, pos_y, pos_z}, {vit_x, vit_y, vit_z});

    ajouter_particule(new Particule(p)); 
}