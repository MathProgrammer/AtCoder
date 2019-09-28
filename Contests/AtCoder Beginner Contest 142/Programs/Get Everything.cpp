#include <iostream>
#include <vector>

using namespace std;

int is_submask(int mask, int submask)
{
    return ((mask&submask) == submask);
}

int main()
{
    int no_of_boxes, no_of_keys;
    cin >> no_of_boxes >> no_of_keys;

    vector <long long> cost(no_of_keys + 1, 0);
    vector <int> no_of_openable_boxes(no_of_keys + 1, 0);
    vector <long long> mask(no_of_keys + 1, 0);

    for(int i = 1; i <= no_of_keys; i++)
    {
        cin >> cost[i] >> no_of_openable_boxes[i];

        for(int j = 1; j <= no_of_openable_boxes[i]; j++)
        {
            int key;
            cin >> key;

            key--;
            mask[i] |= (1 << key);
        }
    }

    long long oo = 1e12;
    int complete_mask = (1LL << no_of_boxes) - 1;
    vector <long long> minimum_cost(complete_mask + 1, oo);
    minimum_cost[0] = 0;

    for(int i = 1; i <= no_of_keys; i++)
    {
        for(int m = 0; m <= complete_mask; m++)
        {
            if(is_submask(m,mask[i]))
            {
                for(int sub_m = 0; sub_m <= complete_mask; sub_m++)
                {
                    if(is_submask(mask[i],sub_m))
                    {
                        minimum_cost[m] = min(minimum_cost[m], minimum_cost[m^sub_m] + cost[i]);
                    }
                }

            }
        }
    }

    cout << (minimum_cost[complete_mask] == oo ? -1 : minimum_cost[complete_mask]) << "\n";
    return 0;
}
