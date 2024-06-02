CC = $(CXX)
CXXFLAGS = -std=c++11 -pedantic -Wall

all: Vecteur3D Particule Systeme exerciceP7 exerciceP9 exerciceP12 Brownien Grid


exerciceP7: exerciceP7.o Enceinte.o Particule.o Vecteur3D.o utils.o Systeme.o \
	TextViewer.o

exerciceP9: exerciceP9.o Enceinte.o Particule.o Vecteur3D.o utils.o Systeme.o \
	TextViewer.o

exerciceP12: exerciceP12.o Enceinte.o Particule.o Vecteur3D.o utils.o Systeme.o \
	TextViewer.o

Grid: testGrid.o Systeme.o Enceinte.o utils.o Particule.o Vecteur3D.o TextViewer.o

Systeme: testSysteme.o Systeme.o Particule.o Vecteur3D.o utils.o Enceinte.o TextViewer.o

Vecteur3D: Vecteur3D.o testVecteur3D.o utils.o

Brownien: Brownien.o testBrownien.o Systeme.o Enceinte.o utils.o Particule.o \
	Vecteur3D.o TextViewer.o

Particule: Particule.o testParticule.o Vecteur3D.o utils.o Enceinte.o \
	Systeme.o


Brownien.o: Brownien.cc Brownien.h TextViewer.h SupportADessin.h \
  Particule.h utils.h Vecteur3D.h Dessinable.h GenerateurAleatoire.h

Enceinte.o: Enceinte.cc Enceinte.h SupportADessin.h Dessinable.h

Particule.o: Particule.cc Particule.h utils.h Vecteur3D.h Dessinable.h \
  SupportADessin.h GenerateurAleatoire.h

Systeme.o: Systeme.cc Systeme.h GenerateurAleatoire.h Dessinable.h \
  SupportADessin.h Enceinte.h utils.h Particule.h Vecteur3D.h

TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h Particule.h \
  utils.h Vecteur3D.h Dessinable.h GenerateurAleatoire.h Enceinte.h \
  Systeme.h

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h utils.h

exerciceP12.o: exerciceP12.cc Systeme.h GenerateurAleatoire.h \
  Dessinable.h SupportADessin.h Enceinte.h Particule.h utils.h \
  Vecteur3D.h TextViewer.o

exerciceP7.o: exerciceP7.cc TextViewer.h SupportADessin.h Particule.h \
  utils.h Vecteur3D.h Dessinable.h GenerateurAleatoire.h Systeme.h \
  Enceinte.h

exerciceP9.o: exerciceP9.cc Systeme.h GenerateurAleatoire.h Dessinable.h \
  SupportADessin.h Enceinte.h Particule.h utils.h Vecteur3D.h TextViewer.h

testBrownien.o: testBrownien.cc Systeme.h GenerateurAleatoire.h \
  Dessinable.h SupportADessin.h Enceinte.h utils.h Particule.h \
  Vecteur3D.h TextViewer.h Brownien.h

testParticule.o: testParticule.cc Particule.h utils.h Vecteur3D.h \
  Dessinable.h SupportADessin.h GenerateurAleatoire.h

testSysteme.o: testSysteme.cc Systeme.h GenerateurAleatoire.h \
  Dessinable.h SupportADessin.h Enceinte.h Particule.h utils.h \
  Vecteur3D.h

testGrid.o: testGrid.cc Systeme.h GenerateurAleatoire.h Dessinable.h \
  SupportADessin.h Enceinte.h utils.h Particule.h Vecteur3D.h \
  TextViewer.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

utils.o: utils.cc utils.h
