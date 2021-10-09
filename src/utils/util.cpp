#include "../main.hpp" 
#include "util.hpp"

#include "../elements/element.hpp"
#include "../elements/directions.hpp"

#include <stdint.h>
#include <random>


bool CUtil::isOutOfBounds(uint16_t x, uint16_t y)
{
    if(x >= ROWS || x <= 0 || y >= COLS || y <= 0) {
        return true;
    }

    return false;
}

CElement* CUtil::getNext(uint16_t x, uint16_t y)
{
    if(isOutOfBounds(x, y))
    {
        return &bounds; 
    }

    return next[x][y];

}

CElement* CUtil::getGrid(uint16_t x, uint16_t y)
{
    if(isOutOfBounds(x, y))
    {
        return &bounds;
    }

    return grid[x][y];

}

bool CUtil::isSurrounded(uint16_t x, uint16_t y)
{
    if(
        getGrid( DOWN ) && getGrid( UP )
        && getGrid( LEFT ) && getGrid( RIGHT )
        && getGrid( DOWN_LEFT ) && getGrid( DOWN_RIGHT )
        && getGrid( UP_LEFT ) && getGrid( UP_RIGHT ) 
    ) 
    {
        return true;
    }

    return false;
}

void CUtil::switchCells( uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2 )
{
    CElement* cell1 = grid[x1][y1];
    CElement* cell2 = grid[x2][y2];

    next[x1][y1] = cell2;
    next[x2][y2] = cell1;

    grid[x1][y1] = 0;
    grid[x2][y2]->willBeReplaced = true;
}

color_t CUtil::getPixel(const SDL_Surface* surface, uint16_t x, uint16_t y)
{
	// bytes per pixel
	const Uint8 bpp = surface->format->BytesPerPixel;

	/*
	Retrieve the address to a specific pixel
	surface->pixels	    = an array containing the SDL_Surface pixels
	surface->pitch		= the length of a row of pixels (in bytes)
	x and y				= offset
	*/

	Uint8* pixel = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

	Uint32 PixelData = *(Uint32*)pixel;

	color_t color;

	// Retrieve the RGB values of the specific pixel
	SDL_GetRGB(PixelData, surface->format, &color.r, &color.g, &color.b);

	return color;
}

const char* CUtil::getFileExtension(const char* path)
{
    const char *dot = strrchr(path, '.');
    if(!dot || dot == path) return "";
    return dot + 1;
}

void CUtil::clearGrid()
{
    for(uint8_t x = 0; x <= ROWS; x++) 
    {
        for(uint8_t y = 0; y <= COLS; y++) 
        {
                
            if(grid[x][y] != 0)
            {
                delete grid[x][y];
    
                grid[x][y] = 0;
            }
    
        }
    }
}


uint8_t CUtil::random(uint8_t min, uint8_t max)
{
    return rand()%(max-min + 1) + min;
}

uint16_t CUtil::random_u16(uint16_t min, uint16_t max)
{
    return rand()%(max-min + 1) + min;
}


int8_t CUtil::randomPositiveNegative()
{
    uint8_t choice = randomBool();

    if(choice == 0) {
        return 1; 
    } else {
        return -1;
    } 
}


bool CUtil::randomBool()
{
    return rand() & 1;
}


bool CUtil::randomBoolChance(float chance)
{   
    static std::default_random_engine generator;

    std::bernoulli_distribution distribution(chance);

    return distribution(generator);

}

