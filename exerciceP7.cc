#include "TextViewer.h"
#include "Particule.h"
#include "Systeme.h"
#include <iostream>

using namespace std;

int main() {

    Systeme S;
    S.ajouter_particule(new Neon({1, 18.5, 1}, {0, 0.2, 0}));
    S.ajouter_particule(new Argon({1, 1, 3.1}, {0, 0, -0.5}));

    TextViewer ecran(cout);

    S.dessine_sur(ecran);

    return 0;
}
