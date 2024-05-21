#include "Particule.h"
#include <iostream>

using namespace std;

int main() {

  Particule p1(4.002602, {1,1,1}, {0,0,0});
  Neon p2({1,18.5,1}, {0,0.2,0});
  Argon p3({1,1,3.1}, {0,0,-0.5});
  Particule p4(p2);

  cout << p1 << endl;
  cout << p2 << endl;
  cout << p3 << endl;
  cout << p4 << endl;

  return 0;
}
