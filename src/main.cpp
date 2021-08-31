#include <SDL2/SDL.h>
#include <stdio.h>
#include <inttypes.h>

#include "main.hpp"
#include "mouse.hpp"
#include "draw.hpp"
#include "color.hpp"

SDL_Window* window = NULL;
SDL_Event event;

bool running = true;

uint8_t grid[rows][cols];

CMouse Mouse;
CDrawing Drawing;


void init()
{

    Mouse.changeCursor(20, 20, 40, 40);

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

    Drawing.init();

}

void quit()
{
    SDL_DestroyRenderer( Drawing.renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}

void handleEvent(SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_MOUSEMOTION:
        SDL_GetMouseState( &Mouse.x, &Mouse.y );
        break;

    case SDL_MOUSEBUTTONDOWN:
        if(event->button.button == SDL_BUTTON_LEFT)
        {
            running = false;
        } 
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


	    Mouse.changeCursor(Mouse.x, Mouse.y, Mouse.w, Mouse.h);        

        Drawing.draw();
	    
    }
    
    quit();

	return 0;
}
