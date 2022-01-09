#include <bits/stdc++.h>
using namespace std;
bool bfsCheck(vector<int> adj[], int node, vector<int> &color_array)
{
    queue<int> q;
    q.push(node);
    color_array[node] = 1;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (auto e : adj[current])
        {
            if (color_array[e] == -1)
            {
                color_array[e] = 1 - color_array[node];
                q.push(e);
            }
            else if (color_array[e] == color_array[current])
            {
                return false;
            }
        }
    }
    return true;
}
bool checkBipartile(vector<int> adj[], int n)
{
    vector<int> color_array(n, -1);
    for (int i = 0; i < n; i++)
    {
        color_array[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (color_array[i] == -1)
        {
            if (bfsCheck(adj, i, color_array))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges => " << endl;
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    for (int i = 0; i < edges; i++)
    {
        cout << "Enter the adjacent edges " << endl;
        int u, v;
        cin >> u >> v;
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (checkBipartile(adj, nodes))
    {
        cout << "yes it is the Bipartile graph";
    }
    else
    {
        cout << "Its is not a Bipartile graph";
    }

    return 0;
}