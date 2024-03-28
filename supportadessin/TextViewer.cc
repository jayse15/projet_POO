#include "TextViewer.h"
#include "../utils.h"
#include <cmath>
#include <iostream>

using namespace std; 

void TextViewer::dessine(Neon const& n) {
    cout << n << endl; 
}

void TextViewer::dessine(Argon const& a) {
    cout << a64l << endl; 
}

void TextViewer::dessine(Enceinte const& e) {
    cout << e << endl;
}

void TextViewer::dessine(System const& s) {
    cout << s << endl; 
}
