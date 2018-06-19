#include <cstdio>
#include <cstring>

const int MAX_N = 55;

int has_edge[MAX_N][MAX_N], a[MAX_N], b[MAX_N], visited[MAX_N];

void delete_edge(int u, int v)
{
    has_edge[u][v] = has_edge[v][u] = false;
}

void create_edge(int u, int v)
{
    has_edge[u][v] = has_edge[v][u] = true;
}


void dfs(int v)
{
    visited[v] = true;

    for(int child = 1; child <= MAX_N; child++)
    {
        if(has_edge[v][child] && !visited[child])
            dfs(child);
    }
}

int main()
{
    int no_of_vertices, no_of_edges;
    scanf("%d %d", &no_of_vertices, &no_of_edges);

    memset(has_edge, false, sizeof(has_edge));

    for(int i = 1; i <= no_of_edges; i++)
    {
        scanf("%d %d", &a[i], &b[i]);

        create_edge(a[i], b[i]);
    }

    int no_of_bridges = 0;
    for(int i = 1; i <= no_of_edges; i++)
    {
        delete_edge(a[i], b[i]);

        memset(visited, false, sizeof(visited));

        dfs(1);

        int is_bridge = false;
        for(int v = 1; v <= no_of_vertices; v++) //Checking if some vertex is not reachable if this bridge is deleted
            if(!visited[v])
                is_bridge = true;

        no_of_bridges += (is_bridge == true);

        create_edge(a[i], b[i]);
    }

    printf("%d\n", no_of_bridges);
    return 0;
}
