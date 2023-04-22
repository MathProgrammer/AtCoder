#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int age, cost;
    cin >> age >> cost;

    if(age <= 5)
    {
        cost = 0;
    }
    else if(age <= 12)
    {
        cost /= 2;
    }

    cout << cost << "\n";
    return 0;
}
