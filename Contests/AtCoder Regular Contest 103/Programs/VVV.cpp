#include <cstdio>
#include <vector>

using namespace std;

void get(vector <int> &A, int &max_1, int &max_2)
{
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] >= A[max_1])
        {
            max_2 = max_1;
            max_1 = i;
        }
        else if(A[i] > A[max_2])
        {
            max_2 = i;
        }
    }
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int MAX_N = 1e5 + 5;
    vector <int> odd_frequency(MAX_N, 0);
    vector <int> even_frequency(MAX_N, 0);

    for(int i = 1; i <= no_of_elements; i++)
    {
        int element;
        scanf("%d", &element);

        if(i%2 == 0)
        {
            even_frequency[element]++;
        }
        else if(i%2 == 1)
        {
            odd_frequency[element]++;
        }
    }

    int most_frequent_even_element = 0, second_most_frequent_even_element = 0;
    get(even_frequency, most_frequent_even_element, second_most_frequent_even_element);

    int most_frequent_odd_element = 0, second_most_frequent_odd_element = 0;
    get(odd_frequency, most_frequent_odd_element, second_most_frequent_odd_element);

    int changes;
    int even_changes = 0, odd_changes = 0;
    if(most_frequent_even_element != most_frequent_odd_element)
    {
        even_changes = no_of_elements/2 - even_frequency[most_frequent_even_element];
        odd_changes = no_of_elements/2 - odd_frequency[most_frequent_odd_element];
        changes = even_changes + odd_changes;
    }
    else if(most_frequent_even_element == most_frequent_odd_element)
    {

            even_changes = no_of_elements/2 - even_frequency[most_frequent_even_element];
            odd_changes = no_of_elements/2 - odd_frequency[second_most_frequent_odd_element];
            int option_1 = even_changes + odd_changes;


            even_changes = no_of_elements/2 - even_frequency[second_most_frequent_even_element];
            odd_changes = no_of_elements/2 - odd_frequency[most_frequent_odd_element];
            int option_2 = even_changes + odd_changes;

        changes = min(option_1, option_2);
    }

    printf("%d\n", changes);
    return 0;
}
