#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int destination;
    long long weight;

    edge()
    {
        destination = 0, weight = 0;
    }

    edge(int d, long long w)
    {
        destination = d;
        weight = w;
    }
};

const int MAX_N = 1e5;
vector <edge> tree[MAX_N];
vector <long long> weight_till(MAX_N, 0);

void dfs(int v, int parent)
{
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child = tree[v][i].destination;
        long long child_weight = tree[v][i].weight;

        if(child != parent)
        {
            weight_till[child] = child_weight + weight_till[v];

            dfs(child, v);
        }
    }
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges    ; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        tree[u].push_back(edge(v, weight));
        tree[v].push_back(edge(u, weight));
    }

    int root;
    for(int i = 1; i <= no_of_vertices; i++)
        if(tree[i].size() == 1)
            root = i;

    weight_till[root] = 0;
    dfs(root, 0);

    for(int i = 1; i <= no_of_vertices; i++)
        cout << weight_till[i]%2 << endl;

    return 0;
}
