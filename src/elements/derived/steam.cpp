#include "../../main.hpp"
#include "../smoke.hpp"
#include "steam.hpp"

// seed

color_t steam_color = { 219, 255, 255 };


CSteam::CSteam()
{
    this->setColor( steam_color );
    type = dSteamElement;
}

void CSteam::receiveHeat(float heatAmount) {}