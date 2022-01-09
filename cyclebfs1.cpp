#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool cycleBFS(int source, int V, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> q;
        visited[source] = true;
        q.push({source, -1});
        while (!q.empty())
        {
            int current = q.front().first;
            int par = q.front().second;
            q.pop();
            for (auto it : adj[current])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, current});
                }
                else if (par != it)
                {
                    return true;
                }
            }
        }
        retrun false;
    }

public:
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> visited(V - 1, 0);
        for (int i = 1; i < V; i++)
        {
            if (!visited[i])
            {
                if (cycleBFS(i, V, adj, vis))
                    return true;
            }
        }
    }
} int main()
{
    return 0;
}