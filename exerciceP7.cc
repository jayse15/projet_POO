#include "TextViewer.h"
#include "Particule.h"
#include "Systeme.h"
#include <iostream>

using namespace std;

int main() {
    Neon p1(20.1797, {1, 18.5, 1}, {0, 0.2, 0});
    Argon p2(39.948, {1, 1, 3.1}, {0, 0, -0.5});

    Systeme S;
    S.ajouter_particule(new Neon(p1));
    S.ajouter_particule(new Argon(p2));

    TextViewer ecran(cout);

    S.dessine_sur(ecran);

    return 0;
}
