//Efficient method to implement prim ALGO
// tc=>
// TC=>nlog(n) when we are using min heap 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,E;
    cout<<"Enter the number of nodes and edges ->"<<endl;
    cin>>N>>E;
    vector<pair<int,int>>adj[N];
    int a, b,wt;
    cout<<"Enter the node a and node b and weight between them ->"<<endl;
    for(int i=0;i<=E;i++){
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});

    }
    int key[N];
    bool mstArray[N];
    int parent[N];
for(int i=0;i<N;i++){
    int key[i]=INT_MAX;
    bool mstArray[i]=false;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>qp;

int key[0]=0;
parent[0]=-1;
qp.push({0,0});
for(int count=0;count<N-1;count++){
    int u=qp.top().second;
    qp.pop();
    mstArray[u]=true;
    for(auto it:adj[u]){
        int v=it.first;
        int weight=it.second;
        if(mstArray[v]==false && weight < key[v]){
            parent[v]=u;
            qp.push({key[u],v});
            key[v]=weight;
        }
    }
}
for(int i=0;i<N;i++){
    cout<<parent[i]<<" "<< i <<"\n";

}
return 0;

}



	typedef pair<int,int>pii;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         int key[V], parent[V], mst[V];
        for (int i = 0; i < V; i++) 
            key[i] = INT_MAX, mst[i] = 0; 
        priority_queue<pii, vector<pii>, greater<pii>> minh;
        key[0] = 0;
        parent[0] = -1;
        minh.push({0,0});
        while(!minh.empty()) {
            int node = minh.top().second;
            mst[node] = 1;
            minh.pop();
            for(auto& it: adj[node]) {
                int x = it[0];
                int wt = it[1];
                if(mst[x]==0 and wt<key[x]) {
                    key[x] = wt;
                    parent[x] = node;
                    minh.push({wt, x});
                }
            }
        }
        return accumulate(key, key+V, 0);
    }
};