#include <iostream>
#include <vector>
#include <algorithm>

#define max_3(a, b, c) max(a, max(b, c))
using namespace std;

int main()
{
    int no_of_days;
    cin >> no_of_days;

    typedef vector <int> v_int;
    v_int swim_happiness(no_of_days + 1);
    v_int bug_happiness(no_of_days + 1);
    v_int homework_happiness(no_of_days + 1);

    for(int i = 1; i <= no_of_days; i++)
        cin >> swim_happiness[i] >> bug_happiness[i] >> homework_happiness[i];

    const int NO_OF_TYPES = 3;
    vector <v_int> maximum_happiness(no_of_days + 1, v_int(NO_OF_TYPES, 0));

    const int SWIM_TODAY = 0, BUG_TODAY = 1, HOMEWORK_TODAY = 2;
    for(int i = 1; i <= no_of_days; i++)
    {
        maximum_happiness[i][SWIM_TODAY] = swim_happiness[i] + max(maximum_happiness[i - 1][BUG_TODAY], maximum_happiness[i - 1][HOMEWORK_TODAY]);

        maximum_happiness[i][BUG_TODAY] = bug_happiness[i] + max(maximum_happiness[i - 1][HOMEWORK_TODAY], maximum_happiness[i - 1][SWIM_TODAY]);

        maximum_happiness[i][HOMEWORK_TODAY] = homework_happiness[i] + max(maximum_happiness[i - 1][SWIM_TODAY], maximum_happiness[i - 1][BUG_TODAY]);
    }

    int overall_happiness = max_3(maximum_happiness[no_of_days][SWIM_TODAY], maximum_happiness[no_of_days][BUG_TODAY], maximum_happiness[no_of_days][HOMEWORK_TODAY]);

    cout << overall_happiness;
    return 0;
}
