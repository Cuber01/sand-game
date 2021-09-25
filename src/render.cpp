#include <SDL2/SDL.h>


#include "elements/element.hpp"
#include "settings.hpp"
#include "utils/data.hpp"
#include "render.hpp"
#include "main.hpp"


void CRenderHandler::init()
{
    #ifdef SOFTWARE_RENDERING
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE); 
    #else
    renderer = SDL_CreateRenderer(window, -1, 0); 
    #endif

    if (renderer == NULL)
    {
        printf("Renderer failed to initialize. Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_RenderSetScale(renderer, scale, scale);
}


void CRenderHandler::draw()
{
    clear();

    #ifndef SOFTWARE_RENDERING

    // create surface
    surface = SDL_CreateRGBSurface(SDL_SWSURFACE, rows, cols, 32, 0, 0, 0, 0);

    if(surface == NULL) 
    {
        printf("Failed to create surface: %s\n", SDL_GetError());
        exit(1);
    }

    // main surface draw loop
    SDL_LockSurface(surface);

    unsigned char* pixels = (unsigned char*)surface -> pixels;
    CElement* value;

    for (uint16_t x = 0; x < rows; x++) {
        for (uint16_t y = 0; y < cols; y++) {

            value = grid[x][y];

            if(value != 0)
            {
                color_t color = value->getColor();

                pixels[4 * (y * surface -> w + x) + 3] = 255;   //opacity

                pixels[4 * (y * surface -> w + x) + 2] = color.r;   //red
                pixels[4 * (y * surface -> w + x) + 1] = color.g;   //green
                pixels[4 * (y * surface -> w + x) + 0] = color.b;   //blue   

            }

        }
    }

    SDL_UnlockSurface(surface);

    // create texture from surface
    texture = SDL_CreateTextureFromSurface(renderer, surface); 
    
    // copy texture over to renderer
    SDL_RenderCopy(renderer, texture, NULL, NULL); 
    
    #endif
     

    #ifdef SOFTWARE_RENDERING

    // main draw loop
    for (uint16_t x = 0; x < rows; x++) {
        for (uint16_t y = 0; y < cols; y++) {
            
            CElement* value = grid[x][y];

            if(value != 0)
            {            

                color_t color = value->getColor();
                //printf("r:%d g:%d b:%d", color.r, color.g, color.b);

                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
                
            }

        }
    }

    #endif

    // draw cursor
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &Cursor.cursor);


    SDL_RenderPresent(renderer);
}

void CRenderHandler::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}
    