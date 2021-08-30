#include <SDL2/SDL.h>
#include <stdio.h>

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

bool running = true;

void init()
{
    if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf( "SDL failed to initialize. Error: %s\n", SDL_GetError() );
        exit(1);
    }

	window = SDL_CreateWindow("Sand game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if( window == NULL )
	{
		printf( "Window could not be created. SDL_Error: %s\n", SDL_GetError() );
        exit(1);
	} 
}

void quit()
{
    SDL_DestroyRenderer( renderer );
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
	    
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, 400, 300); 
        SDL_RenderPresent(renderer);

	    SDL_UpdateWindowSurface( window );


	    
    }
    
    quit();

	return 0;
}
