#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int N;
    cin >> N;

    double numerator = (N/2 + N%2)*1.0, denominator = N*1.0;
    cout << setprecision(6) << numerator/denominator << endl;

    return 0;
}
