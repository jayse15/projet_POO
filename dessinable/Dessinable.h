#pragma once
#include <iostream>
#include <array>
#include "../utils.h"
#include "../supportadessin/SupportADessin.h"

class Dessinable {
    private: 


    public: 
        virtual void dessine_sur(SupportADessin& support) = 0; 

}; 