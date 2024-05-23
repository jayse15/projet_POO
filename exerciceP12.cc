#include <iostream>
#include <string>
#include "Systeme.h"
#include "Particule.h"

using namespace std;

int main() {
  Systeme S;

  double T(20);
  S.initialisation<>(T, 2, 4.21);
  S.initialisation<Argon>(T,2);
  S.initialisation<Helium>(T,1);
  S.initialisation<Neon>(T,2);

  string line("==========----------");
  cout << S << endl;

  cout << "Lancement de la simulation" << endl;

  for (size_t i(0); i<10; i++) {
      cout << line << endl;
      S.evolue(1);
  }
  cout << line << endl;

  return 0;

}
