#include <iostream>
#include <fstream>
#include "Systeme.h"
#include "Particule.h"
#include "TextViewer.h"


using namespace std;

int main() {

    Helium p1(4.002602, {1, 1, 1}, {0, 0, 0});
    Neon p2(20.1797, {1, 18.5, 1}, {0, 0.2, 0});
    Argon p3(39.948, {1, 1, 3.1}, {0, 0, -0.5});

    Systeme S;
    S.ajouter_particule(new Helium(p1));
    S.ajouter_particule(new Neon(p2));
    S.ajouter_particule(new Argon(p3));

    string line("==========----------");
    cout << S << endl;

    cout << "Lancement de la simulation" << endl;

    for (size_t i(0); i<10; i++) {
        cout << line << endl;
        S.evolue(1);
    }
    cout << line << endl;

    return 0;
}
