#include <iostream>
#define max(a, b) (a > b ? a : b)
#define max_3(a, b, c) max( a, max(b, c) )

using namespace std;

int main()
{
    int K, A, B, C;
    cin >> A >> B >> C >> K;

    long long answer = max_3( (1 << K)*A + B + C, A + (1 << K)*B + C, A + B + (1 << K)*C );
    cout << answer;

    return 0;
}
