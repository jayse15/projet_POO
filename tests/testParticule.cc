#include <iostream>
#include "../vecteur/Vecteur3D.h"
#include "../particule/Particule.h"
using namespace std;

int main() {
  Vecteur3D pos1(1,1,1);
  Vecteur3D pos2(1,18.5,1);
  Vecteur3D pos3(1,1,3.1);
  Vecteur3D vit1(0,0,0);
  Vecteur3D vit2(0,0.2,0);
  Vecteur3D vit3(0,0,-0.5);

  Particule p1(4.002602, pos1, vit1);
  Neon p2(20.1797, pos2, vit2);
  Argon p3(39.948, pos3, vit3);
  Particule p4(p2);

  cout << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;
  cout << p4 << endl;

  return 0;
}
