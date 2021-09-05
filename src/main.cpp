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
#include "elements/fire.hpp"
#include "utils/util.hpp"
#include "utils/data.hpp"


// sdl
SDL_Window* window = NULL;
SDL_Event event;


//int
uint16_t lastKeyboardKeyPressed;
uint8_t  lastMouseKeyPressed;
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
CFireHandler FireHandler;
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

   // SDL_ShowCursor(SDL_DISABLE);
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
        lastMouseKeyPressed = event->button.button;
        mouseIsPressed = true;
        break;

    case SDL_MOUSEBUTTONUP:
        mouseIsPressed = false;
        break;

    case SDL_MOUSEWHEEL:
        if(event->wheel.y > 0) 
        {
            Cursor.w = Cursor.w+2;
            Cursor.h = Cursor.h+2;
        } else if(event->wheel.y < 0) 
        {
            if(Cursor.w >= 3 && Cursor.h >= 3)
            {
                Cursor.w = Cursor.w - Cursor.change_value;
                Cursor.h = Cursor.h - Cursor.change_value;
            }
        }
        break;


    case SDL_KEYDOWN:
        lastKeyboardKeyPressed = event->key.keysym.sym;
        break;

    case SDL_QUIT:
        running = false;
        break;
    
    default:
        break;
    }

}

void handleInput()
{
    if(mouseIsPressed)
    {
        if(lastMouseKeyPressed == SDL_BUTTON_LEFT)
        {
            switch (lastKeyboardKeyPressed)
            {

                case SAND_MODE:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, 1);
                    break;

                case WATER_MODE:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, 4);
                    break;

                case WOOD_MODE:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, 6);
                    break;

                case FIRE_MODE:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, 100);
                    break;

                case SMOKE_MODE:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, 7);
                    break;

                default:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, 1);
                    break;

            } 

        } else if (lastMouseKeyPressed == SDL_BUTTON_RIGHT) 
        {
            Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, 0);   
        }   
         
    } 
}

void updateParticles()
{


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
                            WoodHandler.update(x, y);
                            break;

                        case 7:
                            SmokeHandler.update(x, y);
                            break;

                        case 255:
                            break;

                        default:
                            FireHandler.update(x, y);
                            break;
   
                    }
                }        
        
            }
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


        Cursor.adjustCursor(Cursor.x, Cursor.y, Cursor.w, Cursor.h);   
        handleInput();

        memcpy( next, empty, sizeof(next) );

        updateParticles();

        RenderHandler.draw();

        memcpy( grid, next, sizeof(grid) );
        
    }

    quit();

	return 0;
}
