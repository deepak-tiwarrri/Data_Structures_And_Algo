#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
   void dfsTraversal(int V, vector<int> adjList[], vector<int> &vis, int &startNode)
   {
      vis[startNode] = 1;
      for (auto &ele : adjList[startNode])
      {
         if (!vis[ele])
         {
            dfsTraversal(V, adjList, vis, ele);
         }
      }
   }
   void buildAdjList(int V, vector<vector<int>> &edges, vector<int> adjList[])
   {
      for (int i = 0; i < edges.size(); i++)
      {

         int u = edges[i][0];
         int v = edges[i][1];
         adjList[u].push_back(v);
         adjList[v].push_back(u);
      }
   }

public:
   int findNumberOfComponent(int V, vector<vector<int>> &edges)
   {
      vector<int> vis(V, 0);
      vector<int> adjList[V];
      buildAdjList(V, edges, adjList);
      int cnt = 0;
      for (int i = 0; i < V; i++)
      {
         if (!vis[i])
         {
            dfsTraversal(V, adjList, vis, i);
            cnt++;
         }
      }
      return cnt;
   }
};
int main()
{
   // code here

   return 0;
}