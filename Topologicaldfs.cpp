// Topological sort using DFS
#include<bits/stdc++.h>
using namespace std;
class Solution{
    void findTopoSort(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                findTopoSort(it,vis,st,adj);
            }
        }
        st.push(node);
    }
    public:
    // N=no.of nodes
    vector<int>topoSort(int N,vector<int>adj[]){      
        stack<int>st;  //Stack
        vector<int>vis(N,0);    //Visited Array
        for(int i=0;i<N;i++){
            if(vis[i]==0){
             findTopoSort(i,vis,st,adj);
            }
        }
        vector<int>topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();

        }
        return topo;
    }
};


/* void findTopoSort(int node,vector<int>&vis,stack<int>&s,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            findTopoSort(it,vis,st,adj);
        }
    }
    s.push(node);
}
// N=no.of Nodes 
vector<int>topoSort(int N,vector<int>adj[]){
    stack<int>s;
    vector<int>vis(N,0);
    for(int i=0;i<N;i++){
if(vis[i]==0){
    findTopoSort(i,vis,st,adj);
}
    }

    vector<int>topo;
    while(!s.empty()){
        topo.push_back(s.top());
        s.pop();
    }
    return topo;
} */