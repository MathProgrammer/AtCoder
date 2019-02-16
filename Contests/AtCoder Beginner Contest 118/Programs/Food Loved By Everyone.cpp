#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_people, no_of_foods;
    cin >> no_of_people >> no_of_foods;

    vector <int> no_of_likes(no_of_foods + 1, 0);

    for(int p = 1; p <= no_of_people; p++)
    {
        int no_of_liked_foods;
        cin >> no_of_liked_foods;

        for(int f = 1; f <= no_of_liked_foods; f++)
        {
            int food;
            cin >> food;

            no_of_likes[food]++;
        }
    }

    int no_of_liked_foods = 0;
    for(int i = 1; i <= no_of_foods; i++)
        no_of_liked_foods += (no_of_likes[i] == no_of_people);

    cout << no_of_liked_foods;
    return 0;
}
