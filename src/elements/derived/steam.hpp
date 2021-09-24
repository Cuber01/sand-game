#ifndef steam_hpp
#define steam_hpp

#include "../smoke.hpp"

class CSteam : public CSmoke
{
    public:
        // constructor 
        CSteam();

        void receiveHeat(float heatAmount);

};


#endif