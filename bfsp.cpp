/* #include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>graph[],int u,int v){
graph[u].push_back(v);
}


void bfs(vector<int>graph[],int start){
    vector<bool>visited(graph->size(),false);
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int V =q.front();
        cout<<V<<" ";
        q.pop();
        // Enqueue all adjacent nodes of v and mark as visited

        for(auto i=graph[V].begin();i!=graph[V].end();i++){
            if(!visited[*i]){
q.push(*i);
visited[*i]=true;

            }
        }
    }
}
int main(){

    int V=7;   //no.of vertics
    vector<int> graph[V];
   
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,5,6);
    addEdge(graph,2,6);

    cout<<"BFS traversal starting from node 0 :"<<"  ";
    bfs(graph,0);

    return 0;
} */



#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
vector<int>bfsOfGraph(int V,vector<int>adj[]){
    vector<int>bfs;             
    vector<int>visited(V-1,0);


    for(int i=0;i<V;i++){
        if(!visited[i]){

queue<int>q;
q.push(i);
visited[i]=1;
while(!q.empty()){
    int node = q.front();
    q.pop();
    bfs.push_back(node);

    for(auto it : adj[node]){
        if(!visited[it]){
            q.push(it);
            visited[it]=1;

        }
    }
}
        }
    }
}
return bfs;
};
int main(){
    Solution obj;
    int m,n ;
    cout<<"Enter the number of nodes and edges of graph -> "<<endl;
    cin>>m>>n;
    vector<int>adj[m+1];
    cout<<"Enter the node u and node v ->"<<endl;
    for(int i=0 ; i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

obj.bfsOfGraph(m,adj[m+1]);
    return 0;
}