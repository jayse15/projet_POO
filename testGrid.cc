#include "Systeme.h"
#include "Particule.h"
#include "TextViewer.h"
#include <string>
#include <iostream>

using namespace std;

int main() {

    Grid G;
    G.ajouter_particule(new Neon({1, 18.5, 1}, {0, 2, 0}));
    G.ajouter_particule(new Argon({1, 1, 3.1}, {0, 0, -1}));
    G.ajouter_particule(new Helium({1, 1, 1}, {0, 0, 0}));

    TextViewer T;

    string line("==========----------");
    G.dessine_sur(T);

    cout << "Lancement de la simulation" << endl;

    for (size_t i(0); i<10; i++) {
        cout << line << endl;
        G.evolue(1, T);
    }
    cout << line << endl;

    return 0;
}
