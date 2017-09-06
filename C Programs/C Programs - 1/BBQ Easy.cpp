#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_skewers;
    scanf("%d", &no_of_skewers);

    vector <int> length(2*no_of_skewers);
    for(int i = 0; i < 2*no_of_skewers; i++)
        scanf("%d", &length[i]);

    sort(all(length));

    int sum = 0;
    for(int i = 2*no_of_skewers - 2; i >= 0; i-= 2)
        sum += length[i];

    printf("%d\n", sum);
    return 0;
}
