#include <cstdio>

const int MOD = 1e9 + 7, MAX_N = 2e5 + 5;
typedef long long LL;

LL factorial[MAX_N + 1];
LL inverse_factorial[MAX_N + 1];

LL power_mod(LL x, LL power, LL MOD)
{
    LL answer = 1;

    while(power)
    {
        if(power%2 == 1)
            answer = (answer*x)%MOD;

        x = (x*x)%MOD;
        power = power >> 1;
    }

    return answer;
}

LL choose(LL n, LL r, LL MOD)
{
    LL numerator = factorial[n];
    LL denominator_inverse = (inverse_factorial[r]*inverse_factorial[n - r])%MOD;

    return (numerator*denominator_inverse)%MOD;
}

int main()
{
    const int MOD = 1e9 + 7;

    factorial[0] = 1;
    for(int i = 1; i <= MAX_N; i++)
        factorial[i] = (i*factorial[i - 1])%MOD;

    inverse_factorial[MAX_N] = power_mod(factorial[MAX_N], MOD - 2, MOD);
    for(int i = MAX_N - 1; i >= 0; i--)
        inverse_factorial[i] = ( (i + 1)*inverse_factorial[i + 1] )%MOD;

    int no_of_factors, n;
    scanf("%d %d", &no_of_factors, &n);

    LL answer = 1;
    for(int i = 2; i*i <= n; i++)
    {
        int exponent = 0;

        while(n%i == 0)
        {
            n = n/i;
            exponent++;
        }

        LL no_of_ways_of_placing_this_prime = choose(exponent + no_of_factors - 1, exponent, MOD);
        answer = (answer*no_of_ways_of_placing_this_prime)%MOD;
    }

    if(n > 1)
    {
        int exponent = 1;

        LL no_of_ways_of_placing_this_prime = choose(exponent + no_of_factors - 1, exponent, MOD);
        answer = (answer*no_of_ways_of_placing_this_prime)%MOD;
    }

    printf("%lld\n", answer);
    return 0;
}
