#pragma once
#include <vector>
#include <iostream>
#include "GenerateurAleatoire.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Enceinte.h"

class Particule;

class Systeme : public Dessinable
{
    private :
        Enceinte* enceinte_;
        std::vector<Particule*> particules_;
        GenerateurAleatoire tirage_;
        enum type_particule {neon = 'Neon', helium = 'Helium', argon = 'Argon'}; 

    public :
        Systeme(double h = 20, double l = 20, double p = 20) :
          enceinte_(new Enceinte(h,l,p)), particules_{}, tirage_() {}

        Systeme(Systeme const&) = delete;

        ~Systeme()
        {
          delete enceinte_;
          enceinte_ = nullptr;
        }

        Systeme operator=(Systeme const&) = delete;

        std::ostream& affiche(std::ostream& sortie) const;

        void ajouter_particule(Particule* const&);

        void supp_all();

        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

        void collision_paroi(Particule&, unsigned int);

        void collision_particules(Particule&, int);
        
        void afficher_collision(Particule const&, unsigned int) const; 

        void initialisation(double, unsigned int, string, GenerateurAleatoire); 

        void evolue(double);

};

std::ostream& operator<<(std::ostream& sortie, Systeme const& S);
