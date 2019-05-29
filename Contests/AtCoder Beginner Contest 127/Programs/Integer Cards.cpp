#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()

struct operation
{
    long long range, replacement;

    operation(){}

    operation(int Range, int New)
    {
        range = Range, replacement = New;
    }

    const int operator <(operation & A)
    {
        return (replacement > A.replacement);
    }
};

int main()
{
    int no_of_elements, no_of_operations;
    cin >> no_of_elements >> no_of_operations;

    vector <long long> A(no_of_elements, 0);
    for(int i = 0; i < no_of_elements; i++)
        cin >> A[i];

    sort(all(A));

    vector <operation> O(no_of_operations);
    for(int i = 0; i < no_of_operations; i++)
        cin >> O[i].range >> O[i].replacement;

    sort(all(O));

    int last_operation = 0;
    for(int current = 0; current < no_of_elements && last_operation < no_of_operations;)
    {
        for(int current_operations_remaining = O[last_operation].range; current_operations_remaining > 0 && current < no_of_elements; current_operations_remaining--)
        {
            A[current] = max(A[current], O[last_operation].replacement);

            current++;
        }

        last_operation++;
    }

    long long sum = 0;
    for(int i = 0; i < no_of_elements; i++)
        sum += A[i];

    cout << sum;
    return 0;
}
