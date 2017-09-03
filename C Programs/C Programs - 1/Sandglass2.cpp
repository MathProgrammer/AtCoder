#include <cstdio>

#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_grains, time;
    scanf("%d %d", &no_of_grains, &time);

    int no_of_grains_left = max(no_of_grains - time, 0);
    printf("%d\n", no_of_grains_left);
    return 0;
}
