#include <cstdio>
#include <vector>

using namespace std;

int all_ones(int n) //Return a number consisting of n 1s in binary
{
    return (1LL << n) - 1;
}

int is_bit_set(int n, int position)
{
    return ( (n&(1LL << position)) != 0);
}

int main()
{
    int no_of_elements, k;
    scanf("%d %d", &no_of_elements, &k);

    vector <int> cost(no_of_elements + 1);
    vector <int> utility(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d %d", &cost[i], &utility[i]);

    int limit = k + 1;
    const int MAX_BITS = 31;

    long long mask = 0, best_utility = 0;

    for(int bit = MAX_BITS; bit >= 0; bit--)
    {
        if(is_bit_set(limit, bit)) //bit is set
        {
            mask = (limit - (1LL << bit)); //Make that bit 0

            mask |= all_ones(bit); //Set all bits after that position

            long long current_utility = 0;

            for(int i = 1; i <= no_of_elements; i++)
            {
                if( (mask&cost[i]) == cost[i] ) //Cost[i] is a submask of mask
                {
                    current_utility += utility[i];
                }
            }

            best_utility = max(best_utility, current_utility);
        }
    }

    printf("%lld\n", best_utility);
    return 0;
}
