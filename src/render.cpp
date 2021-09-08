#include <SDL2/SDL.h>


#include "elements/element.hpp"
#include "utils/data.hpp"
#include "render.hpp"
#include "main.hpp"


void CRenderHandler::init()
{
    
    renderer = SDL_CreateRenderer(window, -1, 0); // TODO
    
    if (renderer == NULL)
    {
        printf("Renderer failed to initialize. Error: %s\n", SDL_GetError());
        exit(1);
    }

    // SDL_RendererInfo rendererInfo;
    // SDL_GetRendererInfo(renderer, &rendererInfo);
    // SDL_Log("Renderer: %s", rendererInfo.name);

    SDL_RenderSetScale(renderer, scale, scale);
}


void CRenderHandler::draw()
{
    clear();

    for (uint16_t x = 0; x < cols; x++) {
        for (uint16_t y = 0; y < rows; y++) {
            
            CElement* value = grid[x][y];

            if(value != 0)
            {            

                color_t color = value->color;
                //printf("r:%d g:%d b:%d", color.r, color.g, color.b);

                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
                
            }

        }
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &Cursor.cursor);


    SDL_RenderPresent(renderer);
}

void CRenderHandler::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}
    