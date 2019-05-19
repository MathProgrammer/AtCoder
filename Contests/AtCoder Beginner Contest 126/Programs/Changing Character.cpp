#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length, k;
    string S;
    cin >> length >> k >> S;

    S[k - 1] += ('a' - 'A');

    cout << S;
    return 0;
}
