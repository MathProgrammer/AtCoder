#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_sides;
    cin >> no_of_sides;

    vector <int> length(no_of_sides);
    for(int i = 0; i < no_of_sides; i++)
        cin >> length[i];

    sort(all(length));

    int sum = 0;
    for(int i = 0; i < no_of_sides - 1; i++)
        sum += length[i];

    cout << (sum > length[no_of_sides - 1] ? "Yes" : "No");

    return 0;
}
