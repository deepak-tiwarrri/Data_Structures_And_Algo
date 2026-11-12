#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool dfs(int startNode,vector<int> adj[],vector<int> &visited,int &parentNode){
        visited[startNode] = 1;
        for(auto &neighbor:adj[0]){
             if(!visited[neighbor]){
                visited[neighbor] = 1;
                dfs(neighbor,adj,visited,startNode);
             }else if(parentNode!=neighbor) return true;
        }
        return true;
    }
    bool isCycle(int V, vector<int> adj[]) {
       vector<int> visited(V,0);
       int parentNode = -1;
       for(int i=0;i<V;i++){
         if(!visited[i]){
            if(dfs(i,adj,visited,parentNode)==true) return true;
         }
       }
       return false;
    }
};
int main() {
    // code here
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution sol;
    bool isCycleFound = sol.isCycle(V,adj);
    if(isCycleFound) cout<<"cycle found"<<endl;
    else cout<<"cycle not present"<<endl;


    return 0;
}