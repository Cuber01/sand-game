#include <SDL.h>
#include <stdint.h>
#include <stdio.h>

#include "element_list.hpp"
#include "settings.hpp"
#include "cursor.hpp"
#include "main.hpp"

void CCursor::adjustCursor(int x, int y, uint8_t w, uint8_t h)
{
    if(SCALE > 1)
    {
        cursor.x = (x-w)/SCALE;
        cursor.y = (y-h)/SCALE;
    } else 
    {
        cursor.x = (x-(w/2))/SCALE;
        cursor.y = (y-(h/2))/SCALE;
    }

    
    cursor.w = w;
    cursor.h = h;

}


void CCursor::placeParticles(uint16_t x, uint16_t y, uint8_t w, uint8_t h, element_t particle)
{

    if(SCALE == 1)
    {
        x = x + w/2;
        y = y + h/2;
    }

    for(uint8_t i = 1; i < w; i++) {
        for(uint8_t j = 1; j < h; j++) {

            int grid_x = (x + i) / SCALE;
            int grid_y = (y + j) / SCALE;

            if (grid_x <= 0 || grid_x >= ROWS || grid_y <= 0 || grid_y >= COLS) {
                continue;
            }

            if ( Util.getGrid(grid_x, grid_y) == 0 && particle != dNoneElement)
            {                
                CElement* o;

                switch( particle )
                {
                    case dSandElement:         o = new CSand();  break;
                    case dWaterElement:        o = new CWater(); break;
                    case dSmokeElement:        o = new CSmoke(); break;
                    case dSteamElement:        o = new CSteam(); break;
                    case dWoodElement:         o = new CWood();  break;
                    case dWallElement:         o = new CWall();  break;
                    case dDirtElement:         o = new CDirt();  break;
                    case dFireElement:         o = new CFire();  break;
                    case dPetrolElement:       o = new CPetrol();  break;
                    case dCrackedBrickElement: o = new CCrackedBrick(); break;
                    default:
                        printf("Unknown particle.\n");
                        exit(1);
                }

                grid[grid_x][grid_y] = o;
                 
            } else if ( particle == dNoneElement ) {

                delete grid[grid_x][grid_y];

                grid[grid_x][grid_y] = 0;
                 
            }

        }
    }

}