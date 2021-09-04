#ifndef directions_hpp
#define directions_hpp

// -------------------- MOVE ------------------------

#define GO_UP(x, y)           do { next[x][y-1] = grid[x][y];   } while(0)
#define GO_DOWN(x, y)         do { next[x][y+1] = grid[x][y];   } while(0)

#define GO_DOWN_RIGHT(x, y)   do { next[x+1][y+1] = grid[x][y]; } while(0)
#define GO_DOWN_LEFT(x, y)    do { next[x-1][y+1] = grid[x][y]; } while(0)
#define GO_UP_RIGHT(x, y)     do { next[x+1][y-1] = grid[x][y]; } while(0)
#define GO_UP_LEFT(x, y)      do { next[x-1][y-1] = grid[x][y]; } while(0)

#define GO_LEFT(x, y)         do { next[x-1][y] = grid[x][y];   } while(0)
#define GO_RIGHT(x, y)        do { next[x+1][y] = grid[x][y];   } while(0)

#define STAY(x, y)            do { next[x][y] = grid[x][y];     } while(0)

// -------------------- PLACE -----------------------

#define PLACE_UP(x, y, n)         do { next[x][y-1] = n;   } while(0)
#define PLACE_DOWN(x, y, n)       do { next[x][y+1] = n;   } while(0)

#define PLACE_UP_RIGHT(x, y, n)   do { next[x+1][y-1] = n; } while(0)
#define PLACE_UP_LEFT(x, y, n)    do { next[x-1][y-1] = n; } while(0)
#define PLACE_DOWN_RIGHT(x, y, n) do { next[x+1][y+1] = n; } while(0)
#define PLACE_DOWN_LEFT(x, y, n)  do { next[x-1][y+1] = n; } while(0)

#define PLACE_LEFT(x, y, n)       do { next[x-1][y] = n;   } while(0)
#define PLACE_RIGHT(x, y, n)      do { next[x+1][y] = n;   } while(0)

#define PLACE_ON_ME(x, y, n)      do { next[x][y] = n;     } while(0)


// ----------------- DIRECTIONS ---------------------
#define DOWN       x,   y+1
#define UP         x,   y-1 
#define DOWN_RIGHT x+1, y+1
#define DOWN_LEFT  x-1, y+1
#define UP_RIGHT   x+1, y-1
#define UP_LEFT    x-1, y-1
#define RIGHT      x+1, y
#define LEFT       x-1, y
#define ME         x,   y 

#endif