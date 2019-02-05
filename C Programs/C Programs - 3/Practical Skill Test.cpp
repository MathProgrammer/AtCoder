#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int height, width, d;
    cin >> height >> width >> d;

    vector <int> X(height*width + 1);
    vector <int> Y(height*width + 1);

    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            int value;
            cin >> value;

            X[value] = i;
            Y[value] = j;
        }
    }

    vector <int> cost(height*width + 1, 0);
    for(int i = d + 1; i <= height*width; i++)
    {
        cost[i] = cost[i - d] + abs(X[i - d] - X[i]) + abs(Y[i - d] - Y[i]);
    }

    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
    {
        int left, right;
        cin >> left >> right;
        cout << (cost[right] - cost[left]) << "\n";
    }

    return 0;
}
