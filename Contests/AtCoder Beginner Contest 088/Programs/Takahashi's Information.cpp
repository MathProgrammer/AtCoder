#include <cstdio>

int main()
{
    int matrix[4][4];

    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            scanf("%d", &matrix[i][j]);

    int A[4];
    int B[4];

    A[1] = 0;
    B[1] = matrix[1][1] - A[1];
    B[2] = matrix[1][2] - A[1];
    B[3] = matrix[1][3] - A[1];
    A[2] = matrix[2][1] - B[1];
    A[3] = matrix[3][1] - B[1];

    int is_possible = true;
    for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
            if(A[i] + B[j] != matrix[i][j])
                is_possible = false;

    printf(is_possible ? "Yes\n" : "No\n");
    return 0;
}
