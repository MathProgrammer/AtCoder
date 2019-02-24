#include <iostream>

using namespace std;

int to_int(char ch)
{
    return (ch - '0');
}

int main()
{
    string date;
    cin >> date;

    int month = to_int(date[5])*10 + to_int(date[6]);
    cout << (month <= 4 ? "Heisei\n" : "TBD");

    return 0;
}
