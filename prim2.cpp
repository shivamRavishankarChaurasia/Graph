//

#include<bits/stdc++.h>
using namespace std;


int main(){
int nodes , edges;
cout<<"Enter the number of nodes and edges ->"<<endl;
cin>>nodes>>edges;
vector<pair<int,int>>adj[nodes];
int a,b,wt;
cout<<"Enter the node a and node b  and weight between them -> "<<endl;
for(int i=0;i<=nodes;i++){
    cin>>a>>b>>wt;
    adj[a].push_back({b,wt});
    adj[b].push_back({a,wt});
    
}
int key[nodes];
bool mstArray[nodes];
int parent[nodes];
for(int i=0;i<=nodes;i++){
    key[i]=INT_MAX;
    mstArray[i]=false;
    parent[i]=-1

    key[0]=0;
    parent[0]=-1;

}
for(int count=0;count<nodes-1;count++){
    int mini=INT_MAX,u;
    for(int j=0;j<nodes;j++){
        
    }
}
    return 0;
}