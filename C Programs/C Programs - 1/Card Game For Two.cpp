#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> card(no_of_elements, 0);
    for(int i = 0; i < no_of_elements; i++)
        scanf("%d", &card[i]);

    sort(all(card));
    reverse(all(card));

    int difference = 0;
    for(int i = 0; i < no_of_elements; i++)
    {
        difference += (i%2 == 0 ? card[i] : -1*card[i]);
    }

    printf("%d\n", difference);
    return 0;
}
