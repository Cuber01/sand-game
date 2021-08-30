#include <stdio.h>
#include <inttypes.h>

#include "color.hpp"

class CParticle {
    
    public:
        uint16_t id;
        uint8_t type;
        uint8_t lifetime;
        color_t color;
        bool has_been_updated;
        
};