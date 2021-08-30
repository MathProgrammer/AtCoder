#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

long long sum(long long left, long long right)
{
    if(left == 0)
    {
        return (right*(right + 1))/2;
    }

    return sum(0, right) - sum(0, left - 1);
}

int main()
{
    long long no_of_elements, k;
    cin >> no_of_elements >> k;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    priority_queue <long long> Q;
    Q.push(0);
    map <int, long long> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        frequency[A[i]]++;

        if(frequency[A[i]] == 1)
        {
            Q.push(A[i]);
        }
    }

    long long score = 0;
    while(Q.top() > 0 && k > 0)
    {
        long long x = Q.top();
        Q.pop();

        long long next = Q.top();

        if(k >= frequency[x]*(x - next) )
        {
            score += frequency[x]*sum(next + 1, x);
            frequency[next] += frequency[x];

            k -= frequency[x]*(x - next);
        }
        else
        {
            long long quotient = k/frequency[x], remainder = k%frequency[x];

            score += frequency[x]*(sum(x - quotient + 1, x));
            score += remainder*(x - quotient);

            k = 0;
        }
    }

    cout << score << "\n";
    return 0;
}
