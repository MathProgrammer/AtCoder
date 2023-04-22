#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> value(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> value[i];
    }

    vector <int> cost(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> cost[i];
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        value[i] -= cost[i];
    }

    int answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(value[i] > 0)
        {
            answer += value[i];
        }
    }

    cout << answer << "\n";
    return 0;
}
