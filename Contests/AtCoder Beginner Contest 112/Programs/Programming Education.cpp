#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    if(n == 1)
    {
        printf("Hello World\n");
    }
    else if(n == 2)
    {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }

    return 0;
}
