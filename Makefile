CC = $(CXX)
CXXFLAGS = -std=c++20 -pedantic -Wall

all: exec/Vecteur3D exec/Particule exec/Enceinte

exec/Vecteur3D: exec/Vecteur3D.o exec/testVecteur3D.o exec/utils.o

exec/Vecteur3D.o: Vecteur3D.cc Vecteur3D.h utils.h

exec/testVecteur3D.o: tests/testVecteur3D.cc Vecteur3D.h utils.h

exec/Particule: exec/Particule.o tests/testParticule.o exec/Vecteur3D.o utils.o

exec/Particule.o: Particule.cc Particule.h Vecteur3D.h utils.h Dessinable.h
  								SupportADessin.h Enceinte.h Systeme.h

exec/testParticule.o: tests/testParticule.cc Particule.h Vecteur3D.h

exec/Enceinte.o : Enceinte.cc Enceinte.h Dessinable.h SupportADessin.h
									Particule.h Vecteur3D.h utils.h Systeme.h

TextViewer.o: TextViewer.cc TextViewer.h Enceinte.h Dessinable.h
  						SupportADessin.h Particule.h Vecteur3D.h utils.h Systeme.h


exerciceP7.o: exerciceP7.cc TextViewer.h Enceinte.h Dessinable.h
  						SupportADessin.h Particule.h Vecteur3D.h utils.h Systeme.h

exec/utils.o: utils.cc utils.h
