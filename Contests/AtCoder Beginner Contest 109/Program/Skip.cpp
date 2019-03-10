#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_cities, start_location;
    scanf("%d %d", &no_of_cities, &start_location);

    vector <int> locations(no_of_cities + 1);
    locations[0] = start_location;
    for(int i = 1; i <= no_of_cities; i++)
        scanf("%d", &locations[i]);

    sort(all(locations));

    vector <int> difference(no_of_cities);
    for(int i = 0; i < no_of_cities; i++)
        difference[i] = locations[i + 1] - locations[i];

    int gcd = difference[0];
    for(int i = 1; i < no_of_cities; i++)
        gcd = __gcd(gcd, difference[i]);

    printf("%d\n", gcd);
    return 0;
}
