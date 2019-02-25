#include <iostream>
#include <vector>
#include <algorithm>

#define min_3(a, b, c) min(a, min(b, c))
using namespace std;

const int oo = 1e9;
int A, B, C;
vector <int> bamboo;

int dfs(int N, int a, int b, int c)
{
    if(N == 0)
        return (min_3(a, b, c) > 0 ? abs(a - A) + abs(b - B) + abs(c - C) - 30: oo);

    int do_nothing = dfs(N - 1, a, b, c);
    int add_a = dfs(N - 1, a + bamboo[N], b, c) + 10;
    int add_b = dfs(N - 1, a, b + bamboo[N], c) + 10;
    int add_c = dfs(N - 1, a, b, c + bamboo[N]) + 10;

    int minimum_adding = min_3(add_a, add_b, add_c);
    int minimum = min(do_nothing, minimum_adding);

    return minimum;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements >> A >> B >> C;

    bamboo.resize(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> bamboo[i];

    int minimum_cost = dfs(no_of_elements, 0, 0, 0);
    cout << minimum_cost;

    return 0;
}
