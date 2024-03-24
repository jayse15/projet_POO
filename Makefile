CC = $(CXX)
CXXFLAGS = -std=c++20 -pedantic -Wall

all: vecteur/Vecteur3D particule/Particule enceinte/Enceinte

vecteur/Vecteur3D: vecteur/Vecteur3D.o tests/testVecteur3D.o utils.o

vecteur/Vecteur3D.o: vecteur/Vecteur3D.cc vecteur/Vecteur3D.h utils.h

tests/testVecteur3D.o: tests/testVecteur3D.cc vecteur/Vecteur3D.h utils.h

particule/Particule: particule/Particule.o tests/testParticule.o vecteur/Vecteur3D.o utils.o

particule/Particule.o: particule/Particule.cc particule/Particule.h

tests/testParticule.o: tests/testParticule.cc particule/Particule.h vecteur/Vecteur3D.h

enceinte/Enceinte : enceinte/Enceinte.o

enceinte/Enceinte.o : enceinte/Enceinte.h

utils.o: utils.cc utils.h
