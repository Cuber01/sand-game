#ifndef element_hpp
#define element_hpp

#include <stdint.h>
#include <float.h>
#include "../utils/data.hpp"


class CElement
{ 
    private:
    // protected:

        // my color
        color_t color;  
    public:

        // contructor 
        CElement();

        // who am I?
        uint8_t type; 

        // when a movable solid moves on me, it loses its velocity_x by my friction (velocity_x - friction)
        uint8_t friction;
        
        // velocity in y axis
        float velocity_y = 1;

        // velocity in x axis
        float velocity_x = 0;

        // if set to false, element will check only cell on down (y+1, x)
        bool isFalling = true;

        // chance for setting isFalling to true while being nudged
        uint8_t inertialResistance = 0.1;

        // set my color
        void setColor( color_t color);

        // return my color
        color_t getColor();

        // main update loop
        virtual void update(uint16_t x,uint16_t y);
        
};


#endif