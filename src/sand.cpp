class CSandHandler
{

    void sandUpdate(x, y)
    {
        if (GetGrid( x, y+1 ) == 0 ) // down
        {
          grid[x][y+1] = 1;
        } else if (GetGrid( x, y+1 ) == 2 || GetGrid( x, y+1 ) == 3) // down if water
        {
          grid[x][y] = GetGrid( x, y+1 );
          grid[x][y+1] = 1;
        } else if (GetGrid( x+1, y+1) == 0) // down right
        {
          grid[x+1][y+1] = 1;
        } else if (GetGrid( x-1, y+1) == 0) // down left
        {
          grid[x-1][y+1] = 1;
        } else {
          grid[x][y] = 1;
        }
        }
};