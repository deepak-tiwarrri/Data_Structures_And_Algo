#include <bits/stdc++.h>
using namespace std;
vector<int> bfsTraversal(int v, vector<vector<int>> &adj)
{
    vector<int> bfs;
    vector<int> vis(v, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        /* code */
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        // vis[node] = 1;
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}
vector<vector<int>> buildAdjList(int &n, int &m)
{
    vector<vector<int>> adjList(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }
    return adjList;
}
int main()
{

    // code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjListRes = buildAdjList(n, m);
    vector<int> bfsRes = bfsTraversal(n, adjListRes);
    for (int i = 0; i < bfsRes.size(); i++)
    {
        cout << bfsRes[i] << " ";
    }
    return 0;
}