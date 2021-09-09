#include "../main.hpp"
#include "directions.hpp"
#include "element.hpp"

#include <stdint.h> 


color_t color_list[3] =
{
    { 234, 181, 11 }, // sand 1
    { 251, 209, 72 }, // sand 2
    { 251, 242, 54 }, // sand 3
};

CElement::CElement() {}

void CElement::update(uint16_t x,uint16_t y) {}

void CElement::setColor( color_t color) {
    this->color = color;
}

color_t CElement::getColor() {
    return this->color;
}


