#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string S;
    int k;
    cin >> S >> k;

    set <string> substrings;

    for(int length = 1; length <= 5; length++)
    {
        for(int i = 0; i + length - 1 < S.size(); i++)
        {
            substrings.insert(S.substr(i, length));
        }
    }

    int i = 1;
    for(set <string> :: iterator it = substrings.begin(); it != substrings.end() && i <= k; it++, i++)
    {
        if(i == k)
        {
            cout << *it;
        }
    }

    return 0;
}
