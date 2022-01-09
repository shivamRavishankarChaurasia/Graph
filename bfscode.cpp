/* #include <bits/stdc++.h>
using namespace std;
class bfs
{
public:
    vector<int> bfsGraph(int vertics, vector<int> adj[])
    {
        vector<int> bfs;
        vector<int> vis(vertics - 1, 0);
        for (int i = 1; i < vertics; i++)
        {
            if (!vis[i])
            {
                queue<int> q;
                q.push(i);a
                vis[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);
                    for (auto it : adj[node])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
    }
} int main()
{
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;
class bfs
{
public:
    int V; // NO of vertics
    list<int> *adj;
    bfs(int V);
    void addEdge(int v, int w);
    void BFS(int s); // s=source
};
bfs::bfs(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void bfs::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void bfs ::BFS(int s)
{
    vector<int> vis(V - 1, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            list<int> q;
            q.push_back(s);
            vis[s] = 1;

            while (!q.empty())
            {
                s = q.front();
                cout << s << " ";
                q.pop_front();
                for (auto it : adj[s])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push_back(it);
                    }
                }
            }
        }
    }
}
int main()
{
    bfs g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}