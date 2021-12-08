//Kruskal algo

#include<bits/stdc++.h>
using namespace std;
void Krushkals(vector<Edge> & edge_list,int V,int E){
    sort(edge_list.begin(),edge_list.end(),comparator);
    int i=0,j=0;
    while(i<V-1 &&j<E){
        int fromP=find(edge_list[j].src);
        int toP=find(edge_list[j].dst);
        if(fromP==toP){
            ++j; 
            continue;
        }
        else{
            //UNION OPERATION 
            union_op(fromP,toP);
            mst.push_back(edge_list[j]);
            ++i;
        }
    }
}
void printMST(vector<edges>&mst){
    cout<<"MST found "<<endl;
    for(auto p :mst){
        cout<<"src:"<<p.src<<" dst :" <<p.dst<<" wt: "<<p.wt<<endl;
    }
}
int main(){
    int E;
    int V;
    cin>>E>>V;
    dsuf.resize(V);
    for(int i=0;i<V;i++){
        dsuf[i].parent=-1;
        dsuf[i].rank = 0;
    }
    vector<Edge>edge_list;   //adjacency list 
    Edge temp;
    for(int i=0;i<E;++i){
        int from,to,wt;
        cin>>from>>to>>wt;
        temp.src=from;
        temp.dst=to;
        temp.wt=wt;
        edge_list.push_back(temp);
    }
    Krushkals(edge_list,V,E);
    printMST(mst);
    return 0;
}