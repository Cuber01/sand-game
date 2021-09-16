#ifndef element_hpp
#define element_hpp

#include <stdint.h>
#include <float.h>
#include "../utils/data.hpp"


class CElement
{ 
    private:
    // protected:
        color_t color;  
    public:

        CElement();
        uint8_t type; 
        float velocity_y = 1;
        bool isFalling = true;


        void setColor( color_t color);
        color_t getColor();
        virtual void update(uint16_t x,uint16_t y);
        
};


#endif