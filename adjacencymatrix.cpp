#include<bits/stdc++.h>
#define V 5
using namespace std;
void addEdge(int graph[][V],int u,int v){
    graph[u][v]=1;
}
int main(){
    int graph[V][V]={0};
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    addEdge(graph,0,1);
    cout<<"Adjacency Matrix :"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
        cout<<graph[i][j]<<" ";
        cout<<endl;
        }
    }
    return 0;
}