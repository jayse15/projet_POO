#pragma once
#include <iostream>
#include <array>
#include "../utils.h"
#include "../dessinable/Dessinable.h"
#include "../enceinte/Enceinte.h"
#include "../particule/Particule.h"



class SupportADessin
{
    private: 
        std::iostream& affich_; 

    public: 
        virtual ~SupportADessin() = default;
        // on suppose ici que les supports ne seront ni copiés ni déplacés
        virtual void dessine(Neon const&) = 0;
        virtual void dessine(Argon const&) = 0;
        virtual void dessine(Enceinte const&) = 0;
        virtual void dessine(Systeme const&) = 0;
        // ... autres choses que vous voudriez dessiner...
}; 