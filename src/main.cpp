#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <memory>
#include <time.h>

#include "main.hpp"
#include "cursor.hpp"
#include "render.hpp"
#include "utils/util.hpp"
#include "utils/data.hpp"
#include "elements/element.hpp"
#include "elements/wood.hpp"
#include "elements/water.hpp"
#include "elements/sand.hpp"



// sdl
SDL_Window* window = NULL;
SDL_Event event;


//int
uint16_t lastKeyboardKeyPressed;
uint8_t  lastMouseKeyPressed;
uint32_t lastId;

//bool
bool mouseIsPressed = false;
bool running = true;


// grid
CElement* grid[rows][cols];
CElement* next[rows][cols];


// objects
CCursor Cursor;
CRenderHandler RenderHandler;
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
                case KEY_SAND_MODE_NUMKEY1 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, dSandElement);                
                    break;
                case KEY_WATER_MODE_NUMKEY2 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, dWaterElement);                
                    break;
                case KEY_WOOD_MODE_NUMKEY3 :
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, dWoodElement);                
                    break;
                case KEY_FIRE_MODE_NUMKEY4 :
                    break;
                case KEY_SMOKE_MODE_NUMKEY5 :
                    break;
                default:
                    Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, dSandElement);
                    break;

            } 

        } else if (lastMouseKeyPressed == SDL_BUTTON_RIGHT) 
        {
            Cursor.placeParticles(Cursor.x - Cursor.h, Cursor.y - Cursor.h, Cursor.w * scale, Cursor.h * scale, dNoneElement );   
        }   
         
    } else if (lastKeyboardKeyPressed == SDLK_BACKQUOTE)
    {
        memset( next, 0, sizeof(next) );
        memset( grid, 0, sizeof(next) );
        lastKeyboardKeyPressed = 0;
    }
}

void updateParticles()
{


    for (uint16_t x = 0; x < cols; x++) {
            for (uint16_t y = 0; y < rows; y++) {
                CElement* value = grid[x][y];

                if(value != 0) {
                    
                    value->update(x, y);

                }        
        
            }
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


        Cursor.adjustCursor(Cursor.x, Cursor.y, Cursor.w, Cursor.h);   
        handleInput();

        memset( next, 0, sizeof(next) );

        updateParticles();

        RenderHandler.draw();

        memcpy( grid, next, sizeof(grid) );
        
    }

    quit();

	return 0;
}
