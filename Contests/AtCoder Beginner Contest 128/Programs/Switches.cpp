#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 11;
int no_of_bulbs, no_of_switches;
vector <int> switches_connected_to[MAX_N];
vector <int> state_for_bulb_to_be_on(MAX_N, 0), switch_on(MAX_N, 0);

int is_bit_set(int n, int bit)
{
    return ( ( n & (1 << bit) ) != 0);
}

int all_bulbs_on()
{
    for(int i = 1; i <= no_of_bulbs; i++)
    {
        int no_of_on_switches = 0;

        for(int j = 0; j < switches_connected_to[i].size(); j++)
        {
            int current_switch = switches_connected_to[i][j];

            no_of_on_switches += switch_on[current_switch];
        } //cout << "Blub " << i << " No of ON = " << no_of_on_switches << " State = " << state_for_bulb_to_be_on[i] << endl;

        if(no_of_on_switches%2 != state_for_bulb_to_be_on[i])
            return false;
    }

    return true;
}

int main()
{
    cin >> no_of_switches >> no_of_bulbs;

    for(int i = 1; i <= no_of_bulbs; i++)
    {
        int no_of_switches_here;
        cin >> no_of_switches_here;

        for(int j = 1; j <= no_of_switches_here; j++)
        {
            int switch_here;
            cin >> switch_here;

            switches_connected_to[i].push_back(switch_here);
        }
    }

    for(int i = 1; i <= no_of_bulbs; i++)
        cin >> state_for_bulb_to_be_on[i];

    int no_of_combinations = 0;

    const int MAX_MASK = (1 << no_of_switches);
    for(int mask = 0; mask < MAX_MASK; mask++)
    {   //cout << "M = " << mask << endl;
        for(int i = 0; i < no_of_switches; i++)
        {
            switch_on[i + 1] = (is_bit_set(mask, i) ? true : false);
        }

        if(all_bulbs_on())
            no_of_combinations++;// cout << " C = " << no_of_combinations << endl;
    }

    cout << no_of_combinations;
    return 0;
}
