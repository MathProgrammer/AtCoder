#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int no_of_points;
    scanf("%d", &no_of_points);

    vector <int> X(no_of_points + 1);
    vector <int> Y(no_of_points + 1);
    vector <int> height(no_of_points + 1);
    for(int i = 1; i <= no_of_points; i++)
        scanf("%d %d %d", &X[i], &Y[i], &height[i]);

    int non_zero;
    for(int i = 1; i <= no_of_points; i++)
        if(height[i] != 0)
            non_zero = i;

    const int MAX_X = 100, MAX_Y = 100;
    int pyramid_height, center_x, center_y;

    for(int x = 0; x <= MAX_X; x++)
    {
        for(int y = 0; y <= MAX_Y; y++)
        {
            int found = true;

            int candidate_height = height[non_zero] + abs(X[non_zero] - x) + abs(Y[non_zero] - y);

            for(int i = 1; i <= no_of_points; i++)
            {
                int expected_height = max(candidate_height - abs(X[i] - x) - abs(Y[i] - y), 0);

                if(expected_height != height[i])
                {
                    found = false;
                }
            }

            if(found)
            {
                center_x = x, center_y = y;

                pyramid_height = candidate_height;
            }
        }
    }

    printf("%d %d %d\n", center_x, center_y, pyramid_height);
    return 0;
}
