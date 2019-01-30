#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_WIDTH = 1005, MAX_HEIGHT = 1005, MOD = 1e9 + 7;
const char WALL = '#';
char grid[MAX_WIDTH][MAX_HEIGHT];
long long no_of_paths[MAX_WIDTH][MAX_HEIGHT];

int main()
{
    int height, width;
    scanf("%d %d", &height, &width);

    for(int i = 1; i <= height; i++)
        scanf("%s", grid[i] + 1);

    memset(no_of_paths, 0, sizeof(no_of_paths));

    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            if(grid[i][j] == WALL) continue;

            if(i == 1 && j == 1)
            {
                no_of_paths[i][j] = 1;
            }
            else
            {
                no_of_paths[i][j] = (no_of_paths[i - 1][j] + no_of_paths[i][j - 1])%MOD;
            }
        }
    }

    printf("%lld", no_of_paths[height][width]);
    return 0;
}
