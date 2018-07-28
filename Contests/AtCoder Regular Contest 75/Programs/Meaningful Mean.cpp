#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (2*n + 1)
#define RIGHT(n) (2*n + 2)

using namespace std;

typedef long long LL;
const int MAX_N = 2e5 + 5;
int sum[3*MAX_N];

struct info
{
    LL value;
    int index;

    info(LL V, int I)
    {
        value = V, index = I;
    }

    int operator<(const info &A)
    {
        return (value == A.value ? index < A.index : value < A.value);
    }
};

void update(int n, int left, int right, int position, int value)
{
    if(right < position || position < left)
        return;

    if(left == right)
    {
        sum[n] = value;
        return;
    }

    int mid = (left + right) >> 1;

    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);

    sum[n] = sum[RIGHT(n)] + sum[LEFT(n)];
}

int get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(right < query_left || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
        return sum[n];

    int mid = (left + right) >> 1;
    int left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    int right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

int main()
{
    int no_of_elements, k;
    scanf("%d %d", &no_of_elements, &k);

    LL array_sum = 0;
    vector <info> A(no_of_elements + 1, info(0, 0));
    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        scanf("%d", &element);

        array_sum += element;
        A[i] = info(array_sum - i*1LL*k, i);
    }

    sort(all(A));

    memset(sum, 0, sizeof(sum));

    LL answer_pairs = 0;

    for(int i = 0; i <= no_of_elements; i++)
    {
        answer_pairs += get_sum(0, 0, no_of_elements, 0, A[i].index);

        update(0, 0, no_of_elements, A[i].index, 1);
    }

    printf("%lld\n", answer_pairs);
    return 0;
}
