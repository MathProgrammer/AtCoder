#include <iostream>
#include <string>

#define min(a, b) (a < b ? a : b)
using namespace std;

int main()
{
    string S;
    int day;

    cin >> S >> day;
    char answer;

    for(int i = 0; i < min(S.size(), day); i++)
    {
        if(i == day - 1 || S[i] != '1')
        {
            answer = S[i];
            break;
        }
    }

    cout << answer;
    return 0;
}
