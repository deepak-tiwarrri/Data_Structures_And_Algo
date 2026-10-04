#include <bits/stdc++.h>
using namespace std;
// vector<int> bfsTraversal(int v, vector<vector<int>> &adj)
// {
//     vector<int> bfs;
//     vector<int> vis(v, 0);
//     vis[0] = 1;
//     queue<int> q;
//     //use the same binary tree logic but we will have visited array to check
//     // apart from it everything is same
//     q.push(0);
//     while (!q.empty())
//     {
//         /* code */
//         int node = q.front();
//         q.pop();
//         bfs.push_back(node);
//         // vis[node] = 1;
//         for (auto &it : adj[node])
//         {
//             if (!vis[it])
//             {
//                 vis[it] = 1;
//                 q.push(it);
//             }
//         }
//     }

//     return bfs;
// }
// vector<vector<int>> buildAdjList(int &n, int &m)
// {
//     vector<vector<int>> adjList(n);
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adjList[v].push_back(u);
//         adjList[u].push_back(v);
//     }
//     return adjList;
// }

// I'm true
class Solution
{
public:
    void buildAdjList(int V, vector<vector<int>> &adjList, vector<vector<int>> &edges)
    {
        for (auto &ele : adjList)
        {
            int u = ele[0];
            int v = ele[1];
            cout<<u<<" "<<v<<" ";
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

public:
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges)
    {
        vector<int> vis(V,0); 
        vector<int> bfs;
        vector<vector<int>> adjList;
        buildAdjList(V,adjList,edges);
        queue<int> que;
        que.push(0);
        vis[0] = 1;
        while(!que.empty()){
            auto node = que.front();
            que.pop();
            bfs.push_back(node);
            for(auto &ele:adjList[node]){
                if(!vis[ele]){
                    que.push(ele);
                    vis[ele] = 1;
                }
            }
        }
        return bfs;
    }
};

int main()
{

    // code here
    int V, E;
    cout<<"Hello world"<<endl;
    cin >> V >> E;
    vector<vector<int>>  edges;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    for(auto &it:edges){
        for(auto &ele:it){
            cout<<"ele: "<<ele<<" ";
        }
        cout<<endl;
    }

    Solution sol;
    auto res = sol.bfsOfGraph(V,edges);
    for(auto &it:res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}