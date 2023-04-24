#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int segments = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int segments_starting_here = max(0, A[i] - A[i - 1]);
        segments += segments_starting_here;
    }

    cout << segments << "\n";
    return 0;
}
