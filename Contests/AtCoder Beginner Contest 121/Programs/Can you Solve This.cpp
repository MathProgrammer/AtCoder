#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dot_product(vector <int> &A, vector <int> &B)
{
    int answer = 0;
    for(int i = 1; i < A.size(); i++)
    {
        answer += A[i]*B[i];
    }
    return answer;
}

int main()
{
    int no_of_rows, no_of_columns, C;
    cin >> no_of_rows >> no_of_columns >> C;

    vector <int> B(no_of_columns + 1);
    for(int i = 1; i <= no_of_columns; i++)
    {
        cin >> B[i];
    }

    vector <vector <int> > A(no_of_rows + 1, vector <int> (no_of_columns + 1));
    for(int i = 1; i <= no_of_rows; i++)
    {
        for(int j = 1; j <= no_of_columns; j++)
        {
            cin >> A[i][j];
        }
    }

    int good_rows = 0;
    for(int i = 1; i <= no_of_rows; i++)
    {
        good_rows += (dot_product(A[i], B) + C > 0);
    }

    cout << good_rows << "\n";

    return 0;
}


