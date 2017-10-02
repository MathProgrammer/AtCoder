#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main()
{
    int no_of_lectures, minimum_credit;
    scanf("%d %d", &no_of_lectures, &minimum_credit);

    vector <int> credit(no_of_lectures);
    for(int i = 0; i < no_of_lectures; i++)
        scanf("%d", &credit[i]);

    sort(all(credit));

    int minimum_lectures_required = 0, total_credit = 0;
    for(int i = no_of_lectures - 1; total_credit < minimum_credit && i >= 0; i--, minimum_lectures_required++)
        total_credit += credit[i];

    printf("%d\n", total_credit < minimum_credit ? -1 : minimum_lectures_required);
    return 0;
}
