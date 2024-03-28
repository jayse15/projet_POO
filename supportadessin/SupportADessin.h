#pragma once
#include <iostream>
#include <array>
#include "../utils.h"
#include "../dessinable/Dessinable.h"
#include "../enceinte/Enceinte.h"

class SupportADessin : public Dessinable {
    private: 
        


    public: 
        virtual void dessine_sur(SupportADessin& support) override
        { support.dessine(*this); }

        virtual ~SupportADessin() = default;
        // on suppose ici que les supports ne seront ni copiés ni déplacés
        virtual void dessine(Neon const&) = 0;
        virtual void dessine(Argon const&) = 0;
        virtual void dessine(Enceinte const&) = 0;
        virtual void dessine(Systeme const&) = 0;
        // ... autres choses que vous voudriez dessiner...


}; 