#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e4 + 5, MAX_DIGIT = 9, oo = 1e6;
int max_length_with_last_digit[MAX_N][MAX_DIGIT];
int digit_cost[MAX_DIGIT + 1] = {0,2,5,5,4,5,6,3,7,6};

int main()
{
    int total_cost, no_of_digits;
    cin >> total_cost >> no_of_digits;

    vector <int> is_present(MAX_DIGIT + 1, false);
    for(int i = 1; i <= no_of_digits; i++)
    {
        int digit;
        cin >> digit;
        is_present[digit] = true;
    }

    vector <int> max_length(total_cost + 1, -oo);
    max_length[0] = 0;

    for(int cost = 1; cost <= total_cost; cost++)
    {
        for(int last_digit = 1; last_digit <= MAX_DIGIT; last_digit++)
        {
            if(!is_present[last_digit] || digit_cost[last_digit] > cost)
                continue;

            int remaining_cost = cost - digit_cost[last_digit];

            max_length_with_last_digit[cost][last_digit] = 1 + max_length[remaining_cost];

            max_length[cost] = max(max_length[cost], max_length_with_last_digit[cost][last_digit]);
        }
    }

    vector <int> answer;

    for(int cost = total_cost; cost > 0; )
    {
        for(int last_digit = MAX_DIGIT; last_digit >= 1; last_digit--)
        {
            if(!is_present[last_digit])
                continue;

            if(max_length_with_last_digit[cost][last_digit] == max_length[cost])
            {
                answer.push_back(last_digit);

                cost -= digit_cost[last_digit];

                break;
            }
        }
    }

    for(int i = 0; i < answer.size(); i++)
        cout << answer[i];

    return 0;
}
