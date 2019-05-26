#include <iostream>

using namespace std;

int main()
{
    int no_of_apples, no_of_pieces;
    cin >> no_of_apples >> no_of_pieces;

    const int PIECES_FROM_ONE_APPLE = 3, PIECES_IN_ONE_PIE = 2;

    no_of_pieces += no_of_apples*PIECES_FROM_ONE_APPLE;

    int no_of_pies = no_of_pieces/PIECES_IN_ONE_PIE;

    cout << no_of_pies;
    return 0;
}
