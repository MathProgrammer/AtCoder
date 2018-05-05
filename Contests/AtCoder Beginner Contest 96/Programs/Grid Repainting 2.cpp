#include <iostream>

using namespace std;

const int MAX_N = 55, BLACK = 2, WHITE = 1;
int grid[MAX_N][MAX_N];

int all_neighbours_white(int row, int column)
{
    const int NO_OF_NEIGHBOURS = 4;
    int neighbour_x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
    int neighbour_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};

    for(int i = 0; i < NO_OF_NEIGHBOURS; i++)
        if(grid[row + neighbour_x[i]][column + neighbour_y[i]] == BLACK)
            return false;

    return true;
}

int main()
{
    int height, width;
    cin >> height >> width;

    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            char block;
            cin >> block;

            grid[i][j] = (block == '#' ? BLACK : WHITE);


        }
    }

    int possible = true;
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            if(grid[i][j] == BLACK && all_neighbours_white(i, j))
            {
                possible = false;
            }
        }
    }

    cout << (possible ? "Yes\n" : "No\n");

    return 0;
}

