#include <iostream>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
#define min_3(a, b, c) min(a, min(b, c))
#define max_3(a, b, c) max(a, max(b, c))

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    int cost = max_3(A, B, C) - min_3(A, B, C);
    cout << cost;

    return 0;
}
