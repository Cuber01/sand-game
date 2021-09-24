#ifndef smoke_hpp
#define smoke_hpp


#include <stdint.h>

class CSmoke : public CElement
{
    

    public:
        CSmoke();

        virtual void update(uint16_t x, uint16_t y);

        void move(uint16_t x, uint16_t y);
        void handleLifetime(uint16_t x, uint16_t y);

        void receiveHeat(float heatAmount); 

        int16_t lifetime;

};


#endif