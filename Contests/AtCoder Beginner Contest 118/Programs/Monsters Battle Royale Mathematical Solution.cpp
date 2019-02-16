#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
 	return (min(a, b) == 0 ? max(a, b) : gcd(max(a, b)%min(a,b), min(a, b)));
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    int array_gcd;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int health;
        cin >> health;
        array_gcd = (i == 1 ? health : gcd(array_gcd, health));
    }

    cout << array_gcd;
    return 0;
}

