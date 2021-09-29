#include "../main.hpp"
#include "directions.hpp"
#include "sand.hpp"

#include "../utils/util.hpp"
#include <float.h>
#include <stdint.h> 

#define sRETURN { isFalling = true; return; }


color_t sand_color_list[3] =
{
    { 234, 181, 11 },
    { 251, 209, 72 }, 
    { 251, 242, 54 }, 
};

CSand::CSand()
{
    this->setColor( sand_color_list[Util.random(0, 2)] );
    canBeNudged = true;
    type = dSandElement;
    nudgeChance = 0.9;
}


// WARNING: RETURNS AHEAD
void CSand::move(uint16_t x, uint16_t y)
{

    if (!isFalling) {

        notFallingUpdate(x, y);

        return;
    } 

    //------

    if (Util.getGrid( DOWN ) == 0)
    {
        fall(x, y);
        sRETURN;
    }
    
    if (Util.getGrid( DOWN )->type == dWaterElement)
    {
        // grid [x][y] = 1
        // grid [x][y+1] = 2

        //GO_DOWN(x, y);
        next[x][y+1] = grid[x][y];

        // grid[x][y] = 1
        // grid[x][y+1] = 2
        // next[x][y+1] = 1
        
        next[x][y] = grid[x][y+1];

        // grid[x][y] = 1
        // grid[x][y+1] = 2
        // next [x][y+1] = 1
        // next [x][y] = 2

        grid[x][y+1]->willBeReplaced = true;

        sRETURN; // TODO
    }

    //------

    check_order = Util.randomBool();

    if(check_order)
    {
        
        if (Util.getGrid( DOWN_RIGHT ) == 0) 
        {
            GO_DOWN_RIGHT(x, y);
            sRETURN;
        } else if (Util.getGrid( DOWN_LEFT ) == 0) 
        {
            GO_DOWN_LEFT(x, y);
            sRETURN;
        }
    
    } else {

        if (Util.getGrid( DOWN_LEFT ) == 0) 
        {
            GO_DOWN_LEFT(x, y);
            sRETURN;
        } else if (Util.getGrid( DOWN_RIGHT ) == 0) 
        {
            GO_DOWN_RIGHT(x, y);
            sRETURN;
        }

    }

    //------

    if (velocity_x >= 0.5) 
    {
        react_to_velocity_x(x, y, direction);
        sRETURN;
    }

    // else:
        STAY(x, y);

        velocity_x = velocity_y/2;
        direction = Util.randomPositiveNegative();

        velocity_y = 0;
        isFalling = false;

}

void CSand::notFallingUpdate(uint16_t x, uint16_t y)
{
    if (Util.getGrid( DOWN ) == 0)
    {
        fall(x, y);
        isFalling = true;
    } else {
        STAY(x, y);
        velocity_y = 0;
    }
}

void CSand::update(uint16_t x, uint16_t y)
{
    move(x, y);
    
    if(isFalling)
    {
        nudge_neighbors(x, y);
    }
    
}

void CSand::nudge_neighbors(uint16_t x, uint16_t y)
{
    CElement* rightElement = Util.getGrid( RIGHT );
    CElement* leftElement = Util.getGrid( LEFT );

    if(rightElement)
    {
        if(rightElement->canBeNudged)
        {

            if(!Util.randomBoolChance(rightElement->nudgeChance))
            {
                rightElement->isFalling = true;
            }

        } 
    }

    if(leftElement)
    {
        if(leftElement->canBeNudged)
        {
            if(!Util.randomBoolChance(leftElement->nudgeChance))
            {
                leftElement->isFalling = true;
            }
        } 
    }

}

void CSand::fall(uint16_t x, uint16_t y)
{
    int8_t rounded_vel_y = std::roundf(velocity_y);


    for(int8_t i = 1; i <= rounded_vel_y; i++)
    {
        if(Util.getGrid(x, y+i) == 0) // TODO if i add getnext checks it doesnt work
        {
            if(Util.getGrid(x , y + i+1) != 0)
            {
                GO(x, y, x, y+i);
                return;
            }
        
        } else {
            STAY(x, y);
            return;
        }   
    }

    GO(x, y, x, y+rounded_vel_y);

    if(velocity_y < MAX_FALL_SPEED)
    {
        velocity_y += GRAVITY;
    } else {
        velocity_y = MAX_FALL_SPEED;
    }
}


void CSand::react_to_velocity_x(uint16_t x, uint16_t y, int8_t direction)
{
    int8_t rounded_vel_x = std::roundf(velocity_x);


    for(int8_t i = 1; i <= rounded_vel_x; i++)
    {
        if(Util.getGrid(x+(i*direction), y) == 0) 
        {
            if(Util.getGrid(x + ( (i+1) * direction ), y) != 0)
            {
                GO(x, y, x+(i*direction), y);
                velocity_x -= BOUNDS_FRICTION; //TODO it should use friction of the object below
                return;
            }
        
        } else {
            STAY(x, y);
            velocity_x = 0;
            return;
        }   
    }

    GO(x, y, x+(rounded_vel_x * direction), y);
    velocity_x -= BOUNDS_FRICTION;

}

void CSand::receiveHeat(float heatAmount) {}



