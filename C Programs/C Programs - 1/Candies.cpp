#include <cstdio>
#include <cstring>

#define max(a, b) (a > b ? a : b)
using namespace std;

int main()
{
    int no_of_columns;
    scanf("%d", &no_of_columns);

    int candies[2 + 1][no_of_columns + 1];
    memset(candies, 0, sizeof(candies));

    for(int i = 1; i <= 2; i++)
        for(int j = 1; j <= no_of_columns; j++)
            scanf("%d", &candies[i][j]);

    int max_candies_till[2 + 1][no_of_columns + 1];
    memset(max_candies_till, 0, sizeof(max_candies_till));

    for(int i = 1; i <= 2; i++)
    {
        for(int j = 1; j <= no_of_columns; j++)
        {
            max_candies_till[i][j] = candies[i][j] + max(max_candies_till[i - 1][j], max_candies_till[i][j - 1]);
        }
    }

    printf("%d\n", max_candies_till[2][no_of_columns]);
    return 0;
}
