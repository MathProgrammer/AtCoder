#include <iostream>

using namespace std;

int ceil(int numerator, int denominator)
{
    int quotient = numerator/denominator;
    int remainder = numerator%denominator;

    return (quotient + (remainder != 0));
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << (k <= ceil(n,2) ? "YES\n" : "NO\n");
    return 0;
}
