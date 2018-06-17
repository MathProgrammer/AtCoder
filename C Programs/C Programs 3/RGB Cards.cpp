#include <cstdio>

int main()
{
    int red, green, blue;
    scanf("%d %d %d", &red, &green, &blue);
    printf((100*red + 10*green + blue)%4 == 0 ? "YES\n" : "NO\n");
    return 0;
}
