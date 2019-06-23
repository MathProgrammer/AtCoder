#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, L;
    cin >> N >> L;

    int sum = N*L + N*(N + 1)/2 - N;
    int smallest = 0;

    if(L > 0)
    {
        smallest = L;
    }
    else
    {
        if(N - 1 >= abs(L))
            smallest = 0;
        else
            smallest = L + (N - 1);
    }

    sum -= smallest;

    cout << sum;
    return 0;
}
