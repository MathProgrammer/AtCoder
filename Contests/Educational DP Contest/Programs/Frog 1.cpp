#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_stones;
    cin >> no_of_stones;

    vector <int> height(no_of_stones + 1, 0);
    for(int i = 1; i <= no_of_stones; i++)
        cin >> height[i];

    vector <int> minimum_cost(no_of_stones + 1);
    minimum_cost[2] = abs(height[2] - height[1]);
    for(int i = 3; i <= no_of_stones; i++)
        minimum_cost[i] = min(minimum_cost[i - 1] + abs(height[i] - height[i - 1]),
                              minimum_cost[i - 2] + abs(height[i] - height[i - 2]));

    cout << minimum_cost[no_of_stones];
    return 0;
}
