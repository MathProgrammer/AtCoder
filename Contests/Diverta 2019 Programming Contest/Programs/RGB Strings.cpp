#include <iostream>

using namespace std;

int main()
{
    int red_box, green_box, blue_box, balls;
    cin >> red_box >> green_box >> blue_box >> balls;

    int no_of_ways = 0;
    for(int r = 0; r*red_box <= balls; r++)
    {
        for(int g = 0; r*red_box + g*green_box <= balls; g++)
        {
            int balls_taken = r*red_box + g*green_box;
            int balls_remaining = balls - balls_taken;

            if(balls_remaining%blue_box == 0)
                no_of_ways++;
        }
    }

    cout << no_of_ways;
    return 0;
}
