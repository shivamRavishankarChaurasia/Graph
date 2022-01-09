#include <bits/stdc++.h>
using namespace std;
class Solution
{
public: // v=no.of nodes in the graph
    vector<int> bfsOfGraph(int v, vector<int> adj[]);
    vector<int> bfs;
    vector<int> vis[v - 1, 0]; // visited
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            // BFS
            queue<int> q;
            q.push(i); // put starting node in the queue
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for (auto it : adj[node])
                {
                    if (!vis(it))
                    {
                        q.push(it);
                        vis(it) = 1;
                    }
                }
            }
        }
    }
    return bfs;

} int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges ->" << endl;
    cin >> nodes >> edges;
    vector<int> adj[nodes + 1];
    cout << "Enter the node u,node v in the adj list -> " << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfsOfGraph(nodes, adj);

    return 0;
}