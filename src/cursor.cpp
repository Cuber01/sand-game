#include <SDL2/SDL.h>
#include <stdint.h>

#include "elements/element.hpp"
#include "cursor.hpp"
#include "main.hpp"

void CCursor::adjustCursor(int x, int y, uint8_t w, uint8_t h)
{
    if(scale > 1)
    {
        cursor.x = (x-w)/scale;
        cursor.y = (y-h)/scale;
    } else 
    {
        cursor.x = (x-(w/2))/scale;
        cursor.y = (y-(h/2))/scale;
    }

    cursor.w = w;
    cursor.h = h;

}


void CCursor::placeParticles(uint16_t x, uint16_t y, uint8_t w, uint8_t h, CElement* particle)
{

    if(scale == 1)
    {
        x = x + w/2;
        y = y + h/2;
    }

    for(uint8_t i = 1; i < w; i++) {
        for(uint8_t j = 1; j < h; j++) {

            if (not Util.isOutOfBounds((x+i)/scale, (y+j)/scale))
            {
                grid[(x+i)/scale][(y+j)/scale] = particle; //new particle;
            }

        }
    }
}

