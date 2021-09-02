#include <SDL2/SDL.h>

#include "utils/data.hpp"
#include "render.hpp"
#include "main.hpp"


void CRenderHandler::init()
{

    renderer = SDL_CreateRenderer(window, -1, 0);
    
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

    for (uint16_t x = 0; x < cols; x++) {
        for (uint16_t y = 0; y < rows; y++) {

            uint8_t value = grid[x][y];

            if(value < 8)
            {
                color_t color = color_list[value];
            
                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            
            } else {

                color_t color = color_list[(rand()%10)+8];

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
    