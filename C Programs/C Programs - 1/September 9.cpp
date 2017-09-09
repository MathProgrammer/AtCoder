#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int nine_present = false;
    while(n > 0)
    {
        if(n%10 == 9)
            nine_present = true;
        n = n/10;
    }

    printf(nine_present ? "Yes\n" : "No\n");
    return 0;
}
