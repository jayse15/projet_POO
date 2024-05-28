#pragma once
#include "Particule.h" 
#include "Enceinte.h"
#include "Systeme.h"
#include <map>
#include <array>
#include <vector>

class Grid {
    private: 
        std::map<std::array<int,3>, std::vector<Particule*>> grille_; 
    public: 

        
};
