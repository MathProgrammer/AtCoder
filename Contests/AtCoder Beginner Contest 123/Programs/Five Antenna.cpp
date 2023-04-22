#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int NO_OF_ANTENNA = 5;
    vector <int> A(NO_OF_ANTENNA + 1);
    int max_distance;
    for(int i = 1; i <= NO_OF_ANTENNA; i++)
    {
        cin >> A[i];
    }
    cin >> max_distance;

    int possible = (A[NO_OF_ANTENNA] - A[1] <= max_distance ? true : false);
    cout << (possible ? "Yay!" : ":(") << "\n";

    return 0;
}
