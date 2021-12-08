// Cycle detection in the graph using bfs technique 
/* #include<std/bitsc++.h>
using namespace std;
class Solution{
    // s=starting node,V=No.of nodes
    bool checkForCycle(int s,int V,vector<int>adj[],vector<int>&visited){
        // Create a queue for BFS
        queue<pair<int,int>>q;
        visited[s]=true;
        q.push({s,-1});
        while(!q.empty()){
            int node=q.front().first;
            int par = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(!visited[it]){
                    visited[it]=true;
                    q.push({it,node});
                }
                else if (par!=it){
                    return true;
                }
            }
        }
        return  false;
    }
    public:
    bool isCycle(int V,vector<int>adj[]){
        vector<int>vis(V-1,0);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                if(checkForCycle(i,V,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }

};
int main(){
    return 0;
    
*/
class Solution{
    public:
bool checkForCycle(int start_node,int V,vector<int>adj[],vector<int>&visited){
    queue<pair<int,int>>q;
    visited[start_node]=true;
    q.push({start_node,-1});
    while(!q.empty()){
        int node=q.front().first;
        int pre=q.front().second;
        q.pop();
        for(auto it :adj[node]){
            if(!visited[it]){
                visited[it]=true;
                q.push({it,node});

            }else if (par!=it){
                return true;
            }
        }
    }
    return false;
}
public:
bool isCycle(int V,vector<int>adj[]){
    vector<int>vis(V-1,0);
    for(int i=0;i<=V;i++){
        if(!vis[i]){
            if(checkForCycle(i,V,adj,vis)) return true;
        }
    }
}
};