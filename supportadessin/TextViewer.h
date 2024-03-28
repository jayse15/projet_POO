#pragma once
#include <iostream>
#include <array>
#include "../utils.h"
#include "../dessinable/Dessinable.h"
#include "../enceinte/Enceinte.h"
#include "../particule/Particule.h"
#include "../system/Systeme.h"

class TextViewer : public SupportADessin 
{
    private :

    public : 
        void dessine(Neon const&);
        void dessine(Argon const&);
        void dessine(Enceinte const&); 
        void dessine(Systeme const&); 
};
