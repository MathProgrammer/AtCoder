#include <iostream>

using namespace std;

int main()
{
    long long start, end;
    cin >> start >> end;

    int no_of_terms = 1;
    long long a = start;

    while(2*a <= end)
    {
        a = a << 1;
        no_of_terms++;
    }

    cout << no_of_terms;
    return 0;
}
