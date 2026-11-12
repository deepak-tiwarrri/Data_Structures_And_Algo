#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M)
    {
        vector<vector<int>> adj(N);
        vector<int> distance(N, 1e9);
        for (auto &it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> que;
        que.push(0);
        distance[0] = 0;
        while (!que.empty())
        {
            auto node = que.front();
            que.pop();
            for (auto &it : adj[node])
            {
                if (distance[node] + 1 < distance[it])
                {
                    distance[it] = distance[node] + 1;
                    que.push(it);
                }
            }
        }
        for (auto &it : distance)
        {
            if (it == 1e9)
                it = -1;
        }
        return distance;
    }
};

int main()
{
    // code here
    int n = 9, m = 10;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};
    Solution sol;
    vector<int> ans = sol.shortestPath(edges, n, m);
    for (auto &it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}