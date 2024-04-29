#include "TextViewer.h"
#include <iostream>

using namespace std;

void TextViewer::dessine(Particule const& p) {
    visualisation << p << endl;
}

void TextViewer::dessine(Neon const& n) {
    visualisation << n << endl;
}

void TextViewer::dessine(Argon const& a) {
    visualisation << a << endl;
}

void TextViewer::dessine(Helium const& h) {
    visualisation << h << endl;
}

void TextViewer::dessine(Enceinte const& e) {
    visualisation << e << endl;
}

void TextViewer::dessine(Systeme const& s) {
    visualisation << s << endl;
}
