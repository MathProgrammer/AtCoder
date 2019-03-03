#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A, B, K;
    cin >> A >> B >> K;

    int G = __gcd(A, B);

    int divisor_count = 0, k_th_divisor;
    for(int i = G; i >= 1 && divisor_count < K; i--)
    {
        if(G%i == 0)
        {
            divisor_count++;

            if(divisor_count == K)
                k_th_divisor = i;
        }
    }

    cout << k_th_divisor;
    return 0;
}
