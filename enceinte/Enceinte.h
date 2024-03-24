#pragma once
#include <iostream>

class Enceinte
{
    private:
        double hauteur;
        double largeur;
        double profondeur;

    public:
        Enceinte (double h = 20, double l = 20, double p = 20){
            hauteur = h;
            largeur = l;
            profondeur = p;
        }
    };
