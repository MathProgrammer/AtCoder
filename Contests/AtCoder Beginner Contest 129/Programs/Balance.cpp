#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    vector <int> sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        sum_till[i] = sum_till[i - 1] + A[i];

    int minimum_difference = sum_till[no_of_elements];
    for(int i = 1; i <= no_of_elements; i++)
    {
        minimum_difference = min(minimum_difference, abs(sum_till[no_of_elements] - 2*sum_till[i]));
    }

    cout << minimum_difference;
    return 0;
}
