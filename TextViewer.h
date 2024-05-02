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
    private :
        std::ostream& visualisation;
    public :
        TextViewer(std::ostream& flot)
            : visualisation(flot) {}
        virtual ~TextViewer() = default;
        // on ne copie pas les TextViewer
        TextViewer(TextViewer const&) = delete;
        TextViewer& operator=(TextViewer const&) = delete;
        // et on peut pas les déplacer
        TextViewer(TextViewer&&) = delete;
        TextViewer& operator=(TextViewer&&) = delete;

        void dessine(Neon const&) override;
        void dessine(Argon const&) override;
        void dessine(Helium const&) override;
        void dessine(Particule const&) override;
        void dessine(Enceinte const&) override;
        void dessine(Systeme const&) override;
};
