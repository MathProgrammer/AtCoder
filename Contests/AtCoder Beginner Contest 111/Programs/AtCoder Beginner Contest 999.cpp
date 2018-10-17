#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    for(int i = 0; i < S.size(); i++)
            S[i] = '9' - S[i] + '1';

    cout << S;

    return 0;
}
