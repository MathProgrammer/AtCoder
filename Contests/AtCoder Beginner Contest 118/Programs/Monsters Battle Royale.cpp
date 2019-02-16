#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void simulate_fight(vector <int> &H)
{
    int smallest, smallest_position = H.size();
    for(int i = 0; i < H.size(); i++)
    {
        if(H[i] != 0)
        {
            smallest = H[i];
            smallest_position = i;
            break;
        }
    }

    for(int i = smallest_position + 1; i < H.size(); i++)
    {
        H[i] %= smallest;
    }

    sort(all(H));
}

int main()
{
    int no_of_monsters;
    cin >> no_of_monsters;

    vector <int> health(no_of_monsters, 0);
    for(int i = 0; i < no_of_monsters; i++)
        cin >> health[i];

    sort(all(health));

    while(health[no_of_monsters - 2] > 0)
    {
        simulate_fight(health);
    }

    cout << health[no_of_monsters - 1];
    return 0;
}
