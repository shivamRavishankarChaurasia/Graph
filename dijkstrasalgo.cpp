#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,source;
    cout<<"Enter the number of nodes , edges, and source -> "<<endl;
    cin>>n>>m;
    vector<pair<int,int>>g[n+1];    //1-indexed adjacency list for a graph
    int a,b,wt;
    cout<<"Enter the node a node b and weight in the graph -> "<<endl;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        g[a].push_back({b,wt});                 //Condition for undirected graph
        g[b].push_back({a,wt});
    }
    cin>>source;
    // Dijkstra algo 
// min-heap =>{dist,node}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>distArray(n+1,INT_MAX);
     distArray[source]=0;
     pq.push({0,source});
     while(!pq.empty()){
int dist=pq.top().first;
int node=pq.top().second;
pq.pop();


// traverse in graph 
vector<pair<int,int>>::iterator it;
for(auto it :g[node]){
    int next=it.first;
    int nextDist=it.second;
    if(distArray[next]>distArray[node]+nextDist){
        distArray[next]=distArray[node]+nextDist;
        pq.push({distArray[next],next});
    }

}
     }  


     cout<<"The distances from source "<<source<<" are : \n";
     for(int i=1;i<=n;i++){
         cout<<distArray[i]<<" ";

     }
     cout<<endl;
     return 0;
}


priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>distArray(V+1,INT_MAX);
distArray[source]=0;
qp.push({0,source});
while(!qp.empty()){
    int dist=qp.top().first;
    int node=qp.top().second;
    qp.pop();
    vector<pair<int,int>>::iterator it;
    for(auto it:g[node]){
     int next=it.first;
     int nextDist=it.second;
     if(distArray[nextnode]>distArray[node]+nextnode){
distArray[next]=distArray[node]+nextDist;
qp.push({distArray[next],next})
     }

    }

}
