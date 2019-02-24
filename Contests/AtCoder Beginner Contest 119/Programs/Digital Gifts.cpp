#include <iostream>
#include <string>

using namespace std;

int main()
{
    int no_of_gits;
    cin >> no_of_gits;

    double total_sum = 0;
    while(no_of_gits--)
    {
        string currency;
        double value;
        cin >> value >> currency ;

        const long long CONVERSION_RATE = 380000;
        total_sum += (currency == "JPY" ? value : CONVERSION_RATE*value);
    }

    cout << total_sum;
    return 0;
}
