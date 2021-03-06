#ifndef util_hpp
#define util_hpp

#include <stdint.h>

class CUtil
{
    private:


    public:

        // ------------- WORLD --------------------

        // this is returned by get functions when they encounter a bound, to indicate that it is not an empty space
        CElement bounds;

        // returns a value from grid[][]
        CElement* getGrid( uint16_t x, uint16_t y );

        // returns a value from next[][]
        CElement* getNext( uint16_t x, uint16_t y );

        // returns whether I'm surrounded by elements from all sides
        bool isSurrounded(uint16_t x, uint16_t y);

        // whether a given x and y are out of bounds of our game
        bool isOutOfBounds( uint16_t x, uint16_t y );

        // switch two cells (doesnt work...)
        void switchCells( uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);

        // clear grid
        void clearGrid();

        // get color of a pixel at xy coordinates from surface 
        color_t getPixel(const SDL_Surface* surface, uint16_t x, uint16_t y);

        const char* getFileExtension(const char* path);

        // ------------ RANDOM -------------------

        // return a random number where x is min <= x <=max
        uint8_t random(uint8_t min, uint8_t max);

        uint16_t random_u16(uint16_t min, uint16_t max);

        // returns -1 or 1. 50% chance
        int8_t randomPositiveNegative();

        // returns true or false. 50% chance
        bool randomBool();

        // returns true or false with a given chance for true
        bool randomBoolChance(float chance);

        


};

#endif