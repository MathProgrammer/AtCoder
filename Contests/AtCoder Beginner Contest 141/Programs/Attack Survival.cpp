#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int no_of_players, no_of_points, no_of_answers;
    cin >> no_of_players >> no_of_points >> no_of_answers;

    vector <int> points(no_of_players + 1, no_of_points - no_of_answers);
    for(int i = 1; i <= no_of_answers; i++)
    {
        int player;
        cin >> player;

        points[player]++;
    }

    for(int i = 1; i <= no_of_players; i++)
    {
        cout << (points[i] > 0 ? "Yes\n" : "No\n");
    }

    return 0;
}
