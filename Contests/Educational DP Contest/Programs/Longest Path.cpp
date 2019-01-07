#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1e5 + 5;
int longest_path[MAX_N];
vector <int> graph[MAX_N];

int dfs(int v)
{
    if(longest_path[v] != -1)
    {
        return longest_path[v] ;
    }

    int longest_child_path = 0;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        longest_child_path = max(longest_child_path, dfs(child));
    }

    longest_path[v] = 1 + longest_child_path;

    return longest_path[v] ;
}

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    for(int i = 1; i <= no_of_edges; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
    }

    memset(longest_path, -1, sizeof(longest_path));

    int vertices_on_longest_path = 0;

    for(int i = 1; i <= no_of_vertices; i++)
        vertices_on_longest_path = max(vertices_on_longest_path, dfs(i));

    int edges_on_longest_path = vertices_on_longest_path - 1;

    cout << edges_on_longest_path;

    return 0;
}
