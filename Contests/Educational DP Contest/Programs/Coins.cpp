#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int MAX_N = 3003;
double probability_heads[MAX_N][MAX_N], probability[MAX_N];

int main()
{
    int no_of_coins;
    cin >> no_of_coins;

    for(int i = 1; i <= no_of_coins; i++)
        cin >> probability[i];

    memset(probability_heads, 0, sizeof(probability_heads));
    probability_heads[0][0] = 1;

    for(int i = 1; i <= no_of_coins; i++)
    {
        double head_event = probability[i], tail_event = 1 - probability[i];

        probability_heads[0][i] = tail_event*probability_heads[0][i - 1];

        for(int heads = 1; heads <= i; heads++)
        {
            probability_heads[heads][i] = head_event*probability_heads[heads - 1][i - 1] + tail_event*probability_heads[heads][i - 1];
        }
    }

    double answer = 0;
    for(int i = no_of_coins/2 + 1; i <= no_of_coins; i++)
        answer += probability_heads[i][no_of_coins];

    cout << setprecision(9) << answer;
    return 0;
}
