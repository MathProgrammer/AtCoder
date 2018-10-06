#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{
    int no_of_paths, max_time;
    scanf("%d %d", &no_of_paths, &max_time);

    const int oo = 1e9 + 9;
    int min_cost = oo;

    while(no_of_paths--)
    {
        int cost, time;
        scanf("%d %d", &cost, &time);

        if(time <= max_time) min_cost = min(min_cost, cost);
    }

    printf(min_cost == oo ? "TLE\n" : "%d\n", min_cost);
    return 0;
}
