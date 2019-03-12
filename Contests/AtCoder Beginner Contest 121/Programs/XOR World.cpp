#include <iostream>

using namespace std;

typedef long long LL;

LL xor_till(LL n)
{
    LL left = (n/4)*4, right = n;

    LL answer = 0;

    for(LL i = left; i <= right; i++)
        answer ^= i;

    return answer;
}

int main()
{
    LL left, right;
    cin >> left >> right;

    LL xor_answer = xor_till(right)^xor_till(left - 1);

    cout << xor_answer;
    return 0;
}
