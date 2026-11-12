#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool bfsTraversal(int V, vector<vector<int>> &adjList,int startNode,vector<int> &colors){
        queue<int> que;
        que.push(startNode);
        colors[startNode] = 0;
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            for(auto &neighbor:adjList[node]){
                // if neighbor is not colored than color it with opposite color
                if(colors[neighbor]==-1){
                    colors[neighbor] = 1- colors[node];
                    que.push(neighbor);
                }else if(colors[neighbor]==colors[node]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> edges)  {
        vector<int> colors(V,-1);
        vector<vector<int>> adjList(V);
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(colors[i]==-1){
                if(bfsTraversal(V,adjList,i,colors)==false) return false;
            }
        }
        return true;
    }
};

int main() {
    // code here
    int V;
    cin>>V;
    vector<vector<int>> edges;
    for(int i=0;i<V;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    Solution sol;
    bool ans = sol.isBipartite(V,edges);
    if(ans) cout<<"bipartite graph"<<endl;
    else cout<<"not a bipartite graph"<<endl;
    return 0;
}