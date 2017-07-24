#include <cstdio>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
    int no_of_numbers, desired_number;
    scanf("%d %d", &no_of_numbers, &desired_number);

    int array_gcd, largest_number = 0;
    for(int i = 1; i <= no_of_numbers; i++)
    {
        int number_i;
        scanf("%d", &number_i);

        array_gcd = (i == 1 ? number_i : gcd(array_gcd, number_i));
        largest_number = max(number_i, largest_number);
    }

    printf(desired_number%array_gcd == 0 && desired_number <= largest_number ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    return 0;
}
