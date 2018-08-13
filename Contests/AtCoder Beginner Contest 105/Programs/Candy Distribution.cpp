#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int no_of_elements, M;
    scanf("%d %d", &no_of_elements, &M);

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <long long> sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        sum[i] = sum[i - 1] + A[i];

    long long good_pairs = 0;
    map <long long, int> frequency_mod;

    for(int i = 0; i <= no_of_elements; i++)
    {
        good_pairs += frequency_mod[sum[i]%M];

        frequency_mod[sum[i]%M]++;
    }

    printf("%lld\n", good_pairs);
    return 0;
}
