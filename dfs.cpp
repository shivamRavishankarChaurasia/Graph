/* #include<iostream>
using namespace std;
class Solution{
    void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&storeOfDfs){
        storeOfDfs.push_back(node);
        vis[node]=1;
        for(auto it :adj[node])
        if(!vis[i]){
            dfs(it,vis,adj,storeOfDfs)
        }
    }
    public:
    vector<int>dfsOfGraph(int V , vector<int>adj[]);
    vector<int>storeOfDfs;
    vector<int>vis(V+1,0);
    for(int i=1;i<=V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,storeOfDfs);
        }
    }
}
int main(){
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;
// Graph Class represents a directed graph using adjacency list representation
class Graph
{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
    // function to add an edges to graph
    // V=nodes,W=edges
    void addEdge(int V, int W);
    // print DFS
    void DFS(int V);
    void DFS();
};
void Graph::addEdge(int V, int W)
{
    adj[V].push_back(W);
}
void Graph::DFS(int V)
{
    // Marked the current node as visited and print it
    visited[V] = true;
    cout << V << " ";

    // recurr for all the vertics adjacent to this vertex
    list<int>::iterator it;
    for (it = adj[V].begin(); it != adj[V].end(); it++)
    {
        if (!visited[*it])
        {
            DFS(*it);
        }
    }
}
// function to do dfs traversal
void Graph::DFS()
{
    for (auto i : adj)
    {
        if (visited[i.first] == false)
        {
            DFS(i.first);
        }
    }
}
int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    cout << "DFS is ->" << endl;
    g.DFS(2);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
    {
        storeDfs.push_back(node);
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[i])
            {
                dfs(it, vis, adj, storeDfs);
            }
        }
    }

public:
    vector<int> dfsofGraph(int vertics, vector<int> adj[])
    {
        vector<int> storeDFS;
        vector<int> vis(vertics + 1, 0);
        for (int i = 1; i < vertics; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, storeDfs);
            }
        }
        return storeDfs;
    }
} int main()
{
    return 0;
}