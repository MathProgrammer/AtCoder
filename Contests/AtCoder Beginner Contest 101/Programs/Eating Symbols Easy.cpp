#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    int answer = 0;
    for(int i = 0; i < S.size(); i++)
        answer += (S[i] == '+' ? 1 : -1);

    cout << answer;
    return 0;
}
