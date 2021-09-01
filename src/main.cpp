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
#include "elements/smoke.hpp"
#include "elements/wood.hpp"
#include "utils/util.hpp"
#include "utils/data.hpp"


// sdl
SDL_Window* window = NULL;
SDL_Event event;


//int
uint16_t lastKeyPressed;
uint16_t lastId;

//bool
bool mouseIsPressed = false;
bool running = true;


// grid
uint16_t* particles = new uint16_t[5];

uint16_t grid[rows][cols];
uint16_t next[rows][cols];
uint16_t empty[rows][cols];



// objects
CCursor Cursor;
CRenderHandler RenderHandler;
CSandHandler  SandHandler;
CWaterHandler WaterHandler;
CSmokeHandler SmokeHandler;
CWoodHandler WoodHandler;
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

    case SDL_KEYDOWN:
        lastKeyPressed = event->key.keysym.sym;
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
        //SDL_Delay(100);
        
        while( SDL_PollEvent(&event) )
        {
            handleEvent(&event);
        }

        if(mouseIsPressed)
        {
            switch (lastKeyPressed)
            {
            
            case SAND_MODE:
                grid[Cursor.x/scale][Cursor.y/scale] = (rand()%3)+1;
                break;
            
            case WATER_MODE:
                grid[Cursor.x/scale][Cursor.y/scale] = 4; 
                break;

            case WOOD_MODE:
                grid[Cursor.x/scale][Cursor.y/scale] = 7; 
                break;

            case FIRE_MODE:
                grid[Cursor.x/scale][Cursor.y/scale] = 0; 
                break;

            case SMOKE_MODE:
                grid[Cursor.x/scale][Cursor.y/scale] = 6; 
                break;

            default:
                grid[Cursor.x/scale][Cursor.y/scale] = (rand()%3)+1;
                break;
            
            }
            
        } 

	    Cursor.adjustCursor(Cursor.x, Cursor.y, Cursor.w, Cursor.h);   

        memcpy( next, empty, sizeof(next) );

        for (uint16_t x = 0; x < cols; x++) {
            for (uint16_t y = 0; y < rows; y++) {
                uint8_t value = grid[x][y];

                if(value > 0) {
                    
                    switch(value)
                    {
                        case 1:
                        case 2:
                        case 3:
                            SandHandler.update(x, y);
                            break;

                        case 4:
                        case 5:
                            WaterHandler.update(x, y);
                            break;

                        case 6:
                            SmokeHandler.update(x, y);
                            break;

                        case 7:
                            WoodHandler.update(x, y);
                            break;


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
