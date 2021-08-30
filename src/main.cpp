#include <SDL2/SDL.h>
#include <stdio.h>

#include "mouse.cpp"

const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;


SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;

bool running = true;

CMouse Mouse;

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

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL)
    {
        printf("Renderer failed to initialize. Error: %s\n", SDL_GetError());
        exit(1);
    }
}

void quit()
{
    SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
}

void clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void handleEvent(SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_MOUSEMOTION:
        SDL_GetMouseState( &Mouse.x, &Mouse.y );
        break;

    case SDL_QUIT:
        running = false;
        break;
    
    default:
        break;
    }
}

void draw()
{
    clear();
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderDrawRect(renderer, &Mouse.cursor);

    SDL_RenderDrawPoint(renderer, 400, 300); 

    SDL_RenderPresent(renderer);

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

        draw();
	    
    }
    
    quit();

	return 0;
}
