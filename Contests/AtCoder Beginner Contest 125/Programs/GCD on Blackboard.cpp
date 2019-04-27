#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    vector <int> prefix_gcd(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        prefix_gcd[i] = __gcd(prefix_gcd[i - 1], A[i]);

    vector <int> suffix_gcd(no_of_elements + 2, 0);
    for(int i = no_of_elements; i >= 1; i--)
        suffix_gcd[i] = __gcd(suffix_gcd[i + 1], A[i]);

    int best_gcd = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int gcd_without_this = __gcd(prefix_gcd[i - 1], suffix_gcd[i + 1]);

        best_gcd = max(best_gcd, gcd_without_this);
    }

    cout << best_gcd;

    return 0;
}

