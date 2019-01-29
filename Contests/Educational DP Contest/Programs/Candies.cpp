#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 105, MAX_K = 1e5 + 5, MOD = 1e9 + 7;
long long no_of_ways[MAX_N][MAX_K], sum_no_of_ways[MAX_N][MAX_K];

int main()
{
    int no_of_people, no_of_candies;
    cin >> no_of_people >> no_of_candies;

    vector <int> limit(no_of_people + 1);
    for(int i = 1; i <= no_of_people; i++)
        cin >> limit[i];

    //f(i, j) = f(i - 1, j) + f(i - 1, j - 1) + f(i - 1, j - 2) + f(i - 1, j - 3) + ... + f(i - 1, j - a_i);

    no_of_ways[0][0] = 1;
    for(int i = 1; i <= no_of_candies; i++)
        no_of_ways[0][i] = 0;

    for(int i = 1; i <= no_of_people; i++)
    {
        sum_no_of_ways[i - 1][0] = no_of_ways[i - 1][0];
        for(int j = 1; j <= no_of_candies; j++)
        {
            sum_no_of_ways[i - 1][j] = (sum_no_of_ways[i - 1][j - 1] + no_of_ways[i - 1][j])%MOD;
        }

        for(int j = 0; j <= no_of_candies; j++)
        {
            int left = j, right = (j - limit[i] - 1);

            no_of_ways[i][j] = sum_no_of_ways[i - 1][left];

            if(right >= 0)
            {
                no_of_ways[i][j] = (no_of_ways[i][j] - sum_no_of_ways[i - 1][right] + MOD)%MOD;
            }
        }
    }

    cout << no_of_ways[no_of_people][no_of_candies];
    return 0;
}
