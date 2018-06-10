#include <cstdio>
#define min(a, b) (a < b ? a : b)

const int MAX_N = 505, MAX_COLOURS = 35;
int cost[MAX_COLOURS][MAX_COLOURS], frequency[MAX_COLOURS][3];

int all_different(int x, int y, int z)
{
    return (x != y && y != z && z != x);
}

int main()
{
    int n, no_of_colours;
    scanf("%d %d", &n, &no_of_colours);

    for(int i = 1; i <= no_of_colours; i++)
        for(int j = 1; j <= no_of_colours; j++)
            scanf("%d", &cost[i][j]);

    int number;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &number), frequency[number][(i + j)%3]++;

    const int oo = 1e9;
    int minimum_cost = oo;

    for(int c0 = 1; c0 <= no_of_colours; c0++)
    {
        for(int c1 = 1; c1 <= no_of_colours; c1++)
        {
            for(int c2 = 1; c2 <= no_of_colours; c2++)
            {
                if(all_different(c0, c1, c2))
                {
                    int cost_here = 0;

                    for(int c = 1; c <= no_of_colours; c++)
                        cost_here += cost[c][c0]*frequency[c][0];

                    for(int c = 1; c <= no_of_colours; c++)
                        cost_here += cost[c][c1]*frequency[c][1];

                    for(int c = 1; c <= no_of_colours; c++)
                        cost_here += cost[c][c2]*frequency[c][2];

                    minimum_cost = min(minimum_cost, cost_here);
                }
            }
        }
    }

    printf(minimum_cost >= oo ? "-1\n" : "%d\n", minimum_cost);
    return 0;
}
