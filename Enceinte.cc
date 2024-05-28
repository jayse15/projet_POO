#include "Enceinte.h"
#include "util.h"

using namespace std;

double Enceinte::get_h() const{
    return hauteur_;
}

double Enceinte::get_l() const{
    return largeur_;
}

double Enceinte::get_p() const{
    return profondeur_;
}

ostream& Enceinte::affiche(ostream& sortie) const {
    sortie << "Les dimensions de l'enceinte sont: largueur = " << largeur_ <<
    " hauteur = " << hauteur_ << " profondeur = " << profondeur_ << "." << endl;
    return sortie;
}

ostream& operator<<(ostream& sortie, Enceinte const& E) {
    E.affiche(sortie);
    return sortie;
}

bool Enceinte::collision_paroi(Particule& p, size_t i) const {
    bool result(false);
    for (size_t j(0); j<=2; ++j) {
        if (p.get_pos(j) < PRECISION) {
            cout << "La particule " << i << " rebondit sur la face " << j+1 << endl;
            p.set_pos(j, 2*p.get_pos(j)-PRECISION);
            p.set_vit(j,-p.get_vit(j));
            result = true; 
        }
    }
    if (largeur_ - p.get_pos(0) < PRECISION) {
        cout << "La particule " << i << " rebondit sur la face 4" << endl;
        p.set_pos(0,2*largeur_-PRECISION);
        p.set_vit(0,-p.get_vit(0));
        result = true; 
    }
    if (hauteur_ - p.get_pos(1) < PRECISION) {
        cout << "La particule " << i << " rebondit sur la face 5" << endl;
        p.set_pos(1,2*hauteur_-PRECISION);
        p.set_vit(1,-p.get_vit(1));
        result = true; 
    }
    if  (profondeur_ - p.get_pos(2) < PRECISION) {
        cout << "La particule " << i << " rebondit sur la face 6" << endl;
        p.set_pos(2,2*profondeur_-PRECISION);
        p.set_vit(2,-p.get_vit(2));
        result = true; 
    }
    return result;
}

bool Grid::collision_paroi(Particule& p, size_t i) const {
    if (Enceinte::collision_paroi(p,i)) {
        array<int,3> entier(p.pos_floor()); 
        for (auto case_ : grille_) {
            if (case_.first == p.pos_floor()) {
                case_.second.push_back(new Particule(p));
            }
            else {
                vector<Particule*> nouvelle_case; 
                nouvelle_case.push_back(new Particule(p));
                grille_[entier] = nouvelle_case; 
                grille_.emplace(entier, nouvelle_case); 
            }
        }
    }
}