#include <iostream>

using namespace std;

const int MAX_LEVEL = 55;
long long buns[MAX_LEVEL], patties[MAX_LEVEL], total[MAX_LEVEL];

long long no_of_patties(long long height, int level)
{
    const int OUTER_BUN = 1, MIDDLE_PATTY = 1;

    if(height >= total[level])
        return patties[level];
    if(height == 0 || height == OUTER_BUN)
        return 0;
    if(height - OUTER_BUN < total[level - 1])
        return no_of_patties(height - OUTER_BUN, level - 1);

    height -= OUTER_BUN;
    long long patties_here = 0;

    if(height >= total[level - 1])
    {
        patties_here += patties[level - 1];
        height -= total[level - 1];
    }
    if(height >= MIDDLE_PATTY)
    {
        patties_here += MIDDLE_PATTY;
        height -= MIDDLE_PATTY;
    }
    if(height > 0)
    {
        patties_here += no_of_patties(height, level - 1);
    }

    return patties_here;
}

int main()
{
    int levels;
    long long height;
    cin >> levels >> height;

    total[0] = patties[0] = 1;
    buns[0] = 0;

    for(int i = 1; i <= levels; i++)
    {
        const int FIRST_BUN = 1, MIDDLE_PATTY = 1, LAST_BUN = 1;

        buns[i] = FIRST_BUN + buns[i - 1] + buns[i - 1] + LAST_BUN;
        patties[i] = patties[i - 1] + MIDDLE_PATTY + patties[i - 1];
        total[i] = FIRST_BUN + total[i - 1] + MIDDLE_PATTY + total[i - 1] + LAST_BUN;
    }

    long long total_patties = no_of_patties(height, levels);

    cout << total_patties;
    return 0;
}
