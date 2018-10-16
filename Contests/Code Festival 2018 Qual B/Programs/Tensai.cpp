#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_pairs, increase;
    scanf("%d %d", &no_of_pairs, &increase);

    int product_sum = 0;
    int maximum_b = 0;
    while(no_of_pairs--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        maximum_b = max(maximum_b, b);
        product_sum += a*b;
    }

    product_sum += increase*maximum_b;
    printf("%d\n", product_sum);

    return 0;
}
