#include<bits/stdc++.h>
using namespace std;
int main(){
    void bfsOfGraph(int N,vector<int>adj[]){
        vector<int>bfs;
        vector<int>vis(N-1,0);
      
        for(int i=1;i<N;i++){
            if(!vis[i]){      
queue<int>q;
q.push();
vis[i]=1;
while(!q.empty()){
int node =q.front();
q.pop();
bfs.push_back(node);

for(auto it :adj[node]){
if(!vis[it]){
q.push(it);
vis[i]=1;
}
}

            }
        }
    }
    return 0;
}