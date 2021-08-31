#define GO_DOWN(x, y)       do { next[x][y+1] = grid[x][y];   } while(0)
#define GO_DOWN_RIGHT(x, y) do { next[x+1][y+1] = grid[x][y]; } while(0)
#define GO_DOWN_LEFT(x, y)  do { next[x-1][y+1] = grid[x][y]; } while(0)
#define STAY(x, y)          do { next[x][y] = grid[x][y];     } while(0)

#define DOWN       x, y+1
#define DOWN_RIGHT x+1, y+1
#define DOWN_LEFT  x-1, y+1