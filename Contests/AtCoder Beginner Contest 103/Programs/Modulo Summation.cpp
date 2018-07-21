#include <cstdio>
 
int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);
 
    long long sum = 0;
    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);
 
        sum += (element - 1);
    }
 
    printf("%d\n", sum);
    return 0;
}
