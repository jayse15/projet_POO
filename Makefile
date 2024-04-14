CC = $(CXX)
CXXFLAGS = -std=c++20 -pedantic -Wall

all: Vecteur3D Particule Enceinte

Enceinte: Enceinte.o exerciceP7.o utils.o Particule.o Vecteur3D.o 
Vecteur3D: Vecteur3D.o tests/testVecteur3D.o utils.o

Particule: Particule.o tests/testParticule.o Vecteur3D.o utils.o

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h utils.h

testVecteur3D.o: tests/testVecteur3D.cc Vecteur3D.h utils.h

Particule.o: Particule.cc Particule.h Vecteur3D.h utils.h Dessinable.h
	SupportADessin.h Enceinte.h Systeme.h

testParticule.o: tests/testParticule.cc Particule.h Vecteur3D.h

Enceinte.o: Enceinte.cc Enceinte.h Dessinable.h SupportADessin.h
	Particule.h Vecteur3D.h utils.h Systeme.h

TextViewer.o: TextViewer.cc TextViewer.h Enceinte.h Dessinable.h
	SupportADessin.h Particule.h Vecteur3D.h utils.h Systeme.h

exerciceP7.o: exerciceP7.cc TextViewer.h Enceinte.h Dessinable.h
	SupportADessin.h Particule.h Vecteur3D.h utils.h Systeme.h

utils.o: utils.cc utils.h
