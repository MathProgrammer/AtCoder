#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    const int limit = 1e5;
    vector <int> frequency(limit + 1, 0);

    int no_of_elements;
    scanf("%d", &no_of_elements);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int element_i;
        scanf("%d", &element_i);

        frequency[element_i]++;
    }

    int maximum_equal_elements = 0;
    for(int equal_element = 1; equal_element < limit; equal_element++)
    {
        int no_of_equal_elements = frequency[equal_element - 1] + frequency[equal_element] + frequency[equal_element + 1];
        maximum_equal_elements = max(maximum_equal_elements, no_of_equal_elements);
    }

    printf("%d\n", maximum_equal_elements);
    return 0;
}
