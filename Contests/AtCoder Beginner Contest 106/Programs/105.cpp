#include <cstdio>

int divisor_count(int n)
{
    int count = 0;

    for(int i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            count += (i*i == n ? 1 : 2);
        }
    }

    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    int answer = 0;
    for(int i = 1; i <= n; i += 2)
    {
        if(divisor_count(i) == 8)
            answer++;
    }

    printf("%d\n", answer);
    return 0;
}
