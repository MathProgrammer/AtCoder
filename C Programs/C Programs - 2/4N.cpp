#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    const int MAX = 3500;

    for(int i = 1; i <= MAX; i++)
    {
        for(int j = i + 1; j <= MAX; j++)
        {
            long long numerator = n*1LL*i*j;
            long long denominator = 4LL*i*j - (i + j)*1LL*n;

            if(denominator > 0 && numerator%denominator == 0)
            {
                long long k = numerator/denominator;

                printf("%d %d %lld\n", i, j, k);

                return 0;
            }
        }
    }
    return 0;
}
