#include "Vecteur3D.h"
using namespace std;

int main()
{
  Vecteur3D vect1;
  Vecteur3D vect2;
  Vecteur3D vect3;

  // v1 = (1.0, 2.0, -0.1)
  vect1.set_coord(0, 1.0);
  vect1.set_coord(1, 2.0);
  vect1.set_coord(2, -0.1);

  // v2 = (2.6, 3.5,  4.1)
  vect2.set_coord(0, 2.6);
  vect2.set_coord(1, 3.5);
  vect2.set_coord(2, 4.1);

  vect3 = vect1;

  cout << "Vecteur 1 : ";
  vect1.affiche();
  cout << endl;

  cout << "Vecteur 2 : ";
  vect2.affiche();
  cout << endl;

  cout << "Le vecteur 1 est ";
  if (vect1.compare(vect2)) {cout << "égal au";}
  else {cout << "différent du";}

  cout << " vecteur 2," << endl << "et est ";

  if (vect1.compare(vect3)) {cout << "égal au";}
  else {cout << "différent du";}

  cout << " vecteur 3." << endl;

  return 0;
}
