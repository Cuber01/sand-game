#ifndef particle_updater_hpp
#define particle_updater_hpp

#include <stdint.h>
#include <vector>

struct GridBlock {
    uint16_t x_start;
    uint16_t x_end;
    uint16_t y_start;
    uint16_t y_end;
};

class CParticleUpdater
{
private:
    std::vector<GridBlock> blocks[9];
public:
    CParticleUpdater();
    void updateParticles();
};

#endif
