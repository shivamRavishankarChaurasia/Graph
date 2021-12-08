// Root force implemention
// Complexity=O(n2)
// Space Complexity is 3 array[]=> O(N3)
/* #include<bits/stdc++.h>
using namespace std;
int main(){
    int N,E;
    cout<<"Enter the number of edges and nodes in the graph "<<endl;
    cin>>N>>E;
   vector<pair<int,int>>adj[N];
   cout<<"Enter node a and b and weight between them -> "<<endl;
   int a ,b ,wt;
   for(int i=0;i<=E;i++){
cin>>a>>b>>wt;
adj[a].push_back({b,wt});
adj[b].push_back({a,wt});
   }
int parent[N];
int key[N];
bool mstSet[N];
for(int i=0;i<N;i++){
    parent[i]=-1;
    key[i]=INT_MAX;
    mstSet[i]=false;

}
priority_queue<pair<int,int>,vector<pair<int,int>,greater<pair<int,int>>>qp;
key[0]=0;
parent[0]=-1;
qp.push({0,0});
// Find the minimum in the key array
for(int count=0;count<N-1;count++){
    int mini=INT_MAX,u;
    // for(int v=0;v<N;v++)
    //     if(mstSet[v]==false && key[v]<mini)
    //         mini=key[v],u=v;
            mstSet[v]=true;
        for(auto it :adj[u]){
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false && weight <key[v])
            parent[v]=u,key[v]==weight;
        }

    }
    for(int i=1;i<N;i++){
        cout<<parent[i]<<"  "<< i <<"\n";

    }
    return 0;
}
 */


#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAX = 1e4 + 5;
typedef pair<long long, int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        // Select the edge with minimum weight
        p = Q.top();
        Q.pop();
        x = p.second;
        // Checking for cycle
        if(marked[x] == true)
            continue;
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(marked[y] == false)
                Q.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}