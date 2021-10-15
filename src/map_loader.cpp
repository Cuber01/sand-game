#include <settings.hpp>

#ifdef MAP_LOADER

#include <SDL.h>
#include <SDL_image.h>
#include <string.h>
#include <stdio.h>

#include "element_list.hpp"
#include "map_loader.hpp"
#include "main.hpp"


void CmapLoader::placeParticle(uint16_t x, uint16_t y, uint8_t id) {
    switch (id)
    {
        case 0:  grid[x][y] = new CSand;   break;    
        case 1:  grid[x][y] = new CWater;  break;
        case 2:  grid[x][y] = new CWood;   break;
        case 3:  grid[x][y] = new CSmoke;  break;
        case 4:  grid[x][y] = new CFire;   break;
        case 5:  grid[x][y] = new CWall;   break;
        case 6:  grid[x][y] = new CSteam;  break;
        case 7:  grid[x][y] = new CPetrol; break;
        case 8:  grid[x][y] = new CDirt;   break;
        case 9:  grid[x][y] = new CCrackedBrick; break;
        default: grid[x][y] = 0;
    }
}

void CmapLoader::loadMap(const char* pathToMap)
{
    Util.clearGrid();

    const char* png = "png";

    if(strcmp(Util.getFileExtension(pathToMap), png))
    {
        printf(Util.getFileExtension(pathToMap));
        return;
    }

    map = IMG_Load(pathToMap);

    for (uint16_t x = 0; x < ROWS; x++) {
        for (uint16_t y = 0; y < COLS; y++) {

            color_t pixel_color = Util.getPixel(map, x, y);

            for(uint16_t i = 0; i < _colorNumber; i++)
            {
                if(color_list[i].r == pixel_color.r &&
                   color_list[i].g == pixel_color.g &&
                   color_list[i].b == pixel_color.b) 
                {
                    placeParticle(x, y, i);
                }

            }

        }

    }
    
    SDL_FreeSurface(map);

}

#endif