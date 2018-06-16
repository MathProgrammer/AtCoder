#include <cstdio>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
    int no_of_houses;
    scanf("%d", &no_of_houses);

    int min_house = 1000, max_house = 0;
    while(no_of_houses--)
    {
        int distance;
        scanf("%d", &distance);

        min_house = min(min_house, distance);
        max_house = max(max_house, distance);
    }

    printf("%d\n", max_house - min_house);
    return 0;
}
