#include <cstdio>
 
int main()
{
    int sum, no_of_A_coins;
    scanf("%d %d", &sum, &no_of_A_coins);
 
    printf(sum%500 <= no_of_A_coins ? "Yes\n" : "No\n");
    return 0;
}
