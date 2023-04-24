#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    int sum = A + B;
    if(sum < 10)
    {
        cout << sum << "\n";
    }
    else
    {
        cout << "error\n";
    }
    return 0;
}
