#include<iostream>
using namespace std;
void bfs(int s,vector<int>adj[],bool vis[],int N){
queue<int>q;
q.push(s);
vis[s]=true;
while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    for(auto it = adj[curr]){
        if(!vis(it)){
            q.push(adj(it));
            vis[it]=true;
        }
    }

}
}
int main(){
    /* T=No. of test case 
    N=nodes
    E= edges */
    int T;
    cin>>T;
    while(T--){
        cout<<"Enter the number of nodes and edges in the graph "<<endl;
        int N,E;
        cin>>N>>E
        vector<int>adj[N];
        vector<bool>vis[N]={false};
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        bfs(0,adj,vis,N);
        cout<<endl;

    }
    return 0;
}