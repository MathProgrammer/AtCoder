#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct Point
{
    int x, y;
};

int main()
{
    int no_of_points, minimum_points;
    scanf("%d %d", &no_of_points, &minimum_points);

    vector <Point> P(no_of_points);
    vector <int> x(no_of_points);
    vector <int> y(no_of_points);

    for(int i = 0; i < no_of_points; i++)
    {
        scanf("%d %d", &P[i].x, &P[i].y);

        x[i] = P[i].x;
        y[i] = P[i].y;
    }

    sort(all(x));
    sort(all(y));

    long long minimum_area = (x[no_of_points - 1] - x[0])*1LL*(y[no_of_points - 1] - y[0]);

    for(int x_i = 0; x_i < no_of_points; x_i++)
    {
        for(int x_j = x_i + 1; x_j < no_of_points; x_j++)
        {
            for(int y_i = 0; y_i < no_of_points; y_i++)
            {
                for(int y_j = y_i + 1; y_j < no_of_points; y_j++)
                {
                    int x_beginning = x[x_i], x_end = x[x_j], y_beginning = y[y_i], y_end = y[y_j];

                    int inside_points = 0;

                    for(int i = 0; i < no_of_points; i++)
                    {
                        inside_points += (x_beginning <= P[i].x && P[i].x <= x_end && y_beginning <= P[i].y && P[i].y <= y_end);
                    }

                    if(inside_points >= minimum_points)
                        minimum_area = min(minimum_area, (x_end - x_beginning)*1LL*(y_end - y_beginning));
                }
            }
        }
    }

    printf("%lld\n", minimum_area);
    return 0;
}
