#include <cstdio>

int main()
{
    int no_of_levels, source, destination;
    scanf("%d %d %d", &no_of_levels, &source, &destination);

    int no_of_branches = 0;
    while(destination > source)
    {
        destination = destination >> 1;
        no_of_branches++;
    }

    printf("%d\n", destination == source ? no_of_branches : -1);
    return 0;
}
