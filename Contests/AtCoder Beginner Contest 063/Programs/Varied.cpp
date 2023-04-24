#include <iostream>
#include <set>

using namespace std;

int main()
{
    string S;
    cin >> S;

    set <char> distinct;
    for(int i = 0; i < S.size(); i++)
    {
        distinct.insert(S[i]);
    }

    cout << (distinct.size() == S.size() ? "yes" : "no") << "\n";
    return 0;
}
