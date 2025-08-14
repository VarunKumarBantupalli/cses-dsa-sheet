#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, vector<int> &color, vector<vector<int>> &adj)
{
    color[node] = col;

    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if(dfs(it, 3 - col, color, adj) == false){
                return false;
            }
        }
        else if (color[it] == color[node])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u;
        int v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {

        if (color[i] == -1)
        {
            if (!dfs(i, 1, color, adj))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = 1; i < color.size(); i++)
    {
        cout << color[i] << " ";
    }
}