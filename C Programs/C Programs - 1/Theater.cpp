#include <cstdio>

int main()
{
    int no_of_rows;
    scanf("%d", &no_of_rows);

    int no_of_people = 0;
    while(no_of_rows--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        no_of_people += right - (left - 1);
    }

    printf("%d\n", no_of_people);
    return 0;
}
