#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct info
{
    int type, value;

    info(){}

    info(int T, int V)
    {
        type = T, value = V;
    }

    const int operator<(info &A)
    {
        return (value < A.value);
    }
};

int main()
{
    int no_of_elements, no_of_choices;
    cin >> no_of_elements >> no_of_choices;

    vector <info> A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        cin >> A[i].type >> A[i].value;

    sort(all(A));
    reverse(all(A));

    vector <int> used(no_of_elements + 1, false);
    priority_queue <long long,vector<long long>, greater<long long> >Q;

    long long sum = 0, distinct_types = 0;
    for(int i = 0; i < no_of_choices; i++)
    {
        sum += A[i].value;

        if(!used[A[i].type])
        {
            used[A[i].type] = true;
            distinct_types++;
        }
        else
        {
            Q.push(A[i].value);
        }
    }
    sum += distinct_types*distinct_types;

    long long new_sum = sum;

    for(int i = no_of_choices; i < no_of_elements; i++)
    {
        if(used[A[i].type] || Q.size() == 0) continue;

        long long smallest = Q.top();

        new_sum += (A[i].value - smallest) + (distinct_types + 1)*(distinct_types + 1) - (distinct_types*distinct_types);

        Q.pop();

        distinct_types++;

        used[A[i].type] = true;


        sum = max(sum, new_sum);
    }

    cout << sum;
    return 0;
}
