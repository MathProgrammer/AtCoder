#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> element(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    int no_of_swaps = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(element[i] == i)
        {
            no_of_swaps++;
            i++;
        }
    }

    printf("%d\n", no_of_swaps);
    return 0;
}
