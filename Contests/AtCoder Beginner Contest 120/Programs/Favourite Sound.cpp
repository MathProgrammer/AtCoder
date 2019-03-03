#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int answer = min(B/A, C);
    cout << answer;

    return 0;
}
