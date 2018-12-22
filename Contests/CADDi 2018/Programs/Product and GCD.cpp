#include <iostream>
#include <map>

using namespace std;

long long power(long long base, long long p)
{
    long long answer = 1;

    while(p)
    {
        if(p%2)
            answer = answer*base;

        base = base*base;
        p = p >> 1;
    }

    return answer;
}

int main()
{
    long long no_of_numbers, product;
    cin >> no_of_numbers >> product;

    map <long long, int> exponent;
    for(long long i = 2; i*i <= product; i++)
    {
        while(product%i == 0)
        {
            exponent[i]++;
            product /= i;
        }
    }

    if(product > 1)
        exponent[product]++;

    long long gcd = 1;
    for(map <long long, int> :: iterator it = exponent.begin(); it != exponent.end(); it++)
    {
        int this_exponent = it->second;

        gcd *= power(it->first, this_exponent/no_of_numbers);
    }

    cout << gcd;
    return 0;
}
