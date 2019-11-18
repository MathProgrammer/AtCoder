Let #include <iostream>

using namespace std;

long long power_mod(long long x, long long power, long long mod)
{
    long long result = 1;

    while(power)
    {
        if(power%2)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long x, long long mod)
{
    return power_mod(x, mod - 2, mod);
}

long long combinations(long long n, long long r, long long mod)
{
    long long numerator = 1, denominator = 1;

    for(int i = 0; i <= (r - 1); i++)
    {
        numerator = (numerator*(n - i))%mod;
        denominator = (denominator*(r - i))%mod;
    }

    long long answer = (numerator*inverse(denominator, mod))%mod;

    return answer;
}

int main()
{
    int X, Y;
    cin >> X >> Y;

    if( (X + Y)%3 != 0)
    {
        cout << "0\n";

        return 0;
    }

    long long D = (2*Y - X)/3;
    long long L = (2*X - Y)/3;

    const int MOD = 1e9 + 7;
    cout << ( (D < 0 || L < 0) ? 0 : combinations(D + L, D, MOD) );

    return 0;
}
