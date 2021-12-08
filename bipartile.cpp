#include<bits/stdc++.h>
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
            if(checkForBiPartile(i,adj,colour)){
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
}