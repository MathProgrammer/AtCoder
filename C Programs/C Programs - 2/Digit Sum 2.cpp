#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    long long n;
    scanf("%lld\n", &n);

    vector <int> digits;
    while(n > 0)
    {
        digits.push_back(n%10);
        n /= 10;
    }

    reverse(all(digits));

    vector <int> sum_till(digits.size() + 1, 0);
    for(int i = 0; i < digits.size(); i++)
        sum_till[i] = (i == 0 ? digits[i] : digits[i] + sum_till[i - 1]);

    int answer = 0;

    for(int i = 0; i < digits.size(); i++)
    {
        int sum_till_here = (i == digits.size() - 1 ? sum_till[i] : sum_till[i] - 1);
        int sum_from_here = 9*(digits.size() - 1 - i);

        int answer_if_common_prefix_ended_here = sum_till_here + sum_from_here;

        answer = max(answer, answer_if_common_prefix_ended_here);
    }

    printf("%d\n", answer);
    return 0;
}
