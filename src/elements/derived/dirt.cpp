#include "../../main.hpp"
#include "../directions.hpp"
#include "dirt.hpp"

#include "../../utils/util.hpp"
// seed

color_t dirt_color_list[3] =
{
    { 86, 59, 40 },
    { 66, 44, 31 }, 
    { 119, 80, 54 }, 
};

CDirt::CDirt()
{
    this->setColor( dirt_color_list[Util.random(0, 2)] );
    canBeNudged = true;
    type = dDirtElement;
    nudgeChance = 0.01;
}