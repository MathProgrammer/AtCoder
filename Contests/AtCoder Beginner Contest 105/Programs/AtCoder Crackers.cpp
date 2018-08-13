#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int answer = (n%k == 0 ? 0 : 1);
    printf("%d\n", answer);

    return 0;
}
