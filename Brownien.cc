#include "Brownien.h"
#include "Particule.h"

using namespace std;

void Brownien::dessine(Particule const& p) {
    visualisation << p << endl;
    if (&p==&suivie) {
      sortie << p << endl;
    }
}

void Brownien::dessine(Neon const& n) {
    visualisation << n << endl;
    if (&n==&suivie) {
      sortie << n << endl;
    }
}

void Brownien::dessine(Argon const& a) {
    visualisation << a << endl;
    if (&a==&suivie) {
      sortie << a << endl;
    }
}


void Brownien::dessine(Helium const& h) {
    visualisation << h << endl;
    if (&h==&suivie) {
      sortie << h << endl;
    }
}
