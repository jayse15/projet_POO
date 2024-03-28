#pragma once
#include <iostream>
#include "SupportADessin.h"

class Dessinable {
    private:

    public:
        virtual void dessine_sur(SupportADessin& support) = 0;

};
