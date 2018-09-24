#include <iostream>

#define max(a, b) (a > b ? a : b)
#define max_3(a, b, c) max(a, max(b, c))
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int answer = max_3(A*10 + B + C, A + B*10 + C, A + B + C*10);
    cout << answer << "\n";

    return 0;
}
