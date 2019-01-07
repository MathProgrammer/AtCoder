#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_moves, no_of_stones;
    cin >> no_of_moves >> no_of_stones;

    vector <int> move(no_of_moves + 1);
    for(int i = 1; i <= no_of_moves; i++)
        cin >> move[i];

    vector <int> winner(no_of_stones + 1, 2);
    for(int i = 1; i <= no_of_stones; i++)
    {
        for(int j = 1; j <= no_of_moves; j++)
        {
            if(move[j] > i) continue;

            if(winner[i - move[j]] == 2)
                winner[i] = 1;
        }
    }

    cout << (winner[no_of_stones] == 1 ? "First\n" : "Second\n");
    return 0;
}
