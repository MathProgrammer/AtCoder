#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements);
    vector <int> sorted_A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        scanf("%d", &A[i]);
        A[i] -= (i + 1);

        sorted_A[i] = A[i];
    }

    sort(all(sorted_A));

    int median_index = no_of_elements/2 + no_of_elements%2 - 1;
    int median = sorted_A[median_index];

    long long answer = 0;
    for(int i = 0; i < no_of_elements; i++)
        answer += abs(A[i] - median);

    printf("%lld\n", answer);

    return 0;
}
