#include <SDL2/SDL.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Event event;

bool running = true;



int main(int argc, char* args[])
{

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;


	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf( "SDL failed to initialize. Error: %s\n", SDL_GetError() );
        exit(1);
    }

	window = SDL_CreateWindow( "Sand game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	if( window == NULL )
	{
		printf( "Window could not be created. SDL_Error: %s\n", SDL_GetError() );
        exit(1);
	} 
    
	while(running)
    {
	    screenSurface = SDL_GetWindowSurface( window );
	    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
		

	    SDL_UpdateWindowSurface( window );

        if(event.type == SDL_QUIT)
        {
            running = false;
        }
	    
    }
    


	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}
