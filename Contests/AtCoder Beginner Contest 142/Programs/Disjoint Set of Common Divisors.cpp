#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;

    long long gcd = __gcd(A, B);

    int no_of_prime_diviors = 0;
    for(long long i = 2; i*i <= gcd; i++)
    {
        if(gcd%i == 0)
        {
            no_of_prime_diviors++;

            while(gcd%i == 0)
            {
                gcd /= i;
            }
        }
    }

    if(gcd > 1)
        no_of_prime_diviors++;

    int coprime_divisors = 1 + no_of_prime_diviors;

    cout << coprime_divisors << "\n";

    return 0;
}
