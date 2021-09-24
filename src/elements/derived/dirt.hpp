#ifndef dirt_hpp
#define dirt_hpp

#include "../sand.hpp"

class CDirt : public CSand
{
    public:
        // constructor 
        CDirt();

        void receiveHeat(float heatAmount);

};


#endif