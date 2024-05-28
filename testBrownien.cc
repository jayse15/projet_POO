#include <iostream>
#include <string>
#include "Systeme.h"
#include "Particule.h"
#include "Brownien.h"


using namespace std;

int main() {

    Systeme S;
    S.ajouter_particule(new Helium({1, 1, 1}, {0, 0, 0}));
    S.ajouter_particule(new Neon({1, 18.5, 1}, {0, 0.2, 0}));
    S.ajouter_particule(new Argon({1, 1, 3.1}, {0, 0, -0.5}));

    Argon* P = new Argon({1, 4, 2}, {0, 1.8, 0.5});
    Brownien B(cout, "brownien.txt", *P);

    S.ajouter_particule(P);

    string line("==========----------");
    S.dessine_sur(B);

    cout << "Lancement de la simulation" << endl;

    for (size_t i(0); i<10; i++) {
        cout << line << endl;
        S.evolue(1, B);
    }
    cout << line << endl;

    return 0;
}
