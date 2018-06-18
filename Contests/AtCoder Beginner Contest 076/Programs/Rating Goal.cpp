#include <iostream>

using namespace std;

int main()
{
    int rating, target;
    cin >> rating >> target;

    int performance = 2*target - rating;
    cout << performance;

    return 0;
}
