#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int possible = false;

    if(n >= 18)
    {
        possible = true;
    }
    else
    {
        for(int i = 0; 4*i <= n; i++)
        {
            if( (n - 4*i)%7 == 0)
            {
                possible = true;
                break;
            }
        }
    }

    printf(possible ? "Yes\n" : "No\n");

    return 0;
}
