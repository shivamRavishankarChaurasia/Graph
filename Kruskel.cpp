#include<bits/stdc++.h>
using namespace std;
int main(){
    int nodes,edges;
    cout<<"Enter the number of nodes and edges ->"<<endl;
    cin>>nodes>>edges;
    vector<nodes>edges;
    for(int i=0;i<edges;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(node(u,v,wt));
    }
    sort(edges.begin(),edges.end(),comp);
    vector<int>parent(N);
    for(int i=0;i<N;i++)
        parent[i]=1;
        vector<int>rank(N,0);
    int cost=0;
    vector<pair<int,int>>mst;
    for(auto it:edges){
        if(findPar(it.v.parent)!=findPar(it.u,parent)){
            cost+=it.wt;
            mst.push_back({it.u},it.v);
            union(it.u,it.v,parent,rank);
        }
    }

    return 0;
}
