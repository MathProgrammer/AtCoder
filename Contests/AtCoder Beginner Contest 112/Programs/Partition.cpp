#include <cstdio>

#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_elements, sum;
    scanf("%d %d", &no_of_elements, &sum);

    int max_gcd = 1;

    for(int i = 1; i*i <= sum; i++)
    {
        if(sum%i == 0)
        {
            long long factor_1 = i, factor_2 = sum/i;

            if(factor_1*no_of_elements <= sum) max_gcd = max(max_gcd, factor_1);

            if(factor_2*no_of_elements <= sum) max_gcd = max(max_gcd, factor_2);
        }
    }

    printf("%d\n", max_gcd);
    return 0;
}
