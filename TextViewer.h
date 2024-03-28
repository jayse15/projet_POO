#pragma once
#include <iostream>
#include "Enceinte.h"
#include "Particule.h"

class TextViewer : public SupportADessin
{
    private :

    public :
        void dessine(Neon const&) override;
        void dessine(Argon const&) override;
        void dessine(Enceinte const&) override;
        void dessine(System const&) override;
};
