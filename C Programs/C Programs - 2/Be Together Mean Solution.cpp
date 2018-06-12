#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);
    vector <int> A(no_of_elements + 1);

    double sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%d", &A[i]);

        sum += A[i];
    }

    float mean = sum/no_of_elements;
    int int_mean = mean;

    if(mean - int_mean >= 0.5)
        int_mean++;

    int cost = 0;
    for(int i = 1; i <= no_of_elements; i++)
        cost += (A[i] - int_mean)*(A[i] - int_mean);

    printf("%d\n", cost);
    return 0;
}
