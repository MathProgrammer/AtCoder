#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int oo = 1e9 + 9;
    int sum = 0, min_non_multiple_10 = oo;

    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);

        sum += element;

        if(element%10 != 0)
            min_non_multiple_10 = min(min_non_multiple_10, element);
    }

    if(sum%10 == 0)
        printf("%d\n", min_non_multiple_10 == oo ? 0 : sum - min_non_multiple_10);
    else
        printf("%d\n", sum);

    return 0;
}
