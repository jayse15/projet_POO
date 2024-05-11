#include <iostream>
#include "Systeme.h"
#include "Particule.h"

using namespace std; 

int main() {

    int i(0);

    Helium p1(4.002602, {1, 1, 1}, {0, 0, 0});
    Neon p2(20.1797, {1, 18.5, 1}, {0, 0.2, 0});
    Argon p3(39.948, {1, 1, 3.1}, {0, 0, -0.5});

    Systeme S; 
    S.ajouter_particule(new Helium(p1)); 
    S.ajouter_particule(new Neon(p2)); 
    S.ajouter_particule(new Argon(p3)); 

    S.affiche(cout); 

    cout << "Lancement de la simulation" << endl; 

    while (i <= 10) {
        cout << "==========----------" << endl; 
        S.evolue(1); 
        ++i;
    }
    cout << "==========----------" << endl;

    return 0; 
}