#pragma once
#include <vector>
#include <iostream>
#include <memory>
#include <type_traits>
#include <cmath>
#include <map>
#include <set>
#include "GenerateurAleatoire.h"
#include "Dessinable.h"
#include "SupportADessin.h"
#include "Enceinte.h"
#include "utils.h"
#include "Particule.h"
#include "Vecteur3D.h"
#include "TextViewer.h"


class Particule;

class Systeme : public Dessinable
{
    protected :
        const Enceinte enceinte_;
        std::vector<std::unique_ptr<Particule>> particules_;
        /* On utilise des pointeurs pour le polymorphisme. Comme on fait de
         * l'allocation dynamique, on utilise des unique_ptr puisque chaque
         * particule dans le système est unique et ne sera pas affectée ou
         * déplacée. */
        GenerateurAleatoire tirage_;

        // Méthodes protected reservées à l'utilisation interne :

        virtual void collision_paroi(Particule& p, size_t i);
        /* Méthode pour la collision d'une particule sur une paroi. Par défaut
         * nous définissons que l'origine (0,0,0) est sur un coin de l'enceinte.
         * la hauteur est selon z, la largeur selon y et la profondeur selon x.
         * la face 1 est dans le plan x=0, la 2 dans le plan y=0 et la 3 dans le
         * plan z=0. La face 4 est opposée a la 1, la 5 à la 2 et la 6 à la 3. */

        void afficher_collision(Particule const& p, size_t i) const;
        /* Affiche le résultat de la collision de la particule p avec la i-ème
         * particule de particules_. */

        void collision(Particule& p, size_t i);
        /* Méthode qui effectue une collsion entre p et la i-ème particule de
         * particules_. */

        void collision_particules(Particule& p, size_t i);
        /* Méthode pour la collision entre particules. Lorsque deux particules
         * se trovent à une distance EPSILON (voir utils.h) elles sont renvoyés
         * dans des directions aléatoires et avec des vitesses calculées avec
         * la conservation de la quantité de mouvement */

        void afficher_rebond(size_t i, size_t face);
        /* Méthode qui affiche le rebond de la i-ème particule contre la face
         * indiquée. */


    public :
        Systeme(double h = 20, double l = 20, double p = 20) :
          enceinte_(h,l,p), particules_{}, tirage_() {}
        /* Constructeur et constructeur par défaut de la classe Systeme.
         * Le systeme par défaut crée possède une enceinte de dimensions 20x20x20
         * et sans aucune particule. */

        Systeme(Systeme const& s) = delete;
        // Pas de copie de systèmes.

        Systeme operator=(Systeme const& s) = delete;
        // Pas d'affectation de systèmes.

        std::ostream& affiche(std::ostream& sortie) const;
        /* Méthode d'affichage d'un système. Affiche le nombre de particules et
         * les affiche une par une. */

        virtual void ajouter_particule(Particule* p);
        // Ajoute une particule au système.

        virtual void supp_all();
        // Désalloue et efface toutes les particules du système.

        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }
        // Méthode pour dessiner le système sur un support à dessin quelconque

        virtual void evolue(double dt, SupportADessin& s);
        /* Fait evoluer le système sur un temps dt en faisant evoluer chaque
         * particule sur un temps dt (en [s]) */

        template <typename T=Particule>
        typename std::enable_if<std::is_base_of<Particule, T>::value, void>::type
        initialisation(double temperature, uint nb_part, double masse=1){
          /* Méthode d'initialisation aléatoire de nb_part particules a partir
          * de la température du système en suivant la distribution des
          * vitesses de Maxwell. Le template nous permet de choisir le type de
          * particule voulu mais cela oblige que cette méthode soit définie ici. */

          if (temperature<0) {
            throw std::invalid_argument("Temperature must be in kelvin !");
          }

            for (size_t j(0); j<nb_part; j++){

              T* p = new T({tirage_.uniforme(0.0,enceinte_.get_l()),
                            tirage_.uniforme(0.0,enceinte_.get_p()),
                            tirage_.uniforme(0.0,enceinte_.get_h())}, {}, masse);

              for (size_t i(0); i<3; i++){
                p->set_vit(i, tirage_.gaussienne(0.0, sqrt(1000 *
                                                           R/p->get_masse() *
                                                           temperature)));
              }

              ajouter_particule(p);
            }
        }
};

std::ostream& operator<<(std::ostream& sortie, Systeme const& S);
// Opérateur d'affichage de Systeme.


class Grid : public Systeme
{
  private :
      std::map<std::array<int,3>, std::set<size_t>> grille_;

      // Méthodes privées reservées à l'utilisation interne :

      void ajouter_map(const Particule&, size_t i);
      // Méthode permettant d'ajouter une particule dans la grille_.

      void retirer_map(Particule&, size_t i);
      /* Méthode permettant de vérifier si une particule est dans grille_ et si
       * c'est le cas de la retirer */

      virtual void collision_paroi(Particule& p, size_t i) override;
      // idem que Systeme::collision_paroi mais en modifiant grille_

      void collision_particules();
      /* idem que Systeme::collision_particules mais en parcourant simplement
       * chaque case de grille_ */

  public :
      Grid(double h = 20, double l = 20, double p = 20) :
          Systeme(h,l,p), grille_{} {}

      void collision_particules(Particule& p, size_t i) = delete;
      // Afin d'obliger l'utilisation de Grid::collision_particules.

      virtual void ajouter_particule(Particule* p) override;
      // Ajoute une particule au système et à la map.

      virtual void supp_all() override;
      // Désalloue et efface toutes les particules du système et de la map.

      virtual void evolue(double dt, SupportADessin& s) override;
      /* Idem que Systeme::evolue mais en utilisant les méthodes de Grid */
};
