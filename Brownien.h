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
            sortie.open(file, std::ios::in | std::ios::out);
            if (not sortie.is_open()){
              throw(std::invalid_argument("Fichier texte pas valide."));
            }
          }
          /* constructeur de Brownien qui envoie un message d'erreur si le
           * fichier text fourni est invalide ou non-existant */

          virtual ~Brownien() {sortie.close();}

          void dessine(Particule const&) override;
          void dessine(Neon const&) override;
          void dessine(Argon const&) override;
          void dessine(Helium const&) override;
          // methodes pour afficher un objet dessinable sur un TextViewer Brownien
};
