#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_N = 2e5 + 5;

vector <stack <int> > minimum_ending_of_length(MAX_N);
vector <int> A(MAX_N);
vector <vector <int> > tree(MAX_N);
vector <int> LIS_here(MAX_N);

int find_first_greater(int n)
{
    int left = 0, right = MAX_N - 1;

    //L < x <= R
    while(right - left > 1)
    {
        int mid = (left + right)/2;

        if(minimum_ending_of_length[mid].size() == 0 || minimum_ending_of_length[mid].top() >= n)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }

    return right;
}

int find_LIS()
{
    int left = 0, right = MAX_N - 1;

    //L <= x < R
    while(right - left > 1)
    {
        int mid = (left + right)/2;

        if(minimum_ending_of_length[mid].size() > 0)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

void dfs(int v, int parent_v)
{
    int best_position = find_first_greater(A[v]);
    minimum_ending_of_length[best_position].push(A[v]);

    LIS_here[v] = find_LIS();

    for(int child_v : tree[v])
    {
        if(child_v == parent_v)
        {
            continue;
        }

        dfs(child_v, v);
    }

    minimum_ending_of_length[best_position].pop();
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> A[i];
    }

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    for(int v = 1; v <= no_of_vertices; v++)
    {
        cout << LIS_here[v] << "\n";
    }

    return 0;
}
