#include <SDL2/SDL.h>
#include <stdio.h>
#include <inttypes.h>

#include "main.hpp"
#include "cursor.hpp"
#include "render.hpp"
#include "color.hpp"

SDL_Window* window = NULL;
SDL_Event event;

bool running = true;

uint8_t grid[rows][cols];

CCursor Cursor;
CRenderHandler RenderHandler;


void init()
{

    Cursor.changeCursor(20, 20, 40, 40);

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
        if(event->button.button == SDL_BUTTON_LEFT)
        {
            grid[Cursor.x/scale][Cursor.y/scale] = 1;
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


	    Cursor.changeCursor(Cursor.x, Cursor.y, Cursor.w, Cursor.h);        

        RenderHandler.draw();
	    
    }
    
    quit();

	return 0;
}
