#ifndef map_loader_hpp
#define map_loader_hpp

#include <SDL.h>

// colorNumber is reserved by opengl
#define _colorNumber 10

class CmapLoader 
{
    SDL_Surface* map;

    color_t color_list[_colorNumber]
    {
        { 234, 181, 11  }, // sand
        { 71, 126, 255  }, // water
        { 75, 27, 5     }, // wood 
        { 60, 67, 73    }, // smoke      
        { 255, 107, 1   }, // fire 
        { 179, 179, 179 }, // wall
        { 219, 255, 255 }, // steam
        { 28, 37, 48    }, // petrol
        { 86, 59, 40    }, // dirt
        { 76, 73, 81    }  // cracked brick
    };

    void placeParticle(uint16_t x, uint16_t y, uint8_t id);

    public:        
        void loadMap(const char* pathToMap);



};


#endif