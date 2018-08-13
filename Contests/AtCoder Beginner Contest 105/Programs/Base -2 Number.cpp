#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    if(n == 0)
    {
        printf("0\n");
        return 0;
    }

    vector <int> A;
    while(n != 0)
    {
        if(abs(n)%2 == 0)
        {
            A.push_back(0);
            n /= (-2);
        }
        else
        {
            A.push_back(1);
            n--;
            n /= (-2);
        }
    }

    reverse(all(A));

    for(int i = 0; i < A.size(); i++)
        printf("%d", A[i]);

    return 0;
}
