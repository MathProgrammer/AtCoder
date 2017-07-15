#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_sticks, snake_sticks;
    scanf("%d %d", &no_of_sticks, &snake_sticks);

    vector <int> stick_length(no_of_sticks);
    for(int i = 0; i < no_of_sticks; i++)
    {
        scanf("%d", &stick_length[i]);
    }

    sort(all(stick_length));
    reverse(all(stick_length));

    int max_length = 0;
    for(int i = 0; i < snake_sticks; i++)
        max_length += stick_length[i];


    printf("%d\n", max_length);
    return 0;
}
