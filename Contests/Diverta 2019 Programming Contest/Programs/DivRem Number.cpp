#include <iostream>

using namespace std;

typedef long long LL;

int are_remainder_and_quotient_equal(LL n, LL m)
{
    return (m > 0 && n/m == n%m);
}

int main()
{
    LL n;
    cin >> n;

    LL special_number_sum = 0;

    for(LL i = 1; i*i <= n; i++)
    {
        LL factor_1 = i, factor_2 = n/i;

        if(are_remainder_and_quotient_equal(n, factor_1 - 1))
        {
            special_number_sum += factor_1 - 1;
        }

        if(factor_1 == factor_2)
        {
            continue;
        }

        if(are_remainder_and_quotient_equal(n, factor_2 - 1))
        {
            special_number_sum += factor_2 - 1;
        }
    }

    cout << special_number_sum;
    return 0;
}
