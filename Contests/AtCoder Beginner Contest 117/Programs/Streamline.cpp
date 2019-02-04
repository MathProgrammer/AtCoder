#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_pieces, no_of_points;
    cin >> no_of_pieces >> no_of_points;

    vector <int> A(no_of_points);
    for(int i = 0; i < no_of_points; i++)
        cin >> A[i];

    sort(all(A));

    vector <int> difference(no_of_points - 1);
    for(int i = 0; i < no_of_points - 1; i++)
        difference[i] = (A[i + 1] - A[i]);

    sort(all(difference));

    long long travel = 0;
    int no_of_travels = max(0, no_of_points - no_of_pieces);

    for(int i = 0; i < no_of_travels; i++)
        travel += difference[i];

    cout << travel << "\n";
    return 0;
}
