CC = $(CXX)
CXXFLAGS = -std=c++20 -pedantic -Wall

all: Vecteur3D

Vecteur3D: Vecteur3D.o testVecteur3D.o utils.o

Vecteur3D.o: Vecteur3D.cc Vecteur3D.h utils.h

testVecteur3D.o: testVecteur3D.cc Vecteur3D.h utils.h

utils.o: utils.cc utils.h
