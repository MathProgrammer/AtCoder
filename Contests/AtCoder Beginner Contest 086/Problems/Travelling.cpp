#include <cstdio>

#define abs(x) (x > 0 ? (x) : -(x))

int main()
{
    int no_of_steps;
    scanf("%d", &no_of_steps);

    int is_possible = true;
    int last_time = 0;
    int last_x = 0, last_y = 0;

    while(no_of_steps--)
    {
        int time, x, y;
        scanf("%d %d %d", &time, &x, &y);

        int distance = abs(x - last_x) + abs(y - last_y);
        int interval = time - last_time;

        int excess_time = interval - distance;

        if(distance > interval || excess_time%2 == 1)
            is_possible = false;

        last_time = time;
        last_x = x, last_y = y;
    }

    printf(is_possible ? "Yes\n" : "No\n");
    return 0;
}
