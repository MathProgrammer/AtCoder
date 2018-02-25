#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_islands, no_of_boat_services;
    scanf("%d %d", &no_of_islands, &no_of_boat_services);

    vector <int> boats[no_of_islands + 1];

    for(int i = 1; i <= no_of_boat_services; i++)
    {
        int boat_1, boat_2;
        scanf("%d %d", &boat_1, &boat_2);

        boats[boat_1].push_back(boat_2);
        boats[boat_2].push_back(boat_1);
    }

    vector <int> reachable_from_1(no_of_islands + 1, false);
    for(int i = 0; i < boats[1].size(); i++)
        reachable_from_1[boats[1][i]] = true;

    vector <int> reachable_from_n(no_of_islands + 1, false);
    for(int i = 0; i < boats[no_of_islands].size(); i++)
        reachable_from_n[boats[no_of_islands][i]] = true;

    int reachable = false;
    for(int i = 2; i < no_of_islands; i++)
    {
        if(reachable_from_1[i] && reachable_from_n[i])
            reachable = true;
    }

    printf(reachable ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    return 0;
}
