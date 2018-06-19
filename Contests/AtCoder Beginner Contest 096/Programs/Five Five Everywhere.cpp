#include <cstdio>
#include <vector>

using namespace std;

int is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

int main()
{
    int length;
    scanf("%d", &length);

    const int MAX = 55555;

    for(int i = 1, sequence_count = 0; 5*i + 1 <= MAX && sequence_count < length; i++)
    {
        int term = 5*i + 1;

        if(is_prime(term))
        {
            printf("%d\n", term);
            sequence_count++;
        }
    }

    return 0;
}
