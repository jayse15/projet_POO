#pragma once
#include <iostream>
#include "Enceinte.h"
#include "Particule.h"
#include "Systeme.h"



class SupportADessin
{
    private:

    public:
      virtual ~SupportADessin() = default;
      // on ne copie pas les Supports
      SupportADessin(SupportADessin const&) = delete;
      SupportADessin& operator=(SupportADessin const&) = delete;
      // mais on peut les déplacer
      SupportADessin(SupportADessin&&) = default;
      SupportADessin& operator=(SupportADessin&&) = default;
 
      SupportADessin() = default;

      virtual void dessine(Neon const&) = 0;
      virtual void dessine(Argon const&) = 0;
      virtual void dessine(Helium const&) = 0;
      virtual void dessine(Particule const&) = 0;
      virtual void dessine(Enceinte const&) = 0;
      virtual void dessine(Systeme const&) = 0;
      // ... autres choses que vous voudriez dessiner...
};
