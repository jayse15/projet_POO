CC = $(CXX)
CXXFLAGS = -std=c++20 -pedantic -Wall

all: Vecteur3D Particule Systeme exerciceP7 exerciceP9


exerciceP7: exerciceP7.o Enceinte.o Particule.o Vecteur3D.o utils.o Systeme.o \
	TextViewer.o

exerciceP9: exerciceP9.o Enceinte.o Particule.o Vecteur3D.o utils.o Systeme.o \
	TextViewer.o

Systeme: testSystem1.o Systeme.o Particule.o Vecteur3D.o utils.o Enceinte.o

Vecteur3D: Vecteur3D.o testVecteur3D.o utils.o

Particule: Particule.o testParticule.o Vecteur3D.o utils.o Enceinte.o \
	Systeme.o


Enceinte.o: Enceinte.cc Enceinte.h SupportADessin.h Dessinable.h

Particule.o: Particule.cc Particule.h Vecteur3D.h Dessinable.h \
  SupportADessin.h GenerateurAleatoire.h utils.h

Systeme.o: Systeme.cc Systeme.h GenerateurAleatoire.h Dessinable.h \
  SupportADessin.h Enceinte.h utils.h Particule.h Vecteur3D.h

TextViewer.o: TextViewer.cc TextViewer.h SupportADessin.h Particule.h \
  Vecteur3D.h Dessinable.h GenerateurAleatoire.h Enceinte.h Systeme.h

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h utils.h

exerciceP7.o: exerciceP7.cc TextViewer.h SupportADessin.h Particule.h \
  Vecteur3D.h Dessinable.h GenerateurAleatoire.h Systeme.h Enceinte.h

exerciceP9.o: exerciceP9.cc TextViewer.h SupportADessin.h Particule.h \
  Vecteur3D.h Dessinable.h GenerateurAleatoire.h Systeme.h Enceinte.h

testParticule.o: testParticule.cc Particule.h Vecteur3D.h Dessinable.h \
  SupportADessin.h GenerateurAleatoire.h

testSystem1.o: testSystem1.cc Systeme.h GenerateurAleatoire.h \
  Dessinable.h SupportADessin.h Enceinte.h Particule.h Vecteur3D.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h

utils.o: utils.cc utils.h
