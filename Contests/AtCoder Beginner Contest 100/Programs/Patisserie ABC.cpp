#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long LL;
const int MAX_N = 1005, TYPES = 3;
LL A[MAX_N][3];

int is_bit_set(LL n, int position)
{
    return ( (n&(1LL << position) ) != 0);
}

int main()
{
    int no_of_elements, target;
    cin >> no_of_elements >> target;

    for(int i = 0; i < no_of_elements; i++)
    {
        for(int t = 0; t < TYPES; t++)
        {
            cin >> A[i][t];
        }
    }

    const int MAX_MASK = (1LL << TYPES);
    LL best_sum = 0;

    for(int mask = 0; mask < MAX_MASK; mask++)
    {
        vector <LL> current_sum(no_of_elements, 0);

        for(int i = 0; i < no_of_elements; i++)
        {
            for(int t = 0; t < TYPES; t++)
            {
                current_sum[i] += (is_bit_set(mask, t) ? A[i][t] : -A[i][t]);
            }
        }

        sort(all(current_sum));
        reverse(all(current_sum));

        LL sum_here = 0;
        for(int i = 0; i < target;i++)
        {
            sum_here += current_sum[i];
        }

        best_sum = max(best_sum, sum_here);
    }

    cout << best_sum;
    return 0;
}
