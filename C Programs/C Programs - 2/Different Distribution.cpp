#include <cstdio>

int main()
{
    int no_of_scores;
    scanf("%d", &no_of_scores);

    int last_position = 0, lowest_score;

    for(int i = 1; i <= no_of_scores; i++)
    {
        int position, score;
        scanf("%d %d", &position, &score);

        if(position > last_position)
        {
            last_position = position, lowest_score = score;
        }
    }

    int maximum_players = last_position + lowest_score;
    printf("%d\n", maximum_players);

    return 0;
}
