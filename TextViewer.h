#pragma once
#include <iostream>
#include "Enceinte.h"
#include "Particule.h"
#include "Systeme.h"

class TextViewer : public SupportADessin
{
    private :
        std::ostream& visualisation; 
    public :
        void dessine(Neon const&) override;
        void dessine(Argon const&) override;
        void dessine(Enceinte const&) override;
        void dessine(Systeme const&) override;
};
