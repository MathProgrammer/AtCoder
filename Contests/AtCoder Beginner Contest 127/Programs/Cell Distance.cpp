#include <iostream>

using namespace std;

const int MOD = 1e9 + 7, MAX_N = 2e5 + 5;
long long factorial[MAX_N + 1], inverse_factorial[MAX_N + 1];

long long power_mod(long long x, long long power)
{
    long long result = 1;

    while(power > 0)
    {
        if(power%2)
            result = (result*x)%MOD;

        x = (x*x)%MOD;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long n)
{
    return power_mod(n, MOD - 2);
}

void precompute_factorial()
{
    factorial[0] = 1;
    for(int i = 1; i <= MAX_N; i++)
        factorial[i] = (i*factorial[i - 1])%MOD;

    inverse_factorial[MAX_N] = inverse(factorial[MAX_N]);
    for(int i = MAX_N - 1; i >= 0; i--)// i (i - 1)! = i! => (i!)^ = i^ (i - 1)^ => (i!)^ i = (i - 1)^
        inverse_factorial[i] = ((i + 1)*inverse_factorial[i + 1])%MOD;
}

long long combinations(long long n, long long r)
{
    long long numerator = factorial[n];
    long long inverse_denominator = (inverse_factorial[r]*inverse_factorial[n - r])%MOD;

    return (numerator*inverse_denominator)%MOD;
}

int main()
{
    precompute_factorial();

    long long rows, columns, k;
    cin >> rows >> columns >> k;

    long long no_of_times_each_pair_is_counted = combinations(rows*columns - 2, k - 2);

    long long x_contribution = 0;
    for(int i = 1; i <= rows; i++)
    {
        long long x = i;

        long long one_x_contribution = (columns*(i - 1)*x - columns*(rows - i)*x + MOD)%MOD;

        x_contribution += (columns*one_x_contribution)%MOD;
    }

    long long y_contribution = 0;
    for(int i = 1; i <= columns; i++)
    {
        long long y = i;

        long long one_y_contribution = (rows*(i - 1)*y - rows*(columns - i)*y + MOD)%MOD;

        y_contribution += (rows*one_y_contribution)%MOD;
    }

    long long sum_pair_distance = (x_contribution + y_contribution)%MOD;

    long long answer = (no_of_times_each_pair_is_counted*sum_pair_distance)%MOD;

    cout << answer;
    return 0;
}
