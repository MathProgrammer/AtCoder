#include <iostream>
#include <vector>

using namespace std;

void compute(vector <int> &A, int n)
{
    for(int i = 1; i < n; i++)
    {
        int current_i = i;

        for(int p = 2; p*p <= current_i; p++)
        {
            while(current_i%p == 0)
            {
                A[p]++;
                current_i /= p;
            }
        }

        if(current_i > 1)
            A[current_i]++;
    }
}

int main()
{
    int n;
    cin >> n;

    vector <int> exponent_sum(n + 1, 0);
    compute(exponent_sum, n + 1);

    const int LIMIT = 105;
    vector <int> no_of_primes_with_exponent(LIMIT, 0);
    for(int i = 0; i < n + 1; i++)
    {
        if(exponent_sum[i] == 0) continue;

        no_of_primes_with_exponent[exponent_sum[i]]++;
    }

    vector <int> primes_with_exponent_at_least(LIMIT, 0);
    primes_with_exponent_at_least[1] = no_of_primes_with_exponent[1];
    for(int i = LIMIT - 1; i >= 2; i--)
    {
        primes_with_exponent_at_least[i] = primes_with_exponent_at_least[i + 1] + no_of_primes_with_exponent[i];
    }

    int answer = primes_with_exponent_at_least[74];

    answer += primes_with_exponent_at_least[24]*(primes_with_exponent_at_least[2] - 1);
    answer += primes_with_exponent_at_least[14]*(primes_with_exponent_at_least[4] - 1);

    answer +=  (primes_with_exponent_at_least[4]*(primes_with_exponent_at_least[4] - 1)*(primes_with_exponent_at_least[2] - 2))/2;

    cout << answer;
    return 0;
}
