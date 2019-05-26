#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

long long b_sum = 0, median = 0, a_sum_below_median = 0, a_sum_above_median = 0;
priority_queue <int> below_median;
priority_queue <int, vector <int>, greater <int> > above_median;

void answer()
{
    int query_type;
    cin >> query_type;

    const int INSERT = 1, GET_MINIMUM = 2;
    if(query_type == INSERT)
    {
        int a, b;
        cin >> a >> b;

        b_sum += b;

        if(below_median.empty() || a < below_median.top())
        {
            below_median.push(a);
            a_sum_below_median += a;
        }
        else
        {
            above_median.push(a);
            a_sum_above_median += a;
        }

        while(below_median.size() > above_median.size() + 1)
        {
            int x = below_median.top();
            below_median.pop();
            above_median.push(x);

            a_sum_below_median -= x;
            a_sum_above_median += x;
        }

        while(above_median.size() > below_median.size())
        {
            int x = above_median.top();
            above_median.pop();
            below_median.push(x);

            a_sum_above_median -= x;
            a_sum_below_median += x;
        }
    }
    else if(query_type == GET_MINIMUM)
    {
        long long median = below_median.top();
        long long elements_below_median = below_median.size(), elements_above_median = above_median.size();

        long long minimum_value = (median*elements_below_median - a_sum_below_median) + (a_sum_above_median - median*elements_above_median) + b_sum;

        cout << median << " " << minimum_value << endl;
    }
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        answer();

    return 0;
}
