#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_cards;
    scanf("%d", &no_of_cards);

    vector <int> card(no_of_cards);
    for(int i = 0; i < no_of_cards; i++)
        scanf("%d", &card[i]);

    vector <long long> sum_till(no_of_cards);
    sum_till[0] = card[0];
    for(int i = 1; i < no_of_cards; i++)
        sum_till[i] = card[i] + sum_till[i - 1];

    vector <long long> sum_from(no_of_cards);
    sum_from[no_of_cards - 1] = card[no_of_cards - 1];
    for(int i = no_of_cards - 2; i >= 0; i--)
        sum_from[i] = card[i] + sum_from[i + 1];

    long long minimum_difference = 1e15;
    for(int i = 0; i < no_of_cards - 1; i++)
        minimum_difference = min(minimum_difference, abs(sum_till[i] - sum_from[i + 1]));

    printf("%lld\n", minimum_difference);
    return 0;
}
