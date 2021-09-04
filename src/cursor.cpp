#include <SDL2/SDL.h>
#include <stdint.h>

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

void CCursor::placeParticles(uint16_t x, uint16_t y, uint8_t w, uint8_t h, uint8_t particle)
{
    bool place_sand = false;
    bool place_water = false;

    if(scale == 1)
    {
        x = x + w/2;
        y = y + h/2;
    }

    if (particle == 1)
    {
        place_sand = true;
    } else if ( particle == 4 )
    {
        place_water = true;
    }

    for(uint8_t i = 1; i < w; i++) {
        for(uint8_t j = 1; j < h; j++) {
            
            if(place_sand)
            {
                particle = Util.random(1, 3);
            } else if (place_water)
            {
                particle = Util.random(4, 5); 
            } 
            
            if (not Util.isOutOfBounds((x+i)/scale, (y+j)/scale))
            {
                grid[(x+i)/scale][(y+j)/scale] = particle;
            }
        }
    }
}

