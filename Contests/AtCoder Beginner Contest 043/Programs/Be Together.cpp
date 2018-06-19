#include <cstdio>
#include <vector>
#define min(a, b) (a < b ? a : b)

using namespace std;

int square(int n)
{
    return n*n;
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    const int oo = 1e9;
    int min_a = -100, max_a = 100;
    int best_cost = oo;

    for(int final_value = min_a; final_value <= max_a; final_value++)
    {
        int cost = 0;

        for(int i = 1; i <= no_of_elements; i++)
            cost += square(final_value - A[i]);

        best_cost = min(best_cost, cost);
    }

    printf("%d\n", best_cost);
    return 0;
}
