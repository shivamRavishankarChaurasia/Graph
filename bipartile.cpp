/* #include<bits/stdc++.h>
using namespace std;
bool BiPartileBfs(int src,vector<int>adj[],int colour[]){
    queue<int>q;
    q.push(src);
    colour(src)=1;
    while(!q.empty()){
        int  node=q.front();
        q.pop();
    }
    for(auto it :adj[node]){
        if(colour(it)==-1){
            colour(it)=1-colour(node);
            q.push(it);
        }
        else if (colour[it]==colour(node)){
            return false;
        }
    }
    return true;
}
bool checkForBiPartile(vector<int>adj[],int nodes){
    int colour[nodes];
    memset(colour,-1, sizeof colour);
    for(int i=0;i<node;i++){
        if(colour[i]==-1){
            if(!checkForBiPartile(i,adj,colour)){
                return false;
            }
        }
    }
    return true;
}
int main(){
    cout<<"Enter the number of nodes and edges"<<endl;
    int nodes,edges;
    cin>>nodes>>edges;
    vector<int>adj[nodes];
// undirected graph
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    if(checkForBiPartile(adj,nodes)){
        cout<<"Yes "<<endl;
    }
    else {
        cout<<"No"<<endl;
    }

    return 0;
} */

// *************Bipartite using DFS**********//
#include <bits/stdc++.h>
using namespace std;
bool dfsCheck(vector<int> adj[], int node, int col[])
{
    if (col[node] == -1)
    {
        col[node] = 1;
    }
    for (int it : adj[node])
    {
        if (col[it] == -1)
        {
            col[it] = 1 - col[node];
            if (!dfsCheck(adj, it, col))
            {
                return false;
            }
            elseif(col[it] == col[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool checkBipatite(vector<int> adj[], int n)
{
    vector<int> col(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
        {
            if (!dfsCheck(adj, i, col))
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
    cout << "Enter the number of nodes and edged =>" << endl;
    cin >> nodes >> edges;
    vector<int> adj[nodes];
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter the edges between two nodes =>" << endl;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (checkBipartite(adj, n))
    {
        cout << "Yes it is a Bipartite Graph " << endl;
    }
    else
    {
        cout << "NO it is not a Bipartite Graph" << endl;
    }
    return 0;
}
