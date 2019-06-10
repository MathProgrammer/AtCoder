#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX_N = 2019;
char grid[MAX_N][MAX_N];
int leftmost_obstacle[MAX_N][MAX_N], rightmost_obstacle[MAX_N][MAX_N], up_obstacle[MAX_N][MAX_N], down_obstacle[MAX_N][MAX_N];

int main()
{
    int height, width;
    scanf("%d %d", &height, &width);

    for(int i = 1; i <= height; i++)
            scanf("%s", grid[i] + 1);

    memset(up_obstacle, 0, sizeof(up_obstacle));
    memset(leftmost_obstacle, 0, sizeof(leftmost_obstacle));

    for(int h = 1; h <= height; h++)
    {
        for(int w = 1; w <= width; w++)
        {
            leftmost_obstacle[h][w] = (grid[h][w] == '#' ? 0 : leftmost_obstacle[h][w - 1] + 1);

            up_obstacle[h][w] = (grid[h][w] == '#' ? 0 : up_obstacle[h - 1][w] + 1);
        }
    }

    memset(rightmost_obstacle, 0, sizeof(rightmost_obstacle));
    memset(down_obstacle, 0, sizeof(down_obstacle));

    for(int h = height; h >= 1; h--)
    {
        for(int w = width; w >= 1; w--)
        {
            rightmost_obstacle[h][w] = (grid[h][w] == '#' ? 0 : rightmost_obstacle[h][w + 1] + 1);

            down_obstacle[h][w] = (grid[h][w] == '#' ? 0 : down_obstacle[h + 1][w] + 1);
        }
    }

    int answer = 0;
    for(int  h = 1; h <= height; h++)
    {
        for(int w = 1; w <= width; w++)
        {
            if(grid[h][w] == '#')
                continue;

            answer = max(answer, leftmost_obstacle[h][w] + up_obstacle[h][w] + rightmost_obstacle[h][w] + down_obstacle[h][w] - 3);
        }
    }

    printf("%d\n", answer);
    return 0;
}
