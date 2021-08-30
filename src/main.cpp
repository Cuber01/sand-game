#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Event event;

bool running = true;

void init()
{
    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf( "SDL failed to initialize. Error: %s\n", SDL_GetError() );
        exit(1);
    }

	window = SDL_CreateWindow("Sand game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if( window == NULL )
	{
		printf( "Window could not be created. SDL_Error: %s\n", SDL_GetError() );
        exit(1);
	} 
}

void quit()
{
	SDL_DestroyWindow( window );
	SDL_Quit();
}

void handleEvent(SDL_Event* event)
{
    switch (event->type)
    {
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

	    screenSurface = SDL_GetWindowSurface( window );
	    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
		

	    SDL_UpdateWindowSurface( window );


	    
    }
    
    quit();

	return 0;
}
