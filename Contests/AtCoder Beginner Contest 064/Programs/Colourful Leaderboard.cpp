#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int main()
{
    int no_of_contestants;
    scanf("%d", &no_of_contestants);

    const int NO_OF_COLOURS = 8, SPECIAL = 8;
    int frequency[NO_OF_COLOURS + 1] = {0}, special_colours = 0;

    while(no_of_contestants--)
    {
        int rating;
        scanf("%d", &rating);

        if(rating < 3200)
            frequency[rating/400]++;
        else
            special_colours++;
    }

    int normal_colours = 0;
    for(int i = 0; i < SPECIAL; i++)
        normal_colours += (frequency[i] > 0);

    int min_colours = (normal_colours == 0 ? 1 : normal_colours);
    int max_colours = normal_colours + special_colours;

    printf("%d %d", min_colours, max_colours);
    return 0;
}
