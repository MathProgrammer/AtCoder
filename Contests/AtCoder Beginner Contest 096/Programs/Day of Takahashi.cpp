#include <iostream>

using namespace std;

int main()
{
    int month, day;
    cin >> month >> day;

    int answer = month - (day < month);
    cout << answer;

    return 0;
}
