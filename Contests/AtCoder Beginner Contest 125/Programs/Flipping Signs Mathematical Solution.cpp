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

    const int oo = 1e9;
    int negative_count = 0, minimum_element = oo;
    long long sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum += abs(A[i]);

        negative_count += (A[i] < 0);

        minimum_element = min(minimum_element, abs(A[i]));
    }

    if(negative_count%2 == 1)
    {
        sum -= 2*minimum_element;
    }

    cout << sum;
    return 0;
}
