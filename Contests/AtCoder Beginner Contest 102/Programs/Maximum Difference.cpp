#include <cstdio>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int oo = 1e9;
    int minimum = oo, maximum = -oo;

    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);

        maximum = max(maximum, element);
        minimum = min(minimum, element);
    }

    int difference = maximum - minimum;
    printf("%d\n", difference);

    return 0;
}
