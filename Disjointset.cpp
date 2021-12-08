


#include<bits/stdc++.h>
using namespace std;
vector<int>dsuf;
int find(int v){
    if(dsuf[v]==-1)
        return v;
        return find(dsuf[v]);
    
}
void union_op(int fromP,int toP){
    fromP=find(fromP);
    toP=find(top);
    dsuf(fromP)=top;
}
bool isCyclic(vector<pair<int,int>>edges_list){
    for(auto p:edges_list){
        int fromP=find(p.first);
        int toP=find(p.second);
        if(fromP==top){
            return true;

        }
        else
        union_op(fromP,toP);
    }
    return false;
}
int main(){
    int V,E;    //No.of edges and no of vertics (0 to V-1)
    cout<<"Enter the number of nodes and edges  -> "<<endl;
    cin>>V>>E;
    //dsuf=disjoint set union find operation 
    dsuf.resize(V,-1);
    vector<pair<int,int>>edges_list;
    for(int i=0;i<E;i++){

        int from,to;
        cout<<"Enter the 2 node node a amd node b ->"<<endl;
        cin>>from>>to;
        edges_list.push_back({from,to});


    }
    if(isCyclic(edges_list))
    cout<<"TRUE"<<endl;
    else
    cout<<"FALSE"<<endl;
    return 0;
}