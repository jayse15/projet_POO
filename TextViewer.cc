#include <iostream>
#include "TextViewer.h"
#include "Systeme.h"
#include "Enceinte.h"
#include "Particule.h"

using namespace std;

void TextViewer::dessine(Neon const& n) {
    cout << n << endl;
}

void TextViewer::dessine(Argon const& a) {
    cout << a << endl;
}

void TextViewer::dessine(Enceinte const& e) {
    cout << e << endl;
}

void TextViewer::dessine(Systeme const& s) {
    cout << s << endl; 
}
