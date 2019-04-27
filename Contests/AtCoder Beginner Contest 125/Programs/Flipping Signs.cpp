#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5, NO_OF_ENDINGS = 2, WITH_MULTIPLIER = 0, WITHOUT_MULTIPLIER = 1;
long long sum_till[MAX_N][NO_OF_ENDINGS];

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    sum_till[1][WITHOUT_MULTIPLIER] = A[1], sum_till[1][WITH_MULTIPLIER] = A[1];
    sum_till[2][WITH_MULTIPLIER] = -A[1] - A[2], sum_till[2][WITHOUT_MULTIPLIER] = A[1] + A[2];
    for(int i = 3; i <= no_of_elements; i++)
    {
        long long max_without_last_2 = max(sum_till[i - 2][WITHOUT_MULTIPLIER], sum_till[i - 2][WITH_MULTIPLIER]);

        sum_till[i][WITHOUT_MULTIPLIER] = A[i] + max(A[i - 1] + max_without_last_2, sum_till[i - 1][WITH_MULTIPLIER]);

        sum_till[i][WITH_MULTIPLIER] = -A[i] + max(-A[i - 1] + max_without_last_2, sum_till[i - 1][WITH_MULTIPLIER] + 2*A[i - 1]);
    }

    long long answer = max(sum_till[no_of_elements][WITH_MULTIPLIER], sum_till[no_of_elements][WITHOUT_MULTIPLIER]);
    cout << answer;

    return 0;
}

