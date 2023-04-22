#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int NO_OF_YEARS = 10;
    int r, D;
    vector <int> X(NO_OF_YEARS);
    cin >> r >> D >> X[0];

    for(int i = 1; i <= NO_OF_YEARS; i++)
    {
        X[i] = r*X[i - 1] - D;
    }

    for(int i = 1; i <= NO_OF_YEARS; i++)
    {
        cout << X[i] << "\n";
    }
    return 0;
}
