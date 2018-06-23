#include <cstdio>

int digit_sum(int n)
{
    int sum = 0;

    while(n)
    {
        sum += n%10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%s\n", n%digit_sum(n) == 0 ? "Yes" : "No");;
    return 0;
}
