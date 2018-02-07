#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    int i = no_of_elements, front = 1, back = no_of_elements;
    vector <int> final_A(no_of_elements + 1);
    while(i >= 1)
    {
        if(front == back)
            final_A[front] = A[i--];
        else
            final_A[front++] = A[i--], final_A[back--] = A[i--];
    }

    for(int i = 1; i <= no_of_elements; i++)
        printf("%d ", final_A[i]);

    return 0;
}
