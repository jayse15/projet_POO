#include "../Systeme.h"

using namespace std; 

int main() {
    Systeme S1;  
    cout << S1 << endl; 

    S1.ajouter_particule(new Neon(20.1797, {1, 18.5, 1}, {0, 0.2, 0})); 
    S1.ajouter_particule(new Argon(39.948, {1, 1, 3.1}, {0, 0, -0.5})); 

    cout << S1 << endl; 

    return 0; 
}