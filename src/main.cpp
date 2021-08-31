#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <time.h>

#include "main.hpp"
#include "cursor.hpp"
#include "render.hpp"
#include "elements/sand.hpp"
#include "elements/water.hpp"
#include "utils/util.hpp"
#include "utils/color.hpp"


// sdl
SDL_Window* window = NULL;
SDL_Event event;

// bool
bool mouseIsPressed = false;
bool running = true;

// grid
uint8_t grid[rows][cols];
uint8_t next[rows][cols];
uint8_t empty[rows][cols];

// objects
CCursor Cursor;
CRenderHandler RenderHandler;
CSandHandler  SandHandler;
CWaterHandler WaterHandler;
CUtil Util;

void init()
{

    Cursor.adjustCursor(20, 20, 40, 40);
    std:srand((unsigned)time(NULL));

    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        printf( "SDL failed to initialize. Error: %s\n", SDL_GetError() );
        exit(1);
    }

	window = SDL_CreateWindow("Sand game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if(window == NULL)
	{
		printf( "Window could not be created. SDL_Error: %s\n", SDL_GetError() );
        exit(1);
	} 

    SDL_ShowCursor(SDL_DISABLE);
    RenderHandler.init();

}

void quit()
{
    SDL_DestroyRenderer( RenderHandler.renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}

void handleEvent(SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_MOUSEMOTION:
        SDL_GetMouseState( &Cursor.x, &Cursor.y );
        break;

    case SDL_MOUSEBUTTONDOWN:
        mouseIsPressed = true;
        break;

    case SDL_MOUSEBUTTONUP:
        mouseIsPressed = false;
        break;

    case SDL_QUIT:
        running = false;
        break;
    
    default:
        break;
    }
}


int main(int argc, char* args[])
{

    init();

    
	while(running)
    {
        while( SDL_PollEvent(&event) )
        {
            handleEvent(&event);
        }

        if(mouseIsPressed)
        {
            //spawn sand
            //grid[Cursor.x/scale][Cursor.y/scale] = (rand()%3)+1;

            grid[Cursor.x/scale][Cursor.y/scale] = 4; 
            
        } 

	    Cursor.adjustCursor(Cursor.x, Cursor.y, Cursor.w, Cursor.h);   

        memcpy( next, empty, sizeof(next) );

        for (uint16_t x = 0; x < cols; x++) {
            for (uint16_t y = 0; y < rows; y++) {
                uint8_t value = grid[x][y];

                if(value > 0) {
                    
                    if (value <= 3)
                    {
                        SandHandler.sandUpdate(x, y);
                    } else if (value == 4 || value == 5)
                    {
                        WaterHandler.waterUpdate(x, y);
                    }
                
                }        
        
            }
        }     

        RenderHandler.draw();

        memcpy( grid, next, sizeof(grid) );
	    
    }
    
    quit();

	return 0;
}
