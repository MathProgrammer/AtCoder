#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 15, UNMARKED = 0;
vector <int> graph[MAX_N];
int component[MAX_N];

void dfs(int v, int component_no)
{
    component[v] = component_no;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(component[child] == UNMARKED)
            dfs(child, component_no);
    }
}

int main()
{
    int n, no_of_edges;
    scanf("%d %d", &n, &no_of_edges);

    vector <int> permutation(n + 1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &permutation[i]);

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(component, UNMARKED, sizeof(component));

    int component_no = 1;

    for(int i = 1; i <= n; i++)
    {
        if(component[i] == UNMARKED)
            dfs(i, component_no++);
    }

    int no_of_inplace_elements = 0;
    for(int i = 1; i <= n; i++)
        no_of_inplace_elements += (i == permutation[i] || component[i] == component[permutation[i]]);

    printf("%d\n", no_of_inplace_elements);
    return 0;
}
