#include <iostream>
#include <string>
#include "Systeme.h"
#include "Particule.h"
#include "TextViewer.h"

using namespace std;

int main() {

    Systeme S;
    S.ajouter_particule(new Helium({1, 1, 1}, {0, 0, 0}));
    S.ajouter_particule(new Neon({1, 18.5, 1}, {0, 0.2, 0}));
    S.ajouter_particule(new Argon({1, 1, 3.1}, {0, 0, -0.5}));

    TextViewer T(cout);

    string line("==========----------");
    S.dessine_sur(T);

    cout << "Lancement de la simulation" << endl;

    for (size_t i(0); i<10; i++) {
        cout << line << endl;
        S.evolue(1, T);
    }
    cout << line << endl;

    return 0;
}
