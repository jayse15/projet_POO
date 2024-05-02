#include "TextViewer.h"
#include "Particule.h"
#include "Enceinte.h"
#include "Systeme.h"
#include <iostream>

using namespace std;

void TextViewer::dessine(Particule const& p) {
    visualisation << p;
}

void TextViewer::dessine(Neon const& n) {
    visualisation << n;
}

void TextViewer::dessine(Argon const& a) {
    visualisation << a;
}

void TextViewer::dessine(Helium const& h) {
    visualisation << h;
}

void TextViewer::dessine(Enceinte const& e) {
    visualisation << e;
}

void TextViewer::dessine(Systeme const& s) {
    visualisation << s;
}
