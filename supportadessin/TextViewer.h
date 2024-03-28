#pragma once
#include <iostream>
#include <array>
#include "../utils.h"
#include "../dessinable/Dessinable.h"
#include "../enceinte/Enceinte.h"
#include "../particule/Particule.h"

class TextViewer : public SupportADessin 
{
    private :

    public : 
        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

        void dessine(Neon const&);
        void dessine(Argon const&);
        void dessine(Enceinte const&); 
        void dessine(System const&); 
};
