#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    int balance = 0;
    string beginning, ending;

    for(int i = 0; i < S.size(); i++)
    {
        balance += (S[i] == '(' ? 1 : -1);

        if(balance < 0) //Extra
        {
            beginning += '(';
            balance++;
        }
    }

    for(int i = 1; i <= balance; i++)
        ending += ')';

    string answer = beginning + S + ending;
    cout << answer;

    return 0;
}
