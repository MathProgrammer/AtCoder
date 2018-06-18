#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    string S, T;
    cin >> S >> T;

    int match_location = -1;

    for(int i = 0; i + T.size() - 1 < S.size(); i++)
    {
        int match_made = true;
        for(int j = 0; j < T.size(); j++)
        {
            if(S[i + j] != T[j] && S[i + j] != '?')
            {
                match_made = false;
            }
        }

        if(match_made)
            match_location = i;
    }

    for(int i = 0; i < S.size(); i++)
        if(S[i] == '?')
            S[i] = 'a';

    for(int i = 0; i < T.size(); i++)
        S[match_location + i] = T[i];

    if(match_location == -1)
        cout << "UNRESTORABLE\n";
    else
        cout << S;
    return 0;
}

