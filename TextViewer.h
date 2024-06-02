#pragma once
#include "SupportADessin.h"
#include <iostream>

class Enceinte;
class Particule;
class Neon;
class Argon;
class Helium;
class Systeme;

class TextViewer : public SupportADessin
{
    protected :
        std::ostream& visualisation;
    public :
        TextViewer(std::ostream& flot = cout)
            : visualisation(flot) {}

        virtual ~TextViewer() = default;
        TextViewer(TextViewer&&) = delete;
        TextViewer& operator=(TextViewer&&) = delete;
        // on ne déplace pas les TextViewer

        virtual void dessine(Neon const&) override;
        virtual void dessine(Argon const&) override;
        virtual void dessine(Helium const&) override;
        virtual void dessine(Particule const&) override;
        void dessine(Enceinte const&) override;
        void dessine(Systeme const&) override;
        // methodes pour afficher un objet dessinable sur un TextViewer
};
