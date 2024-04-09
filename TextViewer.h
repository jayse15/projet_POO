#pragma once
#include <iostream>
#include "Enceinte.h"
#include "Particule.h"
#include "Systeme.h"
#include "SupportADessin.h"

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
        void dessine(Particule const&) override;
        void dessine(Enceinte const&) override;
        void dessine(Systeme const&) override;
};
