#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int no_of_elements, max_operations;
    cin >> no_of_elements >> max_operations;

    vector <int> A(no_of_elements + 2, 0);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    vector <int> sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        sum[i] += A[i];

    int max_sum = 0;
    for(int left = 0; left <= no_of_elements; left++)
    {
        for(int right = left; right <= no_of_elements; right++)
        {
            int removed_elements =  max(0, left - 1) + (no_of_elements - right);

            if(removed_elements > max_operations)
            {
                continue;
            }

            int sum_now = 0;
            priority_queue <int, vector <int>, greater <int> > Q;
            for(int i = 1; i < left; i++)
            {
                sum_now += A[i];
                Q.push(A[i]);
            }

            for(int i = right + 1; i <= no_of_elements; i++)
            {
                sum_now += A[i];
                Q.push(A[i]);
            }

            int remaining_operations = max_operations - removed_elements;

            while(remaining_operations > 0 && Q.size() > 0 && Q.top() < 0)
            {
                sum_now -= Q.top();
                Q.pop();

                remaining_operations--;
            }

            max_sum = max(max_sum, sum_now);
        }
    }

    cout << max_sum;
    return 0;
}
