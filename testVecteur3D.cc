#include "Vecteur3D.h"
using namespace std;


int main()
{
  // un vecteur en 3D :
  Vecteur3D vect1(1.0, 2.0, -0.1);

  // un autre vecteur en 3D
  Vecteur3D vect2(2.6, 3.5, 4.1);

  Vecteur3D vect3(vect1); // copie de V1

  Vecteur3D vect4; // le vecteur nul

  cout << "Vecteur 1 : " << vect1 << endl;

  //cout << "Vecteur 2 : " << vect2 << endl;

  //cout << "Vecteur 3 : " << vect3 << endl;

  //cout << "Vecteur 4 : " << vect4 << endl;


  cout << "Le vecteur 1 est ";
  if (vect1 == vect2) {
    cout << "égal au";
  } else {
    cout << "différent du";
  }
  cout << " vecteur 2," << endl << "et est ";
  if (vect1 != vect3) {
    cout << "différent du";
  } else {
    cout << "égal au";
  }
  cout << " vecteur 3." << endl;

  vect1 *= 2.0;
  cout << vect1 << endl;

  cout << "Produit scalaire entre vect2 et vect3: " << vect2*vect3 << endl;

  Vecteur3D v5(vect2^vect3);
  cout << "Produit vectoriel entre vect2 et vect3: ";
  cout << v5 << endl;

  Vecteur3D a(2.0, 3.0, 1.0);
  Vecteur3D direction(~a);
  cout << direction << endl;

  return 0;
}
