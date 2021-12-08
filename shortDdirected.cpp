#include<bits/stdc++.h>
using namespace std;
void findTopoSort(int node,int vis[],stack<int>&s,vector<pair<int,int>>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it.first]){
            findTopoSort(it.first,vis,s,adj);
        }
    }
    s.push(node);
}
    void shortestPath(int scr,int N,vector<pair<int,int>>adj[]){
        int vis[N]={0};
    stack<int>s;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            findTopoSort(i,vis,s,adj);
        }
    }

    int dist[N];
    for(int i=0;i<N;i++){
        dist[i]=INT_MAX;
        dist(scr)=0;

    }
    while(s.empty()){
        int node=s.top();
        s.pop();
        if(dist[node]!=INF){
            for(auto it:adj[node]){
                if(dist[node]+it.second<dist[it.first]){
                    dist[it.first]=dist[node]+it.second;
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        (dist[i]==INT_MAX)?cout<<"INF":cout<<dist[i]<<" ";
    }
    }

int main(){
    int n ,m;
    cout<<"Enter the number of nodes and edges ->"<<endl;
    cin>>n>>m;
    cout<<"Enter the nodes and weight between them ->"<<endl;
    vector<pair<int,int>>adj[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});

    }
    shortestPath(0,n,adj);

    return 0;
}