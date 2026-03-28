#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
   void dfsTraversal(int V, vector<int> adjList[], vector<int> &vis, vector<int> &ans, int &startNode)
   {
      vis[startNode] = 1;
      ans.push_back(startNode);
      for (auto &ele : adjList[startNode])
      {
         if (!vis[ele])
         {
            dfsTraversal(V, adjList, vis, ans, ele);
         }
      }
   }

   void bfsTraversal(int V, vector<int> adjList[], vector<int> &vis, vector<int> &ans, int &startNode)
   {
      queue<int> q;
      vis[startNode] = 1;
      q.push(startNode);
      while (!q.empty())
      {
         int node = q.front();
         q.pop();
         ans.push_back(node);
         for (auto &ele : adjList[node])
         {
            if (!vis[ele])
            {
               vis[ele] = 1;
               q.push(ele);
            }
         }
      }
   }

public:
   vector<int> dfsOfGraph(int V, vector<int> adj[])
   {
      vector<int> vis(V, 0);
      vector<int> ans;
      int startNode = 0;
      dfsTraversal(V, adj, vis, ans, startNode);
      return ans;
   }

   vector<int> bfsOfGraph(int V, vector<int> adj[])
   {
      vector<int> vis(V, 0);
      vector<int> ans;
      int startNode = 0;
      bfsTraversal(V, adj, vis, ans, startNode);
      return ans;
   }
};
void buildAdjList(int n, int m, vector<int> adjList[])
{
   for (int i = 0; i < m; i++)
   {
      int u, v;
      cin >> u >> v;
      adjList[v].push_back(u);
      adjList[u].push_back(v);
   }
}
int main()
{
   // code here
   int n, m;
   cin >> n >> m;
   vector<int> adjList[n + 1];
   buildAdjList(n, m, adjList);

   Solution sol = Solution();
   sol.bfsOfGraph(8, adjList);
   sol.dfsOfGraph(8, adjList);

   return 0;
}