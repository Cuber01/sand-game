#include "../../main.hpp"
#include "../directions.hpp"
#include "fire.hpp"

#include "../../utils/util.hpp"


color_t fire_color_list[3] =
{
    { 255, 160, 1  },
    { 255, 107, 1  },
    { 255, 79, 1   },
};

CFire::CFire()
{
    setColor( fire_color_list[Util.random(0, 2)] );
    lifetime = Util.random(30, 80);
    type = dFireElement;
}

void CFire::update(uint16_t x,uint16_t y)
{
    setColor( fire_color_list[Util.random(0, 2)] );
    handleLifetime(x, y);
    move(x, y);
}


