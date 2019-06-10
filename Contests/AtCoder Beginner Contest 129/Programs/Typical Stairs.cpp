#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_steps, no_of_broken_steps;
    cin >> no_of_steps >> no_of_broken_steps;

    vector <int> is_broken(no_of_steps + 1, 0);
    for(int i = 1; i <= no_of_broken_steps; i++)
    {
        int step;
        cin >> step;
        is_broken[step] = true;
    }

    const int MOD = 1e9 + 7;
    vector <long long> no_of_ways_till(no_of_steps + 1, 0);
    no_of_ways_till[0] = 1;
    for(int i = 1; i <= no_of_steps; i++)
    {
        if(is_broken[i])
        {
            no_of_ways_till[i] = 0;
            continue;
        }

        if(i == 1)
        {
            no_of_ways_till[i] = 1;
            continue;
        }

        no_of_ways_till[i] = (no_of_ways_till[i - 1] + no_of_ways_till[i - 2])%MOD;
    }

    cout << no_of_ways_till[no_of_steps];
    return 0;
}
