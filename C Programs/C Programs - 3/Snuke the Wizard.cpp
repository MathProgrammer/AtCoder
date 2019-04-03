#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct moves
{
    char ch, direction;

    moves(){}

    moves(char C, char D)
    {
        ch = C, direction = D;
    }
};

int displacement(string &S, int position, vector <moves> &M)
{
    for(int i = 1; i < M.size(); i++)
    {
        if(S[position] == M[i].ch)
        {
            position += (M[i].direction == 'L' ? -1 : 1);
        }

        if(position == 0 || position == S.size() - 1)
        {
            break;
        }
    }

    return position;
}

int main()
{
    int length, no_of_moves;
    string S;
    cin >> length >> no_of_moves >> S;

    S = '*' + S + '*';

    vector <moves> M(no_of_moves + 1);
    for(int i = 1; i <= no_of_moves; i++)
    {
        cin >> M[i].ch >> M[i].direction;
    }

    int left = 0, right = length + 1;
    while(right - left > 1)
    {
        int mid = (left + right)/2;

        if(displacement(S, mid, M) == 0)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    int rightmost_to_fall_left = left;

    left = 0, right = length + 1;
    while(right - left > 1)
    {
        int mid = (left + right)/2;

        if(displacement(S, mid, M) == length + 1)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    int leftmost_to_fall_right = right;

    int remaining = (leftmost_to_fall_right - 1) - rightmost_to_fall_left;
    cout << remaining;

    return 0;
}
