#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
vector <int> graph[MAX_N];
vector <int> component(MAX_N, 0);

void dfs(int v, int parent_v, int component_no)
{
    component[v] = component_no;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child_v = graph[v][i];

        if(parent_v == child_v || component[child_v] != 0) continue;

        dfs(child_v, v, component_no);
    }
}

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v, z;
        cin >> u >> v >> z;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int no_of_components = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(component[i] == 0)
        {
            no_of_components++;

            dfs(i, 0, no_of_components);
        }
    }

    cout << no_of_components;
    return 0;
}
