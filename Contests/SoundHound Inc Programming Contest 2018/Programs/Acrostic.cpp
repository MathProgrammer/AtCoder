#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    int step;
    cin >> S >> step;

    for(int i = 0; i < S.size(); i++)
        if(i%step == 0)
            cout << S[i];

    return 0;
}
