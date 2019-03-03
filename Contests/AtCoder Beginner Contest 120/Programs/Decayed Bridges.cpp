#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

struct Edge
{
    int u, v;

    Edge(){}
};

LL choose_2(LL n)
{
    return (n*(n - 1))/2;
}

struct DSU
{
    vector <int> parent;
    vector <LL> component_size;

    DSU(int n)
    {
        parent.resize(n + 1);
        component_size.resize(n + 1);

        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
            component_size[i] = 1;
        }
    }

    int get_parent(int x)
    {
        while(x != parent[x])
        {
            int grandparent = get_parent(parent[x]);

            parent[x] = grandparent;

            x = parent[x];
        }

        return x;
    }

    void unite(int u, int v)
    {
        int parent_u = get_parent(u), parent_v = get_parent(v);

        if(parent_u == parent_v)
            return;

        if(component_size[parent_u] > component_size[parent_v])
            swap(parent_u, parent_v);

        component_size[parent_v] += component_size[parent_u];
        component_size[parent_u] = 0;

        parent[parent_u] = parent[parent_v];
    }
};

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    vector <Edge> edge(no_of_edges + 1);
    for(int i = 1; i <= no_of_edges; i++)
        cin >> edge[i].u >> edge[i].v;

    LL no_of_pairs = choose_2(no_of_vertices);
    vector <LL> connected_pairs(no_of_edges + 2, 0);

    DSU dsu(no_of_vertices);

    for(int i = no_of_edges; i >= 1; i--)
    {
        connected_pairs[i] = connected_pairs[i + 1];

        int parent_u = dsu.get_parent(edge[i].u), parent_v = dsu.get_parent(edge[i].v);

        if(parent_u == parent_v)
            continue;

        LL component_u = dsu.component_size[parent_u], component_v = dsu.component_size[parent_v];

        connected_pairs[i] += component_u*component_v;

        dsu.unite(edge[i].u, edge[i].v);
    }

    vector <LL> disconnected_pairs(no_of_edges + 1);
    for(int i = 1; i <= no_of_edges; i++)
        disconnected_pairs[i] = no_of_pairs - connected_pairs[i + 1];

    for(int i = 1; i <= no_of_edges; i++)
        cout << disconnected_pairs[i] << endl;

    return 0;
}
