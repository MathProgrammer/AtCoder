#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

struct query_info
{
    int left, right, query_no;

    query_info(int L, int R, int N)
    {
        left = L, right = R, query_no = N;
    }

    int operator<(const query_info &A)
    {
        return (right < A.right);
    }
};

struct train_info
{
    int left, right;

    train_info(int L, int R)
    {
        left = L, right = R;
    }

    int operator<(const train_info &A)
    {
        return (right < A.right);
    }
};

const int MAX_N = 515;
int sum_tree[4*MAX_N];

void update(int n, int left, int right, int position, int value)
{
    if(position < left || right < position)
        return;

    if(left == right)
    {
        sum_tree[n] += value;
        return;
    }

    int mid = (left + right) >> 1;

    update(LEFT(n), left, mid, position, value);
    update(RIGHT(n), mid + 1, right, position, value);

    sum_tree[n] = sum_tree[LEFT(n)] + sum_tree[RIGHT(n)];
}

int get_sum(int n, int left, int right, int query_left, int query_right)
{
    if(right < query_left || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
    {
        return sum_tree[n];
    }

    int mid = (left + right) >> 1;
    int left_sum = get_sum(LEFT(n), left, mid, query_left, query_right);
    int right_sum = get_sum(RIGHT(n), mid + 1, right, query_left, query_right);

    return (left_sum + right_sum);
}

int main()
{
    int no_of_cities, no_of_trains, no_of_queries;
    scanf("%d %d %d", &no_of_cities, &no_of_trains, &no_of_queries);

    vector <train_info> train(no_of_trains + 1, train_info(0, 0));
    for(int i = 1; i <= no_of_trains; i++)
        scanf("%d %d", &train[i].left, &train[i].right);

    sort(all(train));

    vector <query_info> query(no_of_queries + 1, query_info(0, 0, 0));
    for(int i = 1; i <= no_of_queries; i++)
    {
        scanf("%d %d", &query[i].left, &query[i].right);

        query[i].query_no = i;
    }

    sort(all(query));

    memset(sum_tree, 0, sizeof(sum_tree));
    vector <int> answer(no_of_queries + 1);

    int last_train = 1;
    for(int i = 1; i <= no_of_queries; i++)
    {
        while(last_train <= no_of_trains && train[last_train].right <= query[i].right)
        {
            update(1, 1, no_of_cities, train[last_train].left, 1);

            last_train++;
        }

        answer[query[i].query_no] = get_sum(1, 1, no_of_cities, query[i].left, query[i].right);
    }

    for(int i = 1; i <= no_of_queries; i++)
        printf("%d\n", answer[i]);

    return 0;
}
