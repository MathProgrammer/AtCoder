#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int no_of_choices = n - (k - 1);
    cout << no_of_choices;

    return 0;
}
