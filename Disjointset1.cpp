// optimised of union set 

//Tc = log(n)
#include<iostream>
using namespace std;
struct node{
    int parent;
    int rank;

};
vector<node>dsuf;
int find(int v){
    if(dsuf[v].parent==-1){
        return v;
        return dsuf[v].parent=find(dsuf[v].parent);   //PATH COMPRESSION 
    }
}
void union_op(int fromP,int toP){
    // union by rank
    if(dsuf[fromP].rank > dsuf[top].rank){   //fromP has Higher rank
        dsuf[top].parent = fromP;
    }
    else if (dsuf[fromP].rank < dsuf[toP].rank){   //toP has higher rank
        dsuf[fromP].parent = toP;

    }
    else{
        //Both have same rank so anyone can be made as parent 
        dsuf[fromP].parent=top;
        dsuf[toP].rank +=1;   //Increase rank of parent 
    }

}
bool isCyclic(vector<pair<int,int>> &edges_list){
    for(auto p:edges_list){
        int fromP=find(p.first);
        int toP=find(p.second);
        if(fromP==toP)
        return true;
        else{
            union_op(fromP,toP)
        }
    }
        return false;

}
int main(){
    int E;
    int V;
    cin>>E>>V;
    dsuf.resize(V);   //parent array
    for(int i=0;i<V;i++){
        dsuf[i].parent=-1;
        dsuf[i].rank =0;

    }
    vector<pair<int,int>>edges_list;
    for(int i=0;i<E;i++){
        int from,to;
        cin>>from>>to;
        edges_list.push_back({from,to});        //for undirected graph

    }
    if(isCyclic(edge_list))
    cout<<"TRUE"<<endl;
    else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}
