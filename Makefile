CC = $(CXX)
CXXFLAGS = -std=c++20 -pedantic -Wall

all: Vecteur3D Particule Enceinte

Vecteur3D: Vecteur3D.o testVecteur3D.o utils.o

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h utils.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h utils.h

Particule: Particule.o testParticule.o Vecteur3D.o

Particule.o: Particule.cc Particule.h 

testParticule.o: testParticule.cc Particule.h Vecteur3D.h

Enceinte : Enceinte.o testEnceinte.o

Enceinte.o : Enceinte.cc Enceinte.h 

testEnceinte.o : testEnceinte.cc Enceinte.h 

utils.o: utils.cc utils.h

