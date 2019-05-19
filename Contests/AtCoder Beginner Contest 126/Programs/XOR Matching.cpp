#include <iostream>

using namespace std;

int main()
{
    int n, target_xor;
    cin >> n >> target_xor;

    if(target_xor == 0 && n == 0)
    {
        cout << "0 0";

        return 0;
    }

    if(target_xor == 0 && n == 1)
    {
        cout << " 0 0 1 1";

        return 0;
    }

    if(n <= 1 || target_xor >= (1 << n))
    {
        cout << "-1";

        return 0;
    }

    for(int i = 0; i < (1 << n); i++)
        if(i != target_xor)
            cout << i << " ";

    cout << target_xor << " ";

    for(int i = (1 << n) - 1; i >= 0; i--)
        if(i != target_xor)
            cout << i << " ";

    cout << target_xor << " ";

    return 0;
}
