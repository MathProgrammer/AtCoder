#include <iostream>

#define max_3(a, b, c) max(a, max(b, c))
using namespace std;

int main()
{
    int p, q, r;
    cin >> p >> q >> r;

    int maximum = max_3(p, q, r);
    int sum = p + q + r;

    cout << (sum - maximum);
    return 0;
}
