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

  cout << endl;

  for(uint i(0); i<3; i++) {vect3.set_coord(i, 0);}

  // (1.0, 2.0, -0.1) + (2.6, 3.5, 4.1) = (3.6, 5.5, 4.0)
  vect1.addition(vect2).affiche();

  // (1.0, 2.0, -0.1) + (0, 0, 0)
  vect1.addition(vect3).affiche();

  // (1.0, 2.0, -0.1) - (1.0, 2.0, -0.1) = (0, 0, 0)
  vect1.soustraction(vect1).affiche();

  // opposé(1.0, 2.0, -0.1) = (-1.0, -2.0, 0.1)
  vect1.oppose().affiche();

  // (1.0, 2.0, -0.1) * (2.6, 3.5, 4.1) = 9.19
  cout << vect1.prod_scal(vect2) << endl;

  // (1.0, 2.0, -0.1) ^ (2.6, 3.5, 4.1) = (8.55, -4.36, -1.7)
  vect1.prod_vect(vect2).affiche();

  // ||(1.0, 2.0, -0.1)||^2 = 5.01
  cout << vect1.norme2() << " racine : " << vect1.norme() << endl;

  // ||(2.6, 3.5, 4.1)||^2 = 35.82
  cout << vect2.norme2() << " racine : " << vect2.norme() << endl;


  return 0;
}
