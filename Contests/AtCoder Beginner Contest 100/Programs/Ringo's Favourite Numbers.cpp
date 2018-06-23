#include <cstdio>

int main()
{
    int n, power_of_100;
    scanf("%d %d", &power_of_100, &n);

    if(n == 100)
        n++;

    printf("%d", n);
    for(int zero = 1; zero <= 2*power_of_100; zero++) printf("0");

    return 0;
}
