#include <bits/stdc++.h>
using namespace std;
class Solution{
bool bfs(int startNode,vector<int> adj[],vector<int> &visited){
    queue<pair<int,int>> que;
        // vector<int> visited(V,0);
        que.push({startNode,-1});
        visited[startNode] = 1;
        while(!que.empty()){
            auto [node,parent] = que.front();
            que.pop();
            for(auto &neighbor:adj[node]){
                if(!visited[neighbor]){
                    que.push({neighbor,node});
                    visited[neighbor] = 1;
                }else if(neighbor!=parent){
                    return true;
                }
            }
        }
        return false;
}
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(i,adj,visited)==true) return true;
            }
        }
        return false;
    }
};
// V = 4, adj= [[1, 2], [0], [0, 3], [2]]
int main() {
    int V, E;
    cin >> V >> E;

    vector<int> adjList[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u); // undirected graph
    }

    Solution sol;
    cout << sol.isCycle(V, adjList) << endl;
    return 0;
}