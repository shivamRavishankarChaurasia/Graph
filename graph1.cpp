// Adjacency matrix

#include<bits/stdc++.h>
using namespace std;
int main(){
    //n,m are no.of nodes and edges
    int n , m ;
    cout<<"Enter the number of nodes and edges -> "<<endl;
    cin>>n>>m;
    // Declare the adjacent matrix
    // adj[rows][columns]
    int adj[n+1][n+1];
    // take edges as input 
    for(int i=0;i<m;i++){
        int u,v;          //u=node1 , v = adj node of u 
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    return 0;
}

Adjacency list
// Space complexity = O(N+2E)
int main(){
    int n , m ;       //n=nodes,m=edges
    cout<<"Enter the number of nodes and edges"<<endl;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++){             //For every edges of graph we have u and v nodes
        int u , v ,wt;
        cin>>u>>v>>wt;
        //For undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
        // For directed graph 
        adj[u].push_back(v);
        // for Weighted graph
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});

    }
}
