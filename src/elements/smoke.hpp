#ifndef smoke_hpp
#define smoke_hpp


#include <stdint.h>

class CSmoke : public CElement
{
    private:
        void move(uint16_t x, uint16_t y);

        int16_t lifetime;

    public:
        CSmoke();

        void update(uint16_t x, uint16_t y);

};


#endif