#pragma once
#include "SupportADessin.h"

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
        // mais on peut les déplacer
        TextViewer(TextViewer&&) = default;
        TextViewer& operator=(TextViewer&&) = default;

        void dessine(Neon const&) override;
        void dessine(Argon const&) override;
        void dessine(Helium const&) override;
        void dessine(Particule const&) override;
        void dessine(Enceinte const&) override;
        void dessine(Systeme const&) override;
};
