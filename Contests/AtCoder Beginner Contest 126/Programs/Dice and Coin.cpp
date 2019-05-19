#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int no_of_dice_faces, minimum_score;
    cin >> no_of_dice_faces >> minimum_score;

    long double winning_probability = 0;
    for(int i = 1; i <= no_of_dice_faces; i++)
    {
        if(i >= minimum_score)
        {
            winning_probability += 1.0/(no_of_dice_faces*1.0);

            continue;
        }

        int no_of_heads_required = 0;
        int face = i;

        while(face < minimum_score)
        {
            face *= 2;
            no_of_heads_required++;
        }

        long long no_of_outcomes = (1LL << no_of_heads_required);

        winning_probability += 1.0/(no_of_dice_faces*1.0*no_of_outcomes);
    }

    cout << setprecision(12) << winning_probability;
    return 0;
}
