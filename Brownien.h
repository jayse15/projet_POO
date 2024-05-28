#pragma once
#include "TextViewer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class Enceinte;
class Particule;
class Neon;
class Argon;
class Helium;
class Systeme;

class Brownien : public TextViewer
{
    private :
        std::ofstream sortie;
        Particule& suivie;
    public :
        Brownien(std::ostream& flot, std::string const& file, Particule& p)
          : TextViewer(flot), suivie(p) {
            sortie.open(file);
            if (not sortie.is_open()){
              throw(std::invalid_argument("Fichier texte pas valide."));
            }
          }

        virtual ~Brownien() {sortie.close();}
        Brownien(Brownien const&) = delete;
        Brownien& operator=(Brownien const&) = delete;
        Brownien(Brownien&&) = delete;
        Brownien& operator=(Brownien&&) = delete;
        // on ne copie et on ne déplace pas les TextViewer Brownien

        void dessine(Particule const&) override;
        void dessine(Neon const&) override;
        void dessine(Argon const&) override;
        void dessine(Helium const&) override;
        // methode pour afficher un objet dessinable sur un TextViewer Brownien
};
