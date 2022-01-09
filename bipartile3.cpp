#include <bits/stdc++.h>
using namespace std;
bool isBipartile(int node, vector<int> adj[])
{
    vector<int> col(node, -1);
    queue < pair<int, int> q;
    for (int i = 0; i < node; i++)
    {
        if (col[i] == -1)

        {
            q.push({i, 0});
            col[i] = 0;
        }

        while (!q.empty())

        {
            pair<int, int> p = q.front();
            q.pop();
            int v = p.first;
            int c = p.second;
            for (auto it : adj[v])
            {
                if (col[it] == c)
                {
                    return false;
                }
                if (col[it] == -1)
                {
                    col[it] = (c) ? 0 : 1;
                    q.push({j, col[it]});
                }
            }
        }
    }
    return true;
}
int main()
{
    int nodes, edges;
    nodes = 4, edges = 8;
    vector<int> adj[nodes];
    adj[0] = {1, 3};
    return 0;
}