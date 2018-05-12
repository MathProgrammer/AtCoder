#include <iostream>

#define abs(x) ( (x) > 0 ? (x) : -(x) )
using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << ( (abs(B - A) <= D && abs(C - B) <= D) || abs(C - A) <= D ? "Yes\n" : "No\n");
    return 0;
}

