#include <bits/stdc++.h>
using namespace std;
class Solution{
    //kahn's algorithm
public:
    vector<int> topoSort(int V, vector<int> adj[]){
        queue<int> que;
        vector<int> result;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto &it:adj[i]) indegree[it]++;
        }
        for(int i=0;i<V;i++){
            if(indegree[i]==0) que.push(i);
        }
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            result.push_back(node);
            for(auto &it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    que.push(it);
                }
            }
        }
        return result;
    }
};

int main() {
    // code here
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    Solution sol;
    vector<int> result  = sol.topoSort(V,adj);
    for(auto &it:result){
        cout<<it<<" ";
    }
    cout<<endl;
    

    return 0;
}