#ifndef element_hpp
#define element_hpp

#include <stdint.h>
#include <float.h>
#include "../utils/data.hpp"


class CElement
{ 
    private:
    // protected:

        // my color
        color_t color;  
    public:

        // contructor 
        CElement();

        // who am I?
        uint8_t type; 

        // ------------------------ PHYSICS ------------------------ 

        // when a movable solid moves on me, it loses its velocity_x by my friction (velocity_x - friction) [unused]
        uint8_t friction;
        
        // velocity in y axis
        float velocity_y = 1;

        // velocity in x axis
        float velocity_x = 0;

        // --------------------- MOVABLE SOLID --------------------- 

        // if set to false, element will check only cell on down (y+1, x) [used in sand only atm]
        bool isFalling = true;

        // chance for setting isFalling to true while being nudged [used in sand only atm]
        float nudgeChance = 0.1;

        // whether I can be nudged by other cells
        bool canBeNudged = false;

        // ------------------------- HEAT ------------------------- 

        // am I burning?
        bool isBurning = false;

        // heatResistance I start with
        float initialHeatResistance;

        // when an element emits heat, heatResistance will decrement, when it hits 0, I burn
        float heatResistance;

        // amount of heat I emit
        float amountOfHeatToEmit = 0.2;

        // if it hits 0, I'm not burning anymore
        int8_t fireStrength;

        // when hitpoints hit 0 I die, can be decremented by fire (and explosions in the future)
        float hitpoints = 100;

        // ------------------------ LIQUID ------------------------ 

        // if true, cell won't update next frame [used in water only atm]
        bool willBeReplaced = false;

        // ----------------------- METHODS ------------------------ 

        virtual ~CElement();
        
        // set my color
        void setColor( color_t color);

        // return my color
        color_t getColor();

        // main update loop
        virtual void update(uint16_t x,uint16_t y);

        // lower heat resistance by incoming heat
        virtual void receiveHeat(float heatAmount);

        // emit amountOfHeatToEmit
        void emitHeat(uint16_t x, uint16_t y);

        // check if I should be burning, if yes, set isBurning to true
        void checkHeat();

        // check if I should be dead, if yes, commit sudoku
        virtual void checkHitpoints(uint16_t x, uint16_t y);

        // increment stack if DEBUG_STACK is defined
        void incrementStack();

        
};


#endif