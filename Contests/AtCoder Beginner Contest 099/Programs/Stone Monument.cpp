#include <cstdio>
#include <vector>

using namespace std;

int sum_till(int n)
{
    return (n*(n + 1))/2;
}

int main()
{
    int left, right;
    scanf("%d %d", &left, &right);

    int n = right - left;
    int snow_cover = sum_till(n) - right;

    printf("%d\n", snow_cover);
    return 0;
}
