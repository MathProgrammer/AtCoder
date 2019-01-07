#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1e5 + 5, BLACK = 0, WHITE = 1, MOD = 1e9 + 7;
vector <int> tree[MAX_N];
long long no_of_ways[MAX_N][2];

long long dfs_count(int parent, int v, int colour)
{
    if(no_of_ways[v][colour] != -1)
    {
        return no_of_ways[v][colour];
    }

    no_of_ways[v][colour] = 1;

    for(int i = 0; i < tree[v].size(); i++)
    {
        int child = tree[v][i];

        if(child == parent) continue;

        long long no_of_subtrees = 1;

        if(colour == BLACK)
        {
            no_of_subtrees = dfs_count(v, child, WHITE);
        }
        else if(colour == WHITE)
        {
            no_of_subtrees = (dfs_count(v, child, BLACK) + dfs_count(v, child, WHITE))%MOD;
        }

        no_of_ways[v][colour] = (no_of_ways[v][colour]*no_of_subtrees)%MOD;
    }

    return no_of_ways[v][colour];
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    for(int i = 1; i <= no_of_vertices - 1; i++)
    {
        int x, y;
        cin >> x >> y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    memset(no_of_ways, -1, sizeof(no_of_ways));

    long long answer = (dfs_count(0, 1, BLACK) + dfs_count(0, 1, WHITE))%MOD;

    cout << answer;
    return 0;
}
