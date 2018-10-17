#include <cstdio>
#include <set>

using namespace std;

int all_digits_same(int n)
{
    set <int> digits;

    while(n)
    {
        digits.insert(n%10);

        n /= 10;
    }

    return (digits.size() == 1);
}

int main()
{
    int n;
    scanf("%d", &n);

    while(!all_digits_same(n))
        n++;

    printf("%d\n", n);
    return 0;
}
