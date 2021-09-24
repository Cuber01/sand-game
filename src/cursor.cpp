#include <SDL2/SDL.h>
#include <stdint.h>


#include "elements/derived/dirt.hpp"
#include "elements/derived/steam.hpp"
#include "elements/derived/fire.hpp"
#include "elements/sand.hpp"
#include "elements/water.hpp"
#include "elements/wood.hpp"
#include "elements/smoke.hpp"

#include "settings.hpp"
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


void CCursor::placeParticles(uint16_t x, uint16_t y, uint8_t w, uint8_t h, element_t particle)
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
                if(particle != dNoneElement )
                {
                    CElement* o;
                    switch( particle )
                    {
                        case dSandElement:  o = new CSand();  break;
                        case dWaterElement: o = new CWater(); break;
                        case dSmokeElement: o = new CSteam(); break;
                        case dWoodElement:  o = new CWood();  break;
                        case dDirtElement:  o = new CDirt();  break;
                        case dFireElement:  o = new CFire();  break;
                        default:
                            printf("Unknown particle.");
                            exit(1);
                    }
                    grid[(x+i)/scale][(y+j)/scale] = o;//particle; //new particle;
                } else{
                    grid[(x+i)/scale][(y+j)/scale] = 0;
                } 
            }

        }
    }

}

