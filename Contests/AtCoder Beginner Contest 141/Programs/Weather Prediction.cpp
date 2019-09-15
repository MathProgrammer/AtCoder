#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    switch(S[0])
    {
        case 'S' : cout << "Cloudy\n"; break;
        case 'C' : cout << "Rainy\n";  break;
        case 'R' : cout << "Sunny\n";  break;
    }

    return 0;
}
