#ifndef cracked_brick_hpp
#define cracked_brick_hpp

#include "../sand.hpp"

class CCrackedBrick : public CSand
{
    public:
        // constructor 
        CCrackedBrick();

        void receiveHeat(float heatAmount);

        void notFallingUpdate(uint16_t x, uint16_t y);

};


#endif