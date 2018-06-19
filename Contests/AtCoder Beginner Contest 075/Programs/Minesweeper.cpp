#include <cstdio>
#include <cstring>

const int N = 55;
const char EMPTY = '.', BOMB = '#';
char grid[N][N];

int bomb_count(int row, int column)
{
    const int NO_OF_NEIGHBOURS = 8;
    int x[NO_OF_NEIGHBOURS] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int y[NO_OF_NEIGHBOURS] = {1, 1, 1, 0, -1, -1, -1, 0};

    int bombs = 0;
    for(int i = 0; i < NO_OF_NEIGHBOURS; i++)
        bombs += (grid[row + x[i]][column + y[i]] == BOMB);

    return bombs;
}

int main()
{
    int height, width;
    scanf("%d %d", &height, &width);

    memset(grid, 0, sizeof(grid));
    for(int i = 1; i <= height; i++)
       scanf("%s", grid[i] + 1);

    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            if(grid[i][j] == EMPTY)
                grid[i][j] = bomb_count(i, j) + '0';

            printf("%c", grid[i][j]);
        }

        printf("\n");
    }

    return 0;
}
