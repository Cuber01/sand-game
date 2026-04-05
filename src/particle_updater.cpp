#include "particle_updater.hpp"
#include "main.hpp"
#include "elements/element.hpp"
#include <thread>
#include <vector>

#define BLOCK_SIZE 64

CParticleUpdater::CParticleUpdater()
{
    for (uint16_t y = 0; y < ROWS; y += BLOCK_SIZE) {
        for (uint16_t x = 0; x < COLS; x += BLOCK_SIZE) {
            GridBlock b;
            b.x_start = x;
            b.x_end = (x + BLOCK_SIZE < COLS) ? (x + BLOCK_SIZE) : COLS;
            b.y_start = y;
            b.y_end = (y + BLOCK_SIZE < ROWS) ? (y + BLOCK_SIZE) : ROWS;

            int grid_x = x / BLOCK_SIZE;
            int grid_y = y / BLOCK_SIZE;
            
            int type = (grid_y % 3) * 3 + (grid_x % 3);
            blocks[type].push_back(b);
        }
    }
}

void processBlock(const GridBlock& block) {
    for (uint16_t y = block.y_start; y < block.y_end; y++) {
        for (uint16_t x = block.x_start; x < block.x_end; x++) {
            CElement* value = grid[x][y];
            if(value != 0) {
                value->update(x, y);
            }        
        }    
    }
}

void CParticleUpdater::updateParticles()
{
    for (int type = 0; type < 9; type++) {
        std::vector<std::thread> worker_threads;
        
        for (const auto& block : blocks[type]) {
            worker_threads.emplace_back(processBlock, block);
        }
        
        for (auto& t : worker_threads) {
            t.join();
        }
    }
}
